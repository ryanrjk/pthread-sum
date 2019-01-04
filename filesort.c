#include<stdio.h>
void sort(int *p, int size)
{
int i, j;
for (i = 0; i < size - 1; ++i)
{
for (j = 0; j < size - i - 1; ++j)
{
if (p[j] > p[j + 1])
{
int temp;
temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
}

void createtestfile()
{
FILE *f1;
f1 = fopen("program.txt", "w");
fprintf(f1, "6#this is comment\n");
fprintf(f1, "3#this is comment\n");
fprintf(f1, "7#this is comment\n");
fprintf(f1, "2\n");
}

void readtestfile()
{
FILE *fp;
char buff[1024];
int value;

int number_of_lines;
fp = fopen("program.txt", "r");
do
{
fgets(buff, 1024, fp);
fscanf(fp, "%d", &value);
number_of_lines++;
buff[number_of_lines] = value;
} while (fp != EOF);

sort(buff, number_of_lines);

int i;
for (i = 1; i < number_of_lines; i++)
{
printf("value is %d", buff[i]);
}
}

int main()
{
createtestfile();
readtestfile();
return 0;
}
