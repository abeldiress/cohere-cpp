#include "interface.h"

namespace libcohere {
  class Classify : private Interface {
    Json classify(const std::vector<std::string> &inputs,
                  const std::optional<Json> &examples = std::nullopt, // list of objects
                  const std::optional<string> &model = std::nullopt,
                  const std::optional<string> &preset = std::nullopt,
                  const std::string &truncate = "END" /* enum: NONE, START, END */);
  }
}