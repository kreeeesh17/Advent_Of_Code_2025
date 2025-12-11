/**************************************
11/12
Author - kreeeesh_17
Created : 17:16:50
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
map<string, vector<string>> mp;
map<string, ll> dp;

ll rec(string node, set<string> &vis)
{
    if (node == "out")
    {
        return 1;
    }
    if (dp.find(node) != dp.end())
    {
        return dp[node];
    }
    if (vis.count(node))
    {
        return 0;
    }
    vis.insert(node);
    ll count = 0;
    auto it = mp.find(node);
    if (it != mp.end())
    {
        for (string &x : it->second)
        {
            count += rec(x, vis);
        }
    }
    vis.erase(node);
    return dp[node] = count;
}

void solve()
{
    string s;
    while (getline(cin, s))
    {
        if (s.empty())
        {
            continue;
        }
        ll pos = s.find(':');
        string u = s.substr(0, pos);
        while (!u.empty() && isspace(u.back()))
        {
            u.pop_back();
        }
        ll st = 0;
        while (st < u.size() && isspace(u[st]))
        {
            st++;
        }
        u = u.substr(st);
        string v = s.substr(pos + 1);
        stringstream ss(v);
        string node;
        while (ss >> node)
        {
            mp[u].push_back(node);
        }
    }
    set<string> vis;
    cout << rec("you", vis) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("AdventOfCodeDay11P1_input.txt","r",stdin);
    //   freopen("AdventOfCodeDay11P1_output.txt","w",stdout);
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