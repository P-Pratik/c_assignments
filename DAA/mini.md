# Code
```cpp
#include <iostream>
#include <pthread.h>
#include <time.h>
#include <chrono>

#define MAX 1000000
#define THREAD_MAX 8

using namespace std;

int a[MAX];
int part = 0;
pthread_mutex_t merge_mutex = PTHREAD_MUTEX_INITIALIZER;

void merge(int low, int mid, int high) {
    int* left = new int[mid - low + 1];
    int* right = new int[high - mid];
    int n1 = mid - low + 1, n2 = high - mid, i, j;

    for (i = 0; i < n1; i++)
        left[i] = a[i + low];

    for (i = 0; i < n2; i++)
        right[i] = a[i + mid + 1];

    int k = low;
    i = j = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1) {
        a[k++] = left[i++];
    }

    while (j < n2) {
        a[k++] = right[j++];
    }
}

void merge_sort(int low, int high) {
    int mid = low + (high - low) / 2;
    if (low < high) {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

void* multi_threaded_merge_sort(void* arg) {
    int thread_part = part++;
    int low = thread_part * (MAX / THREAD_MAX);
    int high = (thread_part + 1) * (MAX / THREAD_MAX) - 1;

    merge_sort(low, high);

    // Lock access to merge
    pthread_mutex_lock(&merge_mutex);
    merge(0, (low + high) / 2, high);
    pthread_mutex_unlock(&merge_mutex);
}

int main() {
    for (int i = 0; i < MAX; i++)
        a[i] = rand() % 100;

    // clock_t t1, t2;
    chrono::time_point<chrono::high_resolution_clock> t1, t2;

    pthread_t threads[THREAD_MAX];

    cout << "Threads Used -> " << THREAD_MAX << endl << endl;
    cout << "Sample Size -> " << MAX << endl << endl;

    t1 = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_create(&threads[i], NULL, multi_threaded_merge_sort, (void*)NULL);

    for (int i = 0; i < THREAD_MAX; i++)
        pthread_join(threads[i], NULL);

    t2 = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "Multi-threaded Merge Sort Time taken: " << duration.count() << " seconds" << endl;

    // Reset array
    for (int i = 0; i < MAX; i++)
        a[i] = rand() % 100;

    t1 = chrono::high_resolution_clock::now();
    merge_sort(0, MAX - 1);
    t2 = chrono::high_resolution_clock::now();

    chrono::duration<double> duration2 = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "Single-threaded Merge Sort Time taken: " << duration2.count() << " seconds" << endl;

    double performance_boost;

    performance_boost = ((duration2.count() - duration.count())/duration2.count()) * 100;

    cout << "\nPerformance boost: " << performance_boost << "%" << endl;

    return 0;
}
```
