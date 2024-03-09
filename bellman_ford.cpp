#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef tuple<ll, ll, ll> iii;
const ll INF = 1e16;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

bool bellman_ford(vector<iii> &EL, ll n, ll s)
{
   vll dist(n, INF);
   vll pred(n, -1);
   dist[s] = 0;
   for (ll i = 0; i < n - 1; i++)
   {
      for (auto [u, v, w] : EL)
      {
         if (dist[v] > dist[u] + w)
         {
            dist[v] = dist[u] + w;
            pred[v] = u;
         }
      }
   }
   for (auto [u, v, w] : EL)
   {
      if (dist[v] > dist[u] + w)
      {
         return false;
      }
   }
   return true;
}

void solve()
{
   ll n, m;
   cin >> n >> m;
   ll u, v, w;
   vector<iii> EL(m);
   for (ll i = 0; i < m; i++)
   {
      cin >> u >> v >> w;
      EL[i] = tie(u, v, w);
   }
   if(bellman_ford(EL,n,0)){
      cout<<"possible"<<endl;
      return;
   }
   cout<<"not possible"<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   ios_base::sync_with_stdio(false);
   ll t = 1;
   cin >> t;
   while (t--)
   {
      solve();
   }
   return 0;
}
