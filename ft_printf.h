#include "libft/libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define CHR_PATTERN "c"
#define STR_PATTERN "s"
#define PTR_PATTERN "p"
#define DEC_PATTERN "d"
#define INT_PATTERN "bob"
#define U_INT_PATTERN "u"
#define HEX_PATTERN "x"
#define HEX_UC_PATTERN "X"
#define PERCENT_PATTERN "%"

#define HEX_UC_ALPHABET "0123456789ABCDEF"
#define HEX_LC_ALPHABET "0123456789abcdef"
#define DEC_ALPHABET "0123456789"

int	ft_printf(const char *str, ...);
