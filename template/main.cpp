// Krishnam Maheshwari
// 2212147

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;

#define MOD 1000000007
#define _MOD 998244353
#define INF 1000000000000000000
#define EPS 0.000000001
#define PI 3.141592653589793238462
#define newl "\n"
#define set_bits __builtin_popcountll
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define print(x) do { [](const auto& v) { for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " \n"[i + 1 == v.size()]; }(x); } while (0)

void solve(int tc) 
{
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        solve(i);
    }
    return 0;
}