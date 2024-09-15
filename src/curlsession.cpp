#include "curlsession.h"

#ifndef CURL_STATICLIB
#include <curl/curl.h>
#else
#include "curl/curl.h"
#endif

#include <string>
#include <mutex>
#include <iostream>

std::mutex CURLSession::Session::mutex_session;
int CURLSession::Session::instance_count = 0;

size_t CURLSession::Session::write(void* ptr, size_t size, size_t nmemb, std::string* data) {
  data->append((char*) ptr, size * nmemb);
  return size * nmemb;
}

CURLSession::Session::Session(const std::string &base_url_) : curl(nullptr), list(nullptr), base_url(base_url_) {
  curl = curl_easy_init();
  if (!curl) throw std::runtime_error("Failed to initialize curl handle.");

  if (!instance_count++) curl_global_init(CURL_GLOBAL_ALL);
}

CURLSession::Session::~Session() {
  if (!curl) {
    std::cerr << "CURLSession could not clean up cURL handle." << std::endl;
    // throw std::runtime_error("CURLSession cannot close to cURL handle error.");
  }
  curl_easy_cleanup(curl);
  if (list) curl_slist_free_all(list);
  if (!--instance_count) curl_global_cleanup();
}

void CURLSession::Session::setURL(const std::string &base_url_) { base_url = base_url_; }

void CURLSession::Session::flushHeaders() {
  if (list) curl_slist_free_all(list);
}

// void CURLSession::startCurl() {
//   curl_global_init(CURL_GLOBAL_ALL);
//   curl = curl_easy_init();
//   if (!curl) throw std::runtime_error("\"curl\" handle failed to start.");
//   curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
// }

void CURLSession::Session::setRequest(const HTTPRequest type) {
  switch (type) {
    case HTTPRequest::GET:
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
      curl_easy_setopt(curl, CURLOPT_POST, 0L);
      break;
    case HTTPRequest::POST:
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 0L);
      curl_easy_setopt(curl, CURLOPT_POST, 1L);
      break;
    case HTTPRequest::DELETE:
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 0L);
      curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
      break;
    case HTTPRequest::PATCH:
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 0L);
      curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PATCH");
      break;
    default:
      throw std::runtime_error("Cannot support the specified HTTPRequest.");
  }

  if (!curl) throw std::runtime_error("Cannot set HTTP request of handle.");
}

void CURLSession::Session::addHeader(const std::string &header) {
  if (!list) list = nullptr;
  list = curl_slist_append(list, header.c_str());
  if (!list) throw std::runtime_error(
		   std::string{"Failed to append the following: \"" 
		               + header + "\" to the header"});
}

void CURLSession::Session::setBody(const std::string &data_) {
  data = data_;  // make a copy in case its a temporary literal
}

CURLSession::Response CURLSession::Session::completeRequest() {
  std::lock_guard<std::mutex> lock(mutex_session);

  std::string response_string;
  std::string header_string;

  if (!list) throw std::runtime_error("Failed to mount header to handle");
  if (!curl) throw std::runtime_error("Handle failed to launch.");

  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
  curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

  curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.length());
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

  curl_easy_setopt(curl, CURLOPT_URL, base_url.c_str());

  res = curl_easy_perform(curl);

  bool is_error = res != CURLE_OK;
  std::string error_msg = curl_easy_strerror(res);
  return { response_string, header_string, is_error, error_msg };
}