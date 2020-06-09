#include<iostream>
#include<vector>
#include<climits>
#include <algorithm>    // std::max

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int maxProfit(vector<int>& prices) {           //only faster than 5.01% and 5.51%
    	int profit = 0;
    	for (int i=0;i<(int)prices.size()-1;i++) {                    //prices.size() is unsigned, thus minus 1 is dangerous
    		for (vector<int>::size_type j=i+1;j<prices.size();j++) {
    			if (prices[i]>prices[j]) break;
    			if (prices[j]-prices[i] > profit) {
    				profit = prices[j]-prices[i];
    			}
    		}
    	}
    	return profit;
    }
    int maxProfit2(vector<int>& prices) {           //from discussion(greedy algorithm), the code is so beautiful
    	int profit = 0;
    	int minProfit = INT_MAX;
    	for (vector<int>::size_type i=0;i<prices.size();i++) { //O(n), to compare every stock with the minimum value prior current
    		minProfit = std::min(minProfit, prices[i]);
    		profit = std::max(profit, prices[i]-minProfit);
    	}
    	return profit;
    }
};

int main () {
	Solution sol;
	vector<int> prices = {};
	cout<<sol.maxProfit2(prices)<<endl;
	return 0;
}