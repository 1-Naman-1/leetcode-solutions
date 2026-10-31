class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        unordered_map<int, int> mpp1, mpp2;

        int ans = 0;

        while (j < n) {

            int a = nums[j];
            bool flag = false;

            if (mpp2.find(a) != mpp2.end()) {
                flag = true;
            }

            for (auto& it : mpp1) {
                int target = a + it.first;
                if (mpp1.find(target) != mpp1.end()) {
                    flag = true;
                    break;
                }
            }

            while (flag == true && i < j) {
                int b = nums[i];
                flag = false;

                mpp1[nums[i]]--;
                if (mpp1[nums[i]] == 0) {
                    mpp1.erase(nums[i]);
                }

                for (auto& it : mpp1) {
                    int num = b + it.first;
                    mpp2[num]-=it.second;
                    if (mpp2[num] <= 0) {
                        mpp2.erase(num);
                    }
                }

                if (mpp2.find(a) != mpp2.end()) {
                    flag = true;
                }

                for (auto& it : mpp1) {
                    int target = a + it.first;
                    if (mpp1.find(target) != mpp1.end()) {
                        flag = true;
                        break;
                    }
                }
                i++;
            }

            for (auto& it : mpp1) {
                int sum = a + it.first;
                mpp2[sum]+=it.second;
            }
            mpp1[a]++;

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};