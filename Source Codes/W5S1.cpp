#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int value;
    struct Node* next;// point to the next 
      //element of the current element
}Node;

void printList(Node *head)
{
    printf("Noi dung danh sach:\n");
    Node *p = head;
    while(p!=NULL)
    {
        printf("%d-->",p->value);
        p=p->next;
    }
    printf("\n==============================================\n");
    
}

Node*makeNode(int v){// allocate memory for a new node
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; p->next = NULL;
    return p;
}

Node* insertLast(Node* h, int v){
      Node* p = h;
     if(h == NULL){
            return makeNode(v);
      }
      // general case
      while(p->next != NULL)
            p = p->next;

      Node* q = makeNode(v);
      p->next = q;
      return h;
}

void insertLast2(Node** h, int v){
      Node* p = *h;
     if(*h == NULL){ // danh sach rong
            *h = makeNode(v);
      }
      // general case
      while(p->next != NULL)
            p = p->next;

      Node* q = makeNode(v);
      p->next = q;
}

// nen tranh dung de quy
Node* insertLastRecursive(Node* h, int v){
    if(h == NULL){
        return makeNode(v);
    }
    h->next = insertLastRecursive(h->next, v);
    return h;
}


int main()
{
    Node *head = NULL;
    //head = makeNode(7);
    head = insertLast(head,3);
    head = insertLast(head,5);
    head = insertLast(head,7);
    insertLast2(&head,10);
    insertLast2(&head,15);
    head = insertLastRecursive(head, 20);
    head = insertLastRecursive(head, 30);
    
    printList(head);
}