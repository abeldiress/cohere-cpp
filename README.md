# Cohere C++ SDK
![cpp badge](https://img.shields.io/badge/version-C++17-blue)
![MIT badge](https://img.shields.io/github/license/abeldiress/cohere-cpp)

## Introduction

`cohere-cpp` is an unofficial C++17 library to utilize Cohere's API through [libcurl](https://curl.se/libcurl/) and [nlohmann/json](https://github.com/nlohmann/json). Although still a work in progress, it allows thread-safe access to most API endpoints through only a single header file, `cohere.h`.

## Example

Python, from [Cohere's SDK](https://github.com/cohere-ai/cohere-python?tab=readme-ov-file#usage)
```py
import cohere

co = cohere.Client(
    api_key="YOUR_API_KEY",
)

chat = co.chat(
    message="hello world!",
    model="command"
)

print(chat)
```

C++
```cpp
#include <iostream>

#include "cohere.h"

using namespace std;
using namespace cohere;

int main() {
    Cohere co = Cohere();
    Json chat = co.Chat->chat(
      "hello world!", 
      "command"
    );

    cout << chat.dump() << endl;
}
```

## Endpoint Status

- [ ] chat_stream*
- [x] chat
- [ ] dataset†
- [x] generate_stream*
- [x] generate
- [x] embed
- [x] rerank
- [x] classify
- [x] summarize
- [ ] tokenize
- [ ] detokenize
- [x] check_api_key

\* Done passively through libcurl

†missing 1 endpoint

## Future (vague) Plans
 - Encapsulate parameters with easy-to-use enumerations and classes, finish other endpoints.
 - Provide support for Cohere's other [supported enviroments](https://docs.cohere.com/docs/cohere-works-everywhere#supported-environments) (Bedrock, Azure, etc.)
 - Improve build routine.
 - Add the library to vcpkg for easier access.
 - Provide basic documentation for every available endpoint.

## Acknowledgements
 - [Everything cURL](https://everything.curl.dev/)
 - [Cohere's Python SDK](https://github.com/cohere-ai/cohere-python)
 - [OpenAI's Community Maintained Libraries](https://platform.openai.com/docs/libraries/community-libraries)
 - [nlohmann::json](https://github.com/nlohmann/json), spectacular library
