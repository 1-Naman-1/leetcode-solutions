class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        vector<int> arr(3, -1);
        int i = 0;
        int j = 0;
        long long int ans = 0;
        vector<int> mpp;
        if(n==1){
            return 1;
        }
        if(n==2){
            return 3;

        }

        
        while (j < n) {

            if(s[j]=='a'){
                mpp.push_back(j);
            }

            else if(s[j]=='b' && mpp.size()>0){
           
                arr[0]=mpp.back();
                arr[1]=j;
            }

            else if(s[j]=='c' && arr[0]!=-1 && arr[1]!=-1){
                  i=arr[0]+1;
                  arr[0]=mpp.back();
                  arr[1]=-1;
                  arr[2]=-1;
                  

            }
            ans = ans + j - i + 1;
            j++;

        }
        return ans;
    }
};