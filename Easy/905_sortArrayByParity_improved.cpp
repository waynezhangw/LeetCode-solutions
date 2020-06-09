#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
    	int left = 0;
        int right = A.size()-1;
        int temp;
        while (left < right){
            while (A[left]%2 == 0 && left < right){
                left++;
            }
            while (A[right]%2 != 0 && left < right){
                right--;
            }
            if (left < right){
                temp = A[left];
                A[left] = A[right];
                A[right] = temp;
            }
        }
        return A;
    }
};

int main(){
	Solution sol;
	vector<int> temp = {0,2};
	temp = sol.sortArrayByParity(temp);
	for(unsigned int i=0;i<temp.size();i++){
		cout<<temp[i]<<",";
	}
	return 0;
}