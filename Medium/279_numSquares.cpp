#include<iostream>
#include<vector>
#include <algorithm>    // std::min_element
#include<climits>

using std::vector;
class Solution {
public:
    int numSquares(int n) {       //Time Limit Exceeded
    	int times = 0;
    	recursiveSquare(n, times);
    	return times;
    }
    void recursiveSquare(int n, int& times) {   //be careful with 88-3, 48-3, 98-2, 192-3, 7168, 5156
    	if (times > 4) return;
    	if (n <= 3) {
    		times += n;
    		return;
    	}
    	int i = 1;
        while (i*i <= n) i++;
        vector<int> square;
        for (int j=1;j<=i-2 && j<=i/2;j++) {
        	int temp = times + 1;
        	recursiveSquare(n-(i-j)*(i-j), temp);
        	square.push_back(temp);
        }
        times = *std::min_element(square.begin(), square.end());
    }
    int numSquares2(int n) {          //copied others' dynamic programming method, 65.52% and 73.62%
    	if (n <= 3) return n;
    	//saves its answer in a vector, thereby avoiding the work of recomputing the answer every time 
    	vector<int> accumulateNumSquare(n+1, INT_MAX);
    	accumulateNumSquare[0] = 0;
    	for (int i=1;i<=n;i++) {
    		for (int j=1;j*j<=i;j++) { 
    			accumulateNumSquare[i] = std::min(accumulateNumSquare[i], accumulateNumSquare[i-j*j]+1);	
    		}
    	}
    	return accumulateNumSquare.back();
    }
    int numSquares3(int n) {          //copied others' static dynamic programming method, 98.12% and 82.50%
    	if (n <= 3) return n; 
    	static vector<int> accumulateNumSquare({0});
    	while ((int)accumulateNumSquare.size() <= n) {
    		int now = accumulateNumSquare.size();
    		int tempMin = INT_MAX;
    		for (int i=1;i*i<=now;i++) {
    			tempMin = std::min(tempMin, accumulateNumSquare[now-i*i]+1);
    		}
    		accumulateNumSquare.push_back(tempMin);
    	}
        // std::cout<<accumulateNumSquare[n]<<"--"<<accumulateNumSquare.back()<<std::endl;
    	return accumulateNumSquare[n];   
    	// return accumulateNumSquare.back();  //why it does not run?
    }
};

int main () {
	Solution sol;
	std::cout<<sol.numSquares3(9)<<std::endl;
	return 0;
}