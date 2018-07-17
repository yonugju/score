#include<stdio.h>

void score_in(int **score, int column, int row, char **subject);
void score_out(int **score, int column, int row, char **subject);
void subject_in(char **subject, int num, int length);
void subject_out(char **subject, int num, int length);
int grade(double x);
int sum_array(int *array, int num);
#define st_MAX 10	//학생 최대수
#define sub_MAX 5	//과목 최대수	
#define ch_MAX 9	//문자열 최대수

int main()
{
	int score[sub_MAX][st_MAX];	//점수를 넣는 배열
	int st_num;	//학생수
	char subject[sub_MAX][ch_MAX];//과목명을 넣는 배열
	int sb_num;	//입력받을 과목수
	printf("입력할 과목수를 입력하시오\n");
	scanf("%d", &sb_num);
	printf("입력할 학생수를 입력하시오\n");
	scanf("%d", &st_num);
	subject_in(subject, sb_num, ch_MAX);
	subject_out(subject, sb_num, ch_MAX);
	score_in(score, sb_num, st_num, subject, ch_MAX);
	score_out(score, sb_num, st_num, subject, ch_MAX);
}

void subject_in(char **subject, int num, int length)
{
	for (int i = 0; i < num; i++)
	{
		printf("입력받을 과목을 차례대로 입력하시오.");
		scanf("%s", subject + i*length);

	}
}

void subject_out(char **subject, int num, int length)
{
	for (int i = 0; i < num; i++)
	{
		printf("입력받은 과목 :%s.\n", subject + i*length);

	}
}

void score_in(int **score, int column, int row, char **subject, int tmp)
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d번학생의 %s성적입력하시오.\n", j + 1, subject + i * tmp);
			scanf("%d", score + i * row + j);
			if (*(score + i * row + j) < 0 || *(score + i * row + j) >100)
			{
				printf("0~100사이를 입력하시오.\n");
				j--;
			}
		}
	}
}
//00 10 20
//01 11 21
void score_out(int **score, int column, int row, char **subject, int tmp)
{
	int temp[st_MAX];	//점수를 임시적으로 저장할 배열 선언
	int temp1[st_MAX];	//점수의 합을 저장할 배열 선언
	float average;	//평균값을 저장할 실수형 변수 선언
	for (int i = 0; i < column; i++)
	{
		printf("\t%s", subject + i*tmp);
	}
	printf("\t평균\t등급\n");
	for (int i = 0; i < row; i++)
	{
		printf("%d\t", i + 1);	//학생번호표시
		for (int j = 0; j < row; j++)
		{
			if (j < 1)	//한줄만 출력하기 위해 
			{
				for (int k = 0; k < column; k++)	//입력값 출력
				{
					printf("%3d\t", *(score + k*column + i));
					temp[k] = *(score + k*column + i);
				}
			}
			temp1[i] = sum_array(temp, row);
		}
		average = temp1[i] / column;
		printf("%5.2f\t%3c", average, grade(average));

		printf("\n");
	}
}

int sum_array(int *array, int row)
{
	int i, sum = 0;
	for (i = 0; i < row; i++)
		sum += array[i];
	return sum;
}

int grade(double x)
{
	int gd;
	switch ((int)x / 10){
	case 10:
	case 9: gd = 'A'; break;
	case 8: gd = 'B'; break;
	case 7: gd = 'C'; break;
	case 6: gd = 'D'; break;
	default: gd = 'F';
	}
	return gd;
}
