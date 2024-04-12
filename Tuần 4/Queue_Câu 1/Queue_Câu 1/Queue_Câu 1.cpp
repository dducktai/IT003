#include <iostream>
#include <string>

using namespace std;

//Cấu trúc Date 
struct Date {
	int day, month, year;
};

//Cấu trúc Node 
struct Node {
	string ID, name;
	Date exportDate;
	int price;
	Node* next; //con trỏ next 
};


//Cấu trúc hàng đợi
struct queue {
	Node* front;
	Node* rear;
}; typedef queue QUEUE;


//Khởi tạo 
void Init(QUEUE& q) {
	q.front = NULL;
	q.rear = NULL;
}


//Tạo một node 
Node* CreatNode(string ID, string name, Date exportDate, int price) {
	Node* p = new Node;
	p->ID = ID;
	p->name = name;
	p->exportDate = exportDate;
	p->price = price;
	p->next = NULL;
	return p;
}

//Kiểm tra xem queue có rỗng không
bool IsEmpty(QUEUE q) {
	if (q.front == NULL)
		return true;
	return false;
}

//Thêm node a vào queue q 
void Push(QUEUE& q, Node* p) {
	if (IsEmpty(q)) {
		q.front = p;
		q.rear = p;
	}
	else {
		q.rear->next = p;
		q.rear = p;
	}
}

//Lấy phần tử ở đầu queue ra 
Node* Pop(QUEUE& q) {
	if (IsEmpty(q)) {
		return NULL;
	}
	Node* p = q.front;
	q.front = q.front->next;

	return p;
}

//Nhập một node vào 
Node* Import() {
	string ID, name;
	Date exportDate;
	int price;
	cout << endl << "	- Nhap ma may: ";
	cin >> ID;
	cin.ignore();
	cout << endl << "	- Nhap ten may: ";
	getline(cin, name);
	cout << endl << "	- Nhap ngay xuat hang: ";
	cin >> exportDate.day;
	cout << endl << "	- Nhap thang xuat hang: ";
	cin >> exportDate.month;
	cout << endl << "	- Nhap nam xuat hang: ";
	cin >> exportDate.year;
	cout << endl << "	- Nhap gia xuat hang: ";
	cin >> price;
	Node* p;
	p = CreatNode(ID, name, exportDate, price);
	return p;
}

//Xuất một node ra màn hình 
void Display(Node* p) {
	cout << endl << "	- Ma may: " << p->ID;
	cout << endl << "	- Ten may: " << p->name;
	cout << endl << "	- Ngay xuat hang: " << p->exportDate.day << "/" << p->exportDate.month << "/" << p->exportDate.year;
	cout << endl << "	- Gia xuat hang: " << p->price;
}

//Nhập n node vào trong queue q 
void Input(QUEUE& q, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap node thu " << i + 1 << ": " << endl;
		Node* p;
		p = Import();
		Push(q, p);
	}
}

//Xuất các node trong queue ra màn hình 
void Output(QUEUE q) {
	int i = 1;
	for (Node* p = q.front; p != NULL; p = p->next) {
		cout << "May thu " << i << ":" << endl;
		Display(p);
		cout << endl;
		i++;
	}
}


int main() {
	QUEUE q;
	Init(q);
	int n;
	cout << "Cau 1: Da hoan thanh" << endl;
	cout << "Cau 2:" << endl;
	cout << "Nhap so luong may tinh: ";
	cin >> n;
	Input(q, n);
	cout << endl << "Cau 3: ";
	for (Node* p = q.front; p != NULL; p = p->next) {
		if (p->ID == "007")
			Display(p);
	}
	cout << endl << "Cau 4: ";
	Output(q);
	return 0;
}
