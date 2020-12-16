#include <bits/stdc++.h>
#define db(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define MOD 1000000007
#define FOR(i, n) for(ll i = 0; i < n; i++)
using namespace std;
const long long INF = 3*1e18;

ll get_length (ll num) {  
  ll ans = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
      ++ans;
    } else {
      num = (3 * num) + 1;
      ++ans;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);    
  cin.tie(0);
  ll ans = 0, num = 0;
  for (int i = 2; i <= 1000000; ++i) {
    ll count = get_length(i);
    if (count > ans) {
      ans = count;
      num = i;
    }
  }
  cout << num << "\n";
}
