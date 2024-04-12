#include <iostream>
#include <ctime>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <stdlib.h>


using namespace std;

int random(int minN, int maxN)
{
 return minN + rand() % (maxN + 1 - minN);
}

void input_arr(int a[], int &n)
{
    cin >> n;
    cout << "n = " << n;
    cout << endl;
    int r;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-1000,1000);
        a[i] = r;
    }
}

int linearSearch(int arr[], int x)
{
    int i;
    for (i = 0; i < 1000; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    int n;
    int arr[1000000];
    srand(time(NULL));
    input_arr(arr, n);


}
