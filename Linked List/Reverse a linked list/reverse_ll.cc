/*
Link to the question - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
Approach 1 - Recursive
Approach 2 - Iterative
*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        //Common for both
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
            
        //Aprroach - 1
        
        // struct Node *temp = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return temp;
        
        //Approach - 2
        struct Node *p = head->next, *q = head->next;
        head->next = NULL;
        while(q != NULL) {
            q = q->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};
