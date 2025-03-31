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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *ptr = head;
        if(head ==nullptr)return nullptr;
        while(slow != nullptr && fast != nullptr){
            slow = slow->next;
            if(fast->next == nullptr)return nullptr;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != ptr){
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
