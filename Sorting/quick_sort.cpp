#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a=b;
    b=t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i=low-1;
    for(int j=low; j< high;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int main()
{
    int arr[7] = {5, 3, 44, 1, 88, 254, 5};
    cout<<"Before Sorting :   ";
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr, 0, 6);
    cout<<"After Sorting :   ";
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}