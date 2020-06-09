#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        unsigned int left = 0;
        unsigned int right = 1;
        unsigned int profit = 0;
        int start = -1;

        while (right < prices.size()) {
        	if (prices[left] < prices[right]) {
        		if (start < 0) {
        			start = prices[left];
        		}
        		left++;
        		right++;
        	}
        	else {
        		if (start >= 0) {
        			profit += prices[left]-start;
        			start = -1;
        		}
        		left++;
        		right++;
        	}
        }
        if (right == prices.size() && start != -1) profit += prices[left]-start;
        return profit;
    }
    int maxProfit2(vector<int>& prices) {    //from others, directly computing the difference is just fine
        if (prices.size() <= 1) return 0;
        unsigned int left = 0;
        unsigned int right = 1;
        unsigned int profit = 0;
        while (right < prices.size()) {
        	if (prices[right] > prices[left]) {
        		profit += prices[right]-prices[left];
        	}
        	left++;
        	right++;
        }
        return profit;
    }
};

int main (){
	Solution sol;
	vector<int> prices = {7,1,5,3,6,4};
	cout<<sol.maxProfit2(prices)<<endl;
	return 0;
}