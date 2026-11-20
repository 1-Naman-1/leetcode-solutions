class Solution {
public:
    bool check(vector<int>& nums, long long mid) {
        int n = nums.size();
        long long left = 0;

        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] + left > mid) {
                left = (nums[i] + left) - mid;
            } else {
                left = 0;
            }
        }

        return nums[0] + left <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        long long low = nums[0];
        long long high = *max_element(nums.begin(), nums.end());
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};