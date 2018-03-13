#ifndef LIST_H_
#define LIST_H_
#include<assert.h>
#include<iostream>

template<typename T>
class List {
private:
	 struct Node{T val;Node * next;}* head;
		
public:
	 List();
	~List();

	bool isemply() const;
	bool List_push(const T val);
	bool List_pop( T & va);
	bool List_reverse();
	bool List_append(List& ls);

	List(const List& ls);
	List & operator=(const List& ls);
	

};

template<typename T>
List<T>::List()
{
	head=new Node;
	head->next=NULL;
	head->val=NULL;	
}
template<typename T>
List<T>::~List()
{
	Node * *p=&head;
	Node * q;
	while(*p)
	{
		q=(*p)->next;
		delete *p;
		p=&q;
	}
	
}
template<typename T>
bool List<T>::isemply() const
{
	return head==NULL;
}
template<typename T>
bool List<T>::List_push(const T val)
{
	if(head->val)
	{
		Node * temp=new Node;
		temp->val=val;
		temp->next=head;
		head=temp;
		return true;
	}
	else
	{
		head->val=val;
		return true;
	}	
	
}
template<typename T>
bool List<T>::List_pop( T & va)
{
	assert(head);
	Node * p=head;
	va=p->val;
	head=p->next;
    p=NULL;
	return true;
}

template<typename T>
bool List<T>::List_append(List<T>& ls)
{
	assert(ls);
	Node** p=&head;
	while(*p)
		p=&(*p)->next;
	*p=ls.head;
	return true;

}
template<typename T>
bool List<T>:: List_reverse()
{
	assert(head);
	Node * list=NULL,*rest;
	while(head)
	{
		rest=head->next;
		head->next=list;
		list=head;
		head=rest;
	}
	head=list;
	return true;
}
template<typename T>
List<T>::List(const List<T>& ls)
{
	assert(ls);
	Node** p=&head;
	Node* q=ls.head;
	while(q)
	{
		*p=new Node;
		(*p)->val=q->val;
		p=&(*p->next)
		q=q->next;
	}
	
}

template<typename T>
List<T> & List<T>::operator=(const List<T>& ls)
{
	//assert(ls);
	head=new Node;
	Node** p=&head;
	Node* q=ls.head;
	while(q)
	{
		*p=new Node;
		(*p)->val=q->val;
		p=&(*p)->next;
		q=q->next;
	}
	return *this;
}


#endif