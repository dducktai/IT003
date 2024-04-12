
#include "iostream"
using namespace std;

struct node {
    int data;
    node *next;
};

struct List {
    node *head;
    node *tail;
};

node* CreateNode(int x) {
    node *p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, node *p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = NULL;
    } else {
        p->next = l.head->next;
        l.head = p;
    }
}

void Addtail(List &l, node *p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void PrintList(List &l) {
    node *p = l.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void SelectionSortASC(List &l) {
    node *p = l.head;
    node *q;
    node *min;
    while (p != l.tail) {
        min = p; q = p->next;
        while (q != NULL) {
            if (q->data <= min->data) {
                min = q;
            }
            q = q->next;
        }
        swap(min->data, p->data);
        p = p->next;
    }
}

void SelectionSortDES(List &l) {
    node *p = l.head;
    node *q;
    node *max;
    while (p != NULL) {
        max = p; q = p->next;
        while (q != NULL) {
            if (q->data > max->data) {
                max = q;
            }
            q = q->next;
        }
        swap(max->data, p->data);
        p = p->next;
    }
}

void MergeASC(List &l, List &l1, List &l2) {
    node *p = l1.head;
    node *q = l2.head;
    while (p != NULL && q != NULL) {
        if (p->data >= q->data) {
            Addtail(l, CreateNode(q->data));
            q = q->next;
        } else {
            Addtail(l, CreateNode(p->data));
            p = p->next;
        }
    }
    while (p != NULL) {
        Addtail(l, CreateNode(p->data));
        p = p->next;
    }
    while (q != NULL){
        Addtail(l, CreateNode(q->data));
        q = q->next;
    }
}

void MergeDES(List &l, List &l1, List &l2) {
    node *p = l1.head;
    node *q = l2.head;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            Addtail(l, CreateNode(q->data));
            q = q->next;
        } else {
            Addtail(l, CreateNode(p->data));
            p = p->next;
        }
    }
    while (p != NULL) {
        Addtail(l, CreateNode(p->data));
        p = p->next;
    }
    while (q != NULL){
        Addtail(l, CreateNode(q->data));
        q = q->next;
    }
}

int main() {
    List l, l1, l2;
    CreateList(l); CreateList(l1); CreateList(l2);
    int n, n1, n2, x;
    cout << "Nhap so luong phan tu danh sach 1: ";
    cin >> n1;
    cout << "Nhap danh sach 1: ";
    for (int i = 1; i <= n1; i++) {
        cin >> x;
        Addtail(l1, CreateNode(x));
    }
    cout << "Nhap so luong phan tu danh sach 2: ";
    cin >> n2;
    cout << "Nhap danh sach 2: ";
    for (int i = 1; i <= n2; i++) {
        cin >> x;
        Addtail(l2, CreateNode(x));
    }
    cout << "Sap xep theo chieu tang(1) hay giam(0): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        SelectionSortASC(l1);
        SelectionSortASC(l2);
        MergeASC(l, l1, l2);
    }
    if (choice == 0) {
        SelectionSortDES(l1);
        SelectionSortDES(l2);
        MergeDES(l, l1, l2);
    }
    cout << "Danh sach da tron: ";
    PrintList(l);
    return 0;
}
