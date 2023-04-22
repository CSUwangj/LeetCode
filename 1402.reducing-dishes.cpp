class Solution {
public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());

    int answer = 0;
    int count = 0;
    int sum = 0;
    for(auto sat : satisfaction) {
      if(sum + sat < 0) break;
      answer += sum + sat;
      sum += sat;
    }
    return answer;
  }
};