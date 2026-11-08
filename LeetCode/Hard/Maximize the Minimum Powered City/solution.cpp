class Solution {
public:
    bool check(vector<int>& stations, vector<long long>& diff, int r, int k,
               long long int mid) {

        int n = stations.size();
        long long int currsum = 0;
        vector<long long> d = diff;

        for (int i = 0; i < n; i++) {
            currsum = currsum + (long long)d[i];
            if (currsum < mid) {
                long long int need = mid - currsum;
                if (need <= k) {
                    currsum = currsum + need;
                    k = k - need;
                    if (i + (2 * r) + 1 < n) {
                        d[i + (2 * r) + 1] -= need;
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    };

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> diff(n, 0);
        long long int low = 0;
        long long int high = k;

        for (int i = 0; i < n; i++) {
            diff[max(0, i - r)] += stations[i];
            if (i + r + 1 < n) {
                diff[i + r + 1] -= stations[i];
            }
            high += (long long)stations[i];
            
        }
        long long int ans = 0;

        while (low <= high) {
            long long int mid = (low+high)/2;
            
            if (check(stations,diff,r,k,mid) == true) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};