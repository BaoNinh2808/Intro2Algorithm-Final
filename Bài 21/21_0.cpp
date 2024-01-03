#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
int n, m;
int comp;
vector<int> root;
void initDSU() {
  root.resize(n + 1);
  comp = n;
  for (int i = 1; i <= n; ++i) {
    root[i] = i;
  }
}
int findRoot(int u) {
  if (root[u] == u)
    return u;

  return root[u] = findRoot(root[u]);
}
int merge(int u, int v) {
  int uu = findRoot(u);
  int vv = findRoot(v);

  if (uu != vv) {
    --comp;
    root[uu] = vv;

    return 1;
  } else {
    return 0;
  }
}

struct Edge {
  int u, v, w;

  Edge(int u, int v, int w) : u(u), v(v), w(w){};
};
class Partition;
vector<Edge> edges;

class Partition {
  int start = 0, mstValue = 0;
  vector<int> included, excluded;
  vector<int> mst;

public:
  int getMstValue() { return mstValue; }
  vector<int> getMst() {
    vector<int> ans = included;
    for (int id : mst) {
      ans.push_back(id);
    }
    return ans;
  }
  vector<Partition> generatePartition() {
    vector<Partition> ans;
    Partition cur;
    cur.included = included;
    cur.excluded = excluded;
    cur.excluded.emplace_back();
    for (int id : mst) {
      cur.excluded.back() = id;
      cur.start = id + 1;
      ans.push_back(cur);
      ans.back().findMst();
      if (ans.back().getMstValue() == -1) {
        ans.pop_back();
      }
      cur.included.push_back(id);
    }

    return ans;
  }

  void findMst() {
    initDSU();

    mstValue = 0;
    mst.clear();
    for (int id : included) {
      Edge e = edges[id];
      merge(e.u, e.v);

      mstValue += e.w;
    }

    for (int i = start; i < edges.size(); ++i) {
      Edge e = edges[i];

      if (merge(e.u, e.v)) {
        mstValue += e.w;
        mst.push_back(i);
      }
    }
    if (comp != 1) {
      mstValue = -1;
      mst.clear();
    }
  }
};
vector<Partition> partitions;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    q;

vector<int> msts;
void findKthMst() {
  Partition cur = partitions[q.top().second];
  msts.push_back(q.top().second);
  q.pop();

  vector<Partition> newPartitions = cur.generatePartition();

  for (auto &p : newPartitions) {
    partitions.push_back(p);
    q.push({partitions.back().getMstValue(), (int)partitions.size() - 1});
  }
}

void solve() {
  int k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

  partitions.emplace_back();
  partitions.back().findMst();

  q.push({partitions.back().getMstValue(), (int)partitions.size() - 1});

  for (int i = 0; i < k; ++i) {
    findKthMst();
  }

  for (auto par : msts) {
    vector<int> mst = partitions[par].getMst();
    cout << "===========\n";
    cout << partitions[par].getMstValue() << "\n";
    for (auto id : mst) {
      cout << edges[id].u << " " << edges[id].v << " " << edges[id].w << endl;
    }
  }
}
