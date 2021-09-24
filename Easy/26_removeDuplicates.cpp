#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {  //12 ms, faster than 65.81%, 18.5 MB, less than 36.38%
        if (nums.size() <= 1) return int(nums.size());
        int index = 0;
        for (unsigned int i = 0; i < nums.size(); i++) { // to be exchange
            if (index >= int(nums.size())) return i;
            for (unsigned int j = index; j < nums.size(); j++) {  // move forward constantly
                if (nums[j] == nums[index]) {
                    if (j == nums.size() - 1) {
                        index = j + 1;
                        break;
                    }
                    continue;
                } else {
                    index = j;
                    break;
                }
            }
            nums[i] = nums[index-1];
            if (i == nums.size() -1) return i+1;
        }
        return 0;  //should never come here
    }

    // after watching the official Solution
    int removeDuplicates2(vector<int>& nums) {  //16 ms, faster than 39.81%, 18.3 MB, less than 93.95%
        if (nums.size() <= 1) return int(nums.size());
        int exchangeIndex = 1;
        for (unsigned int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                continue;
            } else {
                nums[exchangeIndex] = nums[i];
                exchangeIndex++;
            }
        }
        return exchangeIndex;
    }

    // after seeing the original code of official Solution
    int removeDuplicates3(vector<int>& nums) {  //16 ms, faster than 39.81%, 18.3 MB, less than 93.95%
        int n = nums.size();
        if (n <= 1) return n;
        int exchangeIndex = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                nums[exchangeIndex] = nums[i];
                exchangeIndex++;
            }
        }
        return exchangeIndex;
    }

    // after copying the original code of 0 ms solution
    int removeDuplicates4(vector<int>& nums) {  //4 ms, faster than 99.07%, 18.2 MB, less than 93.95%
        int n = nums.size(), pre = 0, cur = 0; 
        while(cur < n){
            if(nums[pre] == nums[cur]) cur++;
            else{
                nums[++pre] = nums[cur++]; 
            }
        }
        return nums.empty() ? 0 : pre + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << sol.removeDuplicates4(nums) << endl;
    cout << "results:" << endl;
    for (unsigned int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
