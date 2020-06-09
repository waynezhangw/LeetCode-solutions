#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	vector<int> ret;
    	return ret;
    }
};

int main () {
	Solution sol;
	vector<int> vec = {1,2,3,4};
	vector<int> ret;
	ret = sol.productExceptSelf(vec);
	for (unsigned int i=0;i<ret.size();i++) {
		cout<<ret[i]<<endl;
	}
	return 0;
}