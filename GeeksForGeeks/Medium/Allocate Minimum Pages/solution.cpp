class Solution {
public:

    bool check(vector<int> &arr, int k, long long mid) {
        int cnt = 1;
        int n = arr.size();
        long long sum = 0;

        int j = 0;

        while(j < n) {
            if(sum + arr[j] > mid) {
                cnt++;
                sum = arr[j];
            }
            else {
                sum += arr[j];
            }

            if(cnt > k) return false;

            j++;
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        if(n < k) return -1;

        long long low = INT_MIN;
        long long high = 0;
        long long ans = -1;

        for(int i = 0; i < n; i++) {
            low = max(low, (long long)arr[i]);
            high += arr[i];
        }

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(check(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};