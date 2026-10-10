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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* odddum=head;
        ListNode* evendum=head->next;
        ListNode* evenHead=evendum;
        while(evendum!=NULL&& evendum->next!=NULL){
            odddum->next=odddum->next->next;
            evendum->next=evendum->next->next;

            odddum=odddum->next;
            evendum=evendum->next;
        }
        odddum->next=evenHead;
        return head;

    }
};