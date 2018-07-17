#include<stdio.h>

void score_in(int **score, int column, int row, char **subject);
void score_out(int **score, int column, int row, char **subject);
void subject_in(char **subject, int num, int length);
void subject_out(char **subject, int num, int length);
int grade(double x);
int sum_array(int *array, int num);
#define st_MAX 10	//�л� �ִ��
#define sub_MAX 5	//���� �ִ��	
#define ch_MAX 9	//���ڿ� �ִ��

int main()
{
	int score[sub_MAX][st_MAX];	//������ �ִ� �迭
	int st_num;	//�л���
	char subject[sub_MAX][ch_MAX];//������� �ִ� �迭
	int sb_num;	//�Է¹��� �����
	printf("�Է��� ������� �Է��Ͻÿ�\n");
	scanf("%d", &sb_num);
	printf("�Է��� �л����� �Է��Ͻÿ�\n");
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
		printf("�Է¹��� ������ ���ʴ�� �Է��Ͻÿ�.");
		scanf("%s", subject + i*length);

	}
}

void subject_out(char **subject, int num, int length)
{
	for (int i = 0; i < num; i++)
	{
		printf("�Է¹��� ���� :%s.\n", subject + i*length);

	}
}

void score_in(int **score, int column, int row, char **subject, int tmp)
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d���л��� %s�����Է��Ͻÿ�.\n", j + 1, subject + i * tmp);
			scanf("%d", score + i * row + j);
			if (*(score + i * row + j) < 0 || *(score + i * row + j) >100)
			{
				printf("0~100���̸� �Է��Ͻÿ�.\n");
				j--;
			}
		}
	}
}
//00 10 20
//01 11 21
void score_out(int **score, int column, int row, char **subject, int tmp)
{
	int temp[st_MAX];	//������ �ӽ������� ������ �迭 ����
	int temp1[st_MAX];	//������ ���� ������ �迭 ����
	float average;	//��հ��� ������ �Ǽ��� ���� ����
	for (int i = 0; i < column; i++)
	{
		printf("\t%s", subject + i*tmp);
	}
	printf("\t���\t���\n");
	for (int i = 0; i < row; i++)
	{
		printf("%d\t", i + 1);	//�л���ȣǥ��
		for (int j = 0; j < row; j++)
		{
			if (j < 1)	//���ٸ� ����ϱ� ���� 
			{
				for (int k = 0; k < column; k++)	//�Է°� ���
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
