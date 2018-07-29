#include<stddef.h>

#define str_MAX 9	//스트링 최대수

typedef struct str_arr{
	char *base;
	size_t row, col;
}str_arr;
typedef struct int_2D_arr{
	int *base;
	size_t row, col;
}int_2D_arr;

void prompt(str_arr *subject, int_2D_arr *score);
void total_in(str_arr *subject, int_2D_arr *score);
void total_out(str_arr *subject, int_2D_arr *score);
