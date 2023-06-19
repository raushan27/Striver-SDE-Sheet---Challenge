// Add Two Numbers
// SDE Sheet Q29

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *res = new Node();
    Node *temp = res;
    int carry = 0;

    while (num1 || num2 || carry)
    {
        int sum = 0;
        if (num1)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2)
        {
            sum += num2->data;
            num2 = num2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return res->next;
}