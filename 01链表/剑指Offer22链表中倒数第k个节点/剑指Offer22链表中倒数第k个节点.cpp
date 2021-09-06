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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto p = dummy, q = dummy;
        while(k--) p = p->next;
        while(p){
            p = p->next;
            q = q->next;
        }
        return q;
    }
};