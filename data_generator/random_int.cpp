#include <bits/stdc++.h>

using namespace std;
template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}

int main() {
    random_device r;
 
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(1, 10000);
    vector<int> result;
    int len = uniform_dist(e1);
    for(int i = 0; i < 20; ++i) {
      result.push_back(uniform_dist(e1));
    }
    cout << result << endl;
}