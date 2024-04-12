#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;


int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}


void input_arr(int a[])
{
    int n = 10000;
    int r;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-1000, 1000);
        a[i] = r;
    }
}



int linearSearch(int A[], int x) {
    int i = 0;
    int n = 10000;
    while (i < n) {
        if (A[i] == x) return i;
        i++;
    }
    return -1;
}



int binarySearch(int A[], int x) {
    int n = 10000;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (x == A[m]) return m;
        if (x < A[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}


int main()
{
    int a[1000000], x;
    double time_use = 0.0;
    clock_t start, end;
    input_arr(a);
    cout << "Nhap so ban muon tim: ";
    cin >> x;

    int options;
    cout << endl << "Chon thuat toan:" << endl << "1. Tim kiem tuyen tinh" << endl << "2. Tim kiem nhi phan" << endl;
    cout << "Vui long chon thuat toan: ";
    start = clock();
    do
    {
        cin >> options;
        if (options < 1 || options > 2) cout << "Loi, chon lai: ";
    } while (options >= 1 && options <= 2);

            switch (options)
            {
            case 1:
                linearSearch(a,x);
                    break;
            case 2:
                binarySearch(a,x);
                    break;
            }
        end = clock();
        time_use = (double)(end - start) / CLOCKS_PER_SEC;
        cout << endl;
        cout << "Thoi gian chay chuong trinh: " << fixed << time_use << " giây" << endl;
}
