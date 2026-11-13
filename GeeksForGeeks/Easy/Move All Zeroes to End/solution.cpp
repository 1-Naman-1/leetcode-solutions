class Solution {
  public:
    void pushZerosToEnd(vector<int>& nums) {
        // code here
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            while(i<n && j<<n && nums[i]!=0){
                i++;
                j++;
                
            }
            while(j<n && nums[j]==0){
                j++;
            }
            if(j==n){
                break;
            }
            swap(nums[i],nums[j]);
            i++;
            j++;
            
            
            
        }
    }
};