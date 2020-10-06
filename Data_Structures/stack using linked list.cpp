#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
node *top;
void push();
void peek();
void pop();
int main(){
    node *top;
    int choice;
    do{
        cout<<"Enter 1 for push\nEnter 2 for peek\nEnter 3 for pop\n";
        cout<<"Enter the choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                peek();
                break;
            case 3:
                pop();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }while(choice!=5);
}
void push(){
    int x;
    cout<<"Enter the value you want to push"<<endl;
    node *newnode=new node();
    cin>>x;
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void peek(){
    if(top==NULL){
        cout<<"Underflow condition"<<endl;
    }
    else{
        cout<<"The peek element is "<<top->data<<endl;
    }
}    
void pop(){
    node *temp;
    temp=top;
    if(top==NULL){
        cout<<"Undeflow condition"<<endl;
    }
    else{
        cout<<"The element "<<temp->data<< " is removed"<<endl;
        top=temp->next;
        delete temp;
    }
}

