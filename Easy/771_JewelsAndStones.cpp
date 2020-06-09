#include<iostream>
#include<stdlib.h>
#include<string>
#include<map>

using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewelsNum = 0;
        map<char,int> Jewels;
        pair<map<char,int>::iterator,bool> Insert_Pair;
	    for(unsigned int i=0;i<J.length();i++)
	    {
	    	Insert_Pair=Jewels.insert(pair<char,int>(J[i],i));            
	    	if(Insert_Pair.second==false)
	    	{
	    		cout<<i<<"   "<<J[i]<<"  Jewels insert failed！！！"<<endl;
	    	}
	    }

	    for(unsigned int i=0;i<S.length();i++)
	    {
	    	if(Jewels.count(S[i])!=0)
	    	{
	    		jewelsNum++;
	    	}
	    }
	    return jewelsNum;
    }
};

int main()
{
	Solution mini;
	cout<<mini.numJewelsInStones("ab","abcabcs")<<endl;
	system("pause");
	return 0;
}