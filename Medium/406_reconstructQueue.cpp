#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::pair;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {     //copied from the discussion, 77.47% and 41.39%
    	vector<pair<int, int>> pair_people;
    	for (auto pp : people) {
    		pair<int, int> temp = {pp[0], pp[1]};
    		pair_people.insert(pair_people.begin(), temp);
    	}
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
           { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        std::sort(pair_people.begin(), pair_people.end(), comp);
        vector<pair<int, int>> res;
        for (auto& p : pair_people)
            res.insert(res.begin() + p.second, p);   //insert at the right position, dynamically insert
        int i = 0;
        for (auto p : res) {
        	people[i][0] = p.first;
        	people[i][1] = p.second;
        	i++;
        }
        return people;
    }

    vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {   //shorter version of the first solution, 24.33% and 37.19%
    	vector<pair<int, int>> pair_people;
    	for (auto pp : people) {
    		pair<int, int> temp = {pp[0], pp[1]};
    		pair_people.insert(pair_people.begin(), temp);
    	}
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
           { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        std::sort(pair_people.begin(), pair_people.end(), comp);
        vector<vector<int>> res;
        for (auto p : pair_people) {
        	vector<int> temp = {p.first, p.second};
        	res.insert(res.begin()+p.second, temp);
        }
        return res;
    }

    vector<vector<int>> reconstructQueue3(vector<vector<int>>& people) {   //much shorter version of the first solution, 21.50% and 54.96%
        auto comp = [](const vector<int>& p1, const vector<int>& p2)
           { return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); };
        std::sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for (auto p : people) {
        	res.insert(res.begin()+p[1], p);//sub problem repeat again and again until the last person (usually with shortest height and biggest num in front of him)
        }
        return res;
    }

    void seeVec(vector<vector<int>>& people) {
        for (int i = 0; i < (int)people.size(); i++) {
            for (int j = 0; j < (int)people[0].size(); j++) {
                std::cout << people[i][j] << ",";
            }
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> vec = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    sol.seeVec(vec);
    vec = sol.reconstructQueue3(vec);
    sol.seeVec(vec);
    return 0;
}