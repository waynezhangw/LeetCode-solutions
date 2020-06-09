#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {      //only faster than 13.47%  and 5.13%
    	//rule one
    	for (int i=0;i<9;i++) {
    		vector<char> sub;
    		for (int j=0;j<9;j++) {
    			if (board[i][j] != '.') sub.push_back(board[i][j]);  
    		}
    		if (!isRepetition(sub)) return false;
    		sub.clear();
    	}
    	//rule two
    	for (int i=0;i<9;i++) {
    		vector<char> sub;
    		for (int j=0;j<9;j++) {
    			if (board[j][i] != '.') sub.push_back(board[j][i]);  //inverse i and j
    		}
    		if (!isRepetition(sub)) return false;
    		sub.clear();
    	}
    	//rule three
    	for (int i=0;i<9;i=i+3) {
    		for (int j=0;j<9;j=j+3) {
    			vector<char> sub;
    			for (int ii=0;ii<3;ii++) {
    				for (int jj=0;jj<3;jj++) {
    					if (board[i+ii][j+jj] != '.') sub.push_back(board[i+ii][j+jj]);  
    				}
    			}
    			if (!isRepetition(sub)) return false;
    		    sub.clear();
    		}
    	}
        return true;
    }
    bool isRepetition(vector<char> sub) {
    	std::unordered_map<char, int> myMap;
    	for (vector<char>::size_type i=0;i<sub.size();i++) {
    		myMap[sub[i]]++;
    		if (myMap[sub[i]]>1) return false;
    	}
    	return true;
    }
    bool isValidSudoku2(vector<vector<char>>& board) {            // from others code in discussion  82.66% and 5.13%
    	int rule1[9][9] = {0}, rule2[9][9]={0}, rule3[9][9]={0};
    	for (int i=0;i<9;i++) {
    		for (int j=0;j<9;j++) {
    			if (board[i][j] != '.') {
    				int num = board[i][j] - '0' - 1;
    				int k = i/3*3 + j/3;                //magical!!!
    				if (rule1[i][num] || rule2[j][num] || rule3[k][num]) return false;
    				rule1[i][num] = rule2[j][num] = rule3[k][num] = 1;
    			}
    		}
    	}
    	return true;
    }
    bool isValidSudoku3(vector<vector<char>>& board) {            // from others code in discussion 76.90% and 5.13%
    	bool rule1[9][9] = {false}, rule2[9][9]={false}, rule3[9][9]={false}; //bool cost less memory maybe
    	for (int i=0;i<9;i++) {
    		for (int j=0;j<9;j++) {
    			if (board[i][j] != '.') {
    				int num = board[i][j] - '0' - 1;
    				int k = i/3*3 + j/3;                //magical!!!
    				if (rule1[i][num] || rule2[j][num] || rule3[k][num]) return false;
    				rule1[i][num] = rule2[j][num] = rule3[k][num] = true;
    			}
    		}
    	}
    	return true;
    }
    bool isValidSudoku4(vector<vector<char>>& board) {            // from others code in discussion 76.90% and 47.63%
    	vector<int> rule1(9,0), rule2(9,0), rule3(9,0);
    	for (int i=0;i<9;i++) {
    		for (int j=0;j<9;j++) {
    			if (board[i][j] != '.') {
    				int num = 1 << (board[i][j] - '1'); //magical!!!
    				int k = i/3*3 + j/3;                //magical!!!
    				if (rule1[i] & num || rule2[j] & num || rule3[k] & num) return false;
    				rule1[i] |= num;
    				rule2[j] |= num;
    				rule3[k] |= num;
    			}
    		}
    	}
    	return true;
    }
};

int main () {
	Solution sol;
	vector<vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
  		{'6','.','.','1','9','5','.','.','.'},
  		{'.','9','8','.','.','.','.','6','.'},
  		{'8','.','.','.','6','.','.','.','3'},
  		{'4','.','.','8','.','3','.','.','1'},
  		{'7','.','.','.','2','.','.','.','6'},
  		{'.','6','.','.','.','.','2','8','.'},
  		{'.','.','.','4','1','9','.','.','5'},
  		{'.','.','.','.','8','.','.','7','9'}};

  	vector<vector<char>> board2 = {
  		{'8','3','.','.','7','.','.','.','.'},
  		{'6','.','.','1','9','5','.','.','.'},
  		{'.','9','8','.','.','.','.','6','.'},
  		{'8','.','.','.','6','.','.','.','3'},
  		{'4','.','.','8','.','3','.','.','1'},
  		{'7','.','.','.','2','.','.','.','6'},
  		{'.','6','.','.','.','.','2','8','.'},
  		{'.','.','.','4','1','9','.','.','5'},
  		{'.','.','.','.','8','.','.','7','9'}};

	std::cout<<sol.isValidSudoku4(board2)<<std::endl;
	return 0;
}