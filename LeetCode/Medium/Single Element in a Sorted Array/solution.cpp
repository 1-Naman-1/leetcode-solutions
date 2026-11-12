class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=0;
        int high=n-1;
        int idx=n-1;

        if(n==1){
            return nums[0];
        }

        
        while(low<high){
          int mid = low+(high-low)/2;
          if(mid%2!=0){
            if(nums[mid]==nums[mid-1]){
                low=mid+1;
            }
            else{
                idx=mid;
                high=mid;
            }
          }
          else{
              if(nums[mid]==nums[mid+1]){
                low=mid+1;
              }
              else{
                high=mid;
                idx=mid;
              }
          }
        }

        return nums[idx];


    }
};