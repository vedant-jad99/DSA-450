/*
Link to the question - https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
Approach - Floyd's circle detection algorithm
*/

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // just remove the loop without losing any nodes
        if(head == NULL && head->next == NULL)
            return;
        
        Node *tortoise = head->next, *hare = head->next->next;
        while(hare != NULL && hare->next != NULL) {
            if(hare == tortoise)
                break;
            
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        
        if(hare != tortoise)
            return;
            
        tortoise = head;
        while(tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        
        while(hare->next != tortoise)
            hare = hare->next;
            
        hare->next = NULL;
    }
};
