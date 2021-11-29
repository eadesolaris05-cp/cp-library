/*
 * Description: Range Minimum Queries in O(1) time using Sparse Table
 * Source:
 * - CP algorithms
 * - KACTL RMQ
 *
 * Verification:
 * - https://judge.yosupo.jp/submission/68286
 *
 * Example Usage:
 * - https://codeforces.com/contest/1611/submission/137372470
*/   

template <typename T>
class sparse_table {
    public:
        vector<vector<T>> st;
        vector<T> log;
        int N;

        sparse_table(const vector<T>& v) : N((int) v.size()) {
            int sz = (int) v.size() + 1;
            int K = floor(log2(sz));

            // Precompute logs
            log = vector<T>(sz + 1);
            log[1] = 0;
            for (int i = 2; i < sz + 1; i++) {
                log[i] = log[i/2] + 1;
            }

            // Build Sparse Table
            st = vector<vector<T>>(sz, vector<T>(K + 1));
            for (int i = 0; i < N; i++) {
                st[i][0] = v[i];
            }
            for (int i = 1; i <= K; i++) {
                for (int j = 0; j + (1 << i) <= N; j++) {
                    st[j][i] = min(st[j][i-1], st[j + (1 << (i-1))][i-1]);
                }
            }
        }

        T query(int a, int b) {
            assert(a <= b);
            if (b >= N) b = N - 1;
            int j = log[b - a + 1];
            return min(st[a][j], st[b - (1 << j) + 1][j]);
        }
};

using stable = sparse_table<long long>;
