#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A[0] >= 0){
        	for (unsigned int i=0;i<A.size();i++){
        		A[i] = A[i]*A[i];
        	}
        	return A;
        }
        else if (A[A.size()-1] <= 0){
        	vector<int> ret;
        	for (int i=(int)A.size()-1;i>=0;i--){
        		ret.push_back(A[i]*A[i]);
        	}
        	return ret;
        }
        else {
        	vector<int> ret;
        	int left,right;
        	for (unsigned int i=1;i<A.size();i++){
        		if (A[i]>=0 && A[i-1]<0){
        			left = i-1;
        			right = i;
        			break;
        		}
        	}
        	int size = (int)A.size();
        	while (1){
        		if (left == -1 && right == size){
        			break;
        		}
        		if (left == -1 && right != size){
        			ret.push_back(A[right]*A[right]);
        			right++;
        			continue;
        		}
        		if (right == size && left != -1){
        			ret.push_back(abs(A[left])*abs(A[left]));
        			left--;
        			continue;
        		}
        		if (A[right] <= abs(A[left])){
        			ret.push_back(A[right]*A[right]);
        			right++;
        		}
        		else {
        			ret.push_back(abs(A[left])*abs(A[left]));
        			left--;
        		}
        		
        	}
        	return ret;
        }
        
    }
};

int main(){
	Solution sol;
	vector<int> get = {-4, -3, 0, 3, 10};
	get = sol.sortedSquares(get);
	for (unsigned int i=0;i<get.size();i++){
		cout<<get[i]<<endl;
	}
	return 0;
}