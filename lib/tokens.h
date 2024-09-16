#include "interface.h"
#include <optional>

namespace cohere {
  class Tokens : public Interface {
    public:
      Json tokenize(const std::string &text,
                    const std::string &model);
      Json detokenize(const std::vector<int> &tokens,
                      const std::string &model);
  };
}