#include<iostream>
#include<set>
#include<stack>

using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *create(ListNode *head) {
		ListNode* p1 = new ListNode(-1);
		ListNode* p2 = new ListNode(-1);
		int i = 1;
		cout<<"type in your head value:"<<endl;
		cin>>p1->val;
		while(p1->val > -1){
			if (head->next == NULL) {
				head = p1;
				head->next = p2;
			}
			else {
				p2->next = p1;
			}
			p2 = p1;
			p1 = new ListNode(-1);
			i++;
			cout<<"type in next value:"<<endl;
			cin>>p1->val;
		}
		delete p1;
		p1 = NULL;
		p2->next = NULL;
		cout<<"type link over!"<<endl;
		return head;
	}

	void printList(ListNode *head){
		// if (head == NULL || head->next == NULL){
		if (head == NULL){
			cout<<"link is empty!"<<endl;
		}
		else {
			ListNode* temp = new ListNode(-1);
			temp = head;
			while (temp != NULL){
				cout<<temp->val<<"->";
				temp = temp->next;
			}
		}
		cout<<endl;
	}

    ListNode *reverseList(ListNode* head) {    //百度面试的一道题，但是应该是写得对的
    	if (head == NULL) return head;
    	stack <ListNode*> stackNode;
    	while(head != NULL) {
    		stackNode.push(head);
    		head = head->next;
    	}

    	ListNode *tempHead = stackNode.top();
    	ListNode *newHead = tempHead;
    	while (stackNode.size() != 0) {
    		stackNode.pop();
    		if (stackNode.size() == 0) {
    			tempHead->next = NULL;
    			break;
    		}
    		tempHead->next = stackNode.top();
    		tempHead = stackNode.top();
    	}
        return newHead;
    }

    ListNode *reverseList2(ListNode* head) {     //看完leetcode大神的精简反转方法
    	ListNode *newHead = NULL;
    	while (head) {
    		ListNode *next = head->next;   //先存着下一个
    		head->next = newHead;          //直接借用此时的head回个头指向前面一个
    		newHead = head;                //不断往原来序列的尾部推进
    		head = next;
    	}
        return newHead;
    }
};

int main () {
	Solution sol;
	ListNode *link1 = new ListNode(-1);
	link1 = sol.create(link1);
	sol.printList(link1);
	sol.printList(sol.reverseList2(link1));
	return 0;
}