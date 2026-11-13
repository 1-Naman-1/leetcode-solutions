class Solution {
  public:
  
    int count(vector<vector<int>> &mat,int mid){
        int n = mat.size();
        int a=0;
        for(int i=0;i<n;i++){
           a+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
           
        }
        return a;
        
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int x = (n*m)/2;
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            if(count(mat,mid)>x){
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
