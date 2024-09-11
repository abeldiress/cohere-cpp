#include "interface.h"

namespace cohere {
  class APIKey : private Interface {
    Json check();
  };
}