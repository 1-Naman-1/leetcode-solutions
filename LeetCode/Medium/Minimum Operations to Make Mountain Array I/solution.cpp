

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return -1;
        }
        vector<vector<int>> dpl(n+1,vector<int>(2000+1,1e8));
        vector<vector<int>> prefix(n+1,vector<int>(2000+1,1e8));
        vector<vector<int>> suffix(n+1,vector<int>(2000+1,1e8));

        for(int i=1;i<=2000;i++){
            dpl[0][i]=abs(nums[0]-i);
            prefix[0][i]=min(prefix[0][i-1],dpl[0][i]);


        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=2000;j++){
                    int cost = abs(nums[i]-j) + prefix[i-1][j-1];
                    dpl[i][j]=min(dpl[i][j],cost);
                    prefix[i][j]=min(prefix[i][j-1],dpl[i][j]);

                
            }
        }

        vector<vector<int>> dpr(n+1,vector<int>(2000+1,1e8));
        for(int i=1;i<=2000;i++){
            dpr[n-1][i]=abs(nums[n-1]-i);
            suffix[n-1][i]=min(suffix[n-1][i-1],dpr[n-1][i]);
        }

        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=2000;j++){
                
                    int cost = abs(nums[i]-j) + suffix[i+1][j-1];
                    dpr[i][j]=min(dpr[i][j],cost);
                    suffix[i][j]=min(suffix[i][j-1],dpr[i][j]);

                
            }
        }


        int ans=1e8;


        for(int i=1;i<=n-2;i++){
            
            for(int j=1;j<=2000;j++){
                int first = abs(nums[i]-j);
                int second = prefix[i-1][j-1];
                int third = suffix[i+1][j-1];
                ans=min(ans,first+second+third);
            }
        }
        if(ans==1e8){
            return -1;
        }
        return ans;






    }
};

// int n = nums.size();
//         if(n<3){
//             return -1;
//         }
//         vector<int> prefix(n,0);
//         vector<int> suffix(n,0);

//         prefix[0]=nums[0];
//         for(int i=1;i<n;i++){
//             prefix[i]=max(prefix[i-1],nums[i]);
//         }

//         suffix[n-1]=nums[n-1];
//         for(int i=n-2;i>=0;i--){
//             suffix[i]=max(suffix[i+1],nums[i]);

//         }
//         int ans = INT_MAX;

//         for(int i=1;i<n-1;i++){
//            int a = prefix[i-1];
//            int b = suffix[i+1];
//            int maxi = max(a,b);

//            int diff = maxi - nums[i] + 1;

//         if(diff<=0){
//             diff=INT_MAX;
            
//            }

//            ans = min(ans,diff);
//         }

//         return ans;
