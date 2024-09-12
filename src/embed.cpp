#include "embed.h"

Json cohere::Embed::embed(const std::vector<std::string> &texts,
                          const std::string &model,
                          const std::optional<std::string> &input_type,
                          const std::optional<std::string> &embedding_types,
                          const std::string &truncate) {
  Json body;

  body["texts"] = texts;
  body["model"] = model;
  appendOptJson(body, "input_type", input_type);
  appendOptJson(body, "embedding_types", embedding_types);
  body["truncate"] = truncate;

  Json res = request("/embed", cohere::Method::POST, body);
  return res;
}

Json cohere::Embed::create_job(const std::string &model,
                               const std::optional<std::string> &dataset_id,
                               const std::optional<std::string> &input_type,
                               const std::optional<std::string> &name,
                               const std::optional<std::vector<std::string>> &embedding_types,
                               const std::string &truncate) {
  Json body;

  body["model"] = model;
  appendOptJson(body, "dataset_id", dataset_id);
  appendOptJson(body, "input_type", input_type);
  appendOptJson(body, "name", name);
  appendOptJson(body, "embedding_types", embedding_types);
  body["truncate"] = truncate;

  Json res = request("/embed-jobs", cohere::Method::POST, body);
  return res;
}

Json cohere::Embed::list_jobs() {
  Json res = request("/embed-jobs", cohere::Method::GET);
  return res;
}

Json cohere::Embed::fetch_job(const std::string &id) {
  Json res = request("/embed-jobs/" + id, cohere::Method::GET);
  return res;
}

Json cohere::Embed::cancel_job(const std::string &id) {
  Json res = request("/embed-jobs/" + id + "/cancel", cohere::Method::POST);
  return res;
}