#include <bits/stdc++.h>
#define fi(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define Irelia "paint"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<edge, null_type, less<edge>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 5;

int WIDTH, HEIGHT, n, m, NumQuery;
pii Point[maxn][10];
ll SubArea[maxn], AllArea[maxn], BoardArea;
int c[maxn];

bool kt(int x, int y, int i)
{
    if (i == n + 1) return true;
    ll SS = 0;
    fi(j, 1, m)
    {
        ll tmp = abs(1ll * (Point[i][j].X - x) * (Point[i][j - 1].Y - y) - 1ll * (Point[i][j - 1].X - x) * (Point[i][j].Y - y));
        if (tmp == 0) return false;
        SS += tmp;
    }
    return SS == AllArea[i];
}
bool cmp(int i, int j)
{
    return AllArea[i] < AllArea[j];
}
void sapXep()
{
    fi(i, 1, n) c[i] = i;
    sort(c + 1, c + n + 1, cmp);
    fi(i, 1, n)
    {
        fi(j, 1, i - 1)
        {
            if (kt(Point[c[j]][1].X, Point[c[j]][1].Y, c[i]))
            {
                SubArea[c[i]] -= SubArea[c[j]];
            }
        }
        BoardArea -= SubArea[c[i]];
    }
}

void ANSWER(const ll &Area)
{
    cout << Area / 2 << (Area % 2 ? ".5" : ".0") << '\n';
}
void Query()
{
    int x, y;
    cin >> x >> y;
    fi(i, 1, n) if (kt(x, y, c[i]))
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

struct edge
{
    int x1, y1, x2, y2, id;
    bool operator<(const edge &other) const
    {
        if (x1 == other.x1)
            return x2 == other.x2 ? y1 < other.y1 : x2 < other.x2;
        return x1 < other.x1;
    }
    friend bool isPointLeftEdge(const edge &A, int x, int y)
    {
        double x_0 = (1LL * (A.x2 - A.x1) * y + 1LL * A.x1 * A.y2 - 1LL * A.x2 * A.y1) * 1.0 / (A.y2 - A.y1);
        return x <= x_0;
    }
} ADD[maxn * 5], REM[maxn * 5];

edge make_edge(int _x1, int _y1, int _x2, int _y2, int _id)
{
    if (_y1 > _y2)
    {
        return {_x2, _y2, _x1, _y1, _id};
    }
    return {_x1, _y1, _x2, _y2, _id};
}
bool CompY1(const edge &A, const edge &B)
{
    return A.y1 == B.y1 ? A.x1 < B.x1 : A.y1 < B.y1;
}
bool CompY2(const edge &A, const edge &B)
{
    return A.y2 < B.y2;
}

struct QueryType
{
    int x, y, id;
    bool operator<(const QueryType &other) const
    {
        return y == other.y ? x < other.x : y < other.y;
    }
} QueryPoint[maxn * 2];
int ANS[maxn * 2];
int POLY[maxn];

ordered_set o_set;
int choose(int x, int y, int i, int j){
    if (i == j) return i;
    if (kt(x, y, i)){
        return i;
    }
    else {
        return POLY[i];
    }
}
int CALC(int i)
{
    int dau = 0, cuoi = (int)o_set.size() - 2;
    ordered_set::iterator U, V;
    while (dau <= cuoi)
    {
        int giua = (dau + cuoi) >> 1;
        U = o_set.find_by_order(giua);
        V = U;
        V++;
        bool isLeftU = isPointLeftEdge(*U, QueryPoint[i].x, QueryPoint[i].y);
        bool isLeftV = isPointLeftEdge(*V, QueryPoint[i].x, QueryPoint[i].y);
        if (isLeftU && isLeftV)
        {
            cuoi = giua - 1;
        }
        else if (!isLeftU && !isLeftV)
        {
            dau = giua + 1;
        }
        else
        {
            return choose(QueryPoint[i].x, QueryPoint[i].y, U->id, V->id);
        }
    }
    return n + 1;
}

void SUB4()
{
    fi(i, 1, NumQuery)
    {
        cin >> QueryPoint[i].x >> QueryPoint[i].y;
        QueryPoint[i].id = i;
    }
    fi(i, 1, n)
    {
        int id = i + NumQuery;
        QueryPoint[id] = {Point[i][1].X, Point[i][1].Y, id};
        fi(j, 2, m)
        {
            if (Point[i][j].Y < QueryPoint[id].y){
                QueryPoint[id].x = Point[i][j].X;
                QueryPoint[id].y = Point[i][j].Y;
            }
            else if (Point[i][j].Y == QueryPoint[id].y && Point[i][j].X < QueryPoint[id].x){
                QueryPoint[id].x = Point[i][j].X;
            }
        }
    }
    int TotalQuery = NumQuery + n;
    sort(QueryPoint + 1, QueryPoint + TotalQuery + 1);

    int cnt = 0;
    fi(i, 1, n)
    {
        fi(j, 1, m) if (Point[i][j - 1].Y != Point[i][j].Y)
        {
            ADD[++cnt] = make_edge(Point[i][j - 1].X, Point[i][j - 1].Y,
                                   Point[i][j].X, Point[i][j].Y, i);
            REM[cnt] = ADD[cnt];
        }
    }
    sort(ADD + 1, ADD + cnt + 1, CompY1);
    sort(REM + 1, REM + cnt + 1, CompY2);
    int nowADD = 1, nowREM = 1;
    fi(i, 1, TotalQuery)
    {
        while (nowADD <= cnt && ADD[nowADD].y1 <= QueryPoint[i].y)
        {
            if (ADD[nowADD].y1 == QueryPoint[i].y && ADD[nowADD].x1 >= QueryPoint[i].x) break;
            o_set.insert(ADD[nowADD]);
            nowADD++;
        }
        while (nowREM <= cnt && REM[nowREM].y2 <= QueryPoint[i].y)
        {
            o_set.erase(REM[nowREM]);
            nowREM++;
        }

        ANS[QueryPoint[i].id] = CALC(i);
        if (QueryPoint[i].id > NumQuery){
            POLY[QueryPoint[i].id - NumQuery] = ANS[QueryPoint[i].id];
        }
    }
    fi(i, 1, n)
    {
        SubArea[POLY[i]] -= AllArea[i];
    }
    fi(i, 1, NumQuery)
    {
        ANSWER(SubArea[ANS[i]]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> WIDTH >> HEIGHT >> n >> m >> NumQuery;
    fi(i, 1, n)
    {
        fi(j, 1, m) cin >> Point[i][j].X >> Point[i][j].Y;
        Point[i][0] = Point[i][m];
    }

    BoardArea = 2ll * WIDTH * HEIGHT;

    // Tinh dien tich
    fi(i, 1, n)
    {
        fi(j, 1, m)
        {
            SubArea[i] += 1ll * (Point[i][j].X + Point[i][j - 1].X) * (Point[i][j].Y - Point[i][j - 1].Y);
        }
        SubArea[i] = abs(SubArea[i]);
        AllArea[i] = SubArea[i];
    }
    SubArea[n + 1] = AllArea[n + 1] = BoardArea;

    if (n <= 2000)
        SUB12();
    else
        SUB4();
}
