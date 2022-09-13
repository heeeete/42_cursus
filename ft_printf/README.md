Mandatory part

프로그램 이름	libftprintf.a
제출할 파일	*.c, */*.c, *.h, */*.h, Makefile
Makefile 규칙	all, clean, fclean, re, bonus
사용가능한 
외부 함수	malloc, free, write, va_start, va_arg, va_copy, va_end
직접 만든 libft	사용 가능
설명	실제 printf의 동작을 모방한 ft_printf를 포함하는 라이브러리를 작성하세요.

The prototype of ft_printf should be int ft_printf(const char *, ...);

ft_printf의 프로토타입은 int ft_printf(const char *, ...); 이어야 합니다.

You have to recode the libc’s printf function

여러분은 libc의 printf 함수를 재구현해야 합니다.

It must not do the buffer management like the real printf

실제 printf처럼 버퍼 관리를 수행해서는 안 됩니다.

It will manage the following conversions: cspdiuxX%

다음 서식 지정자를 구현하세요 : cspdiuxX%

It will be compared with the real printf

실제 printf와 비교하여 채점할 것입니다.

You must use the command ar to create your librairy, using the command libtool is forbidden.

ar 명령어를 이용하여 라이브러리를 만들어야 합니다. libtool을 사용하는 것은 금지됩니다.


A small description of the required conversion:

필요한 서식 지정자에 대한 간단한 설명입니다:

%c print a single character.

%c는 단일 문자 (character) 한 개를 출력합니다.

%s print a string of characters.

%s는 문자열 (string) 을 출력합니다.

%p The void * pointer argument is printed in hexadecimal.

%p는 void * 형식의 포인터 인자를 16진수로 출력합니다.

%d print a decimal (base 10) number.

%d는 10진수 숫자를 출력합니다.

%i print an integer in base 10.

%i는 10진수 정수를 출력합니다.

%u print an unsigned decimal (base 10) number.

%u는 부호 없는 10진수 숫자를 출력합니다.

%x print a number in hexadecimal (base 16), with lowercase.

%x는 소문자를 사용하여 숫자를 16진수로 출력합니다.

%X print a number in hexadecimal (base 16), with uppercase.

%X는 대문자를 사용하여 숫자를 16진수로 출력합니다.

%% print a percent sign.

%%는 퍼센트 기호 (%) 를 출력합니다.
