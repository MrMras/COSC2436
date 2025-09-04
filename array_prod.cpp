// Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num_of_zeroes = 0;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                num_of_zeroes++;
            }
            else {
                prod *= nums[i];
            }
        }
        vector<int> ans(nums.size(), 0);
        if (num_of_zeroes == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    ans[i] = prod;
                    break;
                }
            }
        }
        else if (!num_of_zeroes){
           for (int i = 0; i < nums.size(); i++) {
                ans[i] = prod / nums[i];
            } 
        }
        return ans;
    }
};