/*
Link to the question - Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.
Approach - Two pointer (Tortoise and hare)
*/

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head->next == NULL)
            return false;
        if(head->next->next == NULL)
            return false;
            
        Node *hare = head->next, *tortoise = head;
        while(hare != NULL && hare->next != NULL) {
            if(hare == tortoise)
                return true;
            
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        return false;
    }
};
