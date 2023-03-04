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

int a, b, c, d[maxn], cnt, n;
string s;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> b >> c;
    n = a+b+c;
    s.resize(n+5);
    fi(i, 1, a){
        cin >> d[i];
        s[d[i]] = 'A';
    }
    d[a+1] = n+1;
    a++;
    sort(d+1, d+a+1);
    fi(i, 1, a){
        cnt += (d[i] - d[i-1] - 1)/2;
    }
    b -= cnt, c -= cnt;
    if (b < 0 || c < 0){
        cout << -1;
        exit(0);
    }
    fi(i, 1, a){
        if ((d[i] - d[i-1] - 1) % 2 == 0 || b > 0){
            fi(j, d[i-1]+1, d[i]-1){
                s[j] = ((j - d[i-1]) % 2 ? 'B' : 'C');
            }
            b -= (d[i] - d[i-1] - 1) % 2;
        }
        else {
            fi(j, d[i-1]+1, d[i]-1){
                s[j] = ((j - d[i-1]) % 2 ? 'C' : 'B');
            }
            c--;
        }
    }
    fi(i, 1, n) cout << s[i];
}
