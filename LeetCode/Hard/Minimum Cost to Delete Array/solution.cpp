typedef long long int ll;

class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        ll sum = nums[0] + nums[n-1];
        int cnt = 0;
        ll temp = 0;
        int mini = INT_MAX;
        int pos = INT_MAX;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] < 0) {
                temp += (ll)nums[i];
                mini = min(mini, abs(nums[i]));
                cnt++;
            } else {
                pos = min(pos, nums[i]);
            }
        }

        if (cnt % 2 == 0) {
            return sum + temp;
        }

        ll a = sum + temp + (ll)mini;

        ll b = sum + temp + (ll)pos;
        return min(a, b);
    }
};