#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define MAX_DIGIT 9
#define UNSOLVED -1
#define NO_SOLUTION -2

using namespace std;

inline int mod(int x, int n) {
    return ((x % n) + n) % n;
}

int solve(int n) {
    vector<int> dp(n, -1);

    for (int i = 0, power = 1; i < MAX_DIGIT; ++i, power = (power * 10) % n) {
        for (int j = 0; j < n; ++j) {
            if (dp[j] >= 0 && dp[(j + power) % n] == -1 && dp[j] != i) {
                dp[(j + power) % n] = i;
            }
        }
        if (dp[power] == -1) {
            dp[power] = i;
        }
        if (dp[0] != -1) {
            break;
        }
    }

    int res = 0;
    int j = 0;
    do {
        res += (int)pow(10, dp[j]);
        j = mod(j - (int)pow(10, dp[j]), n);
    } while (j != 0);
    return res;
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    int n;
    reader >> n;

    cout << solve(n);

    reader.close();
    writer.close();
    return 0;
}