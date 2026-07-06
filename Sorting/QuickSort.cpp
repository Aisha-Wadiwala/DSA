#include <iostream>
using namespace std;

// Function to partition the array
int Partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int index = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;

            int temp = arr[index];
            arr[index] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot at its correct position
    index++;

    int temp = arr[index];
    arr[index] = arr[end];
    arr[end] = temp;

    return index;
}

// Function to perform Quick Sort
void QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = Partition(arr, start, end);

        QuickSort(arr, start, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, end);
    }
}

// Function to display the array
void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements:" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, size - 1);

    cout << "\nArray after Quick Sort:" << endl;
    Display(arr, size);

    return 0;
}