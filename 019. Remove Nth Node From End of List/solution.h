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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *quick = head, *slow = head;
        for(int i = 0; i < n; ++i)
            quick = quick->next;
        // need to delete the head node
        if(quick == nullptr) {
            head = slow->next;
            delete slow;
            return head;
        }
        while(quick->next != nullptr) {
            quick = quick -> next;
            slow = slow->next;
        }
        ListNode *needDelete = slow->next;
        slow->next = needDelete->next;
        delete needDelete;
        return head;
    }
};