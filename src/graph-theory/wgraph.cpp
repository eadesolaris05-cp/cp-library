/*
 * Description: Basic class for simple graph problems
 *
 * Example Usage:
 * - https://atcoder.jp/contests/abc191/submissions/28485164 
*/

template<typename T>
class wgraph {
    public:
        struct edge {
            int to = -1;
            T weight = 1;

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
                --u; --v;
                add(u, v, cost);
                if (undirected) {
                    add(v, u, cost);
                }
            }
        }
};

using graph = wgraph<long long>;
