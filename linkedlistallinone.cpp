#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	Node* next;
};


//singly linked list insert
void insert(Node **node, int data)
{
	Node *n = new Node();
	n->data = data;
	n->next = NULL;
	if((*node) == NULL)
	{
		(*node) = n;
	}
	else
	{
		Node *no = (*node);
		while(no->next != NULL)
		{
			no = no->next;
		}
		no->next = n;
	}
}


//Displaying singly lined list
void show(Node** node)
{
	if((*node) == NULL)
	{
		cout<<"List is empty";
	}
	else
	{
		Node* n = (*node);
		while(n != NULL)
		{
			cout<<n->data<<" ";
			n = n->next;
		}
	}
}


//getting size of lined list
int size(Node* node1)
{
	int count = 0;
	if(node1 == NULL)
	{
		return 0;
	}
	else
	{
		Node *n = node1;
		while(n != NULL)
		{
			count++;
			n = n->next;
		}
	}
	return count;
}


//reversing singly linked list using stack 
void reverseList(Node* node1)
{
	stack<int> s;
	if(node1 == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		Node* n1 = node1;
		while(n1 != NULL)
		{
			s.push(n1->data);
			n1 = n1->next;
		}
	}
	cout<<"\nReverse of linked list is:"<<endl;
	for(int i=0 ;i <size(node1); i++)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

//traversing circular linked list
void traverse(Node *last) 
{ 
    Node *p; 

    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    p = last -> next; 
   
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
  
    } 
    while(p != last->next); 
  
}


//Adding element at first in circular linked list
void circularLinkedListAddFirst(Node **node1, int data)
{
	Node* temp = new Node();
	temp->data = data;
	if(*node1 == NULL)
	{
		(*node1) = temp;
		((*node1)->next) = (*node1);
	}
	else
	{
		temp->next = (*node1)->next;
		(*node1)->next = temp;
	}
}

//Adding element at last in circular linked list
void circularLinkedListAddLast(Node** node1, int data)
{
	Node* temp = new Node();
	temp->data = data;
	if(*node1 == NULL)
	{
		(*node1) = temp;
		((*node1)->next) = (*node1);
	}
	else
	{

		temp->next = (*node1)->next;
		(*node1)->next = temp;
		(*node1) = temp;
	}
}

//Adding element after a value in linked list
void addAfter(Node **last, int data, int item) 
{ 
    if (last == NULL) 
       cout<<"List is empty"; 
    Node *temp, *p; 
    p = (*last)->next; 
    do
    { 

        if (p ->data == item) 
        { 
            temp = new Node(); 
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp; 
 
            if (p == (*last)) 
                (*last) = temp; 
        }

        p = p -> next; 

    } while (p != (*last)->next);  
} 


//sum of two linked list
void add(Node* node1, Node* node2)
{
	int sum = 0;
	int carry = 0;
	Node *temp = NULL;
	while((node1 != NULL) || (node2 != NULL) || (carry == 1))
	{
		
		sum = carry + (node1 ? node1->data : 0) + (node2 ? node2->data : 0);
		carry = (sum>=10) ? 1 : 0;
		if(node1)
		{
			node1 = node1->next;
		}
		if(node2)
		{
			node2 = node2->next;
		}
		sum = sum%10;
		insert(&temp, sum);	
	}
	cout<<"\nSum of two list is:"<<endl;
	show(&temp);
	cout<<endl;
}

Node* insertAftersinglyLinkedList(Node* head, int data, int item)
{
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		Node* temp = new Node();
		temp->data = data;
		Node* p = head;
		while(p != NULL)
		{
			if(p->data == item)
			{
				temp->next = p->next;
				p->next = temp;
				return head;
			}
			p = p->next;
		}
		
	}
	cout<<"Item is not present in list to add it after the value"<<endl;
	return head; 
	
}


int main()
{
	Node *first = NULL;
	Node *second = NULL;
	Node*circular = NULL;
	
	insert(&first, 9);
	insert(&first, 8);
	insert(&first, 7);
	insert(&first, 6);
	insert(&first, 5);
	insert(&first, 4);
	insert(&first, 5);
	cout<<"First List:"<<endl;
	show(&first);
	cout<<"\n";
	
	insert(&second, 3);
	insert(&second, 4);
	insert(&second, 5);
	insert(&second, 7);
	insert(&second, 5);
	insert(&second, 9);
	
	//insertAftersinglyLinkedList(second, 2, 9);
	
	cout<<"\nSecond List:"<<endl;
	show(&second);
	cout<<"\n";
	
	add(first,second);

	cout<<"\nSize of first linked list is:"<<endl;
	cout<<size(first)<<"\n";

	reverseList(first);
	cout<<"\n";

	circularLinkedListAddFirst(&circular, 11);
	circularLinkedListAddFirst(&circular, 22);
	circularLinkedListAddFirst(&circular, 33);

	circularLinkedListAddLast(&circular, 4);
	circularLinkedListAddLast(&circular, 5);
	circularLinkedListAddLast(&circular, 6);
	
	addAfter(&circular, 44, 4);

	cout<<"\nCircular List:"<<endl;
	traverse(circular);
	
	cout<<"\n";
}