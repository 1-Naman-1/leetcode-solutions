class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        unordered_map<int,int> mpp;
        long long sum=0;
        long long ans=0;


        while(j<n){
            sum=sum+nums[j];
            while(j-i+1>k || mpp.find(nums[j])!=mpp.end()){
                sum=sum-nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            if(j-i+1==k && mpp.find(nums[j])==mpp.end()){
                ans = max(ans,sum);
            }
          mpp[nums[j]]++;
          j++;
        }
        return ans;

    }
};