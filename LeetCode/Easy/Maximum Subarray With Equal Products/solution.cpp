typedef long long int ll;


class Solution {
public:
    int maxLength(vector<int>& nums) {
       int n = nums.size();
       int ans=0;

       for(int i=0;i<n;i++){
        ll p =1;
        ll l = nums[i];
        ll g = nums[i];
        for(int j=i;j<n;j++){
            if(p>=LLONG_MAX/nums[j]){
                break;
            }
             p=p*nums[j];
             l = lcm(l,(ll)nums[j]);
             g = gcd(g,(ll)nums[j]);
             if(l*g==p){
                ans = max(ans,j-i+1);

             }
        }
       }

       return ans;

    }
};