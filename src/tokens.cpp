#include "tokens.h"
#include <vector>

Json cohere::Tokens::tokenize(const std::string &text, const std::string &model) {
  Json body;
  body["text"] = text;
  body["model"] = model;

  Json res = request("/tokenize", cohere::Method::POST, body);
  return res;
}

Json cohere::Tokens::detokenize(const std::vector<int> &tokens, const std::string &model) {
  Json body;

  body["tokens"] = tokens;
  body["model"] = model;

  Json res = request("/detokenize", cohere::Method::POST, body);
  return res;
}