#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>
#include <assert.h>
using namespace std;

int *generateRandomArray(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);

    int *arr = new int[n]; // 创建一个 n个元素的数组

    srand(time(NULL)); // 随机种子
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}

int di_find(int arr[], int be, int ed, int a)
{
    if (be == ed)
        return (a > arr[be]) ? be : be - 1;
    else if (be > ed)
        return be - 1;
    else
    {
        int po = be + (ed - be) / 2;
        if (a < arr[po])
            di_find(arr, be, po, a);
        else if (a > arr[po])
            di_find(arr, po + 1, ed, a);
        else
            return po;
    }
}

int *insertsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int card = arr[i];
        int x = di_find(arr, 0, i - 1, card);
        int j = i - 1;
        while (j > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[x + 1] = card;
    }
    return arr;
}

int main()
{
    int *x = generateRandomArray(500000, 1, 500000);
    insertsort(x, 500000);
    int con = 0;
    for (int i = 0; i < 500000; i++)
    {
        cout << x[i] << ' ';
        con++;
    }
    cout <<endl<< con;
    system("pause");
    return 0;
}