#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix(string &s) {
    vector<int> pref(s.length());

    pref[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        int j = pref[i - 1];
        while (j > 0 && s[i] != s[j])
            --j;
        if (s[i] == s[j])
            ++j;
        pref[i] = j;
    }

    return pref;
}


vector<int> solve(string &A, string &B) {
    vector<int> pref_B = prefix(B);
    vector<int> res;

    int j = 0;
    for (int i = 0; i < A.length(); ++i) {
        while (j > 0 && A[i] != B[j])
            j = pref_B[j - 1];
        if (A[i] == B[j])
            ++j;
        if (j == B.length())
            res.push_back(i - j + 1 + 1);
    }

    return res;
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    string A, B;
    getline(reader, A);
    getline(reader, B);

    vector<int> res = solve(A, B);

    for (int i = 0; i < res.size(); ++i)
        writer << res[i] << " ";

    reader.close();
    writer.close();
    return 0;
}