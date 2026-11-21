
class Solution {
public:
    long long calculate(long long mid, long long cnt) {
        if(mid > cnt) {
            return (mid - 1 + mid - cnt) * cnt / 2;
        }

        return mid * (mid - 1) / 2 + cnt - mid + 1;
    }

    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum;
        long long ans = 1;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            long long sum = mid;
            sum += calculate(mid, index);
            sum += calculate(mid, n - index - 1);

            if(sum <= maxSum) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
