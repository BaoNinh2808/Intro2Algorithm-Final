#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool solve(string &s, string &p) {
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    for (int j = 2; j < n + 1; j += 2)
        if (p[j - 1] == '*' && dp[0][j - 2])
            dp[0][j] = true;

    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                if ((p[j - 1]) == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    if (p[j - 1] == '*')
                        if (p[j - 2] != '.' && p[j - 2] != s[i - 1])
                            dp[i][j] = dp[i][j - 2];
                        else
                            dp[i][j] = (dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j]);

        }
    }

    return dp[m][n];
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    string s, p;
    getline(reader, s);
    getline(reader, p);

    writer << solve(s, p) << "\n";

    reader.close();
    writer.close();
    return 0;
}