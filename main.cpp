#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
typedef struct node* nodePtr;
        nodePtr curr;
        nodePtr temp;
        nodePtr head;
        nodePtr Node;

struct node* SortedMerge(node* a, node* b);
void SplitFrontnBack(node* givennumber, node** Front, node** Back);
void display();

bool Empty() {
    return head == NULL;
}


void addNode(int data ){
    nodePtr n = new node;
    n->next = NULL;
    n->data = data;

    if(!Empty()){
        curr = head;

            while(curr->next !=NULL){
                curr = curr->next;

            }
        curr->next = n;
    }
    else{
        head = n;

    }
}

int calculateSize()
{
    int count = 0;
    Node= head;
    while(Node!=NULL){
        count++;
        Node = Node->next;
    }
    return count;

}

void display(node * node){
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node-> next;
    }
 cout<<endl;
}

void MergeSort(struct node** Head)
{
    node* head = *Head;
    node* a;
    node* b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    SplitFrontnBack(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *Head = SortedMerge(a, b);
}
node* SortedMerge(struct node* a, struct node* b)
{
    node* result = NULL;
    if (a == NULL)
        return b;
    else if (b==NULL)
        return a;
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);

    }
    return result;
}


void SplitFrontnBack(node* givennumber, node** Front, node** Back)
{
    node* fast;
    node* slow;
    if (givennumber==NULL || givennumber->next==NULL)
    {
        *Front = givennumber;
        *Back = NULL;
    }
    else
    {
        slow = givennumber;
        fast = givennumber->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *Front = givennumber;
        *Back = slow->next;
        slow->next = NULL;
    }
}
void push(node** head_ref, int new_data)
{
    node *new_node = new node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    node* res = NULL;
    node* a = NULL;
    srand(time(NULL));
    for(int i = 0; i < 50; i ++)
    {
      push(&a, rand() % 99 + 1); //rand num from 1 ~ 999
    }
    MergeSort(&a);
    cout<<"Out put: \n";
    display(a);
    return 0;
}