#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "pvhoi20b6string"
const int maxn = 3005, mod = 998244353;

using namespace std;

int n, k;
ll res;
string s, s2;

void xuli(){
    int cnt = 0;
    fi(i, 0, n-1){
        fi(j, 0, i){
            fi(t, j, i){
                if (s2[t] > s[t]){
                    cnt++;
                    break;
                }
            }
        }
    }
    res += cnt == k;
}

void ql(int i){
    fi(j, 0, 25){
        s2[i] = 'a' + j;
        if (i == n-1) xuli();
        else ql(i+1);
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k >> s;
    s2 = s;
    if (k == 0){
        res = 1;
        for (auto c : s){
            res = res * ('z' - c + 1) % mod;
        }
        cout << res;
    }
    ql(0);
    cout << res;
}
