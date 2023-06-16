// Intersection of Two Linked Lists
// SDE Sheet Q31

// BRUTE FORCE
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    while (temp1 != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp1 == temp2)
                return temp1;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = secondHead;
    }
    return NULL;
}

// USING HASHING
#include <bits/stdc++.h>
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node *> st;

    Node *l1 = firstHead;
    Node *l2 = secondHead;

    while (l1)
    {
        st.insert(l1);
        l1 = l1->next;
    }

    while (l2)
    {
        if (st.find(l2) != st.end())
            return l2;
        l2 = l2->next;
    }

    return NULL;
}

// OPTIMAL
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *l1 = firstHead;
    Node *l2 = secondHead;

    if (l1 == NULL || l2 == NULL)
        return NULL;

    while (l1 != l2)
    {
        l1 = (l1 == NULL ? secondHead : l1->next);
        l2 = (l2 == NULL ? firstHead : l2->next);
    }

    return l1;
}