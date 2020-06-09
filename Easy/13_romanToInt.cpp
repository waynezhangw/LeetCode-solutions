#include<iostream>
#include<string>
#include<unordered_map>

using std::unordered_map;
using std::string;
class Solution {
public:
	Solution(void) {
		myMap['I'] = 1;
		myMap['V'] = 5;
		myMap['X'] = 10;
		myMap['L'] = 50;
		myMap['C'] = 100;
		myMap['D'] = 500;
		myMap['M'] = 1000;
	}
    int romanToInt(string s) {   //this is a straightforward method but stupid
        int sum = 0;
        unsigned int i;
        for (i=0;i<s.length()-1;) {
        	if (s[i] == 'I') {
        		if (s[i+1] == 'V') {
        			sum += 4;
        			i = i+2;
        		}
        		else if (s[i+1] == 'X') {
        			sum += 9;
        			i = i+2;
        		}
        		else {
        			sum += 1;
        			i++;
        		}
        	}
        	else if (s[i] == 'X') {
        		if (s[i+1] == 'L') {
        			sum += 40;
        			i = i+2;
        		}
        		else if (s[i+1] == 'C') {
        			sum += 90;
        			i = i+2;
        		}
        		else {
        			sum += 10;
        			i++;
        		}
        	}
        	else if (s[i] == 'C') {
        		if (s[i+1] == 'D') {
        			sum += 400;
        			i = i+2;
        		}
        		else if (s[i+1] == 'M') {
        			sum += 900;
        			i = i+2;
        		}
        		else {
        			sum += 100;
        			i++;
        		}
        	}
        	else {
        		sum += myMap[s[i]];
        		i++;
        	}
        }
        if (i == s.length()-1) sum += myMap[s[i]];
        return sum;
    }

private:
	unordered_map<char, int> myMap;

};

int main() {
	Solution sol;
	std::cout<<sol.romanToInt("IIIIMMCC")<<std::endl;
	return 0;
}