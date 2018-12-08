#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Header.h"
#include <ctime> 
#include <math.h>

using namespace std;


void Tree::printnumlist(numnode* tr){
	int counter = 1;
	while (tr){
		cout << "\n\t" << counter << ". " <<tr->phonenum;
		tr = tr->next;
	}
}

void Tree::printPreorder(Tree_Node* nd, int* c){
	if (nd) {
		cout << *c << ". " << nd->name;
		printnumlist(nd->head);
		cout << endl;
		*c = *c + 1;
		printPreorder(nd->left, c);
		printPreorder(nd->right, c);
	}
}

void Tree::createTree(){
	root = NULL;
}

Tree_Node* Tree::searchTree(Tree_Node* traverse, char* name){
	Tree_Node *left = NULL, *right = NULL;
	if (traverse == NULL)
		return NULL;
	if (strcmp(traverse->name, name) == 0)
		return traverse;
	if (traverse->right){
		right = searchTree(traverse->right, name);
	}
	if (traverse->left){
		left = searchTree(traverse->left, name);
	}
	if (left) return left;
	if (right) return right;
	return NULL;
}

int Tree::levelf(Tree_Node* nd){
	if (nd == NULL)
		return 0;
	else{
		int left = levelf(nd->left);
		int right = levelf(nd->right);
		if (left > right) return right + 1;
		else return left + 1;
	}
}

void Tree::addnumnode(Tree_Node* g, char* num){
	numnode* tr;
	numnode* traverse = g->head;
	while (traverse->next)
		traverse = traverse->next;
	tr = new numnode;
	tr->phonenum = new char[strlen(num)];
	strcpy(tr->phonenum, num);
	traverse->next = tr;
	tr->next = NULL;
	return;
}
bool Tree::updatenode(Tree_Node* root, char* name, char* n_name){
	Tree_Node * record;
	record = searchTree(root, name);
	if (record){
		strcpy(record->name, n_name);
	}
	else
		return false;
}
bool Tree::addtreenode(usernode* toadd, Tree_Node* traverse, int level, bool flag){

	if (flag){
		Tree_Node* g = searchTree(root, toadd->name);
		if (g){
			char* chararr = new char(strlen(toadd->phonenum));
			strcpy(chararr, toadd->phonenum);
			addnumnode(g, chararr);
			return true;
		}
	}
	
	if (root == NULL){
		Tree_Node* trnod = new Tree_Node;
		trnod->name = new char(strlen(toadd->name));
		strcpy(trnod->name, toadd->name);
		trnod->left = trnod->right = NULL;
		trnod->head = new numnode;
		trnod->head->phonenum = new char(strlen(toadd->phonenum));
		strcpy(trnod->head->phonenum, toadd->phonenum);
		trnod->head->next = NULL;
		root = trnod;
		return true;
	}
	if (traverse == NULL){
		Tree_Node* trnod = new Tree_Node;
		trnod->name = new char(strlen(toadd->name));
		strcpy(trnod->name, toadd->name);
		trnod->left = trnod->right = NULL;
		trnod->head = new numnode;
		trnod->head->phonenum = new char(strlen(toadd->phonenum));
		strcpy(trnod->head->phonenum, toadd->phonenum);
		trnod->head->next = NULL;
		traverse = trnod;
		return true;
	}
	else{
		if (level == 0) return false;
		if (level == 1){
			if (traverse->left == NULL){
				Tree_Node* trnod = new Tree_Node;
				trnod->name = new char(strlen(toadd->name));
				strcpy(trnod->name, toadd->name);
				trnod->left = trnod->right = NULL;
				trnod->head = new numnode;
				trnod->head->phonenum = new char(strlen(toadd->phonenum));
				strcpy(trnod->head->phonenum, toadd->phonenum);
				trnod->head->next = NULL;
				traverse->left = trnod;
				return true;
			}
			if (traverse->right == NULL){
				Tree_Node* trnod = new Tree_Node;
				trnod->name = new char(strlen(toadd->name));
				strcpy(trnod->name, toadd->name);
				trnod->left = trnod->right = NULL;
				trnod->head = new numnode;
				trnod->head->phonenum = new char(strlen(toadd->phonenum));
				strcpy(trnod->head->phonenum, toadd->phonenum);
				trnod->head->next = NULL;
				traverse->right = trnod;
				return true;
			}
			return false;
		} //end if (level == 1) 
		else
			if ( !addtreenode(toadd, traverse->left, level - 1, false) ) addtreenode(toadd, traverse->right, level - 1, false);
	} //end else

} //end funciton

void Tree::removeTree(Tree_Node* traverse){
	if (traverse == NULL)
		return;
	if (traverse->right)
		removeTree(traverse->right);
	if (traverse->left)
		removeTree(traverse->left);

	numnode* numTraverse = traverse->head;
	numnode* numTail;
	while (numTraverse){
		numTail = numTraverse->next;
		delete numTraverse;
		numTraverse = numTail;
	}
	traverse->head = NULL;
	delete traverse;
	traverse = NULL;

}
