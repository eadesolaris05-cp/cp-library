/**
  *    author:    eadesolaris05
  *    created:   03/01/2022 18:30:27
**/
#include <bits/stdc++.h>
using namespace std;

/*
 * Description: Basic class for simple graph problems
 *
 * Example Usage:
 * - https://codeforces.com/contest/1611/submission/137275158
*/

class graph {
    public:
        int N;
        vector<bool> visited;
        vector<vector<int>> edges;
        vector<int> distance;

        graph (int _n) : N(_n) {
            visited = vector<bool>(N);
            distance = vector<int>(N);
            edges = vector<vector<int>>(N);
        }

        void read(int num_edges, bool undirected) {
            for (int i = 0; i < num_edges; i++) {
                int u, v;
                cin >> u >> v;
                // --u; --v;
                edges[u].push_back(v);
                if (undirected) edges[v].push_back(u);
            }
        }

        bool detect_cycle() {
            fill(visited.begin(), visited.end(), false);

            vector<int> pre(N);
            vector<int> post(N);
            int t = 0;

            function<void(int)> Dfs = [&] (int source) {
                visited[source] = true;
                pre[source] = t;
                t++;
                for (auto u : edges[source]) {
                    if (!visited[u]) {
                        Dfs(u);
                    }
                }
                post[source] = t;
                t++;
            };

            for (int i = 0; i < N; i++) {
                if (visited[i] == false) {
                    Dfs(i);
                }
            }

            for (int u = 0; u < N; u++) {
                for (auto v : edges[u]) {
                    if (post[v] > post[u] && pre[v] < pre[u]) {
                        return true;
                    }
                }
            }
            return false;
        }
     
};

void solve() {

    int n, m;
    cin >> n >> m;

    graph g = graph(n);
    g.read(m, false);

    bool b = g.detect_cycle();
    if (b) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    
    while (T--) solve();

    return 0;
}
