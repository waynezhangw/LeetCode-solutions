#include<iostream>    
#include<vector>

using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    	int max_sumHeight = 0;
    	int sum_original = 0;
    	int sum_final = 0;
    	vector<int> row(grid.size(),0), column(grid[0].size(),0);
    	for(unsigned int i=0;i<grid.size();i++){
    		for(unsigned int j=0;j<grid[0].size();j++){
    			sum_original += grid[i][j];
    			if(grid[i][j]>row[i]){
    				row[i]=grid[i][j];
    			}
    			if(grid[i][j]>column[j]){
    				column[j]=grid[i][j];
    			}
    		}
    	}
    	for(unsigned int i=0;i<grid.size();i++){
    		for(unsigned int j=0;j<grid[0].size();j++){
    			grid[i][j] = row[i]<=column[j]?row[i]:column[j];
    			sum_final += grid[i][j];
    		}
    	}

        max_sumHeight = sum_final - sum_original;
    	return max_sumHeight;
    }
};

int main(){
	Solution test;
	//方法一来初始化二维向量
	int a[4][4] = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    int row = sizeof(a)/sizeof(a[0]);
    int column = sizeof(a)/sizeof(a[0][0])/row;
    vector<vector<int>> A (row,vector<int>(column,99));
    for(int i=0;i<row;i++){
    	for(int j=0;j<column;j++){
    		A[i][j] = a[i][j];
    	}
    }
    //方法二来初始化二维向量
    vector<vector<int>> B = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};

	int sum_h = test.maxIncreaseKeepingSkyline(B);
    cout<<sum_h<<","<<endl;
}