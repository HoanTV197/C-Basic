/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

// tim xem khoa key cos xuat hien trong danh sach
// neu co, tra ve dia chi phan tu chua khoa
// nguoc lai, tra ve NULL
Node *findKey(Node *head, int key)
{
    Node *p = head;
    while(p!=NULL)
    {
        if(p->value==key) return p;
        p=p->next;
    }
    return NULL;
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

void push(Node** head, int v)
{
    Node *q =  makeNode(v);
    q->next = *head;
    *head = q;
}

Node* removeNode(Node* h, int v){
    Node* p = h;
    if(h == NULL) return NULL;
    if(h->value == v)
    {
        Node* tmp = h; h = h->next;      
        free(tmp);  return h;
    }
    
    while(p->next != NULL){
        if(p->next->value == v) break;
        p = p->next;
    }
    if(p->next != NULL){
        Node* q = p->next; p->next = q->next; free(q);
    }
    return h;
}

void removeNode2(Node** h, int v){
    Node* p;
    // dan hsach rong--> khong lam gi ca
    if(*h == NULL) return ;
    
    // neu phan tu can xoa la dau danh sach
    if((*h)->value == v){
        Node* tmp = *h; *h = (*h)->next;      
        free(tmp);  
    }
    
    p = *h;
    // neu phan tu can xoa o giua hoac cuoi
    // p tro toi truoc vi tri can xoa
    while(p->next != NULL){
        if(p->next->value == v) break;
        p = p->next;
    }
    if(p->next != NULL){
        Node* q = p->next; p->next = q->next; free(q);
    }
}

void removeAllKey(Node** h, int v){
    Node* p;
    // danh sach rong--> khong lam gi ca
    if(*h == NULL) return ;
    
    // neu phan tu can xoa la dau danh sach
    if((*h)->value == v){
        Node* tmp = *h; *h = (*h)->next;      
        free(tmp);  
    }
    
    p = *h; 
    do
    {
        // neu phan tu can xoa o giua hoac cuoi
        // p tro toi truoc vi tri can xoa
        while(p->next != NULL){
            if(p->next->value == v) break;
            p = p->next;
        }
        if(p->next != NULL){
            Node* q = p->next; p->next = q->next; free(q);
        }
    }
    while(p->next != NULL);
}


int count(Node* h){
    int cnt = 0;
    Node* p = h;
    while(p != NULL){
        cnt += 1;
        p = p->next;
    }
    return cnt;
}
Node* reverse(Node *h){
    Node* p = h;
    Node* pp = NULL;
    Node* np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
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
    head = insertLastRecursive(head, 30);
    head = insertLastRecursive(head, 30);
    printList(head);
    
    //them vao dau
    push(&head, 2);
    push(&head, 30);
    printList(head);
    
    printf("So luong phan tu: %d\n",count(head));
    int key ;
    printf("Khoa can tim: ");
    scanf("%d",&key);
    if(findKey(head,key)!=NULL)
        printf("Khoa %d co xuat hien trong danh sach!\n", key);
    else 
        printf("Khoa %d KHONG xuat hien trong danh sach!\n", key);
    
    printList(head);
    removeNode2(&head, 5);
    printList(head);
    removeAllKey(&head, 30);
    printList(head);
    printf("Dao nguoc danh sach:\n");
    head = reverse(head);
    printList(head);
    
}