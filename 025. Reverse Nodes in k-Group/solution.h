/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_1 { // use a stack, memory k, not a constant solution
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *cur = head, *pre = NULL;
        int len = 1;
        while(cur = cur->next)
            len++;
        int times = len / k;
        stack<ListNode*> s;
        cur = head;
        int flag = 1;
        for(int j = 0; j < times; ++j){
            for(int i = 0; i < k; ++i){                
                s.push(cur);
                cur = cur->next;
            }
            if(flag){
                head = s.top();
                flag = 0;
            }
            for(int i = 0; i < k; ++i){
                if(pre) pre->next = s.top();
                pre = s.top();
                s.pop();
                if(!s.empty()) pre->next = s.top();
            }
            pre->next = cur;
        }
        return head;
    }
};


class Solution_2 { // simplify the solution_1, not use the len
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *cur = head, *pre = NULL;
        stack<ListNode*> s;
        int flag = 1;
        while(1){
            for(int i = 0; i < k; ++i){     
                if(cur == NULL) return head;
                s.push(cur);
                cur = cur->next;
            }
            if(flag){
                head = s.top();
                flag = 0;
            }
            for(int i = 0; i < k; ++i){
                if(pre) pre->next = s.top();
                pre = s.top();
                s.pop();
                if(!s.empty()) pre->next = s.top();
            }
            pre->next = cur;
        }
        return head;
    }
};

class Solution_3 { // not use the stack, memory O(1)
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *pre = preHead, *cur = head, *nextCur = head, *next, *preCur, *last;
        while(1){
            for(int i = 0; i < k; ++i){
                if(nextCur == NULL) return preHead->next;
                nextCur = nextCur->next;
            }
            last = cur;
            preCur = nextCur;
            for(int i = 0; i < k; ++i){
                next = cur->next;
                cur->next = preCur;
                preCur = cur;
                cur = next;
            }
            pre->next = preCur;
            pre = last;
        }
        return preHead->next;
    }
};