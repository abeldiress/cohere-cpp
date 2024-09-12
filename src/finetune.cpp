#include "finetune.h"

Json cohere::Finetune::get(const std::optional<int> page_size,
                           const std::optional<int> &page_token,
                           const std::optional<std::string> &order_by) {
  Json body;

  appendOptJson(body, "page_size", page_size);
  appendOptJson(body, "page_token", page_token);
  appendOptJson(body, "order_by", order_by);

  Json res = request("/finetunes", cohere::Method::GET, body);
  return res;
}

Json cohere::Finetune::train_deploy(const std::string &name,
                                    const Json &object,
                                    const std::optional<std::string> &id,
                                    const std::optional<std::string> &creator_id,
                                    const std::optional<std::string> &organization_id,
                                    const std::string &status,
                                    const std::optional<std::string> &created_at,
                                    const std::optional<std::string> &completed_at,
                                    const std::optional<std::string> &last_used) {
  Json body;

  body["name"] = name;
  body["object"] = object;
  appendOptJson(body, "id", id);
  appendOptJson(body, "creator_id", creator_id);
  appendOptJson(body, "organization_id", organization_id);
  body["status"] = status;
  appendOptJson(body, "created_at", created_at);
  appendOptJson(body, "completed_at", completed_at);
  appendOptJson(body, "last_used", last_used);

  Json res = request("/finetunes/train_deploy", cohere::Method::POST, body);
  return res;
}

Json cohere::Finetune::update(const std::string &id) {
  Json res = request("/finetunes/" + id, cohere::Method::PATCH);
  return res;
}

Json cohere::Finetune::get(const std::string &id) {
  Json res = request("/finetunes/" + id, cohere::Method::GET);
  return res;
}

Json cohere::Finetune::del(const std::string &id) {
  Json res = request("/finetunes/" + id, cohere::Method::DELETE);
  return res;
}

Json cohere::Finetune::retrieve_events(const std::string &finetuned_model_id) {
  Json res = request("/finetunes/" + finetuned_model_id + "/events", cohere::Method::GET);
  return res;
}

Json cohere::Finetune::retrieve_metrics(const std::string &finetuned_model_id) {
  Json res = request("/finetunes/" + finetuned_model_id + "/metrics", cohere::Method::GET);
  return res;
}