/*
 * Description: Basic class for simple graph problems
 *
 * Example Usage:
 *
*/

class Bfs {
    public:
        graph& g;
        vector<int> parent;
        vector<int> dist;
        vector<bool> visited;
        int inf = (1e9) + 5;

        Bfs (graph& _g) : g(_g) {}

        void shortest_path(int source) {
            parent.assign(g.n, -1);
            dist.assign(g.n, -1);
            visited.assign(g.n, false);

            dist[source] = 0;
            visited[source] = true;
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int u = q.top();
                q.pop();
                for (auto v : g.edges[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                    }
                }
            }
        }

        void restore_path(int s, int t) {
            vector<int path;
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
