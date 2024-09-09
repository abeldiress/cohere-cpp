#include "interface.h"

namespace libcohere {
  class Rerank : private Interface {
    Json rerank(const std::string &query,
                const std::optional<Json> &documents = std::nullopt, /* list of strings or maps from strings to strings */
                const std::optional<string> &models = std::nullopt,
                const std::optional<int> top_n = std::nullopt,
                const std::optional<std::vector<std::string>> &rank_fields = std::nullopt,
                const std::optional<bool> return_documents = std::nullopt,
                const std::optional<int> max_chunks_per_doc = std::nullopt);
  }
}