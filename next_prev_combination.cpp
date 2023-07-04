void solve()
{
   vi a = {1,6,8,9};
   do{
      int num = a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
      int mod = num%7;
      cout<<num<<" "<<mod<<en;
   }while(next_permutation(a.begin(),a.end()));
}
// lexicographically bigger next string
// prev_permutation for smaller string
