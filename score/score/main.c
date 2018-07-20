
#include<stdio.h>

void score_in(char **subject, int **score, int col, int row);
void subject_in(char **subject, int col);
void stu_num(int row);
void total_output(char **subject, int **score, int col, int row);
char grade(float x);
# define st_max 10	//학생 최대수
# define sb_max 6	//과목최대수
# define str_max 9	//스트링최대수
int main()
{
	int score[st_max][str_max];
	char subject[sb_max][str_max];
	int sub_num;	//과목 수를 받는 매개변수
	int st_num;		//학생 수를 받는 매개변수

	printf("과목수를 입력하시오\n");
L1:	scanf("%d", &sub_num);
	if (sub_num<0 || sub_num>st_max)
	{
		printf(" 0~10사이의 숫자를 입력하시오.\n");
		goto L1;
	}
L2:
	printf("학생수를 입력하시오\n");
	scanf("%d", &st_num);
	if (st_num<0 || st_num>sb_max)
	{
		printf(" 0~5사이의 숫자를 입력하시오.\n");
		goto L2;
	}
	subject_in(subject, sub_num);
	score_in(subject, score, sub_num, st_num);
	stu_num(st_num);
	total_output(subject, score, sub_num, st_num);
	return 0;
}
void subject_in(char **subject, int col)
{
	for (int i = 0; i < col; i++)
	{
		printf("입력받을 과목명을 입력하시오.\n");
		scanf("%s", subject + i*col);
	}
}

void score_in(char **subject, int **score, int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d번 학생의 %s 점수를 입력하시오.\n", j + 1, subject + i*col);
			scanf("%d", score + i * row + j);
			if (*(score + i * row + j)>100 || score + i * row + j < 0)
			{
				printf("0~100사이의 숫자를 입력하시오.\n");
				j--;
			}
		}
	}
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < row; j++)
	//	{
	//		printf("%d번 학생의 점수 %d\n", j + 1, *(score + i * row + j));
	//	}
	//}
}
void stu_num(int row)
{
	for (int i = 0; i < row; i++)
	{
		printf("\t%d번", i + 1);;
	}
	printf("\n");
}
void total_output(char **subject, int **score, int col, int row)
{
	int temp1[st_max][str_max];
	int temp[st_max];	//입력받은 [i]행의 score값 전체를 합하여 저장할 배열선언
	float average;
	for (int i = 0; i < col; i++)//과목명을 보여주기 위한 반복문
	{
		printf("%s", subject + i*col);
		for (int j = 0; j < row; j++)//점수를 보여주기 위한 반복문
		{
			printf("\t%d", *(score + i*row + j));
			temp1[i][j] = *(score + i*row + j);
			//printf("%d\n", temp1[i][j]);	값이 잘 들어왔나 중간체크
		}
		for (int a = 0; a < row; a++)	//temp에 값을 저장하기 위한 이중반복문
		{
			temp[a] = 0;
			for (int b = 0; b < col; b++)
			{
				temp[a] += temp1[b][a];
				//printf("%d", temp[a])	;//값이 잘 들어왔나 중간체크
			}
		}
		printf("\n");	// 한칸 띄고
	}
	printf("평균");
	for (int i = 0; i < row; i++)
	{
		average = temp[i] / col;
		printf("\t%5.2f", average);
	}
	printf("\n");	// 한칸 띄고
	printf("등급");
	for (int i = 0; i < row; i++)
	{
		average = temp[i] / col;
		printf("\t%c", grade(average));
	}
	printf("\n");	// 한칸 띄고
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
