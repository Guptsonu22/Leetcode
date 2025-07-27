class Solution {
public:
    int numberOfSubstrings(string s) {
         int freq[3] = {0};  // Only for 'a', 'b', 'c'
        int count = 0;
        int curCount = 0;
        int left = 0;
        int n = s.length();

        for (int right = 0; right < n; right++) {
            char ch = s[right];
            if (freq[ch - 'a'] == 0) curCount++;
            freq[ch - 'a']++;

            while (curCount == 3) {
                count += (n - right);
                char c = s[left];
                freq[c - 'a']--;
                if (freq[c - 'a'] == 0) curCount--;
                left++;
            }
        }

        return count;
    }
};