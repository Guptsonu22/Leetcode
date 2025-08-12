class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalNeeded = 1LL * m * k;
        if (bloomDay.size() < totalNeeded) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if we can make m bouquets by day mid
            int bouquets = 0, flowers = 0;
            for (int b : bloomDay) {
                if (b <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
            if (bouquets >= m) {
                ans = mid;
                high = mid - 1; // try earlier day
            } else {
                low = mid + 1; // need more days
            }
        }
        return ans;
    }
};