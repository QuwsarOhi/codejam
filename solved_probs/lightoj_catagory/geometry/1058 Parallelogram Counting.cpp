// LightOJ
// http://lightoj.com/volume_usersubmissions.php
// 1058 - Parallelogram Counting

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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


int main() {
    int t, ans, x, y, n;
    vii v, line;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        ans = 0;
        
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            v.pb(mp(x, y));
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                x = (v[i].fi + v[j].fi);
                y = (v[i].se + v[j].se);
                line.pb(mp(x, y));
            }
        }
        
        int cnt = 0;
        sort(line.begin(), line.end());
        for(int i = 1; i < SIZE(line); ++i) {
            if(line[i] == line[i-1])
                ++cnt;
            else {
                ans += (cnt*(cnt+1))/2;
                cnt = 0;
            }
        }
        
        v.clear();
        line.clear();
        pf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
