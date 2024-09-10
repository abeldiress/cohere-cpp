#include "interface.h"

namespace libcohere {
  class APIKey : private Interface {
    Json check();
  }
}