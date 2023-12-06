#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

void quicksort(vector<int> &A, int left, int right)
{
    int i = left, j = right;
    int pivot = A[(i + j) / 2];
    while (i <= j)
    {

        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j)
            swap(A[i], A[j]), i++, j--;
    }

    if (j > left)
        quicksort(A, left, j);
    if (i < right)
        quicksort(A, i, right);
}

void printArr(vector<int> &A)
{
    for (int num : A)
    {
        std::cout << num << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    quicksort(arr, 0, arr.size() - 1);

    printArr(arr);
    return 0;
}