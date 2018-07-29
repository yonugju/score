#include "score.h"
#include <stddef.h>
int main(){
	int_2D_arr score = { NULL, };
	str_arr subject = { NULL, };
	subject.row = str_MAX;
	prompt(&subject, &score);
	subject.base  = (char*)malloc(sizeof(char)*subject.col*subject.row);
	score.base = (int*)malloc(sizeof(int)*(score.row)*score.col);
	total_in(&subject, &score);
	total_out(&subject, &score);
	free(subject.base);
	free(score.base);
	
	return 0;
}
