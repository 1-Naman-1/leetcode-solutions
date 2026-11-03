class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=0;
        int rmax=0;
        int l=0;
        int r=height.size()-1;
        int ans=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>lmax){
                    lmax=height[l];
                }
                else{
                    ans+=lmax-height[l];
                }
                l=l+1;
            }
            else{
                if(height[r]>rmax){
                    rmax=height[r];
                }
                else{
                    ans+=rmax-height[r];

                }
                r=r-1;

            }


        }
        return ans;

    }
};