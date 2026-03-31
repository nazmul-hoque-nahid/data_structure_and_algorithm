#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&v,int i){
    int n=v.size();
    int left=i*2+1;
    int right=i*2+2;
    int smallest=i;
        if(left<n&&v[left]<v[smallest])smallest=left;
        if(right<n&&v[right]<v[smallest])smallest=right;
        if(smallest!=i){
            swap(v[smallest],v[i]);
            heapify(v,smallest);
        }
}
void deleteRoot(vector<int>&v){
if(v.empty())return;
v[0]=v[v.size()-1];
v.pop_back();
heapify(v,0);
}
void insert(vector<int>&v,int value){
    v.push_back(value);
    int i=v.size()-1;
    while(i!=0 && v[(i-1)/2]>v[i]){
        swap(v[(i-1)/2],v[i]);
         i=(i-1)/2;
    }
}
int main(){
vector<int>v={8,1,6,4,5,2,7};
int n=7;
for(int i=n/2-1;i>=0;i--){
    heapify(v,i);
}
deleteRoot(v);
insert(v,1);
for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}