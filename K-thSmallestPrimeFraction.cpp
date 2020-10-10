struct s {
    double val;
    int up;
    int dn;

    bool operator < (const s & b) {
        return val < b.val;
    }
}v[2000000];
class Solution {
    public:
        vector < int > kthSmallestPrimeFraction(vector < int > & A, int K) {

            vector < int > ans;
            int cnt = 0;
            for (int i = 1; i < A.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    v[cnt].val = 1.0 * A[j] / A[i];
                    v[cnt].up = A[j];
                    v[cnt].dn = A[i];
                    ++cnt;
                }
            }
            nth_element(v, v + K - 1, v + cnt);
            // for(int i=0;i<v.size();++i){
            //     cout<<v[i].up<<" "<<v[i].dn<<endl;
            // }
            ans.push_back(v[K - 1].up);
            ans.push_back(v[K - 1].dn);
            return ans;
        }
};
