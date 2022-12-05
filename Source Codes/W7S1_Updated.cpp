#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <stack>
using namespace std;

typedef struct Node {
    int row, col;// ch? s? hang và c?t c?a tr?ng thái hi?n t?i
    int step; // s? bu?c di chuy?n d? di t? tr?ng thái xu?t phát d?n tr?ng thái hi?n t?i
    struct Node* next; // con tr? d?n ph?n t? ti?p theo trong hàng d?i
    struct Node* parent;// con tr? tr? d?n tr?ng thái sinh ra tr?ng thái hi?n t?i
}Node;


int n, m;
int r0, c0;
int A[MAX][MAX];

// di chuyen theo 4 huong
const int dr[4] = { 1,-1,0,0 }; //(dr[0],dc[0]) -->(1,0) = di chuyen sang phai 1 o
const int dc[4] = { 0,0,1,-1 };
Node* finalNode;

int visited[MAX][MAX];

// con tro dau va cuoi hang doi
Node* head, * tail;

void input() {
    FILE* f = fopen("maze.txt", "r");
    fscanf(f, "%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &A[i][j]);
        }
    }
    fclose(f);
}

void printCurrMaze()
{
    printf("size %d x %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// tao nut moi cua danh sach lien ket
Node* makeNode(int row, int col, int step, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row; node->col = col; node->next = NULL;
    node->parent = parent; node->step = step;
    return node;
}

void initQueue() {
    head = NULL; tail = NULL;
}
int queueEmpty() {
    return head == NULL && tail == NULL;
}
void pushQueue(Node* node) {
    if (queueEmpty()) {
        head = node; tail = node;
    }
    else {
        tail->next = node; tail = node;
    }
}
// lay va tra ve phan tu dau hang doi
Node* popQueue() {
    if (queueEmpty()) return NULL;
    Node* node = head;    head = node->next;
    if (head == NULL) tail = NULL;
    return node;
}


// ham lien quan den thuat toan
// cai nut hien tai co the them vao hang doi
int legal(int row, int col) {
    return A[row][col] == 0 && !visited[row][col];
}

// den cai o co the thoat ra me cung chua?
// cac o ma o bien la co the thoat ra
int target(int row, int col) {
    return row < 1 || row >= n - 1 || col < 1 || col >= m - 1;
}

// giai phong bo nho
void finalize() {
    if (head == NULL && tail == NULL) return;
    Node* node;
    while (tail != NULL)
    {
        node = tail;
        tail = tail->parent;
        free(node);
    }
}

int main()
{
    printf("MAZE\n");
    input();
    printCurrMaze();

    // gan cac o la chua tham
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            visited[r][c] = 0;

    // toa do o bat dau
    r0 = 2; c0 = 3;

    initQueue();
    Node* startNode = makeNode(r0, c0, 0, NULL);
    pushQueue(startNode);
    visited[r0][c0] = 1;
    Node* node = NULL;
    while (!queueEmpty()) {
        node = popQueue();
        printf("POP (%d,%d)\n", node->row, node->col);
        for (int k = 0; k < 4; k++) {
            int nr = node->row + dr[k];
            int nc = node->col + dc[k];
            if (legal(nr, nc)) {
                visited[nr][nc] = 1;
                Node* newNode = makeNode(nr, nc, node->step + 1, node);
                //node = newNode;
                if (target(nr, nc)) {
                    printf("FOUND!\n");
                    finalNode = newNode; break;
                }
                else
                    pushQueue(newNode);
            }
        }
        //free(node);
        if (finalNode != NULL) break;// found solution
    }
    Node* s = finalNode;
    stack<Node*> path;
    printf("Do dai duong di: %d\n", s->step);
    
    while(s != NULL){
        path.push(s);
        //printf("(%d,%d) ",s->row,s->col);
        s = s->parent;
    }
    while (!path.empty())
    {
        Node* s = path.top();
        path.pop();
        printf("(%d,%d) ", s->row, s->col);
    }
    finalize();

    return 0;
}
