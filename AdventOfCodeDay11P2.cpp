/**************************************
11/12
Author - kreeeesh_17
**************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// device -> list of outputs
unordered_map<string, vector<string>> mp;

// dp[node] = 4 states packed into nested pairs
// mask -> value
// 0 -> dp[node].first.first
// 1 -> dp[node].first.second
// 2 -> dp[node].second.first
// 3 -> dp[node].second.second
unordered_map<string, pair<pair<ll, ll>, pair<ll, ll>>> dp;

// helper: map mask (0..3) to the correct slot in nested pair
ll &get_dp(const string &node, int mask)
{
    auto &p = dp[node]; // default-constructs pair if missing
    if (mask == 0)
        return p.first.first;
    if (mask == 1)
        return p.first.second;
    if (mask == 2)
        return p.second.first;
    return p.second.second; // mask == 3
}

long long dfs(const string &node, int mask, unordered_set<string> &vis)
{
    int newMask = mask;
    if (node == "dac")
        newMask |= 1; // bit 0
    if (node == "fft")
        newMask |= 2; // bit 1

    // base case: reached out
    if (node == "out")
    {
        return (newMask == 3) ? 1LL : 0LL;
    }

    // ensure node has dp entry and default-init all to -1 once
    if (!dp.count(node))
    {
        auto &p = dp[node];
        p.first.first = -1;
        p.first.second = -1;
        p.second.first = -1;
        p.second.second = -1;
    }

    ll &memo = get_dp(node, newMask);
    if (memo != -1)
        return memo;

    // cycle guard
    if (vis.count(node))
        return memo = 0LL;

    vis.insert(node);
    long long ways = 0;

    auto it = mp.find(node);
    if (it != mp.end())
    {
        for (const string &nxt : it->second)
        {
            ways += dfs(nxt, newMask, vis);
        }
    }

    vis.erase(node);
    memo = ways;
    return memo;
}

void solve()
{
    mp.clear();
    dp.clear();

    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        size_t pos = line.find(':');
        if (pos == string::npos)
            continue; // ignore malformed

        string u = line.substr(0, pos);
        // trim spaces around u
        while (!u.empty() && isspace(u.back()))
            u.pop_back();
        size_t st = 0;
        while (st < u.size() && isspace(u[st]))
            st++;
        u = u.substr(st);

        string rest = line.substr(pos + 1); // right side
        stringstream ss(rest);
        string v;
        while (ss >> v)
        {
            mp[u].push_back(v);
        }
        if (!mp.count(u))
            mp[u] = {};
    }

    unordered_set<string> vis;
    long long ans = dfs("svr", 0, vis);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
