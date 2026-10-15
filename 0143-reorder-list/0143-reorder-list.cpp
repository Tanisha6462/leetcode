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
    void reorderList(ListNode* head) {
        //find middle in case of even find first value
        if(head->next == nullptr){
            return ;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        head2 = reverse(head2);

        ListNode* dummy = new ListNode(-1,nullptr);
        ListNode* curr = dummy;
        while(head && head2){
            ListNode* temp1 = head->next;
            ListNode* temp2 = head2->next;
            curr->next = head;
            head->next = head2;
            curr = head2;
            head = temp1;
            head2 = temp2;

        }
        while(head){
            curr->next = head;
            curr = head;
            head = head->next;
        }
        // while(head2){
        //     curr->next = head2;
        //     curr = head2;
        //     head2 = head2->next;
        // }
        return;

    }
};