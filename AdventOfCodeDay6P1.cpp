/**************************************
10/12
Author - kreeeesh_17
Created : 12:05:22
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
    vector<string> a;
    string s;
    while (getline(cin, s))
    {
        a.push_back(s);
    }
    ll n = a.size();
    ll m = 0;
    for (auto x : a)
    {
        m = max(m, (ll)x.size());
    }
    for (auto x : a)
    {
        if (x.size() < m)
        {
            x += string(m - x.size(), ' ');
        }
    }
    vint b(m, 1);
    f(j, m)
    {
        f(i, n)
        {
            if (a[i][j] != ' ')
            {
                b[j] = 0;
                break;
            }
        }
    }
    ll count = 0;
    ll idx = 0;
    while (idx < m)
    {
        while (idx < m && b[idx])
        {
            idx++;
        }
        if (idx == m)
        {
            break;
        }
        ll st = idx;
        while (idx < m && !b[idx])
        {
            idx++;
        }
        ll en = idx - 1;
        char ch = 0;
        g(i, st, en + 1)
        {
            if (a[n - 1][i] == '+' || a[n - 1][i] == '*')
            {
                ch = a[n - 1][i];
                break;
            }
        }
        if (ch == 0)
        {
            continue;
        }
        vint num;
        f(i, n - 1)
        {
            ll pos = st;
            while (pos <= en)
            {
                while (pos <= en && !isdigit(a[i][pos]))
                {
                    pos++;
                }
                if (pos > en)
                {
                    break;
                }
                ll cnt = 0;
                while (pos <= en && isdigit(a[i][pos]))
                {
                    cnt = (cnt * 10) + (a[i][pos] - '0');
                    pos++;
                }
                num.push_back(cnt);
            }
        }
        if (!num.empty())
        {
            ll ans;
            if (ch == '+')
            {
                ans = 0;
            }
            else
            {
                ans = 1;
            }
            for (auto y : num)
            {
                if (ch == '+')
                {
                    ans += y;
                }
                else
                {
                    ans *= y;
                }
            }
            count += ans;
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
    //   freopen("AdventOfCodeDay6P1_input.txt","r",stdin);
    //   freopen("AdventOfCodeDay6P1_output.txt","w",stdout);
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