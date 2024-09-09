#include "interface.h"

namespace libcohere {
  class Dataset : private Interface {
    Json create(const std::string &name,
                const std::string &type, /* enum: embed-input, reranker-finetune-input, single-label-classification-finetune-input, chat-finetune-input, multi-label-classification-finetune-input */
                const std::optional<bool> keep_original_file = std::nullopt,
                const std::optional<bool> skip_malformed_input = std::nullopt,
                const std::optional<std::string> &keep_fields = std::nullopt,
                const std::optional<std::string> &optional_fields = std::nullopt,
                const std::optional<std::string> &text_separator = std::nullopt,
                const std::optional<std::string> &csv_delimiter = std::nullopt);
  }
}