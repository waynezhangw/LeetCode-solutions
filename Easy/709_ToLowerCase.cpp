#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    string toLowerCase(string str) {
    	string after;
    	after.resize(str.size());
        transform(str.begin(), str.end(), after.begin(), ::tolower);
        return after;
    }
};

int main(){
	Solution test;
	string str="ABSerQWE";
	cout<<str<<endl;
	string l_str = test.toLowerCase(str);
	cout<<l_str<<endl;
}