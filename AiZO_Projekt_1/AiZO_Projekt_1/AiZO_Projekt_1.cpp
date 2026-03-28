#include <iostream>

int N = 10; template <typename T>
void insertionSort(T* array, int size, int gap) {
    for (int gapI = 0; gapI < gap; gapI++) {
        for (int i = size - 1 - gapI - gap; i >= 0; i -= gap) {
            for (int j = i; j < size - gapI - 1; j += gap) {
                if (array[j] > array[j + gap]) {
                    int helper = array[j];
                    array[j] = array[j + gap];
                    array[j + gap] = helper;
                }
                else {
                    break;
                }
            }
        }
    }
}

template <typename T>
void quickSort(T* array, int left, int right) {
    int helper;
    helper = array[left + ((right - left) / 2)];
    array[left + ((right - left) / 2)] = array[right];
    array[right] = helper;

    int j = left;
    for (int i = left; i < right; i++) {
        if (array[i] < array[right]) {
            helper = array[i];
            array[i] = array[j];
            array[j] = helper;
            j++;
        }
    }

    helper = array[right];
    array[right] = array[j];
    array[j] = helper;

    /*for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;*/

    if (j - 1 > left) {
        quickSort(array, left, j - 1);
    }

    if (j + 1 < right) {
        quickSort(array, j + 1, right);
    }
}

template <typename T>
void shellSort(T* array, int size) {
    int gap = size / 2;
    for (; gap >= 1; gap /= 2) {
        insertionSort(array, size, gap);
    }
}

int main()
{
    srand(time(0));

    int* array = new int[N];
    int* arrayCopy = new int[N];

    for (int i = 0; i < N; i++) {
        array[i] = rand() % 10;
        arrayCopy[i] = array[i];
    }
    
    for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    quickSort(array, 0, N - 1);

    for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < N; i++) {
        array[i] = arrayCopy[i];
    }

    for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    shellSort(array, N);

    for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}