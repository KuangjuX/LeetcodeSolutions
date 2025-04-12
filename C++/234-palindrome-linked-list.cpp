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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode *cur = head, *next = head->next, *temp = nullptr;
        cur->next = nullptr;
        while(next != nullptr){
            temp = next->next;
            next->next = cur;
            cur = next;
            next = temp;   
        }
        return cur;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr)return false;
        if(head->next == nullptr)return true;
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head0 = head, *head1 = reverseList(slow);
        while(head0 != nullptr && head1 != nullptr){
            if(head0->val != head1->val)return false;
            head0 = head0->next;
            head1 = head1->next;
        }
        return true;
    }
};
