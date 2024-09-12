#include "interface.h"
#include "json_helper.h"

Json cohere::Dataset::create(const std::string &name,
                             const std::string &type,
                             const std::optional<bool> keep_original_file,
                             const std::optional<bool> skip_malformed_input,
                             const std::optional<std::string> &keep_fields,
                             const std::optional<std::string> &optional_fields,
                             const std::optional<std::string> &text_separator,
                             const std::optional<std::string> &csv_delimiter) {
  Json body;

  body["name"] = name;
  body["type"] = type;
  appendOptJson(body, "keep_original_file", keep_original_file);
  appendOptJson(body, "skip_malformed_input", skip_malformed_input);
  appendOptJson(body, "keep_fields", keep_fields);
  appendOptJson(body, "optional_fields", optional_fields);
  appendOptJson(body, "text_separator", text_separator);
  appendOptJson(body, "csv_delimiter", csv_delimiter);

  Json res = request("/datasets", cohere::Method::POST, body);
  return res;
}

Json cohere::Dataset::list(const std::optional<std::string> &dataset_type,
                           const std::optional<std::string> &before,
                           const std::optional<std::string> &after,
                           const std::optional<double> offset,
                           const std::optional<std::string> &validation_status) {
  Json body;

  appendOptJson(body, "dataset_type", dataset_type);
  appendOptJson(body, "before", before);
  appendOptJson(body, "after", after);
  appendOptJson(body, "offset", offset);
  appendOptJson(body, "validation_status", validation_status);

  Json res = request("/datasets", cohere::Method::GET, body);
  return res;
}

Json cohere::Dataset::get_usage() {
  Json res = request("/datasets/usage", cohere::Method::GET);
  return res;
}

Json cohere::Dataset::get(const std::string &id) {
  Json res = request("/datasets/" + id, cohere::Method::GET);
  return res;
}

Json cohere::Dataset::del(const std::string &id) {
  Json res = request("/datasets/" + id, cohere::Method::DELETE);
  return res;
}
