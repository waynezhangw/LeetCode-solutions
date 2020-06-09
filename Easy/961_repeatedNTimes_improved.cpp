#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int length = (int)A.size();
        for (int i=0;i<length-2;i++){
        	if (A[i] == A[i+1] || A[i] == A[i+2]){
        		return A[i];
        	}
        }
        return A[length-1];
    }
};

int main(){
	vector<int> temp = {1,2,3,3};
	Solution sol;
	cout<<sol.repeatedNTimes(temp)<<endl;
	return 0;
}