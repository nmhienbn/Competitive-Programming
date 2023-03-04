#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "protein"
const int maxn = 105, maxm = 4e4 + 5;
using namespace std;

int n, m, cnt;
string a, b;
int f[maxn][maxn], len;
char res[maxm][maxn], now[maxn];

void LCS(){
    fid(i, n, 1) fid(j, m, 1){
        if (a[i] == b[j]){
            f[i][j] = f[i + 1][j + 1] + 1;
        }
        else {
            f[i][j] = max(f[i + 1][j], f[i][j + 1]);
        }
    }
    len = f[1][1];
}

void xuli(){
    cnt++;
    fi(i, 1, len) res[cnt][i] = now[i];
}

void Print(int vt, int i1, int j1){
    if (vt > len){
        xuli();
    }
    if (i1 > n || j1 > m) return;
    for (char ch = 'A'; ch <= 'Z'; ch++){
        bool ok = 0;
        fi(i, i1, n){
            if (a[i] != ch) continue;
            fi(j, j1, m){
                if (b[j] != ch || f[i][j] != len - vt + 1) continue;
                now[vt] = ch;
                Print(vt + 1, i + 1, j + 1);
                ok = 1;
                break;
            }
            if (ok) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    LCS();
    Print(1, 1, 1);
    cout << cnt << '\n';
    fi(i, 1, cnt){
        fi(j, 1, len) cout << res[i][j];
        cout << '\n';
    }
}
