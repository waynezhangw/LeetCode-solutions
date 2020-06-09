#include<iostream>
#include<vector>
#include<algorithm>  

using std::vector;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first to 'transpose matrix' and then 'flip from left to right'
        transpose_matrix(matrix);
        flip_left_right_matrix(matrix);
    }
    void transpose_matrix(vector<vector<int>>& matrix) {
    	unsigned int n = matrix.size();
    	for (unsigned int i=0;i<n;i++) {
    		for (unsigned int j=i+1;j<n;j++) {
    			// int temp = matrix[i][j];
    			// matrix[i][j] = matrix[j][i];
    			// matrix[j][i] = temp;
    			std::swap(matrix[i][j], matrix[j][i]);  //swap, just saw it from other people's code
    		}
    	}
    }
    void flip_left_right_matrix(vector<vector<int>>& matrix) {
    	unsigned int n = matrix.size();
    	for (unsigned int i=0;i<n;i++) {
    		for (unsigned int j=0;j<n/2;j++) {
    			// int temp = matrix[i][j];
    			// matrix[i][j] = matrix[i][n-j-1];
    			// matrix[i][n-j-1] = temp;
    			std::swap(matrix[i][j], matrix[i][n-j-1]);
    		}
    	}
    }
    void see_vector(vector<vector<int>>& matrix) {
    	for (unsigned int i=0;i<matrix.size();i++) {
    		for (unsigned int j=0;j<matrix[0].size();j++) {
    			std::cout<<matrix[i][j]<<",";
    		}
    		std::cout<<std::endl;
    	}
    }
};

int main()
{
	Solution sol;
	// vector<vector<int>> vec;
	vector<vector<int>> vec = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	sol.see_vector(vec);
	sol.rotate(vec);
	sol.see_vector(vec);
	return 0;
}