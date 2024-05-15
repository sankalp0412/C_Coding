typedef long double ld;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl> p3l;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back