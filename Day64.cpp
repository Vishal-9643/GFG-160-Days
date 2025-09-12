// Day 64 : Detect Loop in linked list.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool detectLoop(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
int main()
{

    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

}