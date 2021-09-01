class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *next;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};