#include<bits/stdc++.h>

int main(){
std::string s;
std::cin>>s;
std::unordered_map<char,int>m;
int l=0,r=0,ans=0;
while(r<s.size()){
if(m[s[r]]==0){
m[s[r]]=r+1;
ans=std::max(ans,r-l+1);
}else{
    l=std::max(m[s[r]],l);
}
r++;
}
std::cout<<ans<<std::endl;
}