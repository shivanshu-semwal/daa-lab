#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// partition form the end
int partitionSmall(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

/* quick select algortihm for smallest k */
int quickSelectSmall(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        // partition the array around the last element
        int index = partitionSmall(arr, l, r);

        // if index is same as k
        if (index - l == k - 1) {
            return arr[index];
        }

        // if index is more, recurse for left, else right
        if (index - l > k - 1) {
            return quickSelectSmall(arr, l, index - 1, k);
        } else {
            return quickSelectSmall(arr, index + 1, r, k - index + l - 1);
        }
    }
    return INT_MIN;
}

// partition form the end
int partitionLarge(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] >= x) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;

    return i;
}

/* quick select algorithm for largest k */
int quickSelectLarge(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        // partition the array around the last element
        int index = partitionLarge(arr, l, r);

        // if index is same as k
        if (index - l == k - 1) {
            return arr[index];
        }

        // if index is more, recurse for left, else right
        if (index - l > k - 1) {
            return quickSelectLarge(arr, l, index - 1, k);
        } else {
            return quickSelectLarge(arr, index + 1, r, k - index + l - 1);
        }
    }
    return INT_MAX;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k;
        cin >> k;

        // find the kth smallest and largest element
        if (k > n) {
            cerr << "Invalid input\n";
            continue;
        }
        int smallk = quickSelectSmall(arr, 0, n - 1, k);
        int largek = quickSelectLarge(arr, 0, n - 1, k);
        cout << smallk << "\n"
             << largek << "\n";
    }
    return 0;
}