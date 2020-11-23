#include<iostream>
using namespace std;

class Queue{
   private:
       int frnt;
       int rear;
       int arr[4];
   public:
       Queue()
       {
           rear = -1;
           frnt = -1;
           for(int i=0;i<5;i++)
            arr[i]=0;
       }
       bool isEmpty()
       {
           if(frnt==-1&&rear==-1)
             return true;
           else
            return false;
       }
       bool isFull()
       {
           if(rear==3)
             return true;
           else
            return false;
       }

       void Enqueue(int val)
       {
           if(isFull())
              {
                  cout<<"stack is full "<<endl;
            }
            else if(isEmpty())
            {
                rear=frnt=0;
            }
            else
            {
                rear++;
            }
            arr[rear]=val;
       }

       int Dequeue()
       {   int x;
           if(isEmpty())
           {
               cout<<"stack is empty";
               return 0;
           }
           else if(frnt==rear)
           {   x=arr[frnt];
               arr[frnt]=0;
               frnt=rear=-1;
               return x;
           }
           else
           {   x=arr[frnt];
               arr[frnt]= 0;
               frnt++;
               return x;
           }
       }
       int cont()
       {
           return(rear-frnt+1);
       }

       void display()
       {   cout<<"display function called"<<endl;
           for(int i=0;i<4;i++)
              cout<<arr[i]<<endl;;
       }

};

int main()
{
    Queue q1;
    int option,value;
    do{ cout<<"Enter the corresponding option to perform the task\n also press 0 to exit"<<endl;
        cout<<"1. Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. cont()"<<endl;
        cout<<"6. Display()"<<endl;
        cout<<"7. clear screen"<<endl;
        cin>>option;
        switch(option)
        {
        case 0:
              break;
        case 1:
              cout<<"Enter the element to be Enque"<<endl;
              cin>>value;
              q1.Enqueue(value);
              break;
        case 2:
              cout<<"The element on the top is "<<q1.Dequeue()<<endl;
              break;
        case 3:
              if(q1.isEmpty())
                cout<<"The queue is empty"<<endl;
              else
                cout<<"The queue is not empty"<<endl;
              break;
        case 4:
              if(q1.isFull())
                cout<<"The Queue is full"<<endl;
              else
                cout<<"The queue is  not full"<<endl;
              break;
        case 5:
               cout<<"the total count "<<q1.cont()<<endl;
               break;
        case 6: cout<<"display function called"<<endl;
               q1.display();
               break;
        case 7:
               system("cls");
               break;
        default:
               cout<<"enter the valid option"<<endl;
        }


       }while(option!=0);
}