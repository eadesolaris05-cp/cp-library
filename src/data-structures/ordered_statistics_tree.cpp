/* 
 * Disjoint union (or Union-Find) by size
 * 
 * Source:
 * - encnerwala, order_statistic.hpp
 * 
 * Example Usage:
 * - https://atcoder.jp/contests/abc231/submissions/27977774
 *
*/

#include<bits/extc++.h>

template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

// Supports
//  auto iterator = order_statistic_set().find_by_order(idx); // (0-indexed)
//  int num_strictly_smaller = order_statistic_set().order_of_key(key);

using oset = order_statistic_set<pair<int, int>, std::less<pair<int, int>>>;


