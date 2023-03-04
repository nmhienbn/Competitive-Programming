#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "mesta"
const int maxn = 1e4+5;

using namespace std;

int a, b, c, d[maxn], e[maxn], cnt, dem;
string s;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> b >> c;
    s.resize(a+b+c+5);
    fi(i, 1, a){
        cin >> d[i];
        s[d[i]] = 'A';
    }
    sort(d+1, d+a+1);
    if (d[a] > a+b+c){
        cout << -1;
        exit(0);
    }
    d[a+1] = a+b+c+1;
    a++;
    fi(i, 1, a){
        e[i] = d[i] - d[i-1] - 1;
        cnt += e[i] / 2;
        dem += e[i] % 2;
    }
    int bb = b - cnt, cc = c - cnt;
    if (bb < 0 || cc < 0 || bb + cc < dem){
        cout << -1;
        exit(0);
    }
    fi(i, 1, a){
        if (e[i] % 2 == 0 || bb > 0){
            fi(j, d[i-1]+1, d[i]-1){
                s[j] = ((j - d[i-1]) % 2 ? 'B' : 'C');
            }
            bb -= e[i] % 2;
        }
        else {
            fi(j, d[i-1]+1, d[i]-1){
                s[j] = ((j - d[i-1]) % 2 ? 'C' : 'B');
            }
            cc--;
        }
    }
    fi(i, 1, a+b+c) cout << s[i];
}
