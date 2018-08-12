#include "funtion.h"


int main(){

	container vector;
	vector.size = 0;
	vector.capacity = 0;
	vector.base = (int*)malloc(sizeof(int));
	push_back(&vector, 40);
	push_back(&vector, 50);
	push_back(&vector, 60);
	push_back(&vector, 70);
	push_back(&vector, 80);
	insert(&vector, 3, 300);
	back(&vector);
	erase(&vector, 2, 4);
	//	resize(&vector, 2);
	shrink_to_fit(&vector);
	size(&vector);
	capacity(&vector);
	print(&vector);
	free(vector.base);
	return 0;
}

