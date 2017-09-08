#if 0
//N개의 자연수가 주어질 때 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
#include <stdio.h>
int a[5000];
int main(void)

{

	// 여기서부터 작성
	int n;
	int i;
	int j;
	int temp;


	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++) //버블정렬
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
//N개의 정수가 주어질 때 가장 작은 수 4개를 출력하는 프로그램을 작성하시오.
#include <stdio.h>
int a[30000];


int main(void)

{

	// 여기서부터 작성
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

	for (i = 0; i < n - 1; i++) //선택정렬
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
//N명의 점수가 주어질 때 상위 3명의 ID를 출력하는 프로그램을 작성하시오.

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
	for (left = m; left < n; left++) // 삽입정렬
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

	// 여기서부터 작성

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
//다음 배열 a에서 합이 가장 큰 행과 열의 번호를 각각 인쇄하라.


#include <stdio.h>


int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
int main(void)

{

	// 여기서부터 작성
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
//각 자릿수를 계속 더하여 한 자리 숫자를 만드는 것을 숫자근(Digit Root)이라고 한다.
//
//예를 들어 정수 65, 536의 숫자근은 7이다, 그것은 6 + 5 + 5 + 3 + 6 = 25이고 이를 다시 2 + 5 = 7이기 때문이다.
//
//
//
//n개의 정수가 입력되면 숫자근이 가장 큰 값을 찾는 프로그램을 작성하시오.

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

	// 여기서부터 작성
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
//가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다.이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다.이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 넓이를 구하는 프로그램을 작성하시오.
//예를 들어 흰색 도화지 위에 세 장의 검은색 색종이를 그림과 같은 모양으로 붙였다면 검은색 영역의 넓이는 260이 된다.
#include <stdio.h>
int a[110][110];
int b[110][2];

int main(void)

{

	// 여기서부터 작성
	int n;
	int i;
	int j;
	int x;//가로
	int y;//세로
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
//가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다.이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다.이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 둘레의 길이를 구하는 프로그램을 작성하시오.
#include <stdio.h>
int a[110][110];
int b[110][2];

int main(void)

{	// 여기서부터 작성
	int n;
	int i;
	int j;
	int k = 0;
	int x;//가로
	int y;//세로
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
//9개의 숫자를 입력 받은 다음, 이 중에서 7개의 숫자를 사용하였을 때, 합이 100 이 되는 프로그램을 작성하라.
#include <stdio.h>



int main(void)

{
	int a[9];
	int i;
	int temp;
	int j;
	int sum = 0;
	// 여기서부터 작성
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
//아래와 같이 모눈종이에 각각의 칸들이 칠해져 있는 그림이 있을 때 모눈종이에서 찾고 싶은 패턴의 모양이 몇 개가 있는지를 검사하려고 한다. 이 때, 찾고자 하는 모눈종이의 크기 M(0≤M≤100)과 패턴의 크기 P(0≤M≤100)은 주어진다.
//찾고자 하는 패턴의 모양은 회색과 흰색으로 칠해지고, 패턴은 같은 모양만 찾으면 된다. 또한 회색으로 칠해진 칸은 패턴 매치 검사 시 반복되어 사용될 수 있다.
#include <stdio.h>
int a[110][110];
int b[110][110];
int main(void)

{

	// 여기서부터 작성

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

//N개의 양의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하는 프로그램을 작성하시오.예를 들어 아래와 같이 8개의 양의 실수가 주어진다면,

//색칠된 부분의 곱이 최대가 되며, 그 값은 1.638이다.
//
//결과는 double형의 범위를 넘지 않는다.
#include <stdio.h>
double a[10010];
int main(void)

{

	// 여기서부터 작성
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

		if (max < product) max = product; //전의 곱셈 최대치보다 크면 바꾼다. 즉, 최대치를 계속 유지하며 비교변화.

		for (j = i + 1; j < n; j++)
		{
			if (max < product) //각 시작 숫자마다, 열이 증가할수록 최대치를 찾는다.
			{
				max = product;
			}
			product *= a[j];
		}
	}
	if (a[n] > max) max = a[n]; //마지막 숫자가 최대치보다 큰 지 확인한다.

	printf("%.3f", max);

	return 0;

}
#endif

#if 0
//R행 C열의 격자 모양의 지역에 몇 명의 사람이 서 있다.한 격자에는 최대 한 명의 사람이 있다.
//
//각 사람들은 자신과 인접한 사람과 정확히 한 번씩 악수하는데, 인접한 사람은 아래 그림과 같이 주위 8방향에 있는 사람을 말한다.
#include <stdio.h>

char a[60][60];

int main(void)

{

	// 여기서부터 작성
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
	count = cnt / 2; //중복방지
	cnt = 0;
	for (i = 0; i < R; i++) //민현의 악수 최대 횟수 찾기
	{
		if (max < cnt) max = cnt; //i행이 증가할 때마다 max 찾기 (사실 없어도 됨)

		for (j = 0; j < C; j++)
		{
			if (max < cnt) max = cnt; //j열이 증가할 때마다 max찾기 즉, max는 초기화하지 않고 비교변화.
			cnt = 0; //cnt 초기화
			if (a[i][j] != '.') continue; //사람이 없는 곳에 민현 배치

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
//사탕 공장에서는 요구에 따라 다양한 개수의 사탕을 담고 있는 포장을 하고 있다.어느 날 갑자기 대형 이벤트가 생겨서 공장에 있는 모든 사탕들을 풀어서 하나로 포장 해야 한다.

//A, B, C 3개의 사탕 포장이 있을 때 이 포장들을 한번에 하나로 합칠 수는 없고, 한번에 2개씩만 합칠 수 있다.예를 들면 A와 B를 먼저 합친 후 C를 다시 합치거나 A와 C를 먼저 합치고 B를 합치기, 혹은 B와 C를 먼저 합치고 A를 합칠 수 있다.

//사탕 포장을 풀었다가 다시 합치는 순서는 매우 중요한데, 그 이유는 그 순서에 따라 전체 비용이 달라지기 때문이다.

//사탕 포장 A와 B에 각각 a개와 b개의 사탕이 들어있다고 할 때 이 둘을 합치는 비용은 a + b라고 한다.그러므로 A와 B를 먼저 합치고 C를 합치는 경우 그 전체 비용은 a + b + a + b + c이며, B와 C를 먼저 합치고 A를 합치는 비용은 b + c + b + c + a 이므로 그 둘은 서로 같지 않을 수 있다.

//예를 들어, 각각 2, 2, 5개가 포장되어 있다면 A(2)와 B(2)를 합치는 비용은 4. 합쳐진 것(4)과 C(5)를 합치는 비용은 9로 총 13이 최소비용이다.

//현재 공장에 포장되어 있는 포장 개수 N과 각각 포장에 들어있는 사탕의 개수 ni가 주어질 때, 이들을 하나로 합치는데 들어가는 비용의 최소(C)를 구하라.
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

//한 정수 n을 입력 받아서 1부터 n까지의 합을 구하여 출력하시오.
//
//단, 반드시 재귀함수로 구현하시오.
#include <stdio.h>

int sum(int num)
{
	if (num == 0) return 0;
	return num + sum(num - 1);
}
int main(void)

{

	// 여기서부터 작성
	int n;
	scanf("%d", &n);

	printf("%d", sum(n));



	return 0;

}
#endif

#if 0
//피보나치수열이란 앞의 두 수를 더하여 나오는 수열이다.
//
//첫 번째 수와 두 번째 수는 1이고 세 번째 수는 첫 번째 수와 두 번째 수를 더하여 2가 된다.피보나치수열을 나열해 보면 다음과 같다.

//1, 1, 2, 3, 5, 8, 13...

//자연수 N을 입력 받아 N번째 피보나치 수를 출력하는 프로그램을 작성하여라.
#include <stdio.h>



int main(void)

{

	// 여기서부터 작성
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
//두 개의 자연수를 입력 받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
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

	// 여기서부터 작성

	int x, y;
	scanf("%d %d", &x, &y);

	printf("%d\n%d", gcd(x, y), lcm(x, y));

	return 0;

}
#endif

#if 0
//N개의 정수가 주어질 때 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

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

	// 여기서부터 작성

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
//오름차순의 순서대로 정렬되어 있는 N개의 데이터에서 특정한 숫자가 몇 번째 위치에 있는지를 알아내는 프로그램을 작성하시오.


#include <stdio.h>

int a[50010];
int b[10010];

int main(void)

{

	// 여기서부터 작성
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

		// 여기서부터 작성
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
	//그릇을 바닥에 놓았을 때 그 높이는 10cm 이다.그런데 두 개의 그릇을 같은 방향으로 포개면 그 높이는 5cm만 증가된다.만일 그릇이 서로 반대방향으로 쌓이면 높이는 그릇만큼, 즉 10cm 늘어난다.그릇을 괄호 기호로 나타내어 설명해보자.편의상 그릇이 쌓여지는 방향은 왼쪽에서 오른쪽이라고 가정한다.그림에서 ‘(’은 그릇이 바닥에 바로 놓인 상태를 나타내며, ‘)’은 그릇이 거꾸로 놓인 상태를 나타낸다.
	//
	//
	//
	//만일 그릇이 포개진 모양이 아래 그림 1(a)와 같다면 전체의 높이는 25cm가 된다.왜냐하면 처음 바닥에 있는 그릇의 높이가 10cm이고 이후 같은 방향으로 3개의 그릇이 포개져 있으므로 늘어난 높이는 5 + 5 + 5 = 15 이기 때문이다.그림 1(b)와 같은 경우라면 그 높이는 10 * 4 = 40cm가 된다.
#include <stdio.h>



	int main(void)

	{

		// 여기서부터 작성
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
	//최대 30자의 단어를 입력 받은 후 단어에서 가장 많은 소문자를 인쇄하라.
	//
	//대문자(‘A’~’Z’)와 소문자(‘a’~’z’)가 아닌 문자는 입력되지 않으며, 30자를 초과하여 입력하는 경우는 없다고 가정하고, 이에 대한 예외 처리는 하지 않는다.
#include <stdio.h>

	char a[40];
	int b[26];

	int main(void)

	{

		// 여기서부터 작성

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
	//N개의 분수가 주어질 때, 모든 분수의 합을 기약분수로 나타내는 프로그램을 작성하시오.
	//
	//기약분수란 분모와 분자 사이에 공약수가 1 뿐이어서 더 이상 약분되지 않는 분수이다.

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

		// 여기서부터 작성
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
	//국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것이다.국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있다.그래서 정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정한다.

	//(1) 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
	//
	//(2) 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다.상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다.

	//예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 각각 120, 110, 140, 150이라고 하자.이 경우, 상한액을 127로 잡으면, 위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 된다.

	//여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.
#include <stdio.h>
	int a[10010];
	int sum;//예산요청 총액
	int n;
	int m;//최대예산액
	int max;//상한액
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
	//문자열을 입력 받은 후, 같은 문자가 연속적으로 반복되는 경우 반복 횟수를()안에 넣어 문자열의 길이를 줄이는 압축하는 프로그램을 작성하려고 한다.

	//조건1.같은 문자가 M번 이상 연속으로 반복된 때만()안에 반복 횟수를 넣는다.
	//
	//조건2.연속으로 반복되는 문자 뒤에()를 넣는다.

#include <stdio.h>
	char a[110];
	char b[110];


	int main(void)

	{

		// 여기서부터 작성


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
						printf("%c(%d)", a[i], cnt); //이렇게 표현 가능하다는 거 잊지 말기!
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
	//정올시의 주차장은 주차시간이 10분 미만이면 무료이며, 10분 이상 30분 이하는 500원이다. 또한 30분을 초과하여 주차를 하면 30분 요금에 30분 초과 분에 대한 요금을 10분에 300원씩을 더 받는다.그리고 하루 최대 주차요금은 한 대당 50, 000원을 넘을 수 없다.이것은 정올시에서 지정한 것이다.

	//예로 9분 주차하면 0원, 20을 주차하면 500원, 32분을 주차하면 800원이다.

	//하루에 총 100대를 주차할 수 있는 주차장에 하루 동안 주차했던 차량 수와 각 주차시간이 주어지면 하루 총 주차요금을 구하는 프로그램을 작성하시오.
#include <stdio.h>

	int a[110];
	int main(void)

	{

		// 여기서부터 작성
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
			else if (a[i]>30 && a[i] <= 1670) pay += 500 + ((a[i] - 30) + 9) / 10 * 300; //올림해줘야 함.
			else if (a[i] > 1670) pay += 50000;
		}

		printf("%d", pay);

		return 0;

	}
#endif

#if 0
	//철수는 친구들과 빙고 게임을 하고 있다. 철수가 빙고판에 쓴 수들과 사회자가 부르는 수의 순서가 주어질 때 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지를 출력하는 프로그램을 작성하시오.
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

		// 여기서부터 작성
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
	//LK 텔레콤에 근무하는 신입사원 정희에게 부장님이 새로운 업무를 지시했다.고객들의 휴대폰 전화번호를 정렬하는 작업이다.휴대폰 번호는 국번 3 자리와 중간국번 3자리 또는 4자리, 그리고 뒷자리 수 4 자리로 총 10 개 혹은 11 개의 숫자로 이루어진다.그리고 휴대폰 국번은 010, 011, 016, 017, 018, 019 의 여섯 가지가 존재한다.국번과 중간국번, 뒷자리 수는 하이픈(“ - ”)으로 구분된다.부장님이 원하는 요구사항은 다음과 같다.우선, 특정 국번 번호 순서로 정렬이 되어야 하며, 국번이 같은 경우에는 중간국번 숫자끼리 비교해서 오름차순 정렬이 되어야 하며, 중간국번도 같은 경우에는 뒷자리 번호를 비교해서 오름차순으로 정렬이 되어야 한다.단, 부장님이 원하는 정렬순서는 국번이 같을 경우 중간국번 4 자리인 휴대폰 번호가 중간국번 3 자리인 휴대폰 번호보다 항상 정렬 우선순위가 높다.즉, 국번이 같은 경우 중간국번 4 자리인 휴대폰 번호가 중간국번 3자리인 휴대폰 번호보다 정렬 시 항상 먼저 등장한다.예를 들어, 다음과 같은 휴대폰 번호를 정렬한다고 하자.
	//
	//011 - 275 - 3587
	//017 - 1111 - 2600
	//019 - 222 - 2222
	//017 - 111 - 1234
	//018 - 275 - 9562
	//010 - 333 - 1111
	//016 - 1235 - 3333
	//
	//이 번호들을 017 / 011 / 018 / 019 / 010 / 016 국번 순으로, 그리고 중간국번 4 자리가 중간국번 3자리보다 우선순위가 높도록 정렬을 한다면, 아래와 같이 정렬이 될 것이다.
	//
	//017 - 1111 - 2600
	//017 - 111 - 1234
	//011 - 275 - 3587
	//018 - 275 - 9562
	//019 - 222 - 2222
	//010 - 333 - 1111
	//016 - 1235 - 3333
	//
	//위의 결과에서 첫 번째 라인의 017 - 1111 - 2600 과 두 번째 라인의 017 - 111 - 1234 를 비교해 보면, 중간국번 111 은 1111 보다 작으므로 일반적으로는 정렬 시 017 - 111 - 2600 이 먼저 등장해야 하나, 부장님의 요구사항에서 중간국번 4 자리가 중간국번 3 자리보다 항상 정렬 우선순위가 높다는 규칙 때문에 017 - 1111 - 2600 이 017 - 111 - 1234 보다 먼저 등장한 것을 알 수 있다.
#include <stdio.h>



	int main(void)

	{

		// 여기서부터 작성



		return 0;

	}

#endif

#if 0
	//마을의 위성사진을 본 철수는 평지와 호수로 나뉘어져 있다는 것을 알았다.
	//
	//이 사진을 통해 호수가 몇 개가 있는지 파악하려고 한다.
	//
	//
	//
	//상, 하, 좌, 우, 대각선으로 연결되어 있으면 하나의 호수로 간주한다면 철수의 마을에 몇 개의 호수가 있는지 파악할 수 있는 프로그램을 작성하자.
#include <stdio.h>// FLOOD FILL - 연결된 것을 찾을 때


	int a[110][110];
	int check[110][110];
	int n;
	int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //8방위 조건 걸 때 사용
	int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 };//상하좌우, 상좌대각선, 상우 대각선, 하좌대각선, 하우 대각선


	void check_lake(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (check[i][j] == 1) return;//종료조건-이미 발견된 호수라면 종료.

		check[i][j] = 1; //새로 발견한 호수에 1을 찍는다.
		for (k = 0; k < 8; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (a[ni][nj]) check_lake(ni, nj); //8방위 어느 한 곳에 호수가 있으면 다시 check_lake를 호출
		}

	}

	int main(void)

	{

		// 여기서부터 작성
		int i;
		int j;
		int cnt = 0;

		scanf("%d", &n);
		for (i = 1; i < n + 1; i++) //8방위를 모두 고려해야 할 때는 (1,1)부터 행렬 시작
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
	//당신은 M행, N열의 크기를 가진 행렬을 가지고 있고, 행렬은 1과 0의 세포로 이루어져 있다.여기서 수직이든 수평이든 대각선 방향이든 인접한 두 개의 세포를 연결되어 있다고 표현하는데, 세포가 1인 것들은 서로 연결되어 하나의 구역을 이룬다.
	//
	//행렬에는 몇 개의 구역이 있는데, 행렬에서 크기가 가장 큰 구역을 이루는 세포 1의 개수는 얼마인가 ?
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

		// 여기서부터 작성
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
	//<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
	//
	//철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
	//
	//지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
#include <stdio.h>
	int house[50][50];
	int check[50][50];
	int num[2500]; // 각 단지 별 집 수
	int count; // 각 단지 별 집 수 세기
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

		// 여기서부터 작성
		int i;
		int j;
		int n;
		int cnt = 0; //총 단지 수
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
	//여러 개의 쇠막대기를 레이저로 절단하려고 한다.효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하여 쇠막대기들을 자른다.쇠막대기와 레이저의 배치는 다음 조건을 만족한다.
	//
	//- 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다.
	//
	//- 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓는다.
	//
	//- 각 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
	//
	//- 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다.
	//
	//
	//
	//아래 그림은 위 조건을 만족하는 예를 보여준다.수평으로 그려진 굵은 실선은  쇠막대기이고, 점은 레이저의 위치, 수직으로 그려진 점선 화살표는 레이저의 발사 방향이다.
	///이러한 레이저와 쇠막대기의 배치는 다음과 같이 괄호를 이용하여 왼쪽부터 순서대로 표현할 수 있다.
	//
	//(a)레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘() ’ 으로 표현된다.또한, 모든 ‘() ’는 반드시 레이저를 표현한다.
	//
	//(b)쇠막대기의 왼쪽 끝은 여는 괄호 ‘(’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다.
	//
	//위 예의 괄호 표현은 그림 위에 주어져 있다.
	//
	//
	//
	//쇠막대기는 레이저에 의해 몇 개의 조각으로 잘려지는데, 위 예에서 가장 위에 있는 두 개의 쇠막대기는 각각 3개와 2개의 조각으로 잘려지고, 이와 같은 방식으로 주어진 쇠막대기들은 총 17개의 조각으로 잘려진다.
	//
	//쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 주어졌을 때, 잘려진 쇠막대기 조각의 총 개수를 구하는 프로그램을 작성하시오.
#include <stdio.h>



	int main(void)

	{

		// 여기서부터 작성



		return 0;

	}

#endif

#if 0
	//해마다 열리는 꿀꿀이 올림피아드에는 여러 종목들이 있는데, 요즘에는 꿀꿀이들의 교양을 겨루는 ‘미술관람 대회’가 인기를 끌고 있다.이 대회는 사회자가 빨강, 초록, 파랑으로 이루어진 N × N 픽셀의 그림을 보여주면 그 그림에 포함된 영역의 수를 빠르고 정확하게 맞추는 것이 목표이다.동일한 색깔이 네 방향(상, 하, 좌, 우) 중 한 곳이라도 연결되어 있으면 하나의 영역으로 간주한다.

	//예를 들어, 아래 그림은 각각 2, 1, 1개의 빨간색, 초록색, 파란색 영역이 있어 총 4개의 영역이 있다.

	//
	//한편, 꿀꿀이들의 절반 정도는 선천적인 유전자 때문에 적록색맹이라서 빨간색과 초록색을 구별하지 못한다.따라서 사회자는 일반 대회와 적록색맹용 대회를 따로 만들어서 대회를 진행하려고 한다.사회자를 도와 영역의 수를 구하는 프로그램을 작성하여라.
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

		// 여기서부터 작성
		int i;
		int j;
		int n;



		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			scanf("%s", &picture1[i][1]); //(1,1)부터 넣을 것이다.

		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				picture2[i][j] = picture1[i][j]; //picture2에 picture1을 복사한다.
			}
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (picture1[i][j] == 'R') // cell문제에서는 세포가 아니면 통과했었다.
					//여기서는 R, G, B로 세포 3개를 봐야 하는 것과 동일하므로
					//통과가 아니라 조건에 해당되는 세포만 골라서 본다.
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
	//최신 패션 트렌드가 가죽에 두 개의 점이 있는 암소라고 들은 농부 존은 두 개의 점이 있는 암소를 대량으로 구매를 했다.불행하게도, 패션 트렌드가 빠르게 변해서 가장 인기 있는 현재 패션은 점이 하나 있는 암소이다.

	//존은 자신의 암소들을 현재 패션 트렌드에 맞게 바꾸고 싶다.그래서 두 개의 점에 색을 칠해서 한 개의 점으로 만들려고 한다.
	//
	//예를 들어 암소의 가죽이 N(세로) * M(가로) 크기의 격자로 아래와 같이 주어졌을 때 :

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

	//여기서 각각의 ‘X’는 점의 일부를 나타낸다.두 ‘X’가 같은 점으로 취급되는 경우는 상하나 좌우로 연결되어 있을 때 이다.대각선으로 연결된 것은 같은 점으로 보지 않는다.그래서 위 그림은 정확히 두 점이다.농부 존의 모든 암소는 정확히 두 점을 가지고 있다.

	//존은 두 점을 한 점으로 만들 때 최대한 적게 색칠하고 싶다.위의 예에서 그는 3군데에 새로운 ‘X’를 추가하면 된다. (새로운 ‘X’는 ‘*’로 대체해서 쉽게 볼 수 있게 했다.아래 그림 참조)

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

	//당신이 할 일은 농부 존이 두 개의 점을 병합해서 하나의 큰 점을 만들 수 있게 새로운 ‘X’의 최소 수를 정할 수 있게 도와주는 것이다.

#include <stdio.h>



	int main(void)

	{

		// 여기서부터 작성



		return 0;

	}
#endif

#if 0
	//미로탈출 로봇 대회를 개최하였다. 대회에 사용되는 미로는 가로(X), 세로(Y) 100이하의 크기이며, 미로를 한 칸 이동하는 데는 1초가 걸린다.
	//로봇이 출발점에서 도착점까지 가장 빨리 이동할 경우 걸리는 시간을 구하는 프로그램을 작성하시오.
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
		// 여기서부터 작성
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

#if 0//미로 찾기 문제는 BFS 문제로!
	//Q 사용
	//Q에 초기데이터를 삽입
	//Q에 데이터가 있는 동안 
	//1. Q에서 데이터 1개 read
	//2. 꺼낸 데이터 처리-> 조건 맞으면 Q에 삽입

	//미로탈출 로봇 대회를 개최하였다. 대회에 사용되는 미로는 가로(X), 세로(Y) 100이하의 크기이며, 미로를 한 칸 이동하는 데는 1초가 걸린다.
	//로봇이 출발점에서 도착점까지 가장 빨리 이동할 경우 걸리는 시간을 구하는 프로그램을 작성하시오.

#include <stdio.h>
	typedef struct st
	{
		int i; int j; int d; //길이
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

	{	// 여기서부터 작성

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
	//N×M장기판에 졸 한 개와 말 한 개가 놓여 있다. 말의 이동 방향이 다음과 같다고 할 때, 말이 최소의 이동횟수로 졸을 잡으려고 한다.
	//말이 졸을 잡기 위한 최소 이동 횟수를 구하는 프로그램을 작성해보자.
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
		// 여기서부터 작성
		scanf("%d %d", &n, &m);
		scanf("%d %d %d %d", &R, &C, &S, &K);
		game[R][C] = 1;
		game[S][K] = 2;
		printf("%d", BFS());
		return 0;
	}
#endif

#if 0 //진법 문제-삼성이 좋아함.
	//어떤 동화 속 나라의 왕은 숫자 3을 싫어해서 수의 체계에서 3이라는 숫자를 사용하지 않는다.백성들도 숫자 3은 혐오의 뜻으로 받아 들여 숫자 3을 절대 사용하지 않는다.

	//이 나라의 숫자는 0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, ... 이렇게 숫자가 진행된다.즉, 모든 자리(1의 자리, 10의 자리, 100의 자리, ...)에서 3이란 숫자는 나타나지 않는다.

	//이 나라는 3이 없기 때문에 10진법을 사용하는 다른 나라와 무역을 할 경우에 많은 혼돈을 겪게 된다.예를 들어 이 나라의 4는 다른 나라의 3과 같고, 이 나라의 15는 다른 나라의 13과 같다.

	//정확한 거래량을 따지기 위해 이 나라의 숫자 N을 10진법으로 변환한 수를 출력하는 프로그램을 작성하시오.
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
	//창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.
	//보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
	//하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다.
	//대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
	//	철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
	//토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
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
			//종료조건?
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

	{	// 여기서부터 작성
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
	//너비우선탐색(BFS)는 그래프의 임의의 한 정점에서 출발하여, 연결된 정점들 중 하나에 대해서 너비 순으로 먼저 탐색해 나가는 탐색법이다.이 탐색방법은 장기, 체스, 미로찾기, 무가중치 그래프의 최단경로 탐색 등의 다양한 분야에 활용되는 알고리즘이다.예를 들어 다음과 같은 그래프를 보자.
	//이 그래프에서 1번 정점에서 출발한 너비우선탐색 결과는 다음과 같다.
	//
	//1 - 2 - 4 - 5 - 3 - 6 - 7
	//
	//단, 한 정점에서 갈 수 있는 곳이 여러 곳일 경우 먼저 입력된 정점부터 먼저 방문한다.FIFO 즉, 2 4, 2 3 순으로 입력되었다면 2번 정점에서 4번을 먼저 방문하고 나중에 3번을 방문하도록 작성해야 한다.
	//
	//문제에 주어지는 모든 그래프는 양방향 무가중치 그래프이다.
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
	//주희는 N개의 똑같은 크기의 소시지를 갖고 있다.그녀는 이 소시지를 M명의 사람들에게 똑같이 나누어주려고 한다.소시지를 남김없이 주기 위해서는 소시지를 잘라야 하는데 소시지를 쓸데없이 많이 자르면 보기 안 좋기 때문에 소시지를 최소한 적게 잘라야 한다.주희를 도와 소시지를 최소 몇 번 잘라야 하는지 구하는 프로그램을 작성하여라.
#include <stdio.h>
	int main(void)
	{
		// 여기서부터 작성
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
	//어릴 적 수학 시간에 오른쪽 자릿수에서 왼쪽 자리의 숫자끼리 더하는 방법을 배운다.이러한 과정 중에서 '자리 올림' - 10이상의 숫자가 나와서 다음 자리에 1을 더해주는 것 - 이 발생 하는 것을 알 수 있다. 2개의 숫자가 들어왔을 경우, 몇 번의 자리 올림이 발생하는지 알아보는 프로그램을 작성하라.
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

		// 여기서부터 작성


		int a, b;

		scanf("%d %d", &a, &b);
		digit(a, b);

		return 0;

	}
#endif

#if 0
	//도시의 지하에는 수많은 수도파이프가 설치 되어있다.하지만 이 수도 파이프들이 너무나 무계획적으로 설치되었기 때문에, 실제로는 물이 흐르지 않는 수도파이프도 다수 설치되어 있다고 한다.그래서 수도파이프 배치를 설계하는 사람들이 현재 도시의 수도파이프 설치 상태를 확인한 뒤, 실제 물이 흐르지 않는 수도파이프를 제거하는 공사를 시행하려 한다.

	//다음과 같이 파이프가 설치된 상태에서(0, 0) 수도 공급원 이라고 한다면 5개의 수도파이프는 물이 흐르지 않는 수도 파이프이므로 제거 대상이 된다.

	//다음과 같이 도시의 지하 수도파이프 설치 지도와 수도공급원의 위치가 주어졌을 때, 제거해야 할 수도 파이프의 개수를 구하시오.

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
	{	// 여기서부터 작성

		int i, j;
		int n;
		int x, y; // 수도공급원 시작좌표
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

		// 여기서부터 작성
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

		// 여기서부터 작성
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
		// 여기서부터 작성
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
		// 여기서부터 작성
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
	int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //8방위 조건 걸 때 사용
	int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 };//상하좌우, 상좌대각선, 상우 대각선, 하좌대각선, 하우 대각선


	void check_lake(int i, int j)
	{
		int k;
		int ni;
		int nj;
		if (check[i][j] == 1) return;//종료조건-이미 발견된 호수라면 종료.

		check[i][j] = 1; //새로 발견한 호수에 1을 찍는다.
		for (k = 0; k < 8; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if (a[ni][nj]) check_lake(ni, nj); //8방위 어느 한 곳에 호수가 있으면 다시 check_lake를 호출
		}

	}

	int main(void)

	{

		// 여기서부터 작성
		int i;
		int j;
		int cnt = 0;

		scanf("%d", &n);
		for (i = 1; i < n + 1; i++) //8방위를 모두 고려해야 할 때는 (1,1)부터 행렬 시작
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
		// 여기서부터 작성
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
	// 여기서부터 작성
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
//자연수 N과 M을 입력 받아서 주사위를 N번 던져서 나온 눈의 합이 M이 나올 수 있는 모든 경우를 출력하는 프로그램을 작성하시오.
//첫 줄에 주사위를 던진 횟수 N(2≤N≤7)과 눈의 합 M(1≤M≤40)이 들어온다.
//주사위를 던진 횟수의 합이 M이 되는 경우를 모두 출력한다.
//작은 숫자부터 출력한다.

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
//덧셈을 못하는 철수를 공부시키기 위해 자연수들을 주고, 그 중에 몇 개의 수를 골라서 그 합이 K가 될 수 있는지 알아보라고 시켰다. 철수 어머니가 자연수들을 무작위로 선택해서 본인도 가능한지 아닌지 모르고 있다. 어머니가 채점을 할 수 있게 주어진 문제의 답을 찾아주자.
//첫 번째 줄에 테스트 케이스 개수 T(1≤T≤10)가 주어진다.
//
//두 번째 줄부터 아래 내용이 T개 만큼 주어진다.
//
//첫 줄에 자연수 개수 N(5 <= N <= 20)과 K(1 <= K <= 2, 000, 000)가 공백으로 구분되어 입력된다.
//
//다음 줄에 N개의 자연수 di(1 <= di <= 100, 000)가 공백으로 구분되어 입력된다.

//T줄에 걸쳐 각 테스트 케이스 별로 주어진 자연수 중 몇 개의 합이 K가 되면 “YES”를 아니면 “NO”를 출력한다.

#include <stdio.h>
int s[30];
int a[30];
int sum;
int n;
int T, N, K;
int sol;

void DFS(int n, int sum)
{
	if(sum>K || sol==1) return; //가지치기
	if (n > N) //종료조건
	{
		if (sum == K) sol = 1;
		return;
	}
	DFS(n + 1, sum + a[n]);
	DFS(n + 1, sum);
}


int main(void)

{	// 여기서부터 작성
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

		if (sol) printf("YES\n"); //문자로 나오게 할 때는 flag신호로 main에서 해결하기
		else printf("NO\n");
	}

	return 0;

}

//전형적인 DFS 해법
//int DFS(int n, int sum)
//{
//	if (sum>K || sol == 1) return; //가지치기
//	if (n > N) //종료조건
//	{
//		if (sum == K) return 1;
//		return 0; //아닐 경우 0이 되는 것도 꼭 쓰자.
//	}
//	if(DFS(n + 1, sum + a[n])) return 1;
//	if(DFS(n + 1, sum)) return 1;
//	return 0;
//}
//
//
//int main(void)
//
//{	// 여기서부터 작성
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
//		if (DFS(1,0)) printf("YES\n"); //문자로 나오게 할 때는 flag신호로 main에서 해결하기
//		else printf("NO\n");
//	}
//
//	return 0;


#endif

#if 0
//(주)정올에서는 여러 개의 빌딩을 새로 지을 계획이다.그래서 빌딩을 세울 장소를 선정하였다.그리고 각 빌딩을 각 장소에 세울 경우에 드는 비용을 추정하였다.예를 들어서 아래의 표를 보자.
//1 2 3
//
//A 4 7 3
//
//B 2 6 1
//
//C 3 9 4
//

//A, B, C 는 건물을 나타내고, 1, 2, 3은 장소를 나타낸다.예를 들어서 건물 B를 장소 1에 세우면 비용이 2가 들고, 장소 2에 세우면 비용이 6, 장소 3에 세우면 비용이 1만큼 든다.물론 한 장소에는 한 건물밖에 세울 수 없다.만일 A를 장소 2에, B를 장소 3에, C를 1에 세우면 전체 비용이 7 + 1 + 3 = 11이 필요하다.그런데 A를 3, B를 1, C를 2에 세우면 3 + 2 + 9 = 14 가 필요하다.
//각 빌딩을 어느 장소에 세우면 비용의 합이 최소가 되는지 구하는 프로그램을 작성하시오.
//입력 파일의 첫 줄은 빌딩의 개수 n(1≤n≤15)이 들어있다.
//
//그 다음 n 줄에는 각 건물을 각 장소에 세울 경우에 드는 비용이 입력된다.물론 각 줄 에는 n개의 수가 입력된다.
//
//비용을 나타내는 수의 범위는 1이상 100미만이다.
//첫 줄에는 최소비용을 출력한다.
//
//둘째 줄에는 건물을 세울 장소들을 알파벳 순서에 따라 빈칸을 하나씩 두고 출력한다.


#include <stdio.h>
int a[30][30]; 
int check[30]; //한 장소에 한 건물을 세우기 때문에, A가 있는 장소는 패스하는 등 중복제거 필요
int s[30];
int ps[30];
int sum;
int min = 0x7fffffff;
int N;

void DFS(int n, int sum)
{
	int i;
	if (min <= sum) return; //가지치기
	
	if (n > N)
	{
		if (min > sum)
		{
			min = sum;
			for (i = 1; i <= N; i++)
			{
				ps[i] = s[i]; //최소 비용일 때 장소 번호 갱신
			}
		}
		return;
	}

	for (i = 1; i <= N; i++)
	{
		if (check[i]) continue;
		check[i] = 1; s[n] = i; //장소 번호 저장
		DFS(n + 1, sum + a[n][i]);
		check[i] = 0;
	}
}

int main(void)

{

	// 여기서부터 작성
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
//전국 자동차 경주 대회가 매년 열리고 있다.이 대회에서는 출발지점부터 도착지점까지 거리가 워낙 멀기 때문에 경주 도중에 각 자동차는 정비소를 방문하여 정비를 받아야 한다.정비소들은 출발지점에서 도착지점으로 가는 길가에 있으며 ①번부터 차례로 번호가 붙어 있다.

//이 대회에서는 참가하는 선수의 안전을 위하여 정비를 받지 않고 미리 정한 거리를 초과하여 갈 수 없도록 규칙을 정하였다.그리고 정비소마다 정비하는데 걸리는 정비 시간이 서로 다를 수 있다.

//정비소에서 정비하는데 걸리는 시간을 가장 적게 하려고 할 때 최소 총 정비시간을 구하는 프로그램을 작성하시오.

//예를 들어, 아래 그림과 같이 정비소가 5개 있고, 한 번 정비를 받고 최대 140㎞를 갈 수 있는 경우를 생각해 보자.출발지점에서 정비소 ①까지의 거리가 100㎞이고, 정비소 ①을 방문하여 정비할 때 걸리는 시간은 5분이다.

//자동차가 출발지점에서 대회 규칙을 지키면서 정비소 ①, ③, ⑤를 차례대로 방문하여 도착지점까지 갈 수 있고, 정비소 ②, ④를 방문하여 갈 수도 있다.정비소 ①, ③, ⑤를 방문하는 경우에는 16분(= 5 + 4 + 7분)이 걸리는데, 이것은 정비소 ②, ④를 방문하여 걸리는 21분(= 10 + 11분)보다 총 정비 시간이 적게 걸린다.

//입력 시 첫째 줄에는 정비를 받지 않고 갈 수 있는 최대 거리가 주어진다.둘째 줄에는 정비소의 개수가 입력되는데 정비소 수는 50개 이하이다.셋째 줄에는 인접한 정비소 사이의 거리가 차례로 주어진다.넷째 줄에는 정비소 별 정비 시간이 차례로 주어진다.모든 입력은 양의 정수이다.

//첫째 줄에 정비소에서 정비하는데 걸리는 총 정비 시간을 출력한다. 정비소를 전혀 방문하지 않아도 되는 경우에 총 정비 시간을 0으로 출력한다.


#include <stdio.h>
int N;
int max;
int min=0x7fffffff;
int d[60];
int t[60];
int sum, d_sum;
int n;
int h;

void DFS(int n, int sum, int d_sum) //이진트리에선 if-else를 쓰지 않는다.(가능한 모든 경우를 위해)
{
	if (min <= sum) return;
 	if (n > N)
	{
		if (min > sum) min = sum;
		return;
	}

	if (d_sum + d[n] <= max)
	{
		DFS(n + 1, sum, d_sum + d[n]); //정비 안 받는 경우
	}
	DFS(n + 1, sum + t[n], d[n]); //정비 받는 경우

}


int main(void)

{
	int i;
	// 여기서부터 작성
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
//양의 정수 X와 K가 주어졌을 때, 다음의 방정식을 만족하는 임의의 양의 정수 Y 중에서 K번째로 작은 숫자를 찾는 프로그램을 작성하라.

//X + Y = X | Y

//여기서 '|'는 OR연산을 뜻한다.OR연산은 두 개의 정수를 2진수로 바꾼 다음에 2진수로 이뤄진 숫자의 동일한 위치에 대해서 둘 다 0일 경우 0, 둘 중에 하나라도 1일 경우 1을 취하는 연산자다.

//예를 들어 X가 3이고, Y가 6일 경우 X | Y는 다음과 같다. 011 OR 110 = 111, 111을 10진수로 바꾸면 7이므로, 3 | 6 = 7이 된다.

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
//문제를 잘 풀기로 소문난 도경이는 모든 올림피아드 대회에 참가하고 싶어 했다.대회에 참가하여 상이란 상은 다 타고 싶은 마음이었지만, 한 가지 걸리는 것이 있었다.
//문제는 올림피아드 대회가 모두 해외에서 열리는 관계로 비행기 값이 굉장히 많이 들어간다는 것이다.결국에는 집으로 다시 돌아와야 하는데, 모든 대회에 1번씩만 참가하고 집으로 돌아오는 경비를 가장 최소화하고 싶다.도경이는 이것을 해결하지 못하면, 대회에 참가하기가 어렵게 된다.대회는 참가하기만 하면 언제든지 알고리즘 문제를 풀 수 있기 때문에 경기를 계산하는 것 이외의 사항은 고려하지 않아도 된다.
//첫 줄은 참가하는 대회의 수 N(1≤N≤12)을 입력 받는다.이때, 출발지(집)는 1번으로 한다.
//
//둘째 줄은 N*N 크기의 대회 개최지와 개최지를 이동하는 항공료(0≤항공료<100)가 나온다.각 항공료는 한 칸의 공백으로 구분된다.만약에 개최지에서 개최지로 이동할 수 있는 항공로가 없다면 항공료의 값을 0으로 표시한다.
//집에서 출발하여 전체 대회를 모두 참가하고 돌아올 때, 최소의 항공료를 출력한다.
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
			if (fee[i][j] == 0) fee[i][j] =10000; //0x7ffffff정도. 0x7fffffff를 넣으면 음수가 되어버림.
		}
	}
	check[1] = 1; //본인 집일 때도 체크하기
	DFS(1, 0, 1);

	printf("%d", min);

	return 0;

}
#endif

#if 0
//농부 John은 최근 소 도서관을 위한 책꽂이를 구매했지만, 책이 빠른 속도로 채워져서 지금은 가장 윗부분에만 공간이 남아있다.
//
//농부 John은 N마리의 소를 가지고 있다.(1 <= N <= 20) 각각의 소의 키는 H_i이다.(1 <= H_i <= 1, 000, 000)
//
//책꽂이는 B 높이를 가지고 있다. (1 <= B <= S, S는 모든 소의 키의 합계임).
//
//책꽂이의 젤 윗부분에 닿기 위해서, 하나 혹은 여러 마리의 소가 서로의 머리 위에 올라설 수 있다.그래서 그들의 전체 높이는 개개인 소의 키의 합계가 된다.소들이 책꽂이의 젤 윗부분에 닿기 위해서는 이 전체높이가 책꽂이 높이에 비해 낮아서는 안 된다.
//
//소들이 서로의 머리 위에 올라서게 되면, 높으면 높을수록 위험해지기 때문에, 당신이 할 일은 책꽂이의 젤 윗부분에 닿을 수 있게 하는 소들의 키의 합의 최소값을 찾는 것이다.당신의 프로그램은 당신이 찾게 된 소들의 키의 합이 책꽂이로부터 얼마나 초과하는지를 출력하면 된다.
//첫 번째 줄에는 테스트케이스의 갯수 T가 입력된다.
//
//두 번째 줄부터 T개의 테스트케이스 세트가 주어진다.
//
//테스트케이스의 첫번째 줄은 소의 마리수 N과 B가 주어진다. (1 <= N <= 20, 1 <= B <= S, S는 모든 소의 키의 합계)
//
//테스트케이스의 두번째 줄부터 N줄에 각 소의 키 H_i가 주어진다. (1 <= H_i <= 1, 000, 000)
//적당한 소들의 키의 합과 책꽂이 높이의 차이를 출력한다.
#include <stdio.h>
int cow[30];
int N;
int min = 0x7fffffff;
int T, B;

void DFS(int n, int sum)
{
	if (min <= sum ||min==0) return;//min은 최소 1이상은 되어야 한다.
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
//체스에서 queen의 가로, 세로, 대각선 방향으로 어느 곳이나 한 번에 움직일 수 있다.즉 다음과 같은 체스판에서 queen이 X라고 표시된 위치에서 있을 때, 그 다음 queen이 움직여 갈 수 있는 부분은 어둡게 칠해진 부분 중의 하나이다.


//N*N 크기의 정방형 체스판이 주어졌다.우리는 거기에 N개의 queen을 배치하려고 하는데, 모든 queen들은 서로 잡아먹을 수 없어야 한다.그렇다면 queen들을 어떻게 배치해야만 할까 ? 가능한 모든 경우의 개수를 출력한다.
//Queen의 수 N(1≤N≤10)을 입력 받는다.
//N*N의 체스판에서 N개의 queen들이 서로 잡아먹지 않는 위치로 놓을 수 있는 방법의 수를 출력한다.

#include <stdio.h>
int check[20][20];
int N;
int sol;
int func(int si, int sj)
{
	int i, j;
	for (i = si; i > 0; i--) if (check[i][sj]) return 1;
	for (i = si, j = sj; i > 0&& j > 0; i--, j--) if (check[i][j]) return 1; //&&연산자가 필요
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
	// 여기서부터 작성
	scanf("%d", &N);

	DFS(1);

	printf("%d", sol); 

	return 0;

}

#endif

#if 0
//절대반지를 얻기 위하여 반지원정대가 출발한다.원정대가 지나가야할 다리는 두 개의 인접한 돌다리로 구성되어 있다.하나는 <악마의 돌다리>이고 다른 하나는 <천사의 돌다리>이다.
//
//
//
//아래 그림 1은 길이가 6인 다리의 한 가지 모습을 보여준다.그림에서 위의 가로줄은 <악마의 돌다리>를 표시하는 것이고, 아래의 가로줄은 <천사의 돌다리>를 표시한다.두 돌다리의 길이는 항상 동일하며, 각 칸의 문자는 해당 돌에 새겨진 문자를 나타낸다.두 다리에 새겨진 각 문자는{ R, I, N, G, S } 중 하나이다.
//반지원정대가 소유하고 있는 마법의 두루마리에 <악마의 돌다리>와 <천사의 돌다리>를 건너갈 때 반드시 순서대로 밟고 지나가야할 문자들이 적혀있다.이 순서대로 지나가지 않으면 돌다리는 무너져 반지원정대는 화산 속으로 떨어지게 된다.
//
//다리를 건널 때 다음의 제한 조건을 모두 만족하면서 건어야 한다.
//1) 왼쪽(출발지역)에서 오른쪽(도착지역)으로 다리를 지나가야 하며, 반드시 마법의 두루마리에 적힌 문자열의 순서대로 모두 밟고 지나가야 한다.
//2) 반드시 <악마의 돌다리>와 <천사의 돌다리>를 번갈아가면서 돌을 밟아야 한다.단, 출발은 어떤 돌다리에서 시작해도 된다.
//3) 반드시 한 칸 이상 오른쪽으로 전진해야하며, 건너뛰는 칸의 수에는 상관이 없다.만일 돌다리의 모양이 그림 1고 같고 두루마리의 문자열이 "RGS"라면 돌다리를 건너갈 수 있는 경우는 다음의 3가지 뿐이다. (아래 그림에서 빨간색 문자는 밟고 지나가는 돌다리를 나타낸다.)
//왜냐하면 첫 번째는 문자열 "RGS"를 모두 밟고 지나가야 하는 조건 1)을 만족하지 않으며, 두 번째는 번갈아가면서 돌을 밟아야 하는 조건 2)를, 세 번째는 앞으로 전진을 하여야하는 조건 3)을 만족하지 않기 때문이다.
//
//마법의 두루마리에 적힌 문자열과 두 다리의 돌에 새겨진 문자열이 주어졌을 때, 돌다리를 통과할 수 있는 모든 가능한 방법의 수를 계산하는 프로그램을 작성하시오.예를 들어, 그림 1의 경우는 통과하는 방법이 3가지가 있으므로 3을 출력해야 한다.
//첫째 줄에는 마법의 두루마리에 적힌 문자열(R, I, N, G, S 로만 구성된)이 주어진다.
//
//
//
//이 문자열의 길이는 최소 1, 최대 10 이다.
//
//
//
//그 다음 줄에는 각각 <악마의 돌다리>와 <천사의 돌다리>를 나타내는 같은 길이의 문자열이 주어진다.
//
//
//
//그 길이는 5 이상, 30 이하이다.
//출력 파일에 마법의 두루마리에 적힌 문자열의 순서대로 다리를 건너갈 수 있는 방법의 수를 출력한다.
//
//
//
//그러한 방법이 없으면 0을 출력한다.
//
//
//
//모든 테스트 데이터에 대한 출력결과는 231 - 1 이하이다.

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
//미로 찾기
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
//장기
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
	// 여기서부터 작성
	return 0;
}
#endif

#if 0
//제3국가에 가면 아직 개별 마을이 독립적으로 생활하며 상호 교류를 하지 않는 경우도 많다고 한다.어떤 한 국가에서 이러한 개별 마을을 서로 연결시키기 위한 도로를 계획하기로 했다.물론 각각의 마을들을 전부 연결하면 마을에서 마을로 빠르게 이동할 수 있겠지만, 그러기에는 예산이나 자원이 부족해 최소한의 비용만으로 모든 마을을 연결시키려고 한다.예를 들어 마을 a, b, c가 있을 때, a와 b가 연결되어 있고, b와 c가 연결되어 있으면 a와 c가 연결되어 있다고 본다.
//
//마을의 수(N)과 마을간의 도로 건설 비용(Ei, j)이 아래와 같이 triangular matrix 형태로 주어진다고 할 때 모든 마을을 연결하기 위한 최소한의 비용의 총 합(C)을 구하라.
//
//단, 0은 두 마을간 도로를 건설할 수 없음을 의미하며, 특정 마을에서 자기 자신으로의 도로(Vk, k) 또한 건설할 수 없다.

//마을의 수 N (3≤N≤100)이 입력되고, Ei,j(0≤Eij≤100,000)가 아래와 같이 triangular matrix 형태로 주어진다.

//모든 마을을 연결하기 위한 최소한의 비용의 합(C)을 출력한다.

#include <stdio.h>
int c[110][110];
int cost[110];
int check[110];
#define INF 0x7fffffff
int main(void)
{	// 여기서부터 작성
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

{	// 여기서부터 작성
	scanf("%d %d", &N, &M);
	DFS(1, 0);
	return 0;
}
#endif

#if 0
//초밥
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
		// 여기서부터 작성
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
int a[10];//구슬
int b[20];//추
int check[20];
int s;
int DFS1(int n, int sum, int i)
{
	if (n > N)
	{
		if (sum == a[i]) return 1;
		return 0;
	}
	if (DFS1(n + 1, sum - b[n], i)) return 1; //sum을 쌓다가 구슬 쪽으로 추를 뺄 경우
	//함수를 따로 떼면 겹치는 경우 발생 가능성
	//DFS1에서 N를 리턴해서 DFS2로 갔지만 겹치는 부분 때문에 Y 가 나오기 전에 N 발생 가능성.
	if (DFS1(n + 1, sum + b[n], i)) return 1;
	if (DFS1(n + 1, sum, i)) return 1;
	return 0;
}


int main(void)

{
int flag = 0;

	// 여기서부터 작성
	scanf("%d", &N); //추
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &b[i]);
		s += b[i];
	}

	scanf("%d", &M); //구슬

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



	//입력받는부분

	scanf("%d", &T);

	while (T-->0)

	{

		scanf("%d", &K);

		for (i = 0; i<6; i++)

		{

			scanf("%d %d", &a[i][0], &a[i][1]);

		}



		//여기서부터작성
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
		//출력하는부분

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

	// 여기서부터 작성
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
int c1[30]; //n열에 여왕이 있는지 확인
int c2[30]; //n열에 여왕이 있는지 확인
int c3[30]; //n열에 여왕이 있는지 확인
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

{// 여기서부터 작성
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
		DFS(n + 1, sum + a[sol][i],i); //sol지점에서 i번째 도시로 이동. check[1]=1인 상태로 
		//여기 넘어 오지 않는다.
		//1로는 맨 마지막에 돌아오기 때문.
		check[i] = 0;
	}

}
int main(void)

{
	int i, j;
	// 여기서부터 작성
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

	// 여기서부터 작성
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
		if (a[n][i] == 1 && s[i] >= x) return 0; //부하가 더 많이 받는 경우
		if (a[i][n] == 1 && s[i] <= x) return 0;//상사가 더 적게 받는 경우
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


