#include<iostream>

using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int my_or = x^y;
        int dis = 0;
        while (my_or != 0){
        	if ( (my_or & 1) == 1 ){
        		dis++;
        	}
        	my_or = my_or>>1;
        }
        return dis;
    }
};

int main(){
	Solution sol;
	cout<<sol.hammingDistance(1,4)<<endl;
	return 0;
}