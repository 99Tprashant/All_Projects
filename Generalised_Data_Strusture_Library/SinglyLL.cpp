//Singly Linear linked list with oop in generic way

#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
};

template<class T>
class SinglyLL
{
	public:
		struct node<T> *head;
		int count;
		
		SinglyLL();
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
	SinglyLL<T>::SinglyLL()
	{
		head = NULL;
		count = 0;
	}

	template<class T>
	void SinglyLL<T>::InsertFirst(T no)
	{
		struct node<T> *newn = NULL;
		newn = new node<T>;

		newn->data = no ;
		newn->next = NULL;
	
		if(head == NULL)
		{
			head = newn;
		}
			else
		{
			newn->next = head;
			head = newn;
		}
		count++;
	}
	template<class T>
	void SinglyLL<T>::InsertLast(T no)
	{
		struct node<T> *newn = NULL;
		newn = new node<T>;

		newn->data = no ;
		newn->next = NULL;
	
		if(head == NULL)
		{
			head = newn;
		}
		else
		{
			struct node<T> *temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
		}
		count++;
	}

	template<class T>
	void SinglyLL<T>::Display()
	{
		cout<<"Elements in linked list are:"<<endl;
		struct node<T> *temp =head;
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|->"<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

	template<class T>
	int SinglyLL<T>::CountNode()
	{
		return count;
	}
	
	template<class T>
	void SinglyLL<T>::DeleteFirst()
	{
		if(head==NULL)
		{
			delete head;
		}
		else if(head->next==NULL)
		{
			struct node<T> *temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			struct node<T> *temp = head;
			head = head->next;
			delete temp;
		}
		count--;
	}

	template<class T>
	void SinglyLL<T>::DeleteLast()
	{
		if(head == NULL)
		{
			delete head;
		}
		else if(head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			int iCnt = 0;
			struct node<T> *temp = head;
			
			while(temp->next->next!=NULL)
			{
				temp = temp->next;
			}
			
			delete (temp->next);
			temp->next=NULL;
		}
		count--;
	}
	
	template<class T>
	void SinglyLL<T>::InsertAtPos(T no,int pos)
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
			
			newn-> next = temp -> next;
			temp -> next = newn;		
		}
		count++;
	}
	template<class T>
	void SinglyLL<T>::DeleteAtPos(int pos)
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
			delete Deltemp;
		}
		
		count--;
	}
	
int main()
{
	SinglyLL<int>obj1;
	SinglyLL<float>obj2;
	
	obj1.InsertLast(21);
	obj1.InsertFirst(11);
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
	
	obj1.InsertAtPos(71,5);
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteAtPos(5);
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj2.InsertFirst(21.11);
	obj2.InsertLast(11.11);
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