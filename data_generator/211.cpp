#include <bits/stdc++.h>

using namespace std;
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
void post_process(vector<string> &data) {
  for(auto &s : data) {
    reverse(s.begin(), s.end());
  }
}

int main() {
  int len = 100;
  int count = 25000 - 1;
  string charset = "qwertyuiopasdfghjklxcvbnm";
  vector<string> data(count);
  int cur_base = 1;
  for(int i = 0; i < len; ++i) {
    for(int j = 0; j < count; ++j) {
      data[j].push_back(charset[j / cur_base % charset.length()]);
    }
    cur_base *= charset.length();
    cur_base = min(len, cur_base);
  }
  post_process(data);
  data.push_back(string(100, 'z'));
  const string badSearch = string(99, '.') + "z";
  cout << "[\"WordDictionary\"";
  for(int i = 0; i < 25000; ++i) {
    cout << ",\"addWord\"";
  }
  for(int i = 0; i < 25000; ++i) {
    cout << ",\"search\"";
  }
  cout << "]" << endl << "[[]";
  for(auto &word : data) {
    cout << ",[\"" << word << "\"]";
  }
  for(int i = 0; i < 25000; ++i) {
    cout << ",[\"" << badSearch << "\"]";
  }
  cout << "]" << endl;
  return 0;
}