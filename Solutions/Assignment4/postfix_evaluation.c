#include<stdio.h>
#include<math.h>
#include<string.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

void push(int value)
{
	if (top == SIZE - 1)
		return;
	else
	{
		top++;
		stack[top] = value;

	}
}

int pop()
{
	int value = stack[top];
	top--;
	return value;
}

int isoperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return 1;
	else
		return 0;
}

int main()
{
	char str[SIZE];
	printf("Enter the postfix expression(separated by comma:\n");
	scanf("%s", &str);



	int i = 0;
	int a, b;
	int num = 0, count = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == ',')
			{i++;continue;}
		else if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
		{
			printf("Invalid chacraters!!Cant be evaluated!!!\n");
			return 0;
		}
		else {
			if (isoperator(str[i]))
			{
				switch (str[i])
				{
				case '+':a = pop(); b = pop(); push(a + b); break;
				case '-':a = pop(); b = pop(); push(b-a); break;
				case '*':a = pop(); b = pop(); push(a*b); break;
				case '/':a = pop(); b = pop(); push(b/a); break;

				}
				i++;
			}
			else {
				int j = i;
                count=0,num=0;
				while (str[j]!=' '&&str[j]!= ',')
					{count++;j++;}

				while (count)
				{
					num += pow(10, count-1)*(str[i]-'0');
					i++;
					count--;
				}

				push(num);

			}
		}
	}

	printf("Result of the postfix expression %s is::%d", str,stack[top]);

}
