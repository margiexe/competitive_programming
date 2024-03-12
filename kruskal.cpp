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

class DSU
{
public:
   vector<int> parent, rank;
   DSU(int n)
   {
      parent.resize(n);
      rank.resize(n);
      for (int i = 0; i < n; i++)
      {
         parent[i] = i;
         rank[i] = 0;
      }
   }
   int find(int a)
   {
      if (parent[a] == a)
         return a;
      return parent[a] = find(parent[a]);
   }
   void unionset(int a, int b)
   {
      a = find(a);
      b = find(b);
      if (a == b)
      {
         return;
      }
      if (rank[a] > rank[b])
         swap(rank[a], rank[b]);
      parent[a] = b;
      rank[b]++;
   }
};

void kruskal(vector<pair<ll, ii>> &adj, int n)
{
   DSU ds(n);
   sort(adj.begin(), adj.end());
   int mst_cost = 0;
   for (auto x : adj)
   {
      int n1 = x.second.first;
      int n2 = x.second.second;
      int weight = x.first;
      if (ds.find(n1) != ds.find(n2))
      {
         mst_cost += weight;
         ds.unionset(n1, n2);
      }
      debug(n1,n2,weight);
   }
   cout << mst_cost << endl;
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
   cin >> t;
   while (t--)
   {
      int n,m;
      cin >> n>>m;
      vector<ii> a(m);
      int w;
      vector<pair<ll, ii>> adj;
      for (int i = 0; i < m; i++)
      {
         cin >>a[i].first >> a[i].second>>w;
         adj.push_back({w, {a[i].first-1, a[i].second-1}});
         
      }
      debug(adj);
      kruskal(adj,n);
   }
   return 0;
}
