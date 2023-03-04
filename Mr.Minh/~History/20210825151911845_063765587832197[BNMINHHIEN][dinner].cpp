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

int n, m, a[maxn][maxn], res;
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
                a[i][j] = a[i-1][j] + 1;
            }
            else a[i][j] = 0;
        }
    }
    fi(i, 1, n){
        top = 0; st[0] = 0; a[i][0] = -1;
        fi(j, 1, m){
            while (a[i][st[top]] >= a[i][j]) top--;
            pre[j] = st[top]+1;
            st[++top] = j;
        }
        top = 0; st[0] = m+1; a[i][m+1] = -1;
        fid(j, m, 1){
            while (a[i][st[top]] >= a[i][j]) top--;
            nex[j] = st[top]-1;
            st[++top] = j;
        }
        fi(j, 1, m){
            if (a[i][j] > 0 && nex[j] >= pre[j]){
                res = max(res, a[i][j] + nex[j] - pre[j] + 1);
            }
        }
    }
    cout << res*2 - 1;
}
