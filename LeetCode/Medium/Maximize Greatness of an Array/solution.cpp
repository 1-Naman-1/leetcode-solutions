class Solution {
public:

bool check(vector<int> &arr,int mid){
	int n = arr.size();
	int i = n-mid;

	int j=0;
	
	while(i<n){
		if(arr[j]>=arr[i]){
			return false;
		}
		i++;
		j++;
	}
	return true;
	
}
    int maximizeGreatness(vector<int>& arr) {
    int n = arr.size();
    
    sort(arr.begin(),arr.end());
	int low=0;
	int high=n-1;
	int ans=0;
	
	while(low<=high){
		
		int mid = (low+high)/2;
		
		if(check(arr,mid)==true){
			ans = mid;
			low=mid+1;
			
		}
		else{
			high=mid-1;
			
		}
	}
    return ans;

    }
};