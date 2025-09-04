#include <unordered_map>

// Problem Name: Two Sum
// Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash = {};
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (hash[target - nums[i]] == 0) {
                hash[nums[i]] = i + 1;
                
            }
            else {
                ans = { hash[target - nums[i]] - 1, i};
                break;
            }
        }
        return ans;
    }
};