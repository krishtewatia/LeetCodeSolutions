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
    ListNode* getk(ListNode* temp,int k){
        while(temp!=NULL && k>1){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reversei(ListNode* head){
        ListNode* previous=nullptr;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* next=temp->next;
            temp->next=previous;
            previous=temp;
            temp=next;
        }
        return previous;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        if(head==NULL||head->next==NULL || k<=1) return head;

        while(temp!=NULL){
            ListNode* kn= getk(temp,k);
            if(kn==NULL){
                if(prev!=NULL) prev->next=temp;
                break;
            }
            ListNode* nextn=kn->next;
            kn->next=NULL;

            reversei(temp);
            if(temp==head){
                head=kn;
            }else{
                prev->next=kn;
            }
            temp->next=nextn;
            prev=temp;
            temp=temp->next;
            
        }
        return head;
    }
};