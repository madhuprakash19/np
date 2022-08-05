#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sender();
void receiver(int *message, int l2);

int main()
{
	sender();
	return 0;
}

void sender()
{
	int i, j, n, count = 0, onecounter = 0, l1, zero = 0;
	int msg[50];
	int result[50];

	printf("Enter the number of bits to be sent: ");
	scanf("%d", &n);
	printf("Enter the bits: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &msg[i]);
	}
	result[0] = 0;
	result[1] = 1;
	result[2] = 1;
	result[3] = 1;
	result[4] = 1;
	result[5] = 1;
	result[6] = 1;
	result[7] = 0;
	j = 8;

	for (i = 0; i < n; i++)
	{

		if (count == 5 && zero == 1)
		{
			result[j++] = 0;
			onecounter++;
			count = 0;
		}
		if (msg[i] == 0)
		{
			result[j++] = msg[i];
			zero = 1;
			count = 0;
		}
		else
		{
			result[j++] = msg[i];
			count++;
		}
	}
	if (count == 5)
	{
		result[j++] = 0;
		onecounter++;
		count = 0;
	}
	result[j++] = 0;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 0;
	l1 = 16 + n + onecounter;
	for (i = 0; i < l1; i++)
	{
		printf("%d", result[i]);
	}
	receiver(result, l1);
}

void receiver(int *result, int l2)
{
	int i, j, counter = 0, l3;
	int mesg[100];
	l3 = l2 - 8;
	j = 0;
	for (i = 8; i < l3; i++)
	{

		if (counter == 5)
		{
			i++;
			counter = 0;
		}

		if (result[i] == 0)
		{
			mesg[j] = result[i];
			j++;
			counter = 0;
		}
		else
		{
			mesg[j] = result[i];
			j++;
			counter++;
		}
	}
	printf("\n Receiver side message is:");
	for (i = 0; i < j; i++)
	{
		printf("%d", mesg[i]);
	}
}
