#include <bits/stdc++.h>
#define db(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define MOD 1000000007
#define FOR(i, n) for(ll i = 0; i < n; i++)
using namespace std;
const long long INF = 3*1e18;

ll divisor_count (ll num) {  
  ll ans = 0;
  for (ll i = 1; i * i <= num; ++i) {
    if (num % i == 0) {
      if (i * i < num) ans += 2;
      else ++ans;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);    
  cin.tie(0);
  ll i = 1, ans = 0;
  while (1) {
    ll num =  (i * (i + 1))/2;
    ll count = divisor_count(num);
    db(i) db(count)
    if (count > 500) {
      ans = i;
      break;
    }
    ++i;
  }
  cout << ans << "\n";
}
