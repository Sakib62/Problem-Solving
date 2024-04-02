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
    ListNode* dummy = new ListNode();
    ListNode* tmp = dummy;
    
    ListNode* reverseList(ListNode* head) {

        return iter(head);
        
        //return recur(head);
        
        //return usingArray(head);
        
        //usingRecursion(head);
        //return dummy->next;
    }
    
    ListNode* iter(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    ListNode* recur(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* rev = recur(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return rev;
    }
    
    ListNode* usingRecursion(ListNode* head) {
        if (!head) {
            return new ListNode();
        }
        if (!head->next) {
            tmp->next = new ListNode(head->val);
            return tmp->next;
        }
        
        ListNode* ok = usingRecursion(head->next);
        
        ok->next = new ListNode(head->val);
        return ok->next;
    }
    
    ListNode* usingArray(ListNode* head) {
        vector<int> val;
        ListNode* itr = head;
        while(itr) {
            val.push_back(itr->val);
            itr = itr->next;
        }
        reverse(val.begin(), val.end());
        
        ListNode* dummy = new ListNode();
        ListNode* ll = dummy;
        
        for (auto item : val) {
            ListNode* tmp = new ListNode();
            tmp->val = item;
            ll->next = tmp;
            ll = ll->next;
        }
        return dummy->next;
    }
};