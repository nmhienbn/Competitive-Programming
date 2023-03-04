#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "photo"
#define maxn 100005

using namespace std;

int n;
int a[maxn], b[10][maxn], c[maxn];
bool cmp(int x, int y){
    int dem = 0, vx, vy;
    fi(i, 1, 5){
        fi(j, 1, n){
            if (b[i][j] == a[x]) vx = j;
            if (b[i][j] == a[y]) vy = j;
        }
        if (vx < vy) dem++;
        else dem--;
    }
    if (dem > 0) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, 5) fi(j, 1, n) cin >> b[i][j];
    fi(i, 1, n) {c[i] = i; a[i] = b[1][i];}
    sort(c, c+n+1, cmp);
    fi(i, 1, n) cout << a[c[i]] << ' ';
}
