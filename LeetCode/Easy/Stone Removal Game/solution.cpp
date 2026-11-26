class Solution {
public:
    bool canAliceWin(int n) {
        for(int i=10;i>=1;i--){
            int a = n-i;
            if(a<0){
                if(i%2==0){
                    return false;
                }
                else{
                    return true;
                }
            }
            n=n-i;

        }
        return false;

    }
};