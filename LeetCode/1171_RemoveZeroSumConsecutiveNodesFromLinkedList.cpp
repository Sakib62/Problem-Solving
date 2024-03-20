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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        unordered_map<int, ListNode*>mp;
        mp[0] = dummy;
        
        ListNode* current = head;
        int pSum = 0;
        
        while (current) {
            pSum += current->val;
            
            if (mp.find(pSum) != mp.end()) {
                ListNode* dlt = mp[pSum]->next; //start deleting from here
                int tmp = pSum;
                
                while (dlt != current) {//till current
                    tmp += dlt->val;
                    mp.erase(tmp);
                    dlt = dlt->next;
                }
                mp[pSum]->next = current->next;//remaining nodes deleted
            }
            else {
                mp[pSum] = current;
            }
            
            current = current->next;
        }
        
        return dummy->next;
    }
};