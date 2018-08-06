#include "funtion.h"


int main(){

	conector vector;
	vector.size = 0;
	vector.capacity = 0;
	vector.base = (int*)malloc(sizeof(int));
	push_back(&vector, 40);
	push_back(&vector, 50);
	push_back(&vector, 60);
	push_back(&vector, 70);
	push_back(&vector, 80);
	push_back(&vector, 90);
	push_back(&vector, 100);
	push_back(&vector, 110);
	push_back(&vector, 120);
	print(&vector);
	free(vector.base);
	return 0;
}
