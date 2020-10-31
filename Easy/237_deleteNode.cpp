#include <iostream>

using std::cin;
using std::cout;
using std::endl;
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

class Solution {
   public:
    ListNode* create(ListNode* head) {
        ListNode* p1 = new ListNode(-1);
        ListNode* p2 = new ListNode(-1);
        int i = 1;
        cout << "type in your head value:" << endl;
        cin >> p1->val;
        while (p1->val > -1) {
            if (head->next == NULL) {
                head = p1;
                head->next = p2;
            } else {
                p2->next = p1;
            }
            p2 = p1;
            p1 = new ListNode(-1);
            i++;
            cout << "type in next value:" << endl;
            cin >> p1->val;
        }
        delete p1;
        p1 = NULL;
        p2->next = NULL;
        cout << "type link over!" << endl;
        return head;
    }

    void printList(ListNode* head) {
        if (head == NULL) {
            cout << "link is empty!" << endl;
        } else {
            ListNode* temp = new ListNode(-1);
            temp = head;
            while (temp != NULL) {
                cout << temp->val << "->";
                temp = temp->next;
            }
            delete temp;
            temp = NULL;
        }
        cout << endl;
    }
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(-1);
    head = sol.create(head);
    sol.printList(head);
    sol.deleteNode(head->next->next);
    sol.printList(head);
    return 0;
}
