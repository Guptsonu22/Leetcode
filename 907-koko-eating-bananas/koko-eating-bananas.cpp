class Solution {
public:
 long long totalHours(vector<int>& piles, int speed) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + speed - 1) / speed; // ceil division
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
         int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (totalHours(piles, mid) <= h) {
                ans = mid; // possible answer
                high = mid - 1; // try smaller speed
            } else {
                low = mid + 1; // need faster eating
            }
        }
        return ans;
    }
};