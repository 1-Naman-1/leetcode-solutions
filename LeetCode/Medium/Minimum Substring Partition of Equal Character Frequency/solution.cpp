class Solution {
public:
     bool check(vector<int> &b){
        int last=0;
         int idx=0;

        for(int i=0;i<26;i++){
            if(b[i]==0){
                continue;
            }
            if(b[i]>0){
                last=b[i];
                idx=i;
                break;
            }
        }

        for(int j=idx;j<26;j++){
            if(b[j]==0){
                continue;
            }
            else if(b[j]!=last){
                return false;
            }
        }

        return true;
     }

    int minimumSubstringsInPartition(string s) {
        int n = s.size();

        vector<int> dp(n+1,INT_MAX);
        dp[0]=1;

        for(int i=1;i<n;i++){
           vector<int> b(26,0);
            for(int j=i;j>=1;j--){
                b[s[j]-'a']++;
                if(check(b)==true){
                    int p = 1 + dp[j-1];
                    dp[i]=min(dp[i],p);

                }
            }
            b[s[0]-'a']++;
            if(check(b)==true){
                dp[i]=min(dp[i],1);
            }

        }
      return dp[n-1];

    }
};