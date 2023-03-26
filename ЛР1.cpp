#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
static int partition(T arr[], int idx_start, int idx_end)
{
    //pivot это опорный элемент

    int idx_pivot = 0;
    // rand
    int pivot = arr[idx_start];

    int counter = 0, i = 0, j = 0;

    for (int i = idx_start + 1; i <= idx_end; ++i)
        if (arr[i] <= pivot)
            counter++;

    idx_pivot = counter + idx_start;

    swap(arr[idx_pivot], arr[idx_start]);

    i = idx_start;
    j = idx_end;

    while (i < idx_pivot && j > idx_pivot)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < idx_pivot && j > idx_pivot)
            swap(arr[i], arr[j]);
    }
    return idx_pivot;
}

template <typename T>
void quickSort(T arr[], int idx_start, int idx_end)
{
    if (idx_start >= idx_end)
        return;
    int idx_pivot = partition(arr, idx_start, idx_end);

    quickSort(arr, idx_start, idx_pivot - 1);
    quickSort(arr, idx_pivot + 1, idx_end);

}

template <typename T>
void bubleSort(T arr[], int idx_end){
    for (int i = 0; i <= idx_end; i++) {
        bool isDone = true;
        for (int j = 0; j <= idx_end - (i + 1); j++) {
            if (arr[j] > arr[j + 1]) {
                isDone = false;
                swap (arr[j], arr[j + 1]);
            }
        }
        if (isDone == true) {
            break;
        }
    }
}

template <typename T>
void countSort(T arr[], int idx_end){
    int count = 0;
    for (int i = 0; i <= idx_end; i++) {

        for (int j = 0; j <= idx_end; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
            swap(arr[i],arr[count]);
        }
    }
}

int main()
{

    unsigned int start_time = clock();

    int arrQ[] = {1, 9, 7, 4, 11 };
    int size_arr = sizeof(arrQ) / sizeof(arrQ[0]);
    cout << "Array before sort: \n";
    for (int i = 0; i < size_arr; ++i)
        cout << arrQ[i] << " ";
    cout << endl;

    cout << "Array sorted by Quick Sort method: \n";
    quickSort(arrQ, 0, size_arr - 1);

    for (int i = 0; i < size_arr; ++i)
        cout << arrQ[i] << " ";
    cout << endl;

    double arrQd[] = {1.5, 9.5, 7.5, 4.5, 11.5 };
    cout << "Array before sort: \n";
    for (int i = 0; i < size_arr; ++i)
        cout << arrQd[i] << " ";
    cout << endl;
    int size_arr2 = sizeof(arrQd) / sizeof(arrQd[0]);
    cout << "Array sorted by Quick Sort method: \n";
    quickSort(arrQd, 0, size_arr2 - 1);

    for (int i = 0; i < size_arr2; ++i)
        cout << arrQd[i] << " ";


    int arrB[] = { 41,3,0,13,29 };
    cout << "\nArray before sort: \n";
    for (int i = 0; i < size_arr; ++i)
        cout << arrB[i] << " ";
    cout << endl;
    int size_arrB = sizeof(arrB) / sizeof(arrB[0]);
    cout << "Array sorted by Bubble Sort method: \n";
    bubleSort(arrB ,size_arrB - 1);
    for (int i = 0; i < size_arrB; ++i)
        cout << arrB[i] << " ";

    int arrC[] = { 21,3,22,13,29 };
    cout << "\nArray before sort: \n";
    for (int i = 0; i < size_arr; ++i)
        cout << arrC[i] << " ";
    cout << endl;
    int size_arrC = sizeof(arrC) / sizeof(arrC[0]);
    cout << "Array sorted by Count Sort method: \n";
    bubleSort(arrC ,size_arrC - 1);
    for (int i = 0; i < size_arrC; ++i)
        cout << arrC[i] << " ";
    cout << endl;

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Time: " << search_time;

    return 0;
}