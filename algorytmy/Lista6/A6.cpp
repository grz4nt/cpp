#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

enum class typDanych { calkowite, rzeczywiste };
enum class algorytmSortowania { bubble, selection, insertion, merge, counting, heap, bucket, quicksort };

// n= 30.000, 50.000, 100.000, 150.000, 200.000, 500.000, 1.000.000, 2.000.000, 5.000.000, 10.000.000

int rozmiarTablicy() {
    int wybor;

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

    std::cin >> wybor;

    switch (wybor) {
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
            std::cout << "Nieprawidlowy wybor!\n";
            return rozmiarTablicy();
    }
}

typDanych wybierzDane() {
    int wybor;

    std::cout << "Podaj typ danych:\n";
    std::cout << "1. Liczby calkowite\n";
    std::cout << "2. Liczby rzeczywiste\n";
    std::cin >> wybor;

    switch (wybor) {
        case 1: return typDanych::calkowite;
        case 2: return typDanych::rzeczywiste;
        default:
            std::cout << "Nieprawidlowy wybor!\n";
            return wybierzDane();
    }
}

algorytmSortowania wybierzAlgorytm() {
    int wybor;

    std::cout << "Wybierz algorytm sortowania:\n";
    std::cout << "1. Bubble\n";
    std::cout << "2. Selection\n";
    std::cout << "3. Insertion\n";
    std::cout << "4. Merge\n";
    std::cout << "5. Counting (tylko liczby calkowite)\n";
    std::cout << "6. Heap\n";
    std::cout << "7. Bucket\n";
    std::cout << "8. Quicksort\n";
    std::cin >> wybor;

    switch (wybor) {
        case 1: return algorytmSortowania::bubble;
        case 2: return algorytmSortowania::selection;
        case 3: return algorytmSortowania::insertion;
        case 4: return algorytmSortowania::merge;
        case 5: return algorytmSortowania::counting;
        case 6: return algorytmSortowania::heap;
        case 7: return algorytmSortowania::bucket;
        case 8: return algorytmSortowania::quicksort;
        default:
            std::cout << "Nieprawidlowy wybor!\n";
            return wybierzAlgorytm();
    }
}

template <typename T>
class tablica {
    std::vector<T> dane;

public:
    tablica(int rozmiar) : dane(rozmiar) {
        std::generate(dane.begin(), dane.end(), std::rand);
    }

    void bubbleSort() {
        clock_t start = clock();
        for (int i = 0; i < dane.size() - 1; i++) {
            for (int j = 0; j < dane.size() - i - 1; j++) {
                if (dane[j] > dane[j + 1]) {
                    std::swap(dane[j], dane[j + 1]);
                }
            }
        }
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
    }

