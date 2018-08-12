#include <stdio.h>
#include <malloc.h>
#include "funtion.h"

void push_back(container *vector, int value){
	printf("capacity:%d\n", vector->capacity);
	printf("size: %d\n", vector->size);
	if (vector->size == vector->capacity)
	{
		vector->capacity = vector->capacity ? vector->capacity * 2 : vector->capacity + 1;
		vector->base = realloc(vector->base, sizeof(int)*vector->capacity);
	}
	vector->base[vector->size] = value;
	vector->size++;

}
void insert(container *vector, int value1, int value2)
{
	printf("size: %d\n", vector->size);
	printf("capacity:%d\n", vector->capacity);
	if (vector->size == vector->capacity)
	{
		vector->capacity = vector->capacity ? vector->capacity * 2 : vector->capacity + 1;
		vector->base = realloc(vector->base, sizeof(int)*vector->capacity);
	}
	for (int i = vector->size; value1 - 1 < i; i--){
		vector->base[i] = vector->base[i - 1];
	}
	vector->base[value1 - 1] = value2;
	vector->size++;

}
void erase(container *vector, int value1, int value2){
	int temp;
	temp = value2 - value1 + 1;//=2
	for (int i = 0; i < temp; i++)
	{
		vector->base[value1 + i - 1] = vector->base[value2 + i];
	}
	vector->size = vector->size - temp;
	vector->base = realloc(vector->base, sizeof(int)*vector->size);
}
void size(container *vector){
	printf("present size: %d\n", vector->size);
}
void capacity(container *vector){
	printf("present capacity: %d\n", vector->capacity);
}
void begin(container *vector){
	vector->base[0];
}
void end(container *vector){
	vector->base[vector->size];
}
void back(container *vector){
	for (int i = vector->size; 0 < i; i--){
		printf("%d\n", *(vector->base + i - 1));
	}
}

void resize(container *vector, int value1){////¹Ì¿Ï·á

	vector->base = realloc(vector->base, sizeof(int)*value1);
	for (int i = value1; i < vector->capacity; i++)
	{
		*(vector->base + i) = 0;
	}

}
void shrink_to_fit(container *vector){

	vector->capacity = vector->size;
	vector->base = realloc(vector->base, sizeof(int)*vector->capacity);
	printf("size: %d\n", vector->size);
	printf("capacity:%d\n", vector->capacity);

}
void pop_back(container *vector, int value){

	vector->base[vector->size] = 0;
	vector->size--;
}
void print(container *vector){
	for (int i = 0; i < vector->size; i++){
		printf("%d\n", *(vector->base + i));
	}
}
