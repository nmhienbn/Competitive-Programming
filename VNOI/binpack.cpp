#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define minimize(x, y) x = x > y ? y : x
#define pb push_back
#define ll long long
#define Irelia "binpack"
const int maxn = 1e6 + 5, INF = 1e9;
using namespace std;

int L, n, a[maxn], res, maxa;
int f1[10005][5005], f2[10005][5005];

void ql(int i, int x1, int x2, int d){
    if (i > n){
        minimize(res, d + (x1 > 0) + (x2 > 0));
        return;
    }
    if (x1 + a[i] >= L)
        ql(i + 1, x1 + a[i] - L, x2, d + 1);
    else
        ql(i + 1, x1 + a[i], x2, d);
    if (x2 + a[i] >= L)
        ql(i + 1, x1, x2 + a[i] - L, d + 1);
    else
        ql(i + 1, x1, x2 + a[i], d);
}
void sub1(){
    res = INF;
    ql(1, 0, 0, 0);
    cout << res;
    exit(0);
}

void sub2(){
    int x = 0, y = 0, d = 0;
    fi(i, 1, n){
        if (a[i] == 1){
            if (L - y == 1){
                d++;
                y = 0;
            }
            else {
                x += a[i];
                if (x >= L) d++, x -= L;
            }
        }
        else {
            y += a[i];
            if (y >= L) d++, y -= L;
        }
    }
    if (x && y){
        y = L - y;
        x -= y;
        d += (x > 0) + 1;
    }
    cout << d;
    exit(0);
}

void sub3(){
    fi(i, 1, n) fi(j, 0, L){
        f1[i][j] = INF;
        f2[i][j] = INF;
    }
    f1[1][0] = 0;
    f2[1][0] = a[1];
    f1[1][a[1]] = 0;
    f2[1][a[1]] = 0;
    fi(i, 1, n - 1){
        fi(j, 0, L){
            if (j + a[i + 1] <= L){
                if (f1[i + 1][j + a[i + 1]] > f1[i][j]){
                    f1[i + 1][j + a[i + 1]] = f1[i][j];
                    f2[i + 1][j + a[i + 1]] = f2[i][j];
                }
                else if (f1[i + 1][j + a[i + 1]] == f1[i][j]
                        && f2[i + 1][j + a[i + 1]] > f2[i][j]){
                    f2[i + 1][j + a[i + 1]] = f2[i][j];
                }
            }
            else {
                if (f1[i + 1][a[i + 1]] > f1[i][j] + 1){
                    f1[i + 1][a[i + 1]] = f1[i][j] + 1;
                    f2[i + 1][a[i + 1]] = f2[i][j];
                }
                else if (f1[i + 1][a[i + 1]] == f1[i][j] + 1
                        && f2[i + 1][a[i + 1]] > f2[i][j]){
                    f2[i + 1][a[i + 1]] = f2[i][j];
                }
            }
            if (f2[i][j] + a[i + 1] <= L){
                 if (f1[i + 1][j] > f1[i][j]){
                      f1[i + 1][j] = f1[i][j];
                      f2[i + 1][j] = f2[i][j] + a[i + 1];
                 }
                 else if (f1[i + 1][j] == f1[i][j]
                        && f2[i + 1][j] > f2[i][j] + a[i + 1]){
                    f2[i + 1][j] = f2[i][j] + a[i + 1];
                }
            }
            else {
                if (f1[i + 1][j] > f1[i][j] + 1){
                    f1[i + 1][j] = f1[i][j] + 1;
                    f2[i + 1][j] = a[i + 1];
                }
                else if (f1[i + 1][j] == f1[i][j] + 1
                        && f2[i + 1][j] > a[i + 1]){
                    f2[i + 1][j] = a[i + 1];
                }
            }
        }
    }
    res = INF;
    fi(i, 0, L){
        minimize(res, f1[n][i] + (i > 0) + (f2[n][i] > 0));
    }
    cout << res;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> L >> n;
    fi(i, 1, n) cin >> a[i];
    maxa = *max_element(a + 1, a + n + 1);
    if (n <= 20) sub1();
    if (maxa <= 2) sub2();
    sub3();
}
