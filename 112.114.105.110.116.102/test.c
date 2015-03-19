#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <limits.h>
#include "libft.h"

#include <wchar.h>

int					main(int ac, char **av)
{
//	if (ac == 2)
//		printf("\nprintf return = %d\n", printf("%d", atoi(av[1])));
//	printf("\n%d\n", ft_printf("tata"));
	char			*toto;
	char			z;
	unsigned char	utf8[5];

	(void)z;
	setlocale(LC_ALL, "");
//	char	*titi;
//	char	*tutu;

//	ft_printf("tata\n");
//	printf("%s\n", 84);
//	printf("write return = %d\n", (int)write(1, "tata\n", sizeof("tata\n")));
//	char	c;
//
//	c = '\n';
//	printf("typeof return = %s\n", typeof(write(1, &c, 1)));
//	puts(NULL);
	char	*str = "toto";
	int		test[] = {9, 8, 7, 6};

//	ft_putnbr(puts(NULL));
//	ft_putendl("");
//	ft_putnbr(printf("%s%s%s%s%s", "1", "2", "3", "4", "5"));
//	ft_putnbr(printf("s: %s, p: %p, d:%d\n", "a string", str, 42));
	// printf("%u\n", L"我是一只猫。"[6]);
	/*int		c;

	c = L"我是一只猫。"[0] & 0xf;
	write(1, &c, 1);
	c = (L"我是一只猫。"[1] << 8) & 0xff;
	write(1, &c, 1);
	c = (L"我是一只猫。"[2] << 16) & 0xff;
	write(1, &c, 1);
	c = (L"我是一只猫。"[3] << 24) & 0xff;
	write(1, &c, 1);
	c = (L"我是一只猫。"[4] << 32) & 0xff;
	write(1, &c, 1);
	c = (L"我是一只猫。"[5] << 40) & 0xff;
	write(1, &c, 1);
	c = (L"我是一只猫。"[6] << 48) & 0xff;
	write(1, &c, 1);
	write(1, "\n", 1);*/
	/*ft_printf("%C\n", L'莨')*/;
	/*ft_puthex(L'莨')*/;
	ft_putendl("");
	int		c = 0x83a8;
	/*ft_putwchar(L'莨');*/
	int		*addr;
	/*char	*cheat = "\u83a8";*/
	int		nbr;
	wchar_t	wc;
	char	*cheat;

	/*printf("sizeof 1 = %ld\nsizeof 2 = %ld\n", sizeof('B'), sizeof(L'莨'));*/
	/*wc = L'莨';*/
	/*wc = (wchar_t *)ft_memalloc(100);*/
	/*wmemset(&wc, L'我', sizeof(L'我'));*/
	/*wc = wcsdup(L"我是一只猫。");*/
	/*wmemcpy(wc, L"莨", 100);*/
	ft_putendl("==========");
	/*c = 0xE5928C;*/
	/*write(1, "\u83a8", 3);*/
	/*c = 0xe5;
	write(1, &c, 1);
	c = 0x92;
	write(1, &c, 1);
	c = 0x8c;
	write(1, &c, 1);*/
	/*cheat = ft_strnew(100);*/
	/*wmemset(&wc, L'莨', 1);
	unsigned char	byte;

	byte = ((unsigned char)L'莨') & 0xff;
	write(1, &byte, 1);
	byte = ((unsigned char)L'莨' >> 8) & 0xff;
	write(1, &byte, 1);
	byte = ((unsigned char)L'莨' >> 16) & 0xff;
	write(1, &byte, 1);
	byte = ((unsigned char)L'莨' >> 24) & 0xff;
	write(1, &byte, 1);*/
	/*mbstate_t mbs;
	mbrlen (NULL,0,&mbs);

	size_t length;
	const wchar_t* pt = L"B";

	if (wcrtomb(cheat, *pt) == (size_t)-1)
		puts("ERROR");
	printf("TEST = %s\n", cheat);*/
	/*ft_putnbr(printf("{%010s}", "tata"));*/
	/*printf("%lld", LLONG_MIN);*/
	ft_putendl("");
	int		tc;
	int		d;
	char	*kaki;

	tc = 92;
	d = 0;
	kaki = ft_memalloc(100);
	/*kaki += 50;*/
	ft_ztom(kaki + 50, tc);
	d = ft_mtoz(kaki + 50);
	/*kaki -= 50;*/
	ft_putendl("\n----------");
	char	error_type;

	error_type = 'A';
	/*ft_putnbr(ft_printnwchar(error_type, ' ', 50));*/
	/*ft_putnbr(ft_printnlong(-101564684, 'X', 100));*/
	u_char	*wdebug;

	/*wdebug = ft_memalloc()*/
	/*ft_wc_to_utf8(L'我', wdebug);
	ft_putnbr(ft_strlen((char *)wdebug));*/
	/*ft_putnbr(printf("%hhO, %hhO", 0, USHRT_MAX));
	ft_putnbr(ft_printf("%hhO, %hhO", 0, USHRT_MAX));*/
	ft_putnbr(ft_printf("%.4x", 42));
	ft_putnbr(printf("%.4x", 42));
	ft_putendl("\n----------");
	/*ft_putulong(12345);*/
	ft_putendl("\n==========");
	/*ft_putlong(-100)*/;
	/*ft_putnbr(-10000);*/
	/*printf("wcslen(wc) = %zu\n", wcslen(wc));*/
	/*wc = L'B';*/
	nbr = 0;
	addr = (int *)cheat;
	/*free(wc);*/
	wchar_t		w;

	w = L'莨';
	/*printf("sizeof a = %ld\nsizeof b = %ld\n", sizeof(w), sizeof(L'莨'));*/
	/*printf(L"%c", w);*/
	ft_putendl("");
	/*printf("return test = %d\n", L"B"[1])*/;
	ft_putendl("");
	/*ft_putnbr(printf("%s\n", "\u2510"));*/
/*	printf();
*/	/*ft_putnbr(printf("%x\n", 0x12345678));
	ft_putendl("");
	ft_putnbr(printf("%o\n", 0x12345678));
	ft_putendl("");
	ft_putnbr(printf("%u\n", 0x12345678));
	ft_putendl("");
	ft_putnbr(ft_printf("%o\n", 0x12345678));
	ft_putendl("");*/
//	ft_putnbr(ft_printf("%%\n", str));
	ft_putendl("");
	return (0);
}
