const int n = 1e6;
vector<int> primes(n+1,1);

void seive(){
   primes[0] = 0;
   primes[1] = 0;
   for(int i=2; i<=n; i++){
      if(!primes[i]){
         continue;
      }
      for(int j=2*i; j<=n; j+=i){
         primes[j] = 0;
      }
   }
}
