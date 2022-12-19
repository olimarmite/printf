#include "ft_printf.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
int	main(void)
{
	// ft_printf("Hello %c", 'H');
	// ft_printf("\n---printf:---\n");
	// printf("Hello %c", 'H');
	// fflush(stdin);
	// ft_printf("\n\n");
	void *ptr = malloc(1);

	//printf("%ld", LONG_MIN);
	ft_printf("[%bob]\n", ft_printf(" %c %c %c ", 0, '1', '2'));
	ft_printf("[%i]\n",ft_printf("Hello %c\n", 0));
	ft_printf("[%i]\n",ft_printf("Hello %c\n", 'H'));
	ft_printf("[%i]\n",ft_printf("Hello %c%c\n", 'H', 'B'));
	ft_printf("[%i]\n",ft_printf("Hello %s\n", "BOUH"));
	ft_printf("[%i]\n",ft_printf("Hello %s\n", NULL));
	ft_printf("[%i]\n",ft_printf("Hello %d\n", NULL));
	ft_printf("[%i]\n",ft_printf("Hello %d\n", -42));
	ft_printf("[%i]\n",ft_printf("Hello %i\n", -42));
	ft_printf("[%i]\n",ft_printf("Hello %x\n", -42));
	ft_printf("[%i]\n",ft_printf("Hello %x\n", 42));
	ft_printf("[%i]\n",ft_printf("Hello %X\n", -42));
	ft_printf("[%i]\n",ft_printf("Hello %u\n", -42));
	ft_printf("[%i]\n",ft_printf("Hello %u\n", 42));
	ft_printf("[%i]\n",ft_printf("Hello %p\n", ptr));
	ft_printf("[%i]\n",ft_printf("Hello %p\n", NULL));
	ft_printf("[%i]\n",ft_printf(" %p %p ", 0 , 0));
	ft_printf("[%i]\n",ft_printf(" %p %p ", LONG_MIN, LONG_MAX));

	//ft_printf("[%i]\n",ft_printf(" %% "));
	//ft_printf("[%i]\n",ft_printf("qwhdqwkhqi % qwlkdq; ;  "));
	//ft_printf("[%i]\n",ft_printf("%"));





	printf("\n---printf:---\n");
	ft_printf("[%i]\n", printf(" %c %c %c ", 0, '1', '2'));
	ft_printf("[%i]\n",	printf("Hello %c\n", 0));
	ft_printf("[%i]\n",printf("Hello %c\n", 'H'));
	ft_printf("[%i]\n",printf("Hello %c%c\n", 'H', 'B'));
	ft_printf("[%i]\n",printf("Hello %s\n", "BOUH"));
	ft_printf("[%i]\n",printf("Hello %s\n", (char *)NULL));
	ft_printf("[%i]\n",printf("Hello %d\n", NULL));
	ft_printf("[%i]\n",printf("Hello %d\n", -42));
	ft_printf("[%i]\n",printf("Hello %d\n", -42));
	ft_printf("[%i]\n",printf("Hello %x\n", -42));
	ft_printf("[%i]\n",printf("Hello %x\n", 42));
	ft_printf("[%i]\n",printf("Hello %X\n", -42));
	ft_printf("[%i]\n",printf("Hello %u\n", -42));
	ft_printf("[%i]\n",printf("Hello %u\n", 42));
	ft_printf("[%i]\n",printf("Hello %p\n", ptr));
	ft_printf("[%i]\n",printf("Hello %p\n", (void *)0));
	ft_printf("[%i]\n",printf(" %p %p ", 0, 0));
	ft_printf("[%i]\n",printf(" %p %p ", LONG_MIN, LONG_MAX));
	ft_printf("[%i]\n",printf(" %% "));
	ft_printf("[%i]\n",printf("qwhdqwkhqi % qwlkdq; ;  "));
	ft_printf("[%i]\n",printf("%"));
	ft_printf("[%i]\n",printf("q%"));
	ft_printf("[%x]\n",NULL);




	printf("\n---end---\n");

	free(ptr);

}
