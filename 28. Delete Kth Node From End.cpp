//Delete Kth Node From End
// SDE Sheet Q28

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    if(head == NULL || head->next == NULL && K == 1)
        return NULL;

    Node* fast = head;
    Node* slow = head;

    while(K--){
        fast = fast->next;
    }

    if(!fast)                   //when the first node is to be deleted
        return head->next;

    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}
