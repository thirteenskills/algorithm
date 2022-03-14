#include <iostream>
using namespace std;

int *merge(int arr[],int be,int po,int ed);

int *sort(int arr[], int be, int en)
{
    if (be >= en)
    {
        return arr;
    }

    int po = be+(en - be) / 2;
    sort(arr, be, po);
    sort(arr, po + 1, en);
    merge(arr,be,po+1,en);
    return arr;
}

int *merge(int arr[],int be,int po,int ed)
{

    int arr1[po-be], arr2[ed-po+1];
    for (int i = be; i < po; i++)
    {
        arr1[i-be] = arr[i];
    }
    for (int i = po; i <ed+1; i++)
    {
        arr2[i-po] = arr[i];
    }
    int j = 0, k = 0;
    for (int i = be; i < ed+1; i++)
    {
        if (j == po-be)
        {
            for (int t = i; t <ed+1; t++)
            {
                arr[t] = arr2[k + t-i];
            }
            break;
        }
        if (k == ed-po+1)
        {
            for (int t = i; t <ed+1; t++)
            {
                arr[t] = arr1[j + t-i];
            }
            break;
        }
        if (arr1[j] < arr2[k])
        {
            arr[i] = arr1[j];
            j += 1;
        }
        else
        {
            arr[i] = arr2[k];
            k += 1;
        }
    }
    return arr;
}

int main()
{
    int a[]={13,5,867,34,1,0,87,9,1,3,5,2,6,8,7};
    int  x=sizeof(a)/sizeof(a[1]);
    sort(a,0,x-1);
    
    for(int i=0;i<x;i++)
    cout<<a[i]<<" ";
    return 0;
}