#include <iostream>

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

int main() {
    int arr[] = {2, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

