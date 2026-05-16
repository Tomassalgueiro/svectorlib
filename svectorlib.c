#include "svectorlib.h"
#include <stdlib.h>
#include <stdio.h>

svector_int m;

void svector_init(svector_int *v){
	v->size = 0;
	v->capacity = 0;
	v->data = NULL; 
}

void svector_free(svector_int *v){
	free(v->data);
	v->data = NULL;
	v->capacity = 0;
	v->size = 0;
}

int svector_size(svector_int *v){
	return v->size;
}

void svector_push(svector_int *v, int value){

	if(v->size >= v->capacity){
		if(v->capacity == 0){
			v->capacity = 4;
		}
		else{
			v->capacity *=2;
		}

		int *new_data = realloc(v->data, v->capacity*sizeof(int)); 
		if(new_data == NULL){
			fprintf(stderr, "Invalid data");
			exit(1);
		}

		v->data = new_data;
	}

	v->data[v->size] = value;
	v-> size++;
}

int svector_get(const svector_int *v, size_t index){

	if(index >= v->size){
		fprintf(stderr, "Index out of bounds");
		exit(1);
	}

	return v->data[index];
}


void svector_pop(svector_int *v){

	// this means the vector is empty
	if(v->size == 0){
		return; 
	}
	v->size--; 
}

void svector_insert(svector_int *v, int index, int value){

	// index out of bounds
	if(index < 0 || index > v->size){ 
		fprintf(stderr, "Index out of bounds");
		exit(1);
	}

	if(v->size >= v->capacity){
		if(v->capacity == 0){
			v->capacity = 4;
		}
		else{
			v->capacity *=2;
		}

		int *new_data = realloc(v->data, v->capacity*sizeof(int)); 
		if(new_data == NULL){
			fprintf(stderr, "Failed to realloc data");
			exit(1);
		}

		v->data = new_data;
	}

	if (index == v->size) { svector_push(v, value); return; }
	for(int i = v->size; i > index; i--){
		v->data[i] = v->data[i-1];
	}
	v->data[index] = value;
	v->size++;
	return;

}

void svector_remove(svector_int *v, int index){
	if (index < 0 || index >= v->size){
		fprintf(stderr, "Index out of bounds");
		exit(1);
	}
	
	if (index == v->size-1) { svector_pop(v); return; }
	for(int i = index; i < v->size-1; i++){
		v->data[i] = v->data[i+1];
	}
	v->size--;
	return;
}

void svector_print(svector_int *v){
	for(int i = 0; i < v->size; i++){
		int var = v->data[i];
		printf("%d ", var);
	}
}
