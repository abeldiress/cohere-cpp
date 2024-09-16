#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "cohere.h"

using namespace std;
using namespace cohere;

int main() {
  vector<string> g = {"hello world"};
  Cohere co = Cohere(); // enviroment variable: CO_API_KEY
  Json embed = co.Embed->embed(g);
  Json chat = co.Chat->chat("hello world!", "command", true);
  
  cout << embed.dump() << endl;

  return 0;
}
