#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<climits>

using std::vector;
using std::stack;
class MinStack {           //my vector method, 5.10% and 87.45%
public:
    /** initialize your data structure here. */
    MinStack() {
        vector<int> vec;
    }

    void push(int x) {
        vec.push_back(x);
    }

    void pop() {
        vec.pop_back();
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return *min_element(vec.begin(), vec.end());
    }
private:
    vector<int> vec;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack2 {           //from the discussion of java solution, 14.00% and 96.41%
public:
    /** initialize your data structure here. */
    MinStack2() {
        myMin = INT_MAX;
    }

    void push(int x) {
        if (x <= myMin) {             // '<=' rather than '<', wrong answer here
            myStack.push(myMin);
            myMin = x;                //must in if, , wrong answer here
        }
        myStack.push(x);
    }

    void pop() {
        if (myStack.top() == myMin) { 
            myStack.pop();
            myMin = myStack.top();
        }
        myStack.pop();
    }

    int top() {
        return myStack.top();
    }

    int getMin() {
        return myMin;
    }
private:
    int myMin;
    stack<int> myStack;
};

class MinStack3 {           //from the details, 16.65% and 49.75%, supposed to be faster
public:
    /** initialize your data structure here. */
    MinStack3() {
        
    }

    void push(int x) {
        myData.push(x);
        if (myMin.empty() || x <= myMin.top()) myMin.push(x);
    }

    void pop() {
        int top = myData.top();
        myData.pop();
        if (myMin.top() == top) myMin.pop();
    }

    int top() {
        return myData.top();
    }

    int getMin() {
        return myMin.top();
    }
private:
    stack<int> myData;
    stack<int> myMin;
};

int main() {
    MinStack3* obj = new MinStack3();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    std::cout << obj->getMin() << std::endl;
    std::cout << obj->top() << std::endl;
    obj->pop();
    std::cout << obj->getMin() << std::endl;
    return 0;
}