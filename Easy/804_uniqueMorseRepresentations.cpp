#include<iostream>
#include<string>
#include<vector>
#include<set>    //判断有几种模式

using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
    	for(unsigned int i=0;i<words.size();i++){
    		string temp = "";
    		for(unsigned int j=0;j<words[i].size();j++){
    			temp += get_codes(words[i][j]-97);
    		}
    		pattern.insert(temp);
	    }
    	return pattern.size();
    }
    string get_codes(int i){
    	return codes[i];
    }
    int charTo_26pos(char alphabet){
    	return alphabet-97;
    }
private:
	string codes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	set<string> pattern;
};

int main(){
	vector<string> test = {"gin", "zen", "gig", "msg"};
	Solution solu;
	int num = solu.uniqueMorseRepresentations(test);
	cout<<num<<endl;
	return 0;
}