#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "main"
#define maxn

using namespace std;

bool antoan(string s){
    int a=0, b=0, c=0;
    for (int i=0; i < s.size(); i++){
        if (s[i] >= 'a' && s[i] <= 'z') a++;
        else if (s[i] >= 'A' && s[i] <= 'Z') b++;
        else if (s[i] >= '0' && s[i] <= '9') c++;
    }
    if (min(a, min(b, c))==0) return false;
    return true;
}
int res;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int n=s.length();
    s='*'+s;
    f(i, 1, n-5){
        int a=0, b=0, c=0;
        f(j, i, n){
            if (s[j] >= 'a' && s[j] <= 'z') a++;
            if (s[j] >= 'A' && s[j] <= 'Z') b++;
            if (s[j] >= '0' && s[j] <= '9') c++;
            if (min(a, min(b, c))>0 && j-i >= 5) {res+=n-j+1; break;}
        }
    }
    /*int d=0, c=s.size()-1;
    while (d<c-5){
        if (antoan(s)) res++;
        if (antoan(s.substr(d+1, c))) {res++; d++;}
        if (antoan(s.substr(d, c-1))) {res++; c--;}
    }*/
    cout << res;
}
