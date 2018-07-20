
#include<stdio.h>

void score_in(char **subject, int **score, int col, int row);
void subject_in(char **subject, int col);
void stu_num(int row);
void total_output(char **subject, int **score, int col, int row);
char grade(float x);
# define st_max 10	//�л� �ִ��
# define sb_max 6	//�����ִ��
# define str_max 9	//��Ʈ���ִ��
int main()
{
	int score[st_max][str_max];
	char subject[sb_max][str_max];
	int sub_num;	//���� ���� �޴� �Ű�����
	int st_num;		//�л� ���� �޴� �Ű�����

	printf("������� �Է��Ͻÿ�\n");
L1:	scanf("%d", &sub_num);
	if (sub_num<0 || sub_num>st_max)
	{
		printf(" 0~10������ ���ڸ� �Է��Ͻÿ�.\n");
		goto L1;
	}
L2:
	printf("�л����� �Է��Ͻÿ�\n");
	scanf("%d", &st_num);
	if (st_num<0 || st_num>sb_max)
	{
		printf(" 0~5������ ���ڸ� �Է��Ͻÿ�.\n");
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
		printf("�Է¹��� ������� �Է��Ͻÿ�.\n");
		scanf("%s", subject + i*col);
	}
}

void score_in(char **subject, int **score, int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d�� �л��� %s ������ �Է��Ͻÿ�.\n", j + 1, subject + i*col);
			scanf("%d", score + i * row + j);
			if (*(score + i * row + j)>100 || score + i * row + j < 0)
			{
				printf("0~100������ ���ڸ� �Է��Ͻÿ�.\n");
				j--;
			}
		}
	}
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < row; j++)
	//	{
	//		printf("%d�� �л��� ���� %d\n", j + 1, *(score + i * row + j));
	//	}
	//}
}
void stu_num(int row)
{
	for (int i = 0; i < row; i++)
	{
		printf("\t%d��", i + 1);;
	}
	printf("\n");
}
void total_output(char **subject, int **score, int col, int row)
{
	int temp1[st_max][str_max];
	int temp[st_max];	//�Է¹��� [i]���� score�� ��ü�� ���Ͽ� ������ �迭����
	float average;
	for (int i = 0; i < col; i++)//������� �����ֱ� ���� �ݺ���
	{
		printf("%s", subject + i*col);
		for (int j = 0; j < row; j++)//������ �����ֱ� ���� �ݺ���
		{
			printf("\t%d", *(score + i*row + j));
			temp1[i][j] = *(score + i*row + j);
			//printf("%d\n", temp1[i][j]);	���� �� ���Գ� �߰�üũ
		}
		for (int a = 0; a < row; a++)	//temp�� ���� �����ϱ� ���� ���߹ݺ���
		{
			temp[a] = 0;
			for (int b = 0; b < col; b++)
			{
				temp[a] += temp1[b][a];
				//printf("%d", temp[a])	;//���� �� ���Գ� �߰�üũ
			}
		}
		printf("\n");	// ��ĭ ���
	}
	printf("���");
	for (int i = 0; i < row; i++)
	{
		average = temp[i] / col;
		printf("\t%5.2f", average);
	}
	printf("\n");	// ��ĭ ���
	printf("���");
	for (int i = 0; i < row; i++)
	{
		average = temp[i] / col;
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
