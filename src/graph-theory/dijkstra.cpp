/*
 * Description: Dijkstra's algorithm with priority queue
 * Source:
 * - CLRS
 * - neal wu, dijsktra.cpp
 *
 * Verification:
 * - https://judge.yosupo.jp/submission/73949
 *
 * Example Usage:
 * - https://atcoder.jp/contests/abc191/submissions/28485164 
*/   

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
