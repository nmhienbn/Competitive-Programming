#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bhouse"
const int maxn = 1005;
using namespace std;

int n, m, a[maxn][maxn], b[maxn];
ll res;
int st[maxn], top;
int pre[maxn], nex[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n)
            cin >> a[i][j];
    }
    fi(i, 1, m){
        fi(j, 1, n){
            if (a[i][j] == a[i - 1][j]) b[j]++;
            else b[j] = 1;
        }
        top = 0;
        st[top] = n + 1;
        fid(j, n, 1){
            if (a[i][j] != a[i][j + 1]){
                top = 0;
                st[top] = j + 1;
            }
            while (top > 0 && b[st[top]] > b[j]) top--;
            nex[j] = st[top] - 1;
            st[++top] = j;
        }
        top = 0;
        st[top] = 0;
        fi(j, 1, n){
            if (a[i][j] != a[i][j - 1]){
                top = 0;
                st[top] = j - 1;
            }
            while (top > 0 && b[st[top]] >= b[j]) top--;
            pre[j] = st[top] + 1;
            st[++top] = j;
        }
        fi(j, 1, n){
            res += 1ll * b[j] * (nex[j] - j + 1) * (j - pre[j] + 1);
        }
    }
    cout << res;
}
