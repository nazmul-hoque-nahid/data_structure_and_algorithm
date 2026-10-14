#include <bits/stdc++.h>
using namespace std;
struct  Node
{
  int data;
  Node*next;
  Node(int data):data(data),next(nullptr){}
};
void addFirst(Node*&head,int data){
       Node*temp=new Node(data);
       temp->next=head;
       head=temp;
}
void addLast(Node*&head,int data){
  Node*temp=new Node(data);
  if(head==nullptr){
      head=temp;
      return;
  }
  Node*curr=head;
  while (curr->next!=nullptr)
  {
    curr=curr->next;
  }
  curr->next=temp;
  
}
void addAnyPos(Node*&head,int data,int pos){
  if(pos<0)return ;
  if(pos==0){
    Node*temp=new Node(data);
    temp->next=head;
    head=temp;
    return;
  }
  Node*curr=head;
  for(int i=0;i<pos-1;i++){
    if(curr==nullptr)return;
    curr=curr->next;
  }
  if(curr==nullptr)return;
  Node*temp=new Node(data);
  temp->next=curr->next;
  curr->next=temp;
}
void deleteFirst(Node*&head){
  if(head==nullptr)return;
  Node*temp=head;
  head=head->next;
  delete temp;
}
void deleteLast(Node*&head){
  if(head==nullptr)return;
  if(head->next==nullptr){
    Node*temp=head;
    head=head->next;
    delete temp;
    return;
  }
  Node*curr=head;
  while (curr->next->next!=nullptr)
  {
    curr=curr->next;
  }
  Node*temp=curr->next;
  curr->next=temp->next;
  delete temp;

}
void deleteAnyPos(Node*&head,int pos){
  if(pos<0 || head==nullptr)return;
  if(pos==0){
    Node*temp=head;
    head=head->next;
    delete temp;
    return;
  }
  Node*curr=head;
  for(int i=0;i<pos-1;i++){
    if(curr->next==nullptr)return;
    curr=curr->next;
  }
  if(curr->next==nullptr)return;
  Node*temp=curr->next;
  curr->next=temp->next;
  delete temp;
}
Node*reverse(Node*head){
      Node*prev=nullptr;
      Node*curr=head;
      while (curr!=nullptr)
      {
           Node*temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;
      }
      
      return prev;
}
int main(){
vector<int>v={44,31,7,65,49,87,56};
Node*head=nullptr;
Node*tail=nullptr;
for(int i=0;i<v.size();i++){
  Node*temp=new Node(v[i]);
  if(head==nullptr){
    head=temp;
    tail=temp;
  }else{
    tail->next=temp;
    tail=temp;
  }
}
//deleteAnyPos(head,0);
//addAnyPos(head,5444,2);
head=reverse(head);
while (head!=nullptr)
{
  cout<<head->data<<" ";
  head=head->next;
}

}
