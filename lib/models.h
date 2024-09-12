#include "interface.h"
#include <optional>

namespace cohere {
  class Models : public Interface {
    Json get(const std::string &model);
    Json list(const std::optional<double> &page_size,
              const std::optional<std::string> &page_token,
              const std::optional<std::string> &endpoint, /* enum: chat embed classify summarize rerank rate generate */
              const std::optional<bool> &default_only);
  };
}