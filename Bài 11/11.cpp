#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solve(vector<pair<int, int>> &a, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    dp[0][0] = 0;
    if (m >= 1) dp[1][0] = a[0].first;
    if (n >= 1) dp[0][1] = a[0].second;

    for (int i = 0; i < a.size(); ++i) {
        pair<int, int> p = a[i];
        for (int j = 0; j <= min(m, i); ++j) {
            for (int k = 0; k <= min(n, i - j); ++k) {
                if (j > 0) {
                    dp[j][k] = max(dp[j - 1][k] + p.first, dp[j][k]);
                }
                else if (k > 0) {
                    dp[j][k] = max(dp[j][k - 1] + p.second, dp[j][k]);
                }
            }
        }

        // cout << "--- " << i << endl;
        // for (int i = 0; i <= m; ++i) {
        //     for (int j = 0; j <= n; ++j) {
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << "\n";
        // }
    }

    return dp[m][n];
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    int k, m, n, x, y;
    vector<pair<int, int>> a;
    reader >> k >> m >> n;

    for (int i = 0; i < k; ++i) {
        reader >> x >> y;
        a.push_back(make_pair(x, y));
    }

    writer << solve(a, m, n);

    reader.close();
    writer.close();
    return 0;
}