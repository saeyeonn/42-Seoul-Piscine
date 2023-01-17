/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:37:10 by saelim            #+#    #+#             */
/*   Updated: 2022/09/15 21:30:25 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_set_addr(unsigned long long llu, int index, char *arr)
{
	const char	*hex;
    // 인덱스 15, llu = 주소값
	hex = "0123456789abcdef";
	if (llu >= 16) //16진수 나누는거
		ft_set_addr(llu / 16, index - 1, arr);
	else // 0채우기
	{
		arr[index] = '0';
		if (index > 0)
			ft_set_addr(0, index - 1, arr);
	}
	arr[index] = hex[llu % 16]; //담기
}

void	ft_print_addr(char *arr) //출력
{
	int	i;

	i = 0;
	while (i < 16)
		write(1, &arr[i++], 1);
	write(1, ": ", 2);
}

void	ft_char_hex(char *str, unsigned int size)
{
	unsigned int	count; // 사이즈 만큼 돌아야한다.

	if (size >= 16) //16보다 크면 16으로 끝는다.
		size = 16;
	count = 0;
	while (*str != '\0' && count < size)
	{
		write(1, &"0123456789abcdef"[*str / 16], 1);
		write(1, &"0123456789abcdef"[*str++ % 16], 1);
		if (++count % 2 == 0) // 2배수라면 띄아쓰기
			write(1, " ", 1);
	}
	if (*str == '\0' && count < size) //널값찍기
	{
		write(1, "00", 2);
		if (++count % 2 == 0)
			write(1, " ", 1);
	}
	while (count < 16) //중간에 문자가 끝나면 공백으로 채워준다 count가 16까지 찍혀야한다.
	{
		write(1, "  ", 2);
		if (++count % 2 == 0)
			write(1, " ", 1);
	}
}

void	ft_print_str(char *str, unsigned int size)
{
	unsigned int	count;

	if (size >= 16)
		size = 16;
	count = 0;
	while (*str != '\0' && count < size)
	{
		if (*str < 32 || *str > 126) //출력불가능한거 .으로 대체
			write(1, ".", 1);
		else
			write(1, str, 1); //나머지 출력
		count++;
		str++;
	}
	if (*str == '\0' && count < size) //널을 .으로 출력
		write(1, ".", 1);
	write(1, "\n", 1); //개행
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	count; //줄수
	char			arr[16]; //주소값 담을거
	char			*str; //문자열 담을 공간

	i = -1;
	if (size % 16 == 0) //줄수 세기
		count = size / 16;
	else
		count = size / 16 + 1; //줄수세기 글자의 개수가  16으로 안떨어지면 + 1
	str = (char *)addr; // 캐릭터로 바꿔 담은것
	if (size == 0) // 예외처리
		return (addr);
	while (++i < count) //줄수만큼 돈다.
	{
		ft_set_addr((unsigned long long)str, 15, arr); //주소 담음
		ft_print_addr(arr); //주소 출력
		ft_char_hex(str, size); //2글자씩16진수로  바꿔 출력
		ft_print_str(str, size); //마지막 그냥출력
		size -= 16; //줄수 마이너스
		str += 16; // 배열 초기화
	}
	return (addr);
}

#include <stdio.h>
int main()
{
	void	*addr;
	char	s12[98] = "Oui, Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
	printf("\n=============== test 12 ===============\n");
	printf("Text is too long : Check your pdf\n");
	addr = ft_print_memory((void *)s12, 92);
}
