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
    ListNode* findk(ListNode* temp,int k){
        int cnt=1;
        ListNode* he=temp;
        while(he->next!=NULL){
            if(cnt==k) return he;
            he=he->next;
            cnt+=1;
        }
        return NULL;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0) return head;
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            len+=1;
            temp=temp->next;
        }
        if(k%len==0) return head;
        k=k%len;
        ListNode* lstn=findk(head,len-k);
        temp->next=head;
        head=lstn->next;
        lstn->next=NULL;
        return head;



    }
};