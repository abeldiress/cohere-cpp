#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "cohere.h"
#include "curlsession.h"

using namespace std;
using namespace cohere;

int main() {
  // Json body;
  // body["model"] = "embed-english-v2.0";
  // body["texts"] = "[\"hello world\"]";
  // body["truncate"] = "END";

  // Interface i;

  // Json res = i.request("/embed", cohere::Method::POST, body);

  // cout << res.dump() << endl;

  vector<string> g = {"hello world"};
  Cohere co = Cohere(); // enviroment variable: CO_API_KEY
  Json embed = co.Embed->embed(g);
  cout << embed.dump() << endl;

  return 0;
}
