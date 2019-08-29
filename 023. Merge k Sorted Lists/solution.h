/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_1 { // merge list one by one
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1) return NULL;
        ListNode *res = lists[0];
        for(int i = 1; i < lists.size(); ++i) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
    
    // merge two lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        else if(l2 == nullptr) return l1;
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return nullptr;
    }
};

class Solution_2 { // divided to accelerate Solution_1
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1) return NULL;
        int k = lists.size();
        int now = 1;
        while(now < k) {
            for(int i = 0; i < k - now; i += 2 * now) {
                lists[i] = mergeTwoLists(lists[i], lists[i + now]);
            }
            now *= 2;
        }
        return lists[0];
    }
    
    // merge two lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        else if(l2 == nullptr) return l1;
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return nullptr;
    }
};