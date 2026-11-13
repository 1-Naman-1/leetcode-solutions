class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        
        
        unordered_map<int,int> mpp;
        mpp[0]++;
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int target = prefix[i]-k;
            if(mpp.find(target)!=mpp.end()){
                ans+=mpp[target];
            }
            mpp[prefix[i]]++;
            
        }
        
        return ans;
        
    }
};