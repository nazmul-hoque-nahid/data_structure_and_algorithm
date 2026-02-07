#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,e;
    cout<<"Enter the number of Node and Edge"<<endl;
    cin>>n>>e;
vector<vector<int>>v(n);
cout<<"Enter each two connected Nodes"<<endl;
while(e--){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
vector<int>visited(n+1,0);
queue<int>q;
int start;
cout<<"Enter starting Node"<<endl;
cin>>start;
q.push(start);
visited[start]=1;
while(!q.empty()){
    auto front_=q.front();
    cout<<front_<<" ";
    q.pop();
    for(auto child:v[front_]){
        if(visited[child]==0){
              visited[child]=1;
            q.push(child);
        }
    }
}
}
