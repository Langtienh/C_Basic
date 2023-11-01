#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    int val;
    struct node * next;
}node;

// node * l = head (Luu dia chi cua phan tu dau tien)

node * makeNode(int v){
    node * p = (node *)malloc(sizeof(node));
    p->val = v;
    p->next = NULL;
    return p;
}

node * pushBack(node *l, int v){
    if (l == NULL) return makeNode(v);
    node * p = l;
    while(p->next != NULL) p = p->next;
    p->next = makeNode(v);
    return l;
}

node * scanList(){
    int n, v;
    node * l = NULL;
    printf("Nhap so luong phan tu danh sach: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v);
        l = pushBack(l, v);
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
    while(p->next->next != NULL) p = p->next;
    node * temp = p->next;
    p->next = NULL;
    free(temp);
    return l;
}

node * removeFirst(node * l, int v){
    if (l->val == v) return popFront(l);
    node * p = l;
    while (p->next->val != v){
        if (p->next == NULL) return l;
        p = p->next;
    }
    node * temp = p->next;
    p->next = temp->next;
    free(temp);
    return l;
}

node * removeAll(node * l, int v){
    while (l->val == v) l = popFront(l);
    if (l == NULL) return l;
    node * p = l;
    while (p->next != NULL){
        if (p->next->val == v){
            node * temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else p = p->next;
    }
    return l;
}

node * removeMax(node * l){
    int lMax = INT_MIN;
    node * p = l;
    while (p != NULL){
        if (p->val > lMax) lMax = p->val;
        p = p->next;
    }
    return removeFirst(l, lMax);
}

node * removeMin(node * l){
    int lMin = INT_MAX;
    node * p = l;
    while (p != NULL){
        if (p->val < lMin) lMin = p->val;
        p = p->next;
    }
    return removeFirst(l, lMin);
}

node * removeAllMax(node * l){
    int lMax = INT_MIN;
    node * p = l;
    while (p != NULL){
        if (p->val > lMax) lMax = p->val;
        p = p->next;
    }
    return removeAll(l, lMax);
}

node * removeAllMin(node * l){
    int lMin = INT_MAX;
    node * p = l;
    while (p != NULL){
        if (p->val < lMin) lMin = p->val;
        p = p->next;
    }
    return removeAll(l, lMin);
}

node * clearList(node * l){
    while(l != NULL) l = popBack(l);
    return l;
}

void printMenu(){
    printf("------------------------------------------------\n");
    printf("0: Xoa list va thoat chuong trinh\n");
    printf("1: Nhap list\n");
    printf("2: In List\n");
    printf("3: Xoa 1 node dau tien co gia tri lon nhat\n");
    printf("4: Xoa 1 node dau tien co gia tri nho nhat\n");
    printf("5: Xoa tat ca node co gia tri lon nhat\n");
    printf("6: Xoa tat ca node co gia tri nho nhat\n");
    printf("------------------------------------------------\n");
}

int main(){
    printMenu();
    int t;
    node * l = NULL;
    while (1){
        printf("Nhap lua chon: ");
        scanf("%d", &t);
        if (t == 0){
            l = clearList(l);
            return 0;
        }
        switch(t){
            case 1:
                l = scanList();
                break;
            case 2:
                printList(l);
                break;
            case 3:
                l = removeMax(l);
                break;
            case 4:
                l = removeMin(l);
                break;
            case 5:
                l = removeAllMax(l);
                break;
            case 6:
                l = removeAllMin(l);
                break;
            default:
                printf("Gia tri khong hop le\n");
                printMenu();
        }
    }
}

