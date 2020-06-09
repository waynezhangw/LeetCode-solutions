#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using std::string;
using std::vector;
using std::unordered_map;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> output;
    	if (strs.size()==0) return output;
        unordered_map<string, vector<string>> myMap;
        for (unsigned int i=0;i<strs.size();i++) {
        	string temp = strs[i];
        	sort(temp.begin(), temp.end());
        	myMap[temp].push_back(strs[i]);
        }
        for (auto vec: myMap) {
        	output.push_back(vec.second);
        }
        return output;
    }
};

int main () {
	Solution sol;
	vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> output = sol.groupAnagrams(input);
	for (unsigned int i=0;i<output.size();i++) {
		for (unsigned int j=0;j<output[i].size();j++) {
			std::cout<<output[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	return 0;
}