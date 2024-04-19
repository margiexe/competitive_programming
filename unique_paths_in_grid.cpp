#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> dp(n + 1, vector<int>(m + 1));
   dp[0][0] = 1;
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= m; j++)
      {
         if (i == 0 || j == 0)
         {
            dp[i][j] = 1;
            continue;
         }
         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
   }
   cout << dp[n][m];
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   ios_base::sync_with_stdio(false);

   int t = 1;
   // cin >> t;

   while (t--)
   {
      solve();
   }

   return 0;
}
