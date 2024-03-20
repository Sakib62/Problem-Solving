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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = list1;
        ListNode* finish;
        ListNode* end = list2;
        
        int cnt = 0;
        while (cnt != a - 1) {
            start = start->next;
            cnt++;
        }
        
        finish = start;
        while (cnt != b + 1) {
            finish = finish->next;
            cnt++;
        }
        
        while(end->next) {
            end = end->next;
        }
        
        start->next = list2;
        end->next = finish;
        
        return list1;
    }
};