#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "bethist"
const int maxn = 1e4+5;

using namespace std;

int n, a, b, L[maxn][205], pre[maxn][205], t[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> a >> b;
    a += 100; b += 100;
    L[0][100] = 1;
    cin >> t[1];
    L[1][100-t[1]] = L[1][100+t[1]] = 1;
    fi(i, 2, n){
        int x;
        cin >> x;
        t[i] = x;
        fi(j, a, b){
            if (j - x >= a && L[i-1][j-x]){
                L[i][j] = L[i-1][j-x];
                pre[i][j] = 1;
            }
            if (j + x <= b && L[i-1][j+x]){
                L[i][j] = L[i-1][j+x];
                pre[i][j] = 0;
            }
        }
    }
    stack<int> res;
    fi(i, a, b){
        if (L[n][i]){
            fid(j, n, 1){
                if (!pre[j][i]) res.push(0), i += t[j];
                else res.push(1), i -= t[j];
            }
            while (res.size()){
                cout << res.top();
                res.pop();
            }
            exit(0);
        }
    }
    cout << "Impossible";
}
