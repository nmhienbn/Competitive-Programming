#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "palincut"
const int maxn = 10005, N = 1 << 13;

using namespace std;

int n, q, k, a[15];
int L[N], nex[maxn][maxn];
bool kt[maxn][maxn];
string s;

void maximize(int& x, int y){
    if (x < y) x = y;
}

void minimize(int& x, int y){
    if (x > y) x = y;
}

void palindrome(){
    fi(i, 1, n) kt[i][i] = 1;
    fi(i, 1, n - 1) if (s[i] == s[i + 1]) kt[i][i + 1] = 1;
    fi(j, 2, n - 1) fi(i, 1, n - j){
        if (s[i] == s[i + j]) kt[i][i + j] = kt[i + 1][i + j - 1];
    }
    fi(i, 1, n){
        fi(j, n - i + 2, n + 5) nex[i][j] = n + 1;
        fid(j, n - i + 1, 1){
            if (kt[j][j + i - 1]) nex[i][j] = j;
            else nex[i][j] = nex[i][j + 1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    palindrome();
    cin >> q;
    while (q--){
        cin >> k;
        fi(i, 0, k - 1) cin >> a[i];
        int u = (1 << k) - 1;
        L[0] = 0;
        fi(i, 1, u) L[i] = n + 1;
        fi(i, 1, u){
            fi(j, 0, k-1){
                if (gb(i, j)){
                    int p = i - (1 << j);
                    if (L[p] >= n) continue;
                    minimize(L[i], nex[a[j]][L[p] + 1] + a[j] - 1);
                }
            }
        }
        //fi(i, 0, u) cout << M[i];
        cout << (L[u] <= n ? "YES" : "NO") << '\n';
    }
}
