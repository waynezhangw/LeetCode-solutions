#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> result;
        int permuteNum = 1;
        for (unsigned int i=1;i<=nums.size();i++) {
        	permuteNum = permuteNum*i;
        }
        cout<<"iteration:"<<permuteNum<<"  vs  tgamma:"<<tgamma(nums.size()+1)<<endl;
        permute_recursion(nums, 0, result);
        return result;
    }

    void permute_recursion(vector<int>& nums, int begin, vector<vector<int>> &result){ //如果看不懂就按照{1, 2, 3}这个输入在脑子里走一遍递归过程
    	if (begin >= (int)nums.size()) {
    		result.push_back(nums);
    		return;
    	}
    	else {
    		for (int i=begin;i<(int)nums.size();i++) {      //这层for为了以begin开头（num里所有的值开头）搞一遍
    			swap(nums[begin], nums[i]);
    			permute_recursion(nums, begin+1, result);
    			swap(nums[begin], nums[i]);
    		}
    	}
    }

    void seeVector(vector<vector<int>> result) {
    	for (unsigned int i=0;i<result.size();i++) {
    		for (unsigned int j=0;j<result[0].size();j++) {
    			cout<<result[i][j]<<",";
    		}
    		cout<<endl;
    	}
    	cout<<endl;
    }
};

int main() {
	Solution sol;
	vector<int> v1 = {1, 2, 3, 4};
	sol.seeVector(sol.permute(v1));
	return 0;
}