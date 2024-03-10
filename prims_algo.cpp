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

ll prims_algo(vector<vii> &AL, ll n)
{
   priority_queue<ii, vector<ii>, greater<ii>> pq;   
   //vector is used to mantain heap structure

   vector<bool> taken(n, 0);
   taken[0] = 1;

   for (auto &[v, w] : AL[0])
   {
      pq.push({w, v});
   }
   ll mst_cost = 0, num_taken = 0;
   while(!pq.empty()){
      ll curr_node = pq.top().second;
      ll weight = pq.top().first;

      if(taken[curr_node]) continue;

      pq.pop();
      taken[curr_node] = 1;
      mst_cost += weight;
      for(auto &[node,w]:AL[curr_node]){
         if(!taken[node]){
            pq.push({w,node});
         }

         num_taken++;
         if(num_taken==n-1) break;
      }
   }
   return mst_cost;
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
      ll n;
      cin >> n;
      vector<vii> AL(n + 1, vii());
      for (ll i = 0; i < n; i++)
      {
         ll degree;
         cin >> degree;
         while(degree--){
            ll node_to_connect,weight;
            cin>>node_to_connect>>weight;
            node_to_connect--;
            AL[i].push_back({node_to_connect,weight});
         }
      }
      cout<<prims_algo(AL,n)<<endl;
   }
   return 0;
}
