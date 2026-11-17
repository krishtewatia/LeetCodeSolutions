/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Insert The Copy Node
        Node* temp = head;
        while (temp != nullptr) {
            Node* copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;
            temp = copynode->next;
        }

        temp = head;
        while (temp != nullptr) {
            Node* copynode = temp->next;

            if (temp->random != nullptr) {
                copynode->random = temp->random->next;
            }

            temp = copynode->next;
        }

        temp = head;
        Node* dummy = new Node(0);
        Node* res = dummy;
        while (temp != nullptr) {
            Node* copy=temp->next;
            temp->next=copy->next;
            res->next=copy;
            res=copy;
            temp=copy->next;
        }
        return dummy->next;
    }
};