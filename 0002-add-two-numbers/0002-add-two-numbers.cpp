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
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp){
            ListNode* curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* dummy = new ListNode(-1,nullptr);
        ListNode* curr = dummy;
        int carry = 0;
        while(head1 && head2){
            int sum = head1->val + head2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(digit , nullptr);

            curr->next = node;
            curr = node;

            head1 = head1->next;
            head2 = head2->next;


        }
        while(head1){
            int sum = head1->val+ carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* node = new ListNode(digit , nullptr);

            curr->next = node;
            curr = node;
            head1 = head1->next;
        }
        while(head2){
            int sum = head2->val+ carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* node = new ListNode(digit , nullptr);

            curr->next = node;
            curr = node;
            head2 = head2->next;
        }
        if(carry){
            ListNode* node = new ListNode(carry , nullptr);
            curr->next = node;
            curr = node;
        }

        return dummy->next;

        


    }
};