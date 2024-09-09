#include "curlsession.h"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using Json = nlohmann::json;

namespace libcohere {
  using Method = Session::HTTPRequest;
  const static std::string base_url = "https://api.cohere.com/v1";

  class Interface {
    public:
      Interface(const std::string &key = "") {
        if (key.empty()) {
          if (const char *p = std::get_env("CO_API_KEY")) {
            api_key = std::string{p};
          }
        }
      }

      Interface(const Interface&) = delete;
      Interface& operator=(const Interface&) = delete;
      Interface(Interface&&) = delete;
      Interface& operator=(Interface&&) = delete;
      ~Interface() {}
      
      Json request(const Method &http_method, 
                    const std::string &endpoint, 
                    const std::string &content_type = "application/json",
                    const std::optional<std::json> &req_data = std::nullopt,
                    const std::optional<std::string> &client_name = std::nullopt) {
        Json headers;
        headers.push_back({"Content-Type": content_type});
        headers.push_back({"Accept": "application/json"}); // every API endpoint uses json...default
        headers.push_back({"Authorization:": "bearer" + api_key});
        if (client_name.has_value()) {
          headers.push_back({"X-Client-Name": client_name});
        }

        session.flushHeaders();
        for (auto &[key, value] : jsonObject.items()) {
          session.addHeader(key + ": " + value);
        }

        if (req_data.has_value()) {
          session.setBody(req_data.dump());
        }
        
        session.setURL(base_url + endpoint);
        session.setRequest(static_cast<HTTPRequest>(http_method));
    
        CURLSession::CURLResponse res = session.completeRequest();
        session.flushHeaders();
        
        if (res.is_error) {
          Json err;
          err["error"] = res.error_msg;
          return err; 
        }

        return Json::parse(res.response_data);
      }

    private:
      static CURLSession session;
      std::string api_key;
  };
}