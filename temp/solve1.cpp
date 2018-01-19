#include <bits/stdc++.h>
using namespace std;
#define MAX                 50
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
#define StrToInt(STR)       stoi(STR, nullptr)
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

int x, hr, Min;

void minusX() {
    Min -= x;
    if(Min < 0) {
        Min += 60;
        hr--;
        if(hr < 0) {
            hr = 23;
            //daypass++;
        }
    }
}

bool checkLuck(int v) {
    while(v > 0) {
        int t = v%10;
        if(t==7)
            return 1;
        v /=10;
    }
    return 0;
}

int main() {
    //fileRead("in");
    int cnt = 0;
    cin >> x;
    cin >> hr >> Min;
    
    do {
        if(checkLuck(hr) || checkLuck(Min)) {
            cout << cnt << endl;
            //cout << hr << " " << Min << endl;
            break;
        }
        ++cnt;
        minusX();
    }while(1);
    //main();
    return 0;
}
    
