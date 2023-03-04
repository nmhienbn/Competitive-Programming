#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define maximize(x, y) x = x < y ? y : x
#define ll long long
#define Irelia "message1"
const int maxn = 105;
using namespace std;

int nt, m, n, res;
int d[maxn];
int st[maxn], top;
int nex[maxn], pre;

void calc(int x, int y, const vector<string> &a, const vector<string> &b){
    int iL = max(0, x); int iR = min(m, m + x);
    int jL = max(0, y); int jR = min(n, n + y);
    if ((iR - iL) * (jR - jL) <= res) return;
    fi(i, 0, n) d[i] = 0;
    fi(i, iL, iR - 1){
        fi(j, jL, jR - 1){
            if (a[i][j] == b[i - x][j - y]) d[j]++;
            else d[j] = 0;
        }
        if ((i - iL + 1) * (jR - jL) <= res) continue;
        top = 0, st[0] = jR;
        fid(j, jR - 1, jL){
            while (top > 0 && d[st[top]] >= d[j]){
                top--;
            }
            nex[j] = st[top];
            st[++top] = j;
        }
        top = 0, st[0] = jL - 1;
        fi(j, jL, jR - 1){
            while (top > 0 && d[st[top]] >= d[j]){
                top--;
            }
            pre = st[top];
            st[++top] = j;
            maximize(res, d[j] * (nex[j] - pre - 1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        res = 0;
        cin >> m >> n;
        vector<string> a(m), b(m);
        for (auto &s: a) cin >> s;
        for (auto &s: b) cin >> s;
        fi(i, 0, m - 1) fi(j, 0, n - 1){
            calc(i, j, a, b);
            if (i){
                calc(-i, j, a, b);
                if (j) calc(-i, -j, a, b);
            }
            if (j){
                calc(i, -j, a, b);
            }
        }
        cout << res << '\n';
    }
}
