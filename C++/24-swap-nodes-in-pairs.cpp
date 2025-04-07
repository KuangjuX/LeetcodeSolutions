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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode *prev = nullptr, *cur = head, *next = head->next;
        head = next;
        while(cur != nullptr && next != nullptr){
            cur->next = next->next;
            next->next = cur;
            if(prev != nullptr)prev->next = next;
            
            prev = cur;
            cur = cur->next;
            if(cur != nullptr)next = cur->next;
            else next = nullptr;
        }
        return head;
    }
};
