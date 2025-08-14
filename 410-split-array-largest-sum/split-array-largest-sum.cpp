class Solution {
public:
    bool canSplit(vector<int> &nums, int k, long long limit) {
        int count = 1;
        long long sum = 0;
        for (int num : nums) {
            if (sum + num > limit) {
                count++;
                sum = num;
                if (count > k) return false;
            } else {
                sum += num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1; // try smaller max
            } else {
                low = mid + 1; // need larger max
            }
        }
        return (int)ans;
    }
};
