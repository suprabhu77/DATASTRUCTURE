#include<iostream>
#include<string>
using namespace std;


class Stack{
      public:
          int top;
          int arr[5];
      public:
      Stack ()
      {
          top = -1;
          for(int i=0;i<=4;i++)
              {arr[i]=0;}

      }
      bool isEmpty()
      {
          if(top ==-1)
            return true;
          else
            return false;
      }
       bool isFull()
       {
           if(top==4)
             return true;
           else
            return false;
       }

       void push(int val)
       {
         if(isFull())
         {
             cout<<"stack isoverflow"<<endl;
         }
         else
         {
             top = top + 1;
             printf("%d",top);
             arr[top]=val;
         }
       }
       int pop()
       {
           if(isEmpty())
           {
               cout<<"stack is underflow"<<endl;
               return 0;
           }
           else
           {
              int position1 = arr[top];
               arr[top]=0;
               top--;
               return(position1);
           }
       }
       void change(int pos,int val)
       {
           {
               arr[pos]=val;
           }
       }

       void display()
       {
            int i;
             for(i=0;i<5;i++)
              cout<<arr[i]<<endl;
       }

       int cont()
       {
           return(top+1);
       }

       int peek(int pos)
       { if(isEmpty())
           {
           cout<<"stack underflow"<<endl;
           return 0;
           }
          else
            {
                return(arr[pos]);

            }
       }



};
int main()
{
    Stack s;
    int position,value,option;
    do
        { cout<<"Enter the corresponding option to perform the task\n also press 0 to exit"<<endl;
        cout<<"1. push()"<<endl;
        cout<<"2. pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. change()"<<endl;
        cout<<"6. cont()"<<endl;
        cout<<"7. peek"<<endl;
        cout<<"8. display()"<<endl;
        cout<<"9. clear screen"<<endl;
        cin>>option;
        switch(option)
        {
        case 0:
              break;
        case 1:
              cout<<"Enter the element to be pushed"<<endl;
              cin>>value;
              s.push(value);
              break;
        case 2:
              cout<<"The element on the top is "<<s.pop()<<endl;
              break;
        case 3:
              if(s.isEmpty())
                cout<<"The stack is empty"<<endl;
              else
                cout<<"The stack is not empty"<<endl;
              break;
        case 4:
              if(s.isFull())
                cout<<"The stack is full"<<endl;
              else
                cout<<"The stack is  not full"<<endl;
              break;
        case 5:
              cout<<"Enter the position of an element to be changed"<<endl;
              cin>>position;
              cout<<"Enter the value of an element to be changed"<<endl;
              cin>>value;
              s.change(position,value);
              break;
        case 6:
               cout<<"the total count "<<s.cont()<<endl;
               break;
        case 7:
               cout<<"enter the position of an element to be peak"<<endl;
               cin>>position;
               cout<<"the elment at position"<<s.peek(position)<<endl;
               break;
        case 8: cout<<"display function called"<<endl;
               s.display();
               break;
        case 9:
               system("cls");
               break;
        default:
               cout<<"enter the valid option"<<endl;
        }
    }while(option!=0);
    return 0;
}