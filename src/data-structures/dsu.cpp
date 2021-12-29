/* 
 * Disjoint union (or Union-Find) by size
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
};
