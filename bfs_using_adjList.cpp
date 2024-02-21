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

void bfs_using_adjList(int s, int V, vector<vpii> AL)
{

   vi dist(V+1, inf); dist[s] = 0;
   queue<int> q; 
   q.push(s);
   p.assign(V+1,-1);

   int layer = -1;

   while(!q.empty()){
      int u = q.front();
      q.pop();
      if(dist[u] != layer){
         cout<<"layer : "<<dist[u]<<endl;
      }
      layer = dist[u];
      cout<<u <<" : ";
      for(auto &[v,w] : AL[u]){
         if(dist[v]==inf){
            dist[v] = dist[u]+1;
            p[v] = u;
            q.push(v);
            cout<<v<<" ";
         }
      }
      cout<<endl;
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
      cin>>V;                                         //no. of vertices
      vector<vpii> AL(V+1, vpii());                     //adj list
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

      bfs_using_adjList(s,V,AL);                                //s is the start point from
   }                                              //where you want to start

   return 0;
}
