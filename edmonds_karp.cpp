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

class max_flow
{
private:
   int V;
   vector<iii> EL;
   vector<vi> AL;
   vi d, last;
   vector<ii> p;

public:
   max_flow(int initialV) : V(initialV)
   {
      EL.clear();
      AL.assign(V, vi());
   }
   // in case of bidirectional set directed = false
   void add_edge(ll u, ll v, ll w, bool directed = true)
   {
      if (u == v)
      {
         return; // no self loops
      }
      EL.push_back({v, w, 0}); // u --> v, capicity w, flow 0
      AL[u].push_back(EL.size() - 1);
      EL.push_back({u, directed ? 0 : w, 0}); // back edge
      AL[v].push_back(EL.size() - 1);         // remember this edge
   }
   bool BFS(ll s, ll t)
   {
      d.assign(V, -1);
      d[s] = 0;
      p.assign(V, {-1, -1});
      queue<ll> q({s});
      while (!q.empty())
      {
         ll u = q.front();
         q.pop();
         if (u == t)
            break;
         for (auto &idx : AL[u])
         {
            auto &[v, cap, flow] = EL[idx];
            if ((cap - flow > 0) && (d[v] == -1)) // positive residual + unexplored
            {
               d[v] = d[u] + 1;
               q.push(v);
               p[v] = {u, idx}; // parent info
            }
         }
      }
      return d[t] != -1;
   }
   ll send_one_flow(ll s, ll t, ll f = INF) // send one flow from s-->t
   {
      if (s == t)
         return f; // bottleneck edge f found
      auto &[u, idx] = p[t];
      auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);

      ll pushed = send_one_flow(s, u, min(f, cap - flow));
      flow += pushed;

      auto &rflow = get<2>(EL[idx ^ 1]); // to get partner edge
      rflow -= pushed;

      return pushed;
   }
   ll edmonds_karp(ll s, ll t)
   {
      ll maxf = 0;
      while (BFS(s, t))
      {
         ll f = send_one_flow(s, t);
         if (f == 0)
            break;
         maxf += f;
      }
      return maxf;
   }
};

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   ios_base::sync_with_stdio(false);
   
   ll e;
   cin>>e;
   max_flow maxf(1000);
   for(int i=0; i<e; i++){
      int x,y;
      cin>>x>>y;
      int w;
      cin>>w;
      maxf.add_edge(x, y, w);
   }
   cout<<maxf.edmonds_karp(0,5)<<endl;
   // 0-->source 5-->destination
   return 0;
}
