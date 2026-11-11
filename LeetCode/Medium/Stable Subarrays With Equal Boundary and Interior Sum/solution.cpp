class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();

        vector<long long> prefix(n, 0);
        prefix[0] = capacity[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + capacity[i];
        }

        map<pair<long long, long long>, long long> mpp;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long target = prefix[i] - (long long)2 * (long long)capacity[i];
            if (mpp.find({target, capacity[i]}) != mpp.end()) {
                ans = ans + mpp[{target, capacity[i]}];
            }

            if(i!=0 && capacity[i]==0 && capacity[i]==capacity[i-1]){
                ans=ans-1;

            }

            mpp[{prefix[i], capacity[i]}]++;
        }

        return ans;
    }
};