#if 0
//N���� �ڿ����� �־��� �� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
int a[5000];
int main(void)

{

	// ���⼭���� �ۼ�
	int n;
	int i;
	int j;
	int temp;


	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++) //��������
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}


	return 0;

}

#endif

#if 0
//N���� ������ �־��� �� ���� ���� �� 4���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
int a[30000];


int main(void)

{

	// ���⼭���� �ۼ�
	int i;
	int j;
	int n;
	int temp;
	int t;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++) //��������
	{
		for (t = 0, j = 0; j < n - 1 - i; j++)
		{
			if (a[j + 1] > a[t])
			{
				t = j + 1;
			}


		}
		if (j != t)
		{
			temp = a[j];
			a[j] = a[t];
			a[t] = temp;
		}

	}

	for (i = 0; i < 4; i++)
	{
		printf("%d ", a[i]);
	}


	return 0;

}
#endif

#if 0
//N���� ������ �־��� �� ���� 3���� ID�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>

struct st
{
	int ID;
	int grade;
}student[30010];

int Sort_Quick(struct st *student, int m, int n)
{

	int pivot = n;
	int left;
	int target = m;
	struct st temp;

	if (m >= n) return 1;
	for (left = m; left < n; left++) // ��������
	{
		if (student[pivot].grade<student[left].grade)
		{
			if (target != left)
			{
				temp.ID = student[target].ID;
				temp.grade = student[target].grade;
				student[target] = student[left];
				student[left].ID = temp.ID;
				student[left].grade = temp.grade;
			}
			target++;
		}

	}
	if (target != pivot)
	{
		temp.ID = student[target].ID;
		temp.grade = student[target].grade;
		student[target] = student[pivot];
		student[pivot].ID = temp.ID;
		student[pivot].grade = temp.grade;
	}

	Sort_Quick(student, m, target - 1);
	Sort_Quick(student, target + 1, n);
	return n - m + 1;

}


int main(void)

{

	// ���⼭���� �ۼ�

	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		student[i].ID = i + 1;
		scanf("%d", &student[i].grade);
	}
	Sort_Quick(student, 0, n - 1);

	for (i = 0; i<3; i++)
	{
		printf("%d ", student[i].ID);
	}
	return 0;

}
#endif


#if 0
//���� �迭 a���� ���� ���� ū ��� ���� ��ȣ�� ���� �μ��϶�.


#include <stdio.h>


int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
int main(void)

{

	// ���⼭���� �ۼ�
	int row[4] = { 0 };
	int column[5] = { 0 };
	int i;
	int temp;
	int j;
	int max = -10000;
	int x;
	int y;


	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			row[i] += a[i][j];
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (max < row[i])
		{
			max = row[i];
			x = i + 1;
		}
	}


	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 4; i++)
		{
			column[j] += a[i][j];
		}
	}
	max = -10000;
	for (i = 0; i < 5; i++)
	{
		if (max < column[i])
		{
			max = column[i];
			y = i + 1;
		}
	}

	printf("%d %d", x, y);



	return 0;

}
#endif

#if 0
//
//�� �ڸ����� ��� ���Ͽ� �� �ڸ� ���ڸ� ����� ���� ���ڱ�(Digit Root)�̶�� �Ѵ�.
//
//���� ��� ���� 65, 536�� ���ڱ��� 7�̴�, �װ��� 6 + 5 + 5 + 3 + 6 = 25�̰� �̸� �ٽ� 2 + 5 = 7�̱� �����̴�.
//
//
//
//n���� ������ �ԷµǸ� ���ڱ��� ���� ū ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>
int a[1010];
int b[1010];
int c[1010];
int digit_root(int n)
{
	int sum = 0;
	int cnt = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
		cnt++;
	}
	if (cnt == 1) return sum;
	return digit_root(sum);
}

int main(void)

{

	// ���⼭���� �ۼ�
	int n;
	int i;
	int j;
	int temp;
	int x;
	int min = 1000000;
	int max = -1000000;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		a[i] = digit_root(b[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			x = i;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] == a[x])
		{
			c[i] = b[i];
		}
	}

	for (i = 0; i < n; i++)
	{
		if (min>c[i] && c[i] != 0)
		{
			min = c[i];
		}
	}
	printf("%d", min);
	return 0;

}
#endif

#if 0
//����, ������ ũ�Ⱑ ���� 100�� ���簢�� ����� ��� ��ȭ���� �ִ�.�� ��ȭ�� ���� ����, ������ ũ�Ⱑ ���� 10�� ���簢�� ����� ������ �����̸� �������� ���� ��ȭ���� ���� �����ϵ��� ���δ�.�̷��� ������� �����̸� �� �� �Ǵ� ���� �� ���� �� �����̰� ���� ���� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� ��� ��� ��ȭ�� ���� �� ���� ������ �����̸� �׸��� ���� ������� �ٿ��ٸ� ������ ������ ���̴� 260�� �ȴ�.
#include <stdio.h>
int a[110][110];
int b[110][2];

int main(void)

{

	// ���⼭���� �ۼ�
	int n;
	int i;
	int j;
	int x;//����
	int y;//����
	int sum = 0;


	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (x = b[i][0]; x < b[i][0] + 10; x++)
		{
			for (y = b[i][1]; y < b[i][1] + 10; y++)
			{
				a[x][y] = 1;
			}

		}


	}

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (a[i][j]) sum += a[i][j];
		}

	}
	printf("%d", sum);


	return 0;

}
#endif

#if 0
//����, ������ ũ�Ⱑ ���� 100�� ���簢�� ����� ��� ��ȭ���� �ִ�.�� ��ȭ�� ���� ����, ������ ũ�Ⱑ ���� 10�� ���簢�� ����� ������ �����̸� �������� ���� ��ȭ���� ���� �����ϵ��� ���δ�.�̷��� ������� �����̸� �� �� �Ǵ� ���� �� ���� �� �����̰� ���� ���� ������ �ѷ��� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
int a[110][110];
int b[110][2];

int main(void)

{	// ���⼭���� �ۼ�
	int n;
	int i;
	int j;
	int k = 0;
	int x;//����
	int y;//����
	int sum = 0;


	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}


	for (i = 0; i < n; i++)
	{
		for (x = b[i][0]; x < b[i][0] + 10; x++)
		{
			for (y = b[i][1]; y < b[i][1] + 10; y++)
			{
				a[x][y] = 1;
			}

		}
	}

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (a[i][j] != 1) continue;
			if (a[i][j - 1] == 0) sum++;
			if (a[i - 1][j] == 0) sum++;
			if (a[i + 1][j] == 0) sum++;
			if (a[i][j + 1] == 0) sum++;
		}

	}

	printf("%d", sum);


	return 0;
}
#endif

#if 0
//9���� ���ڸ� �Է� ���� ����, �� �߿��� 7���� ���ڸ� ����Ͽ��� ��, ���� 100 �� �Ǵ� ���α׷��� �ۼ��϶�.
#include <stdio.h>



int main(void)

{
	int a[9];
	int i;
	int temp;
	int j;
	int sum = 0;
	// ���⼭���� �ۼ�
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < 9; i++)
	{
		sum += a[i];
	}

	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (a[i] + a[j] == (sum - 100) && a[i] != 0 && a[j] != 0)
			{
				a[i] = 0;
				a[j] = 0;
			}
		}

	}

	for (i = 0; i < 9; i++)
	{
		if (a[i] != 0)
		{
			printf("%d\n", a[i]);
		}


	}

	return 0;

}
#endif


#if 0
//�Ʒ��� ���� �����̿� ������ ĭ���� ĥ���� �ִ� �׸��� ���� �� �����̿��� ã�� ���� ������ ����� �� ���� �ִ����� �˻��Ϸ��� �Ѵ�. �� ��, ã���� �ϴ� �������� ũ�� M(0��M��100)�� ������ ũ�� P(0��M��100)�� �־�����.
//ã���� �ϴ� ������ ����� ȸ���� ������� ĥ������, ������ ���� ��縸 ã���� �ȴ�. ���� ȸ������ ĥ���� ĭ�� ���� ��ġ �˻� �� �ݺ��Ǿ� ���� �� �ִ�.
#include <stdio.h>
int a[110][110];
int b[110][110];
int main(void)

{

	// ���⼭���� �ۼ�

	int m;
	int p;
	int i;
	int j;
	int h;
	int k;
	int cnt = 0;
	int cnt1 = 0;
	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	scanf("%d", &p);
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < p; j++)
		{
			scanf("%1d", &b[i][j]);
		}
	}
	for (i = 0; i < m - (p - 1); i++)
	{

		for (j = 0; j < m - (p - 1); j++)
		{
			cnt = 0;
			for (k = 0; k < p; k++)
			{
				for (h = 0; h < p; h++)
				{
					if (a[i + k][j + h] != b[k][h])
					{
						cnt++;
						break;
					}

				}
				if (cnt) break;
			}
			if (!cnt) cnt1++;

		}
	}
	printf("%d", cnt1);
	return 0;

}
#endif

#if 0

//N���� ���� �Ǽ��� ���� ��, �� �� �̻��� ���ӵ� ������ ���� �ִ밡 �Ǵ� �κ��� ã��, �� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.���� ��� �Ʒ��� ���� 8���� ���� �Ǽ��� �־����ٸ�,

//��ĥ�� �κ��� ���� �ִ밡 �Ǹ�, �� ���� 1.638�̴�.
//
//����� double���� ������ ���� �ʴ´�.
#include <stdio.h>
double a[10010];
int main(void)

{

	// ���⼭���� �ۼ�
	double product = 1.0;
	int i;
	int j;
	int n;
	double max = -10000.0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		product = a[i];

		if (max < product) max = product; //���� ���� �ִ�ġ���� ũ�� �ٲ۴�. ��, �ִ�ġ�� ��� �����ϸ� �񱳺�ȭ.

		for (j = i + 1; j < n; j++)
		{
			if (max < product) //�� ���� ���ڸ���, ���� �����Ҽ��� �ִ�ġ�� ã�´�.
			{
				max = product;
			}
			product *= a[j];
		}
	}
	if (a[n] > max) max = a[n]; //������ ���ڰ� �ִ�ġ���� ū �� Ȯ���Ѵ�.

	printf("%.3f", max);

	return 0;

}
#endif

#if 0
//R�� C���� ���� ����� ������ �� ���� ����� �� �ִ�.�� ���ڿ��� �ִ� �� ���� ����� �ִ�.
//
//�� ������� �ڽŰ� ������ ����� ��Ȯ�� �� ���� �Ǽ��ϴµ�, ������ ����� �Ʒ� �׸��� ���� ���� 8���⿡ �ִ� ����� ���Ѵ�.
#include <stdio.h>

char a[60][60];

int main(void)

{

	// ���⼭���� �ۼ�
	int i;
	int j;
	int R;
	int C;
	int cnt = 0;
	int count = 0;
	int cnt1 = 0;
	int max = -10000;

	scanf("%d %d", &R, &C);

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			scanf(" %1c", &a[i][j]);
		}
	}

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (a[i][j] == '.') continue;

			if (a[i - 1][j] == 'o') cnt++;
			if (a[i - 1][j - 1] == 'o') cnt++;
			if (a[i - 1][j + 1] == 'o') cnt++;
			if (a[i + 1][j - 1] == 'o') cnt++;
			if (a[i + 1][j] == 'o') cnt++;
			if (a[i + 1][j + 1] == 'o') cnt++;
			if (a[i][j - 1] == 'o') cnt++;
			if (a[i][j + 1] == 'o') cnt++;

		}
	}
	count = cnt / 2; //�ߺ�����
	cnt = 0;
	for (i = 0; i < R; i++) //������ �Ǽ� �ִ� Ƚ�� ã��
	{
		if (max < cnt) max = cnt; //i���� ������ ������ max ã�� (��� ��� ��)

		for (j = 0; j < C; j++)
		{
			if (max < cnt) max = cnt; //j���� ������ ������ maxã�� ��, max�� �ʱ�ȭ���� �ʰ� �񱳺�ȭ.
			cnt = 0; //cnt �ʱ�ȭ
			if (a[i][j] != '.') continue; //����� ���� ���� ���� ��ġ

			if (a[i - 1][j] == 'o') cnt++;
			if (a[i - 1][j - 1] == 'o') cnt++;
			if (a[i + 1][j] == 'o') cnt++;
			if (a[i - 1][j + 1] == 'o') cnt++;
			if (a[i + 1][j - 1] == 'o') cnt++;
			if (a[i + 1][j + 1] == 'o') cnt++;
			if (a[i][j - 1] == 'o') cnt++;
			if (a[i][j + 1] == 'o') cnt++;
		}

	}
	count += max;

	printf("%d", count);

	return 0;

}
#endif

#if 0
//���� ���忡���� �䱸�� ���� �پ��� ������ ������ ��� �ִ� ������ �ϰ� �ִ�.��� �� ���ڱ� ���� �̺�Ʈ�� ���ܼ� ���忡 �ִ� ��� �������� Ǯ� �ϳ��� ���� �ؾ� �Ѵ�.

//A, B, C 3���� ���� ������ ���� �� �� ������� �ѹ��� �ϳ��� ��ĥ ���� ����, �ѹ��� 2������ ��ĥ �� �ִ�.���� ��� A�� B�� ���� ��ģ �� C�� �ٽ� ��ġ�ų� A�� C�� ���� ��ġ�� B�� ��ġ��, Ȥ�� B�� C�� ���� ��ġ�� A�� ��ĥ �� �ִ�.

//���� ������ Ǯ���ٰ� �ٽ� ��ġ�� ������ �ſ� �߿��ѵ�, �� ������ �� ������ ���� ��ü ����� �޶����� �����̴�.

//���� ���� A�� B�� ���� a���� b���� ������ ����ִٰ� �� �� �� ���� ��ġ�� ����� a + b��� �Ѵ�.�׷��Ƿ� A�� B�� ���� ��ġ�� C�� ��ġ�� ��� �� ��ü ����� a + b + a + b + c�̸�, B�� C�� ���� ��ġ�� A�� ��ġ�� ����� b + c + b + c + a �̹Ƿ� �� ���� ���� ���� ���� �� �ִ�.

//���� ���, ���� 2, 2, 5���� ����Ǿ� �ִٸ� A(2)�� B(2)�� ��ġ�� ����� 4. ������ ��(4)�� C(5)�� ��ġ�� ����� 9�� �� 13�� �ּҺ���̴�.

