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
  int len = 2000;
  int count = 2000;
  string charset = "qwertyuiopasdfghjklzxcvbnm";
  vector<string> data(count);
  for(auto &s : data) s.push_back('"');
  int cur_base = 1;
  for(int i = 0; i < len; ++i) {
    for(int j = 0; j < count; ++j) {
      data[j].push_back(charset[j / cur_base % charset.length()]);
    }
    cur_base *= charset.length();
    cur_base = min(len, cur_base);
  }
  for(auto &s : data) s.push_back('"');
  post_process(data);
  cout << data << endl;
  return 0;
}