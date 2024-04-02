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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            fast = fast->next->next;//when fast reaches end, slow is in the middle
            ListNode* tmp = slow->next;//reverse the first half of list
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        if (fast) {//in case of odd nodes, middle nodes need not be comapred
            slow = slow->next;
        }
        
        while (prev && slow) {
            if (prev->val != slow->val) {
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};