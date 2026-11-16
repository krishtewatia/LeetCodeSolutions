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
    ListNode* mergel(ListNode* l1,ListNode* l2){
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;

        while(l1!=nullptr && l2!=nullptr){

            if(l1->val <= l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1!=nullptr) temp->next=l1;
        // if(l2!=nullptr) temp->next=l2;
        else temp->next=l2;

        return dummy->next;
    }
    ListNode* merged(vector<ListNode*>& lists,int low,int high){
        if(low==high) return lists[low];

        int mid= low + (high-low) /2;

        ListNode* l1= merged(lists,low, mid);
        ListNode* l2= merged(lists,mid+1, high);

        ListNode* head=mergel(l1,l2);
        return head;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* head=merged(lists,0,lists.size()-1);
        return head;

    }
};