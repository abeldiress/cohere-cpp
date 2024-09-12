#include "rerank.h"

Json cohere::Rerank::rerank(const std::string &query,
                            const std::optional<Json> &documents,
                            const std::optional<std::string> &models,
                            const std::optional<int> top_n,
                            const std::optional<std::vector<std::string>> &rank_fields,
                            const std::optional<bool> return_documents,
                            const std::optional<int> max_chunks_per_doc) {
  Json body;

  body["query"] = query;
  appendOptJson(body, "documents", documents);
  appendOptJson(body, "models", models);
  appendOptJson(body, "top_n", top_n);
  appendOptJson(body, "rank_fields", rank_fields);
  appendOptJson(body, "return_documents", return_documents);
  appendOptJson(body, "max_chunks_per_doc", max_chunks_per_doc);

  Json res = request("/rerank", cohere::Method::POST, body);
  return res;
}