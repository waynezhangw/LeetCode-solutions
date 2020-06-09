#include<iostream>
#include<string>
#include<unordered_map>

using std::string;
using std::unordered_map;
class Solution {
public:
    int firstUniqChar(string s) {       //time O(n), space O(n)
        unordered_map<char, int> myMap;
        for (auto c : s) {
        	myMap[c]++;
        }
        for (unsigned int i=0;i<s.length();i++) {
        	if (myMap[s[i]]==1) {
        		return i;
        	}
        }
        return -1;
    }
    int firstUniqChar2(string s) {       //time O(n^2), space O(1)
    	if (s.length()==1) return 0;     //attention, got a wrong answer
        for (unsigned int i=0;i<s.length();i++) {
        	for (unsigned int j=0;j<s.length();j++) {
        		if (s[i]==s[j] && i!=j) {
        			break;
        		}
        		if (j==s.length()-1) return i;
        	}
        }
        return -1;
    }
    int firstUniqChar3(string s) {       //time O(n), space O(n)
    	int arr [26] = {};               //each initialized with a value of zero
        for (string::size_type i=0;i<s.length();i++) {
        	arr[s[i]-97]++;
        }
        for (string::size_type i=0;i<s.length();i++) {
        	if (arr[s[i]-97]==1) return i;
        }
        return -1;
    }
};

int main() {
	Solution sol;
	std::cout<<sol.firstUniqChar3("loveleetcode")<<std::endl;
	return 0;
}