#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "nk"
const int maxn = 155;
using namespace std;

int n, m, f[maxn][maxn];
pair<char, int> pre[maxn][maxn];
string s, t, res;

void minimize(int& x, int y){
    if (x > y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    cin.ignore();
    getline(cin, t);
    n = s.size();
    m = t.size();
    t = ' ' + t;
    fi(i, 0, m) fi(j, 0, n - 1) f[i][j] = 1e9;
    f[0][0] = 0;
    fi(i, 1, m){
        if (t[i] == ' '){
            fi(j, 0, n - 1){
                if (f[i][j] > f[i - 1][j]){
                    f[i][j] = f[i - 1][j];
                    pre[i][j].first = 'S';
                }
            }
        }
        else {
            fi(j, 0, n - 1) if (s[j] == t[i]){
                fi(k, 0, n - 1){
                    if (abs(k - j) <= n / 2){
                        if (f[i][j] > f[i - 1][k] + abs(k - j)){
                            f[i][j] = f[i - 1][k] + abs(k - j);
                            pre[i][j].second = abs(k - j);
                            if (k == j) pre[i][j].first = 'O';
                            else if (k < j) pre[i][j].first = 'R';
                            else pre[i][j].first = 'L';
                        }
                    }
                    else {
                        if (f[i][j] > f[i - 1][k] + n - abs(k - j)){
                            f[i][j] = f[i - 1][k] + n - abs(k - j);
                            pre[i][j].second = n - abs(k - j);
                            if (k < j) pre[i][j].first = 'L';
                            else pre[i][j].first = 'R';
                        }
                    }
                }
            }
        }
    }
    int id = 0;
    fi(i, 1, n - 1) if (f[m][i] < f[m][id]){
        id = i;
    }
    fid(i, m, 1){
        if (t[i] != ' '){
            res = 'P' + res;
            pair<char, int> now = pre[i][id];
            fi(j, 1, now.second){
                res = now.first + res;
                if (now.first == 'L') id = (id + 1) % n;
                else id = (id + n - 1) % n;
            }
        }
        else res = 'S' + res;
    }
    cout << res;
}
