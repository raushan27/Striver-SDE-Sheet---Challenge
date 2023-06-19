// Palindrome Linked List
// SDE Sheet Q34

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
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

bool isPalindrome(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *slow = head;

    while (fast->next && fast->next->next)
    { // slow will be on middle
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    fast = head;

    while (slow)
    {
        if (fast->data != slow->data)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}