/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:56:17 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/11 18:17:18 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatcher(char str, va_list *args)
{
	if (str == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (str == 'p')
		return (ft_putptr((unsigned long)va_arg(*args, unsigned long)));
	else if (str == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	else if (str == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (str == 'u')
		return (ft_putunint(va_arg(*args, unsigned int)));
	else if (str == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (str == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_dispatcher(str[++i], &args);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// //================= MAIN 1 ===============//

// int main(int argc, char **argv)
// {
//     int i;x

//     if (argc < 2)
//     {
//         ft_printf("Usage: ./test [string] [string] ...\n");
//         return (0);
//     }
//     i = 1;
//     while (i < argc)
//     {
//         ft_printf("arg %d : %s\n", i, argv[i]);
//         i++;
//     }
//     return (0);
// }

//================ MAIN 2 ================//

// void    print_sep(char *title)
// {
//     printf("─────────────────────────────────────\n");
//     printf("  %s\n", title);
//     printf("─────────────────────────────────────\n");
// }

// void    check(int ret1, int ret2)
// {
//     if (ret1 == ret2)
//         printf("✅ OK | printf: %d | ft_printf: %d\n\n", ret1, ret2);
//     else
//         printf("❌ KO | printf: %d | ft_printf: %d\n\n", ret1, ret2);
// }

// int main(void)
// {
//     int ret1;
//     int ret2;
//     int n;

//     // ─── %c ───
//     print_sep("TEST %c");

//     printf("test 'A'          : ");
//     ret1 = printf("%c\n", 'A');
//     printf("                  : ");
//     ret2 = ft_printf("%c\n", 'A');
//     check(ret1, ret2);

//     printf("test espace ' '   : ");
//     ret1 = printf("%c\n", ' ');
//     printf("                  : ");
//     ret2 = ft_printf("%c\n", ' ');
//     check(ret1, ret2);

//     printf("test '0'          : ");
//     ret1 = printf("%c\n", '0');
//     printf("                  : ");
//     ret2 = ft_printf("%c\n", '0');
//     check(ret1, ret2);

//     // ─── %s ───
//     print_sep("TEST %s");

//     printf("test hello world  : ");
//     ret1 = printf("%s\n", "hello world");
//     printf("                  : ");
//     ret2 = ft_printf("%s\n", "hello world");
//     check(ret1, ret2);

//     printf("test vide \"\"      : ");
//     ret1 = printf("%s\n", "");
//     printf("                  : ");
//     ret2 = ft_printf("%s\n", "");
//     check(ret1, ret2);

//     printf("test NULL         : ");
//     ret1 = printf("%s\n", (char *)NULL);
//     printf("                  : ");
//     ret2 = ft_printf("%s\n", (char *)NULL);
//     check(ret1, ret2);

//     // ─── %d ───
//     print_sep("TEST %d");

//     printf("test 42           : ");
//     ret1 = printf("%d\n", 42);
//     printf("                  : ");
//     ret2 = ft_printf("%d\n", 42);
//     check(ret1, ret2);

//     printf("test -42          : ");
//     ret1 = printf("%d\n", -42);
//     printf("                  : ");
//     ret2 = ft_printf("%d\n", -42);
//     check(ret1, ret2);

//     printf("test 0            : ");
//     ret1 = printf("%d\n", 0);
//     printf("                  : ");
//     ret2 = ft_printf("%d\n", 0);
//     check(ret1, ret2);

//     printf("test INT_MAX      : ");
//     ret1 = printf("%d\n", 2147483647);
//     printf("                  : ");
//     ret2 = ft_printf("%d\n", 2147483647);
//     check(ret1, ret2);

//     printf("test INT_MIN      : ");
//     ret1 = printf("%d\n", (int)-2147483648);
//     printf("                  : ");
//     ret2 = ft_printf("%d\n", (int)-2147483648);
//     check(ret1, ret2);

//     // ─── %i ───
//     print_sep("TEST %i");

//     printf("test 42           : ");
//     ret1 = printf("%i\n", 42);
//     printf("                  : ");
//     ret2 = ft_printf("%i\n", 42);
//     check(ret1, ret2);

//     printf("test -123         : ");
//     ret1 = printf("%i\n", -123);
//     printf("                  : ");
//     ret2 = ft_printf("%i\n", -123);
//     check(ret1, ret2);

//     printf("test 0            : ");
//     ret1 = printf("%i\n", 0);
//     printf("                  : ");
//     ret2 = ft_printf("%i\n", 0);
//     check(ret1, ret2);

//     // ─── %u ───
//     print_sep("TEST %u");

//     printf("test 42           : ");
//     ret1 = printf("%u\n", 42u);
//     printf("                  : ");
//     ret2 = ft_printf("%u\n", 42u);
//     check(ret1, ret2);

//     printf("test 0            : ");
//     ret1 = printf("%u\n", 0u);
//     printf("                  : ");
//     ret2 = ft_printf("%u\n", 0u);
//     check(ret1, ret2);

//     printf("test UINT_MAX     : ");
//     ret1 = printf("%u\n", 4294967295u);
//     printf("                  : ");
//     ret2 = ft_printf("%u\n", 4294967295u);
//     check(ret1, ret2);

//     // ─── %x ───
//     print_sep("TEST %x");

//     printf("test 255          : ");
//     ret1 = printf("%x\n", 255);
//     printf("                  : ");
//     ret2 = ft_printf("%x\n", 255);
//     check(ret1, ret2);

//     printf("test 0            : ");
//     ret1 = printf("%x\n", 0);
//     printf("                  : ");
//     ret2 = ft_printf("%x\n", 0);
//     check(ret1, ret2);

//     printf("test UINT_MAX     : ");
//     ret1 = printf("%x\n", 4294967295u);
//     printf("                  : ");
//     ret2 = ft_printf("%x\n", 4294967295u);
//     check(ret1, ret2);

//     // ─── %X ───
//     print_sep("TEST %X");

//     printf("test 255          : ");
//     ret1 = printf("%X\n", 255);
//     printf("                  : ");
//     ret2 = ft_printf("%X\n", 255);
//     check(ret1, ret2);

//     printf("test 0            : ");
//     ret1 = printf("%X\n", 0);
//     printf("                  : ");
//     ret2 = ft_printf("%X\n", 0);
//     check(ret1, ret2);

//     printf("test UINT_MAX     : ");
//     ret1 = printf("%X\n", 4294967295u);
//     printf("                  : ");
//     ret2 = ft_printf("%X\n", 4294967295u);
//     check(ret1, ret2);

//     // ─── %p ───
//     print_sep("TEST %p");

//     n = 42;
//     printf("test &n           : ");
//     ret1 = printf("%p\n", &n);
//     printf("                  : ");
//     ret2 = ft_printf("%p\n", &n);
//     check(ret1, ret2);

//     printf("test NULL         : ");
//     ret1 = printf("%p\n", NULL);
//     printf("                  : ");
//     ret2 = ft_printf("%p\n", NULL);
//     check(ret1, ret2);

//     // ─── %% ───
//     print_sep("TEST %%");

//     printf("test 100%%        : ");
//     ret1 = printf("100%%\n");
//     printf("                  : ");
//     ret2 = ft_printf("100%%\n");
//     check(ret1, ret2);

//     // ─── MIXED ───
//     print_sep("TEST MIXTE");

//     printf("test multi args   : ");
//     ret1 = printf("%s a %d ans et mesure %c\n", "Bob", 30, 'Z');
//     printf("                  : ");
//     ret2 = ft_printf("%s a %d ans et mesure %c\n", "Bob", 30, 'Z');
//     check(ret1, ret2);

//     printf("test hex mixte    : ");
//     ret1 = printf("%x et %X\n", 255, 255);
//     printf("                  : ");
//     ret2 = ft_printf("%x et %X\n", 255, 255);
//     check(ret1, ret2);

//     return (0);
// }
