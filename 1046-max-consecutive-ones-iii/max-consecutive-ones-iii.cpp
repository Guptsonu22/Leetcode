class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0 , j=0;
        int maxlen=0;
        int zeros=0;
        for(j=0; j<nums.size(); j++){
            if(nums[j] == 0)
            zeros++;
            while(zeros>k){
                if(nums[i] == 0)
                zeros --;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
        
    }
};