#include "interface.h"

Json cohere::Classify::classify(const std::vector<std::string> &inputs,
                                const std::optional<Json> &examples,
                                const std::optional<std::string> &model,
                                const std::optional<std::string> &preset,
                                const std::string &truncate) {
  Json body;

  body["inputs"] = inputs;
  appendOptJson(body, "examples", examples);
  appendOptJson(body, "model", model);
  appendOptJson(body, "preset", preset);
  body["truncate"] = truncate;

  Json res = request("/classify", cohere::Method::GET, body);
  return res;
}
