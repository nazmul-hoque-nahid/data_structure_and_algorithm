#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&v,int n,int target){
int left=0,right=n-1,middle=0;
while(left<=right){
middle=(left+right)/2;
if(v[middle]==target)return middle;
else if(v[middle]<target)left=middle+1;
else right=middle-1;
}
return -1;
}
int firstOccurance(vector<int>&v,int n,int target){
    int left=0,right=n-1,middle=0;
    int result=-1;
    while(left<=right){
        middle=(left+right)/2;
        if(v[middle]==target){
            result=middle;
            right=middle-1;
        }else if(v[middle]<target)left=middle+1;
        else right=middle-1;
    }
    return result;
}
int lastOccurance(vector<int>&v,int n,int target){
    int left=0,right=n-1,middle=0;
    int result=-1;
    while(left<=right){
        middle=(left+right)/2;
        if(v[middle]==target){
            result=middle;
            left=middle+1;
        }else if(v[middle]<target)left=middle+1;
        else right=middle-1;
    }
    return result;
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
else cout<<"Found at index: "<<ans+1<<endl;

 ans=firstOccurance(v,n,target);
if(ans==-1)cout<<"Not found"<<endl;
else cout<<"First Occurance at index: "<<ans+1<<endl;

 ans=lastOccurance(v,n,target);
if(ans==-1)cout<<"Not found"<<endl;
else cout<<"Last Occurance at index: "<<ans+1<<endl;
}
