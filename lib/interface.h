#ifndef INTERFACE_H
#define INTERFACE_H

#include "curlsession.h"
#include <string>
#include <nlohmann/json.hpp>
#include <optional>

using Json = nlohmann::json;

namespace cohere {
  using Method = CURLSession::HTTPRequest;
  const static std::string base_url = "https://api.cohere.com/v1";

  template<typename T>
  void appendOptJson(Json &j, const std::string &key, const std::optional<T> &arg) {
    if (arg.has_value()) j[key] = *arg;
  }

  class Interface {
    public:
      Interface(const std::string &key = "");

      Interface(const Interface&) = delete;
      Interface& operator=(const Interface&) = delete;
      Interface(Interface&&) = delete;
      Interface& operator=(Interface&&) = delete;
      ~Interface() {}
      
      Json request(const std::string &endpoint,
                  const Method &http_method,
                  const std::string &content_type = "application/json",
                  const std::optional<Json> &req_data = std::nullopt);

      void setClientName(const std::string &c);

      std::string &getClientName();

      // template<typename T>
      // void appendOptJson(Json &j, const std::string &key, const std::optional<T> &arg);

      static std::string api_key;
      std::string client_name;

    private:
      static CURLSession::Session session;
  };
}

#endif // INTERFACE_H