class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ans1=1;
        int ans2=1;
        

         int i=0;
         int j=1;
         while(j<n){

            if(nums[j]<=nums[j-1]){
                i=j;
            }

            ans1=max(ans1,j-i+1);
            j++;


         }

         i=0;
         j=1;
        while(j<n){

            if(nums[j]>=nums[j-1]){
                i=j;
            }

            ans2=max(ans2,j-i+1);
            j++;

         }

         return max(ans1,ans2);

    }
};