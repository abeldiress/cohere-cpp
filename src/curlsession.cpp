#include "curlsession.hpp"

#ifndef CURL_STATICLIB
#include <curl/curl.h>
#else
#include "curl/curl.h"
#endif

#include <string>
#include <mutex>

CURLSession::CURLSession(const std::string &base_url_ = "") {
  curl = curl_easy_init();
  list = nullptr;
  base_url = base_url_;
}

CURLSession::~CURLSession() {
  if (!curl) {
    throw std::runtime_error("CURLSession cannot close to cURL handle error.")
  }
  curl_easy_cleanup(curl);
  if (list) curl_slist_free_all(list);
  curl_global_cleanup();
}

void setURL(const std::string base_url_) { base_url = base_url_}

void flushHeaders(const std::string) {
  if (list) curl_slist_free_all(list);
}

void CURLSession::startCurl() {
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if (!curl) throw std::runtime_error("\"curl\" handle failed to start.");
  curl_east_setopt(curl, CURLOPT_NOSIGNAL, 1L);
}

void CURLSession::setRequest(HTTPRequest type) {
  switch (type) {
    case HTTPRequest::GET:
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 0L);
      curl_easy_setopt(curl, CURLOPT_POST, 1L);
    case HTTPRequest::POST:
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 0L);
      curl_easy_setopt(curl, CURLOPT_POST, 1L);
    case HTTPRequest::DELETE:
      curl_easy_setopt(curl_, CURLOPT_HTTPGET, 0L);
      curl_easy_setopt(curl_, CURLOPT_NOBODY, 0L);
      curl_easy_setopt(curl_, CURLOPT_CUSTOMREQUEST, "DELETE");
    case HTTPRequest::PATCH:
      curl_easy_setopt(curl_, CURLOPT_HTTPGET, 0L);
      curl_easy_setopt(curl_, CURLOPT_NOBODY, 0L);
      curl_easy_setopt(curl_, CURLOPT_CUSTOMREQUEST, "PATCH");
    default:
      throw std::runtime_error("Cannot support the specified HTTPRequest.");
  }

  if (!curl) throw std::runtime_error("Cannot set HTTP request of handle.")
}

void CURLSession::addHeader(const std::string header) {
  list = curl_slist_append(list, header.c_str());
  if (!list) throw std:runtime_error(
		   std::string{"Failed to append the following: \"" 
		               + header + "\" to the header"});
}

void CURLSession::setBody(const std::string data) {
  curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.length());
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
}

Response completeRequest() {
  std::lock_guard<std::mutex> lock(mutex_session);

  std::string response_string;
  std::string header_string;

  if (!list) throw std::runtime_error();
  if (!curl) throw std::runtime_error();

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
  curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

  curl_easy_setopt(curl, CURLOPT_URL, base_url.c_str());

  res = curl_easy_perform(curl);

  bool is_error = res != CURLE_OK;
  return { response_string, header_string, is_error, std::string{curl_easy_strerror(res_)} };
}
