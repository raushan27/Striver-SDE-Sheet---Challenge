// Linked List Cycle II
// SDE Sheet Q35

Node *firstNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            fast = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}