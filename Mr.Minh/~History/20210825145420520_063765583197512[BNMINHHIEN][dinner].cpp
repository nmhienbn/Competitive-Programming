#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dinner"
const int maxn = 405;

using namespace std;

int n, m, a[maxn][maxn], b[maxn][maxn], res;
int st[maxn*2], top, pre[maxn], nex[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        fi(j, 1, m){
            char c;
            cin >> c;
            if (c == '.'){
                a[i][j] = 1;
            }
            b[i][j] = a[i][j];
            if (a[i-1][j] && a[i][j]) b[i][j] += b[i-1][j];
        }
    }
    fi(i, 1, n){
        top = 0; st[0] = 0;
        fi(j, 1, m){
            while (top > 0 && b[i][st[top]] >= b[i][j]) top--;
            pre[j] = st[top];
            st[++top] = j;
        }
        top = 0; st[0] = n+1;
        fid(j, m, 1){
            while (top > 0 && b[i][st[top]] >= b[i][j]) top--;
            nex[j] = st[top];
            st[++top] = j;
        }
        fi(j, 1, m){
            if (b[i][j] > 0 && nex[j] - pre[j] > 1){
                res = max(res, b[i][j] + nex[j] - pre[j] - 1);
            }
        }
    }
    cout << res*2 - 1;
}
