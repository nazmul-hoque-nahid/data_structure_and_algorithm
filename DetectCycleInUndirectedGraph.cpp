//Detect Cycle in Undirected Graph.Nodes must be 0 based and number
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>&v,vector<int>&vis,int node,int par){
	    vis[node]=1;
	    for(auto child:v[node]){
		if(!vis[child]){
		if(dfs(v,vis,child,node))return true;
		}else{
		if(child!=par)return true;
		}
	    }
	    return false;
}
int main(){
	int n,e;
	cin>>n>>e;
          vector<vector<int>>v(n);
          while(e--){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
          }
          vector<int>vis(n,0);
  if(dfs(v,vis,0,-1))cout<<" There has a Cycle";
  else cout<<"There is no Cycle";

}
