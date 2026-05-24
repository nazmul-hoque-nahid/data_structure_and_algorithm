#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&v,int i,int n){
    //heapify Down
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;

    if(left<n && v[left]<v[smallest]) smallest=left;
    if(right<n && v[right]<v[smallest]) smallest=right;

    if(smallest!=i){
        swap(v[i],v[smallest]);
        heapify(v,smallest,n);
    }
}
void deleteRoot(vector<int>&v){
    if(v.empty()) return;
    if(v.size() == 1){
        v.pop_back();
        return;
    }
    v[0] = v.back();
    v.pop_back();
    heapify(v, 0,v.size());
}
void insert(vector<int>&v,int value){
    //Heapify Up 
    v.push_back(value);
    int i=v.size()-1;
    while(i!=0 && v[(i-1)/2]>v[i]){
        swap(v[(i-1)/2],v[i]);
         i=(i-1)/2;
    }
}
int main(){
vector<int>v={8,1,6,4,5,2,7};
int n=v.size();
for(int i=n/2-1;i>=0;i--){
    heapify(v,i,n);
}
deleteRoot(v);
insert(v,1);
for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}
