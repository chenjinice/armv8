
volatile unsigned int *const UART0_TX = (unsigned int *)0x09000000;

void uart_print(const char *str)
{
	while (*str != '\0')
	{
		*UART0_TX = *str;
		str++;
	}
}

int sub(int a, int b)
{
	return a + b;
}

int add(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	int ret = a + b + c + d + e + f + g + h + i;
	return ret;
}

int main()
{
	int a = 11;
	int b = 12;
	int ret = add(1, 2, 3, 4, 5, 6, 7, 8, 9);
	uart_print("1234567890\n");

	return 0;
}
