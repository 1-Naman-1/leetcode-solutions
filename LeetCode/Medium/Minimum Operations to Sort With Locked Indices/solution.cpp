class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int cnt=0;
        int ans=0;
        int mx=0;
        
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            if(locked[i]==1 && (nums[i]!=i+1 || mx>nums[i])){
                locked[i]=0;
                cnt++;
            }
        }
        if(cnt>k){
            return -1;
        }
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(nums[i]>nums[j]){
            if(locked[i]==0 && locked[j]==0){
                swap(nums[i],nums[j]);
                cnt++;
            }
                else{
                    return -1;
                    
                }
                
            }
          }
        }


        return cnt;
        
    }
};