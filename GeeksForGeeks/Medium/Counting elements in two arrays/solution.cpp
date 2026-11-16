class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(),b.end());
        int n = a.size();
       
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int cnt=upper_bound(b.begin(),b.end(),a[i])-b.begin();
            ans.push_back(cnt);
        }
        return ans;
        
    }
};