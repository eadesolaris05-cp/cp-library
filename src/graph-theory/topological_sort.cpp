/* 
 * Description: Two approaches to topological sort (DFS and BFS)
 * 
 * Source:
 * - USACO GUIDE, topological sort
 * - cp-algorithms, topological sort
 * 
 * Example Usage:
 * - https://atcoder.jp/contests/abc223/submissions/28320877
 *
*/

vector<int> topological_sort(graph& g) {
    /*
     * Classic Topological Sort
    */
    fill(g.visited.begin(), g.visited.end(), false);
    vector<int> pre(g.N);
    vector<int> post(g.N);
    vector<int> ord;
    int t = 0;
 
    function<void(int)> Dfs = [&] (int source) {
        g.visited[source] = true;
        pre[source] = t;
        t++;
        for (auto u : g.edges[source]) {
            if (!g.visited[u]) {
                Dfs(u);
            }
        }
        post[source] = t;
        t++;
        ord.push_back(source);
    };
 
    for (int i = 0; i < g.N; i--) {
        if (visited[i] == false) {
            Dfs(i);
        }
    }
 
    for (int u = 0; u < g.N; u++) {
        for (auto v : g.edges[u]) {
            if (post[v] > post[u] && pre[v] < pre[u]) {
                return {};
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
} 

vector<int> kahns_algorithm(graph& g) {
    /*
     * Kahn's algorithm which returns lexicographically smallest topological sort
    */ 
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> ord;
    g.visited.assign(false, 0);

    for (int i = 0; i < g.N; i++) {
        if (g.indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ord.push_back(u);
        g.visited[u] = true;
        for (auto v : g.edges[u]) {
            if (!g.visited[v]) {
                g.indegree[v]--;
                if (g.indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    // if the ordering has size = N then we have a valid topological sort.
    if ((int) ord.size() == g.N) {
        return ord;
    }
    return {};
}
