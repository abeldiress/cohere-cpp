#ifndef COHERE_H
#define COHERE_H

#include "chat.h"
#include "embed.h"
#include "rerank.h"
#include "classify.h"
#include "dataset.h"
#include "tokens.h"
#include "connectors.h"
#include "models.h"
#include "apikey.h"
#include "finetune.h"

namespace cohere {
  class Cohere {
    public:
      Cohere() = default;
      Cohere(const Cohere &) = delete;
      Cohere(const Cohere &&) = delete;
      Cohere &operator=(const Cohere &&) = delete;
      Cohere operator=(const Cohere &) = delete;

      // NOTE: only one API key can be used at a time
      std::unique_ptr<cohere::Chat> Chat = std::make_unique<cohere::Chat>();
      // std::unique_ptr<cohere::Embed> Embed = std::make_unique<cohere::Embed>();
      // std::unique_ptr<cohere::Rerank> Rerank = std::make_unique<cohere::Rerank>();
      // std::unique_ptr<cohere::Classify> Classify = std::make_unique<cohere::Classify>();
      // std::unique_ptr<cohere::Dataset> Dataset = std::make_unique<cohere::Dataset>();
      // std::unique_ptr<cohere::Tokens> Tokens = std::make_unique<cohere::Tokens>();
      // std::unique_ptr<cohere::Connectors> Connectors = std::make_unique<cohere::Connectors>();
      // std::unique_ptr<cohere::Models> Models = std::make_unique<cohere::Models>();
      // std::unique_ptr<cohere::APIKey> APIKey = std::make_unique<cohere::APIKey>();
      // std::unique_ptr<cohere::Finetune> Finetune = std::make_unique<cohere::Finetune>();
  };
}
#endif // COHERE_H