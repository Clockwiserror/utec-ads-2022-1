#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data_in, Node *next_in,Node *prev_in)
    {
        this->data = data_in;
		this->next = next_in;
        this->prev = prev_in;
    }
};
struct List{
    Node *tail;
    Node *newdata;
    Node *head;
    public:
        List(){};
        int count = 0;
        void append(int data){
            if (count != 0){
            newdata = new Node(data,NULL,tail);
            tail->next = newdata;
            tail = newdata;
            }
            else{
                tail = new Node(data,NULL,NULL);
                head=tail;
            }
            count +=1;
        }
        void addfront(int data){
            if (count != 0){
            newdata = new Node(data,head,NULL);
            head = newdata;
            }
            else{
                head = new Node(data,NULL,NULL);
                tail=head;
            }
            count +=1;
        }
        void print(){
            Node *it;
            for (it=head;it!=NULL;it= it->next)
            {
                cout << it->data << " "; 
            }
            cout << endl;
        }
        void pop(){
            Node *delete_node;
            delete_node = tail;
            this->tail = tail->prev;
            delete delete_node;
            tail->next=NULL;
        }
};
int main(){
	List l;
    for (int i = 0; i<=10; i++ )
    {
        l.append(i);
        l.addfront(2*i);
    }

    l.print();

    for (int i = 0; i<=4; i++ )
    {
        l.pop();
    }
	
    l.print();
	return 0;
}





