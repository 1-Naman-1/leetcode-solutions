class Solution {
public:

    bool check(vector<int> &arr,int mid,int d){
	long long int h=0;
	
	for(int i=0;i<arr.size();i++){
		
        h+=ceil((double)arr[i]/mid);

		if(h>d){
			return false;
		}
	}
	return true;
	
}

    int minEatingSpeed(vector<int>& arr, int d) {
    int low=1;
	int high=INT_MIN;
    int n = arr.size();

	
	for(int i=0;i<n;i++){
		high=max(high,arr[i]);
	}
    int ans=0;

	
	while(low<=high){
		int mid = (low+high)/2;
		if(check(arr,mid,d)){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	
	return ans;
    }
};