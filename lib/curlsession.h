#ifndef CURLSESSION_H

#define CURLSESSION_H

// minimal class to make interacting with the C-based curl.h OOP based and thread-safe

#ifndef CURL_STATICLIB
#include <curl/curl.h>
#else 
#include "curl/curl.h"
#endif

#include <nlohmann/json.hpp>  // nlohmann/json
#include <mutex>
// #include "Response.hpp"
// #include "Request.hpp"

namespace CURLSession {
  enum HTTPRequest { GET, POST, DELETE, PATCH }; // other HTTP requests ommitted based on API reference

  // errors are exception based

  struct Response {
    std::string    response_data;
    std::string    header_data;
    bool           is_error;
    std::string    error_msg;
  };

  class Session {
    public:
      Session(const std::string &base_url = "");
      
      ~Session();

      void setURL(const std::string &base_url);

      void flushHeaders();

      void startCurl();

      void setRequest(const HTTPRequest type);

      void addHeader(const std::string &header); // covers removal, adding, changing
      
      void setBody(const std::string &data_);

      Response completeRequest();

    private:
      CURL                          *curl;
      CURLcode                        res;
      static     std::mutex mutex_session;
      static int           instance_count;
      struct curl_slist   *list = nullptr;
      std::string                base_url;
      std::string                    data;

      static size_t write(void* ptr, size_t size, size_t nmemb, std::string* data);
  };
}

#endif // CURLSESSION_H