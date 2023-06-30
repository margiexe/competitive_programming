//0-1 knapsack recursive solution
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
   if(n==0 || w==0){
      return 0;
   }
   if(wt[n-1]>w){
      return knapsack(w,wt,val,n-1);
   }
   ans = max(knapsack(w,wt,val,n-1),knapsack(w - wt[n-1],wt,val,n-1)+val[n-1]);
   return ans;
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
   while (tt--)
   {
      solve();
   };
   return 0;
}
