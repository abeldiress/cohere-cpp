#include <string>
#include <memory>
#include <vector>

#include <fstream>
#include <iostream>

#include "cohere.h"

using namespace std;
using namespace cohere;

int main() {
  // not at all exhausitve testing
  // vector<string> g = {"hello world"};
  // Json embed = co.Embed->embed(g);
  // Json chat = co.Chat->chat("hello world!", "command", false);
  // cout << chat.dump() << endl;

  // Json tokens = co.Tokens->tokenize("orange bicycle", "command");
  // cout << tokens.dump() << endl;

  // Json words = co.Tokens->detokenize({40723,21641}, "command");
  // cout << words.dump() << endl;

  Cohere co = Cohere(); // enviroment variable: CO_API_KEY

  ifstream ifs{"prompts.txt"};

  vector<string> prompts;
  string prompt;

  while (ifs >> prompt) {
    prompts.push_back(prompt);
  }

  cout << "{" << prompts[0] << "}" << endl;

  for (auto &p: prompts) {
    Json chat = co.Chat->chat(p, "command");
    cout << chat << endl;
  }

  return 0;
}
