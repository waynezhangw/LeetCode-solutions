#include<iostream>
#include<vector>
#include<algorithm> //copy
#include<iterator>  //ostream_iterator

using std::vector;
using std::cout;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> temp = {1};
        for (int i=0; i<numRows; i++,temp.clear()) {
        	if (i==0) {
        		ret.push_back(temp);
        	}
        	else {
        		vector<int> lastRow = ret[ret.size()-1];
        		if (lastRow.size()==1) {
        			temp = {1,1};
        		}
        		else {
        			temp.push_back(1);
        			for (vector<int>::size_type j=0; j<lastRow.size()-1;j++) {
        				temp.push_back(lastRow[j]+lastRow[j+1]);
        			}
        			temp.push_back(1);
        		}
        		ret.push_back(temp);
        	}
        }
        return ret;
    }
    vector<vector<int>> generate2(int numRows) {          //others submission
        vector<vector<int>> ret(numRows);
        for (int i=0;i<numRows;i++) {
        	ret[i].resize(i+1);
        	ret[i][0] = ret[i][i] = 1;
        	for (int j=1;j<i;j++) {
        		ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        	}
        }
        return ret;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> vec = sol.generate2(5);
	for (vector<int>::size_type i=0;i<vec.size();i++) {
		std::copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
		cout<<std::endl;
	}
	return 0;
}