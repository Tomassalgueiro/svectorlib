#include <stddef.h>

typedef struct {
	size_t size;
	size_t capacity;
	int *data;
} svector_int;

// vector properties 
/* initialize the vector */
void svector_init(svector_int *v);

/* free the memory containing the vector */
void svector_free(svector_int *v);

/* get the vector size */
int svector_size(svector_int *v);

 
// mess with the vector elements
/* add an element to the vector */
void svector_push(svector_int *v, int value);

/* get an element from the vector */
int svector_get(const svector_int *v, size_t index);

/* remove the highest index element */
// interesting way to think is that the pop function doenst actually "delete" the element it just makes it so that trying to access that index is invalid
void svector_pop(svector_int *v);

/* insert an element at a determined index */
void svector_insert(svector_int *v, int index, int value);

/* remove an element at a determined index */
void svector_remove(svector_int *v, int index);

// extra
/* print all the elements in a vector */
void svector_print(svector_int *v);
