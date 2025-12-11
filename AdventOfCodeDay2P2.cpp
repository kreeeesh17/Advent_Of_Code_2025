/**************************************
08/12
Author - kreeeesh_17
Created : 11:12:47
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

ll check(ll x)
{
    if (x == 0)
        return 1;
    ll d = 0;
    while (x > 0)
    {
        d++;
        x /= 10;
    }
    return d;
}

void solve()
{
    string a, s;
    while (cin >> s)
    {
        a += s;
    }

    vector<string> b;
    string curr;
    for (auto x : a)
    {
        if (x == ',')
        {
            if (!curr.empty())
            {
                b.push_back(curr);
                curr.clear();
            }
        }
        else
        {
            curr.push_back(x);
        }
    }
    if (!curr.empty())
    {
        b.push_back(curr);
    }

    vector<pair<ll, ll>> d;
    ll maxm1 = 0;
    for (auto &x : b)
    {
        if (x.empty())
            continue;
        auto idx = x.find('-');
        ll l = stoll(x.substr(0, idx));
        ll r = stoll(x.substr(idx + 1));
        if (l > r)
            swap(l, r);
        d.push_back({l, r});
        maxm1 = max(maxm1, r);
    }

    if (d.empty())
    {
        cout << 0 << endl;
        return;
    }

    ll maxm = check(maxm1);
    vector<ll> p(maxm + 1);
    p[0] = 1;
    g(i, 1, maxm + 1)
    {
        p[i] = p[i - 1] * 10LL;
    }

    vector<ll> c;

    set<ll> st;

    for (ll i = 2; i <= maxm; i++)
    {
        ll cnt = p[i];

        for (ll j = 1; j < i; j++)
        {
            if (i % j != 0)
                continue;
            ll tmp = p[j];
            ll x = tmp - 1;
            ll num = cnt - 1;
            ll ans = num / x;

            ll low = p[j - 1];
            ll high = tmp - 1;

            if (ans == 0)
                continue;

            if (low > maxm1 / ans)
                continue;

            ll lim = maxm1 / ans;
            if (lim < high)
                high = lim;

            for (ll k = low; k <= high; k++)
            {
                ll N = k * ans;
                st.insert(N);
            }
        }
    }

    for (auto v : st)
        c.push_back(v);
    sort(asc(c));

    sort(asc(d));

    ll count = 0;
    ll j = 0;

    for (ll x : c)
    {
        while (j < d.size() && x > d[j].second)
            j++;
        if (j == d.size())
            break;
        if (d[j].first <= x && x <= d[j].second)
        {
            count += x;
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
    //   freopen("AdventOfCodeDay2P1_input.txt","r",stdin);
    //   freopen("AdventOfCodeDay2P1_output.txt","w",stdout);
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