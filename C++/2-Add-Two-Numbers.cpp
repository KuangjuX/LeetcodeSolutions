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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0;
        ListNode* ans = new ListNode();
        ListNode* node = ans;
        while(true) {
            if(l1 != nullptr && l2 != nullptr) {
                int data = (l1->val + l2->val + x) % 10;
                x = (l1->val + l2->val + x) / 10;
                ListNode* next = new ListNode(data);
                node->next = next;
                node = next;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 == nullptr && l2 != nullptr){
                int data = (l2->val + x) % 10;
                x = (l2->val + x) / 10;
                ListNode* next = new ListNode(data);
                node->next = next;
                node = next;
                l2 = l2->next;
            }else if(l2 == nullptr && l1 != nullptr) {
                int data = (l1->val + x) % 10;
                x = (l1->val + x) / 10;
                ListNode* next = new ListNode(data);
                node->next = next;
                node = next;
                l1 = l1->next;
            }else if(l2 == nullptr && l1 == nullptr) {
                if(x == 0){ break ;}
                else{
                    int data = x;
                    ListNode* next = new ListNode(data);
                    node->next = next;
                    node = next;
                    break;
                }
            }
        }
        
        return ans->next;
    }
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* x = l1, *y = l2;
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        int pos = 0;
        while(x != nullptr || y != nullptr || pos != 0) {
            if(x == nullptr && y == nullptr){
                int z = pos;
                pos = 0;
                head->val = z;
            }
            else if(x == nullptr){
                int z = (y->val + pos) % 10;
                pos = (y->val + pos) / 10;
                head->val = z;
                y = y->next;
                if(y != nullptr || pos != 0){
                    head->next = new ListNode();
                    head = head->next;
                }
            }
            else if(y == nullptr){
                int z = (x->val + pos) % 10;
                pos = (x->val + pos) / 10;
                head->val = z;
                x = x->next;
                if(x != nullptr || pos != 0){
                    head->next = new ListNode();
                    head = head->next;
                }
            }else{
                int z = (x->val + y->val + pos) % 10;
                pos = (x->val + y->val + pos) / 10;
                head->val = z;
                x = x->next;
                y = y->next;
                if(x != nullptr || y != nullptr || pos != 0){
                    head->next = new ListNode();
                    head = head->next;
                }
            }
        }
        return ans;
    }
};
