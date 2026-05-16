/* DOCUMENTATION
 *

* initialize the vector 
void svector_##name##_init(svector_ *v);

* free the memory containing the vector 
void svector_##name##_free(svector_int *v);

* get the vector size 
int svector_##name##_size(svector_int *v);
 
* add an element to the vector 
void svector_##name##_push(svector_int *v, type value);

* get an element from the vector 
int svector_##name##_get(const svector_int *v, size_t index);

* remove the highest index element 
// interesting way to think is that the pop function doenst actually "delete" the element it just makes it so that trying to access that index is invalid
void svector_##name##_pop(svector_int *v);

* insert an element at a determined index 
void svector_##name##_insert(svector_int *v, int index, type value);

* remove an element at a determined index 
void svector_##name##_remove(svector_int *v, int index);

* print all the elements in a vector 
void svector_##name##_print(svector_int *v);

*/

#ifndef SVECTOR_H
#define SVECTOR_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define SVECTOR_DEFINE(type,name)											\
							                                                                \
							                                                                \
typedef struct {					                                                                \
	size_t size;					                                                                \
	size_t capacity;						                                                \
	type *data;					                                                                \
} svector_##name;					                                                                \
							                                                                \
void svector_##name##_init(svector_##name *v){			                                                        \
	v->size = 0;					                                                                \
	v->capacity = 0;				                                                                \
	v->data = NULL;					                                                                \
}							                                                                \
							                                                                \
void svector_##name##_free(svector_##name *v){			                                                        \
	free(v->data);					                                                                \
	v->data = NULL;					                                                                \
	v->capacity = 0;				                                                                \
	v->size = 0;					                                                                \
}							                                                                \
                                                                                                                        \
int svector_##name##_size(svector_##name *v){                                                                           \
	return v->size;                                                                                                 \
}                                                                                                                       \
                                                                                                                        \
void svector_##name##_push(svector_##name *v, type value){                                                              \
                                                                                                                        \
	if(v->size >= v->capacity){                                                                                     \
		if(v->capacity == 0){                                                                                   \
			v->capacity = 4;                                                                                \
		}                                                                                                       \
		else{                                                                                                   \
			v->capacity *=2;                                                                                \
		}                                                                                                       \
                                                                                                                        \
		type *new_data = realloc(v->data, v->capacity*sizeof(type));                                            \
		if(new_data == NULL){                                                                                   \
			fprintf(stderr, "Invalid data");                                                                \
			exit(1);                                                                                        \
		}													\
                                                                                                                        \
		v->data = new_data;                                                                                     \
	}                                                                                                               \
                                                                                                                        \
	v->data[v->size] = value;                                                                                       \
	v-> size++;                                                                                                     \
}                                                                                                                       \
                                                                                                                        \
type svector_##name##_get(const svector_##name *v, size_t index){                                                       \
                                                                                                                        \
	if(index >= v->size){                                                                                           \
		fprintf(stderr, "Index out of bounds");                                                                 \
		exit(1);                                                                                                \
	}                                                                                                               \
                                                                                                                        \
	return v->data[index];                                                                                          \
}                                                                                                                       \
                                                                                                                        \
                                                                                                                        \
void svector_##name##_pop(svector_##name *v){                                                                           \
                                                                                                                        \
	if(v->size == 0){                                                                                               \
		return;                                                                                                 \
	}                                                                                                               \
	v->size--;                                                                                                      \
}                                                                                                                       \
                                                                                                                        \
void svector_##name##_insert(svector_##name *v, int index, type value){                                                 \
                                                                                                                        \
	if(index < 0 || index > v->size){                                                                               \
		fprintf(stderr, "Index out of bounds");                                                                 \
		exit(1);                                                                                                \
	}                                                                                                               \
                                                                                                                        \
	if(v->size >= v->capacity){                                                                                     \
		if(v->capacity == 0){                                                                                   \
			v->capacity = 4;                                                                                \
		}													\
		else{                                                                                                   \
			v->capacity *=2;                                                                                \
		}                                                                                                       \
                                                                                                                        \
		type *new_data = realloc(v->data, v->capacity*sizeof(type));                                            \
		if(new_data == NULL){                                                                                   \
			fprintf(stderr, "Failed to realloc data");                                                      \
			exit(1);                                                                                        \
		}                                                                                                       \
                                                                                                                        \
		v->data = new_data;                                                                                     \
	}                                                                                                               \
                                                                                                                        \
	if (index == v->size) { svector_##name##_push(v, value); return; }                                              \
	for(int i = v->size; i > index; i--){                                                                           \
		v->data[i] = v->data[i-1];                                                                              \
	}                                                                                                               \
	v->data[index] = value;                                                                                         \
	v->size++;                                                                                                      \
	return;                                                                                                         \
                                                                                                                        \
}                                                                                                                       \
                                                                                                                        \
void svector_##name##_remove(svector_##name *v, int index){                                                             \
	if (index < 0 || index >= v->size){                                                                             \
		fprintf(stderr, "Index out of bounds");                                                                 \
		exit(1);                                                                                                \
	}                                                                                                               \
	                                                                                                                \
	if (index == v->size-1) { svector_##name##_pop(v); return; }                                                    \
	for(int i = index; i < v->size-1; i++){                                                                         \
		v->data[i] = v->data[i+1];                                                                              \
	}                                                                                                               \
	v->size--;                                                                                                      \
	return;                                                                                                         \
}                                                                                                                       \
                                                                                                                        \
void svector_##name##_print(svector_##name *v){                                                                         \
	for(int i = 0; i < v->size; i++){                                                                               \
		type var = v->data[i];                                                                                  \
		printf("%d ", var);                                                                                     \
	}                                                                                                               \
}                                                                                                                       \


#endif
