#include <bits/stdc++.h>
using namespace std;


bool sx(int x, int y)
{
    if(x%2==0 && y%2==0)
        return x<y;
    if(x%2!=0 && y%2!=0)
        return x>y;
    return true;
}
int main()
{
    int a[] = { 12, 8, 2, 14, 3, 5, 10, 15, 36 };
    for(int i = 0; i<8 ; i++)
        for(int j=i+1; j < 9; j++)  {
            if(!sx(a[i], a[j]))
                swap(a[i], a[j]);  }

    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
}
