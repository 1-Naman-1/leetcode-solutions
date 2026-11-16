class Solution {
public:
    bool check(vector<int> &nums,int mid , int k){
        int n = nums.size();
        
        for(int i=0;i<n;i++){
             if(nums[i]<=mid){
                k--;
                i++;
             }
        }
        if(k<=0){
            return true;
        }
        return false;


    }
    int minCapability(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxi=max(maxi,nums[i]);

        }


        int low = mini;
        int high=maxi;
        int ans=0;

        while(low<=high){
            int mid = (low+high)/2;
            if(check(nums,mid,k)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};