//���� ���忡 ����Ǿ� �ִ� ���� ���� N�� ���� ���忡 ����ִ� ������ ���� ni�� �־��� ��, �̵��� �ϳ��� ��ġ�µ� ���� ����� �ּ�(C)�� ���϶�.
#include <stdio.h>
int a[5010];

int main(void)
{
	int n;
	int i;
	int j;
	int k;
	int sum = 0;
	int temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i; j < i + 2; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				if (a[j]>a[k])
				{
					temp = a[j];
					a[j] = a[k];
					a[k] = temp;
				}
			}
		}
		a[i + 1] = a[i] + a[i + 1];
		sum += a[i + 1];
	}
	printf("%d", sum);

}
#endif


#if 0

//�� ���� n�� �Է� �޾Ƽ� 1���� n������ ���� ���Ͽ� ����Ͻÿ�.
//
//��, �ݵ�� ����Լ��� �����Ͻÿ�.
#include <stdio.h>

int sum(int num)
{
	if (num == 0) return 0;
	return num + sum(num - 1);
}
int main(void)

{

	// ���⼭���� �ۼ�
	int n;
	scanf("%d", &n);

	printf("%d", sum(n));



	return 0;

}
#endif

#if 0
//�Ǻ���ġ�����̶� ���� �� ���� ���Ͽ� ������ �����̴�.
//
//ù ��° ���� �� ��° ���� 1�̰� �� ��° ���� ù ��° ���� �� ��° ���� ���Ͽ� 2�� �ȴ�.�Ǻ���ġ������ ������ ���� ������ ����.

//1, 1, 2, 3, 5, 8, 13...

//�ڿ��� N�� �Է� �޾� N��° �Ǻ���ġ ���� ����ϴ� ���α׷��� �ۼ��Ͽ���.
#include <stdio.h>



int main(void)

{

	// ���⼭���� �ۼ�
	int i;
	int a[50];
	int n;
	scanf("%d", &n);
	a[0] = 1; a[1] = 1;
	for (i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%d", a[n - 1]);
	return 0;

}
#endif

#if 0
//�� ���� �ڿ����� �Է� �޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(int a, int b)
{
	return a*b / gcd(a, b);
}


int main(void)

{

	// ���⼭���� �ۼ�

	int x, y;
	scanf("%d %d", &x, &y);

	printf("%d\n%d", gcd(x, y), lcm(x, y));

	return 0;

}
#endif

#if 0
//N���� ������ �־��� �� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>

int a[30010];
int sort_quick(int *d, int m, int n)
{
	int pivot = n;
	int target = m;
	int left;
	int temp;

	if (m >= n) return 1;

	for (left = m; left <n; left++)
	{
		if (d[left]<d[pivot])
		{
			if (left != target)
			{
				temp = d[left];
				d[left] = d[target];
				d[target] = temp;
			}
			target++;
		}
	}
	if (target != pivot)
	{
		temp = d[pivot];
		d[pivot] = d[target];
		d[target] = temp;
	}

	sort_quick(d, m, target - 1);
	sort_quick(d, target + 1, n);

	return n - m + 1;
}
int main(void)

{

	// ���⼭���� �ۼ�

	int n;
	int i;
	int j;
	int k;
	int temp;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	sort_quick(a, 0, n - 1);


	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;

}
#endif

#if 0
void print(int n)
{
	if (n < 0) return;
	print(n - 1);
	printf("%d ", n);
}
int main()
{
	int n;
	scanf("%d", &n);
	print(n);
}
#endif

#if 0
#include <stdio.h>
int pibo(int n)
{
	if (n == 1 || n == 2) return 1;

	return pibo(n - 1) + pibo(n - 2);


}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", pibo(n));
}
#endif

#if 0
//���������� ������� ���ĵǾ� �ִ� N���� �����Ϳ��� Ư���� ���ڰ� �� ��° ��ġ�� �ִ����� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.


#include <stdio.h>

int a[50010];
int b[10010];

int main(void)

{

	// ���⼭���� �ۼ�
	int n;
	int t;
	int i;
	int h;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &b[i]);
	}

	for (h = 0; h < t; h++)
	{
		for (i = 0; i < n; i++)
		{

			if (a[i] == b[h])
			{
				cnt++;
				b[h] = i + 1;
				break;
			}
		}
		if (!cnt) b[h] = 0;


	}

	for (i = 0; i < t; i++)
	{
		printf("%d\n", b[i]);
	}



	return 0;

}

#endif

#if 0
#include <stdio.h>

int a[50010];
int b[10010];
int BS(int *d, )
{

	int main(void)

	{

		// ���⼭���� �ۼ�
		int n;
		int t;
		int i;
		int h;
		int cnt = 0;

		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		scanf("%d", &t);

		for (i = 0; i < t; i++)
		{
			scanf("%d", &b[i]);
		}

		for (h = 0; h < t; h++)
		{

			b[h] = BS(a, b[h]);

		}

		for (i = 0; i < t; i++)
		{
			printf("%d\n", b[i]);
		}

		return 0;

	}
#endif

#if 0
	//�׸��� �ٴڿ� ������ �� �� ���̴� 10cm �̴�.�׷��� �� ���� �׸��� ���� �������� ������ �� ���̴� 5cm�� �����ȴ�.���� �׸��� ���� �ݴ�������� ���̸� ���̴� �׸���ŭ, �� 10cm �þ��.�׸��� ��ȣ ��ȣ�� ��Ÿ���� �����غ���.���ǻ� �׸��� �׿����� ������ ���ʿ��� �������̶�� �����Ѵ�.�׸����� ��(���� �׸��� �ٴڿ� �ٷ� ���� ���¸� ��Ÿ����, ��)���� �׸��� �Ųٷ� ���� ���¸� ��Ÿ����.
	//
	//
	//
	//���� �׸��� ������ ����� �Ʒ� �׸� 1(a)�� ���ٸ� ��ü�� ���̴� 25cm�� �ȴ�.�ֳ��ϸ� ó�� �ٴڿ� �ִ� �׸��� ���̰� 10cm�̰� ���� ���� �������� 3���� �׸��� ������ �����Ƿ� �þ ���̴� 5 + 5 + 5 = 15 �̱� �����̴�.�׸� 1(b)�� ���� ����� �� ���̴� 10 * 4 = 40cm�� �ȴ�.
#include <stdio.h>



	int main(void)

	{

		// ���⼭���� �ۼ�
		char a[60];
		int i;
		int cnt = 0;
		int flag = 1;
		int sol = 0;

		scanf("%s", a);

		for (i = 0; i < 60; i++)
		{
			cnt++;
			if (a[i] == 0) break;
		}

		for (i = 0; i < cnt; i++)
		{
			if ((a[i] == '(' && a[i + 1] == ')') || (a[i] == ')' && a[i + 1] == '(')) flag = 0;
			else flag = 1;

			if (flag) sol += 5;
			else sol += 10;
		}
		printf("%d", sol);
		return 0;

	}


#endif

#if 0
	//�ִ� 30���� �ܾ �Է� ���� �� �ܾ�� ���� ���� �ҹ��ڸ� �μ��϶�.
	//
	//�빮��(��A��~��Z��)�� �ҹ���(��a��~��z��)�� �ƴ� ���ڴ� �Էµ��� ������, 30�ڸ� �ʰ��Ͽ� �Է��ϴ� ���� ���ٰ� �����ϰ�, �̿� ���� ���� ó���� ���� �ʴ´�.
#include <stdio.h>

	char a[40];
	int b[26];

	int main(void)

	{

		// ���⼭���� �ۼ�

		int i;
		int cnt = 0;
		int max = -100;
		int x;


		scanf("%s", a);

		for (i = 0; i < 40; i++)
		{
			cnt++;
			if (a[i] == 0) break;
		}

		for (i = 0; i < cnt; i++)
		{
			b[a[i] - 'a'] += 1;
		}

		for (i = 0; i < 26; i++)
		{
			if (max < b[i])
			{
				max = b[i];
			}
		}

		for (i = 0; i < 26; i++)
		{
			if (b[i] == max)
			{
				printf("%c", i + 'a');
				return 0;
			}
		}





	}
#endif

#if 0
	//N���� �м��� �־��� ��, ��� �м��� ���� ���м��� ��Ÿ���� ���α׷��� �ۼ��Ͻÿ�.
	//
	//���м��� �и�� ���� ���̿� ������� 1 ���̾ �� �̻� ��е��� �ʴ� �м��̴�.

#include <stdio.h>

	int a[110];
	int b[110];
	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a%b);
	}
	int lcm(int a, int b)
	{
		return a*b / gcd(a, b);
	}

	int main(void)

	{

		// ���⼭���� �ۼ�
		int A;
		int B;
		int sum = 0;
		int i;
		int n;
		int x;
		int y;

		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &a[i], &b[i]);

		}

		x = b[0];

		for (i = 0; i < n; i++)
		{
			x = lcm(x, b[i]);
		}

		for (i = 0; i < n; i++)
		{
			a[i] = a[i] * x / b[i];
			sum += a[i];
		}

		y = gcd(sum, x);

		A = sum / y;
		B = x / y;
		if (A == 0) printf("%d", 0);
		else printf("%d/%d", A, B);


		return 0;

	}
#endif

#if 0
	//������ ���� �� �ϳ��� ���� ������ �����û�� �ɻ��Ͽ� ������ ������ �й��ϴ� ���̴�.���������� �Ѿ��� �̸� ������ �־ ��� �����û�� ������ �ֱ�� ����� ���� �ִ�.�׷��� ������ �Ѿ� ���Ͽ��� ������ �� �ִ��� �� ������ ������ ���� ������� �����Ѵ�.

	//(1) ��� ��û�� ������ �� �ִ� ��쿡�� ��û�� �ݾ��� �״�� �����Ѵ�.
	//
	//(2) ��� ��û�� ������ �� ���� ��쿡�� Ư���� ���� ���Ѿ��� ����Ͽ� �� �̻��� �����û���� ��� ���Ѿ��� �����Ѵ�.���Ѿ� ������ �����û�� ���ؼ��� ��û�� �ݾ��� �״�� �����Ѵ�.

	//���� ���, ��ü ���������� 485�̰� 4�� ������ �����û�� ���� 120, 110, 140, 150�̶�� ����.�� ���, ���Ѿ��� 127�� ������, ���� ��û�鿡 ���ؼ� ���� 120, 110, 127, 127�� �����ϰ� �� ���� 484�� ������ �ִ밡 �ȴ�.

	//���� ������ �����û�� ���������� �Ѿ��� �־����� ��, ���� ������ ��� �����ϵ��� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
	int a[10010];
	int sum;//�����û �Ѿ�
	int n;
	int m;//�ִ뿹���
	int max;//���Ѿ�
	int sol;
	int func(int max)
	{
		int i;
		sum = 0;
		for (i = 0; i < n; i++)
		{
			if (max < a[i]) sum += max;
			else sum += a[i];
		}
		if (sum <= m)
		{
			sol = max;
			return 1;
		}

		else return 0;
	}

	int main(void)
	{
		int i;
		int j;
		int s;
		int e;
		int temp;
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j<n - 1 - i; j++)
			{
				if (a[j]>a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}

		scanf("%d", &m);
		s = a[0];
		e = a[n - 1];

		while (s <= e)
		{
			max = (s + e) / 2;
			if (func(max)) s = max + 1;
			else e = max - 1;
		}
		printf("%d", sol);

		return 0;
	}

#endif

#if 0
	//���ڿ��� �Է� ���� ��, ���� ���ڰ� ���������� �ݺ��Ǵ� ��� �ݺ� Ƚ����()�ȿ� �־� ���ڿ��� ���̸� ���̴� �����ϴ� ���α׷��� �ۼ��Ϸ��� �Ѵ�.

	//����1.���� ���ڰ� M�� �̻� �������� �ݺ��� ����()�ȿ� �ݺ� Ƚ���� �ִ´�.
	//
	//����2.�������� �ݺ��Ǵ� ���� �ڿ�()�� �ִ´�.

#include <stdio.h>
	char a[110];
	char b[110];


	int main(void)

	{

		// ���⼭���� �ۼ�


		int cnt = 0;
		int i;
		int j;
		int m;
		int n = 0;
		scanf("%d", &m);
		scanf("%s", a);

		for (i = 0; i < 110; i++)
		{
			n++;
			if (a[i] == 0) break;
		}

		for (i = 0; i < n; i++)
		{
			cnt++;
			if (a[i] != a[i + 1])
			{
				if (cnt < m)
				{
					for (j = 0; j < cnt; j++)
					{
						printf("%c", a[i]);
					}
					cnt = 0;
				}
				else if (cnt >= m)
				{
					for (j = 0; j < cnt; j++)
					{
						printf("%c(%d)", a[i], cnt); //�̷��� ǥ�� �����ϴٴ� �� ���� ����!
						break;
					}
					cnt = 0;
				}

			}
		}


		return 0;

	}
#endif

#if 0
	//���ý��� �������� �����ð��� 10�� �̸��̸� �����̸�, 10�� �̻� 30�� ���ϴ� 500���̴�. ���� 30���� �ʰ��Ͽ� ������ �ϸ� 30�� ��ݿ� 30�� �ʰ� �п� ���� ����� 10�п� 300������ �� �޴´�.�׸��� �Ϸ� �ִ� ��������� �� ��� 50, 000���� ���� �� ����.�̰��� ���ýÿ��� ������ ���̴�.

	//���� 9�� �����ϸ� 0��, 20�� �����ϸ� 500��, 32���� �����ϸ� 800���̴�.

	//�Ϸ翡 �� 100�븦 ������ �� �ִ� �����忡 �Ϸ� ���� �����ߴ� ���� ���� �� �����ð��� �־����� �Ϸ� �� ��������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>

	int a[110];
	int main(void)

	{

		// ���⼭���� �ۼ�
		int i;
		int pay = 0;
		int n;
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		for (i = 0; i < n; i++)
		{
			if (a[i] < 10) pay += 0;
			else if (a[i] >= 10 && a[i] <= 30) pay += 500;
			else if (a[i]>30 && a[i] <= 1670) pay += 500 + ((a[i] - 30) + 9) / 10 * 300; //�ø������ ��.
			else if (a[i] > 1670) pay += 50000;
		}

		printf("%d", pay);

		return 0;

	}
#endif

