#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "tbc"
#define maxn 1005
#define maxm 1000005

using namespace std;

int n, a[maxn], m, res, xd[maxm], dem;
struct dulieu{
    int val, vt1, vt2;
};

bool cmp(dulieu a, dulieu b){
    return a.val < b.val;
}
//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';

dulieu b[maxm];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fi(i, 1, n-1)
        fi(j, i+1, n){
            b[++m].val = a[i] + a[j];
            b[m].vt1 = i;
            b[m].vt2 = j;
        }
    sort(b+1, b+m+1, cmp);
    fi(i, 1, n){
        if (a[i] == a[i-1] && i > 1) {xd[i] = xd[i-1]; res += xd[i]; continue;}
        int x = a[i]*3;
        fi(j, 1, n){
            int d1 = 1, c1 = m;
            while (d1 < c1){
                int g = (c1+d1)/2;
                if (b[g].val >= x-a[j]) c1 = g;
                else d1 = g+1;
            }

            int d2 = 1, c2 = m;
            while (d2 < c2){
                int g = (c2+d2)/2;
                if (b[g].val > x-a[j]) c2 = g-1;
                else d2 = g+1;
            }
            fi(u, c1, c2-1) if (j != b[u].vt1 && j != b[u].vt2){xd[i] = 1; res++; break;}
            if (xd[i] == 1) break;
        }
    }
    cout << res;
}
