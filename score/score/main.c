#include<stdio.h>
#include<malloc.h>


# define st_max 10	//학생 최대수
# define sb_max 6	//과목최대수
# define str_max 9	//스트링최대수



typedef struct _str_arr
{
	char **base;
	size_t col, row;
};


struct _int_2D_arr
{
	int **base;
	size_t col, row;
};

typedef struct _str_arr str_arr;
typedef struct _int_2D_arr int_2D_arr;

void score_in(str_arr *a, int_2D_arr *b);
void subject_in(str_arr *a);
void stu_num(str_arr *a);
void total_output(str_arr *a, int_2D_arr *b);
void first_in(str_arr *a);
char grade(float x);
//정적 배열은 컴파일 시점에 메모리 할당
//동적 배열은 실행 시점에 메모리 할당
int main()
{
	int **base1;	//2차원 배열 할당 base1
	base1 = (int**)malloc(sizeof(int *)*st_max);
	for (int i = 0; i < st_max; i++)
	{
		base1[i] = (int *)malloc(sizeof(int)*str_max);
	}
	char **base2;	//2차원 배열 할당 base2
	base2 = (char**)malloc(sizeof(char *)*sb_max);
	for (int i = 0; i < sb_max; i++)
	{
		base2[i] = (char *)malloc(sizeof(char)*str_max);
	}


	str_arr subject;
	int_2D_arr score;

	score.base = base1;
	subject.base = base2;

	first_in(&subject);
	subject_in(&subject);
	score_in(&subject, &score);
	stu_num(&subject);
	total_output(&subject, &score);

	for (int i = 0; i < subject.col; i++)	//base1 메모리해제

	{
		free(base1[i]);
	}

	free(base1);

	for (int i = 0; i < subject.row; i++)	//base2 메모리해제

	{
		free(base2[i]);
	}
	free(base2);

	return 0;
}
void first_in(str_arr *a)
{
	for (int i = 0; i < 1; i++){
		printf("과목수를 입력하시오\n");
		scanf("%d", &a->col);
		if (a->col < 0 || a->col > sb_max)
		{
			printf(" 0~6사이의 숫자를 입력하시오.\n");
			i--;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		printf("학생수를 입력하시오\n");
		scanf("%d", &a->row);
		if (a->row < 0 || a->row > st_max)
		{
			printf(" 0~10사이의 숫자를 입력하시오.\n");
			i--;
		}
	}
}

void subject_in(str_arr *a)
{
	for (int i = 0; i < a->col; i++)
	{

		printf("입력받을 과목명을 입력하시오.\n");
		scanf("%s", (a->base) + i*str_max);
		printf("입력받은 과목명:%s\n", (a->base) + i*str_max);
	}
}

void score_in(str_arr *a, int_2D_arr *b)
{
	for (int i = 0; i < a->col; i++)
	{
		for (int j = 0; j < a->row; j++)
		{

			printf("%d번 학생의 %s 점수를 입력하시오.\n", j + 1, (a->base) + i*str_max);
			scanf("%d", b->base + i * a->row + j);
			if (*(b->base + i * a->row + j) >100 || *(b->base + i * a->row + j) < 0)
			{
				printf("0~100사이의 숫자를 입력하시오.\n");
				j--;
			}
		}
	}

}
void stu_num(str_arr *a)
{
	for (int i = 0; i < a->row; i++)
	{
		printf("\t%d번", i + 1);;
	}
	printf("\n");
}
void total_output(str_arr *a, int_2D_arr *b)
{
	int temp1[st_max][str_max];
	int temp[st_max];	//입력받은 [i]행의 score값 전체를 합하여 저장할 배열선언
	float average;
	for (int i = 0; i < a->col; i++)//과목명을 보여주기 위한 반복문
	{
		printf("%s", (a->base) + i*str_max);
		for (int j = 0; j < a->row; j++)//점수를 보여주기 위한 반복문
		{
			printf("\t%d", *(b->base + i*a->row + j));
			temp1[i][j] = *(b->base + i*a->row + j);
			//	printf("%d\n", temp1[i][j]);	//값이 잘 들어왔나 중간체크
		}
		for (int x = 0; x < a->row; x++)	//temp에 값을 저장하기 위한 이중반복문
		{
			temp[x] = 0;
			for (int b = 0; b < a->col; b++)
			{
				temp[x] += temp1[b][x];
				//printf("%d", temp[a])	;//값이 잘 들어왔나 중간체크
			}
		}
		printf("\n");	// 한칸 띄고
	}
	printf("평균");
	for (int i = 0; i < a->row; i++)
	{
		average = temp[i] / a->col;
		printf("\t%5.2f", average);
	}
	printf("\n");	// 한칸 띄고
	printf("등급");
	for (int i = 0; i < a->row; i++)
	{
		average = temp[i] / a->col;
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
