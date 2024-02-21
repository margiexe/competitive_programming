#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef tuple<int,int,int> tiii;
// const ll mod = 1e9 + 7;

const ll inf = 1e9;

// visualalgo.net
//  void solve()
//  {
//  }
vi p;                                                  //parent 
vector<vi> AM(2000, vi(2000));                         //adj matrix
vector<bool> vis;

void dfs(int u, vector<vpii> &AL)
{
   cout<<u<<" ";
   vis[u] = 1;
   for(auto &[v,w] : AL[u]){
      if(!vis[v]){
         dfs(v,AL);
      }
   }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios::sync_with_stdio(false);
   ll t = 1;
   // cin >> t;
   while (t--)
   {
      // solve();
      int V;
      cin>>V;                                           //no. of vertices
      vector<vpii> AL(V+1, vpii());                     //adj list
      vis.assign(V,0);
      for(int i=0; i<V; i++){
         for(int j=0; j<V; j++){
            cin>>AM[i][j];
         }
      }

      int s;
      bool ok = true;
      for(int i=1; i<=V; i++){
         int neighbours;
         // cout<<"enter number of neighbours : ";
         cin>>neighbours;
         while(neighbours--){
            int u,w;
            cin>>u>>w;                             //1 based indexing
            if(ok) s=u; ok=false;
            AL[i].push_back({u,w});
         }
      }

      int E;                                      //edges
      cin>>E;
      vector<tiii> EL(E);
      for(int i=0; i<E; i++){
         int u,v,w;
         EL[i] = tie(u,v,w);
      }
      s=1;
      dfs(s,AL);                                //s is the start point from
   }                                              //where you want to start

   return 0;
}
