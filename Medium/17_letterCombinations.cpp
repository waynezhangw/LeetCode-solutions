#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<unordered_map>

using std::string;
using std::vector;
class Solution {
public:
    vector<string> letterCombinations(string digits) {    //copied others' idea from discussion, 27.34% and 43.49%
        vector<string> vec;
        if (digits.size()==0) return vec;
        vec.push_back("");
        std::unordered_map<char, string> myMap;
        myMap['2'] = "abc";myMap['3'] = "def";myMap['4'] = "ghi";
        myMap['5'] = "jkl";myMap['6'] = "mno";myMap['7'] = "pqrs";
        myMap['8'] = "tuv";myMap['9'] = "wxyz";
        vector<string> temp;
        for (string::size_type i=0;i<digits.size();i++) {
        	string wait = myMap[digits[i]];
        	for (string::size_type j=0;j<wait.size();j++) {
        		for (vector<string>::size_type k=0;k<vec.size();k++) {
        			temp.push_back(vec[k]+wait[j]);
        		}
        	}
        	vec = temp;
        	temp.clear();
        }
        return vec;
    }
    vector<string> letterCombinations2(string digits) {    //copied others' code from discussion, 100.00% and 44.79%
        vector<string> vec;
        if (digits.size()==0) return vec;
        vec.push_back("");
        const string myMap[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> temp;
        for (string::size_type i=0;i<digits.size();i++) {
        	string wait = myMap[digits[i]-'0'];
        	for (string::size_type j=0;j<wait.size();j++) {
        		for (vector<string>::size_type k=0;k<vec.size();k++) {
        			temp.push_back(vec[k]+wait[j]);
        		}
        	}
        	vec = temp;
        	temp.clear();
        }
        return vec;
    }
    vector<string> letterCombinations3(string digits) {    //copied others' code from discussion, 100.00% and 60.88%
        vector<string> vec;
        if (digits.size()==0) return vec;
        vec.push_back("");
        const string myMap[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> temp;
        for (string::size_type i=0;i<digits.size();i++) {
        	string wait = myMap[digits[i]-'0'];
        	for (string::size_type j=0;j<wait.size();j++) {
        		for (vector<string>::size_type k=0;k<vec.size();k++) {
        			temp.push_back(vec[k]+wait[j]);
        		}
        	}
        	vec.swap(temp); //comments said this way is more efficient, vector::swap() swaps the reference address in the two vectors
        	temp.clear();
        }
        return vec;
    }
    vector<string> letterCombinations4(string digits) {    //copied others' recursive code from discussion, 100.00% and 60.88%
        vector<string> vec;
        if (digits.size()==0) return vec;
        const vector<string> myMap = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combination("", digits, 0, vec, myMap);
        return vec;
    }
    void combination(string prefix, string &digits, int offset, vector<string> &vec, const vector<string> &myMap) {
    	if (offset >= (int)digits.size()) {
    		vec.push_back(prefix);
    		return;
    	}
    	string wait = myMap[digits[offset]-'0'];
    	for (string::size_type i=0;i<wait.size();i++) {
    		combination(prefix+wait[i], digits, offset+1, vec, myMap);
    	}
    }
};

int main () {
	Solution sol;
	string str = "234";
	vector<string> vec = sol.letterCombinations4(str);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<string>(std::cout, " "));
	std::cout<<std::endl;
	return 0;
}