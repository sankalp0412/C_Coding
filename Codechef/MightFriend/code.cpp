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
freopen("error.txt", "w", stderr); 
#endif
}
void solve() {
  int N , K;
  cin >> N >> K;
  priority_queue<int> motu; //max heap 
  priority_queue<int, vector<int>, greater<int>> tomu; //min heap - to win
  int curr;
  for(int i = 0; i < N; i++) {
    cin >> curr;
    if(i & 1) 
        tomu.push(curr); // log(n/2) TC
    else 
        motu.push(curr); // log(n/2) TC

        //so for N elemens O(N log N)
    
  }

  //i will try to swap the max valu from motu to the least value of tomu

  while(K-- && !motu.empty() && !tomu.empty()) {
    int topFromMotu = motu.top();
    int topFromTomu = tomu.top();

    if(topFromMotu <= topFromTomu) break; 

    motu.pop();  // O(log N)
    tomu.pop(); // O(log N)

    motu.push(topFromTomu); // O(log N)
    tomu.push(topFromMotu); // O(log N)
    //this will be K times so KlogN, and in the works case
    // K can be equal to N so N log N
}

  ll motuSum= 0, tomuSum  = 0;

  while(!motu.empty()) {
    motuSum += motu.top();
    motu.pop();
  }
  while(!tomu.empty()) {
    tomuSum += tomu.top();
    tomu.pop();
  }

if(tomuSum > motuSum) 
  cout << "YES" << endl;
else 
cout << "NO" << endl;

}
int main() {
	init_code();
   	int TC = 1; cin>>TC;
   	while(TC--) solve();

   	return 0;
}


/*

✅ Space Complexity: O(N)
Why?
You're storing elements in two heaps:

One max heap (motu)

One min heap (tomu)

Each heap stores about N/2 elements, so:

mathematica
Copy
Edit
Space = O(N/2) + O(N/2) = O(N)
✔️ Correct. Space complexity is O(N).



------------

Time Complexity: O(N log N)

Step 1: Reading and inserting into heaps — O(N log N)
for (int i = 0; i < N; i++) {
    cin >> curr;
    if(i & 1) tomu.push(curr);     // log(n/2)
    else motu.push(curr);          // log(n/2)
}
Each push takes O(log n) time in a heap. Total for N elements:

✅ O(N log N)


Step 2: K Swaps in the loop — O(K log N)
cpp
Copy
Edit
while (K-- && !motu.empty() && !tomu.empty()) {
    ...
    motu.pop();          // O(log N)
    tomu.pop();          // O(log N)
    motu.push(...);      // O(log N)
    tomu.push(...);      // O(log N)
}
Each iteration takes 4 × O(log N) operations = O(log N).

So K iterations ⇒ O(K log N)

⚠️ In the worst case, K can be up to N, so this becomes O(N log N)

Step 3: Sum calculation from heaps — O(N log N) worst-case
cpp
Copy
Edit
while (!motu.empty()) {
    motuSum += motu.top();
    motu.pop();           // log N
}
Each pop = O(log N) → done N/2 times
→ Total: O(N log N) again

Same applies to tomu.

✅ Final Time Complexity:
mathematica
Copy
Edit
O(N log N) + O(K log N) + O(N log N)
= O(N log N)
So both space and time complexities are O(N log N) in the worst case.

✅ Bonus: When is Time Complexity O(N)?
Only if:

K = 0

You're not doing any heap operations beyond insert once

But that’s rare. So:

❗ Your original claim of O(N) time complexity is not fully accurate.
✅ The correct answer is: O(N log N) time, O(N) space.

*/