#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

enum DataType { INTEGER, REAL };
enum SortAlgorithm { BUBBLE, SELECTION, INSERTION, MERGE, COUNTING, HEAP, BUCKET, QUICK };

// n= 30.000, 50.000, 100.000, 150.000, 200.000, 500.000, 1.000.000, 2.000.000, 5.000.000, 10.000.000


int chooseArraySize() {
    int choice;

    std::cout << "Wybierz rozmiar tablicy:\n";
    std::cout << "1. 30.000\n";
    std::cout << "2. 50.000\n";
    std::cout << "3. 100.000\n";
    std::cout << "4. 150.000\n";
    std::cout << "5. 200.000\n";
    std::cout << "6. 500.000\n";
    std::cout << "7. 1.000.000\n";
    std::cout << "8. 2.000.000\n";
    std::cout << "9. 5.000.000\n";
    std::cout << "10. 10.000.000\n";

    std::cin >> choice;

    switch (choice) {
        case 1: return 30000;
        case 2: return 50000;
        case 3: return 100000;
        case 4: return 150000;
        case 5: return 200000;
        case 6: return 500000;
        case 7: return 1000000;
        case 8: return 2000000;
        case 9: return 5000000;
        case 10: return 10000000;
        default:
            std::cout << "Invalid choice. Please choose a number between 1 and 10.\n";
            return chooseArraySize();
    }
}

DataType chooseDataType() {
        int choice;

        std::cout << "Podaj typ danych:\n";
        std::cout << "0. LICZBA_CALKOWITA\n";
        std::cout << "1. LICZBA_RZECZYWISTA\n";
        std::cin >> choice;

        switch (choice) {
            case 0: return INTEGER;
            case 1: return REAL;
            default:
                std::cout << "Nieprawidłowy wybór. Proszę podać liczbę 0 lub 1.\n";
                return chooseDataType();
        }
    }

SortAlgorithm chooseSortAlgorithm() {
        int choice;

        std::cout << "Wybierz algorytm sortowania:\n";
        std::cout << "0. BUBBLE\n";
        std::cout << "1. SELECTION\n";
        std::cout << "2. INSERTION\n";
        std::cout << "3. MERGE\n";
        std::cout << "4. COUNTING (tylko liczby calkowite)\n";
        std::cout << "5. HEAP\n";
        std::cout << "6. BUCKET\n";
        std::cout << "7. QUICK\n";
        std::cin >> choice;

        switch (choice) {
            case 0: return BUBBLE;
            case 1: return SELECTION;
            case 2: return INSERTION;
            case 3: return MERGE;
            case 4: return COUNTING;
            case 5: return HEAP;
            case 6: return BUCKET;
            case 7: return QUICK;
            default:
                std::cout << "Invalid choice. Please choose a number between 0 and 7.\n";
                return chooseSortAlgorithm();
        }
    }

template <typename T>
class Array {
    std::vector<T> data;

public:
    Array(int size) : data(size) {
        // Fill the array with random data
        std::generate(data.begin(), data.end(), std::rand);
    }

    void bubbleSort() {
        for (int i = 0; i < data.size() - 1; i++) {
            for (int j = 0; j < data.size() - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }

    void selectionSort() {
        for (int i = 0; i < data.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < data.size(); j++) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(data[i], data[minIndex]);
        }
    }

    void insertionSort() {
        for (int i = 1; i < data.size(); i++) {
            T key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    void mergeSort() {
        mergeSortHelper(0, data.size() - 1);
    }

    void mergeSortHelper(int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSortHelper(low, mid);
            mergeSortHelper(mid + 1, high);
            merge(low, mid, high);
        }
    }

    void merge(int low, int mid, int high) {
        int leftSize = mid - low + 1;
        int rightSize = high - mid;

        std::vector<T> left(leftSize);
        std::vector<T> right(rightSize);

        for (int i = 0; i < leftSize; i++) {
            left[i] = data[low + i];
        }

        for (int j = 0; j < rightSize; j++) {
            right[j] = data[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = low;

        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                data[k] = left[i];
                i++;
            } else {
                data[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < leftSize) {
            data[k] = left[i];
            i++;
            k++;
        }

        while (j < rightSize) {
            data[k] = right[j];
            j++;
            k++;
        }
    }

    void countingSort() {
        // Find the maximum element in the array
        T maxElement = *std::max_element(data.begin(), data.end());

        // Create a count array to store the count of each element
        std::vector<int> count(maxElement + 1, 0);

        // Count the occurrences of each element
        for (int i = 0; i < data.size(); i++) {
            count[data[i]]++;
        }

        // Calculate the cumulative count
        for (int i = 1; i < count.size(); i++) {
            count[i] += count[i - 1];
        }

        // Create a temporary array to store the sorted elements
        std::vector<T> sorted(data.size());

        // Place the elements in the sorted array
        for (int i = data.size() - 1; i >= 0; i--) {
            sorted[count[data[i]] - 1] = data[i];
            count[data[i]]--;
        }

        // Copy the sorted elements back to the original array
        for (int i = 0; i < data.size(); i++) {
            data[i] = sorted[i];
        }
    }

    void heapSort() {
        // Build max heap
        for (int i = data.size() / 2 - 1; i >= 0; i--) {
            heapify(data.size(), i);
        }

        // Extract elements from the heap one by one
        for (int i = data.size() - 1; i > 0; i--) {
            std::swap(data[0], data[i]);
            heapify(i, 0);
        }
    }

    void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left] > data[largest]) {
            largest = left;
        }

        if (right < n && data[right] > data[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(data[i], data[largest]);
            heapify(n, largest);
        }
    }

    void bucketSort() {
        // Implement bucket sort
        std::vector<std::vector<T>> buckets(data.size());
        
        // Place elements into buckets
        for (int i = 0; i < data.size(); i++) {
            int bucketIndex = data.size() * data[i];
            buckets[bucketIndex].push_back(data[i]);
        }
        
        // Sort each bucket
        for (int i = 0; i < data.size(); i++) {
            std::sort(buckets[i].begin(), buckets[i].end());
        }
        
        // Concatenate the sorted buckets
        int index = 0;
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                data[index++] = buckets[i][j];
            }
        }
    }

    void quickSort() {
        quickSortHelper(0, data.size() - 1);
    }

    void quickSortHelper(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);
            quickSortHelper(low, pivotIndex - 1);
            quickSortHelper(pivotIndex + 1, high);
        }
    }

    int partition(int low, int high) {
        T pivot = data[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }

        std::swap(data[i + 1], data[high]);
        return i + 1;
    }

    void sort(SortAlgorithm algorithm) {
        switch (algorithm) {
            case BUBBLE: bubbleSort(); break;
            case SELECTION: selectionSort(); break;
            case INSERTION: insertionSort(); break;
            case MERGE: mergeSort(); break;
            case COUNTING: countingSort(); break;
            case HEAP: heapSort(); break;
            case BUCKET: bucketSort(); break;
            case QUICK: quickSort(); break;
        }
    }
};

int main() {
    DataType dataType;
    SortAlgorithm sortAlgorithm;
    int size;

    dataType = chooseDataType();

    size = chooseArraySize();

    if (dataType == INTEGER) {
        Array<int> array(size);
        array.sort(sortAlgorithm);
    } else {
        Array<double> array(size);
        array.sort(sortAlgorithm);
    }

    return 0;
}