#if 0
	//ö���� ģ����� ���� ������ �ϰ� �ִ�. ö���� �����ǿ� �� ����� ��ȸ�ڰ� �θ��� ���� ������ �־��� �� ��ȸ�ڰ� �� ��° ���� �θ� �� ö���� "����"�� ��ġ�� �Ǵ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
	int bingo[5][5];
	int a[5][5];
	int count;
	int flag;
	int cnt;
	void erase(int n)
	{
		int i;
		int j;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (bingo[i][j] == n)
				{
					bingo[i][j] = 0;

				}
			}
		}
	}

	int Bingo(void)
	{
		int i;
		int j;


		cnt = 0;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (bingo[i][j] != 0)
				{
					flag++;
					break;
				}

			}
			if (!flag)
			{
				cnt++;
			}


			else flag = 0;
		}

		flag = 0;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (bingo[j][i] != 0)
				{
					flag++;
					break;
				}
			}
			if (!flag)
			{
				cnt++;
			}
			else flag = 0;
		}

		flag = 0;

		for (i = 0; i < 5; i++)
		{
			if (bingo[i][i] != 0)
			{
				flag++;
				break;
			}
		}
		if (!flag)
		{
			cnt++;
		}

		flag = 0;

		for (i = 0; i < 5; i++)
		{
			if (bingo[i][4 - i] != 0)
			{
				flag++;
				break;
			}
		}

		if (!flag)
		{
			cnt++;
		}
		flag = 0;

		return cnt;
	}
	int main(void)

	{

		// ���⼭���� �ۼ�
		int i;
		int j;
		int sum = 0;

		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				scanf("%d", &bingo[i][j]);
			}
		}
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				count++;
				scanf("%d", &a[i][j]);
				erase(a[i][j]);
				Bingo();
				if (cnt >= 3)
				{
					printf("%d", count);
					return 0;
				}

			}
		}



		return 0;

	}


#endif

#if 0


#include <stdio.h>

	int main(void)
	{

		return 0;
	}
#endif

#if 0
	//LK �ڷ��޿� �ٹ��ϴ� ���Ի�� ���񿡰� ������� ���ο� ������ �����ߴ�.������ �޴��� ��ȭ��ȣ�� �����ϴ� �۾��̴�.�޴��� ��ȣ�� ���� 3 �ڸ��� �߰����� 3�ڸ� �Ǵ� 4�ڸ�, �׸��� ���ڸ� �� 4 �ڸ��� �� 10 �� Ȥ�� 11 ���� ���ڷ� �̷������.�׸��� �޴��� ������ 010, 011, 016, 017, 018, 019 �� ���� ������ �����Ѵ�.������ �߰�����, ���ڸ� ���� ������(�� - ��)���� ���еȴ�.������� ���ϴ� �䱸������ ������ ����.�켱, Ư�� ���� ��ȣ ������ ������ �Ǿ�� �ϸ�, ������ ���� ��쿡�� �߰����� ���ڳ��� ���ؼ� �������� ������ �Ǿ�� �ϸ�, �߰������� ���� ��쿡�� ���ڸ� ��ȣ�� ���ؼ� ������������ ������ �Ǿ�� �Ѵ�.��, ������� ���ϴ� ���ļ����� ������ ���� ��� �߰����� 4 �ڸ��� �޴��� ��ȣ�� �߰����� 3 �ڸ��� �޴��� ��ȣ���� �׻� ���� �켱������ ����.��, ������ ���� ��� �߰����� 4 �ڸ��� �޴��� ��ȣ�� �߰����� 3�ڸ��� �޴��� ��ȣ���� ���� �� �׻� ���� �����Ѵ�.���� ���, ������ ���� �޴��� ��ȣ�� �����Ѵٰ� ����.
	//
	//011 - 275 - 3587
	//017 - 1111 - 2600
	//019 - 222 - 2222
	//017 - 111 - 1234
	//018 - 275 - 9562
	//010 - 333 - 1111
	//016 - 1235 - 3333
	//
	//�� ��ȣ���� 017 / 011 / 018 / 019 / 010 / 016 ���� ������, �׸��� �߰����� 4 �ڸ��� �߰����� 3�ڸ����� �켱������ ������ ������ �Ѵٸ�, �Ʒ��� ���� ������ �� ���̴�.
	//
	//017 - 1111 - 2600
	//017 - 111 - 1234
	//011 - 275 - 3587
	//018 - 275 - 9562
	//019 - 222 - 2222
	//010 - 333 - 1111
	//016 - 1235 - 3333
	//
	//���� ������� ù ��° ������ 017 - 1111 - 2600 �� �� ��° ������ 017 - 111 - 1234 �� ���� ����, �߰����� 111 �� 1111 ���� �����Ƿ� �Ϲ������δ� ���� �� 017 - 111 - 2600 �� ���� �����ؾ� �ϳ�, ������� �䱸���׿��� �߰����� 4 �ڸ��� �߰����� 3 �ڸ����� �׻� ���� �켱������ ���ٴ� ��Ģ ������ 017 - 1111 - 2600 �� 017 - 111 - 1234 ���� ���� ������ ���� �� �� �ִ�.
#include <stdio.h>



	int main(void)

	{

		// ���⼭���� �ۼ�



		return 0;

	}

#endif

#if 0
	//������ ���������� �� ö���� ������ ȣ���� �������� �ִٴ� ���� �˾Ҵ�.
	//
	//�� ������ ���� ȣ���� �� ���� �ִ��� �ľ��Ϸ��� �Ѵ�.
	//
	//
	//
	//��, ��, ��, ��, �밢������ ����Ǿ� ������ �ϳ��� ȣ���� �����Ѵٸ� ö���� ������ �� ���� ȣ���� �ִ��� �ľ��� �� �ִ� ���α׷��� �ۼ�����.
#include <stdio.h>// FLOOD FILL - ����� ���� ã�� ��


	int a[110][110];
	int check[110][110];
	int n;
	int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //8���� ���� �� �� ���
	int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 };//�����¿�, ���´밢��, ��� �밢��, ���´밢��, �Ͽ� �밢��


	void check_lake(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (check[i][j] == 1) return;//��������-�̹� �߰ߵ� ȣ����� ����.

		check[i][j] = 1; //���� �߰��� ȣ���� 1�� ��´�.
		for (k = 0; k < 8; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (a[ni][nj]) check_lake(ni, nj); //8���� ��� �� ���� ȣ���� ������ �ٽ� check_lake�� ȣ��
		}

	}

	int main(void)

	{

		// ���⼭���� �ۼ�
		int i;
		int j;
		int cnt = 0;

		scanf("%d", &n);
		for (i = 1; i < n + 1; i++) //8������ ��� ����ؾ� �� ���� (1,1)���� ��� ����
		{
			for (j = 1; j < n + 1; j++)
			{
				scanf("%1d", &a[i][j]);
			}
		}


		for (i = 1; i < n + 1; i++)
		{
			for (j = 1; j < n + 1; j++)
			{
				if (a[i][j] == 0) continue;
				if (check[i][j] == 1) continue;
				check_lake(i, j);
				cnt++;
			}
		}

		printf("%d", cnt);


		return 0;

	}
#endif

#if 0
	//����� M��, N���� ũ�⸦ ���� ����� ������ �ְ�, ����� 1�� 0�� ������ �̷���� �ִ�.���⼭ �����̵� �����̵� �밢�� �����̵� ������ �� ���� ������ ����Ǿ� �ִٰ� ǥ���ϴµ�, ������ 1�� �͵��� ���� ����Ǿ� �ϳ��� ������ �̷��.
	//
	//��Ŀ��� �� ���� ������ �ִµ�, ��Ŀ��� ũ�Ⱑ ���� ū ������ �̷�� ���� 1�� ������ ���ΰ� ?
#include <stdio.h>

	int cell[20][20];
	int check[20][20];
	int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
	int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
	int cnt;
	int max = -10000;
	void check_cell(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (check[i][j]) return;
		check[i][j] = 1;
		cnt++;
		for (k = 0; k < 8; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];

			if (cell[ni][nj]) check_cell(ni, nj);
		}


	}
	int main(void)

	{

		// ���⼭���� �ۼ�
		int i;
		int j;
		int m;
		int n;


		scanf("%d %d", &m, &n);

		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &cell[i][j]);
			}
		}

		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (cell[i][j] == 0) continue;
				if (check[i][j] == 1) continue;
				check_cell(i, j);

				if (max < cnt)
				{
					max = cnt;

				}
				cnt = 0;
			}
		}

		printf("%d", max);
		return 0;

	}
#endif

#if 0
	//<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.
	//
	//ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�.���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�.�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�.
	//
	//������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
	int house[50][50];
	int check[50][50];
	int num[2500]; // �� ���� �� �� ��
	int count; // �� ���� �� �� �� ����
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	void check_house(int i, int j)
	{
		int k;
		int ni;
		int nj;

		if (check[i][j]) return;

		check[i][j] = 1;
		count++;
		for (k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (house[ni][nj]) check_house(ni, nj);
		}
	}

	int main(void)

	{

		// ���⼭���� �ۼ�
		int i;
		int j;
		int n;
		int cnt = 0; //�� ���� ��
		int temp;
		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%1d", &house[i][j]);
			}
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (house[i][j] == 0) continue;
				if (check[i][j]) continue;

				check_house(i, j);
				cnt++;
				num[cnt - 1] = count;
				count = 0;
			}
		}
		printf("%d\n", cnt);

		for (i = 0; i < cnt - 1; i++)
		{
			for (j = i + 1; j < cnt; j++)
			{
				if (num[i]>num[j])
				{
					temp = num[j];
					num[j] = num[i];
					num[i] = temp;
				}
			}
		}

		for (i = 0; i < cnt; i++)
		{
			printf("%d\n", num[i]);
		}
		return 0;

	}
#endif

#if 0
	//���� ���� �踷��⸦ �������� �����Ϸ��� �Ѵ�.ȿ������ �۾��� ���ؼ� �踷��⸦ �Ʒ����� ���� ���� ����, �������� ������ �������� �߻��Ͽ� �踷������ �ڸ���.�踷���� �������� ��ġ�� ���� ������ �����Ѵ�.
	//
	//- �踷���� �ڽź��� �� �踷��� ������ ���� �� �ִ�.
	//
	//- �踷��⸦ �ٸ� �踷��� ���� ���� ��� ������ ���Եǵ��� ����, ������ ��ġ�� �ʵ��� ���´�.
	//
	//- �� �踷��⸦ �ڸ��� �������� ��� �ϳ� �����Ѵ�.
	//
	//- �������� � �踷����� �� �������� ��ġ�� �ʴ´�.
	//
	//
	//
	//�Ʒ� �׸��� �� ������ �����ϴ� ���� �����ش�.�������� �׷��� ���� �Ǽ���  �踷����̰�, ���� �������� ��ġ, �������� �׷��� ���� ȭ��ǥ�� �������� �߻� �����̴�.
	///�̷��� �������� �踷����� ��ġ�� ������ ���� ��ȣ�� �̿��Ͽ� ���ʺ��� ������� ǥ���� �� �ִ�.
	//
	//(a)�������� ���� ��ȣ�� �ݴ� ��ȣ�� ������ �� ��() �� ���� ǥ���ȴ�.����, ��� ��() ���� �ݵ�� �������� ǥ���Ѵ�.
	//
	//(b)�踷����� ���� ���� ���� ��ȣ ��(�� ��, ������ ���� ���� ��ȣ ��) �� �� ǥ���ȴ�.
	//
	//�� ���� ��ȣ ǥ���� �׸� ���� �־��� �ִ�.
	//
	//
	//
	//�踷���� �������� ���� �� ���� �������� �߷����µ�, �� ������ ���� ���� �ִ� �� ���� �踷���� ���� 3���� 2���� �������� �߷�����, �̿� ���� ������� �־��� �踷������ �� 17���� �������� �߷�����.
	//
	//�踷���� �������� ��ġ�� ��Ÿ���� ��ȣ ǥ���� �־����� ��, �߷��� �踷��� ������ �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>



	int main(void)

	{

		// ���⼭���� �ۼ�



		return 0;

	}

#endif

#if 0
	//�ظ��� ������ �ܲ��� �ø��ǾƵ忡�� ���� ������� �ִµ�, ���򿡴� �ܲ��̵��� ������ �ܷ�� ���̼����� ��ȸ���� �α⸦ ���� �ִ�.�� ��ȸ�� ��ȸ�ڰ� ����, �ʷ�, �Ķ����� �̷���� N �� N �ȼ��� �׸��� �����ָ� �� �׸��� ���Ե� ������ ���� ������ ��Ȯ�ϰ� ���ߴ� ���� ��ǥ�̴�.������ ������ �� ����(��, ��, ��, ��) �� �� ���̶� ����Ǿ� ������ �ϳ��� �������� �����Ѵ�.

	//���� ���, �Ʒ� �׸��� ���� 2, 1, 1���� ������, �ʷϻ�, �Ķ��� ������ �־� �� 4���� ������ �ִ�.

	//
	//����, �ܲ��̵��� ���� ������ ��õ���� ������ ������ ���ϻ����̶� �������� �ʷϻ��� �������� ���Ѵ�.���� ��ȸ�ڴ� �Ϲ� ��ȸ�� ���ϻ��Ϳ� ��ȸ�� ���� ���� ��ȸ�� �����Ϸ��� �Ѵ�.��ȸ�ڸ� ���� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͽ���.
