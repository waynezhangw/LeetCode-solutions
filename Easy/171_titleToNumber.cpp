#include<iostream>
#include<string>
#include<math.h>

using std::string;
class Solution {
public:
	int titleToNumber(string s) {   // 26 decimal, from right to left
		double sum = 0;
		double j=0;
		for (int i=s.length()-1;i>=0;i--,j++) {
			int currentChar = s[i]-64;
			sum += currentChar*pow(26.0, j); //here, pow returns double
		}
		return int(sum);
	}
};

int main()
{
	Solution sol;
	std::cout<<sol.titleToNumber("AB")<<std::endl;
	return 0;
}