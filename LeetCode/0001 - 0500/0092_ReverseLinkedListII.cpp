/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* init = dummy;
        ListNode* st = dummy;
        
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next;
        
        while (left > 1) {
            init = cur;
            cur = cur->next;
            left--;
            right--;
        }
        
        st = cur;
        while (right > 0) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            right--;
        }
        
        init->next = prev;
        st->next = cur;
        return dummy->next;
    }
};