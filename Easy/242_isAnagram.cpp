#include<iostream>
#include<string>
#include<map>

#include<algorithm>

#include <unordered_map>

using std::map;
using std::unordered_map;
using std::cout;
using std::endl;
using std::string;
using std::sort;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> my_dic;
        for (unsigned int i=0;i<s.size();i++) my_dic[s[i]]++;
        for (unsigned int i=0;i<t.size();i++) {
        	if (my_dic.count(t[i]) == 0) return false;
        	else {
        		my_dic[t[i]]--;
        		if (my_dic[t[i]]<0) return false;
        	}
        }
        return true;
    }

    bool isAnagram2(string s, string t) {           //when I saw others comments
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram3(string s, string t) {           //a simplified version from 'details'
        if (s.length() != t.length()) return false;
        unordered_map<char, int> my_dic;
        for (unsigned int i=0;i<s.length();i++) {
        	my_dic[s[i]]++;
        	my_dic[t[i]]--;
        }
        for (auto c: my_dic) {
        	if (c.second) return false;
        }
        return true;
    }
};

int main()
{
	Solution sol;
	cout<<sol.isAnagram3("rat", "car")<<endl;
	return 0;
}