
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
#define N 1000000000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

unsigned int divs[10010];
vi div_store;

void divisors(ull n)
{
    for(ull i = 1; i <= n; i++)
        for(ull j = i; j <= n; j+=i) {
            divs[j]++;
            if(divs[j] > mx_div) {
                mx_div = divs[j];
                div_store.clear();
                div_store.push(j);
            }
            else if(mx_div == divs[j])
                div_store.push(j);
        }
}

int main()
{
    ri t;
    sf("%d", &t);
    wh(t--) {
        sf("%lld %lld", &u, &l);

}
