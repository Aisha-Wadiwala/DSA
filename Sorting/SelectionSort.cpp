#include <iostream>
using namespace std;

// Function to perform Selection Sort
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        // Find the index of the smallest element
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // Swap the smallest element with the current element
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    SelectionSort(arr, size);

    cout << "\nArray after Selection Sort:" << endl;
    Display(arr, size);

    return 0;
}