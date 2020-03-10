# printf 형식 문자(format string)

printf 형식 문자는 C 언어의 여러 입출력 라이브러리의 함수들과 다른 많은 프로그래밍 언어에서 사용하는 조작용 파라미터(control parameter)입니다. 이 문자는 간단한 템플릿 언어로 작성합니다: 문자들은 보통 함수의 출력에 문자 그대로 출력되지만, %문자와 함께 시작하는 형식 지정자들은 문자들에 (숫자와 같은) 데이터 조각으로 바꾸기(translate) 위한 위치와 변환 방법을 알려줍니다.

"printf"는 C 언어의 주요 출력 함수의 이름 중 하나이며, "형식을 지정한 출력(print formatted)"를 의미합니다. printf 형식 문자는 형식을 지정한 입력을 제공하는 scanf 형식 문자와 상호 보완적입니다. 두 경우(printf와 scnaf)에 있어, 이 형식 문자는 복잡하고 유연한 템플릿 엔진 또는 파서(parser)보다는 간단한 기능과 제한적인(고정된, fixed) 형식만을 제공하지만, 충분히 사용할만 합니다.

C 언어 이외의 많은 언어는 해당 언어의 I/O 함수들 중에 하나로 printf 형식 문자 문법과 비슷하거나, 정확하게 일치하는 함수를 갖고 있습니다(copy).

형식 지정자와 데이터의 형식간의 불일치는 오류나 취약점의 원인이 될 수 있습니다. 대부분의 형식 문자는 함수 호출시 정적 분석이 가능한 문자열 리터럴(string reteral)입니다. 하지만, 변수의 값일 수도 있으므로 동적 형식 지정도 가능하지만, 이는 제어 불가능한 형식 문자열 악용(uncontrolled format string exploit)으로 알려진 보안 취약점이 될 수 있습니다.

## 역사(History)

포트란(Fortran)과 같은 초기 프로그래밍 언어는 다른 계산(calculations)과는 완전히 다른 특수한 문법을 이용해 형식을 지정했습니다:

````fortran
   WRITE OUTPUT TAPE 6, 601, IA, IB, IC, AREA
 601  FORMAT (4H A= ,I5,5H  B= ,I5,5H  C= ,I5,
     &        8H  AREA= ,F10.2, 13H SQUARE UNITS)
````

알골 68(ALGOL 68)은 좀더 API스러운 함수를 가지고 있었으나, 여전히 특별한 문법을 사용했습니다(`$` 구분자로 둘러싼 특별한 형식 지정 문법):

````algol68
printf(($"Color "g", number1 "6d,", number2 "4zd,", hex "16r2d,", float "-d.2d,", unsigned value"-3d"."l$,
         "red", 123456, 89, BIN 255, 3.14, 250));
````

그러나 일반적인 함수 호출과 자료형(data types)의 사용은 언어와 컴파일러를 더욱 간편하게 해주며, 동일한 언어로 입출력을 구현할 수 있게 해줍니다. 이 장점은 (타입 안정성이 전혀 보장되지 않는 경우와 같은) 단점을 능가하며, 대부분의 최신 언어에서 I/O는 문법의 일부가 아닙니다.

C's printf has its origins in BCPL's writef function (1966). In comparison to printf, *N is a newline and the order of field width and type are swapped in writef:

C 언어의 `printf`는 BCPL의 `writef` 함수에서 유래했습니다(1986). `printf`와 비교해서 보자면, `*N`은 개행이며, 필드의 길이와 자료형의 순서는 `writef`와 반대입니다.

````c
WRITEF("%I2-QUEENS PROBLEM HAS %I5 SOLUTIONS*N", NUMQUEENS, COUNT)
````

아마 C 언어 외부의 문법에서 `printf`의 첫번째 복제본은 유닉스의 버전 4에서 C 언어를 포팅하는 과정에서 처음 등장한 `printf` 쉘 명령일 것입니다.

## 형식 자리지정자 지정(Format placeholder specification)

