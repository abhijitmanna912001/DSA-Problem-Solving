#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity)
    {
        this->arr = new int[capacity + 1];
        this->capacity = capacity;
        this->size = 0;
        arr[0] = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
                break;
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int ans = arr[1];
        arr[1] = arr[size];
        size--;

        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestElementIndex = index;

            if (leftIndex <= size && arr[largestElementIndex] < arr[leftIndex])
                largestElementIndex = leftIndex;
            if (rightIndex <= size && arr[largestElementIndex] < arr[rightIndex])
                largestElementIndex = rightIndex;

            if (index == largestElementIndex)
                break;
            else
            {
                swap(arr[index], arr[largestElementIndex]);
                index = largestElementIndex;
            }
        }

        return ans;
    }

    void heapify(int *arr, int n, int index)
    {
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;
        int largestElementIndex = index;

        if (leftIndex <= n && arr[leftIndex] > arr[largestElementIndex])
            largestElementIndex = index;
        if (rightIndex <= n && arr[rightIndex] > arr[largestElementIndex])
            largestElementIndex = rightIndex;
        if (index != largestElementIndex)
        {
            swap(arr[index], arr[largestElementIndex]);
            index = largestElementIndex;
            heapify(arr, n, index);
        }
    }

    void buildHeap(int arr[], int n)
    {
        for (int index = n / 2; index > 0; index--)
            heapify(arr, n, index);
    }

    void heapSort(int arr[], int n)
    {
        while (n != 1)
        {
            swap(arr[1], arr[n]);
            n--;
            heapify(arr, n, 1);
        }
    }
};

int main()
{
    // Create a heap with capacity 20
    Heap h(20);

    // Insert elements into the heap
    h.insert(100);
    h.insert(50);
    h.insert(60);
    h.insert(30);
    h.insert(20);

    // Print the heap
    cout << "Heap after inserting elements: " << endl;
    h.printHeap();

    // Delete the root element
    int ans = h.deleteRoot();
    cout << "Deleted root element: " << ans << endl;

    // Print the heap after deleting the root
    cout << "Heap after deleting root: " << endl;
    h.printHeap();

    // Example array for buildHeap and heapSort
    int arr[] = {0, 10, 20, 30, 40, 50}; // Including a dummy 0 index
    int n = 5;                           // Number of elements

    // Build heap using the array
    cout << "Building heap from array: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    h.buildHeap(arr, n);

    // Print heap after building it
    cout << "Heap after buildHeap: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Perform heap sort
    h.heapSort(arr, n);

    // Print array after heap sort
    cout << "Array after heapSort: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}