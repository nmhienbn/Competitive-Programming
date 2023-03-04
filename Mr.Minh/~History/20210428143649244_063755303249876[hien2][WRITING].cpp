#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "WRITING"
#define maxn 3005
#define maxm 3000005

using namespace std;

int n, m, dem1[59], dem2[59], res;
string s1, s2;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m >> s1 >> s2;
    fi(i, 0, n-1) dem1[s1[i]-64] ++;
    fi(i, 0, n-1) dem2[s2[i]-64] ++;
    int check = 1;
    fi(i, 1, 58) if (dem1[i] != dem2[i]) {check = 0; break;}
    res += check;
    fi(i, n, m-1){
        int c = s2[i]-64, d = s2[i-n]-64;
        dem2[c]++; dem2[d]--;
        int check = 1;
        fi(i, 1, 58) if (dem1[i] != dem2[i]) {check = 0; break;}
        res += check;
    }
    cout << res;
}
