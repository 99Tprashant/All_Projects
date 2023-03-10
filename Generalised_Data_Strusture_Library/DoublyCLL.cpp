//Doubly circular linked list with oop in generic way

#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
	struct node *prev;
};

template<class T>
class DoublyCLL
{
	public:
		struct node<T> *head;
		struct node<T> *tail;
		int count;
		
		DoublyCLL();
		void InsertFirst(T);
		void InsertLast(T);
		void Display();
		int CountNode();
		void DeleteFirst();
		void DeleteLast();
		void InsertAtPos(T,int);
		void DeleteAtPos(int);
};
	template<class T>
	DoublyCLL<T>::DoublyCLL()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	template<class T>
	void DoublyCLL<T>::InsertFirst(T no)
	{
		struct node<T> *newn = NULL;
		newn = new node<T>;

		newn->data = no ;
		newn->next = NULL;
		newn->prev = NULL;
	
		if((head == NULL )&& (tail == NULL))
		{
			head = newn;
			tail = newn;
		}
		else
		{
			newn->next = head;
			newn->prev = tail;
			head->prev = newn;
			head = newn;
			tail->next = newn;
		}
		count++;
	}
	template<class T>
	void DoublyCLL<T>::InsertLast(T no)
	{
		struct node<T> *newn = NULL;
		newn = new node<T>;

		newn->data = no ;
		newn->next = NULL;
		newn->prev = NULL;
	
		if((head == NULL )&& (tail == NULL))
		{
			head = newn;
			tail = newn;
		}
		else
		{
			tail -> next = newn;
			newn -> prev = tail;
			tail = newn;
			head -> prev = tail;
		}
		tail -> next = head; 
		
		count++;
	}

	template<class T>
	void DoublyCLL<T>::Display()
	{
		cout<<"Elements in linked list are:"<<endl;
		struct node<T> *temp =head;
		do
		{
			cout<<"|"<<temp->data<<"|->"<<" ";
			temp=temp->next;
		}while(temp!=head);
		cout<<endl;
	}

	template<class T>
	int DoublyCLL<T>::CountNode()
	{
		return count;
	}
	
	template<class T>
	void DoublyCLL<T>::DeleteFirst()
	{
		if((head==NULL)&&(tail = NULL))
		{
			delete head;
			delete tail;
		}
		else if(head==tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head -> next;
			delete tail->next;
			tail -> next = head;
			head -> prev = tail;
		}
		count--;
	}

	template<class T>
	void DoublyCLL<T>::DeleteLast()
	{
		if((head == NULL)&&(tail == NULL))
		{
			return;
		}
		else if(head == tail)
		{
			delete tail;
			head = NULL;
			tail = NULL;
		}
		else
		{
			struct node<T> *temp = head;
			while(temp->next != tail)
			{
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail -> next = head;
			head -> prev = tail;
		}
		count--;
	}
	
	template<class T>
	void DoublyCLL<T>::InsertAtPos(T no,int pos)
	{
		int Size = CountNode();
		if(pos < 1 || pos >(Size+1))
		{
			cout<<"your entered position is invalide"<<endl;
		}
		else if(pos == 1)
		{
			InsertFirst( no);
		}
		else if(pos == (Size+1))
		{
			InsertLast( no);
		}
		else
		{
			struct node<T> *newn = NULL;
			newn = new node<T>;

			newn->data = no ;
			newn->next = NULL;
			
			struct node<T> *temp = head;
			
			for(int iCnt = 1; iCnt < pos-1;iCnt++)
			{
				temp = temp -> next; 
			}
			
			temp -> next -> prev = newn;
			newn -> next = temp -> next;
			newn -> prev = temp;
			temp -> next = newn;		
		}
		count++;
	}

	template<class T>
	void DoublyCLL<T>::DeleteAtPos(int pos)
	{
		int Size = CountNode();
		if(pos < 1 || pos >(Size+1))
		{
			cout<<"your entered position is invalide"<<endl;
		}
		else if(pos == 1)
		{
			DeleteFirst();
		}
		else if(pos == Size)
		{
			DeleteLast();
		}
		else
		{
			struct node<T> *temp = head;
			struct node<T> *Deltemp = NULL;
			for(int iCnt = 1; iCnt < pos-1;iCnt++)
			{
				temp = temp -> next; 
			}
			Deltemp = temp -> next;
			temp -> next =  temp -> next -> next;
			temp -> next -> prev = temp;
			delete Deltemp;
		}
		
		count--;
	}
	
int main()
{
	DoublyCLL<int>obj1;
	DoublyCLL<float>obj2;
	
	obj1.InsertFirst(21);
	obj1.InsertLast(11);
	obj1.InsertFirst(51);
	obj1.InsertFirst(101);
	obj1.InsertFirst(111);
	obj1.InsertFirst(121);
	obj1.InsertFirst(151);
	obj1.InsertFirst(171);
	
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteFirst();
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteLast();
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.InsertAtPos(71,2);
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteAtPos(5);
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj2.InsertFirst(21.11);
	obj2.InsertFirst(11.11);
	obj2.InsertFirst(51.11);
	obj2.InsertFirst(101.11);
	obj2.InsertFirst(121.21);
	obj2.InsertFirst(151.31);
	obj2.InsertFirst(171.41);
	
	obj2.Display();
	cout<<"number of nodes are:"<<obj2.CountNode()<<endl;
	
	obj2.InsertAtPos(71.5,5);
	obj2.Display();
	cout<<"number of nodes are:"<<obj2.CountNode()<<endl;
	
	obj2.DeleteAtPos(5);
	obj2.Display();
	cout<<"number of nodes are:"<<obj2.CountNode()<<endl;
	

	
	return 0;
}