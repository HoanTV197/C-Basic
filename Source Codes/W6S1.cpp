#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char c; // 1 byte
    struct Node* next;  // 4-8 byte
}Node;

Node* top; // bien toan cuc, nen tranh dung

Node* makeNode(char x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = x; p->next = NULL;
    return p;
}

void initStack(){
    top = NULL;
}
int stackEmpty(){
    return top == NULL;
}

// push = them vao dau danh sach lien ket
void push(char x){
    Node* p = makeNode(x);
    p->next = top; top = p;
}


// xoa phan tu o dau danh sach
char pop(){
    if(stackEmpty()) return ' ';
    char x = top->c;
    Node* tmp = top; top = top->next; free(tmp);
    return x;
}

int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

// nbeu loi -> return vi tri bi loi
// khong loi --> return 0
int check(char* s){
    initStack();
    for(int i = 0; i < strlen(s); i++){           
        
        // mo ngoac thi day vao stack
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            push(s[i]);
        }else{  //dong ngoac
            if(stackEmpty()) return i; // c?n return v? trí b? l?i
            char x = pop();
            if(!match(x,s[i])) return i;
        }
    }
    if(stackEmpty()) return 0;
    return -1;// thieu dau ngoac dong
}


int main()
{
    char str[] ="()))";  // A=6+7*(c/2*(6-3*c[2]))
    int result = check(str);
    if(result !=0)
        printf("Cap dau ngoac khong hop le!\nVi tri loi %d",result);
    else
        printf("Dau ngoac OK!\n");
    return 0;
}