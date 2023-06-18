#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define fr(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define pb push_back
#define en endl
#define sz(x) ((int)(x).size())
#define inf 0x3f3f3f3f
#define Margi                        \
   ios_base::sync_with_stdio(false); \
   cin.tie(0);                       \
   cout.tie(0);                      \
   cin.tie(nullptr);

const int mod = 1e9+7;

// int query(int i, int j){
//    int q;
//    cout<<"? "<<i<<" "<<j<<en;
//    cin>>q;
//    return q;
// }

void solve()
{
   ll n,m;
   cin>>n>>m;
   vvi grid(n+1, vi(m+1));
   fr(i,1,n+1){
      fr(j,1,m+1){
         cin>>grid[i][j];
      }
   }
   vvi dp(n+1, vi(m+1));
   dp[1][1] = grid[1][1];
   fr(i,1,n+1){
      fr(j,1,m+1){
         if(i>1 && j>1){
            dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            // cout<<dp[i][j]<<" ";
         }
         if(i==1 && j>1){
            dp[i][j] = grid[i][j] + dp[i][j-1];
            // cout<<dp[i][j]<<" ";
         }
         if(j==1 && i>1){
            dp[i][j] = grid[i][j] + dp[i-1][j];
            // cout<<dp[i][j]<<" ";
         }
      }
      cout<<en;
   }
   cout<<en<<dp[n][m]<<en;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   Margi;
   int tt = 1;
   // cin >> tt;
   while (tt--)
   {
      // cout<<"tc: "<<tt<<en;
      solve();
   };
   return 0;
}
