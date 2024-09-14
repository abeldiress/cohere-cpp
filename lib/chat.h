#ifndef CHAT_H
#define CHAT_H

#include "interface.h"
#include <optional>

namespace cohere {
  class Chat : public cohere::Interface {
    // decided not to use this
    // using cohere::Interface::Interface;

    public:
      Chat(const std::string &key = "");
      Json chat(const std::string &message,
                const std::string &model = "command-r-plus-08-2024",
                const bool stream = false,
                const std::optional<std::string> &preamble = std::nullopt,
                const std::optional<Json> &chat_history = std::nullopt, // list of objects
                const std::optional<std::string> &conversation_id = std::nullopt,
                const std::string &prompt_truncation = "AUTO", // enum OFF, AUTO, AUTO_PRESERVE_ORDER
                const std::optional<Json> &connectors = std::nullopt, // list of objects
                const bool search_queries_only = false,
                const std::optional<Json> &documents = std::nullopt, // list of maps from strings to strings
                const std::string &citation_quality = "accurate", // enum fast, accurate, off
                const double temprature = 0.3,
                const std::optional<int> &max_tokens = std::nullopt,
                const std::optional<int> &max_input_tokens = std::nullopt,
                const int k = 0,
                const double p = 0.75,
                const std::optional<int> &seed = std::nullopt,
                const std::optional<Json> &stop_sequences = std::nullopt,
                const double frequency_penalty = 0.0,
                const double presence_penalty = 0.0,
                const std::optional<Json> &tools = std::nullopt, // list of objects
                const std::optional<Json> &tool_results = std::nullopt, // list of objects
                const bool force_single_step = false,
                const std::optional<Json> &response_format = std::nullopt,
                const std::string &safety_mode = "CONTEXTUAL" /* enum CONTEXTUAL STRICT NONE */);
  };
}

#endif // CHAT_H