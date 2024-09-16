#include "chat.h"

cohere::Chat::Chat(const std::string &key): cohere::Interface(key) { }

Json cohere::Chat::chat(const std::string &message,
              const std::string &model,
              const bool stream,
              const std::optional<std::string> &preamble,
              const std::optional<Json> &chat_history,
              const std::optional<std::string> &conversation_id,
              const std::string &prompt_truncation,
              const std::optional<Json> &connectors,
              const bool search_queries_only,
              const std::optional<Json> &documents, 
              const std::string &citation_quality,
              const double temprature,
              const std::optional<int> &max_tokens,
              const std::optional<int> &max_input_tokens,
              const int k,
              const double p,
              const std::optional<int> &seed,
              const std::optional<Json> &stop_sequences,
              const double frequency_penalty,
              const double presence_penalty,
              const std::optional<Json> &tools,
              const std::optional<Json> &tool_results,
              const bool force_single_step,
              const std::optional<Json> &response_format,
              const std::optional<std::string> &safety_mode) {
  Json body;

  body["message"] = message;
  body["stream"] = stream;
  body["model"] = model;
  appendOptJson(body, "preamble", preamble);
  appendOptJson(body, "chat_history", chat_history);
  appendOptJson(body, "conversation_id", conversation_id);
  body["prompt_truncation"] = prompt_truncation;
  appendOptJson(body, "connectors", connectors);
  body["search_queries_only"] = search_queries_only;
  appendOptJson(body, "documents", documents);
  body["citation_quality"] = citation_quality;
  body["temprature"] = temprature;
  appendOptJson(body, "max_tokens", max_tokens);
  appendOptJson(body, "max_input_tokens", max_input_tokens);
  body["k"] = k;
  body["p"] = p;
  appendOptJson(body, "seed", seed);
  appendOptJson(body, "stop_sequences", stop_sequences);
  body["frequency_penalty"] = frequency_penalty;
  body["presence_penalty"] = presence_penalty;
  appendOptJson(body, "tools", tools);
  appendOptJson(body, "tool_results", tool_results);
  body["force_single_step"] = force_single_step;
  appendOptJson(body, "response_format", response_format);
  appendOptJson(body, "safety_mode", safety_mode);
  // body["safety_mode"] = safety_mode;

  Json res = request("/chat", cohere::Method::POST, "application/json", body);
  return res;
}