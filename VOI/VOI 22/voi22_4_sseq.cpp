#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

struct dl
{
    int l, r, w;
    bool operator<(const dl &x) const
    {
        return l < x.l;
    }
};
dl a[maxn];

int n;
long long st[maxm << 2], lz[maxm << 4];
long long res;

void lazy(int id, long long x)
{
    st[id] += x;
    lz[id] += x;
}
void down(int id)
{
    lazy(id << 1, lz[id]);
    lazy(id << 1 | 1, lz[id]);
    lz[id] = 0;
}
void update(int id, int l, int r, int d, int c, int x)
{
    if (r < d || l > c)
        return;
    if (d <= l && r <= c)
    {
        lazy(id, x);
        return;
    }
    int m = (l + r) >> 1;
    down(id);
    update(id << 1, l, m, d, c, x);
    update(id << 1 | 1, m + 1, r, d, c, x);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}
void update(int d, int c, int x)
{
    update(1, 1, 1000000, d, c, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("sseq.inp", "r", stdin);
    freopen("sseq.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].w;
        update(a[i].r, 1000000, a[i].w);
    }
    sort(a + 1, a + n + 1);
    int j = 1;
    for (int i = 1; i <= n; i++)
        if (a[i].l != a[i - 1].l)
        {
            while (j < i)
            {
                update(a[j].r, 1000000, -a[j].w);
                j++;
            }
            res = max(res, st[1]);
        }
    cout << res;
}
