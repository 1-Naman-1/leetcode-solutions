class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k){
            return s;
        }
        

        while(s.size()>k){
          int i=0;
          int j=0;
          string s1="";
          int num=0;

          while(j<s.size()){
             int a = s[j]-'0';

             num+=a;
             if(j-i+1==k){
                s1=s1+to_string(num);
                num=0;
                i=j+1;
             }
             j++;
          }
          if(s.size()%k!=0){
            s1=s1+to_string(num);
          }
          s=s1;
        }
        return s;

    }
};