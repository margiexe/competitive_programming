#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define en endl
#define sz(x) ((int)(x).size())
#define Margi                        \
   ios_base::sync_with_stdio(false); \
   cin.tie(0);                       \
   cout.tie(0);                      \
   cin.tie(nullptr);

int ans = INT_MIN;

int knapsack(int w, vi wt, vi val, int n){
   int dp[n+1][w+1];
   for(int i=0; i<=n; i++){
      for(int j=0; j<=w; j++){
         if(i==0 || j==0){
            dp[i][j] = 0;
            continue;
         }
         if(j-wt[i-1]<0){
            dp[i][j] = dp[i-1][j];
            continue;
         }
         dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
      }
   }
   return dp[n][w];
}

void solve()
{
   vi wt,val;
   wt = {5,4,6,3};
   val = {10,40,30,50};
   int w = 10;
   cout<<knapsack(w,wt,val,sz(val))<<en;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
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
