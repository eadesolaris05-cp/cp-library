/* 
 * Description: Coordinate Compression
 * 
 * Source:
 * - https://atcoder.jp/contests/abc221/editorial/2732 (atcoder's implementation of coordinate compression) 
 *
*/

template<typename T>
int compress(vector<T>& v) {
    std::map<T, int> mem;
    for (auto p : v)
        mem[p]++;
    int sz = 0;
    for (auto &p: mem) p.second = sz++; 
    for (auto &p: v) p = mem[p];
    return sz;
} 
