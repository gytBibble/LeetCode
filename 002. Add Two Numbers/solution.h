/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = NULL;
        ListNode* prev = NULL;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        while(p1 != NULL || p2 != NULL) {
            int v1 = p1 != NULL ? p1->val : 0;
            int v2 = p2 != NULL ? p2->val : 0;
            int sum = carry + v1 + v2;
            carry = sum / 10;
            ListNode* cur = new ListNode(sum % 10);
            if(pHead == NULL)
                pHead = cur;
            if(prev != NULL)
                prev->next = cur;
            prev = cur;
            if(p1 != NULL)
                p1 = p1->next;
            if(p2 != NULL)
                p2 = p2->next;
        }
        // consider the final carry
        if(carry != 0) {
            ListNode* fin = new ListNode(1);
            prev->next = fin;
        }
        return pHead;
    }
};