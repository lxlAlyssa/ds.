#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e3 + 10;

struct Edge {
    int u, v, w;
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

int fa[MAXN];

int Find(int x) {
    if (fa[x] != x) {
        fa[x] = Find(fa[x]);
    }
    return fa[x];
}

void Union(int x, int y) {
    fa[Find(x)] = Find(y);
}

int Prim(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int cnt = 0, ans = 0;
    for (auto e : edges) {
        if (Find(e.u) != Find(e.v)) {
            Union(e.u, e.v);
            ans += e.w;
            ++cnt;
            if (cnt == n - 1) break;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }
    cout << Prim(n, edges) << endl;
    return 0;
}


//²âÊÔ°¸Àý£º
//
//ÊäÈë£º
//
//6 9
//1 2 3
//1 3 4
//2 3 1
//2 4 7
//3 4 1
//3 5 6
//4 5 8
//4 6 2
//5 6 5
//Êä³ö£º
//
//13









