#include <bits/stdc++.h>
using namespace std;
struct TrieNode{
    bool endWord;
    char ch;
    TrieNode* children[26];
    TrieNode(char ch){
        endWord=false;
        ch=ch;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
void insert(struct TrieNode*root,string word){
     TrieNode* crawler = root;
    for (char ch : word) {
        int ind = ch - 'a';
        if (crawler->children[ind]==nullptr) {
            crawler->children[ind]=new TrieNode(ch);
        }
        crawler=crawler->children[ind];
    }
    crawler->endWord=true;
}
bool search(struct TrieNode*root,string word) {
       TrieNode* crawler = root;
    for (char ch : word) {
        int ind = ch - 'a';
        if (crawler->children[ind]==nullptr) {
            return false;
        }
        cout<<ch<<" ";
        crawler = crawler->children[ind];
    }
    if (crawler!=nullptr && crawler->endWord==true)return true;
    else return false;
}
bool startWith(struct TrieNode*root,string word){
       int i;
TrieNode*crawler=root;
for( i=0;i<word.size();i++){
       char ch=word[i];
       int ind=ch-'a';
       if(crawler->children[ind]==nullptr)return false;
       crawler=crawler->children[ind];
}
if(i==word.size())return true;
return false;
}
int main(){
 TrieNode* root = new TrieNode('#'); // Initialize the root node
    insert(root,"apple");
    insert(root,"india");
    insert(root,"bangladesh");
   insert(root,"indana") ;
   // if(startWith(root,"indana"))cout<<"YES";
    //else cout<<"NO";
    cout<<search(root,"india");
}
/*
struct node{
    char data;
    node*child[5];
    node(char data):data(data){
        for(int i=0;i<5;i++){
            child[i]=nullptr;
        }
    }
};
int main() {
node*root=new node('#');
root->child[0]=new node('a');
cout<<root->child[0]->data;
}
*/