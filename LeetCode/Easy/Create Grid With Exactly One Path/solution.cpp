class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s="";
        string a="";

        for(int i=0;i<n;i++){
            s=s+'.';
            a=a+'#';
        }

        vector<string> ans;
        a[n-1]='.';
        ans.push_back(s);
        for(int i=1;i<m;i++){
            ans.push_back(a);
        }
        return ans;

    }
};