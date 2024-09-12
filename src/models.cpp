#include "models.h"

Json cohere::Models::get(const std::string &model) {
  Json res = request("/models/" + model, cohere::Method::GET);
  return res;
}

Json cohere::Models::list(const std::optional<double> &page_size,
                          const std::optional<std::string> &page_token,
                          const std::optional<std::string> &endpoint,
                          const std::optional<bool> &default_only) {
  Json body;

  appendOptJson(body, "page_size", page_size);
  appendOptJson(body, "page_token", page_token);
  appendOptJson(body, "endpoint", endpoint);
  appendOptJson(body, "default_only", default_only);

  Json res = request("/models", cohere::Method::GET, body);
  return res;
}
