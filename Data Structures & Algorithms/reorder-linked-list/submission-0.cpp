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
    void reorderList(ListNode* head) {
        //find middle node

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *temp = slow->next;
        slow->next = NULL;

        //Reverse second half nodes
        ListNode* curr = temp;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //merge the two halves
        ListNode* head1 = head;
        ListNode* head2 = prev;

        while(head2 != NULL){
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }
    }
};
