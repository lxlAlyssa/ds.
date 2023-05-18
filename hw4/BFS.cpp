#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;

vector<int> g[MAXN];
bool vis[MAXN];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : g[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    BFS(s);
    return 0;
}

//
//≤‚ ‘∞∏¿˝£∫
//
// ‰»Î£∫
//```
//5 5 1
//1 2
//1 3
//2 4
//3 4
//4 5
//```
//
// ‰≥ˆ£∫
//```
//1 2 3 4 5
//```

