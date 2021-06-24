/*
Link to the question - https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#
*/

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *removeDuplicates(Node *head)
{
 // your code goes here
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *sentinel = new Node(0);
    sentinel->next = head;
    
    Node *temp = head->next;
    while(temp != NULL) {
        if(head->data == temp->data) {
            temp = temp->next;
            continue;
        }
        head->next = temp;
        head = head->next;
        temp = temp->next;
    }
    head->next = temp;
    return sentinel->next;
}
