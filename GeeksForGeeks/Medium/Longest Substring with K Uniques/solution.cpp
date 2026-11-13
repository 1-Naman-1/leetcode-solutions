class Solution {
  public:
    int longestKSubstr(string &nums, int k) {
        // code here
        int n = nums.size();
        unordered_map<char,int> mpp;
        int i=0;
        int j=0;
        int ans=-1;
        
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                    
                }
                i++;
            }
            if(mpp.size()==k){
                ans=max(ans,j-i+1);
            }
            j++;
            
        }
        return ans;
        
        
    }
};