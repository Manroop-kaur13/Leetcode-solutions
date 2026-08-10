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
    ListNode* middle(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val>right->val){
                dummy->next=right;
                dummy=dummy->next;
                right=right->next;
                }
            else{
                dummy->next=left;
                dummy=dummy->next;
                left=left->next;
            }
        }
        while(left){
            dummy->next=left;
            dummy=dummy->next;
            left=left->next;
        }
        while(right){
            dummy->next=right;
            dummy=dummy->next;
            right=right->next;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}
        ListNode* mid=middle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);

        return mergeList(left,right);
    }
};