#include "chat.h"

Json cohere::Chat::chat(const std::string &message,
              const bool stream,
              const std::string &model,
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
              const std::string &safety_mode) {
  Json body;
  
  // body["message"] = std::move(message);
  // body["stream"] = std::move(stream);
  // body["model"] = std::move(model);
  // body["preamble"] = std::move(preamble);
  // body["chat_history"] = std::move(chat_history->dump());
  // body["conversation_id"] = std::move(conversation_id);
  // body["prompt_truncation"] = std::move(prompt_truncation);
  // body["connectors"] = std::move(connectors->dump());
  // body["search_queries_only"] = std::move(search_queries_only);
  // body["documents"] = std::move(documents->dump());
  // body["citation_quality"] = std::move(citation_quality);
  // body["temprature"] = std::move(temprature);
  // body["max_tokens"] = std::move(max_tokens);
  // body["max_input_tokens"] = std::move(max_input_tokens);
  // body["k"] = std::move(k);
  // body["p"] = std::move(p);
  // body["seed"] = std::move(seed);
  // body["stop_sequences"] = std::move(stop_sequences->dump());
  // body["frequency_penalty"] = std::move(frequency_penalty);
  // body["presence_penalty"] = std::move(presence_penalty);
  // body["tools"] = std::move(tools->dump());
  // body["tool_results"] = std::move(tool_results->dump());
  // body["force_single_step"] = std::move(force_single_step);
  // body["response_format"] = std::move(response_format->dump());
  // body["safety_mode"] = std::move(safety_mode);

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
  body["safety_mode"] = safety_mode;

  Json res = request("/chat", cohere::Method::GET, body);
  return res;
}