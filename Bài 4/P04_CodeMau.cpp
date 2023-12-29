#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    // divide the array into two halves and count the inversions in each half
    int leftInversions = solve(a, left, mid);
    int rightInversions = solve(a, mid + 1, right);

    // count the number of inversions that span across the two halves of the array
    int crossInversions = 0;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        // if a[i] > a[j], increase the number of inversions by the number of elements remaining in the left half
        if (a[i] > a[j]) {
            crossInversions += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }

    // merge the two halves of the array in sorted order
    vector<int> temp(right - left + 1);
    int k = 0;
    i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (i = left; i <= right; i++) {
        a[i] = temp[i - left];
    }

    // return the total number of inversions
    return leftInversions + rightInversions + crossInversions;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solve(a, 0, n - 1) << "\n";
}