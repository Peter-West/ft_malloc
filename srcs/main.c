#include "ft_malloc.h"

#include <stdio.h>
#include <string.h>

int main() {
	char	*test0 = NULL;
	test0 = ft_malloc(8);
	memcpy(test0, "Bonjour\n", 8);
	printf("test0 : %s", test0);
	return (0);
}