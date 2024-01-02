#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> bar;

int solve(vector<int> &h) {
    int res = 0;
    stack<bar> s;

    s.push(make_pair(h[0], 0));
    int i = 1;
    while (i < h.size()) {
        if (h[i] > h[i - 1]) {
            bar leftWall, bottom;
            bottom = s.top(); s.pop();
            if (!s.empty()) {
                leftWall = s.top(); s.pop();
                while (1) {
                    res += (i - leftWall.second - 1) * (leftWall.first - bottom.first);
                    if (s.empty() || s.top().first > h[i])
                        break;
                    bottom = leftWall;
                    leftWall = s.top(); s.pop();
                }
                if (!s.empty()) {
                    res += (i - s.top().second - 1) * (h[i] - leftWall.first);
                }
            }
        }
        s.push(make_pair(h[i], i));
        ++i;
    }
    return res;
}


int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    int n, x;
    vector<int> h;

    reader >> n;
    for (int i = 0; i < n; ++i) {
        reader >> x;
        h.push_back(x);
    }

    writer << solve(h);

    reader.close();
    writer.close();
    return 0;
}