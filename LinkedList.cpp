#include <bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node*next;
};
void print(Node*head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int search(Node*head,int value){
    int i=1;
    while(head!=NULL){
        if(head->data==value)return i;
        i++;
        head=head->next;
    }
    return -1;
}
Node*reverse(Node*head){
Node*prev=NULL,*current=head,*next=NULL;
while(current!=NULL){
next=current->next;
current->next=prev;
prev=current;
current=next;
}
return prev;
}
Node*insertFirst(Node*head,int data){
Node*temp=new Node();
temp->data=data;
temp->next=head;
    head=temp;
    return head;
}
Node*insertLast(Node*head,int data){
    Node*temp=new Node();
    temp->data=data;
    temp->next=NULL;
    Node*current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;
    return head;
}
int main() {
Node *head=NULL,*temp=NULL,*current=NULL;
int a[6]={9,5,12,7,32,76};
for(int i=0;i<6;i++){
temp=new Node();
temp->data=a[i];
temp->next=NULL;
if(head==NULL){
head=temp;
current=temp;
}else{
 current->next=temp;
    current=temp;//or current=current->next;
}
}
/* int result=search(head,12);
if(result>0)cout<<"Found at "<<result;
else cout<<"Not found"; */

//head=reverse(head);
//head=insertFirst(head,55);
//head=insertLast(head,66);
print(head);
}