#include "interface.h"

CURLSession::Session cohere::Interface::session = CURLSession::Session();
std::string cohere::Interface::api_key = "";

cohere::Interface::Interface(const std::string &key) {
  if (key.empty() && api_key.empty()) {
    if (const char *co = std::getenv("CO_API_KEY")) {
      api_key = std::string{co};
    } else {
      // throw std::runtime_error("Could not find API key in enviroment variables");
    }
  } else if (api_key.empty()) {
    api_key = key;
  }
}

Json cohere::Interface::request(const std::string &endpoint,
            const Method &http_method,
            const std::optional<Json> &req_data,
            const std::string &content_type) {
  // Json headers;
  // headers["Content-Type"] = content_type;
  // headers[] = ""; 
  // headers[] = "Bearer" + api_key; 

  session.addHeader("Content-Type: " + content_type);
  session.addHeader("Accept: application/json"); // every API endpoint uses json...default
  session.addHeader("Authorization: Bearer " + api_key);
  
  if (!client_name.empty()) {
    session.addHeader("X-Client-Name: " + client_name);
    // headers["X-Client-Name"] = client_name;
  }

  // std::cout << headers.dump() << std::endl;

  // for (auto &[key, value] : headers.items()) {
  //   session.addHeader(key + ": " + value.dump());
  // }

  // std::cout << req_data->dump() << std::endl;
  // std::cout << base_url + endpoint << std::endl;

  if (req_data.has_value()) {
    session.setBody(req_data->dump());
  }
 
  session.setURL(base_url + endpoint);
  session.setRequest(http_method);

  CURLSession::Response res = session.completeRequest();
  session.flushHeaders();
  
  if (res.is_error) {
    Json err;
    err["error"] = res.error_msg;
    return err; 
  }

  return Json::parse(res.response_data);
}

void cohere::Interface::setClientName(const std::string &c) { client_name = c; }

std::string& cohere::Interface::getClientName() {
  return client_name;
}

// template<typename T>
// void cohere::Interface::appendOptJson(Json &j, const std::string &key, const std::optional<T> &arg) {
//   if (arg.has_value()) j[key] = *arg;
// }