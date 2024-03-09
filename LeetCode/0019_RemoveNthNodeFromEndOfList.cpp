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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head, *right = head, *prev = head;
        while (n--) {
            right = right->next;
        }

        if (right == nullptr) {
            head = head->next;
            return head;
        }
        
        while (right != nullptr) {
            prev = left;
            left = left->next;
            right = right->next;
            
        }
        
        prev->next = left->next;
        return head;
    }
};