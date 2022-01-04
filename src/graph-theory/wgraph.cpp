template<typename T>
class wgraph {
    public:
        int N;
        vector<vector<pair<int, T>> edges;

        wgraph (int _n) : N(_n) {
            edges = vector<vector<pair<int, T>>>(N);
        }

        void read(int num_edges, bool undirected) {
            for (int i = 0; i < num_edges; i++) {
                int u, v;
                T cost;
                cin >> u >> v >> cost;
                --u; --v;
                edges[u].emplace_back(v, cost);
                if (undirected) {
                    edges[v].emplace_back(u, cost);
                }
            }
        }
};

using graph = wgraph<long long>;
