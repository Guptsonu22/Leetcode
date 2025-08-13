class Solution {
public:
   bool canShip(const vector<int>& weights, int capacity, int days) {
        int currentLoad = 0;
        int dayCount = 1; // start from day 1
        for (int w : weights) {
            if (currentLoad + w <= capacity) {
                currentLoad += w;
            } else {
                dayCount++;
                currentLoad = w;
                if (dayCount > days) return false; // need more days than allowed
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for (int w : weights) right += w;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};