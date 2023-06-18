const int mod = 1e9 + 7;

ll fact(ll n, ll r){
    ll ans=1;
    fr(i,1,min(r,n-r)+1){
        ans = (ans * (n-i+1))/i;
        ans %= mod;
    }
    return ans;
}
