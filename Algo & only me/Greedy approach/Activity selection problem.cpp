#include <bits/stdc++.h>

void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {    // X na howa porjonto colbe
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    } // ei loop theke ber howa mane iXj hoya gese

    std::swap(arr[left], arr[j]);

    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

int main()
{
    int n=3;
    int st[n]={10,12,20};
    int fin[n]={20,15,30};

     quickSort(fin, 0, n - 1);


}
