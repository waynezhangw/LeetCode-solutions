#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
    	vector<string> FB(n);
        for (int i=1;i<=n;i++) {
        	if (i%3 == 0 && i%5 != 0) {
        		FB[i-1] = "Fizz";
        	}
        	else if (i%3 != 0 && i%5 == 0) {
        		FB[i-1] = "Buzz";
        	}
        	else if (i%3 == 0 && i%5 == 0) {
        		FB[i-1] = "FizzBuzz";
        	}
        	else {
        		FB[i-1] = to_string(i);
        	}
        }
        return FB;
    }

    void seeVector(vector<string> vec) {
    	for (unsigned int i=0;i<vec.size();i++) {
    		cout<<"\""<<vec[i]<<"\""<<endl;
    	}
    	cout<<endl;
    }
};

int main() {
	Solution sol;
	sol.seeVector(sol.fizzBuzz(15));
	return 0;
}