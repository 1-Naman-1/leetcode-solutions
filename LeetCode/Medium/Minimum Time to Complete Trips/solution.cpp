class Solution {
public:
    bool check(vector<int>& time, long long mid, int totalTrips) {
        long long cnt = 0;
        for (int t : time) {
            cnt += mid / t;
            if (cnt >= totalTrips) return true; 
        }
        return cnt >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(time, mid, totalTrips)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};