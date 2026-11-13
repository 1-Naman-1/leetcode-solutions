class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,1);
        vector<int> suffix(n+1,1);
        for(int i=1;i<=n;i++){
            if(prefix[i-1]==0){
                prefix[i]=nums[i-1];
            }
            else{
            prefix[i]=prefix[i-1]*nums[i-1];}

        }
        for(int i=n-1;i>=0;i--){
            
           if(suffix[i+1]==0){
            suffix[i]=nums[i];
           }
           else{
           suffix[i]=suffix[i+1]*nums[i];}
        }

        prefix[0]=INT_MIN;
        suffix[n]=INT_MIN;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==0){
                ans=max(ans,suffix[i]);
            }
            ans=max(ans,max(prefix[i],suffix[i]));

        }
        return ans;


    }
};