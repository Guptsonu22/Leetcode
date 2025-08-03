// class Solution {
// public:
//     vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
//         unordered_map<int, int> mp;
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == x) {
//                 count++;
//                 mp[count] = i;  
//             }
//         }
//         vector<int> ans;
//         for (int i : queries) {
//             if (mp.find(i) == mp.end()) {
//                 ans.push_back(-1);
//             } else {
//                 ans.push_back(mp[i]); 
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> positions;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                positions.push_back(i);
            }
        }
        vector<int> ans;
        for (int q : queries) {
            if (q <= positions.size()) {
                ans.push_back(positions[q - 1]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
