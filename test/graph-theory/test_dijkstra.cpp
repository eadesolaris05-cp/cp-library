/**
  *    author:    eadesolaris05
  *    created:   12/01/2022 12:29:39
**/
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class wgraph {
    public:
        struct edge {
            int to = -1;
            T weight = 0;

            edge(int _to, T _weight) : to(_to), weight(_weight) {}
        };
    
        int N;
        vector<vector<edge>> adj;

        wgraph (int _n) : N(_n) {
            adj = vector<vector<edge>>(N);
        }

        void add(int from, int to, T weight) {
            adj[from].emplace_back(to, weight);
        }

        void read(int num_edges, bool undirected) {
            for (int i = 0; i < num_edges; i++) {
                int u, v;
                T cost;
                cin >> u >> v >> cost;
                // --u; --v;
                add(u, v, cost);
                if (undirected) {
                    add(v, u, cost);
                }
            }
        }
};

using graph = wgraph<long long>;

template<typename T>
class Dijkstra {
    public:
        wgraph<T>& g;
        vector<int> parent;
        vector<T> dist;
        T inf = numeric_limits<T>::max();

        Dijkstra (wgraph<T>& _g) : g(_g) {}

        struct state {
            T dist;
            int node; 
            
            state(T _dist, int _node) : dist(_dist), node(_node) {}

            bool operator< (const state &other) const {
                return dist > other.dist;
            }
        };

        void relax(priority_queue<state> &pq, int from, int to, T weight) {
            if (dist[from] + weight < dist[to]) {
                dist[to] = dist[from] + weight;
                parent[to] = from;
                pq.emplace(dist[from] + weight, to);
            }
        }

        void shortest_path(int source) {
            parent.assign(g.N, -1);
            dist.assign(g.N, inf);
            priority_queue<state> pq;

            pq.emplace(0, source);
            dist[source] = 0;

            while (!pq.empty()) {
                state top = pq.top();
                pq.pop();

                if (top.dist > dist[top.node]) 
                    continue;

                for (auto e : g.adj[top.node]) {
                    relax(pq, top.node, e.to, e.weight);
                }
            }
        }

        vector<int> restore_path(int s, int t) {
            vector<int> path;
            if (dist[t] == inf)
                return path;

            int v = t;
            while (v != s) {
                path.push_back(v);
                v = parent[v];
            }
            path.push_back(s);
            reverse(path.begin(), path.end());
            return path;
        }
};

using dijkstra = Dijkstra<long long>;

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    graph g = graph(n);
    g.read(m, false);

    dijkstra d = dijkstra(g);
    d.shortest_path(s);
    
    vector<int> path = d.restore_path(s, t);
    if ((int) path.size() == 0) {
        cout << -1 << endl;
    } else {
        int l = (int) path.size() - 1;
        cout << d.dist[t] << " " << l << endl;
        for (int i = 1; i < l + 1; i++) {
            cout << path[i-1] << " " << path[i] << endl;
        }
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
