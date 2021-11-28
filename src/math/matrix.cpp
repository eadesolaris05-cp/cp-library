/*
 * Description: Product and Binary exponentiation on square matrices
 * Source: 
 * - ecnerwala modnum.hpp
 *
 * To Do:
 * - Update matrix so it takes a template and non square matrices
 * - Add basic matrix operations  
 *
 * Example Usage:
 * - https://codeforces.com/contest/450/submission/136375909 
 */


template<typename T>
class matrix {
    public:
        int N;
        vector<vector<T>> data;

        matrix(int _n) : N(_n) {
            data = vector<vector<T>>(N, vector<T>(N, 0)); 
            for (int i = 0; i < N; i++) { data[i][i] = 1; } 
        }

        matrix(int _n, vector<vector<T>> _v) : N(_n), data(_v) {}

        friend std::ostream& operator << (std::ostream& out, const matrix& M) { 
            for (int i = 0; i < M.N; i++) {
                for (int j = 0; j < M.N; j++) {
                    out << M.data[i][j] << " ";
                }
                out << endl;
            }
            return out;
        };

        matrix& operator *= (const matrix B) {
            matrix A(this->N, this->data);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    this->data[i][j] = 0;
                    for (int k = 0; k < N; k++) {
                        data[i][j] += (A.data[i][k] * B.data[k][j]) % MOD;
                    }
                }
            }
            return *this;
        };

        matrix pow (long long b) {
            assert(b >= 0);
            matrix r(N); matrix A(this->N, this->data);
            while (b) { if (b & 1) r *= A; b >>= 1; A *= A; } return r;
        }

        friend matrix operator * (const matrix& A, const matrix& B) { return matrix(A.N, A.data) *= B; }

};

using Matrix = matrix<mint>;

