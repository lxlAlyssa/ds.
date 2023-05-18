#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;

vector<pair<int, int>> g[MAXN];
int dis[MAXN];
bool vis[MAXN];

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, s });
    dis[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto e : g[u]) {
            int v = e.first;
            int w = e.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({ dis[v], v });
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    for (int i = 1; i <= n; ++i) dis[i] = MAXN;
    Dijkstra(s);
    cout << dis[t] << endl;
    return 0;
}

//²âÊÔ°¸Àý£º
//
//ÊäÈë£º/*
//
//4 4 1 4
//1 2 1
//2 3 2
//3 4 1
//1 4 5
//
//Êä³ö£º
//4*/

