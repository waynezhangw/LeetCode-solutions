#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A){
        vector<int> ret(A.size());
        int left = 0, right = A.size()-1, i = right;
        while (left <= right){
            if ( (A[left]*A[left]) >= (A[right]*A[right]) ){
                ret[i] = A[left]*A[left];
                i--;
                left++;
            }
            else{
                ret[i] = A[right]*A[right];
                i--;
                right--;
            }
        }
        return ret;
    }
};

int main(){
	Solution sol;
	vector<int> get = {-11, -3, 0, 2, 14};
	get = sol.sortedSquares(get);
	for (unsigned int i=0;i<get.size();i++){
		cout<<get[i]<<endl;
	}
	return 0;
}