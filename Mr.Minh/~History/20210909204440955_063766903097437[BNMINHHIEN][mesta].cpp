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

int a, b, c, d[maxn], cnt, dem;
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
    fi(i, 2, a){
        if (d[i-1] >= d[i] - 1){
            cout << -1;
            exit(0);
        }
        cnt += (d[i] - d[i-1]) / 2;
        dem += (d[i] - d[i-1]) % 2;
    }
    int bb = b - cnt, cc = c - cnt;
    if (bb < 0 || cc < 0 || bb + cc < dem || max(bb, cc) > min(bb, cc) + 2 || d[a] > a+b+c){
        cout << -1;
        exit(0);
    }
    fi(i, 2, a){
        if ((d[i] - d[i-1]) % 2 == 0 || bb > 0){
            fi(j, d[i-1]+1, d[i]-1){
                s[j] = ((j - d[i-1]) % 2 ? 'B' : 'C');
            }
            bb -= (d[i] - d[i-1]) % 2;
        }
        else {
            fi(j, d[i-1]+1, d[i]-1){
                s[j] = ((j - d[i-1]) % 2 ? 'C' : 'B');
            }
            cc--;
        }
    }
    if (cc == bb + 2){
        fi(i, 1, d[1]-1){
            s[i] = (i % 2 ? 'C' : 'B');
        }
        bb -= (d[1] - 1) / 2;
        cc -= d[1] - 1 - (d[1] - 1) / 2;
    }
    else {
        fi(i, 1, d[1]-1){
            s[i] = (i % 2 ? 'B' : 'C');
        }
        bb -= d[1] - 1 - (d[1] - 1) / 2;
        cc -= (d[1] - 1) / 2;
    }
    if (bb >= cc){
        fi(j, d[a]+1, a+b+c){
            s[j] = ((j - d[a]) % 2 ? 'B' : 'C');
        }
    }
    else {
        fi(j, d[a]+1, a+b+c){
            s[j] = ((j - d[a]) % 2 ? 'C' : 'B');
        }
    }
    fi(i, 1, a+b+c) cout << s[i];
}
