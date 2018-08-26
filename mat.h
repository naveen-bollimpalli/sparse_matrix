#ifndef MAT_H
#define MAT_H
struct Node
{
	int row,col;
	float key;
	struct Node *rlink;
	struct Node *clink;
};
typedef struct Node node;

struct Sparse
{
	node *row[500];
	node *col[500];
	int row_sz;
	int col_sz;
		
};
typedef struct Sparse sparse;

void insert_node(int ,int ,float key,sparse *);
//void inser_node1(int,int,float,sparse *);
void init_sparse(sparse *);
void display(sparse*);
void create_mat(sparse *);
void create_mat1(sparse *);
int* create_mat2();
int* craete_mat3();
void gelim(sparse *);
void gelim1(int *);
float getv(sparse *,int ,int);
void gelim(sparse *);
void swap(sparse *,int,int,float,int,int,float);
int delete_node(int , int ,sparse *);
void guass (sparse *);
void forwardSubstitution(sparse *);
void reverseElimination(sparse *);
#endif
