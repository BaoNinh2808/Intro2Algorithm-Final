#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> Point;

Point p0;

float sin_p0(Point a) {
    return (a.second - p0.second) / sqrt(
        (a.first - p0.first) * (a.first - p0.first)
        + (a.second - p0.second) * (a.second - p0.second)
    );
}

float cmp_sin_p0(pair<Point, int> a, pair<Point, int> b) {
    return sin_p0(a.first) < sin_p0(b.first);
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    int n, x, y;
    vector<pair<Point, int>> p;

    reader >> n;
    for (int i = 0; i < n; ++i) {
        reader >> x >> y;
        p.push_back(make_pair(make_pair(x, y), i));
    }

    sort(p.begin(), p.end());
    p0 = p[0].first;

    sort(p.begin() + 1, p.end(), cmp_sin_p0);

    writer << p[0].second << " " << p[p.size() / 2].second << "\n";

    reader.close();
    writer.close();
    return 0;
}