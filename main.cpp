#include <string>
#include <iostream>
#include <memory>

#include "cohere.h"
#include "curlsession.h"

using namespace std;
using namespace cohere;

size_t writeFunction(void* ptr, size_t size, size_t nmemb, string* data) {
  data->append((char*) ptr, size * nmemb);
  return size * nmemb;
}

int main() {
  // CURL *c = curl_easy_init();

  // std::string data{"{\"message\": \"hello world\"}"};
  // std::string ct{"Content-Type: application/json"};
  // std::string at{"Accept: application/json"};
  // std::string auth{"Authorization: Bearer "};

  // string response_string;
  // string header_string;

  // struct curl_slist *list = nullptr;

  // list = curl_slist_append(list, ct.c_str());
  // list = curl_slist_append(list, at.c_str());
  // list = curl_slist_append(list, auth.c_str());
  // curl_easy_setopt(c, CURLOPT_HTTPHEADER, list);

  // curl_easy_setopt(c, CURLOPT_HTTPGET, 0L);
  // curl_easy_setopt(c, CURLOPT_POST, 1L);
  // curl_easy_setopt(c, CURLOPT_URL, "https://api.cohere.com/v1/chat");
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

  CURLSession::Session session;
  session.setURL("https://api.cohere.com/v1/chat");
  session.addHeader("Content-Type: application/json");
  session.addHeader("Accept: application/json");
  session.addHeader("Authorization: Bearer ");
  session.setRequest(CURLSession::HTTPRequest::POST);
  session.setBody("{\"message\": \"hello world\"}");
  CURLSession::Response r = session.completeRequest();

  cout << "Response Code: " << r.is_error << endl;
  cout << "Response Error: " << r.error_msg << endl;
  cout << "Response: " << endl << r.response_data << endl;
  cout << "Header: " << endl << r.header_data << endl;

  // Json body;
  // body["message"] = "hello world";
  // Interface i("");
  // Json res = i.request("/chat", Method::POST, "application/json", body);
  // cout << res.dump() << endl;

  // Cohere co = Cohere(""); // enviroment variable: CO_API_KEY
  // Json chat = co.Chat->chat("hello world!");
  // cout << chat.dump() << endl;
  return 0;
}