#include <stdio.h>

	char picture1[110][110];
	char picture2[110][110];
	int pig[110][110];
	int pig_x[110][110];
	int pig_cnt;
	int pig_x_cnt;
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	void check_R(int i, int j)
	{
		int k;
		int ni;
		int nj;

		if (pig[i][j] == 1) return;
		if (picture1[i][j] == 'R')	pig[i][j] = 1;

		for (k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];

			if (picture1[ni][nj] == 'R') check_R(ni, nj);
		}
	}

	void check_RX(int i, int j)
	{
		int k;
		int ni;
		int nj;

		if (pig_x[i][j] == 1) return;
		if (picture2[i][j] == 'R' || picture2[i][j] == 'G') pig_x[i][j] = 1;

		for (k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];

			if (picture2[ni][nj] == 'R' || picture2[ni][nj] == 'G') check_RX(ni, nj);
		}
	}

	void check_G(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (pig[i][j] == 2) return;
		if (picture1[i][j] == 'G') pig[i][j] = 2;
		for (k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (picture1[ni][nj] == 'G') check_G(ni, nj);
		}
	}

	void check_B(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (pig[i][j] == 3) return;
		if (picture1[i][j] == 'B')pig[i][j] = 3;
		for (k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (picture1[ni][nj] == 'B') check_B(ni, nj);
		}
	}

	void check_BX(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (pig_x[i][j] == 3) return;
		if (picture2[i][j] == 'B') pig_x[i][j] = 3;
		for (k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (picture2[ni][nj] == 'B') check_BX(ni, nj);
		}
	}

	int main(void)

	{

		// ���⼭���� �ۼ�
		int i;
		int j;
		int n;



		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			scanf("%s", &picture1[i][1]); //(1,1)���� ���� ���̴�.

		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				picture2[i][j] = picture1[i][j]; //picture2�� picture1�� �����Ѵ�.
			}
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (picture1[i][j] == 'R') // cell���������� ������ �ƴϸ� ����߾���.
					//���⼭�� R, G, B�� ���� 3���� ���� �ϴ� �Ͱ� �����ϹǷ�
					//����� �ƴ϶� ���ǿ� �ش�Ǵ� ������ ��� ����.
				{
					if (pig[i][j] == 1) continue;
					check_R(i, j);
					pig_cnt++;
				}

				if (picture1[i][j] == 'G')
				{
					if (pig[i][j] == 2) continue;
					check_G(i, j);
					pig_cnt++;
				}

				if (picture1[i][j] == 'B')
				{
					if (pig[i][j] == 3) continue;
					check_B(i, j);
					pig_cnt++;
				}
			}
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{

				if (picture2[i][j] == 'R' || picture2[i][j] == 'G')
				{
					if (pig_x[i][j] == 1) continue;
					check_RX(i, j);
					pig_x_cnt++;
				}


				if (picture2[i][j] == 'B')
				{
					if (pig_x[i][j] == 3) continue;
					check_BX(i, j);
					pig_x_cnt++;
				}
			}
		}

		printf("%d %d", pig_cnt, pig_x_cnt);

		return 0;

	}
#endif

#if 0
	//�ֽ� �м� Ʈ���尡 ���׿� �� ���� ���� �ִ� �ϼҶ�� ���� ��� ���� �� ���� ���� �ִ� �ϼҸ� �뷮���� ���Ÿ� �ߴ�.�����ϰԵ�, �м� Ʈ���尡 ������ ���ؼ� ���� �α� �ִ� ���� �м��� ���� �ϳ� �ִ� �ϼ��̴�.

	//���� �ڽ��� �ϼҵ��� ���� �м� Ʈ���忡 �°� �ٲٰ� �ʹ�.�׷��� �� ���� ���� ���� ĥ�ؼ� �� ���� ������ ������� �Ѵ�.
	//
	//���� ��� �ϼ��� ������ N(����) * M(����) ũ���� ���ڷ� �Ʒ��� ���� �־����� �� :

	//................
	//
	//
	//..XXXX....XXX...
	//
	//
	//...XXXX....XX...
	//
	//
	//.XXXX......XXX..
	//
	//
	//........XXXXX...
	//
	//.........XXX....

	//���⼭ ������ ��X���� ���� �Ϻθ� ��Ÿ����.�� ��X���� ���� ������ ��޵Ǵ� ���� ���ϳ� �¿�� ����Ǿ� ���� �� �̴�.�밢������ ����� ���� ���� ������ ���� �ʴ´�.�׷��� �� �׸��� ��Ȯ�� �� ���̴�.��� ���� ��� �ϼҴ� ��Ȯ�� �� ���� ������ �ִ�.

	//���� �� ���� �� ������ ���� �� �ִ��� ���� ��ĥ�ϰ� �ʹ�.���� ������ �״� 3������ ���ο� ��X���� �߰��ϸ� �ȴ�. (���ο� ��X���� ��*���� ��ü�ؼ� ���� �� �� �ְ� �ߴ�.�Ʒ� �׸� ����)

	//................
	//
	//
	//..XXXX....XXX...
	//
	//
	//...XXXX*...XX...
	//
	//
	//.XXXX..**..XXX..
	//
	//
	//........XXXXX...
	//
	//.........XXX....

	//����� �� ���� ��� ���� �� ���� ���� �����ؼ� �ϳ��� ū ���� ���� �� �ְ� ���ο� ��X���� �ּ� ���� ���� �� �ְ� �����ִ� ���̴�.

#include <stdio.h>



	int main(void)

	{

		// ���⼭���� �ۼ�



		return 0;

	}
#endif

#if 0
	//�̷�Ż�� �κ� ��ȸ�� �����Ͽ���. ��ȸ�� ���Ǵ� �̷δ� ����(X), ����(Y) 100������ ũ���̸�, �̷θ� �� ĭ �̵��ϴ� ���� 1�ʰ� �ɸ���.
	//�κ��� ��������� ���������� ���� ���� �̵��� ��� �ɸ��� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
	int miro[110][110];
	int check[110][110];
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	int cnt = 1;
	int sx, sy;
	int ex, ey;
	void escape(int i, int j)
	{
		int ni;
		int nj;
		int k;
		if (i == ey && j == ex) return;

		cnt++;
		for (k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];

			if (miro[ni][nj] == 1) continue;
			if (check[ni][nj]) continue;
			if (ni <1 || nj <1 || ni>y || nj>x) continue;
			check[ni][nj] = cnt;
		}
		if (miro[ni][nj] == 0) escape(ni, nj);

	}

	int main(void)

	{
		// ���⼭���� �ۼ�
		int x, y;

		int i;
		int j;
		scanf("%d %d", &x, &y);
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		for (i = 1; i <= y; i++)
		{
			for (j = 1; j <= x; j++)
			{
				scanf("%1d", &miro[i][j]);
			}
		}

		check[sy][sx] = cnt;

		for (i = sy; i <sy + y; i++)
		{
			for (j = sx; j <sx + x; j++)
			{
				if (miro[i][j] == 1) continue;

				escape(i, j);

				printf("%d", cnt);
				return 0;

			}
		}


		return 0;

	}
#endif

#if 0//�̷� ã�� ������ BFS ������!
	//Q ���
	//Q�� �ʱⵥ���͸� ����
	//Q�� �����Ͱ� �ִ� ���� 
	//1. Q���� ������ 1�� read
	//2. ���� ������ ó��-> ���� ������ Q�� ����

	//�̷�Ż�� �κ� ��ȸ�� �����Ͽ���. ��ȸ�� ���Ǵ� �̷δ� ����(X), ����(Y) 100������ ũ���̸�, �̷θ� �� ĭ �̵��ϴ� ���� 1�ʰ� �ɸ���.
	//�κ��� ��������� ���������� ���� ���� �̵��� ��� �ɸ��� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>
	typedef struct st
	{
		int i; int j; int d; //����
	}Queue;
	Queue Q[100 * 100 + 10];
	int miro[110][110];
	int check[110][110];
	int wp, rp;
	int ti, tj, td;
	int x, y;
	int sx, sy;
	int ex, ey;
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	int BFS(void)
	{
		int ni;
		int nj;
		int k;
		Q[wp].i = sx;
		Q[wp].j = sy;
		Q[wp++].d = 0;
		check[sx][sy] = 1;

		while (rp < wp)
		{
			ti = Q[rp].i;
			tj = Q[rp].j;
			td = Q[rp++].d;

			if (ti == ex && tj == ey) return td;
			for (k = 0; k < 4; k++)
			{
				ni = ti + di[k];
				nj = tj + dj[k];

				if (ni<1 || nj<1 || ni>x || nj>y) continue;
				if (miro[ni][nj] || check[ni][nj]) continue;
				Q[wp].i = ni;
				Q[wp].j = nj;
				Q[wp++].d = td + 1;
				check[ni][nj] = 1;
			}
		}
	}
	int main(void)

	{	// ���⼭���� �ۼ�

		int i;
		int j;

		scanf("%d %d", &y, &x);
		scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
		for (i = 1; i <= x; i++)
		{
			for (j = 1; j <= y; j++)
			{
				scanf("%1d", &miro[i][j]);
			}
		}

		printf("%d", BFS());

		return 0;

	}
#endif

#if 0
	//N��M����ǿ� �� �� ���� �� �� ���� ���� �ִ�. ���� �̵� ������ ������ ���ٰ� �� ��, ���� �ּ��� �̵�Ƚ���� ���� �������� �Ѵ�.
	//���� ���� ��� ���� �ּ� �̵� Ƚ���� ���ϴ� ���α׷��� �ۼ��غ���.
#include <stdio.h>
	typedef struct st
	{
		int i, j, d;
	}Queue;
	Queue Q[100 * 100 + 10];
	int game[110][110];
	int check[110][110];
	int ti, tj, td;
	int n, m, R, C, S, K;
	int rp, wp;
	int di[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int dj[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int BFS(void)
	{
		int ni, nj;
		int k;
		Q[wp].i = R; Q[wp].j = C; Q[wp++].d = 0; check[R][C] = 1;
		while (rp < wp)
		{
			ti = Q[rp].i; tj = Q[rp].j; td = Q[rp++].d;
			if (ti == S && tj == K) return td;
			for (k = 0; k < 8; k++)
			{
				ni = ti + di[k];
				nj = tj + dj[k];

				if (check[ni][nj]) continue;
				if (ni<1 || nj<1 || ni>n || nj>m) continue;
				Q[wp].i = ni; Q[wp].j = nj; Q[wp++].d = td + 1; check[ni][nj] = 1;
			}
		}
		return -1;
	}


	int main(void)
	{
		// ���⼭���� �ۼ�
		scanf("%d %d", &n, &m);
		scanf("%d %d %d %d", &R, &C, &S, &K);
		game[R][C] = 1;
		game[S][K] = 2;
		printf("%d", BFS());
		return 0;
	}
#endif

#if 0 //���� ����-�Ｚ�� ������.
	//� ��ȭ �� ������ ���� ���� 3�� �Ⱦ��ؼ� ���� ü�迡�� 3�̶�� ���ڸ� ������� �ʴ´�.�鼺�鵵 ���� 3�� ������ ������ �޾� �鿩 ���� 3�� ���� ������� �ʴ´�.

	//�� ������ ���ڴ� 0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, ... �̷��� ���ڰ� ����ȴ�.��, ��� �ڸ�(1�� �ڸ�, 10�� �ڸ�, 100�� �ڸ�, ...)���� 3�̶� ���ڴ� ��Ÿ���� �ʴ´�.

	//�� ����� 3�� ���� ������ 10������ ����ϴ� �ٸ� ����� ������ �� ��쿡 ���� ȥ���� �ް� �ȴ�.���� ��� �� ������ 4�� �ٸ� ������ 3�� ����, �� ������ 15�� �ٸ� ������ 13�� ����.

	//��Ȯ�� �ŷ����� ������ ���� �� ������ ���� N�� 10�������� ��ȯ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
	long long int func(long long int n)
	{
		while (n > 0)
		{
			if (n % 10 == 3) return 1;
			n /= 10;
		}
		return 0;
	}

	int main(void)

	{
		long long int n = 0;
		long long int cnt = 0;
		long long int sol;
		scanf("%lld", &sol);
		for (;;)
		{
			n++;
			if (func(n)) continue;
			else cnt++;
			if (n == sol)
			{
				printf("%ll", cnt);
				return 0;
			}
		}
		return 0;
	}
#endif

#if 0
	//â�� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, ���� ���� ���� �丶��鵵 ���� �� �ִ�.
	//���� �� �Ϸ簡 ������, ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�.
	//�ϳ��� �丶���� ������ ���� ����, ������, ��, �� �� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�.
	//�밢�� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�.
	//	ö���� â�� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ���, �� �ּ� �ϼ��� �˰� �;� �Ѵ�.
	//�丶�並 â�� �����ϴ� ���ڸ���� ���ڵ��� ũ��� ���� �丶���� ���� ���� �丶����� ������ �־����� ��, ��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ��϶�.��, ������ �Ϻ� ĭ���� �丶�䰡 ������� ���� ���� �ִ�.
#include <stdio.h>
	typedef struct st
	{
		int i, j, d;
	}Queue;
	Queue Q[1000 * 1000 + 10];
	int tomato[1010][1010];
	int check[1010][1010];
	int ti, tj, td;
	int si, sj;
	int rp, wp;
	int m, n;
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };

	int BFS(void)
	{
		int ni, nj;
		int k;
		int i, j;


		while (rp < wp)
		{
			ti = Q[rp].i; tj = Q[rp].j; td = Q[rp++].d;
			//��������?
			for (k = 0; k < 4; k++)
			{
				ni = ti + di[k]; nj = tj + dj[k];
				if (check[ni][nj] || tomato[ni][nj]) continue;
				if (ni<1 || nj<1 || ni>n || nj>m) continue;
				Q[wp].i = ni; Q[wp].j = nj; Q[wp++].d = td + 1; check[ni][nj] = 1;
			}
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (tomato[i][j]) check[i][j] = 1;
				if (check[i][j] == 0) return -1;
			}
		}
		return td;
	}

	int main(void)

	{	// ���⼭���� �ۼ�
		int i, j;
		int tom = 0;
		scanf("%d %d", &m, &n);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf("%d", &tomato[i][j]);
				if (tomato[i][j] == 1)
				{
					Q[wp].i = i; Q[wp].j = j; Q[wp++].d = 0; check[i][j] = 1;
				}
				if (tomato[i][j] != 1) tom = 1;
			}
		}
		if (!tom)
		{
			printf("%d", 0); return 0;
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (tomato[i][j] == 0 || tomato[i][j] == -1) continue;
				else
				{
					si = i; sj = j;
				}
			}
		}
		printf("%d", BFS());
		return 0;
	}
#endif	

#if 0
	//�ʺ�켱Ž��(BFS)�� �׷����� ������ �� �������� ����Ͽ�, ����� ������ �� �ϳ��� ���ؼ� �ʺ� ������ ���� Ž���� ������ Ž�����̴�.�� Ž������� ���, ü��, �̷�ã��, ������ġ �׷����� �ִܰ�� Ž�� ���� �پ��� �о߿� Ȱ��Ǵ� �˰����̴�.���� ��� ������ ���� �׷����� ����.
	//�� �׷������� 1�� �������� ����� �ʺ�켱Ž�� ����� ������ ����.
	//
	//1 - 2 - 4 - 5 - 3 - 6 - 7
	//
	//��, �� �������� �� �� �ִ� ���� ���� ���� ��� ���� �Էµ� �������� ���� �湮�Ѵ�.FIFO ��, 2 4, 2 3 ������ �ԷµǾ��ٸ� 2�� �������� 4���� ���� �湮�ϰ� ���߿� 3���� �湮�ϵ��� �ۼ��ؾ� �Ѵ�.
	//
	//������ �־����� ��� �׷����� ����� ������ġ �׷����̴�.
