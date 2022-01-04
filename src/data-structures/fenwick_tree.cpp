/*
 * Description: Fenwick Tree using 0 based indexing
 * Source:
 * - CP algorithms
 *
 * Verification:
 * - https://judge.yosupo.jp/submission/72036
 *
 * Example Usage:
 * - https://atcoder.jp/contests/abc221/submissions/28270353
*/   

template<typename T>
class fenwick_tree {
    public:
        int n;
        vector<T> tree;

        fenwick_tree(int _n) : n(_n) {
            tree.assign(n, 0);
        }

        fenwick_tree(vector<T> a) : fenwick_tree((int) a.size()) {
            for (int i = 0; i < (int) a.size(); i++) {
                add(i, a[i]);
            }
        }

        T sum(int idx) {
            T ret = 0;
            for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
                ret += tree[idx];
            return ret;
        }

        T sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }

        T get(int idx) {
            return sum(idx, idx-1);
        }

        void add(int idx, T delta) {
            for (; idx < n; idx = idx | (idx + 1))
                tree[idx] += delta;
        }
};

using bit = fenwick_tree<long long>;

