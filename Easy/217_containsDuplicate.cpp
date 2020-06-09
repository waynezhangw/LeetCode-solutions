#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::set;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {    //the time complexity and space complexity is both high
        set<int> unique;
        std::pair<set<int>::iterator, bool> ret;
        for (unsigned int i=0;i<nums.size();i++) {
        	ret = unique.insert(nums[i]);
        	if (ret.second == false) return true;
        }
        return false;
    }
    bool containsDuplicate2(vector<int>& nums) {    //one line solution from other people's comments
        return nums.size() > set<int> (nums.begin(), nums.end()).size();
    }
    bool containsDuplicate3(vector<int>& nums) {    //when I saw others sorting method
        if (nums.size()<=1) return false;
        sort(nums.begin(), nums.end());
        for (unsigned int i=0;i<nums.size()-1;i++) {
        	if (nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};

int main()
{
	Solution sol;
	vector<int> abc = {1,2,3,5,1};
	cout<<sol.containsDuplicate3(abc)<<endl;
	return 0;
}