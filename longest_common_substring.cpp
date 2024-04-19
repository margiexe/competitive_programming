#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif



void solve()
{
   string s1,s2;
   cin>>s1>>s2;
   int n =s1.size();
   int m = s2.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1));
   dp[n][m] = 0;
   for(int i=n-1; i>=0; i--){
      for(int j=m-1; j>=0; j--){
         if(s1[i]==s2[j]){
            dp[i][j] = 1+dp[i+1][j+1];
         }
         else{
            dp[i][j] = 0;
         }
      }
   }
   // print max element of dp
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