형식 지정은 형식 문자열 내의 자리지정자(placeholder)를 이용합니다. 예를 들어, 사람의 나이를 출력하려하는 프로그램이 있다면, "Your age is "라는 문구를 앞에 출력할 수 있습니다. 이 문구 다음에 즉시 나이를 출력하는 정수를 보여주기 위해, 우리는 형식 문자열을 사용할 수 있습니다:

````c
printf("Your age is %d", age);
````

### Syntax

아래는 형식 자리지정자를 위한 문법입니다:

````c
%[parameter][flags][width][.precision][length]type
````

### 파라미터 필드(Parameter field)

This is a POSIX extension and not in C99. The Parameter field can be omitted or can be:
이는 [포직스(POSIX)](https://ko.wikipedia.org/wiki/POSIX) 익스텐션이며, C99에 포함되지 않습니다. 파라미터 필드는 생락하거나 아래처럼 작성할 수 있습니다:

|Character|Description                                                         |
|---------|--------------------------------------------------------------------|
|---------|--------------------------------------------------------------------|
|n$|`n`은 형식 지정자에서 사용하는 출력을 위한 파라미터 순서에 따른 숫자이며, 다양한 형식 지정자를 사용하거나 다른 순서로 제공된 파라미터를 여러 번 출력할 수 있습니다. 하나의 자리지정자가 파라미터를 지정하면, 모든 나머지 자리지정자도 파라미터를 지정해야합니다.<br>예를 들어,  `printf("%2$d %2$#x; %1$d %1$#x",16,17)` 는 다음을 출력합니다: `17 0x11; 16 0x10`.<br>이 기능은 주로 언어 종속 규칙에 따라 파라미터의 생성 순서가 다른 지역화(localization)에서 사용합니다(his feature mainly sees its use in localization, where the order of occurrence of parameters vary due to the language-dependent convention).|

### Flags field

The Flags field can be zero or more (in any order) of:

|Character|Description                                                         |
|---------|--------------------------------------------------------------------|
|-(minus)|Left-align the output of this placeholder. (The default is to right-align the output.)
|+(plus)|Prepends a plus for positive signed-numeric types. positive = +, negative = -.<br>(The default doesn't prepend anything in front of positive numbers.)
|' '(space)|Prepends a space for positive signed-numeric types. positive =  , negative = -. This flag is ignored if the + flag exists.<br>(The default doesn't prepend anything in front of positive numbers.)
|0(zero)|When the 'width' option is specified, prepends zeros for numeric types. (The default prepends spaces.)<br>For example, printf("%4X",3) produces     3, while printf("%04X",3) produces 0003.
|'(apostrophe)|The integer or exponent of a decimal has the thousands grouping separator applied.
|#(hash)|Alternate form:<br>For g and G types, trailing zeros are not removed.<br>For f, F, e, E, g, G types, the output always contains a decimal point.<br>For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers.

### Width field

The Width field specifies a minimum number of characters to output, and is typically used to pad fixed-width fields in tabulated output, where the fields would otherwise be smaller, although it does not cause truncation of oversized fields.

The width field may be omitted, or a numeric integer value, or a dynamic value when passed as another argument when indicated by an asterisk *.[citation needed] For example, printf("%*d", 5, 10) will result in    10 being printed, with a total width of 5 characters.

Though not part of the width field, a leading zero is interpreted as the zero-padding flag mentioned above, and a negative value is treated as the positive value in conjunction with the left-alignment - flag also mentioned above.

### Precision field

The Precision field usually specifies a maximum limit on the output, depending on the particular formatting type. For floating point numeric types, it specifies the number of digits to the right of the decimal point that the output should be rounded. For the string type, it limits the number of characters that should be output, after which the string is truncated.

The precision field may be omitted, or a numeric integer value, or a dynamic value when passed as another argument when indicated by an asterisk *. For example, printf("%.*s", 3, "abcdef") will result in abc being printed.

### Length field

The Length field can be omitted or be any of:

|Character|Description                                                         |
|---------|--------------------------------------------------------------------|
|hh|For integer types, causes printf to expect an int-sized integer argument which was promoted from a char.|
|h|For integer types, causes printf to expect an int-sized integer argument which was promoted from a short.|
|l|For integer types, causes printf to expect a long-sized integer argument.<br>For floating point types, this has no effect.[3]|
|ll|For integer types, causes printf to expect a long long-sized integer argument.|
|L|For floating point types, causes printf to expect a long double argument.|
|z|For integer types, causes printf to expect a size_t-sized integer argument.|
|j|For integer types, causes printf to expect a intmax_t-sized integer argument.|
|t|For integer types, causes printf to expect a ptrdiff_t-sized integer argument.|

Additionally, several platform-specific length options came to exist prior to widespread use of the ISO C99 extensions:

|Character|Description                                                         |
|---------|--------------------------------------------------------------------|
|I|For signed integer types, causes printf to expect ptrdiff_t-sized integer argument; for unsigned integer types, causes printf to expect size_t-sized integer argument. Commonly found in Win32/Win64 platforms.|
|I32|For integer types, causes printf to expect a 32-bit (double word) integer argument. Commonly found in Win32/Win64 platforms.|
|I64|For integer types, causes printf to expect a 64-bit (quad word) integer argument. Commonly found in Win32/Win64 platforms.|
|q|For integer types, causes printf to expect a 64-bit (quad word) integer argument. Commonly found in BSD platforms.|

ISO C99 includes the inttypes.h header file that includes a number of macros for use in platform-independent printf coding. These must be outside double-quotes, e.g. printf("%" PRId64 "\n", t);

Example macros include:

|Macro    |Description                                                         |
|---------|--------------------------------------------------------------------|
|PRId32   |Typically equivalent to I32d (Win32/Win64) or d|
|PRId64   |Typically equivalent to I64d (Win32/Win64), lld (32-bit platforms) or ld (64-bit platforms)|
|PRIi32   |Typically equivalent to I32i (Win32/Win64) or i|
|PRIi64   |Typically equivalent to I64i (Win32/Win64), lli (32-bit platforms) or li (64-bit platforms)|
|PRIu32   |Typically equivalent to I32u (Win32/Win64) or u|
|PRIu64   |Typically equivalent to I64u (Win32/Win64), llu (32-bit platforms) or lu (64-bit platforms)|
|PRIx32   |Typically equivalent to I32x (Win32/Win64) or x|
|PRIx64   |Typically equivalent to I64x (Win32/Win64), llx (32-bit platforms) or lx (64-bit platforms)|

### Type field

The Type field can be any of:

|Character|Description                                                         |
|---------|--------------------------------------------------------------------|
|%        |Prints a literal % character (this type doesn't accept any flags, width, precision, length fields).|
|d, i     |int as a signed integer. %d and %i are synonymous for output, but are different when used with scanf() for input (where using %i will interpret a number as hexadecimal if it's preceded by 0x, and octal if it's preceded by 0.)|
|u        |Print decimal unsigned int.|
|f, F     |double in normal (fixed-point) notation. f and F only differs in how the strings for an infinite number or NaN are printed (inf, infinity and nan for f; INF, INFINITY and NAN for F).|
|e, E     |double value in standard form ([-]d.ddd e[+/-]ddd). An E conversion uses the letter E (rather than e) to introduce the exponent. The exponent always contains at least two digits; if the value is zero, the exponent is 00. In Windows, the exponent contains three digits by default, e.g. 1.5e002, but this can be altered by Microsoft-specific _set_output_format function.|
|g, G     |double in either normal or exponential notation, whichever is more appropriate for its magnitude. g uses lower-case letters, G uses upper-case letters. This type differs slightly from fixed-point notation in that insignificant zeroes to the right of the decimal point are not included. Also, the decimal point is not included on whole numbers.|
|x, X     |unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case.|
|o        |unsigned int in octal.|
|s        |null-terminated string.|
|c        |char (character).|
|p        |void * (pointer to void) in an implementation-defined format.|
|a, A     |double in hexadecimal notation, starting with 0x or 0X. a uses lower-case letters, A uses upper-case letters. (C++11 iostreams have a hexfloat that works the same).|
|n        |Print nothing, but writes the number of characters successfully written so far into an integer pointer parameter.<br>Java: indicates a platform neutral newline/carriage return.<br>Note: This can be utilized in Uncontrolled format string exploits.|

### Custom format placeholders

There are a few implementations of printf-like functions that allow extensions to the escape-character-based mini-language, thus allowing the programmer to have a specific formatting function for non-builtin types. One of the most well-known is the (now deprecated) glibc's register_printf_function(). However, it is rarely used due to the fact that it conflicts with static format string checking. Another is Vstr custom formatters, which allows adding multi-character format names.

Some applications (like the Apache HTTP Server) include their own printf-like function, and embed extensions into it. However these all tend to have the same problems that register_printf_function() has.

The Linux kernel printk function supports a number of ways to display kernel structures using the generic %p specification, by appending additional format characters.[7] For example, %pI4 prints an IPv4 address in dotted-decimal form. This allows static format string checking (of the %p portion) at the expense of full compatibility with normal printf.

Most non-C languages that have a printf-like function work around the lack of this feature by just using the %s format and converting the object to a string representation. C++ offers a notable exception, in that it has a printf function inherited from its C history, but also has a completely different mechanism that is preferred.

## Vulnerabilities

### Invalid conversion specifications

If the syntax of a conversion specification is invalid, behavior is undefined, and can cause program termination. If there are too few function arguments provided to supply values for all the conversion specifications in the template string, or if the arguments are not of the correct types, the results are also undefined. Excess arguments are ignored. In a number of cases, the undefined behavior has led to "Format string attack" security vulnerabilities.

Some compilers, like the GNU Compiler Collection, will statically check the format strings of printf-like functions and warn about problems (when using the flags -Wall or -Wformat). GCC will also warn about user-defined printf-style functions if the non-standard "format" __attribute__ is applied to the function.

### Field width versus explicit delimiters in tabular output

Using only field widths to provide for tabulation, as with a format like %8d%8d%8d for three integers in three 8-character columns, will not guarantee that field separation will be retained if large numbers occur in the data. Loss of field separation can easily lead to corrupt output. In systems which encourage the use of programs as building blocks in scripts, such corrupt data can often be forwarded into and corrupt further processing, regardless of whether the original programmer expected the output would only be read by human eyes. Such problems can be eliminated by including explicit delimiters, even spaces, in all tabular output formats. Simply changing the dangerous example from before to %7d %7d %7d addresses this, formatting identically until numbers become larger, but then explicitly preventing them from becoming merged on output due to the explicitly included spaces. Similar strategies apply to string data.

## Programming languages with printf

Languages that use format strings that deviate from the style in this article (such as AMPL and Elixir), languages that inherit their implementation from the JVM or other environment (such as Clojure and Scala), and languages that do not have a standard native printf implementation but have external libraries which emulate printf behavior (such as JavaScript) are not included in this list.

- awk (via sprintf)
- C
  - C++ (also provides overloaded shift operators and manipulators as an alternative for formatted output – see iostream and iomanip)
  - Objective-C
- D
- F#
- G (LabVIEW)
- GNU MathProg
- GNU Octave
- Go
- Haskell
- J
- Java (since version 1.5) and JVM languages
- Lua (string.format)
- Maple
- MATLAB
- Max (via the sprintf object)
- Mythryl
- PARI/GP
- Perl
- PHP
- Python ( via % operator)
- R
- Raku (via printf, sprintf, and fmt)
- Red/System
- Ruby
- Tcl (via format command)
- Transact-SQL (via xp_sprintf)
- Vala (via print() and FileStream.printf())
- The printf utility command, sometimes built in the shell like some implementations of the Korn shell (ksh), Bourne again shell (bash), or Z shell (zsh). These commands usually interpret C escapes in the format string.
