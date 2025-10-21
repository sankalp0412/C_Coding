#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Macros
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back
#define printyes cout << "YES" << endl;
#define printno cout << "NO" << endl;


void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
void solve() {
    int D,d,P,Q;
    cin >> D >> d>> P >> Q;
    ll ans = D * ((2*P + (D - 1)* Q)) / 2;

    cout << ans << endl;
}
int main() {
	init_code();
   	int TC = 1; cin>>TC;
   	while(TC--) solve();

   	return 0;
}