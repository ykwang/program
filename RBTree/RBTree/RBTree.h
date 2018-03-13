#ifndef RBTREE_H_
#define RBTREE_H_


#define BLACK 1
#define RED 0

class RBTree{
private:
	struct node{
		int value;
		bool color;
	    struct node *parent,*left,*right;
		node(){
			value=0;
			parent=0;
			left=0;
			right=0;
			color=RED;
		}
		struct node *grandparent(){
			if(parent!=NULL)
				ruturn parent->parent;
			else
				return NULL;
		}
		struct node *uncle(){
			if(grandparent()==NULL)
				return NULL;
			else if(parent==grandparent()->left)
				return grandparent()->right;
			else
				return grandparent()->left;
		}


	};
	
public:

}
#endif