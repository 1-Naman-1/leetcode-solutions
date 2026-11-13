class Solution {
  public:
    bool isSubSeq(string& s, string& t) {
        // code here
        int i=0;
                int j=0;
                int n = s.size();
                int m = t.size();

                while(i<n && j<m){
                    if(s[i]==t[j]){
                        i++;
                     }
                     j++;

                }
                return i==n;
        
    }
};