#include "interface.h"
#include <optional>

namespace cohere {
  class Finetune : public Interface {
    Json get(const std::optional<int> page_size = std::nullopt,
             const std::optional<int> &page_token = std::nullopt,
             const std::optional<std::string> &order_by = std::nullopt);
    Json train_deploy(const std::string &name,
                      const Json &object,
                      const std::optional<std::string> &id = std::nullopt,
                      const std::optional<std::string> &creator_id = std::nullopt,
                      const std::optional<std::string> &organization_id = std::nullopt,
                      const std::string &status = "STATUS_UNSPECIFIED", /* enum: (9 values) https://docs.cohere.com/reference/createfinetunedmodel */
                      const std::optional<std::string> &created_at = std::nullopt,
                      const std::optional<std::string> &completed_at = std::nullopt,
                      const std::optional<std::string> &last_used = std::nullopt);
    Json update(const std::string &id);
    Json get(const std::string &id);
    Json del(const std::string &id);
    Json retrieve_events(const std::string &finetuned_model_id);
    Json retrieve_metrics(const std::string &finetuned_model_id);
  };
}