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
                    const std::string& content_type = "application/json",
                    const std::optional<json> &req_data) {
        Json headers;
        headers.push_back({"Content-Type": content_type});
        headers.push_back({"accept": "application/json"}); // every API reference uses json
        headers.push_back({"Authorization:": "bearer" + api_key});
        
        session.setRequest(static_cast<HTTPRequest>(http_method));
        if (req_data.has_value()) {
          session.setBody(req_data.dump());
        }

        session.setURL(base_url + endpoint);
        session.flushHeaders();
        
        for (auto &[key, value] : jsonObject.items()) {
          session.addHeader(key + ": " + value);
        }

        CURLSession::CURLResponse res = session.completeRequest();

        if (res.is_error) {
          Json err;
          err["error"] = res.error_msg; 
        }

        session.flushHeaders();
        return Json::parse(res.response_data);
      }

    private:
      static CURLSession session;
      std::string api_key;
  };
}