#include <stdio.h>
int Q[210 * 210 + 10]; 
int rp, wp;
int si, t;
int node, edge;
int s[210];
int e[210];
int check[210];
void BFS(void)
{
	int k;

	printf("%d ", 1);
	while (rp < wp)
	{
		t = Q[rp++];

		for (k = 1; k <= edge; k++)
		{
			
			if (s[k] == t)
			{
				Q[wp++] = e[k]; 
				if (check[e[k]]) continue;
				check[e[k]] = 1;
				printf("%d ", e[k]);
			}

			if (e[k] == t)
			{
				Q[wp++] = s[k];
				if (check[s[k]]) continue;
				check[s[k]] = 1;
				printf("%d ", s[k]);
			}
		}
	}
	
	
}

int main(void)
{
	int i;
	scanf("%d %d", &node, &edge);

	for (i = 1; i <= edge; i++)
	{
		scanf("%d %d", &s[i], &e[i]);
	}

	for (i = 1; i <= edge; i++)
	{
		if (s[i] == 1 || e[i]==1)
		{
			Q[wp++] = 1; check[1] = 1;
		}
	}

	BFS();


	return 0;
}
#endif

#if 0
	//����� N���� �Ȱ��� ũ���� �ҽ����� ���� �ִ�.�׳�� �� �ҽ����� M���� ����鿡�� �Ȱ��� �������ַ��� �Ѵ�.�ҽ����� ������� �ֱ� ���ؼ��� �ҽ����� �߶�� �ϴµ� �ҽ����� �������� ���� �ڸ��� ���� �� ���� ������ �ҽ����� �ּ��� ���� �߶�� �Ѵ�.���� ���� �ҽ����� �ּ� �� �� �߶�� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͽ���.
#include <stdio.h>
	int main(void)
	{
		// ���⼭���� �ۼ�
		int n, m;
		int g;
		int cnt = 0;
		scanf("%d %d", &n, &m);

		while (n >= 0)
		{
			if (n%m == 0)
			{
				cnt += 0;
				break;
			}

			else
			{
				if (m%n) cnt = n*(m / n) + 1;
				else cnt = n*(m / n - 1);
				break;
			}

		}

		printf("%d", cnt);

		return 0;

	}
#endif

#if 0
	//� �� ���� �ð��� ������ �ڸ������� ���� �ڸ��� ���ڳ��� ���ϴ� ����� ����.�̷��� ���� �߿��� '�ڸ� �ø�' - 10�̻��� ���ڰ� ���ͼ� ���� �ڸ��� 1�� �����ִ� �� - �� �߻� �ϴ� ���� �� �� �ִ�. 2���� ���ڰ� ������ ���, �� ���� �ڸ� �ø��� �߻��ϴ��� �˾ƺ��� ���α׷��� �ۼ��϶�.
#include <stdio.h>
	int cnt;
	int carry;
	void digit(int a, int b)
	{
		while (a != 0 || b != 0)
		{
			if (a % 10 + b % 10 + carry >= 10)
			{
				a /= 10;
				b /= 10;
				carry = 1;
			}

			else
			{
				a /= 10;
				b /= 10;
				carry = 0;
			}
			if (carry)
			{
				cnt++;
			}
		}
		if (cnt == 1) printf("%d carry operation.", 1);
		else if (cnt) printf("%d carry operations.", cnt);
		else printf("No carry operation.");
	}


	int main(void)

	{

		// ���⼭���� �ۼ�


		int a, b;

		scanf("%d %d", &a, &b);
		digit(a, b);

		return 0;

	}
#endif

#if 0
	//������ ���Ͽ��� ������ ������������ ��ġ �Ǿ��ִ�.������ �� ���� ���������� �ʹ��� ����ȹ������ ��ġ�Ǿ��� ������, �����δ� ���� �帣�� �ʴ� ������������ �ټ� ��ġ�Ǿ� �ִٰ� �Ѵ�.�׷��� ���������� ��ġ�� �����ϴ� ������� ���� ������ ���������� ��ġ ���¸� Ȯ���� ��, ���� ���� �帣�� �ʴ� ������������ �����ϴ� ���縦 �����Ϸ� �Ѵ�.

	//������ ���� �������� ��ġ�� ���¿���(0, 0) ���� ���޿� �̶�� �Ѵٸ� 5���� ������������ ���� �帣�� �ʴ� ���� �������̹Ƿ� ���� ����� �ȴ�.

	//������ ���� ������ ���� ���������� ��ġ ������ �������޿��� ��ġ�� �־����� ��, �����ؾ� �� ���� �������� ������ ���Ͻÿ�.

#include <stdio.h>
	int map[20][20];
	int check[20][20];
	int cnt;
	int di[] = { -1, 1, 0, 0 };
	int dj[] = {}

		int check_map(int i, int j)
	{
		int ni, nj, k;
		if (check[i][j]) return;

		cnt++;

	}
	int main(void)
	{	// ���⼭���� �ۼ�

		int i, j;
		int n;
		int x, y; // �������޿� ������ǥ
		scanf("%d", &n);
		scanf("%d %d", &x, &y);

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (map[i][j] == 0) continue;
				if (check[i][j]) continue;
				check_map(i, j);
			}
		}
		printf("%d", n*n - cnt);

		return 0;

	}
#endif

#if 0
#include <stdio.h>
	int student[110];
	int apple[110];
	int left[110];


	int main(void)

	{

		// ���⼭���� �ۼ�
		int n;
		int i;
		int sum = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &student[i], &apple[i]);
		}

		for (i = 0; i < n; i++)
		{
			left[i] = apple[i] % student[i];
			sum += left[i];
		}

		printf("%d", sum);
		return 0;

	}
#endif



#if 0
#include <stdio.h>

	int N1[30];
	int N2[30];
	int N3[50];
	int sum[100];

	int main(void)

	{

		// ���⼭���� �ۼ�
		int i, j, h;
		int n1, n2, n3;
		int x = 0;
		int max = -10000;
		scanf("%d %d %d", &n1, &n2, &n3);

		for (i = 1; i <= n1; i++)
		{
			for (j = 1; j <= n2; j++)
			{
				for (h = 1; h <= n3; h++)
				{
					x = i + j + h;
					sum[x] += 1;
				}
			}
		}

		for (i = 1; i <100; i++)
		{
			if (max < sum[i])
			{
				max = sum[i];
			}
		}

		for (i = 1; i < 100; i++)
		{
			if (sum[i] == max)
			{
				x = i;
				printf("%d", x);
				return 0;
			}
		}


		return 0;

	}
#endif

#if 0
#include <stdio.h>
	typedef struct st
	{
		int i, j, d;
	}Queue;
	Queue Q[110 * 110 + 10];
	int star[110][110];
	int check[110][110];
	int ti, tj, td;
	int wp, rp;
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	int left, cnt;
	int R, C;
	int x, y;

	int BFS(void)
	{
		int ni, nj, k;
		int i, j;
		while (rp < wp)
		{
			ti = Q[rp].i; tj = Q[rp].j; td = Q[rp++].d;

			for (k = 0; k < 4; k++)
			{
				ni = ti + di[k];
				nj = tj + dj[k];

				if (check[ni][nj]) continue;
				if (star[ni][nj] == 0) continue;
				if (ni<1 || nj<1 || ni>R || nj>C) continue;

				Q[wp].i = ni; Q[wp].j = nj; Q[wp++].d = td + 1; check[ni][nj] = 1;
			}
		}
		for (i = 1; i <= R; i++)
		{
			for (j = 1; j <= C; j++)
			{
				if (star[i][j] == 0) check[i][j] = 1;
			}
		}
		return td;
	}

	int main(void)
	{
		// ���⼭���� �ۼ�
		int i, j;

		scanf("%d %d", &C, &R);

		for (i = 1; i <= R; i++)
		{
			for (j = 1; j <= C; j++)
			{
				scanf("%1d", &star[i][j]);
			}
		}

		scanf("%d %d", &y, &x);
		Q[wp].i = x; Q[wp].j = y; Q[wp++].d = 3; check[x][y] = 1;

		printf("%d\n", BFS());


		for (i = 1; i <= R; i++)
		{
			for (j = 1; j <= C; j++)
			{
				if (check[i][j] == 0) left++;
			}
		}
		printf("%d", left);

		return 0;

	}
#endif

#if 0
#include <stdio.h>
	typedef struct st
	{
		int i, j, d;
	}Queue;
	Queue Q[110 * 110 + 10];
	int skin[110][110];
	int check[110][110];
	int sum[110];
	int ti, tj, td;
	int si, sj, ei, ej;
	int wp, rp;
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	int min = 10000;
	int n;


	int BFS(void)
	{
		int ni, nj, k;
		int i, j;

		Q[wp].i = 1; Q[wp].j = 1; Q[wp++].d = skin[1][1]; check[1][1] = 1;


		while (rp < wp)
		{

			ti = Q[rp].i; tj = Q[rp].j; td = Q[rp++].d; sum[ti] = td;



			for (k = 0; k < 4; k++)
			{
				ni = ti + di[k];
				nj = tj + dj[k];

				if (check[ni][nj]) continue;
				if (ni<1 || nj<1 || ni>n || nj>n) continue;

				Q[wp].i = ni; Q[wp].j = nj; Q[wp++].d = td + skin[ni][nj]; check[ni][nj] = 1;

			}
		}
		return td;

	}

	int main(void)
	{
		// ���⼭���� �ۼ�
		int i, j;

		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%1d", &skin[i][j]);
			}
		}
		BFS();

		for (i = 0; i < 110; i++)
		{
			if (sum[i] == 0) continue;
			if (min>sum[i])
			{
				min = sum[i];
			}
		}

		printf("%d", min);
		return 0;

	}
#endif

#if 0
#include <stdio.h>

	int a[110][110];
	int check[110][110];
	int n;
	int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //8���� ���� �� �� ���
	int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 };//�����¿�, ���´밢��, ��� �밢��, ���´밢��, �Ͽ� �밢��


	void check_lake(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (check[i][j] == 1) return;//��������-�̹� �߰ߵ� ȣ����� ����.

		check[i][j] = 1; //���� �߰��� ȣ���� 1�� ��´�.
		for (k = 0; k < 8; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (a[ni][nj]) check_lake(ni, nj); //8���� ��� �� ���� ȣ���� ������ �ٽ� check_lake�� ȣ��
		}

	}

	int main(void)

	{

		// ���⼭���� �ۼ�
		int i;
		int j;
		int cnt = 0;

		scanf("%d", &n);
		for (i = 1; i < n + 1; i++) //8������ ��� ����ؾ� �� ���� (1,1)���� ��� ����
		{
			for (j = 1; j < n + 1; j++)
			{
				scanf("%1d", &a[i][j]);
			}
		}


		for (i = 1; i < n + 1; i++)
		{
			for (j = 1; j < n + 1; j++)
			{
				if (a[i][j] == 0) continue;
				if (check[i][j] == 1) continue;
				check_lake(i, j);
				cnt++;
			}
		}

		printf("%d", cnt);


		return 0;

	}
#endif

#if 0
#include <stdio.h>
	char chess[20][20];
	int check[20][20];

	int main(void)

	{
		// ���⼭���� �ۼ�
		int R, C, A, B;
		int i, j, h, k;
		int flag = 1;


		scanf("%d %d", &R, &C);
		scanf("%d %d", &A, &B);

		for (i = 1; i <= A; i++)
		{
			for (j = 1; j <= B; j++)
			{
				chess[i][j] = 'X';
			}
		}

		for (i = 1; i <= R*A; i++)
		{
			for (j = 1; j <= C*B; j++)
			{
				if (chess[i - A][j] == 'X' || chess[i][j - B] == 'X') flag = 0;
				else if (chess[i - A][j] == '.' || chess[i][j - B] == '.')flag = 1;

				for (h = 0; h < A; h++)
				{
					for (k = 0; k < B; k++)
					{
						if (flag) chess[i + h][j + k] = 'X';
						else chess[i + h][j + k] = '.';
					}
				}
			}
		}

		for (i = 1; i <= R*A; i++)
		{
			for (j = 1; j <= C*B; j++)
			{
				printf("%c", chess[i][j]);
			}
			printf("\n");
		}

		return 0;

	}
#endif
#if 0
#include <stdio.h>
char chess[400][400];
int check[400][400];


int main(void)
{
	// ���⼭���� �ۼ�
	int R, C, A, B;
	int i, j, h, k;
	int flag = 1;


	scanf("%d %d", &R, &C);
	scanf("%d %d", &A, &B);

	for (i = 1; i <= R*A; i++)
	{

		for (j = 1; j <= C*B; j++)
		{
			check[i][j] = -1;
		}
	}

	for (i = 1; i <= A; i++)
	{
		for (j = 1; j <= B; j++)
		{
			chess[i][j] = 'X';
			check[i][j] = 1;
		}
	}


	for (i = 1; i <= R*A; i += A)
	{
		for (j = 1; j <= C*B; j += B)
		{
			if (check[i][j] == 1 || check[i][j] == 2) continue;
			for (h = 0; h < A; h++)
			{
				for (k = 0; k < B; k++)
				{
					if (check[i - A][j] == 2 || check[i][j - B] == 2)
					{
						chess[i + h][j + k] = 'X';
						check[i + h][j + k] = 1;
					}
					else if (check[i - A][j] == 1 || check[i][j - B] == 1)
					{
						chess[i + h][j + k] = '.';
						check[i + h][j + k] = 2;
					}
				}
			}

		}
	}

	for (i = 1; i <= R*A; i++)
	{
		for (j = 1; j <= C*B; j++)
		{
			printf("%c", chess[i][j]);
		}
		printf("\n");
	}

	return 0;

	}
#endif

#if 0
#include <stdio.h>
//�ڿ��� N�� M�� �Է� �޾Ƽ� �ֻ����� N�� ������ ���� ���� ���� M�� ���� �� �ִ� ��� ��츦 ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//ù �ٿ� �ֻ����� ���� Ƚ�� N(2��N��7)�� ���� �� M(1��M��40)�� ���´�.
//�ֻ����� ���� Ƚ���� ���� M�� �Ǵ� ��츦 ��� ����Ѵ�.
//���� ���ں��� ����Ѵ�.

