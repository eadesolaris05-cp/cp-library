/* 
 * Description: Disjoint union (or Union-Find) by size
 * 
 * Source:
 * - nealwu, dsu.cpp
 * - tourist, dsu.cpp  
 * - cp algorithms, disjoint set union
 *
 * Example Usage:
 * - https://atcoder.jp/contests/abc229/submissions/27622178
 *
*/

class dsu {
    public:
        vector<int> parent;
        vector<int> size;
        int components;
    
        dsu(int _n) : components(_n) {
            parent.resize(components );
            size.resize(components, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int v) {
            if (v == parent[v]) {
                return v;
            }
            parent[v] = find(parent[v]);
            return parent[v];
        }

        bool unite(int x, int y) {
            x = find(x);
            y = find(y);

            if (x == y)
                return false;
            
            if (size[x] < size[y])
                swap(x, y);

            parent[y] = x;
            size[x] += size[y];
            components--;
            return true;
        }

        int find_size(int x) {
            x = find(x);
            return size[x];
        }
};

/* 
 * Description: Kruskal's algorithm for finding the minimum spanning tree.
 * 
 * Source:
 * - nealwu, kruskal.cpp
 *
 * Example Usage:
 * - https://atcoder.jp/contests/abc235/tasks/abc235_e
 *
*/

template<typename T>
class Kruskal {
    public:
        struct edge {
            int a, b;
            T weight;
            int index  = -1;
            bool in_tree = false;

            edge() {}

            edge(int _a, int _b, T _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index)  {}

            bool operator < (const edge &other) const {
                return weight < other.weight;
            }
        };

        dsu d;
        vector<edge> edges;
        vector<bool> original_in_tree;

        Kruskal(int _n) : d(dsu(_n)) {}

        // this function does not subtract the edges, must be handled in the reading of the numbers.
        void add_edge(int a, int b, T weight, int type) {
            edges.emplace_back(a, b, weight, edges.size());
            original_in_tree.push_back(false);
        }

        T find_mst() {
            sort(edges.begin(), edges.end());
            T total = 0;
            for (edge &e : edges) {
                if (d.unite(e.a, e.b)) {
                    total += e.weight;
                    e.in_tree = true;
                    original_in_tree[e.index] = true;
                }
            }
            return total;
        }
};

using kruskal = Kruskal<long long>;

