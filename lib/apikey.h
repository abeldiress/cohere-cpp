#include "interface.h"

namespace cohere {
  class APIKey : private Interface {
    public:
      // APIKey();
      // APIKey(const APIKey &) = delete;
      // APIKey &operator=(const APIKey &) = delete;
      // APIKey(APIKey &&) = delete;
      // APIKey &operator=(APIKey &&) = delete;

      Json check();
  };
}