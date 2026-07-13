#include <iostream>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap adjacent elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // If no swapping occurred, array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

// Display Array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    displayArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    displayArray(arr, n);

    return 0;
}