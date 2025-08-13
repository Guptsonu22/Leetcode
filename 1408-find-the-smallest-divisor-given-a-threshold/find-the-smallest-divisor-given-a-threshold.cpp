class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
         int left = 1;
    int right = *max_element(nums.begin(), nums.end());
    auto computeSum = [&](int divisor) {
        long long total = 0;
        for (int num : nums) {
            total += (num + divisor - 1) / divisor; // ceiling division
        }
        return total;
    };
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (computeSum(mid) > threshold) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
    }
};