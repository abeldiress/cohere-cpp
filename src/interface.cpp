#include "interface.h"

CURLSession::Session cohere::Interface::session = CURLSession::Session();
std::string cohere::Interface::api_key = "";
cohere::Interface::Interface(const std::string &key) {
  if (key.empty() && api_key.empty()) {
    if (const char *p = std::getenv("CO_API_KEY")) {
      api_key = std::string{p};
    }
  }
}

Json cohere::Interface::request(const std::string &endpoint,
            const Method &http_method,
            const std::string &content_type,
            const std::optional<Json> &req_data) {
  Json headers;
  headers.push_back({"Content-Type", content_type});
  headers.push_back({"Accept", "application/json"}); // every API endpoint uses json...default
  headers.push_back({"Authorization:", "bearer" + api_key});
  
  if (!client_name.empty()) {
    headers.push_back({"X-Client-Name", client_name});
  }

  session.flushHeaders();
  for (auto &[key, value] : headers.items()) {
    session.addHeader(key + ": " + value.dump());
  }

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