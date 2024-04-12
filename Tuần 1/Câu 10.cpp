#include <iostream>
using namespace std;

struct DonThuc {
	int Dau;
	double HeSo;
	int Bac;
};

struct Node
{
    DonThuc data;
    Node* pNext = NULL;
};
struct List
{
    Node* pHead = NULL;
    Node* pTail = NULL;
};

Node* createNode(DonThuc x)
{
    Node* p = new Node;
    p->data = x;
    return p;
}

void addTail(List& l, DonThuc x)
{
    Node* p = createNode(x);
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void NhapDaThuc(List& l)
{
    int n;
    cout << "Cho biet bac cua da thuc: ";
    cin >> n;
    DonThuc x;
    for (int i = 0; i < n; ++i)
    {
        cout << "So hang thu " << i + 1 << '\n';
        do {
            cout << "Cho biet dau: ";
            cin >> x.Dau;
        } while (x.Dau != 0 && x.Dau != 1);
        cout << "Cho biet he so: ";
        cin >> x.HeSo;
        do {
            cout << "Cho biet bac: ";
            cin >> x.Bac;
        } while (x.Bac < 0 || x.Bac > 99 || x.Bac > n);
        cout << '\n';
        addTail(l, x);
    }
}
void Sapxep(List l) {
    Node* p = l.pHead;
    while (p != NULL) {
        Node* q = p->pNext;
        Node* max = p;
        while (q != NULL) {
            if (q->data.Bac > max->data.Bac)
                max = q;
            q = q->pNext;
        }
        swap(p->data, max->data);
        p = p->pNext;
    }
}

void XuatDonThuc(DonThuc x)
{
    if (x.Dau == 0) cout << "-";
    cout << x.HeSo << "x^" << x.Bac << " " ;
}
void XuatDaThuc(List& l)
{
    cout << "\n";
    Node* p = l.pHead;
    while (p)
    {
        XuatDonThuc(p->data);
        p = p->pNext;
        if (p->data.Dau == 1) cout << "+";
    }
}

int main() {
    List l;
    NhapDaThuc(l);
    Sapxep(l);
    XuatDaThuc(l);
    return 0;
}