int N, M;
int sum;
int n;
int s[7 + 10];
void DFS(int n, int sum)
{
	int i;
	if (n > N)
	{
		if (sum == M)
		{
			for (i = 1; i <= N; i++)
			{
				printf("%d ", s[i]);
			}
			printf("\n");
		}
	
		return; 
	}

	for (i = 1; i <= 6; i++)
	{
		s[n] = i;
		DFS(n + 1, sum + i);
	}

}
int main(void)
{
	scanf("%d %d", &N, &M);
	DFS(1, 0);
	return 0;
}

#endif

#if 0
//������ ���ϴ� ö���� ���ν�Ű�� ���� �ڿ������� �ְ�, �� �߿� �� ���� ���� ��� �� ���� K�� �� �� �ִ��� �˾ƺ���� ���״�. ö�� ��Ӵϰ� �ڿ������� �������� �����ؼ� ���ε� �������� �ƴ��� �𸣰� �ִ�. ��Ӵϰ� ä���� �� �� �ְ� �־��� ������ ���� ã������.
//ù ��° �ٿ� �׽�Ʈ ���̽� ���� T(1��T��10)�� �־�����.
//
//�� ��° �ٺ��� �Ʒ� ������ T�� ��ŭ �־�����.
//
//ù �ٿ� �ڿ��� ���� N(5 <= N <= 20)�� K(1 <= K <= 2, 000, 000)�� �������� ���еǾ� �Էµȴ�.
//
//���� �ٿ� N���� �ڿ��� di(1 <= di <= 100, 000)�� �������� ���еǾ� �Էµȴ�.

//T�ٿ� ���� �� �׽�Ʈ ���̽� ���� �־��� �ڿ��� �� �� ���� ���� K�� �Ǹ� ��YES���� �ƴϸ� ��NO���� ����Ѵ�.

#include <stdio.h>
int s[30];
int a[30];
int sum;
int n;
int T, N, K;
int sol;

void DFS(int n, int sum)
{
	if(sum>K || sol==1) return; //����ġ��
	if (n > N) //��������
	{
		if (sum == K) sol = 1;
		return;
	}
	DFS(n + 1, sum + a[n]);
	DFS(n + 1, sum);
}


int main(void)

{	// ���⼭���� �ۼ�
	int i;
	scanf("%d", &T);
	

	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}
		sol = 0;
		DFS(1, 0);

		if (sol) printf("YES\n"); //���ڷ� ������ �� ���� flag��ȣ�� main���� �ذ��ϱ�
		else printf("NO\n");
	}

	return 0;

}

//�������� DFS �ع�
//int DFS(int n, int sum)
//{
//	if (sum>K || sol == 1) return; //����ġ��
//	if (n > N) //��������
//	{
//		if (sum == K) return 1;
//		return 0; //�ƴ� ��� 0�� �Ǵ� �͵� �� ����.
//	}
//	if(DFS(n + 1, sum + a[n])) return 1;
//	if(DFS(n + 1, sum)) return 1;
//	return 0;
//}
//
//
//int main(void)
//
//{	// ���⼭���� �ۼ�
//	int i;
//	scanf("%d", &T);
//
//
//	while (T--)
//	{
//		scanf("%d %d", &N, &K);
//		for (i = 1; i <= N; i++)
//		{
//			scanf("%d", &a[i]);
//		}
//		sol = 0;
//
//		if (DFS(1,0)) printf("YES\n"); //���ڷ� ������ �� ���� flag��ȣ�� main���� �ذ��ϱ�
//		else printf("NO\n");
//	}
//
//	return 0;


#endif

#if 0
//(��)���ÿ����� ���� ���� ������ ���� ���� ��ȹ�̴�.�׷��� ������ ���� ��Ҹ� �����Ͽ���.�׸��� �� ������ �� ��ҿ� ���� ��쿡 ��� ����� �����Ͽ���.���� �� �Ʒ��� ǥ�� ����.
//1 2 3
//
//A 4 7 3
//
//B 2 6 1
//
//C 3 9 4
//

//A, B, C �� �ǹ��� ��Ÿ����, 1, 2, 3�� ��Ҹ� ��Ÿ����.���� �� �ǹ� B�� ��� 1�� ����� ����� 2�� ���, ��� 2�� ����� ����� 6, ��� 3�� ����� ����� 1��ŭ ���.���� �� ��ҿ��� �� �ǹ��ۿ� ���� �� ����.���� A�� ��� 2��, B�� ��� 3��, C�� 1�� ����� ��ü ����� 7 + 1 + 3 = 11�� �ʿ��ϴ�.�׷��� A�� 3, B�� 1, C�� 2�� ����� 3 + 2 + 9 = 14 �� �ʿ��ϴ�.
//�� ������ ��� ��ҿ� ����� ����� ���� �ּҰ� �Ǵ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//�Է� ������ ù ���� ������ ���� n(1��n��15)�� ����ִ�.
//
//�� ���� n �ٿ��� �� �ǹ��� �� ��ҿ� ���� ��쿡 ��� ����� �Էµȴ�.���� �� �� ���� n���� ���� �Էµȴ�.
//
//����� ��Ÿ���� ���� ������ 1�̻� 100�̸��̴�.
//ù �ٿ��� �ּҺ���� ����Ѵ�.
//
//��° �ٿ��� �ǹ��� ���� ��ҵ��� ���ĺ� ������ ���� ��ĭ�� �ϳ��� �ΰ� ����Ѵ�.


#include <stdio.h>
int a[30][30]; 
int check[30]; //�� ��ҿ� �� �ǹ��� ����� ������, A�� �ִ� ��Ҵ� �н��ϴ� �� �ߺ����� �ʿ�
int s[30];
int ps[30];
int sum;
int min = 0x7fffffff;
int N;

void DFS(int n, int sum)
{
	int i;
	if (min <= sum) return; //����ġ��
	
	if (n > N)
	{
		if (min > sum)
		{
			min = sum;
			for (i = 1; i <= N; i++)
			{
				ps[i] = s[i]; //�ּ� ����� �� ��� ��ȣ ����
			}
		}
		return;
	}

	for (i = 1; i <= N; i++)
	{
		if (check[i]) continue;
		check[i] = 1; s[n] = i; //��� ��ȣ ����
		DFS(n + 1, sum + a[n][i]);
		check[i] = 0;
	}
}

int main(void)

{

	// ���⼭���� �ۼ�
	int i,j;
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	DFS(1, 0);

	printf("%d\n", min);
	for (i = 1; i <= N; i++)
	{
		printf("%d ", ps[i]);
	}
	return 0;

}
#endif

#if 0
//���� �ڵ��� ���� ��ȸ�� �ų� ������ �ִ�.�� ��ȸ������ ����������� ������������ �Ÿ��� ���� �ֱ� ������ ���� ���߿� �� �ڵ����� ����Ҹ� �湮�Ͽ� ���� �޾ƾ� �Ѵ�.����ҵ��� ����������� ������������ ���� �氡�� ������ ������� ���ʷ� ��ȣ�� �پ� �ִ�.

//�� ��ȸ������ �����ϴ� ������ ������ ���Ͽ� ���� ���� �ʰ� �̸� ���� �Ÿ��� �ʰ��Ͽ� �� �� ������ ��Ģ�� ���Ͽ���.�׸��� ����Ҹ��� �����ϴµ� �ɸ��� ���� �ð��� ���� �ٸ� �� �ִ�.

//����ҿ��� �����ϴµ� �ɸ��� �ð��� ���� ���� �Ϸ��� �� �� �ּ� �� ����ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���� ���, �Ʒ� �׸��� ���� ����Ұ� 5�� �ְ�, �� �� ���� �ް� �ִ� 140���� �� �� �ִ� ��츦 ������ ����.����������� ����� ������� �Ÿ��� 100���̰�, ����� ���� �湮�Ͽ� ������ �� �ɸ��� �ð��� 5���̴�.

//�ڵ����� ����������� ��ȸ ��Ģ�� ��Ű�鼭 ����� ��, ��, �븦 ���ʴ�� �湮�Ͽ� ������������ �� �� �ְ�, ����� ��, �긦 �湮�Ͽ� �� ���� �ִ�.����� ��, ��, �븦 �湮�ϴ� ��쿡�� 16��(= 5 + 4 + 7��)�� �ɸ��µ�, �̰��� ����� ��, �긦 �湮�Ͽ� �ɸ��� 21��(= 10 + 11��)���� �� ���� �ð��� ���� �ɸ���.

//�Է� �� ù° �ٿ��� ���� ���� �ʰ� �� �� �ִ� �ִ� �Ÿ��� �־�����.��° �ٿ��� ������� ������ �ԷµǴµ� ����� ���� 50�� �����̴�.��° �ٿ��� ������ ����� ������ �Ÿ��� ���ʷ� �־�����.��° �ٿ��� ����� �� ���� �ð��� ���ʷ� �־�����.��� �Է��� ���� �����̴�.

//ù° �ٿ� ����ҿ��� �����ϴµ� �ɸ��� �� ���� �ð��� ����Ѵ�. ����Ҹ� ���� �湮���� �ʾƵ� �Ǵ� ��쿡 �� ���� �ð��� 0���� ����Ѵ�.


#include <stdio.h>
int N;
int max;
int min=0x7fffffff;
int d[60];
int t[60];
int sum, d_sum;
int n;
int h;

void DFS(int n, int sum, int d_sum) //����Ʈ������ if-else�� ���� �ʴ´�.(������ ��� ��츦 ����)
{
	if (min <= sum) return;
 	if (n > N)
	{
		if (min > sum) min = sum;
		return;
	}

	if (d_sum + d[n] <= max)
	{
		DFS(n + 1, sum, d_sum + d[n]); //���� �� �޴� ���
	}
	DFS(n + 1, sum + t[n], d[n]); //���� �޴� ���

}


int main(void)

{
	int i;
	// ���⼭���� �ۼ�
	scanf("%d", &max);
	scanf("%d", &N);

	for (i = 0; i <= N; i++)
	{
		scanf("%d",&d[i]);
	}

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &t[i]);
	}

	DFS(1, 0, d[0]);
	printf("%d", min);
	return 0;

}

#endif

#if 0
//���� ���� X�� K�� �־����� ��, ������ �������� �����ϴ� ������ ���� ���� Y �߿��� K��°�� ���� ���ڸ� ã�� ���α׷��� �ۼ��϶�.

//X + Y = X | Y

//���⼭ '|'�� OR������ ���Ѵ�.OR������ �� ���� ������ 2������ �ٲ� ������ 2������ �̷��� ������ ������ ��ġ�� ���ؼ� �� �� 0�� ��� 0, �� �߿� �ϳ��� 1�� ��� 1�� ���ϴ� �����ڴ�.

//���� ��� X�� 3�̰�, Y�� 6�� ��� X | Y�� ������ ����. 011 OR 110 = 111, 111�� 10������ �ٲٸ� 7�̹Ƿ�, 3 | 6 = 7�� �ȴ�.

#include <stdio.h>
long long int X[70];
long long int K[70];
long long int Y[70];
long long int x_cnt, k_cnt;

long long int binary(long long int n, long long int *a, long long int cnt)
{
	while (n>0)
	{
		a[cnt++] = n % 2;
		n /= 2;
	}
	return cnt;
}

long long int decimal(long long int *a, long long int cnt)
{
	long long int pow = 1;
	long long int i = 0;
	long long int n=0;
	while (cnt--)
	{
		n += a[i] * pow;
		i++; 
		pow *= 2;
	}

	return n;
}


int main(void)

{
	long long int x, k;
	long long int i;
	long long int h = 0;
	scanf("%lld %lld", &x, &k);
	x_cnt=binary(x, X, x_cnt);
	k_cnt=binary(k, K, k_cnt);

	for (i = 0; i < 64; i++)
	{
		if (X[i] == 1) X[i] = 0;
		else X[i] = K[h++];
	}
	
	printf("%lld", decimal(X,i));
	return 0;
}

#endif

#if 0
//������ �� Ǯ��� �ҹ��� �����̴� ��� �ø��ǾƵ� ��ȸ�� �����ϰ� �;� �ߴ�.��ȸ�� �����Ͽ� ���̶� ���� �� Ÿ�� ���� �����̾�����, �� ���� �ɸ��� ���� �־���.
//������ �ø��ǾƵ� ��ȸ�� ��� �ؿܿ��� ������ ����� ����� ���� ������ ���� ���ٴ� ���̴�.�ᱹ���� ������ �ٽ� ���ƿ;� �ϴµ�, ��� ��ȸ�� 1������ �����ϰ� ������ ���ƿ��� ��� ���� �ּ�ȭ�ϰ� �ʹ�.�����̴� �̰��� �ذ����� ���ϸ�, ��ȸ�� �����ϱⰡ ��ư� �ȴ�.��ȸ�� �����ϱ⸸ �ϸ� �������� �˰��� ������ Ǯ �� �ֱ� ������ ��⸦ ����ϴ� �� �̿��� ������ ������� �ʾƵ� �ȴ�.
//ù ���� �����ϴ� ��ȸ�� �� N(1��N��12)�� �Է� �޴´�.�̶�, �����(��)�� 1������ �Ѵ�.
//
//��° ���� N*N ũ���� ��ȸ �������� �������� �̵��ϴ� �װ���(0���װ���<100)�� ���´�.�� �װ���� �� ĭ�� �������� ���еȴ�.���࿡ ���������� �������� �̵��� �� �ִ� �װ��ΰ� ���ٸ� �װ����� ���� 0���� ǥ���Ѵ�.
//������ ����Ͽ� ��ü ��ȸ�� ��� �����ϰ� ���ƿ� ��, �ּ��� �װ��Ḧ ����Ѵ�.
#include <stdio.h>

int fee[20][20];
int check[20];
int N;
int min= 0x7fffffff;
void DFS(int n, int sum, int game)
{
	int i;
	if (min <= sum) return;
	if (n >=N)
	{
		if (min > sum + fee[game][1]) min = sum + fee[game][1];
		return;
	}

	for (i = 1; i <= N; i++)
	{
		if (check[i]) continue;
		check[i] = 1;
		DFS(n + 1, sum + fee[game][i], i);
		check[i] = 0;
	}
}
int main(void)

