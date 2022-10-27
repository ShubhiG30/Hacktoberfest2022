#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *midPoint(Node *head)
{
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *mergeSortedLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    /* No need of this condition it is already covered in above condition
   else if (head1 == NULL && head2 == NULL){
        return head1;
    }
    */
    Node *fh = NULL, *ft = NULL, *temp1 = head1, *temp2 = head2;
    if (temp1->data < temp2->data)
    {
        fh = ft = temp1;
        temp1 = temp1->next;
    }
    else
    {
        fh = ft = temp2;
        temp2 = temp2->next;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            ft->next = temp1;
            ft = temp1;
            temp1 = temp1->next;
        }
        else
        {
            ft->next = temp2;
            ft = temp2;
            temp2 = temp2->next;
        }
    }
    if (temp1 != NULL)
    {
        ft->next = temp1;
    }
    else
    {
        ft->next = temp2;
    }
    return fh;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = midPoint(head);
    Node *h1 = head;
    Node *h2 = mid->next;
    mid->next = NULL;
    h1 = mergeSort(h1);
    h2 = mergeSort(h2);
    Node *finalHead = mergeSortedLL(h1, h2);
    return finalHead;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = mergeSort(head);
        print(head);
    }

    return 0;
}
