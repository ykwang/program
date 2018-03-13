
#include"list.h"



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
	Node ** p=&head;
	Node * q=head;
	while(*p)
	{
		q=(*p)->next;
		delete *p;
		*p=q;
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
	Node * temp=new Node;
	
	
}
template<typename T>
bool List<T>::List_pop(const T & val)
{
	
}

template<typename T>
bool List<T>::List_append(List<T>& ls)
{
	
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
	return *this;
}