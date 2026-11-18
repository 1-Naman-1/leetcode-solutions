typedef long long int ll;

class Solution {
public:
    bool check(vector<int>& nums, int p, ll mid) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        ll cnt = 0;

        while (j < n) {
            if ((ll)nums[j] - (ll)nums[i] <= mid) {
                cnt++;
                i = i + 2;
                j = j + 2;
            } else {
                i++;
                j++;
            }
        }
        return cnt >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll low = 0;
        ll high = INT_MIN;

        for (int i = 0; i < n; i++) {
            high = max(high, (ll)nums[i]);
        }
        ll ans = 0;

        while (low <= high) {
            ll mid = (low + high) / 2;
            if (check(nums, p, mid) == true) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};