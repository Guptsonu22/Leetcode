class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xxory = 0;
        for (int n : nums) {
            xxory ^= n;
        }
         unsigned int mask = (unsigned int) xxory & (-(unsigned int)       xxory);
        vector<int> result = {0, 0};
        for (int n : nums) {
            if ((n & mask) == 0)
                result[1] ^= n;
            else
                result[0] ^= n;
        }

        return result;
    }
};
