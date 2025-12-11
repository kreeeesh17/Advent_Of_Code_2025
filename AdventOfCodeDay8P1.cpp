/**************************************
11/12
Author - kreeeesh_17
Created : 14:47:04
**************************************/

#include <bits/stdc++.h>
using namespace std;
#define f(i, n) for (ll i = 0; i < n; i++)
#define ll long long int
#define inf 1000000000
#define endl '\n'
#define g(i, m, n) for (ll i = m; i < n; i++)
#define vint vector<ll>
#define ia(a, n) \
    vint a(n);   \
    f(i, n) cin >> a[i];
#define asc(a) (a).begin(), (a).end()
#define desc(a) (a).rbegin(), (a).rend()
#define print(a)          \
    for (auto x : (a))    \
        cout << x << ' '; \
    cout << endl;
#define pb(x) push_back(x);
#define pii pair<ll, ll>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define debarr(a, n)            \
    cout << #a << " : ";        \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";    \
    cout << endl;
#define debmat(mat, row, col)         \
    cout << #mat << " :\n";           \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cout << mat[i][j] << " "; \
        cout << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS)
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cout << str << " : " << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cout << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b)
{
    cout << "[";
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cout << ", ";
        cout << *i;
    }
    cout << "]\n";
}
ll mod = 1e9 + 7;
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2)
        return a * power(a, b - 1) % mod;
    else
    {
        ll x = power(a, b / 2);
        return (x * x) % mod;
    }
}
ll inverse(ll x) { return power(x, mod - 2); }
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
/********************************************************************************************************************************************************************************************/
class UnionFind
{
public:
    ll n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(ll a)
    {
        n = set_size = a;
        parent = new ll[n + 1];
        rank = new ll[n + 1];
        g(i, 0, n + 1)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ll find(ll x)
    {
        if (x != parent[x])
        {
            return parent[x] = find(parent[x]);
        }
        return x;
    }
    void merge(ll x, ll y)
    {
        ll xroot = find(x);
        ll yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }
    void reset()
    {
        set_size = n;
        g(i, 1, n + 1)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ll size()
    {
        return set_size;
    }
    void print_par()
    {
        g(i, 1, n + 1)
        {
            cout << i << "->" << parent[i] << endl;
        }
    }
};

void solve()
{
    vint a, b, c;
    ll x, y, z;
    char c1, c2;
    while (cin >> x >> c1 >> y >> c2 >> z)
    {
        a.push_back(x);
        b.push_back(y);
        c.push_back(z);
    }
    ll n = a.size();
    vector<pair<ll, pair<ll, ll>>> edge;
    f(i, n)
    {
        g(j, i + 1, n)
        {
            ll dist = (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]) + (c[i] - c[j]) * (c[i] - c[j]);
            edge.push_back({dist, {i, j}});
        }
    }
    sort(asc(edge));
    UnionFind uf(n);
    f(i, min((ll)edge.size(), (ll)1000))
    {
        uf.merge(edge[i].second.first, edge[i].second.second);
    }
    map<ll, ll> mp;
    f(i, n)
    {
        mp[uf.find(i)]++;
    }
    vint sz;
    for (auto x : mp)
    {
        sz.push_back(x.second);
    }
    sort(asc(sz));
    ll count = 1;
    if (!sz.empty())
    {
        ll len = sz.size();
        f(i, min((ll)3, (ll)sz.size()))
        {
            count *= sz[len - 1 - i];
        }
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("AdventOfCodeDay8P1_input.txt","r",stdin);
    //   freopen("AdventOfCodeDay8P1_output.txt","w",stdout);
    // #endif
    ll t;
    t = 1;
    // cin >> t;
    g(i, 1, t + 1)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}