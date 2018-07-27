#include<stdio.h>
#include<malloc.h>
typedef struct str_arr{
	char **base;
	size_t row, col;
}str_arr;
typedef struct int_2D_arr{
	int **base;
	size_t row, col;
}int_2D_arr;

#define st_MAX 10	//�л� �ִ��
#define sb_MAX 6	//���� �ִ��
#define str_MAX 9	//��Ʈ�� �ִ��
void prompt(str_arr *subject, int_2D_arr *score);
int error(int num, int max);
void subname_in(str_arr *subject);
void score_in(str_arr *subject, int_2D_arr *score);
void subname_out(int_2D_arr *score);
void score_out(str_arr *subject, int_2D_arr *score);
char grade(float x);

int main(){
	int_2D_arr score;
	str_arr subject;
	//char sub_arr[sb_MAX][str_MAX];
	//	int score_arr[st_MAX][str_MAX];
	subject.row = str_MAX;
	prompt(&subject, &score);
	char **sub_arr = (char**)malloc((char*)*&(subject.col));
	int **score_arr = (int**)malloc((int*)*&(score.row));
		subject.base = sub_arr;
		score.base = score_arr;
		subname_in(&subject);
		score_in(&subject, &score);
		subname_out(&score);
		score_out(&subject, &score);
		free(sub_arr);
		free(score_arr);
		return 0;
}
void prompt(str_arr *subject, int_2D_arr *score){
	do{
		printf("�л� ���� �Է��Ͻÿ�.\n");
		scanf("%d", &score->row);
	} while (error(score->row, st_MAX));

	int temp;
	do{
		printf("���� ���� �Է��Ͻÿ�.\n");
		scanf("%d", &temp);
	} while (error(temp, sb_MAX));
	score->col = temp;
	subject->col = temp;
}
int error(int num, int max){
	if (num > max || num < 0){
		printf("0~%d���̸� �Է��Ͻÿ�\n", max);
		return 1;
	}
	return 0;

}

void subname_in(str_arr *subject){
	for (int i = 0; i < subject->col; i++){
		printf("�Է¹��� ������� �Է��Ͻÿ�.\n");
		scanf("%s", (char*)(subject->base) + i*(subject->row));
	}
}
//���� 1	2	3	4	5	6
//����
//����
//����
//�Ҿ�
void score_in(str_arr *subject, int_2D_arr *score){
	for (int i = 0; i < score->col; i++){
		for (int j = 0; j < score->row; j++){
			printf("%d���� %s������ �Է��Ͻÿ�\n", j + 1, (char*)(subject->base) + i*(subject->row));
			scanf("%d", score->base + i * score->row + j);
		}
	}
}
void subname_out(int_2D_arr *score){
	printf("����\t");
	for (int i = 0; i < score->row; i++){
		printf("%d\t", i + 1);
	}
	printf("\n");
}
void score_out(str_arr *subject, int_2D_arr *score){
	int temp1[st_MAX][st_MAX] ;
	int temp2[st_MAX];
	/*int temp1[st_MAX*sb_MAX];
	int temp2 = score->row;����2*/
	/*int *temp1 = (int*)malloc(score->row);
	int *temp2 = (int*)malloc(1 * (score->row*score->col));*/
	float average = 0;
	for (int i = 0; i < score->col; i++){
		printf("%s\t", (char*)(subject->base) + i*(subject->row));
		for (int j = 0; j < score->row; j++){
			printf("%d\t", *(score->base + i * score->row + j));
			temp1[i][j] = *(score->base + i * score->row + j);
		}
		///*	temp1[i+j] = *(score->base + i*score->row + j);*/
		//	printf("%d", temp1[i + j]);//����1
		/*		temp2[j] = *(score->base + i*score->row + j);
				printf("%d\n", temp2[j]);//����1*/
		/*}for (int k = 0; k < score->row; k++){
			printf("%d\n", temp1[i+temp2]);//����2
			}*/
		/*printf("%d\n", temp2[i]);//����1*/
		printf("\n");
	}
	printf("���\t");
	for (int i = 0; i < score->row; i++){
		temp2[i] = 0;
		for (int j = 0; j < score->col; j++){
			temp2[i] += temp1[j][i];
		}
	}
	for (int i = 0; i < score->row;i++){
			average = temp2[i] / score->col;
			printf("%5.2f\t", average);

	}
	printf("\n���\t");
	for (int i = 0; i < score->row; i++){
		printf("%c\t", grade(temp2[i] / score->col));
	}
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
