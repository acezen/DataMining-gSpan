#ifndef INCLUDE_OUTPUT_H_
#define INCLUDE_OUTPUT_H_

#include <common.h>
#include <vector>
#include <string>

namespace gbolt {

class Output {
 public:
  explicit Output(const string &output_file): output_file_(output_file) {}

  size_t size() const {
    return support_.size();
  }

  void push_back(const string &str, size_t nsupport, size_t graph_id);

  void push_back(const string &str, size_t nsupport, size_t graph_id, size_t thread_id, int parent_id);

  void save(bool output_parent = false, bool output_pattern = false);

 private:
  vector<string> buffer_;
  vector<size_t> support_;
  vector<size_t> thread_id_;
  vector<int> parent_id_;
  vector<size_t> graph_id_;
  const string output_file_;
};

}  // namespace gbolt

#endif  // INCLUDE_OUTPUT_H_
