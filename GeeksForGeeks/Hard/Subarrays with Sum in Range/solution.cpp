class Solution {
  public:
  
  int sub(vector<int>& arr , int target){
      int i=0;
      int j=0;
      int n=arr.size();
      int sum=0;
      int count=0;
      
      
      while(j<n){
         sum = sum + arr[j];
         while(sum>target){
             sum = sum - arr[i];
             i++;
             
         }
         
         count += j-i+1;
         j++;
      }
      return count;
      
  }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        
        int y = sub(arr,r);
        int x = sub(arr,l-1);
        return y-x;
        
        
        
    }
};