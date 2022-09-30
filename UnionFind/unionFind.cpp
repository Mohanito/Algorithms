#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
public:
    vector<int> uf;
    UnionFind(int n) : uf(n) {
        iota(uf.begin(), uf.end(), 0);
    }

    int root(int i) {
        while (i != uf[i])
            i = uf[i];
        return i;
    }

    void connect(int a, int b) {
        uf[root(a)] = root(b);
    }

    bool connected(int a, int b) {
        return root(a) == root(b);
    }
};

// Example: Number of Connected Components in an Undirected Graph
int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    for (auto& edge : edges) {
        // A naive solution with duplicate root-finding
        if (!uf.connected(edge[0], edge[1])) {
            uf.connect(edge[0], edge[1]);
            n--;
        }
    }
    return n;
}
