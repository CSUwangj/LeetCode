#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;


class Solution {
  public:

  int left_color;
  int right_color;
  int min_color;
  int max_color;
  int balls_used;
  int balls_left;
  int number_of_balls;
  int number_of_colors;
  long long answer;
  long long c[50][50];
  vector < int > ball;

  void dfs(long long cur, int idx) {
    if (idx == number_of_colors) {
      if (left_color == right_color) {
        answer += cur;
      }
      return;
    }
    int minballs = max(number_of_balls / 2 - (balls_used + balls_left - ball[idx]), 0);
    int maxballs = min(number_of_balls / 2 - balls_used, ball[idx]);
    for (int i = minballs; i <= maxballs; i++) {
      balls_left -= ball[idx];
      balls_used += i;
      if (i == 0 && left_color <= max_color) {
        dfs(cur, idx + 1);
      } else if (i && i < ball[idx] && left_color < max_color) {
        left_color += 1;
        const long long new_cur = cur * c[ball[idx]][i];
        dfs(new_cur, idx + 1);
        left_color -= 1;
      } else if (i == ball[idx] && left_color < max_color && right_color > min_color) {
        left_color += 1;
        right_color -= 1;
        dfs(cur, idx + 1);
        right_color += 1;
        left_color -= 1;
      }
      balls_left += ball[idx];
      balls_used -= i;
    }
  }

  void init() {
    for (int i = 1; i < 50; i++) {
      c[i][i] = 1;
      c[i][0] = 1;
      for (int j = 1; j < i; ++j) {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      }
    }
  }

  void round_init() {
    number_of_colors = ball.size();
    number_of_balls = 0;
    int one = 0;
    for (int i = 0; i < number_of_colors; ++i) {
      if (ball[i] == 1) {
        one += 1;
      }
      number_of_balls += ball[i];
    }
    balls_left = number_of_balls;
    min_color = (number_of_colors + 1) / 2;
    max_color = number_of_colors - (one + 1) / 2;
    right_color = number_of_colors;
    left_color = 0;
    balls_used = 0;
    answer = 0;
  }

  double getProbability(vector < int > & balls) {
    ball = balls;
    init();
    round_init();
    dfs(1, 0);
    return 1.0 * answer / c[number_of_balls][number_of_balls / 2];
  }
};

int main() {
  vector<vector<int>> data = {
    {6,6,6,6,6,6},
    {3,2,1},
    {1,2,1,2}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.getProbability(data);
    cout << ans << endl;
  } 
  return 0;
}