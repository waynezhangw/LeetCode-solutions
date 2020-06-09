#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

bool myfunction (int i,int j) { return (i>j); }
typedef pair<int, int> pint;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {  //输出前k个高频出现的元素
        vector<int> ret;
        vector<int> entity;
        vector<float> appear;    //float和int一样也只占4个字节
        for (unsigned int i=0;i<nums.size();i++) {   //为了建立  值->次数  的映射
        	vector<int>::iterator it = find(entity.begin(), entity.end(), nums[i]);
        	if (it == entity.end()) {
        		entity.push_back(nums[i]);
        		appear.push_back(1);
        	}
        	else {
        		appear[it-entity.begin()]++;
        	}
        }
        vector<float> appear_sort;
        for (unsigned int i=0;i<entity.size();i++) {       //由于次数可能出现相同的情况
        	appear[i] += (double)i/(double)entity.size();
        	appear_sort.push_back(appear[i]);              //存到一个新的地方，要用它排序
        	cout<<entity[i]<<": "<<appear[i]<<endl;   //得到值：次数 映射
        }
        sort(appear_sort.begin(), appear_sort.end(), myfunction);
        for (int i=0;i<k;i++) {                            //把top k个放进来
        	vector<float>::iterator it = find(appear.begin(), appear.end(), appear_sort[i]);
        	ret.push_back(entity[it-appear.begin()]);
        }
        return ret;
    }

    vector<int> topKFrequent4(vector<int>& nums, int k) {     //看的leetcode上别人的答案,自己又写了一遍
        vector<int> ret;                                      //用到了tydef，unordered_map，priority_queue
        unordered_map<int ,int> countMap;
        for (unsigned int i=0;i<nums.size();i++) {
        	countMap[nums[i]]++;
        }
        priority_queue<pint, vector<pint>, greater<pint> > pq;            //greater小值会在队头，//类型-容器-比较方式
        for (auto iter = countMap.begin();iter!=countMap.end();iter++) {
        	pq.push(make_pair(iter->second, iter->first));                 //让次数在前，就会以次数来排序
        	if ((int)pq.size() > k) {
        		pq.pop();
        	}
        }
        for (int i=0;i<k;i++) {
        	ret.push_back(pq.top().second);                     //先放进去的是小值，因为队头值小
        	pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main () {
	Solution sol;
	vector<int> nums = {4,2,3,4,2,2,3,3,1,3};   //
	vector<int> out;
	out = sol.topKFrequent4(nums, 3);
	for (unsigned int i=0;i<out.size();i++) {
		cout<<out[i]<<",";
	}
	return 0;
}