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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* remove=head;
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL||head->next==NULL) {
                return NULL;
        }
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        while(fast->next!=NULL &&fast->next->next!=NULL){
            remove=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next){
            remove=remove->next;
        }
        ListNode* temp=remove->next;
        remove->next=temp->next;
        delete(temp);
        return head;
    }
};