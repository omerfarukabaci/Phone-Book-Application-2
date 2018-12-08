
struct numnode{
	char* phonenum;
	numnode *next;
};


struct Tree_Node{
	char* name;
	numnode *head;
	Tree_Node *left, *right;
};

struct usernode{
	char name[15];
	char phonenum[15];
};

struct Tree{
	Tree_Node *root;
	void createTree();
	void removeTree(Tree_Node* traverse);
	bool addtreenode(usernode* toadd, Tree_Node* traverse, int level, bool flag);
	void addnumnode(Tree_Node* g, char* num);
	void printPreorder(Tree_Node* nd, int* c);
	void printnumlist(numnode* tr);
	int levelf(Tree_Node* nd);
	bool updatenode(Tree_Node* root, char* name, char* n_name);
	Tree_Node* searchTree(Tree_Node* traverse, char* name);

	//void printInorder(Tree_Node *nd);
	//void printPostorder(Tree_Node *nd);
	//int findMax(Tree_Node* nd, int level);
	//int findMin(Tree_Node* nd, int level);
	//int findNumNode(Tree_Node *nd, int x);
	//int findNumLeaf(Tree_Node *nd, int x);
	//int calculateDepth(size_t size);
	//int calculateSum(Tree_Node* nd, int sum);
	//float calculateAverage(size_t x);
	
};