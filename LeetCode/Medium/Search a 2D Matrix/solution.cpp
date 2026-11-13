class Solution {
public:

    int row(vector<vector<int>>& mat, int target){
        int n = mat.size();
        int m = mat[0].size();
        int l1=0;
        int h1=n-1;

        while(l1<=h1){
            int mid = (l1+h1)/2;
            int a = mat[mid][0];
            int b = mat[mid][m-1];

            if(target>=a && target<=b){
                    return mid;
            }
            if(target>mat[mid][m-1]){
                l1=mid+1;
            }
            if(target<mat[mid][0]){
                h1=mid-1;
            }
        }
return -1;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
       int row_number = row(mat,target);
        int n = mat.size();
        int m = mat[0].size();
        int low=0;
        int high=m-1;
        if(row_number==-1){
            return false;

        }
        while(low<=high){
            int mid = (low+high)/2;
            if(mat[row_number][mid]==target){
                return true;
            }
            if(mat[row_number][mid]>target){
                high=mid-1;
            }
          if(mat[row_number][mid]<target){
            low=mid+1;
          }
        }
       return false;

    }
};