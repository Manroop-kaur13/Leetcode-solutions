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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        ListNode* temp2=head;
        while(head){
            count++;
            head=head->next;
        }

        if(count==n){
            ListNode* del=temp;
            temp=temp->next;
            delete(del);
            return temp; 
        }
        while(temp){
            if(count==n+1){
                if(temp->next){
                    ListNode* del=temp->next;
                    temp->next=temp->next->next;
                    delete(del);
                    break;
            }
            else{
                temp=nullptr;
            }}
            
            temp=temp->next;
            count--;
        }
        return temp2;
    }
};