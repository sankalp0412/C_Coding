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
    int N;
    cin >> N;
    vector<pii> guests(N); 
    for(int i = 0; i < N;i++) {
        cin >> guests[i].first;
    }
    for(int i = 0; i < N;i++) {
        cin >> guests[i].second;
    }


    sort(guests.begin(),guests.end(), [](const pii &g1, const pii &g2) {
        return g1.first < g2.first;
    });


    int ans = 0;

    unordered_map<int,int> current; //guestid - deptTime

    for(int i = 0; i < N; i++) {

        auto guest = guests[i];
        
        int at = guest.first;
        int dt = guest.second;

        //remove all the guests whose dt is less or equst to curent guest dt
        vector<int> to_erase;
        for(auto &x: current) {
            if(x.second <= at)
                to_erase.push_back(x.first);
        }
        for(int key : to_erase) {
            current.erase(key);
        }

        //this guest has now checked in 
        current[i] = dt;

        ans = max(ans, (int)current.size());
    }
    cout << ans << endl;
}
int main() {
	init_code();
   	int TC = 1; cin>>TC;
   	while(TC--) solve();

   	return 0;
}