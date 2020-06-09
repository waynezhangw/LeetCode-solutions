#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
    	cout<<longUrl<<endl;
        longUrlVec.push_back(longUrl);
        return "http://tiny/"+to_string(longUrlVec.size());
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
    	cout<<shortUrl<<endl;
        int pos = shortUrl.find_last_of('/');
        return longUrlVec[stoi(shortUrl.substr(pos+1))-1];
    }
private:
	vector<string> longUrlVec;
};

int main(){
	Solution test;
	test.decode(test.encode("https://leetcode.com/problems/design-tinyurl"));
}

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));