class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i =0;
        int j=n-1;
        return min(nums[j-1]-nums[i+1],min(nums[j-2]-nums[0],nums[j]-nums[i+2]));
    }
};