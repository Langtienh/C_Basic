#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
}node;

node * makeNode(int v){
    node * p = (node*)malloc(sizeof(node));
    p->val = v;
    p->next = NULL;
    return p;
}

node * insertLast(node * l, int v){
    if (l == NULL) return makeNode(v);
    node * p = l;
    while (l->next != NULL) l = l->next;
    l->next = makeNode(v);
    return p;
}

node * insertFirst(node * l, int v){
    node * p = (node*)malloc(sizeof(node));
    p->val = v;
    p->next = l;
    return p;
}

node * scanList(node * l){
    int n, v;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v);
        l = insertLast(l, v);
    }
    return l;
}

void printList(node * l){
    while (l != NULL){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

node * popFront(node * l){
    node * p = l->next;
    free(l);
    return p;
}

node * popBack(node * l){
    if (l->next == NULL) return popFront(l);
    node * p = l;
    while (p->next->next != NULL) p = p->next;
    node * tmp = p->next;
    p->next = NULL;
    free(tmp);
    return l;
}

node * removeFirst(node * l, int v){
    if (l->val == v) return popFront(l);
    node * p = l;
    while (l->next->val != v) l = l->next;
    node * q = l->next;
    l->next = q->next;
    free(q);
    return p;
}

node * removeAll(node * l, int v){
    node * p = l;
    while (l->val == v) {
        p = l->next;
        free(l);
        l = p;
    }
    while (l->next != NULL){
        if (l->next->val == v){
            node * temp = l->next;
            l->next = l->next->next;
            free(temp);
        }
        else l = l->next;
    }
    return p;
}

node * reverseList(node * l){
    node * p = NULL;
    while (l != NULL){
        p = insertFirst(p, l->val);
        l = l->next;
    }
    return p;
}

int count(node * l){
    int n = 0;
    while (l != NULL){
        n++;
        l = l->next;
    }
    return n;
}

node * giaiPhongLish(node * l){
    while (l != NULL) popBack(l);
    return NULL;
}

int main(){
    printf("-----------------------------------------------\n");
    printf("0: Thoat chuong trinh\n");
    printf("1: Nhap list\n");
    printf("2: In danh sach\n");
    printf("3: them 1 phan tu vao dau\n");
    printf("4: Them mot phan tu vao cuoi\n");
    printf("5: Xoa 1 phan tu\n");
    printf("6: Xoa tat ca cac phan tu co gia tri v\n");
    printf("7: Dao nguoc danh sach\n");
    printf("8: in so phan tu cua sach hien tai\n");
    printf("-----------------------------------------------\n");
    node * l = NULL;
    int t, v;
    while (1){
        scanf("%d", &t);
        if (t == 0) {
            l = giaiPhongLish(l);
            return 0;
        }
        switch(t){
            case 1:
                l = scanList(l);
                break;
            case 2:
                printList(l);
                break;
            case 3:
                printf("Nhap gia tri can them vao dau danh sach: ");
                scanf("%d", &v);
                l = insertFirst(l, v);
                break;
            case 4:
                printf("Nhap gia tri can them vao cuoi danh sach: ");
                scanf("%d", &v);
                l = insertLast(l, v);
                break;
            case 5:
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &v);
                l = removeFirst(l, v);
                break;
            case 6:
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &v);
                l = removeAll(l, v);
                break;
            case 7:
                l = reverseList(l);
                break;
            case 8:
                printf("%d", count(l));
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }
    return 0;
}