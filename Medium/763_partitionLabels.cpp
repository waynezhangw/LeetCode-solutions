#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>    // std::max

using std::vector;
using std::cout;
using std::unordered_map;
using std::make_pair;
using std::pair;
using std::string;
using std::max;


class Solution {
public:
    //my method is faster than 21.33% of C++，less than 56.80% of C++
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        unordered_map< char, pair<unsigned int,unsigned int> > myMap; //store each char's first and last position
        for(unsigned int i = 0;i < s.size();i++) {
            char ch = s[i];
            if (myMap.count(ch) > 0) {
                int first = myMap[ch].first;
                myMap[ch] = make_pair(first, i);
            } else {
                myMap[ch] = make_pair(i, i);
            }
        }
        //start to compare
        unsigned int left = myMap[s[0]].first;
        unsigned int right = myMap[s[0]].second;
        unsigned int i = 0;
        while(true) {
            i++;
            if (left == right) {
                ret.push_back(1);
                if (i >= s.size()) break;
                left = myMap[s[i]].first;
                right = myMap[s[i]].second;
            } else if (i >= s.size()) {
                break;
            } else if (myMap[s[i]].second <= right) {
                if (right - i <= 1) {
                    ret.push_back(right - left + 1);
                    i = right + 1;
                    if ( i < s.size()) {
                        left = myMap[s[i]].first;
                        right = myMap[s[i]].second;
                    } else {
                        break;
                    }
                }
            } else {
                right = myMap[s[i]].second;
            }
        }
        return ret;
    }

    //method from submission details, is faster than 82.46% of C++ and less than 56.80%
    vector<int> partitionLabels2(string s) {
        vector<int> ret;
        int myMap[26];
        for(unsigned int i = 0;i < s.size();i++) {
            myMap[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for(unsigned int i = 0;i < s.size();i++) {
            end = max(end, myMap[s[i] - 'a']);
            if ((int)i == end) {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }

    //my method chaged a little inspired by partitionLabels2
    //is faster than 82.46% and less than 37.29%
    vector<int> partitionLabels3(string s) {
        vector<int> ret;
        unordered_map<char, int> myMap; //store each char's last position
        for(unsigned int i = 0;i < s.size();i++) {
            char ch = s[i];
            myMap[ch] = i;
        }
        //start to compare
        unsigned int i = 0, left = 0, right = myMap[s[0]];
        while(true) {
            i++;
            if (left == right) {
                ret.push_back(1);
                if (i >= s.size()) break;
                left = right + 1;
                right = myMap[s[i]];
            } else if (i >= s.size()) {
                break;
            } else if (myMap[s[i]] <= (int)right) {
                if (right - i <= 1) {
                    ret.push_back(right - left + 1);
                    i = right + 1;
                    if ( i < s.size()) {
                        left = i;
                        right = myMap[s[i]];
                    } else {
                        break;
                    }
                }
            } else {
                right = myMap[s[i]];
            }
        }
        return ret;
    }

    void printVec(const vector<int> &vec) {
        for(unsigned int i = 0;i < vec.size();i++) {
            cout << vec[i] << ",";
        }
        cout << std::endl;
    }
};

int main() {
    Solution sol;
    string s = "eccbbbbdecx";
    sol.printVec(sol.partitionLabels3(s));
    return 0;
}