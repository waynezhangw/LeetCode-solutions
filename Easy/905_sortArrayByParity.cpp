#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
    	stack<int> even;
    	stack<int> odd;
        for(unsigned int i=0;i<A.size();i++){   //单另用栈比较费内存，内存占用只击败6%的人，速度击败23%，差！
        	if(A[i]%2 == 0){
        		even.push(A[i]);
        	}
        	else{
        		odd.push(A[i]);
        	}
        }
        for(unsigned int i=0;i<A.size();i++){
        	if(!even.empty()){
        		A[i] = even.top();
        		even.pop();
        	}
        	else{
        		A[i] = odd.top();
        		odd.pop();
        	}
        }
        return A;
    }
};

int main(){
	Solution sol;
	vector<int> temp = {3,1,2,4,5,7,8};
	temp = sol.sortArrayByParity(temp);
	for(unsigned int i=0;i<temp.size();i++){
		cout<<temp[i]<<",";
	}
	return 0;
}