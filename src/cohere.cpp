#include "cohere.h"
#include <memory> 

#include <iostream>

cohere::Cohere::Cohere(const std::string &api_key) {
  Chat = std::make_unique<cohere::Chat>(api_key);
  // std::unique_ptr<cohere::Embed> Embed = std::make_unique<cohere::Embed>();
  // std::unique_ptr<cohere::Rerank> Rerank = std::make_unique<cohere::Rerank>();
  // std::unique_ptr<cohere::Classify> Classify = std::make_unique<cohere::Classify>();
  // std::unique_ptr<cohere::Dataset> Dataset = std::make_unique<cohere::Dataset>();
  // std::unique_ptr<cohere::Tokens> Tokens = std::make_unique<cohere::Tokens>();
  // std::unique_ptr<cohere::Connectors> Connectors = std::make_unique<cohere::Connectors>();
  // std::unique_ptr<cohere::Models> Models = std::make_unique<cohere::Models>();
  // std::unique_ptr<cohere::APIKey> APIKey = std::make_unique<cohere::APIKey>();
  // std::unique_ptr<cohere::Finetune> Finetune = std::make_unique<cohere::Finetune>();
}