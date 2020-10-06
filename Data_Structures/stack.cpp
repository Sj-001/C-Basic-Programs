#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
    int a[10];
    int top=-1;
    void push();
    void pop();
    void peek();
    void display();
};
void Stack::push(){
    int x;
    if(top>=9){
        cout<<"overflow condition"<<endl;
    }
    else{
        cout<<"enter element to be pushed: ";
        cin>>x;
        a[++top]=x;
        cout<<x<<" pushed in the stack."<<endl;
    }
}
void Stack::pop(){
    if(top==-1){
        cout<<"underflow condition"<<endl;
    }
    else{
        --top;
    }
    cout<<"top element removed"<<endl;
}
void Stack::peek(){
    cout<<"topmost element is:"<<a[top]<<endl;
}
void Stack::display(){
    cout<<"stack elements are: ";
    for(int i=0;i<=top;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
  Stack s;
  int ch;
  do{
    cout<<"enter choice: ";
    cin>>ch;
    switch(ch){
    case 1: s.push();
     break;
    case 2: s.pop();
    break;
    case 3: s.peek();
    break;
    case 4:s.display();
     break;
    default:
        cout<<"Invalid choice"<<endl;
    }
  }while(ch!=0);
}

