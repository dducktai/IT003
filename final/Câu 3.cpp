#include "iostream"
#include "cmath"
using namespace std;

struct node {
    int data;
    int mu;
    node *next;
};

struct Dathuc {
    node *head;
    node *tail;
};

node* CreateNode(int x, int y) {
    node *p = new node;
    p->data = x;
    p->mu = y;
    p->next = NULL;
    return p;
}

void CreateList(Dathuc &l) {
    l.head = l.tail = NULL;
}

void AddHead(Dathuc &l, node *p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = NULL;
    } else {
        p->next = l.head->next;
        l.head = p;
    }
}

void Addtail(Dathuc &l, node *p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void PrintDathuc(Dathuc &l) {
    node *p = l.head;
    while (p != NULL) {
        if (p == l.head) {
            if (p->data != 0) {
                cout << p->data << " ";
            }
            p = p->next;
        } else {
            if (p->data != 0) {
                if (p->mu == 1) {
                    if (p->data > 0) {
                        if (abs(p->data) != 1) {
                            cout << "+ " << p->data << "x ";
                        } else {
                            cout << "+ " << "x ";
                        }
                    } else {
                        if (abs(p->data) != 1) {
                            cout << "- " << p->data << "x ";
                        } else {
                            cout << "- " << "x ";
                        }
                    }
                } else {
                    if (p->data > 0) {
                        if (abs(p->data) != 1) {
                            cout << "+ " << p->data << "x^" << p->mu << " ";
                        } else {
                            cout << "+ " << "x^" << p->mu << " ";
                        }
                    } else {
                        if (abs(p->data) != 1) {
                            cout << "- " << abs(p->data) << "x^" << p->mu << " ";
                        } else {
                            cout << "- " << "x^" << p->mu << " ";
                        }

                    }
                }
            }
            p = p->next;
        }
    }
    cout << endl;
}

void Sum(Dathuc &x, Dathuc &y, Dathuc &s) {
    node *a = x.head;
    node *b = y.head;

    while ((a != NULL) && (b != NULL)) {
        Addtail(s, CreateNode(a->data + b->data, a->mu));
        a = a->next;
        b = b->next;
    }
    while (a != NULL) {
        Addtail(s, CreateNode(a->data, a->mu));
        a = a->next;
    }
    while (b != NULL) {
        Addtail(s, CreateNode(b->data, b->mu));
        b = b->next;
    }
}

int main() {
    Dathuc d1, d2, sum;
    CreateList(d1); CreateList(d2); CreateList(sum);
    cout << "Nhap mu so cao nhat cua da thuc 1, n1 = ";
    int n1, x;
    cin >> n1;
    cout << "Nhap lan luot cac he so da thuc 1: a0 + a1.x + a2.x^2 +...+an1.x^n1\n";
    for (int i = 0; i <= n1; i++) {
        cin >> x;
        Addtail(d1, CreateNode(x, i));
    }
    cout << "Nhap mu so cao nhat cua da thuc 2, n2 = ";
    int n2, y;
    cin >> n2;
    cout << "Nhap lan luot cac he so da thuc 2: a0 + a1.x + a2.x^2 +...+an2.x^n1\n";
    for (int i = 0; i <= n2; i++) {
        cin >> y;
        Addtail(d2, CreateNode(y, i));
    }
    Sum(d1, d2, sum);
    cout << "Ket qua cong 2 da thuc: ";
    PrintDathuc(sum);
    return 0;
}
