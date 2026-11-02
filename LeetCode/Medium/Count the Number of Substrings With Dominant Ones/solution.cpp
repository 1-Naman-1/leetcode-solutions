class Solution {
public:
    int count(string &s, vector<int>& z, int st, int en) {
        int idx = st + en - 1;
        int i = z[st];
        int j = z[idx];

        int m = st == 0 ? -1 : z[st - 1];
        int cnt = 0;
        int nxt = idx+1<z.size() ? z[idx+1] : s.size();


        for (int a = m + 1; a <= i; a++) {
            int tot = nxt-1 - a + 1 - en;
            int need = en * en - tot;

            if (need <= 0) {
                int lo = max(j, a + en * en + en - 1);
                cnt=cnt+nxt-lo;
            } else {
                break;
            }
        }

        return cnt;
    };

    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> z;
        int ans = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                z.push_back(j);
                i = j + 1;
            } else {
                ans = ans + j - i + 1;
            }
        }

        for (int i = 1; i <= z.size() && i * i <= n; i++) {
            int k = i;
            int j = 0;

            while (j + k <= z.size()) {
                ans += count(s, z, j, k);
                j++;
            }
        }
        return ans;
    }
};