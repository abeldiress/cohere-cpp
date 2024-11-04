#include "interface.h"
#include <optional>

namespace cohere {
  class Classify : public Interface {
    public:
      // Classify();
      // Classify(const Classify &) = delete;
      // Classify &operator=(const Classify &) = delete;
      // Classify(Classify &&) = delete;
      // Classify &operator=(Classify &&) = delete;
      
      Json classify(const std::vector<std::string> &inputs,
                    const std::optional<Json> &examples = std::nullopt, // list of objects
                    const std::optional<std::string> &model = std::nullopt,
                    const std::optional<std::string> &preset = std::nullopt,
                    const std::string &truncate = "END" /* enum: NONE, START, END */);
  };
}