{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &fee[i][j]);
			if (fee[i][j] == 0) fee[i][j] =10000; //0x7ffffff����. 0x7fffffff�� ������ ������ �Ǿ����.
		}
	}
	check[1] = 1; //���� ���� ���� üũ�ϱ�
	DFS(1, 0, 1);

	printf("%d", min);

	return 0;

}
#endif

#if 0
//��� John�� �ֱ� �� �������� ���� å���̸� ����������, å�� ���� �ӵ��� ä������ ������ ���� ���κп��� ������ �����ִ�.
//
//��� John�� N������ �Ҹ� ������ �ִ�.(1 <= N <= 20) ������ ���� Ű�� H_i�̴�.(1 <= H_i <= 1, 000, 000)
//
//å���̴� B ���̸� ������ �ִ�. (1 <= B <= S, S�� ��� ���� Ű�� �հ���).
//
//å������ �� ���κп� ��� ���ؼ�, �ϳ� Ȥ�� ���� ������ �Ұ� ������ �Ӹ� ���� �ö� �� �ִ�.�׷��� �׵��� ��ü ���̴� ������ ���� Ű�� �հ谡 �ȴ�.�ҵ��� å������ �� ���κп� ��� ���ؼ��� �� ��ü���̰� å���� ���̿� ���� ���Ƽ��� �� �ȴ�.
//
//�ҵ��� ������ �Ӹ� ���� �ö󼭰� �Ǹ�, ������ �������� ���������� ������, ����� �� ���� å������ �� ���κп� ���� �� �ְ� �ϴ� �ҵ��� Ű�� ���� �ּҰ��� ã�� ���̴�.����� ���α׷��� ����� ã�� �� �ҵ��� Ű�� ���� å���̷κ��� �󸶳� �ʰ��ϴ����� ����ϸ� �ȴ�.
//ù ��° �ٿ��� �׽�Ʈ���̽��� ���� T�� �Էµȴ�.
//
//�� ��° �ٺ��� T���� �׽�Ʈ���̽� ��Ʈ�� �־�����.
//
//�׽�Ʈ���̽��� ù��° ���� ���� ������ N�� B�� �־�����. (1 <= N <= 20, 1 <= B <= S, S�� ��� ���� Ű�� �հ�)
//
//�׽�Ʈ���̽��� �ι�° �ٺ��� N�ٿ� �� ���� Ű H_i�� �־�����. (1 <= H_i <= 1, 000, 000)
//������ �ҵ��� Ű�� �հ� å���� ������ ���̸� ����Ѵ�.
#include <stdio.h>
int cow[30];
int N;
int min = 0x7fffffff;
int T, B;

void DFS(int n, int sum)
{
	if (min <= sum ||min==0) return;//min�� �ּ� 1�̻��� �Ǿ�� �Ѵ�.
	if (n > N)
	{
		if (sum >= B)
		{
			if (min > sum) min = sum;
		}
		return;
	}

	DFS(n + 1, sum + cow[n]);
	DFS(n + 1, sum);
}
int main(void)
{
	int i;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &N, &B);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &cow[i]);
		}
		min = 0x7fffffff;
		DFS(1, 0);
		printf("%d\n", min-B);
	}
	

}


#endif

#if 0
//ü������ queen�� ����, ����, �밢�� �������� ��� ���̳� �� ���� ������ �� �ִ�.�� ������ ���� ü���ǿ��� queen�� X��� ǥ�õ� ��ġ���� ���� ��, �� ���� queen�� ������ �� �� �ִ� �κ��� ��Ӱ� ĥ���� �κ� ���� �ϳ��̴�.


//N*N ũ���� ������ ü������ �־�����.�츮�� �ű⿡ N���� queen�� ��ġ�Ϸ��� �ϴµ�, ��� queen���� ���� ��Ƹ��� �� ����� �Ѵ�.�׷��ٸ� queen���� ��� ��ġ�ؾ߸� �ұ� ? ������ ��� ����� ������ ����Ѵ�.
//Queen�� �� N(1��N��10)�� �Է� �޴´�.
//N*N�� ü���ǿ��� N���� queen���� ���� ��Ƹ��� �ʴ� ��ġ�� ���� �� �ִ� ����� ���� ����Ѵ�.

#include <stdio.h>
int check[20][20];
int N;
int sol;
int func(int si, int sj)
{
	int i, j;
	for (i = si; i > 0; i--) if (check[i][sj]) return 1;
	for (i = si, j = sj; i > 0&& j > 0; i--, j--) if (check[i][j]) return 1; //&&�����ڰ� �ʿ�
	for (i = si, j = sj; i > 0&&j <= N; i--, j++) if (check[i][j]) return 1;
	return 0;
}

void DFS(int n)
{	
	int i;

if (n > N)
{
	sol++;
	return;
}

for (i = 1; i <= N; i++)
{
	if (func(n, i)) continue;
	check[n][i] = 1;
	DFS(n + 1);
	check[n][i] = 0;
}
}



int main(void)

{
	// ���⼭���� �ۼ�
	scanf("%d", &N);

	DFS(1);

	printf("%d", sol); 

	return 0;

}

#endif

#if 0
//��������� ��� ���Ͽ� ���������밡 ����Ѵ�.�����밡 ���������� �ٸ��� �� ���� ������ ���ٸ��� �����Ǿ� �ִ�.�ϳ��� <�Ǹ��� ���ٸ�>�̰� �ٸ� �ϳ��� <õ���� ���ٸ�>�̴�.
//
//
//
//�Ʒ� �׸� 1�� ���̰� 6�� �ٸ��� �� ���� ����� �����ش�.�׸����� ���� �������� <�Ǹ��� ���ٸ�>�� ǥ���ϴ� ���̰�, �Ʒ��� �������� <õ���� ���ٸ�>�� ǥ���Ѵ�.�� ���ٸ��� ���̴� �׻� �����ϸ�, �� ĭ�� ���ڴ� �ش� ���� ������ ���ڸ� ��Ÿ����.�� �ٸ��� ������ �� ���ڴ�{ R, I, N, G, S } �� �ϳ��̴�.
//���������밡 �����ϰ� �ִ� ������ �η縶���� <�Ǹ��� ���ٸ�>�� <õ���� ���ٸ�>�� �ǳʰ� �� �ݵ�� ������� ��� ���������� ���ڵ��� �����ִ�.�� ������� �������� ������ ���ٸ��� ������ ����������� ȭ�� ������ �������� �ȴ�.
//
//�ٸ��� �ǳ� �� ������ ���� ������ ��� �����ϸ鼭 �Ǿ�� �Ѵ�.
//1) ����(�������)���� ������(��������)���� �ٸ��� �������� �ϸ�, �ݵ�� ������ �η縶���� ���� ���ڿ��� ������� ��� ��� �������� �Ѵ�.
//2) �ݵ�� <�Ǹ��� ���ٸ�>�� <õ���� ���ٸ�>�� �����ư��鼭 ���� ��ƾ� �Ѵ�.��, ����� � ���ٸ����� �����ص� �ȴ�.
//3) �ݵ�� �� ĭ �̻� ���������� �����ؾ��ϸ�, �ǳʶٴ� ĭ�� ������ ����� ����.���� ���ٸ��� ����� �׸� 1�� ���� �η縶���� ���ڿ��� "RGS"��� ���ٸ��� �ǳʰ� �� �ִ� ���� ������ 3���� ���̴�. (�Ʒ� �׸����� ������ ���ڴ� ��� �������� ���ٸ��� ��Ÿ����.)
//�ֳ��ϸ� ù ��°�� ���ڿ� "RGS"�� ��� ��� �������� �ϴ� ���� 1)�� �������� ������, �� ��°�� �����ư��鼭 ���� ��ƾ� �ϴ� ���� 2)��, �� ��°�� ������ ������ �Ͽ����ϴ� ���� 3)�� �������� �ʱ� �����̴�.
//
//������ �η縶���� ���� ���ڿ��� �� �ٸ��� ���� ������ ���ڿ��� �־����� ��, ���ٸ��� ����� �� �ִ� ��� ������ ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.���� ���, �׸� 1�� ���� ����ϴ� ����� 3������ �����Ƿ� 3�� ����ؾ� �Ѵ�.
//ù° �ٿ��� ������ �η縶���� ���� ���ڿ�(R, I, N, G, S �θ� ������)�� �־�����.
//
//
//
//�� ���ڿ��� ���̴� �ּ� 1, �ִ� 10 �̴�.
//
//
//
//�� ���� �ٿ��� ���� <�Ǹ��� ���ٸ�>�� <õ���� ���ٸ�>�� ��Ÿ���� ���� ������ ���ڿ��� �־�����.
//
//
//
//�� ���̴� 5 �̻�, 30 �����̴�.
//��� ���Ͽ� ������ �η縶���� ���� ���ڿ��� ������� �ٸ��� �ǳʰ� �� �ִ� ����� ���� ����Ѵ�.
//
//
//
//�׷��� ����� ������ 0�� ����Ѵ�.
//
//
//
//��� �׽�Ʈ �����Ϳ� ���� ��°���� 231 - 1 �����̴�.

#include <stdio.h>
char magic[20];
char brid[2][40];
int check[40];
int evil;
int angel;
int sol;
int N;
int h;
void DFS(int n, int cnt, int flag)
{

}

void count(char *a)
{
	while (*a)
	{
		N++;
		a++;
	}
}
int main(void)

{
	int i, j;
	scanf("%s", magic);
	for (i = 0; i < 2; i++)
	{
		scanf("%s", brid[i]);
	}
	scanf("%s", brid);
	count(brid[0]);
	DFS(0, 0,0);
	printf("%d", sol); 

	return 0;

}



#endif

#if 0
//�̷� ã��
#include <stdio.h>
typedef struct st
{
	int i, j, d;
}Queue;
Queue Q[110 * 110 + 10];
int si, sj, ei, ej;
int ti, tj, td;
int rp, wp;
int maze[110][110];
int check[110][110];
int x, y;
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

int BFS(void)
{
	int ni, nj, k; 
	Q[wp].i = si; Q[wp].j = sj; Q[wp++].d = 0; check[si][sj] = 1;

	while (rp < wp)
	{
		ti = Q[rp].i; tj = Q[rp].j; td = Q[rp++].d;
		if (ti == ei && tj == ej) return td;

		for (k = 0; k < 4; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];

			if (check[ni][nj] || maze[ni][nj]) continue;
			if (ni<1 || nj<1 || ni>y || nj>x) continue;
			Q[wp].i = ni; Q[wp].j = nj; Q[wp++].d = td + 1; check[ni][nj] = 1;
		}
	}
}

int main(void)

{
	int i, j;
	scanf("%d %d", &x, &y);
	scanf("%d %d %d %d", &sj, &si, &ej, &ei);

	for (i = 1; i <= y; i++)
	{
		for (j = 1; j <= x; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	printf("%d", BFS());
	return 0;
}
#endif

#if 0
//���
#include <stdio.h>
typedef struct st
{
	int i, j, d;
}Queue;
Queue Q[110 * 110 + 10]; 
int game[110][110];
int check[110][110];
int N, M;
int R, C, S, K;
int ti, tj, td;
int rp, wp;
int di[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dj[] = { -1, -2, -2, -1, 1, 2, 2, 1 };


int BFS(void)
{
	int ni, nj, k;

	Q[wp].i = R; Q[wp].j = C; Q[wp++].d = 0; check[R][C] = 1;
	while (rp < wp)
	{
		ti = Q[rp].i; tj = Q[rp].j; td = Q[rp++].d;
		if (ti == S && tj == K) return td;

		for (k = 0; k < 8; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];
			if (check[ni][nj]) continue;
			if (ni<1 || nj<1 || ni>N || nj>M) continue;
			Q[wp].i = ni; Q[wp].j = nj; Q[wp++].d = td + 1; check[ni][nj] = 1;
		}
	}
}


int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);
	game[R][C] = 1;
	game[S][K] = 1;
	printf("%d", BFS());
	// ���⼭���� �ۼ�
	return 0;
}
#endif

#if 0
//��3������ ���� ���� ���� ������ ���������� ��Ȱ�ϸ� ��ȣ ������ ���� �ʴ� ��쵵 ���ٰ� �Ѵ�.� �� �������� �̷��� ���� ������ ���� �����Ű�� ���� ���θ� ��ȹ�ϱ�� �ߴ�.���� ������ �������� ���� �����ϸ� �������� ������ ������ �̵��� �� �ְ�����, �׷��⿡�� �����̳� �ڿ��� ������ �ּ����� ��븸���� ��� ������ �����Ű���� �Ѵ�.���� ��� ���� a, b, c�� ���� ��, a�� b�� ����Ǿ� �ְ�, b�� c�� ����Ǿ� ������ a�� c�� ����Ǿ� �ִٰ� ����.
//
//������ ��(N)�� �������� ���� �Ǽ� ���(Ei, j)�� �Ʒ��� ���� triangular matrix ���·� �־����ٰ� �� �� ��� ������ �����ϱ� ���� �ּ����� ����� �� ��(C)�� ���϶�.
//
//��, 0�� �� ������ ���θ� �Ǽ��� �� ������ �ǹ��ϸ�, Ư�� �������� �ڱ� �ڽ������� ����(Vk, k) ���� �Ǽ��� �� ����.

//������ �� N (3��N��100)�� �Էµǰ�, Ei,j(0��Eij��100,000)�� �Ʒ��� ���� triangular matrix ���·� �־�����.

//��� ������ �����ϱ� ���� �ּ����� ����� ��(C)�� ����Ѵ�.

#include <stdio.h>
int c[110][110];
int cost[110];
int check[110];
#define INF 0x7fffffff
int main(void)
{	// ���⼭���� �ۼ�
	int n;
	int i, j,k;
	int sel;
	int min = 0x7ffffff;
	int sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &c[i][j]);
			c[j][i] = c[i][j];
		}
		cost[i] = INF;
	}

	cost[1] = 0; check[1] = 1; sel= 1;

	for (k = 0; k < n ; k++)
	{
		for (i = 1; i <= n; i++)
		{
			if (c[sel][i] == 0 ||check[i]) continue;
			if (cost[i] > c[sel][i]) cost[i] = c[sel][i];
		}

		min = INF;
		for (i = 1; i <= n; i++)
		{
			if (check[i]) continue;
			if (min > cost[i])
			{
				min = cost[i];
				sel= i;
			}
		}
		check[sel] = 1; 
	}

	for (i = 1; i <= n; i++)
	{
		sum += cost[i];
	}

	printf("%d", sum);
	return 0;

}
#endif

