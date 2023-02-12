#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int maxm = maxn * maxn;

int n, d, m, res;
int a[maxn];
pair<int, int> b[maxm], c[maxm];
bool cl[maxn];

bool cmp(pair<int, int> i, pair<int, int> j)
{
    return a[i.first] + a[i.second] < a[j.first] + a[j.second];
}

bool cmp2(pair<int, int> i, pair<int, int> j)
{
    return i.first == j.first ? i.second > j.second : i.first < j.first;
}

void nhap()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            b[++m] = {i, j};
    sort(b + 1, b + m + 1, cmp);
}

void xuli()
{
    for (int i = 1; i <= m; i++)
        if (a[b[i - 1].first] + a[b[i - 1].second] < a[b[i].first] + a[b[i].second])
        {
            int cnt = 0, ans = 0, sum = a[b[i].first] + a[b[i].second] + d;
            for (int j = i; j <= m; j++)
            {
                if (a[b[j].first] + a[b[j].second] > sum)
                    break;
                c[++cnt] = b[j];
            }
            sort(c + 1, c + cnt + 1, cmp2);
            for (int j = 1; j <= cnt; j++)
            {
                if (!cl[c[j].first] && !cl[c[j].second])
                {
                    ans++;
                    cl[c[j].first] = cl[c[j].second] = 1;
                }
            }
            res = max(res, ans);
            for (int j = 1; j <= cnt; j++)
            {
                cl[c[j].first] = cl[c[j].second] = 0;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("pair.inp", "r", stdin);
    freopen("pair.out", "w", stdout);
    nhap();
    xuli();
    cout << res;
}
