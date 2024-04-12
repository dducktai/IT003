
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
    if (l.head == NULL) {
        cout << "Empty!\n";
        return;
    }
    Node *p = l.head;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

/*void Shuffle(List &l) {
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
}*/

void Split(List &l, List &chan, List &le) {
    Node *p = l.head;
    while (p != NULL) {
        if (p->info % 2 == 0) {
            Addtail(chan, CreateNode(p->info));
        } else {
            Addtail(le, CreateNode(p->info));
        }
        p = p->next;
    }
}

int main() {
    List l, chan, le; int n, x;
    CreateList(l); CreateList(chan); CreateList(le);
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap danh sach: ";
    for (int i = 1; i <= n; i++) {
        cin >> x;
        Addtail(l, CreateNode(x));
    }
    Split(l, chan, le);
    cout << "Danh sach phan tu so nguyen chan: ";
    PrintList(chan);
    cout << "Danh sach phan tu so nguyen le: ";
    PrintList(le);
    return 0;
}
