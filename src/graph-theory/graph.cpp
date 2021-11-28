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
                --u; --v;
                edges[u].push_back(v);
                if (undirected) edges[v].push_back(u);
            }
        }

        void dfs(int sourceVertex) {
            visited[sourceVertex] = true;
            for (auto u : edges[sourceVertex]) {
                if (!visited[u]) {
                    dfs(u);
                }
            }
        }

        void bfs(int sourceVertex) {
            fill(visited.begin(), visited.end(), false);
            queue<int> q;
            q.push(sourceVertex);
            while (!q.empty()) {
                int sourceVertex = q.front(); q.pop();
                for (auto u : edges[sourceVertex]) {
                    if (visited[u]) continue;
                    visited[u] = true;
                    distance[u] = distance[sourceVertex] + 1;
                    q.push(u);
                }
            }
        }
};
