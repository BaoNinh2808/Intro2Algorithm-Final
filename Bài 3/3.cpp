#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

inline int abs(int x) {
    return (x >= 0) ? x : -x;
}

int findLowerBound(vector<pair<int, int>> &a, int k) {
    int left = 0;
    int right = a.size();
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (k <= a[mid].first) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }    

    return left;
}

pair<int, int> solve(vector<pair<int, int>> &A, vector<pair<int, int>> &B) {
    vector<pair<int, int>> *p, *q;

    if (A.size() > B.size()) {
        p = &A;
        q = &B;
    }
    else {
        p = &B;
        q = &A;
    }

    sort(q->begin(), q->end());

    int min_ = INT_MAX;
    pair<int, int> res;

    for (int i = 0; i < p->size(); ++i) {
        int j = findLowerBound(*q, - (*p)[i].first);
        if (j > 0) {
            if (min_ > abs((*p)[i].first + (*q)[j - 1].first)) {
                min_ = abs((*p)[i].first + (*q)[j - 1].first);
                res = make_pair(i, (*q)[j - 1].second);
            }
        }
        if (min_ > abs((*p)[i].first + (*q)[j].first)) {
            min_ = abs((*p)[i].first + (*q)[j].first);
            res = make_pair(i, (*q)[j].second);
        }
    }

    // If A is the longer
    if (p == &A) {
        return make_pair(res.first + 1, res.second + 1); // Since the OUTPUT is 1-indexed
    }
    // If B is the longer, then we need to reverse the order of (i, j)
    return make_pair(res.second + 1, res.first + 1);
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    int m, n, x;
    vector<pair<int, int>> A, B;

    reader >> m >> n;
    for (int i = 0; i < m; ++i) {
        reader >> x;
        A.push_back(make_pair(x, i));
    }
    for (int j = 0; j < n; ++j) {
        reader >> x;
        B.push_back(make_pair(x, j));
    }

    pair<int, int> res = solve(A, B);

    writer << res.first << " " << res.second << "\n";

    reader.close();
    writer.close();
    return 0;
}