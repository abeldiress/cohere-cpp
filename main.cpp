#include <curl/curl.h>
#include <string>
#include <iostream>

#include "curlsession.hpp"

using namespace std;

// size_t writeFunction(void* ptr, size_t size, size_t nmemb, string* data) {
//   data->append((char*) ptr, size * nmemb);
//   return size * nmemb;
// }

int main() {
  // CURL *c = curl_easy_init();

  // std::string data{"{\"foo\": \"bar\"}"};

  // string response_string;
  // string header_string;

  // struct curl_slist *list = NULL;

  // list = curl_slist_append(list, "Content-Type: application/json");
  // curl_easy_setopt(c, CURLOPT_HTTPHEADER, list);

  // curl_easy_setopt(c, CURLOPT_HTTPGET, 0L);
  // curl_easy_setopt(c, CURLOPT_POST, 1L);
  // curl_easy_setopt(c, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");
  // curl_easy_setopt(c, CURLOPT_POSTFIELDSIZE, data.length());
  // curl_easy_setopt(c, CURLOPT_POSTFIELDS, data.c_str());

  // curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, writeFunction);
  // curl_easy_setopt(c, CURLOPT_WRITEDATA, &response_string);
  // curl_easy_setopt(c, CURLOPT_HEADERDATA, &header_string);

  // CURLcode res = curl_easy_perform(c);

  // cout << "Response Code: " << res << endl;
  // cout << "Response Error: " << string{curl_easy_strerror(res)} << endl;
  // cout << "Response: " << endl << response_string << endl;
  // cout << "Header: " << endl << header_string << endl;

  // curl_easy_cleanup(c);

  // CURLSession session;
  // session.setURL("https://jsonplaceholder.typicode.com/posts");
  // session.addHeader("Content-Type: application/json");
  // session.setRequest(HTTPRequest::POST);
  // session.setBody("{\"foo\": \"bar\"}");
  // Response r = session.completeRequest();

  // cout << "Response Code: " << r.is_error << endl;
  // cout << "Response Error: " << r.error_msg << endl;
  // cout << "Response: " << endl << r.response_data << endl;
  // cout << "Header: " << endl << r.header_data << endl;
  curl_global_init(CURL_GLOBAL_ALL);
  curl_global_init(CURL_GLOBAL_ALL);
  return 0;
}
