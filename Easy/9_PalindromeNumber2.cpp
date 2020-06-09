#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0))
        {
        	return false;
        }
        if(x>=0&&x<INT_MAX)
        {
        	int push=0;
        	int rev=0;
        	while(x>rev)
        	{
        		push=x%10;
        		x=x/10;
        		rev=rev*10+push;
        	}
        	if(rev==x||rev/10==x)
        	{
        		return true;
        	}
        }
        return false;
    }
};
int main()
{
	Solution caa;
	cout<<caa.isPalindrome(1010101)<<endl;
	system("pause");
	return 0;
}