#include <string>
#include <iostream>
#include <memory>

#include "cohere.h"
#include "curlsession.h"

using namespace std;
using namespace cohere;

int main() {
  Cohere co = Cohere(); // enviroment variable: CO_API_KEY
  Json chat = co.Chat->chat("hello world!", "command");
  cout << chat.dump() << endl;
  return 0;
}
