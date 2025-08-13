class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0;   // number before the first element
    int missingCount = 0;
    for (int num : arr) {
        int missing = num - prev - 1;
        if (missingCount + missing >= k) {
            return prev + (k - missingCount);
        }
        missingCount += missing;
        prev = num;
    }
    return arr.back() + (k - missingCount);
    }
};