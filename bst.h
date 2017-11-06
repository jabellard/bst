#ifndef BST_H
#define BST_H

typedef struct _bst_node_t
{
	struct _bst_t *container;
	void *data;
	struct _bst_node_t *left;
	struct _bst_node_t *right;
}bst_node_t;

typedef int (*bst_cmp_func_t)(void *, void *);
typedef void * (*bst_data_ctor_func_t)(void *);
typedef void (*bst_data_dtor_func_t)(void *);

typedef struct _bst_t
{
	bst_node_t *root;
	size_t size;
	bst_cmp_func_t data_cmp;
	bst_data_ctor_func_t data_ctor;
	bst_data_dtor_func_t data_dtor;
}bst_t;

bst_node_t *
bst_node_create(void *data);

void
bst_node_destroy(bst_node_t *n);

bst_t *
bst_create(bst_cmp_func_t cmp, bst_data_ctor_func_t ctor, bst_data_dtor_func_t dtor);

static void
bst_destroy_nodes(bst_node_t *root);

void
bst_destroy(bst_t *bst);

int
bst_insert(bst_t **bst, bst_node_t *n, int flags);

bst_node_t *
_bst_search(bst_t *bst, void *data);

void *
bst_search(bst_t *bst, void *data);

static bst_node_t **
bst_find_min(bst_node_t **root);

static bst_node_t *
_bst_delete(bst_node_t **root, void *data);

bst_node_t *
bst_delete(bst_t **bst, void *data);

static void safe_free(void **pp);
#define sfree(p) safe_free((void**)&(p))

#endif // BST_H
