#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

bool comp(const pair<int, int> &a,const pair<int, int> &b){
    return a.first<b.first;
}

pair<int, int> *p;
int main(){
    int n,d;
    cin>>n>>d;
    p=new pair<int, int>[n];
    for (int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        p[i]=make_pair(a, b);
    }
    sort(p, p+n, comp);
    
    ll m=LLONG_MIN;
    
    ll ans=0;
    int a=0,b=0;
    while (b<n) {
        while (a<n && (p[b].first+d)>p[a].first) {
            ans+=p[a].second;
            a++;
        }
        m=max(ans,m);
        ans-=p[b].second;
        b++;
    }
    cout<<m;
    return 0;
}