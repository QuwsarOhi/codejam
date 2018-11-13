// LightOJ
// 1145 - Dice (I)
// Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define MAX                 6
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD                 100000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

// Loop Reduction
// + Double DP state

ll dp[2][15010];

ll BottomUP(int n, int k, int s) {
    memset(dp, 0, sizeof dp);

    bool present = 0, past = 1;
    dp[present][0] = 1;
    ll sum = 0;

    for(int Throw = 1; Throw <= n; ++Throw) {
        present ^= 1, past ^= 1;
        sum = 0;
        for(int tot = 0; tot <= s; ++tot) {
            // sum contains cumulative value of past k positions
            //cout << Throw << " " << tot << " " << sum << endl;

            dp[present][tot] = sum;
            dp[present][tot] %= MOD;
            sum -= tot-k >= 0 ?dp[past][tot-k]:0;
            sum = (sum + MOD)%MOD;
            sum += dp[past][tot];
            sum = (sum + MOD)%MOD;
        }
    }
    return dp[present][s]%MOD;
}

int main() {
    //fileWrite("out");
    int t, n, k, s;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &n, &k, &s);
        printf("Case %d: %lld\n", Case, BottomUP(n, k, s));
    }
    return 0;
}