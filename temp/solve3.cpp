#include <bits/stdc++.h>
using namespace std;
#define MAX                 250000
typedef vector<int> vi;
typedef vector<long long>vl;
typedef long long ll;

struct node {
    ll val;
    node *lft, *rht;
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        val = v;
        L = lft;
        R = rht;
    }
};

node *presis[MAX];
vi G[MAX];
int parent[MAX], sparse[MAX][20], level[MAX], val[MAX];
map<ll, ll>Map, ReMap;


node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->lft = x->lft;
        tmp->rht = x->rht;
        tmp->val = x->val;
    }
    return tmp;
}

void update(node *pos, int l, int r, int idx, int val) {
    if(l == r) {
        pos->val += 1;
        return;
    }
    
    int mid = (l+r)>>1;
    
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        update(pos->lft, l, mid, idx, val);
    }
    else {
        pos->rht = nCopy(pos->rht);
        update(pos->rht, mid+1, r, idx, val);
    }
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
}


int query(node *lca0, node *lca, node *u, node *v, int l, int r, int k) {
    if(l == r)
        return l;
    
    lca0->lft = nCopy(lca0->lft);
    lca0->rht = nCopy(lca0->rht);
    lca->lft = nCopy(lca->lft);
    lca->rht = nCopy(lca->rht);
    u->lft = nCopy(u->lft);
    u->rht = nCopy(u->rht);
    v->lft = nCopy(v->lft);
    v->rht = nCopy(v->rht);
    
    int mid = (l+r)>>1;
    int Count = u->lft->val + v->lft->val - lca->lft->val - lca0->lft->val;
    
    if(Count >= k)
        return query(lca0->lft, lca->lft, u->lft, v->lft, l, mid, k);
    else
        return query(lca0->rht, lca->rht, u->rht, v->rht, mid+1, r, k-Count);
}


void dfs(int u, int prnt, int lvl, int V) {
    // For Sparse Table
    level[u] = lvl;
    parent[u] = prnt;
    
    // Segment Tree
    if(prnt != -1)
        presis[u] = nCopy(presis[prnt]);
    update(presis[u], 1, V, Map[val[u]], 1);
    
    for(auto v : G[u])
        if(parent[u] != v)
            dfs(v, u, lvl+1, V);
}


void LCAinit(int V) {
    memset(sparse, -1, sizeof sparse);
    
    for(int u = 1; u <= V; ++u)             // node u's 2^0 parent
        sparse[u][0] = parent[u];
    
    int v;
    for(int p = 1; (1<<p) <= V; ++p)
        for(int u = 1; u <= V; ++u)
            if((v = sparse[u][p-1]) != -1)      // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}


int LCA(int u, int v) {
    if(level[u] > level[v])     // v is deeper
        swap(u, v);
    
    int p = ceil(log2(level[v]));
    
    // Pull up v to same level as u
    for(int i = p ; i >= 0; --i)
        if(level[v] - (1LL<<i) >= level[u])
            v = sparse[v][i];
    
    // if u WAS the parent
    if(u == v)
        return u;
    
    // Pull up u and v together while LCA not found
    for(int i = p; i >= 0; --i)
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is for being on safe side
            u = sparse[u][i], v = sparse[v][i];
    
    return parent[u];
}


int main() {
    //freopen("in", "r", stdin);
    int V, u, v, q, ans, k, LCAnode;

    scanf("%d %d", &V, &q);
    
    for(int i = 1; i <= V; ++i) {
        cin >> val[i];
        Map[val[i]];
    }
    
    int idx = 0;
    for(auto it = Map.begin(); it != Map.end(); ++it) {
        it->second = ++idx;
        ReMap[idx] = it->first;
    }
    
    for(int i = 1; i < V; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    presis[1] = nCopy(presis[1]);
    dfs(1, -1, 0, V);
    LCAinit(V);
    
    node *dummy = new node();
    node *lca, *lca0;
    while(q--) {
        scanf("%d%d%d", &u, &v, &k);
        LCAnode = LCA(u, v);
        lca = presis[LCAnode];
        
        lca0 = sparse[LCAnode][0] == -1 ? dummy:presis[sparse[LCAnode][0]];
        ans = query(lca0, lca, presis[u], presis[v], 1, idx, k);
        printf("%lld\n", ReMap[ans]);
    }
    
    return 0;
}
