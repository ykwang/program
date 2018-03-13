//普通二叉搜索树
#include<stdio.h>
#include<stdlib.h>
struct BSTreeNode
{
	int v_key;
	BSTreeNode * lchild;
	BSTreeNode * rchild;
	BSTreeNode * prefather;
};
void inorderTreeWalk(BSTreeNode * pNode)
{
	if(pNode)
	{
		if(pNode->lchild!=NULL)
			inorderTreeWalk(pNode->lchild);
		printf("%d\n",pNode->v_key);;
		inorderTreeWalk(pNode->rchild);
	}
	
}
void preorderTreeWalk(BSTreeNode * pNode)
{
	if(pNode)
	{
	    printf("%d\n",pNode->v_key);;
		preorderTreeWalk(pNode->lchild);
		preorderTreeWalk(pNode->rchild);
	}
}
void postorderTreeWalk(BSTreeNode*pNode)
{
	if(pNode)
	{
		postorderTreeWalk(pNode->lchild);
		postorderTreeWalk(pNode->rchild);
		printf("%d\n",pNode->v_key);
	}
}
BSTreeNode* TreeSearch(BSTreeNode*pNode,int k)
{
	while(pNode!=NULL&&pNode->v_key!=k)
	{
		if(pNode->v_key>k)
			pNode=pNode->lchild;
		else
			pNode=pNode->rchild;
	}
	if(pNode)
		return pNode;
	else
		return NULL;
}
BSTreeNode* TreeMinimum(BSTreeNode*pNode)
{
	while(pNode->lchild)
		pNode=pNode->lchild;
	return pNode;
}
BSTreeNode* TreeMaximum(BSTreeNode*pNode)
{
	while(pNode->rchild!=NULL)
		pNode=pNode->rchild;
	return pNode;
}
//二叉树结点的后继是中序遍历的后一数值
BSTreeNode*TreeSuccessor(BSTreeNode*pNode)
{

	BSTreeNode*qNode;
	qNode=pNode->prefather;
	if(pNode->rchild){
		pNode=pNode->rchild;
		while(pNode->lchild!=NULL)
			pNode=pNode->lchild;
		return pNode;
		}
	else
	{
//当该结点没有右子结点，有一结点是根结点的左子结点时，该结点的根结点即为所求后继
	//该结点有左孩子结点时，即为后继	
		while(qNode->lchild!=NULL)
			{
				pNode=qNode;
				qNode=qNode->prefather;
				
			}
		return qNode;
	}
}
//二叉树节点的前驱是中序遍历的前一数值
BSTreeNode*TreePrecursor(BSTreeNode*pNode)
{
	BSTreeNode*qNode;
	qNode=pNode->prefather;
	if(pNode->lchild){
		pNode=pNode->lchild;
		while(pNode->rchild!=NULL)
			pNode=pNode->rchild;
		return pNode;
	}
	else
	{
//当该结点没左子结点，有一结点是根结点的右子结点时，该结点的根结点即为所求前驱
		//即一结点有右孩子的结点即为前驱
		while(qNode->lchild==pNode&&qNode!=NULL)
		{
			pNode=qNode;
			qNode=qNode->prefather;
			
		}
		return qNode;
	}
}

void TreeInsert(BSTreeNode**root,BSTreeNode* k)
{
	BSTreeNode*x=*root;
	BSTreeNode*y=NULL;
	while(x)
	{
		y=x;
		if(k->v_key<=x->v_key)
			x=x->lchild;
		else
			x=x->rchild;
	}
	k->prefather=y;
	if(y==NULL)
		*root=k;
	else if(k->v_key<=y->v_key)
		y->lchild=k;
	else
		y->rchild=k;
	
}


void TreeDelete(BSTreeNode*pNode)
{
	BSTreeNode*p=pNode;
	BSTreeNode*y=pNode->prefather;
	BSTreeNode*x;
	if(pNode->lchild==NULL&&pNode->rchild==NULL)
	{
		if(y->lchild==pNode)
			y->lchild=NULL;
		else
			y->rchild=NULL;
		pNode->prefather=NULL;
	}
	else if(pNode->lchild!=NULL&&pNode->rchild==NULL)
	{
		x=pNode->lchild;
		if(y->lchild==pNode)
			y->lchild=x;
		else
			y->rchild=x;
		x->prefather=y;
		pNode->prefather=NULL;
	}
	else if(pNode->rchild!=NULL&&pNode->lchild==NULL)
	{
		x=pNode->rchild;
		if(y->lchild==pNode)
			y->lchild=x;
		else
			y->rchild=x;
		x->prefather=y;
		pNode->prefather=NULL;
	}
	else
	{
		x=TreeSuccessor(p);
		x->prefather->lchild=NULL;
		x->prefather=y;
		if(y->lchild==pNode)
			y->lchild=x;
		else
			y->rchild=x;
		x->lchild=pNode->lchild;
		x->rchild=pNode->rchild;
	}
}
int max,min;
void search(BSTreeNode * root)
{
    int maxl,minl;
    if(root=NULL)return;
    BSTreeNode *l=root->lchild;
    BSTreeNode *r=root->rchild;
	if(l&&l->v_key>root->v_key){
        maxl=l->v_key;
        minl=root->v_key;
        }
    else if(l){
        maxl=root->v_key;
        minl=l->v_key;
        }
    if(r&&maxl<r->v_key)
        maxl=r->v_key;
    if(r&&minl>r->v_key)
        minl=r->v_key;
    if(max<maxl)max=maxl;
    if(min>minl)min=minl;
    search(l);
    search(r);
}
void main(){

	BSTreeNode*pHead=NULL;
	BSTreeNode*pList=NULL;
	int num[9]={3,5,3,4,9,13,11,7,4};
	for(int i=0;i<9;i++){
		pList=(BSTreeNode*)malloc(sizeof(struct BSTreeNode));
		pList->v_key=num[i];
		pList->lchild=NULL;
		pList->rchild=NULL;
		pList->prefather=NULL;
		TreeInsert(&pHead,pList);
	}
	search(pHead);
	printf("%d",max-min);
	inorderTreeWalk(pHead);
	pList=TreeSearch(pHead,9);
	pList=TreePrecursor(pList);
	printf("%d\n",pList->v_key);
}