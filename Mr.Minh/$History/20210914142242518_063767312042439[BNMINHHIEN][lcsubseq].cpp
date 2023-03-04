#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lcsubseq"
const int maxn = 2005;

using namespace std;

struct dl {
    char c;
    int x, y;
} lv[maxn][maxn];

int L[maxn][maxn];
string a, b;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    fi(i, 1, n){
        fi(j, 1, m){
            if (a[i] == b[j]){
                L[i][j] = L[i-1][j-1] + 1;
                lv[i][j] = {a[i], i-1, j-1};
            }
            else {
                if (L[i-1][j] > L[i][j-1] ||
                    (L[i-1][j] == L[i][j-1] && lv[i-1][j].c < lv[i][j-1].c)){
                    L[i][j] = L[i-1][j];
                    lv[i][j] = lv[i-1][j];
                }
                else {
                    L[i][j] = L[i][j-1];
                    lv[i][j] = lv[i][j-1];
                }
            }
        }
    }
    string res;
    int i = n, j = m;
    fi(k, 1, L[n][m]){
        res = lv[i][j].c + res;
        auto t = lv[i][j];
        i = t.x;
        j = t.y;
    }
    cout << res;
}
