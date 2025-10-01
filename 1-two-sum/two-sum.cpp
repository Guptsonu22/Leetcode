// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//          int n = nums.size();
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 if(nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         map<int , int > mp;
//         for(int i=0; i<n; i++){
//             int remaning = target-nums[i];
//             if(mp.find(remaning) != mp.end()){
//                 return {mp[remaning],i};
//             }
//             mp[nums[i]]=i;
//         }
//         return{};
        
//     }
// }; 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;          // value -> index
        mp.reserve(nums.size());            // optional: reduce rehashing
        for (int i = 0; i < (int)nums.size(); ++i) {
            int remaining = target - nums[i];
            auto it = mp.find(remaining);
            if (it != mp.end()) {
                return {it->second, i};
            }
            mp[nums[i]] = i;
        }
        return {}; // no pair found
    }
};