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
vector<int>visited(n+1,0);
vector<int>distance(n+1,INT_MAX);
int start;
cin>>start;
distance[start]=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,start});
while(!pq.empty()){
auto [w,top]=pq.top();
pq.pop();
if(visited[top])continue;
visited[top]=1;
for(auto [child,weight]:v[top]){
           if(distance[top]+weight<distance[child]){
            distance[child]=distance[top]+weight;
            pq.push({distance[child],child});
            }
}
}
for(int i=0;i<n;i++){
cout<<" Distance of "<<i<<" is "<<distance[i]<<" From "<<start<<endl;
}
}





