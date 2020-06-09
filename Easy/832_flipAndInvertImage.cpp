#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int temp;
        for (unsigned int i=0;i<A.size();i++){
        	for (unsigned int j=0;j<int(A[0].size()/2.0);j++){
        		temp = A[i][A[0].size()-j-1];
        		A[i][A[j].size()-j-1] = !A[i][j];
        		A[i][j] = !temp;
        	}
        	if(A[0].size()%2 != 0){
        		A[i][int(A[0].size()/2.0)] = !A[i][int(A[0].size()/2.0)];
        	}
        }
        return A;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> temp = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
	temp = sol.flipAndInvertImage(temp);
	for (unsigned int i=0;i<temp.size();i++){
		for (unsigned int j=0;j<temp[0].size();j++){
			cout<<temp[i][j]<<",";
		}
		cout<<endl;
	}

	return 0;
}