#include "curl/curl.h"
#include <iostream>

using namespace std;

int main() {
  curl_global_init(CURL_GLOBAL_ALL);

  curl_version_info_data *version = curl_version_info(CURLVERSION_NOW);
  cout << "Version: " << version->version << endl;
  
  curl_global_cleanup();
  return 0;
}