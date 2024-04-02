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
    bool hasCycle(ListNode *head) {
        //Floyd Cycle Finding algorithm [Hare and Tortoise]
        auto one = head, two = head;
        
        while (two && two->next) {
            one = one->next;
            two = two->next->next;
            if (one == two) { //cycle found
                return true;
            }
        }
        
        return false;
    }
};