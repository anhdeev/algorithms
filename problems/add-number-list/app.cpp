#include "../common/base.h"
#include "../common/data.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *convert(const vector<int> &input) {
        ListNode *root = nullptr;
        ListNode *cur = nullptr;

        for(auto ip: input) {
            ListNode *newnode = new ListNode(ip);
            if(!root) root = newnode;
            if(cur) cur->next = newnode;
            cur = newnode;
        }
        return root;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int pad = 0;
        ListNode *head = l1;
        ListNode **cur = &l1;

        if(!l1) return l2;
        if(!l2) return l1;

        while(*cur || l2 || pad) {
            int v1 = (*cur) ? (*cur)->val : 0;
            int v2 = l2 ? l2->val : 0;

            int sum = v1 + v2 + pad;
            if(*cur) (*cur)->val = sum%10;
            else (*cur) = new ListNode(sum%10);
            
            pad = sum/10;

            cur = &((*cur)->next);
            if(!l2 && pad == 0) break;
            l2 = l2 ? l2->next: l2;
        }

        return head;
    }
};

int main() {
    Solution solution;
    ListNode *num1 = solution.convert(std::vector({9,9,9,9,9,9}));
    ListNode *num2 = solution.convert(std::vector({9,9,9,9,9,9,9,9,9}));
    
    ListNode *num = solution.addTwoNumbers(num1, num2);
    
    while(num) {
        cout << num->val << " ";
        num = num->next;
    }
    cout << endl;

    return 0;
}