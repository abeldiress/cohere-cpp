#include "interface.h"
#include <optional>

namespace cohere {
  class Dataset : public Interface {
    Json create(const std::string &name,
                const std::string &type, /* enum: embed-input, reranker-finetune-input, single-label-classification-finetune-input, chat-finetune-input, multi-label-classification-finetune-input */
                const std::optional<bool> keep_original_file = std::nullopt,
                const std::optional<bool> skip_malformed_input = std::nullopt,
                const std::optional<std::string> &keep_fields = std::nullopt,
                const std::optional<std::string> &optional_fields = std::nullopt,
                const std::optional<std::string> &text_separator = std::nullopt,
                const std::optional<std::string> &csv_delimiter = std::nullopt
                /* data -> file */
                /* eval_data -> file */);
    Json list(const std::optional<std::string> &dataset_type = std::nullopt,
              const std::optional<std::string> &before = std::nullopt,
              const std::optional<std::string> &after = std::nullopt,
              const std::optional<double> offset = std::nullopt,
              const std::optional<std::string> &validation_status = std::nullopt /* enum unknown queued processing failed validated skipped */);
    Json get_usage();
    Json get(const std::string &id);
    Json del(const std::string &id);
  };
}