#if 0
#include <stdio.h>
int s[10];
int N, M;

void DFS(int n, int sum)
{
	int i;

	if (n > N)
	{
		if (sum == M)
		{
			for (i = 1; i <= N; i++)
			{
				printf("%d ", s[i]);
			}
			printf("\n");
		}
		return;
	}

	for (i = 1; i <= 6; i++)
	{
		s[n] = i; 
		DFS(n + 1, sum + i);
		
	}

}


int main(void)

{	// ���⼭���� �ۼ�
	scanf("%d %d", &N, &M);
	DFS(1, 0);
	return 0;
}
#endif

#if 0
//�ʹ�
#include <stdio.h>
int sushi[30010];
int check[3010];

int main(void)

{
	int n, d, k, c;
	int i, j;
	int h = 0;
	int max = -100;
	int cnt = 0;
	int flag = 0;
		

	scanf("%d %d %d %d", &n, &d, &k, &c);

	for (i = 0; i < n; i++)
		// ���⼭���� �ۼ�
	{
		scanf("%d", &sushi[i]);
	}



	
	for (i = 0; i < 3010; i++)
	{
		if (max < check[i]) max = check[i];
	}

	if (flag) cnt = max + 1;
	else cnt = max - 1;

	printf("%d", cnt);

	return 0;
}
#endif

#if 0
#include <stdio.h>
int a[30];
int T, N, K;

int DFS(int n, int sum)
{
	if (n > N)
	{
		if (sum == K) return 1;
		return 0;
	}

	if (DFS(n + 1, sum + a[n])) return 1;
	if (DFS(n + 1, sum)) return 1;
	return 0;
}

int main(void)

{
	int i;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++) scanf("%d", &a[i]);
		if (DFS(1, 0)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;

}
#endif

#if 0
int a[20][20];
int check[20];
int s[20]; 
int N;
int sum;
int min = 0x7fff0000;
void DFS(int n, int sum)
{
	int i;
	if (min <= sum) return;
	if (n > N)
	{
		if (min > sum) min = sum;
		return;
	}

	for (i = 1; i <= N; i++)
	{
		if (check[i]) continue;
		check[i] = 1;
		//s[i] = n;
		DFS(n + 1, sum + a[n][i]);
		check[i] = 0;
	}
}
int main(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	DFS(1, 0);
	printf("%d\n", min);
	for (i = 1; i <= N; i++)
	{
		printf("%d ", s[i]);
	}

}

#endif

#if 0


#include <stdio.h>
int N, M;
int i;
int a[10];//����
int b[20];//��
int check[20];
int s;
int DFS1(int n, int sum, int i)
{
	if (n > N)
	{
		if (sum == a[i]) return 1;
		return 0;
	}
	if (DFS1(n + 1, sum - b[n], i)) return 1; //sum�� �״ٰ� ���� ������ �߸� �� ���
	//�Լ��� ���� ���� ��ġ�� ��� �߻� ���ɼ�
	//DFS1���� N�� �����ؼ� DFS2�� ������ ��ġ�� �κ� ������ Y �� ������ ���� N �߻� ���ɼ�.
	if (DFS1(n + 1, sum + b[n], i)) return 1;
	if (DFS1(n + 1, sum, i)) return 1;
	return 0;
}


int main(void)

{
int flag = 0;

	// ���⼭���� �ۼ�
	scanf("%d", &N); //��
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &b[i]);
		s += b[i];
	}

	scanf("%d", &M); //����

	for (i = 1; i <= M; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= M; i++)
	{
		if (DFS1(1, 0, i)) printf("Y ");
		else  printf("N ");
	}

	return 0;

}
#endif

#if 0
	
#include <stdio.h>



int main(void)

{

	int a[6][2];

	int T, K, sum = 0;

	int i;



	//�Է¹޴ºκ�

	scanf("%d", &T);

	while (T-->0)

	{

		scanf("%d", &K);

		for (i = 0; i<6; i++)

		{

			scanf("%d %d", &a[i][0], &a[i][1]);

		}



		//���⼭�����ۼ�
		int j; int flag = 0; int R, C; int r, c; int sol;
		for (i = 0; i < 5; i++)
		{
			for (j = i + 1; j < 6; j++)
			{
				if (a[i][0] == a[j][0])
				{
					flag = 1; 
					sol = i;
					break;
				}
			}

			if (flag) break;
			if (!flag)
			{
				if (a[i][0] == 1 || a[i][0] == 2) R = a[i][1];
				if (a[i][0] == 3 || a[i][0] == 4) C = a[i][1];
			}
		}

		if (sol == 1) { r = a[sol + 1][1]; c = a[5][1]; }
		else { r = a[sol + 1][1]; c = a[sol + 2][1]; }
		sum = K*(R*C - r*c);
		//����ϴºκ�

		printf("%d\n", sum);

	}

	return 0;

}
#endif

#if 0
#include <stdio.h>

int a[110][110];
int a_check[110][110];
int check[110][110];
int H[110 * 110];
int cnt;
int di[] = { -1, 1, 0, 0 }; 
int dj[] = { 0, 0, -1, 1 };
int N;
int cnt;
int count[110];

void Check(int x)
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (a[i][j] <= x) a_check[i][j] = 1;
		}
	}
}

void Fill(int i, int j)
{
	int ni, nj, k;
	if (check[i][j]) return;
	check[i][j] = 1;
	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];
		if (a_check[ni][nj]) continue;
		if (check[ni][nj])continue;
		if (ni<1 || nj<1 || ni>N || nj>N) continue;

		Fill(ni, nj);
	}
}

void reset(void)
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (a_check[i][j]) a_check[i][j] = 0;
		}
	}
}
int main(void)

{

	// ���⼭���� �ۼ�
	int i, j;
	int k = 0;
	int h;
	int p=0;
	int max = -100;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			H[k++] = a[i][j];
		}
	}

	for (i = 0; i < N*N-1; i++)
	{
		for (j = i + 1; j < N*N; j++)
		{
			if (H[i] == H[j]) H[j] = 0;
		}
	}
	for (h = 0; h < N*N; h++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{

				if (H[h] == 0) continue;
				Check(H[h]);


				Fill(i, j);
				cnt++;
				reset();

			}
		
		}
		count[p++] = cnt;
		cnt = 0;
	}

	for (p = 0; p < 110; p++)
	{
		if (max < count[p])
		{
			max = count[p];
		}
	}
	printf("%d", max);
		return 0; 

}
#endif

#if 0
#include <stdio.h>
int c1[30]; //n���� ������ �ִ��� Ȯ��
int c2[30]; //n���� ������ �ִ��� Ȯ��
int c3[30]; //n���� ������ �ִ��� Ȯ��
int N;
int cnt;

void DFS(int n)
{
	int i;
	if (n > N)
	{
		cnt++; return;
	}
	for (i = 1; i <= N; i++)
	{
		if (c1[i] || c2[n + i] || c3[12 + n - i]) continue;
		c1[i] = c2[n + i] = c3[12 + n - i] = 1;
		DFS(n + 1);
		c1[i] = c2[n + i] = c3[12 + n - i] = 0;
	}

}
int main(void)

{// ���⼭���� �ۼ�
	scanf("%d", &N);
	DFS(1);
	printf("%d", cnt);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int a[30][30];
int check[30];
int N;
int min = 0x7fff0000;

void DFS(int n, int sum, int sol)
{
	int i;
	if (min <= sum) return;
	if (n >=N)
	{
		if (min > sum + a[sol][1]) min = sum + a[sol][1];
		return;
	}
	for (i = 1; i <= N; i++)
	{
		if (check[i]) continue;
		check[i] = 1;
		DFS(n + 1, sum + a[sol][i],i); //sol�������� i��° ���÷� �̵�. check[1]=1�� ���·� 
		//���� �Ѿ� ���� �ʴ´�.
		//1�δ� �� �������� ���ƿ��� ����.
		check[i] = 0;
	}

}
int main(void)

{
	int i, j;
	// ���⼭���� �ۼ�
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) a[i][j] = 10000;
		}
	}
	check[1] = 1;
	DFS(1, 0,1);
	printf("%d", min);
	return 0;

}
#endif


#if 0
#include <stdio.h>
char a[20];
char b[2][50];
int sol;
int N, M;

void DFS(int n, int cnt, int p)
{
	if (n > N)
	{
		if (cnt == M)
		{
			sol++;
		}
		cnt = 0;
		return;
	}

		if (b[p][n] == a[cnt])
		{
			DFS(n + 1, cnt + 1, !p);
		}
		DFS(n + 1, cnt, p);
	
}
int main(void)

{

	// ���⼭���� �ۼ�
	int i;
	scanf("%s", a);
	for (i = 0;i<2; i++)
	{
		scanf("%s", &b[i][0]);
	}
	for (i = 0; i < 20; i++)
	{
		if (a[i] == 0)break;
		M++;
	}

	for (i = 0; i < 50; i++)
	{
		if (b[0][i] == 0) break;
		N++;
	}
	DFS(0, 0, 0);
	DFS(0, 0, 1);
	printf("%d", sol);
	return 0;

}
#endif

#if 0
#include <stdio.h>
int a[20];
int T, B, N;
int min = 0x7fff0000;


void DFS(int n, int sum)
{
	if (n > N)
	{
		if (sum >= B && min > sum)
		{
				min = sum;
		}
		return;
	}
	DFS(n + 1, sum + a[n]);
	DFS(n + 1, sum);
}
int main(void)
{
	int i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &B);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}
		min = 0x7ffff000;
		DFS(1, 0);
		printf("%d\n", min-B);
	}

}
#endif

#if 0
#include <stdio.h>
#define INF 0x7ffff000
int a[110][110];
int c[110];
int check[110]; 
int N;
int main(void)
{
	int i, j;
	int sel;
	int min = INF;
	int sum = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <=i; j++)
		{
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
		}
		c[i] = INF;
	}

	sel = 1; c[1] = 0; check[1] = 1;


	for (j = 1; j <= N - 1;j++)
	{
		for (i = 1; i <= N; i++)
	{
		if (check[i] || a[sel][i] == 0) continue;
		if (c[i] > a[sel][i]) c[i] = a[sel][i];
	}
		min = INF;
	for (i = 1; i <= N; i++)
	{
		if (check[i]) continue;
		if (min > c[i]) { min = c[i]; sel = i; }
	}

	check[sel] = 1;

}

	for (i = 1; i <= N; i++)
	{
sum += c[i];
	}
	printf("%d", sum);
}
#endif

#if 0
#include <stdio.h>
#define INF 0x7ffff000
int a[20][20];
int c[20];
int check[20];
int r[20];
int N;
int min = INF;

int main(void)
{
	int i, j; 
	int sel;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
		}
		c[i] = INF;
		r[i] = 1;
	}

	sel = 1; check[1] = 1; c[1] = 0;
	for (j = 1; j <= N - 1; j++)
	{
		for (i = 1; i <= N; i++)
		{
			if (check[i] || a[sel][i] == 0) continue;
			if (c[i] > c[sel] + a[sel][i])
			{
				c[i] = c[sel] + a[sel][i];
				r[i] = sel;
			}
		}
		min = INF;
		for (i = 1; i <= N; i++)
		{
			if (check[i]) continue;
			if (min > c[i])
			{
				min = c[i];
				sel = i;
			}
		}
		check[sel]=1;

	}
	printf("%d", c[N]);
}
#endif



#if 0
#include <stdio.h>
#define MAX -1000
int a[1100][1100];
int c[1100];
int check[1100];
int N, M;
int main(void)
{
	int i, j, k;
	int x, b, y;
	int sel;
	int sum = 0;
	int max;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++)
{
	scanf("%d %d %d", &x, &b, &y);
				if (a[x][b] < y)
				{
					a[x][b] = y;
					a[b][x] = y;
				}

}

	for (i = 1; i <= N; i++)
	{
		c[i] = MAX;
	}

	
	sel = 1; c[1] = 0; check[1] = 1;


	for (j = 1; j <= N - 1; j++)
	{
		for (i = 1; i <= N; i++)
		{
			if (check[i] || a[sel][i] == 0) continue;
			if (c[i] < a[sel][i]) c[i] = a[sel][i];
		}
		max = MAX;
		for (i = 1; i <= N; i++)
		{
			if (check[i]) continue;
			if (max < c[i]) { max= c[i]; sel = i; }
		}

		check[sel] = 1;

	}

	for (i = 1; i <= N; i++)
	{
		sum += c[i];
	}
	printf("%d", sum);
}
#endif

#if 0
#include <stdio.h>
int a[20][20];
int s[20];
int N,M;

int Check(int n, int c)
{
	int i;
	for (i = 1; i < n; i++)
	{
		if (a[n][i] && s[i] == c) return 0;
	}
	return 1;
}

int DFS(int n)
{
	int i;
	if (n > N) return 1;

	for (i = 1; i <= M; i++)
	{
		if (Check(n, i) == 0) continue;
		s[n] = i;
		if (DFS(n + 1)) return 1;
	}
	return 0;
}
int main(void)
{
	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	if (DFS(1))
	{
		for (i = 1; i <= N; i++)
		{
			printf("%d ", s[i]);
		}
	}
	else printf("-1");
	return 0;

}
#endif

#if 1
#include <stdio.h>
int a[20][20];
int b[20];
int s[20];
int check[20];
int N, M;
int Check(int n, int x)
{
	int i;
	for (i = 1; i < n; i++)
	{
		if (a[n][i] == 1 && s[i] >= x) return 0; //���ϰ� �� ���� �޴� ���
		if (a[i][n] == 1 && s[i] <= x) return 0;//��簡 �� ���� �޴� ���
	}
	return 1;
}

int DFS(int n)
{
	int i;
	if (n > N) return 1;
	for (i = 1; i <= N; i++)
	{
		if (check[i]|| Check(n, b[i]) == 0) continue;
		s[n] = b[i]; check[i] = 1;
		if(DFS(n + 1)) return 1;
		check[i] = 0;
	}
	return 0;
}
int main(void)
{
	int i;
	int x, y;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= M; i++)
	{
		scanf("%d %d", &x, &y);
			a[x][y] = 1;
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &b[i]);
	}
	if (DFS(1))

	{
		for (i = 1; i <= N; i++)
		{
			printf("%d ", s[i]);
		}
	}

	

}
#endif


