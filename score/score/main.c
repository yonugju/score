#include<stdio.h>

# define st_max 10	//�л� �ִ��
# define sb_max 6	//�����ִ��
# define str_max 9	//��Ʈ���ִ��



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

char grade(float x);
//���� �迭�� ������ ������ �޸� �Ҵ�
//���� �迭�� ���� ������ �޸� �Ҵ�
int main()
{
	int base1[st_max][str_max];
	char base2[sb_max][str_max];
	str_arr subject;
	int_2D_arr score;

	score.base = base1;
	subject.base = base2;
	printf("������� �Է��Ͻÿ�\n");

L1:
	scanf("%d", &subject.col);
	if (subject.col < 0 || subject.col > sb_max)
	{
		printf(" 0~10������ ���ڸ� �Է��Ͻÿ�.\n");
		goto L1;
	}
L2:
	printf("�л����� �Է��Ͻÿ�\n");
	scanf("%d", &subject.row);
	if (subject.row < 0 || subject.row > st_max)
	{
		printf(" 0~5������ ���ڸ� �Է��Ͻÿ�.\n");
		goto L2;
	}
	//printf("%d %d", score.col, score.row);
	subject_in(&subject);
	score_in(&subject, &score);
	stu_num(&subject);
	total_output(&subject, &score);
	return 0;
}
void subject_in(str_arr *a)
{
	for (int i = 0; i < a->col; i++)
	{

		printf("�Է¹��� ������� �Է��Ͻÿ�.\n");
		scanf("%s", (char*)(a->base) + i*a->col);
		printf("�Է¹��� �����:%s\n", (char*)(a->base) + i*a->col);
		//printf("%s", (char*)a->.base + i*a->.col);
	}
}

void score_in(str_arr *a, int_2D_arr *b)
{
	for (int i = 0; i < a->col; i++)
	{
		for (int j = 0; j < a->row; j++)
		{

			printf("%d�� �л��� %s ������ �Է��Ͻÿ�.\n", j + 1, (char*)(a->base) + i*a->col);
			scanf("%d", b->base + i * a->row + j);
			if (*(b->base + i * a->row + j) >100 || *(b->base + i * a->row + j) < 0)
			{
				printf("0~100������ ���ڸ� �Է��Ͻÿ�.\n");
				j--;
			}
		}
	}

}
void stu_num(str_arr *a)
{
	for (int i = 0; i < a->row; i++)
	{
		printf("\t%d��", i + 1);;
	}
	printf("\n");
}
void total_output(str_arr *a, int_2D_arr *b)
{
	int temp1[st_max][str_max];
	int temp[st_max];	//�Է¹��� [i]���� score�� ��ü�� ���Ͽ� ������ �迭����
	float average;
	for (int i = 0; i < a->col; i++)//������� �����ֱ� ���� �ݺ���
	{
		printf("%s", (char*)(a->base) + i*a->col);
		for (int j = 0; j < a->row; j++)//������ �����ֱ� ���� �ݺ���
		{
			printf("\t%d", *(b->base + i*a->row + j));
			temp1[i][j] = *(b->base + i*a->row + j);
			//	printf("%d\n", temp1[i][j]);	//���� �� ���Գ� �߰�üũ
		}
		for (int x = 0; x < a->row; x++)	//temp�� ���� �����ϱ� ���� ���߹ݺ���
		{
			temp[x] = 0;
			for (int b = 0; b < a->col; b++)
			{
				temp[x] += temp1[b][x];
				//printf("%d", temp[a])	;//���� �� ���Գ� �߰�üũ
			}
		}
		printf("\n");	// ��ĭ ���
	}
	printf("���");
	for (int i = 0; i < a->row; i++)
	{
		average = temp[i] / a->col;
		printf("\t%5.2f", average);
	}
	printf("\n");	// ��ĭ ���
	printf("���");
	for (int i = 0; i < a->row; i++)
	{
		average = temp[i] / a->col;
		printf("\t%c", grade(average));
	}
	printf("\n");	// ��ĭ ���
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
//