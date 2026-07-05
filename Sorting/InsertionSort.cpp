#include <iostream>
using namespace std;

int main()
{
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int u = size - 1;
    int l = 0;

    // Insertion Sort
    for (int i = l + 1; i <= u; i++)
    {
        int value = arr[i];
        int j;

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] <= value)
                break;

            arr[j + 1] = arr[j];
        }

        arr[j + 1] = value;
    }

    cout << "\nSorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}