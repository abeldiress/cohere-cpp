#ifndef CURLSESSION_H

#define CURLSESSION_H

// minimal class to make interacting with the C-based curl.h OOP based and thread-safe

#ifndef CURL_STATICLIB
#include <curl/curl.h>
#else 
#include "curl/curl.h"
#endif

#include <nlohmann/json.hpp>  // nlohmann/json
// #include "Response.hpp"
// #include "Request.hpp"

enum HTTPRequest { GET, POST, DELETE, PATCH }; // other HTTP requests ommitted based on API reference

// errors are exception based

struct Response {
  std::string    response_data;
  std::string    header_data;
  bool           is_error;
  std::string    error_msg;
};

class CURLSession {
  CURLSession(const std::string base_url);
  
  ~CURLSession();

  void setURL(const std::string base_url);

  void flushHeaders(const std::string);

  void CURLSession::startCurl();

  void setRequest(HTTPRequests type);

  void addHeader(const std::string header); // covers removal, adding, changing
  
  void setBody(const std::string data);

  Response completeRequest();

  private:
    CURL               *curl;
    CURLcode             res;
    std::mutex mutex_session;
    struct curl_slist  *list;
    std::string     base_url;

    static size_t write(void* ptr, size_t size, size_t nmemb, std::string* data) {
      data->append((char*) ptr, size * nmemb);
      return size * nmemb;
    }
}
#endif // CURLSESSION_H
