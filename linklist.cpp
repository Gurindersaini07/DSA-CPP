#include<iostream>
using namespace std;

class SSL{
    private:
    struct node{
        int item;
        node *next;
    };
    node *start;
    public:

    //Constructer

    SSL(){
        start=NULL;
    }

    // Print Node Function

    void listprint(){
        node *temp=start;
        while(temp!=NULL){
            cout<<temp->item;
            temp=temp->next;
            cout<<",";
            }   
    }

    // Insert at First Function 

    int insertatfirst(int value){
        if(start==NULL){
            node *new_node=new node;
            start=new_node;
            new_node->item=value;
            new_node->next=NULL;
            return 0;
        }else{
            node *new_node=new node;
            new_node->item=value;
            new_node->next=start;
            start=new_node;
            return 0;
        }return 0;
    }

    //Insert at end

    int insertatend(int value){
        if(start==NULL){
            node *new_node=new node;
            start=new_node;
            new_node->item=value;
            new_node->next=NULL;
            return 0;
        }else{
            node *new_node=new node;
            new_node->item=value;
            new_node->next=NULL;
            node *temp=start;
            while(temp->next){
                temp=temp->next;
                }temp->next=new_node;
            }
        return 0;
    }

    //Insert after node

    int insertafternode(int nodeserchvalue, int value){
       node *new_node = new node;
       new_node->item=value;
       node *temp=start;
       while(temp->item!=nodeserchvalue){
        temp=temp->next;
       } 
       new_node->next =temp->next;
       temp->next=new_node;
       return 0;
    }

    //Delete First

    int deletefist(){
        start=start->next;
        return 0;
    }

    //Delete Last

    int deletelast(){
        node *temp;
        temp=start;
        if(start->next==NULL){
            start=NULL;
            return 0;
        }
        while(temp->next->next){
            temp=temp->next;
        }
        temp->next=NULL;
        return 0;
    }

    //Delete perticular Node/value

    int deleteperticularnode(int value){
        node *temp=start;
        if(start->item==value){
            start=start->next;
            return 0;
        }
        while(temp->next->item!=value){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return 0;
    }
};

int main(){
    int choice;
    SSL list1;
    while(true){
        system("CLS");
        list1.listprint();
        cout<<"\n1. Insert at first\n";
        cout<<"2. insert at end\n";
        cout<<"3. insert after node\n";
        cout<<"4. delete first\n";
        cout<<"5. delete last\n";
        cout<<"6. delete value\n";
        cout<<"-------------------------------------------\n";
        cout<<"enetr your choice:\n";
        cin>>choice;
        switch(choice){
            int value,deletevalue,searchvalue;
            case 1:
                cout<<"enter value:\n"; cin>>value;
                list1.insertatfirst(value);
                break;
            case 2:
                cout<<"enter value:\n"; cin>>value;
                list1.insertatend(value);
                break;
            case 3:
                cout<<"enter value:\n"; cin>>value;
                cout<<"enter search value:\n"; cin>>searchvalue;
                list1.insertafternode(searchvalue,value);
                break;
            case 4:
                list1.deletefist();
                break;
            case 5:
                list1.deletelast();
                break;
            case 6:
                cout<<"enter value you want to delete:\n"; cin>>deletevalue;
                list1.deleteperticularnode(deletevalue);
                break;
        }
    }
    return 0;
}