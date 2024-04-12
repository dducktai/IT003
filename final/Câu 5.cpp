
#include "iostream"
using namespace std;

struct Node {
    int info;
    struct Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

Node* CreateNode(int x) {
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, Node *p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = NULL;
    } else {
        p->next = l.head->next;
        l.head = p;
    }
}

void Addtail(List &l, Node *p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void PrintList(List &l) {
    Node *p = l.head;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void DeleteList(List &l) {
    Node *p;
    while (l.head != NULL) {
        p = l.head;
        l.head = p->next;
        delete p;
    }
    l.tail = NULL;
}

void Shuffle(List &l) {
    int i = 0;
    Node *list = l.head;
    List chan, le; CreateList(chan); CreateList(le);
    while (list != NULL) {
        i++;
        if (i%2 == 0) {
            Addtail(chan, CreateNode(list->info));
        } else {
            Addtail(le, CreateNode(list->info));
        }
        list = list->next;
    }
    DeleteList(l);
    Node *p = chan.head, *q = le.head;
    while (p != NULL) {
        Addtail(l, CreateNode(p->info));
        p = p->next;
    }
    while (q != NULL) {
        Addtail(l, CreateNode(q->info));
        q = q->next;
    }
}

int main() {
    List l;
    CreateList(l);
    int n, x;
    cout << "Nhap so phan tu cua danh sach: ";
    cin >> n;
    cout << "Nhap danh sach: ";
    for (int i = 1; i <= n; i++) {
        cin >> x;
        Addtail(l, CreateNode(x));
    }
    Shuffle(l);
    cout << "Danh sach da sap xep:\n";
    PrintList(l);
    return 0;
}
