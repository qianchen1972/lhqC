#include <stdio.h>
#include <stdlib.h>


#define NAMESIZE 32
struct score_st 
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

struct node_st
{
	struct score_st data;
	struct node_st *l, *r;

};

void print_S(struct score_st *d)
{
	printf("%d %s %d %d\n", d->id, d->name, d->math, d->chinese);
}

int insert(struct node_st **root, struct score_st *data)
{		
	struct node_st *node;

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = *data;
		node->l = NULL;
		node->r = NULL;

		*root = node;
		return 0;

		
	}

	
	if(data->id <= (*root)->data.id)
		return insert(&(*root)->l, data);
	else
		return insert(&(*root)->r, data);
}

struct score_st *find(struct node_st *root, int id)
{
	if(root == NULL)
		return NULL;

	if(id == root->data.id)
		return &root->data;

	if(id < root->data.id)
		find(root->l, id);
	else
		find(root->r, id);



}


draw_(struct node_st *root, int level)
{
	
	int i;
	if(root == NULL)
		return;
	
	draw_(root->r, level+1);

	for(i = 0; i < level; i++)
		printf("   ");
	print_S(&root->data);

	draw_(root->l, level+1);

}

void draw(struct node_st *root)
{
	draw_(root, 0);

}



int main()
{
	
	int arr[] = {1, 2, 3, 7, 6, 5, 9, 8,4};
	int i;
	struct node_st *tree = NULL;
	struct score_st tmp, *datap;

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++ )
	{
		tmp.id = arr[i];
		snprintf(tmp.name, NAMESIZE, "stu%d", arr[i]);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;
		
		insert(&tree, &tmp);
	}

	int tmpid = 12;
	datap = find(tree, tmpid);
	if(datap == NULL)
		printf("Can not find the id %d\n", tmpid);
	else
		print_S(datap);

	draw(tree);

	exit(0);
}
