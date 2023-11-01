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

// thêm 1 phần tử vào list được sắp xếp bằng cách duyệt từ đầu đền khi tìm được đúng vị trí cần thêm
node * push(node *l, int v){
    if (l == NULL) return makeNode(v);
    node * temp = makeNode(v);
    if (v < l->val) {
        temp->next = l;
        return temp;
    }
    node * p = l;
    while(p->next != NULL && (v < p->val || p->next->val < v))
        p = p->next;
    temp->next = p->next;
    p->next = temp;
    return l;
}
/*
    (có thể sử dụng thuật toán tìm kiếm nhị phân ĐPT O(logN) để tìm vị trí chèn)
    So sánh: sau khi tìm được vị trí cần chèn thì
        -Đối với cách sử dụng linkList thì thao tác chèn ĐPT O(1)
            vì chỉ cần thay đổi địa chỉ của ô nhớ tiếp theo
        -Đối với cách sử dụng mảng tĩnh thì thao tác chèn ĐPT O(N) 
            vì cần phải thay đổi giá trị của tất cả các ô nhớ tiếp theo    
*/

node * scanList(){
    int n, v;
    node * l = NULL;
    printf("Nhap so luong phan tu danh sach: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v);
        l = push(l, v);
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

node * clearList(node * l){
    while(l != NULL) l = popBack(l);
    return l;
}

void printMenu(){
    printf("------------------------------------------------\n");
    printf("0: Xoa list va thoat chuong trinh\n");
    printf("1: Nhap list\n");
    printf("2: In List\n");
    printf("3: Chen them 1 phan tu\n");
    printf("------------------------------------------------\n");
}

int main(){
    printMenu();
    int t, v;
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
                scanf("%d", &v);
                l = push(l, v);
                break;
            default:
                printf("Gia tri khong hop le\n");
                printMenu();
        }
    }
}



