#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        while (left <= right){
        	int temp = left;
        	bool flag = true;
        	while (temp != 0){
        		int digit = temp%10;
        		if (digit == 0){
        			flag = false;
        			break;
        		}
        		if ( (left%digit) != 0 ){
        			flag = false;
        			break;
        		}
        		temp = temp/10;
        	}
        	if (flag){
        		ret.push_back(left);
        	}
        	left++;
        }
        return ret;
    }
};

int main(){
	Solution sol;
	vector<int> get = sol.selfDividingNumbers(1,22);
	for (unsigned int i=0;i<get.size();i++){
		cout<<get[i]<<" ";
	}
	cout<<endl;
	return 0;
}