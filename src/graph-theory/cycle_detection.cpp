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
