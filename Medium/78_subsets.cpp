#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        return ret;
    }

    void printVec(const vector<vector<int>>& vec) {
    	for (unsigned int i = 0; i < vec.size(); i++) {
    		for (unsigned int j = 0; i < vec[i].size(); j++) {
    			cout << vec[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
};

int main() {
	Solution sol;
	vector<int> vec = {1, 2, 3};
	vector<vector<int>> ret = sol.subsets(vec);
	sol.printVec(ret);
	return 0;
}