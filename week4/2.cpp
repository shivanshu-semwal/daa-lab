#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int start, int end, int &comp, int &swap) {
    int pivot = arr[end]; // end element is pivot
    int i = start - 1;    // right postiton of pivot
    for (int j = start; j < end; j++) {
        if (++comp && arr[j] < pivot) {
            i++;
            swap++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    if (i + 1 != end) {
        swap++;
        int temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
    }
    return i + 1;
}

// random pivot
int partition_r(vector<int> &arr, int l, int r, int &comp, int &swap) {
    srand(time(NULL));
    int random = l + rand() % (r - l);
    swap++;
    int temp = arr[random];
    arr[random] = arr[r];
    arr[r] = temp;

    return partition(arr, l, r, comp, swap);
}

/* quick sort algorithm */

void quick_sort(vector<int> &arr, int start, int end, int &comp, int &swap) {
    if (start < end) {
        int pivot = partition_r(arr, start, end, comp, swap);
        quick_sort(arr, start, pivot - 1, comp, swap);
        quick_sort(arr, pivot + 1, end, comp, swap);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int comparisions = 0, swaps = 0;
        quick_sort(arr, 0, arr.size() - 1, comparisions, swaps);
        for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
        cout << "\n";
        cout << "comparisions: " << comparisions << "\n";
        cout << "swaps: " << swaps;
        cout << "\n";
    }

    return 0;
}