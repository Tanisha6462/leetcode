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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }


        ListNode* temp = head;
        int i = 1;
        while(temp && i < k){
            temp = temp->next;
            i++;
        }
        if(temp == nullptr || i < k){
            return head;
        }
        ListNode* node = temp->next;
        temp->next = nullptr;
        ListNode* head1 = reverseKGroup(node , k);

        temp = head;
        
        ListNode* prev = nullptr;
        while(temp){
            ListNode* curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        head->next = head1;
        return prev;

         
    }
};