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

  Cohere co; // enviroment variable: CO_API_KEY

  Json chat = co.Chat->request(
    "hello world!", 
    "command"
  );

  cout << chat.dump() << endl;
  return 0;
}
