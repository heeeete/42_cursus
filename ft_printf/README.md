## Mandatory part

| **프로그램 이름**            | libftprintf.a                                                             |
| ---------------------------- | ------------------------------------------------------------------------- |
| **제출할 파일**              | \*.c, \*/\*.c, \*.h, \*/\*.h, Makefile                                    |
| **Makefile 규칙**            | all, clean, fclean, re, bonus                                             |
| **사용가능한 <br>외부 함수** | malloc, free, write, va_start, va_arg, va_copy, va_end                    |
| **직접 만든 libft**          | 사용 가능                                                                 |
| **설명**                     | 실제 printf의 동작을 모방한 ft_printf를 포함하는 라이브러리를 작성하세요. |

<br>

- ##### _The prototype of ft_printf should be `int ft_printf(const char *, ...);`_

  ft_printf의 프로토타입은 `int ft_printf(const char *, ...);` 이어야 합니다.

- ##### _You have to recode the `libc`’s `printf` function_

  여러분은 `libc`의 `printf` 함수를 재구현해야 합니다.

- ##### _It must not do the buffer management like the real printf_

  실제 `printf`처럼 버퍼 관리를 수행해서는 안 됩니다.

- ##### _It will manage the following conversions: cspdiuxX%_

  다음 서식 지정자를 구현하세요 : `cspdiuxX%`

- ##### _It will be compared with the real printf_

  실제 printf와 비교하여 채점할 것입니다.

- ##### _You must use the command `ar` to create your librairy, using the command `libtool` is forbidden._
  `ar` 명령어를 이용하여 라이브러리를 만들어야 합니다. `libtool`을 사용하는 것은 금지됩니다.

<br>

##### _A small description of the required conversion:_

필요한 서식 지정자에 대한 간단한 설명입니다:

- ##### _%c print a single character._

  %c는 단일 문자 (character) 한 개를 출력합니다.

- ##### _%s print a string of characters._

  %s는 문자열 (string) 을 출력합니다.

- ##### _%p The void \* pointer argument is printed in hexadecimal._

  %p는 void \* 형식의 포인터 인자를 16진수로 출력합니다.

- ##### _%d print a decimal (base 10) number._

  %d는 10진수 숫자를 출력합니다.

- ##### _%i print an integer in base 10._

  %i는 10진수 정수를 출력합니다.

- ##### _%u print an unsigned decimal (base 10) number._

  %u는 부호 없는 10진수 숫자를 출력합니다.

- ##### _%x print a number in hexadecimal (base 16), with lowercase._

  %x는 소문자를 사용하여 숫자를 16진수로 출력합니다.
  
- ##### _%X print a number in hexadecimal (base 16), with uppercase._

  %X는 대문자를 사용하여 숫자를 16진수로 출력합니다.

- ##### _%% print a percent sign._

  %%는 퍼센트 기호 (%) 를 출력합니다.

> 💡 <br>
>
> ##### _for more complete references : `man 3 printf / man 3 stdarg`_
>
> 더 완벽한 참고 자료는 `man 3 printf / man 3 stdarg`
