class Solution {
  public:
  
    bool check(vector<int> &arr,int k,int mid){
        int i=0;
        int j=0;
        int cnt=1;
        int n = arr.size();
        
        while(j<n){
            if(arr[j]-arr[i]>=mid){
                i=j;
                cnt++;
            }
            j++;
        }
        return cnt>=k;
        
    }
        
    
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n==0){
            return 0;
            
        }
         
        sort(arr.begin(),arr.end());
        int ans=0;
        int low = 0;
        int high = arr[n-1];
        while(low<=high){
            int mid = (low+high)/2;
            if(check(arr,k,mid)==true){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};