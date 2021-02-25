//最大公約数
ll gcd(ll x, ll y){
  if(x%y==0){
    return y;
  }else{
    return(gcd(y,x%y));
  }
}
//最小公倍数
ll lcm(ll x, ll y){
  return x*y/gcd(x,y);
}

//2で何回われるか
int count_2(int x){
  int ans=0;
  while(x%2==0){
    x/=2;
    ans++;
  }
  return ans;
}
