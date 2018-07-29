#include<stdio.h>
#include<malloc.h>
#include "score.h"

int error(int num, int max){
	if (num > max || num < 0){
		printf("0~%d사이를 입력하시오\n", max);
		return 1;
	}
	return 0;

}

void prompt(str_arr *subject, int_2D_arr *score){
	printf("학생 수를 입력하시오.\n");
	scanf("%d", &score->row);
	int temp;
	printf("과목 수를 입력하시오.\n");
	scanf("%d", &temp);
	score->col = temp;
	subject->col = temp;
}
void subject_in(str_arr *subject){
	for (int i = 0; i < subject->col; i++){
		printf("입력받을 과목명을 입력하시오.\n");
		scanf("%s", (char*)(subject->base) + i*(subject->row));
	}
}
void score_in(str_arr *subject, int_2D_arr *score){
	for (int i = 0; i < score->col; i++){
		for (int j = 0; j < score->row; j++){
			printf("%d번의 %s성적을 입력하시오\n", j + 1, (char*)(subject->base) + i*(subject->row));
			scanf("%d", score->base + i * score->row + j);
			if (error(*(score->base + i * score->row + j), 100))
				j--;
		}
	}
}

void total_in(str_arr *subject, int_2D_arr *score){

	subject_in(subject);
	score_in(subject, score);

}

char grade(float x)
{
	int gd;
	switch ((int)x / 10)
	{
	case 10:
	case 9: gd = 'A'; break;
	case 8: gd = 'B'; break;
	case 7: gd = 'C'; break;
	case 6: gd = 'D'; break;
	default: gd = 'F';
	}
	return gd;
}
void subject_out(str_arr *subject){
	printf("과목\t");
	for (int i = 0; i < subject->col; i++){
		printf("%s\t", (char*)(subject->base) + i*(subject->row));
	}printf("평균\t등급\n");

}
void score_out(int_2D_arr *score){

	for (int i = 0; i < score->row; i++){
		float temp = 0;
		printf("%d\t", i + 1);
		for (int j = 0; j < score->col; j++){
			printf("%d\t", *(score->base + i * score->row + j));
			temp += *(score->base + i * score->row + j);
		}
		printf("%5.2f\t %c\n", temp / score->col, grade(temp / score->col));
	}
}
void total_out(str_arr *subject, int_2D_arr *score){

	subject_out(subject);
	score_out(score);

}
