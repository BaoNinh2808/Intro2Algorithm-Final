#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

typedef vector<int> DSU;

void init_DSU(DSU &parent, int size) {
    parent.resize(size);
    for (int i = 0; i < parent.size(); ++i)
        parent[i] = i;
}

int findRoot_DSU(DSU &parent, int u) {
    return (parent[u] == u) ? u : (parent[u] = findRoot_DSU(parent, parent[u]));
}

bool union_DSU(DSU &parent, int u, int v) {
    int root_u = findRoot_DSU(parent, u);
    int root_v = findRoot_DSU(parent, v);

    if (root_u != root_v) {
        parent[root_u] = root_v;
        return true;
    }
    return false;
}

// struct Partition {
//     int start, mstValue;
//     vector<int> included, excluded;
//     vector<int> mst;

//     Partition() : start(0), mstValue(0) {}

//     int getMstValue() {
//         return mstValue;
//     }

//     vector<int> getMst() {
//         vector<int> res = included;
//         for (int i = 0; i < mst.size(); ++i)
//             res.push_back(mst[i]);
//         return res;
//     }

//     vector<Partition> generatePartition() {

//     }

//     void findMst() {

//     }
// };

bool hasSmallerWeight(Edge a, Edge b) {
    return a.w < b.w;
}

void solve(vector<Edge> &edges, int n, int m, int k) {
    sort(edges.begin(), edges.end(), hasSmallerWeight);

    PQ pq;
    Partition firstMST(n, &edges);
    firstMST.findMst();
    vector<Partition> partitions;
    vector<int> res;

    // res.push_back(0);`
    partitions.push_back(firstMST);
    pq.push(make_pair(partitions[0].getMstValue(), 0));

    for (int i = 0; i < k; ++i)
        getSmallestSpanningTree(pq, partitions, res);
}

struct Partition {
    int start, mstValue, n;
    vector<Edge> *edges;
    vector<int> included;
    vector<int> mstEdges_notFromIncluded;

    Partition(int n, vector<Edge>* edges) {
        start = 0;
        mstValue = 0;
        this->edges = edges;
    }

    int getMstValue() {
        return mstValue;
    }

    vector<int> getMst() {
        vector<int> res = included;
        for (int i = 0; i < mstEdges_notFromIncluded.size(); ++i)
            res.push_back(mstEdges_notFromIncluded[i]);
        return res;
    }

    void findMst() {
        vector<int> parent;
        init_DSU(parent, n);

        mstValue = 0;
        mstEdges_notFromIncluded.clear();

        for (int i = 0; i < included.size(); ++i) {
            Edge e = (*edges)[i];
            union_DSU(parent, e.u, e.v);
            mstValue += e.w;
        }

        for (int i = start; i < edges->size(); ++i) {
            Edge e = (*edges)[i];
            if (union_DSU(parent, e.u, e.v)) {
                mstValue += e.w;
                mstEdges_notFromIncluded.push_back(i);
            }
        }

        if (included.size() + mstEdges_notFromIncluded.size() != n - 1) {
            mstValue = -1;
            mstEdges_notFromIncluded.clear();
        }
    }

    vector<Partition> generatePartition() {
        vector<Partition> res;
        Partition cur(n, edges);

        cur.included = this->included;
        
        for (int i = 0; i < mstEdges_notFromIncluded.size(); ++i) {
            cur.start = mstEdges_notFromIncluded[i] + 1;
            res.push_back(cur);
            res.back().findMst();
            if (res.back().getMstValue() == -1)
                res.pop_back();
            cur.included.push_back(mstEdges_notFromIncluded[i]);
        }

        return res;
    }
};

void getSmallestSpanningTree(PQ &pq, vector<Partition> &partitions, vector<int> &res) {
    Partition cur = partitions[pq.top().second];
    res.push_back(pq.top().second);
    pq.pop();

    vector<Partition> newPartitions = cur.generatePartition();
    for (int i = 0; i < newPartitions.size(); ++i) {
        Partition p = newPartitions[i];
        partitions.push_back(p);
        pq.push(make_pair(p.getMstValue(), partitions.size() - 1));
    }
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    int k, m, n;
    int u, v, w;
    vector<Edge> edges;

    reader >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        reader >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    reader.close();
    writer.close();
    return 0;
}