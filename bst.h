#ifndef BST_H
#define BST_H

typedef struct _bst_node_t
{
	struct _bst_t *container;
	void *data;
	_bst_node_t *left;
	_bst_node_t *right;
}bst_node_t;

typedef int (*bst_cmp_func_t)(void *, void *);
typedef void (*bst_data_dtor_func_t)(void *);

typedef struct _bst_t
{
	bst_node_t *root;
	size_t size;
	bst_cmp_func_t data_cmp;
	bst_data_dtor_func_t data_dtor;;
}bst_t;

#endif // BST_H
