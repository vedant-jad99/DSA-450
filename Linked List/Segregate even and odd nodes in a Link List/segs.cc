/*
Link to the question - https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#
Time and space complexity - O(n), O(1)
*/

//Linked list structure - 
/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
    public:
        Node* divide(int N, Node *head){
            // code here
            Node *head2 = new Node(0), *head3 = new Node(0);
            Node *cur2 = head2, *cur3 = head3;

            while(head != NULL){
                if(head->data%2 == 0) {
                    cur2->next = head; 
                    cur2 = cur2->next;
                }
                else {
                    cur3->next = head;
                    cur3 = cur3->next;            
                }
                head = head->next;
            }

            cur3->next = NULL;
            cur2->next = head3->next;
            return head2->next;
        }
};
