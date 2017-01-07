
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ld long double
#define ui unsigned int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> >
#define vvi vector<vector<int> >
#define N 2147483648
#define EPS 1e-9
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int co_efficient[1000];

long long horner(int x, int n)
{
    long long ans = co_efficient[0];
    //printf("%d ", co_efficient[0]);
    int lim = min(x, n);
    for(int i = 1; i < lim; i++) {
        //printf("%d ", co_efficient[i]);
        ans = ans*x + co_efficient[i];
    }
    //printf("\n");
    return ans;
}

int main()
{
    char a[10000];
    int x, n, c, i;
    while(scanf(" %d", &x) != EOF) {
        scanf(" %[^\n]", a);
        stringstream ss;
        ss << a;
        n = 0;
        i = x+1;
        memset(co_efficient, 0, sizeof(co_efficient));
        while(ss >> c) {
            co_efficient[n] = c * i;
            i--;
            n++;
        }
        printf("%lld\n", horner(x, x));
    }
    return 0;
}
