#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int WIDTH, HEIGHT, n, m, NumQuery;
pair<int, int> Point[maxn][10];
long long SubArea[maxn], AllArea[maxn], BoardArea;
int c[maxn];
int point;

bool kt(int x, int y, int i)
{
    long long SS = 0;
    for (int j = 1; j <= m; j++)
    {
        SS += abs(((long long)(Point[i][j].first - x)) * (Point[i][j - 1].second - y) - ((long long)(Point[i][j - 1].first - x)) * (Point[i][j].second - y));
    }
    return SS == AllArea[i];
}
bool cmp(int i, int j)
{
    return AllArea[i] < AllArea[j];
}
void sapXep()
{
    for (int i = 1; i <= n; i++)
        c[i] = i;
    sort(c + 1, c + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            if (kt(Point[c[j]][1].first, Point[c[j]][1].second, c[i]))
            {
                SubArea[c[i]] -= SubArea[c[j]];
            }
        }
        BoardArea -= SubArea[c[i]];
    }
}

void ANSWER(const long long &Area)
{
    cout << Area / 2 << (Area % 2 ? ".5" : ".0") << '\n';
}
void Query()
{
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
        if (kt(x, y, c[i]))
        {
            ANSWER(SubArea[c[i]]);
            return;
        }
    ANSWER(BoardArea);
}

void SUB12()
{
    sapXep();
    while (NumQuery--)
    {
        Query();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // freopen("paint.inp", "r", stdin);
    // freopen("paint.out", "w", stdout);
    cin >> WIDTH >> HEIGHT >> n >> m >> NumQuery;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> Point[i][j].first >> Point[i][j].second;
    }

    BoardArea = 2ll * WIDTH * HEIGHT;

    // Tinh dien tich
    for (int i = 1; i <= n; i++)
    {
        Point[i][0] = Point[i][m];
        for (int j = 1; j <= m; j++)
        {
            SubArea[i] += ((long long)(Point[i][j].first + Point[i][j - 1].first) * (Point[i][j].second - Point[i][j - 1].second));
        }
        SubArea[i] = abs(SubArea[i]);
        AllArea[i] = SubArea[i];
    }

    sapXep();
    while (NumQuery--)
    {
        Query();
    }

    return 0;
}
