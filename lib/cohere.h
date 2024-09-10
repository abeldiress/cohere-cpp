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

namespace libcohere {
  class Cohere {
    public:
      Cohere() = default;
      Cohere(const Cohere const&) = delete;
      Cohere(const Cohere &&) = delete;
      Cohere &operator=(const Cohere &&) = delete;
      Cohere operator=(const Cohere &) = delete;

      std::unique_ptr<Chat *> = std::make_unique<Chat>();
      std::unique_ptr<Embed *> = std::make_unique<Embed>();
      std::unique_ptr<Rerank *> = std::make_unique<Rerank>();
      std::unique_ptr<Classify *> = std::make_unique<Classify>();
      std::unique_ptr<Dataset *> = std::make_unique<Dataset>();
      std::unique_ptr<Tokens *> = std::make_unique<Tokens>();
      std::unique_ptr<Connectors *> = std::make_unique<Connectors>();
      std::unique_ptr<Models *> = std::make_unique<Models>();
      std::unique_ptr<APIKey *> = std::make_unique<APIKey>();
      std::unique_ptr<Finetune *> = std::make_unique<Finetune>();
  }
}