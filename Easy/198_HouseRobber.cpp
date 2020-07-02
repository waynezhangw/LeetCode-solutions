#include<iostream>
#include<vector>
#include <algorithm>    // std::max

using std::vector;
class Solution {
public:
    int rob(vector<int>& nums) {            //from discussion idea and implemented by myself, 46.01% and 10.91%
        if (nums.empty()) return 0;
        vector<int> history(nums.size(), -1);  //if no history will cause Time Limit Exceeded because of redundancy
        return robChoice(0, nums, history);
    }
    int robChoice(int start, vector<int>& nums, vector<int>& history) {
        if (start > (int)nums.size() - 1) return 0;
        if (history[start] >= 0) return history[start];
        int choice1 = robChoice(start + 1, nums, history);
        int choice2 = robChoice(start + 2, nums, history);
        history[start] = std::max(choice1, choice2 + nums[start]);
        return history[start];
    }

    int rob2(vector<int>& nums) {         //from discussion, iterative method, 46.01% and 46.72%
        if (nums.empty()) return 0;
        vector<int> history(nums.size()+1, 0);
        history[nums.size()] = 0;
        history[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            int robMoney = nums[i];
            history[i] = std::max(history[i+1], history[i + 2] + robMoney);
        }
        return history[0];
    }

    int rob3(vector<int>& nums) {         //from discussion, 2 variables method, 46.01% and 84.41%
        if (nums.empty()) return 0;
        int last1 = 0;
        int last2 = nums[nums.size() - 1];
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            int robMoney = nums[i];
            int temp = last2;
            last2 = std::max(last2, last1 + robMoney);
            last1 = temp;
        }
        return last2;
    }

    int rob4(vector<int>& nums) {         //copied from details, 46.01% and 21.19%
        if (nums.size()==0) return 0;     
        else if(nums.size()==1) return nums[0];          
        else if(nums.size()==2) return std::max(nums[0], nums[1]);
        vector<int> dp(nums.size());    
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);  
        for(int i=2; i<(int)nums.size(); i++) {
            dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2,7,9,1,3,10,4 };
    // vector<int> nums = { 226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,
    //     43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,
    //     209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,
    //     192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,
    //     219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
    std::cout << sol.rob4(nums) << std::endl;
    return 0;
}