#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    int key;
    Node* next;
    Node()
    {
      data = 0;
      key = 0;
    }
};

class singlelinkedlist{
    public:
    Node* head;
    singlelinkedlist(){
        head = NULL;
    }
    Node* NodeExist(int k){
        Node * temp = NULL;
        Node * ptr = head;
        while (ptr!= NULL)
        {       
            if(ptr->key==k){
                temp = ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    void appendNode(Node * n){
        if(NodeExist(n->key)!=NULL){
            cout<<"The Node is already exist with that key"<<n->key<<endl;
        }
        else if(head ==NULL){
            head = n;
        }
        else
        {
            Node * temp = head;
            while(temp!=NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
        
    }
    void prependNode(Node*n){
        if(NodeExist(n->key)!=NULL){
            cout<<"The Node is already exist with that key"<<n->key<<endl;
        }
        else{
            
            n->next=head;
            head = n;

        }
    }
    void insertNodeAfter(int k, Node * n){
        Node * temp = NodeExist(k);
        if(temp==NULL){
            cout<<"No Node exist with the value"<< k;
        }
        else if(NodeExist(n->key)!=NULL){
            cout<<"Node with Key"<<n->key << "aklready exist";
        }
        else
        {
            n->next = temp->next;
            temp->next= n;
            cout<<"Node inserted";
        }
        
    }
     void deleteNodeByKey(int k) {
    if (head == NULL) {
      cout << "Singly Linked List already Empty. Cant delete" << endl;
    } else if (head != NULL) {
      if (head -> key == k) {
        head = head -> next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        } else {
          cout << "Node Doesn't exist with key value : " << k << endl;
        }
      }
    }
 
  }
  void updateNodeByKey(int k, int d) {
 
    Node * ptr = NodeExist(k);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }
 
  }

  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;
 
      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }
 
  }

};
int main() {
 
  singlelinkedlist s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
 
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;
 
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
 
      s.insertNodeAfter(k1, n1);
      break;
 
    case 4:
 
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);
 
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);
 
      break;
    case 6:
      s.printList();
 
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}