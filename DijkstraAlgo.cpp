#include <bits/stdc++.h>
using namespace std;
int main() {
int n,e;
cin>>n>>e;
vector<vector<pair<int,int>>>v(n);
while(e--){
int x,y,w;
cin>>x>>y>>w;
v[x].push_back({y,w});
}
int start;
cin>>start;
vector<int>dis(n,INT_MAX);
vector<int>vis(n,0);
dis[start]=0;
for(int propagate=0;propagate<n;propagate++){
int Min=INT_MAX,index=-1;
for(int i=0;i<n;i++){
if(dis[i]<Min && vis[i]==0){
Min=dis[i];
index=i;
}
}
if(index==-1)break;
vis[index]=1;
for(auto [child,weight]:v[index]){
              if(dis[index]+weight<dis[child] && dis[index] != INT_MAX ){
                             dis[child]=dis[index]+weight;
              }
}
}
for(int i=0;i<n;i++)cout<<dis[i]<<" "<<i<<endl;
}
