/**************************************
10/12
Author - kreeeesh_17
Created : 16:10:24
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

void solve()
{
    vector<pair<ll, ll>> a;
    string s;
    while (getline(cin, s))
    {
        if (s.empty())
        {
            break;
        }
        ll pos = s.find('-');
        ll x = stoll(s.substr(0, pos));
        ll y = stoll(s.substr(pos + 1));
        a.push_back({x, y});
    }
    sort(asc(a));
    vector<pair<ll, ll>> b;
    b.push_back({a[0].first, a[0].second});
    ll n = a.size();
    g(i, 1, n)
    {
        if (a[i].first <= b.back().second + 1)
        {
            b.back().second = max(b.back().second, a[i].second);
        }
        else
        {
            b.push_back({a[i].first, a[i].second});
        }
    }
    ll count = 0;
    f(i, b.size())
    {
        count += (b[i].second - b[i].first + 1);
    }
    cout << count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("AdventOfCodeDay5P1_input.txt","r",stdin);
    //   freopen("AdventOfCodeDay5P1_output.txt","w",stdout);
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