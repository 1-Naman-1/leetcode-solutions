class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> prev,curr,result;
        for(int i=0;i<n;i++){
            for(auto &it : prev){
                curr.insert(arr[i]|it);
                result.insert(arr[i]|it);
            }
                    curr.insert(arr[i]);
        result.insert(arr[i]);
        prev=curr;
        curr.clear();
        }

return result.size();
    }

    

};