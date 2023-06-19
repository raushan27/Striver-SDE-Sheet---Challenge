// Reverse Linked List
// SDE Sheet Q25

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *pre = NULL;
    LinkedListNode<int> *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}