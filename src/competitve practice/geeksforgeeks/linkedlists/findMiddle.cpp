#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

void printMiddleUsing2Ptr(Node *head)
{
    Node *fast_ptr = head;
    Node *slow_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        cout << slow_ptr->data << endl;
    }
}

void printMiddleUsingCounter(Node *head)
{
    int count = 0;
    Node *temp = head;
    Node *mid = head;

    while (temp != NULL)
    {
        if (count & 1)
            mid = mid->next;

        count++;
        temp = temp->next;
    }

    if (mid != NULL)
        cout << mid->data << endl;
}

Node *insertElements(Node *head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = 1;
    temp->next = NULL;
    head = temp;

    Node *nn;
    for (int i = 2; i <= 6; i++)
    {
        nn = (Node *)malloc(sizeof(Node));
        nn->data = i;
        nn->next = NULL;
        temp->next = nn;
        temp = nn;
    }
    return head;
}

int main()
{
    Node *head;
    head = insertElements(head);
    printMiddleUsing2Ptr(head);
    printMiddleUsingCounter(head);

    return 0;
}
