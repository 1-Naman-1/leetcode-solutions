class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int i=0;
        int j=0;
        int n = arr.size();
        int sum=0;
        int ans=0;
        
        while(j<n){
            sum=sum+arr[j];
            if(j-i+1>k){
                sum=sum-arr[i];
                i++;
            }
            ans=max(ans,sum);
            j++;
        }
        return ans;
        
    }
};