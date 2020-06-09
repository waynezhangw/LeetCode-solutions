#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;
using std::cout;
using std::endl;
class Solution {
public:
    int majorityElement(vector<int>& nums) {   //百度的摩尔投票算法
        int major = 0;
        int count = 0;
        for (unsigned int i=0;i<nums.size();i++) {
            if (count == 0) {
                major = nums[i];
                count++;
            }
            else {
                if (nums[i] == major) {
                    count++;
                }
                else {
                    count--;
                }
            }
        }
        return major;
    }
    int majorityElement2(vector<int>& nums) {     //看了别人的解法，用insert就巨慢
        map<int,int> freq;
        std::pair<map<int,int>::iterator,bool> ret;
        for (unsigned int i=0;i<nums.size();i++) {
            ret = freq.insert(std::pair<int,int>(nums[i],1));
            if (ret.second == false) {
                freq[nums[i]]++;
            }
            if(freq[nums[i]] > int(nums.size()/2)) {
                return nums[i];
            }
        }
        return 0;
    }
    int majorityElement3(vector<int>& nums) {     //直接抄了别人的解法
        map<int,int> freq;
        for (unsigned int i=0;i<nums.size();i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] > int(nums.size()/2)) {
                return nums[i];
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> test = {3,1,3};
    cout<<sol.majorityElement3(test)<<endl;
    return 0;
}