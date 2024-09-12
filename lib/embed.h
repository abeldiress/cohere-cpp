#include "interface.h"
#include <optional>

namespace cohere {
  class Embed : public Interface {
    Json embed(const std::vector<std::string> &texts,
              const std::string &model = "embed-english-v2.0",
              const std::optional<std::string> &input_type = std::nullopt, /* enum: search_document, search_query, classification, clustering */
              const std::optional<std::string> &embedding_types = std::nullopt, /* enum: float, int8, uint8, binary, ubinary */
              const std::string &truncate = "END" /* enum: NONE, START, END */);
    Json create_job(const std::string &model = "embed-english-v2.0",
                    const std::optional<std::string> &dataset_id = std::nullopt,
                    const std::optional<std::string> &input_type = std::nullopt, /* enum: search_document, search_query, classification, clustering */
                    const std::optional<std::string> &name = std::nullopt,
                    const std::optional<std::vector<std::string>> &embedding_types = std::nullopt, /* list of enums: float, int8, uint8, binary, ubinary */
                    const std::string &truncate = "END" /* START or END */);
    Json list_jobs();
    Json fetch_job(const std::string &id);
    Json cancel_job(const std::string &id);
  };
}