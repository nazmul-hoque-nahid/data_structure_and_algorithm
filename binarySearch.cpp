#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>v,int n,int target){
int left=0,right=n-1,middle=0;
while(left<=right){
middle=(left+right)/2;
if(v[middle]==target)return middle+1;
else if(v[middle]<target)left=middle+1;
else right=middle-1;
}
return -1;
}
int main() {
cout<<"Enter size of array:";
int n;
cin>>n;
vector<int>v(n);
cout<<"Enter valure :"<<endl;
for(int i=0;i<n;i++)cin>>v[i];
cout<<"Enter target: ";
int target;
cin>>target;
int ans=binarySearch(v,n,target);
if(ans==-1)cout<<"Not found"<<endl;
else cout<<"Found at index: "<<ans<<endl;
}
