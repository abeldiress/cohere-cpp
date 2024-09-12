#include "interface.h"
#include <optional>

namespace cohere {
  class Connectors : public Interface {
    Json list();
    Json create(const std::string &name,
                const std::string &url,
                const std::optional<std::string> &description = std::nullopt,
                const std::optional<std::vector<std::string>> &excludes = std::nullopt,
                const std::optional<Json> &oauth = std::nullopt,
                const std::optional<bool> &active = std::nullopt,
                const std::optional<bool> &continue_on_failure = std::nullopt,
                const std::optional<Json> &service_auth = std::nullopt);
    Json get(const std::string &id);
    Json update(const std::string &id);
    Json del(const std::string &id);
    Json authorize(const std::string &id);
  };
}