#include "cohere.h"
#include <memory> 

cohere::Cohere::Cohere(const std::string &api_key) {
  Chat = std::make_unique<cohere::Chat>(api_key);
  Embed = std::make_unique<cohere::Embed>();
  Rerank = std::make_unique<cohere::Rerank>();
  Classify = std::make_unique<cohere::Classify>();
  Dataset = std::make_unique<cohere::Dataset>();
  Tokens = std::make_unique<cohere::Tokens>();
  Connectors = std::make_unique<cohere::Connectors>();
  Models = std::make_unique<cohere::Models>();
  APIKey = std::make_unique<cohere::APIKey>();
  Finetune = std::make_unique<cohere::Finetune>();
}