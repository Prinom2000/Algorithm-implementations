#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void merge(vector<int> &A, int left, int mid, int right)
{
    int Nl, Nr;
    Nl = mid - left + 1;
    Nr = right - mid;

    vector<int> Q1(Nl + 1);
    vector<int> Q2(Nr + 1);

    for (int i = 0; i < Nl; i++)
        Q1[i] = A[i + left];
    for (int i = 0; i < Nr; i++)
        Q2[i] = A[i + mid + 1];

    int i = 0, j = 0, k = left;
    while (i < Nl && j < Nr)
    {
        if (Q1[i] <= Q2[j])
            A[k] = Q1[i], i++;
        else
            A[k] = Q2[j], j++;
        k++;
    }

    while (i < Nl)
    {
        A[k] = Q1[i];
        i++;
        k++;
    }

    while (j < Nr)
    {
        A[k] = Q2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &A, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + (right - left) / 2);
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);

    merge(A, left, mid, right);
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
    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);
    return 0;
}