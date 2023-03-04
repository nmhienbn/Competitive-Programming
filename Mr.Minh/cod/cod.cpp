#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cod"
const int maxn = 205;

using namespace std;

int n, m, L[maxn][maxn];
string a, b, s[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a >> b;
    n = a.size();
    a = ' ' + a;
    m = b.size();
    b = ' ' + b;

    fi(i, 1, n) fi(j, 1, m){
        if (a[i] == b[j]){
            L[i][j] = L[i - 1][j - 1] + 1;
            s[i][j] = s[i - 1][j - 1] + a[i];
        }
        else {
            if (L[i - 1][j] > L[i][j - 1]){
                L[i][j] = L[i - 1][j];
                s[i][j] = s[i - 1][j];
            }
            else if (L[i - 1][j] < L[i][j - 1]){
                L[i][j] = L[i][j - 1];
                s[i][j] = s[i][j - 1];
            }
            else {
                L[i][j] = L[i - 1][j];
                s[i][j] = max(s[i - 1][j], s[i][j - 1]);
            }
        }
    }
    cout << s[n][m];
}
