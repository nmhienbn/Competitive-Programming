#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "permn"
const int maxn = 1e5+5;
using namespace std;

int m;
vector<int> cnt(10, 0);
ll res;
string x;
map<vector<int>, ll> a[100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> x >> m;
    for (char c : x){
        cnt[c - '0']++;
    }
    a[0][cnt] = 1;
    fi(i, 1, int(x.size())){
        map<vector<int>, ll> b[100];
        fi(j, 0, m-1){
            for (auto vt : a[j]){
                vector<int> u = vt.first;
                ll v = vt.second;
                if (i > 1 && u[0] > 0){
                    u[0]--;
                    b[(j*10) % m][u] += v;
                    u[0]++;
                }
                fi(k, 1, 9) if (u[k] > 0){
                    u[k]--;
                    b[(j*10+k) % m][u] += v;
                    u[k]++;
                }
            }
        }
        fi(j, 0, m-1) a[j] = b[j];
    }
    fi(i, 0, 9) cnt[i] = 0;
    cout << a[0][cnt];
}
