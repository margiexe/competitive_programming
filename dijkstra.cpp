#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

const ll INF = 1e16;

void dijkstra(int s, int n, vector<vii> &AL)
{
   vll dist(n, INF);
   dist[s] = 0;
   set<ii> pq;
   vll pred(n);
   for (int u = 0; u < n; u++)
   {
      pq.insert({dist[u], u});
   }
   while (!pq.empty())
   {
      auto [d, u] = *pq.begin(); // capturing smallest element
      pq.erase(pq.begin());      // removing it
      for (auto &[v, w] : AL[u])
      {
         if (dist[u] + w >= dist[v])
         {
            continue; // edge is not tense so skip
         }
         // if edge is tense then relax it
         pq.erase({dist[v], v});  // erase old pair
         dist[v] = dist[u] + w;   // relax operation
         pred[v] = u;             // update predecessor
         pq.insert({dist[v], v}); // enqueue better pair
      }
   }
   if (dist[n - 1] != INF)
   {
      vll path;
      ll current = n - 1;
      while (current != 0)
      {
         path.push_back(current);
         current = pred[current];
      }
      path.push_back(current);
      reverse(path.begin(), path.end());
      for (int i = 0; i < path.size(); i++)
      {
         cout << path[i] + 1 << " ";
      }
      cout << endl;
   }
   else
   {
      cout << "-1" << endl;
   }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   ios_base::sync_with_stdio(false);

   ll n, m;
   cin >> n >> m;
   vector<vii> AL(n);
   ll u, v, w;
   for (int i = 0; i < m; i++)
   {
      cin >> u >> v >> w;
      --u, --v;
      AL[u].push_back({v, w});
      AL[v].push_back({u, w});
   }
   dijkstra(0, n, AL);
   return 0;
}
