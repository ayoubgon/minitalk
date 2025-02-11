#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>

int	ft_atoi(const char *str);
// ft_printf
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
void	ft_puthex(unsigned long adr, char *hex, int *len);
int		ft_putstr(char *str);
void	ft_putnbr(int nb, int *len);
int		ft_putfun(va_list arg, char s);
void	ft_putunsignednbr(unsigned int nb, int *len);
void	ft_putadr(unsigned long nbr, int *len);

#endif