    void selectionSort() {
    clock_t start = clock();
        for (int i = 0; i < dane.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < dane.size(); j++) {
                if (dane[j] < dane[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(dane[i], dane[minIndex]);
        }
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
    }

    void insertionSort() {
    clock_t start = clock();
        for (int i = 1; i < dane.size(); i++) {
            T key = dane[i];
            int j = i - 1;
            while (j >= 0 && dane[j] > key) {
                dane[j + 1] = dane[j];
                j--;
            }
            dane[j + 1] = key;
        }
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
    }

    void mergeSort() {
    clock_t start = clock();
        mergeSortHelper(0, dane.size() - 1);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
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
        int lewaRozmiar = mid - low + 1;
        int prawaRozmiar = high - mid;

        std::vector<T> lewy(lewaRozmiar);
        std::vector<T> prawy(prawaRozmiar);

        for (int i = 0; i < lewaRozmiar; i++) {
            lewy[i] = dane[low + i];
        }

        for (int j = 0; j < prawaRozmiar; j++) {
            prawy[j] = dane[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = low;

        while (i < lewaRozmiar && j < prawaRozmiar) {
            if (lewy[i] <= prawy[j]) {
                dane[k] = lewy[i];
                i++;
            } else {
                dane[k] = prawy[j];
                j++;
            }
            k++;
        }

        while (i < lewaRozmiar) {
            dane[k] = lewy[i];
            i++;
            k++;
        }

        while (j < prawaRozmiar) {
            dane[k] = prawy[j];
            j++;
            k++;
        }
    }

    void countingSort() {
        if (std::is_same<T, int>::value) {
            clock_t start = clock();
            int maxElement = *std::max_element(dane.begin(), dane.end());
            int minElement = *std::min_element(dane.begin(), dane.end());
            int range = maxElement - minElement + 1;

            std::vector<int> count(range, 0);
            std::vector<T> output(dane.size());

            for (int i = 0; i < dane.size(); i++) {
                count[dane[i] - minElement]++;
            }

            for (int i = 1; i < range; i++) {
                count[i] += count[i - 1];
            }

            for (int i = dane.size() - 1; i >= 0; i--) {
                output[count[dane[i] - minElement] - 1] = dane[i];
                count[dane[i] - minElement]--;
            }

            for (int i = 0; i < dane.size(); i++) {
                dane[i] = output[i];
            }

            clock_t end = clock();
            double duration = double(end - start) / CLOCKS_PER_SEC;
            std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
        } else {
            std::cout << "Sortowanie przez zliczanie wymaga liczb calkowitych.\n";
        }
    }

    void heapSort() {
    clock_t start = clock();
        for (int i = dane.size() / 2 - 1; i >= 0; i--) {
            heapify(dane.size(), i);
        }

        // Extract elements from the heap one by one
        for (int i = dane.size() - 1; i > 0; i--) {
            std::swap(dane[0], dane[i]);
            heapify(i, 0);
        }
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
    }

    void heapify(int n, int i) {
        int maksimum = i;
        int lewy = 2 * i + 1;
        int prawy = 2 * i + 2;

        if (lewy < n && dane[lewy] > dane[maksimum]) {
            maksimum = lewy;
        }

        if (prawy < n && dane[prawy] > dane[maksimum]) {
            maksimum = prawy;
        }

        if (maksimum != i) {
            std::swap(dane[i], dane[maksimum]);
            heapify(n, maksimum);
        }
    }

    void bucketSort() {
    clock_t start = clock();
        // Implement bucket sort
        std::vector<std::vector<T>> buckets(dane.size());
        
        // Place elements into buckets
        for (int i = 0; i < dane.size(); i++) {
            int bucketIndex = dane.size() * dane[i];
            buckets[bucketIndex].push_back(dane[i]);
        }
        
        // Sort each bucket
        for (int i = 0; i < dane.size(); i++) {
            std::sort(buckets[i].begin(), buckets[i].end());
        }
        
        // Concatenate the sorted buckets
        int index = 0;
        for (int i = 0; i < dane.size(); i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                dane[index++] = buckets[i][j];
            }
        }
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
    }

    void quickSort() {
    clock_t start = clock();
        quickSortHelper(0, dane.size() - 1);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas sortowania (w sekundach): " << duration << std::endl;
    }

    void quickSortHelper(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);
            quickSortHelper(low, pivotIndex - 1);
            quickSortHelper(pivotIndex + 1, high);
        }
    }

    int partition(int low, int high) {
        T pivot = dane[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (dane[j] < pivot) {
                i++;
                std::swap(dane[i], dane[j]);
            }
        }

        std::swap(dane[i + 1], dane[high]);
        return i + 1;
    }

    void sort(algorytmSortowania algorithm) {
        switch (algorithm) {
            case algorytmSortowania::bubble: bubbleSort(); break;
            case algorytmSortowania::selection: selectionSort(); break;
            case algorytmSortowania::insertion: insertionSort(); break;
            case algorytmSortowania::merge: mergeSort(); break;
            case algorytmSortowania::counting: countingSort(); break;
            case algorytmSortowania::heap: heapSort(); break;
            case algorytmSortowania::bucket: bucketSort(); break;
            case algorytmSortowania::quicksort: quickSort(); break;
        }
    }
};

int main() {
    typDanych typ;
    algorytmSortowania algorytm;
    int rozmiar;

    while (true) {
        typ = wybierzDane();

        rozmiar = rozmiarTablicy();

        algorytm = wybierzAlgorytm();

        if (typ == typDanych::calkowite) {
            tablica<int> tab(rozmiar);
            tab.sort(algorytm);
        } else {
            tablica<double> tab(rozmiar);
            tab.sort(algorytm);
        }

        std::cout << "Czy chcesz kontynuowac? (T/N): ";
        char wybor;
        std::cin >> wybor;
        if (wybor != 'T' && wybor != 't') {
            break;
        }
    }

    return 0;
}
