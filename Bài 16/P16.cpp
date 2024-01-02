/**
 *    author:    hungt1
 *    created:   30-12-2022   20:53:49
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 0;
    vector<int> sub(n, 0);
    function<void(int, int)> dfs = [&](int u, int p){
        sub[u] = 1;
        for (int v : adj[u]){
            if (v == p) continue;
            dfs(v, u);
            sub[u] += sub[v];
        }
        cout << u+1 << " " << sub[u] << endl;
        ans += 1LL * sub[u] * (n - sub[u]);
    };

    dfs(0, -1);
    cout << ans << '\n';
    return 0;
}