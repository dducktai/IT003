#include <iostream>

using namespace std;


//Khai báo node
struct Node {
    int Data;
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

//Tạo một node 
Node* CreatNode(int x) {
    Node* p = new Node;
    p->Data = x;
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

//Thêm p vào sau node q cho trước
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
    for (int i = 1; i <= n; i++) {
        int x;
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> x;
        Node* p = CreatNode(x);
        AddpTail(l,p);
    }
}


//In ra danh sách  
void Print(List l) {
    Node* p = l.pHead;
    while (p != NULL) {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}


//Tìm một phần tử trong danh sách
Node* Search(List l, int x) {
    Node* p;
    p = l.pHead;
    while ((p != NULL) && (p->Data != x))
        p = p->Next;
    return p;
}

//Sắp xếp trực tiếp
void SelectionSort_Increase(List& l) {
    Node* p, * q, * min;
    p = l.pHead;
    while (p != l.pTail) {
        min = p;
        q = p->Next;
        while (q != NULL) {
            if (q->Data < p->Data)
                min = q;
            q = q->Next;
        }
        swap(min->Data, p->Data);
        p = p->Next;
    }
}


int main()
{
    List l;
    CreatList(l);
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    InputList(l, n);
    SelectionSort_Increase(l);
    Print(l);
    system("Pause");
}
