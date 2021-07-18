#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:
    //4 ms faster than 91.00%, 8.6 MB less than 17.88%
    vector<int> countBits(int n) {
        vector<int> ret;
        for (int i = 0; i <= n; i++) {
            int num = i;
            int res = 0;
            while (num != 0) {
                num = num & (num-1);
                res++;
            }
            ret.push_back(res);
        }
        return ret;
    }

    //4 ms faster than 91.00%, 8.5 MB less than 17.88%
    vector<int> countBits2(int n) {
        vector<int> ret;
        for (int i = 0; i <= n; i++) {
            int num = i;
            int res = 0;
            for (int i = 0;i < 17; i++) {
                if (((num >> i) & 1) == 1) res++;
            }
            ret.push_back(res);
        }
        return ret;
    }

    //metod from submission details
    //4 ms, faster than 91.00%, 7.7 MB, less than 97.30%
    vector<int> countBits3(int n) {
        vector<int> ret(n+1);
        ret[0] = 0;
        for (int i = 1; i <= n; i++) {
            ret[i] = ret[i >> 1] + i%2;
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
    sol.printVec(sol.countBits3(2));
    return 0;
}