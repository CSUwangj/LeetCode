#include<bits/stdc++.h>

using namespace std;

const int SZ = (1 << 20);

int pre[SZ][20];
int overlap[20][20];

using ti = tuple<int, int, int, int>;

void init(vector<string> &words) {
    for(int i = 0; i < words.size(); ++i) {
        for(int j = 0; j < words.size(); ++j) {
            if(i == j) continue;
            overlap[i][j] = 0;
            for(int k = min(words[i].length(), words[j].length()) - 1; k > 0; --k) {
                if(words[i].substr(words[i].length() - k) == words[j].substr(0, k)) {
                    overlap[i][j] = k;
                    break;
                }
            }
        }
    }
}

string constructAnswer(vector<string> &words, int state, int last) {
    string answer = words[last];
    while(pre[state][last] != -1) {
        // cout << state << ' ' << last << endl;
        int p = pre[state][last];
        state ^= (1 << last);
        answer = words[p].substr(0, words[p].length() - overlap[p][last]) + answer;
        last = p;
    }
    return answer;
}

string solve(vector<string> &words) {
    memset(pre, 0, sizeof(pre));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    int len = words.size();
    int target = (1 << len) - 1;
    for(int i = 0; i < len; ++i) {
        pq.push({words[i].length(), 1 << i, -1, i});
    }
    while(pq.size()) {
        auto [length, state, p, last] = pq.top();
        pq.pop();
        if(pre[state][last]) continue;
        pre[state][last] = p;
        if(state == target) return constructAnswer(words, state, last);
        for(int i = 0; i < len; ++i) {
            if(state & (1 << i)) continue;
            pq.push({length + words[i].length() - overlap[last][i], state | (1 << i), last, i});
        }
    }
    return "";
}

int main() {
    vector<vector<string>> test= {
        {"catg","ctaagt","gcta","ttca","atgcatc"},
    };
    int c = 0;
    for(auto &data : test) {
        init(data);
        cout << "Case " << c++ << ": " << solve(data) << endl;
    }
    return 0;
}