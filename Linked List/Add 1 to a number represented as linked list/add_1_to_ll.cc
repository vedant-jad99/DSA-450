/*
Link to the question - https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
*/

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *temp = reverse(head);
        Node *rev = temp;
        int carry = 0, sum;
        bool add = true;
        
        Node *temp_for_temp = temp;
        while(temp_for_temp != NULL) {
            if(add) {
                sum = temp_for_temp->data + 1 + carry;
                carry = sum/10;
                add = false;
            }
            else {
                sum = temp_for_temp->data + carry;
                carry = sum/10;
            }
            temp_for_temp->data = sum%10;
            temp_for_temp = temp_for_temp->next;
        }
        
        while(temp->next != NULL)
            temp = temp->next;
        
        if(carry)
            temp->next = new Node(carry);
        
        return reverse(rev);
    }
    Node *reverse(Node *head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
            
        Node *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
};
