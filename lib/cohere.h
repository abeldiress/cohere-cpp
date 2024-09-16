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

#include <memory>

namespace cohere {
  class Cohere {
    public:
      Cohere(const std::string &api_key = "");
      Cohere(const Cohere &) = delete;
      Cohere(const Cohere &&) = delete;
      Cohere &operator=(const Cohere &&) = delete;
      Cohere operator=(const Cohere &) = delete;

      // NOTE: only one API key can be used at a time
      std::unique_ptr<cohere::Chat> Chat;
      std::unique_ptr<cohere::Embed> Embed;
      std::unique_ptr<cohere::Rerank> Rerank;
      std::unique_ptr<cohere::Classify> Classify;
      std::unique_ptr<cohere::Dataset> Dataset;
      std::unique_ptr<cohere::Tokens> Tokens;
      std::unique_ptr<cohere::Connectors> Connectors;
      std::unique_ptr<cohere::Models> Models;
      std::unique_ptr<cohere::APIKey> APIKey;
      std::unique_ptr<cohere::Finetune> Finetune;
  };
}

#endif // COHERE_H