#include<iostream>
#include<vector>
#include<set>

using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int length = (int)A.size();
        set<int> unique;
        for (int i=0;i<length;i++){
        	unique.insert(A[i]);
        	if ((int)unique.size() != i+1){
        		return A[i];
        	}
        }
        return A[length-1];
    }
};

int main(){
	vector<int> temp = {5,1,5,2,5,3,5,4};
	Solution sol;
	cout<<sol.repeatedNTimes(temp)<<endl;
	return 0;
}