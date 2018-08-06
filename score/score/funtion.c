#include <stdio.h>
#include <malloc.h>
#include "funtion.h"


void push_back(conector *vector, int value){
	printf("size: %d\n", vector->size);
	printf("capacity:%d\n", vector->capacity);
	if (vector->size == vector->capacity)
	{
		vector->capacity = vector->capacity ? vector->capacity * 2 : vector->capacity + 1;
		vector->base = realloc(vector->base, sizeof(int)*vector->capacity);
	}
	vector->base[vector->size] = value;
	vector->size++;

}
void print(conector *vector){
	for (int i = 0; i < vector->size; i++){
		printf("%d\n", *(vector->base + i));
	}
}
