#include "chat.h"

Json Chat::chat(const std::string &message,
              const bool stream = false,
              const std::string &model,
              const std::optional<std::string> &preamble = std::nullopt,
              const std::optional<Json> &chat_history = std::nullopt, // list of objects
              const std::optional<std::string> &conversation_id = std::nullopt,
              const std::string &prompt_truncation, // enum OFF, AUTO, AUTO_PRESERVE_ORDER
              const std::optional<Json> &connectors = std::nullopt, // list of objects
              const bool search_queries_only = false,
              const std::optional<Json> &documents = std::nullopt, // list of maps from strings to strings
              const std::string &citation_quality, // enum fast, accurate, off
              const double temprature,
              const std::optional<int> &max_tokens = std::nullopt,
              const std::optional<int> &max_input_tokens = std::nullopt,
              const int k,
              const double p,
              const std::optional<int> &seed = std::nullopt,
              const std::optional<std::vector<std::string>> &stop_sequences = std::nullopt,
              const double frequency_penalty,
              const double presence_penalty,
              const std::optional<Json> &tools = std::nullopt, // list of objects
              const std::optional<Json> &tool_results = std::nullopt, // list of objects
              const bool force_single_step = false,
              const std::optional<Json> &response_format = std::nullopt,
              const std::string &safety_mode = "CONTEXTUAL" /* enum CONTEXTUAL STRICT NONE */) {
  Json body;
  body.push_back("message", std::move(message));
  body.push_back("stream", std::move(stream));
  body.push_back("model", std::move(model));
  body.push_back("");
  body.push_back();
  //
}