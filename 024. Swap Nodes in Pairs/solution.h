/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_1 { // Recursive
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next ==NULL) return head;
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};

class Solution_2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next ==NULL) return head;
        ListNode *cur = head, *pre = NULL, *next = NULL;
        int flag = 1;
        while(cur && cur->next) {
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            if(pre) pre->next = next;
            cur = cur->next;
            pre = next->next;
            if(flag) {
                head = next;
                flag = 0;
            }
        }
        return head;
    }
};