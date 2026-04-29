#include <stddef.h>

typedef struct {
	size_t size;
	size_t capacity;
	int *data;
} svector_int;

/*
 * initialize the vector
 */
void svector_init(svector_int *v);

/*
 * add an element to the vector 
 */
void svector_push(svector_int *v, int value);

/*
 * get an element from the vector 
 */
void svector_get(svector_int *v, size_t index);

/*
 * free the memory containing the vector
 */
void svector_free(svector_int *v);
