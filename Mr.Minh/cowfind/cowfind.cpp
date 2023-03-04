#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cowfind"
const int maxn = 100005;
using namespace std;

string s;
int a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    int n = s.length();
    int sl = 0;
    fi (i, 1, n-1){
         if (s[i] == '(' && s[i-1] == '(') a[++sl] = 1;
         if (s[i] == ')' && s[i-1] == ')') a[++sl] = 2;
    }
    int dem = 0;
    fi (i, 1, sl)
        if ( a[i] == 1){
            fi (j, i, sl) if (a[j] == 2) dem ++;
        }
    cout << dem ;
}
