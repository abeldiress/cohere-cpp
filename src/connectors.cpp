#include "interface.h"

Json cohere::Connectors::list() {
  Json res = request("/connectors", cohere::Method::GET);
  return res;
}

Json cohere::Connectors::create(const std::string &name,
                                const std::string &url,
                                const std::optional<std::string> &description,
                                const std::optional<std::vector<std::string>> &excludes,
                                const std::optional<Json> &oauth,
                                const std::optional<bool> &active,
                                const std::optional<bool> &continue_on_failure,
                                const std::optional<Json> &service_auth) {
  Json body;

  body["name"] = name;
  body["url"] = url;
  appendOptJson(body, "description", description);
  appendOptJson(body, "excludes", excludes);
  appendOptJson(body, "oauth", oauth);
  appendOptJson(body, "active", active);
  appendOptJson(body, "continue_on_failure", continue_on_failure);
  appendOptJson(body, "service_auth", service_auth);

  Json res = request("/connectors", cohere::Method::POST, body);
  return res;
}

Json cohere::Connectors::get(const std::string &id) {
  Json res = request("/connectors/" + id, cohere::Method::GET);
  return res;
}

Json cohere::Connectors::update(const std::string &id) {
  Json res = request("/connectors/" + id, cohere::Method::PATCH);
  return res;
}

Json cohere::Connectors::del(const std::string &id) {
  Json res = request("/connectors/" + id, cohere::Method::DELETE);
  return res;
}

Json cohere::Connectors::authorize(const std::string &id) {
  Json res = request("/connectors/" + id + "/authorize", cohere::Method::POST);
  return res;
}
