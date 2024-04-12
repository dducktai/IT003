#include <iostream>

using namespace std;


//Khai báo Node
struct Node {
    int coso;
    int luythua;
    Node* Next;
};

//Khai báo list
struct List {
    Node* pHead;
    Node* pTail;
};

//Tạo một danh sách (rỗng)
void CreatList(List& l) {
    l.pHead = l.pTail = NULL;
}

//Tạo một Node 
Node* CreateNode(int a, int b) {
    Node* p = new Node;
    p->coso = a;
    p->luythua = b;
    p->Next = NULL;
    return p;
}

//Thêm vào đầu danh sách
void AddpHead(List& l, Node* p) {
    if (l.pHead == NULL) {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else {
        p->Next = l.pHead;
        l.pHead = p;
    }
}

//Thêm vào cuối danh sách
void AddpTail(List& l, Node* p) {
    if (l.pHead == NULL) {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else {
        l.pTail->Next = p;
        l.pTail = p;
    }
}

//Thêm p vào sau Node q cho trước
void InsertAfter(List& l, Node* p, Node* q) {
    if (q != NULL) {
        p->Next = q->Next;
        q->Next = p;
        if (l.pTail == q)
            l.pTail = p;
    }
    else {
        AddpHead(l, p); //Thêm vào đầu danh sách
    }
}


//Nhập vào danh sách
void InputList(List& l, int n) {
    cout << "Da thuc co dang: a0 + a1.x + ... + an.x^n" << endl;
    cout << "Nhap lan luot cac he so a0, a1 ... an: ";
    for (int i = 0; i <= n; i++) {
        int x;
        cin >> x;
        Node* p = CreateNode(x, i);
        AddpTail(l, p);
    }
}


//In ra danh sách  
void PrintList(List& l) {
    Node* p = l.pHead;
    while (p != NULL) {
        if (p == l.pHead) {
            if (p->coso != 0) {
                cout << p->coso << " ";
            }
            p = p->Next;
        }
        else {
            if (p->coso != 0) {
                if (p->luythua == 1) {
                    if (p->coso > 0) {
                        if (abs(p->coso) != 1) {
                            cout << "+ " << p->coso << "x ";
                        }
                        else {
                            cout << "+ " << "x ";
                        }
                    }
                    else {
                        if (abs(p->coso) != 1) {
                            cout << "- " << p->coso << "x ";
                        }
                        else {
                            cout << "- " << "x ";
                        }
                    }
                }
                else {
                    if (p->coso > 0) {
                        if (abs(p->coso) != 1) {
                            cout << "+ " << p->coso << "x^" << p->luythua << " ";
                        }
                        else {
                            cout << "+ " << "x^" << p->luythua << " ";
                        }
                    }
                    else {
                        if (abs(p->coso) != 1) {
                            cout << "- " << abs(p->coso) << "x^" << p->luythua << " ";
                        }
                        else {
                            cout << "- " << "x^" << p->luythua << " ";
                        }

                    }
                }
            }
            p = p->Next;
        }
    }
    cout << endl;
}

//Cộng hai đa thức
void Sum(List& x, List& y, List& s) {
    Node* a = x.pHead;
    Node* b = y.pHead;

    while ((a != NULL) && (b != NULL)) {
        AddpTail(s, CreateNode(a->coso + b->coso, a->luythua));
        a = a->Next;
        b = b->Next;
    }
    while (a != NULL) {
        AddpTail(s, CreateNode(a->coso, a->luythua));
        a = a->Next;
    }
    while (b != NULL) {
        AddpTail(s, CreateNode(b->coso, b->luythua));
        b = b->Next;
    }
}

int main()
{
    List l, k, result;
    CreatList(l);
    CreatList(k);
    CreatList(result);

    int a, b;
    cout << "Da thuc thu nhat co bac cao nhat la: ";
    cin >> a;
    InputList(l, a);
    cout << endl;
    cout << "Da thuc thu hai co bac cao nhat la: ";
    cin >> b;
    InputList(k, a);

    Sum(l, k, result);
    cout << endl;
    PrintList(result);
    
    system("Pause");
}

