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
|n$|`n`은 형식 지정자에서 사용하는 출력을 위한 파라미터 순서에 따른 숫자이며, 다양한 형식 지정자를 사용하거나 다른 순서로 제공된 파라미터를 여러 번 출력할 수 있습니다. 하나의 자리지정자가 파라미터를 지정하면, 모든 나머지 자리지정자도 파라미터를 지정해야합니다.<br>예를 들어,  `printf("%2$d %2$#x; %1$d %1$#x",16,17)` 는 다음을 출력합니다: `17 0x11; 16 0x10`.<br>이 기능은 주로 언어 종속 규칙에 따라 파라미터의 생성 순서가 다른 지역화(localization)에서 사용합니다(his feature mainly sees its use in localization, where the order of occurrence of parameters vary due to the language-dependent convention).|

### 플래그 필드(Flags field)

플래그 필드는 0이거나 (어떤 순서로든) 아래의 문자가 될 수 있습니다:

|문자      |설명                                                                |
|---------|--------------------------------------------------------------------|
|-(minus) |이 자리지정자 출력값을 좌측 정렬(기본은 우측 정렬)|
|+(plus)  |양수에 더하기 부호를 붙여줌. 양수 = +, 음수 = -.<br>(기본값은 양수일 경우에는 그 앞에 아무 부호를 붙이지 않음)|
|' '(space)|양수의 앞에 공백을 붙여 줌. 양수 = ' ', 음수 = -. 만약 + 플래그가 있다면 이 플래그는 적용되지 않음<br>(기본값은 양수일 경우에는 그 앞에 아무 부호를 붙이지 않음)||0(zero)  |'width' 옵션이 지정됐을 때, 숫자형의 앞에 0을 붙여줌(기본 값은 공백을 앞에 추가함).<br>예를 들어, `printf("%4X",3)`은 `   3`을, `printf("%04X",3)`은 `0003`을 출력함|
|'(apostrophe)|정수 또는 소수의 지수(exponent of a decimal)는 천 단위 그룹 구분자가 적용됩니다.|
|#(hash)  |대안적인 형태:<br>`g`와 `G` 유형을 위해서, 뒤따르는 0을 제거하지 않습니다.<br>`f`, `F`, `e`, `E`, `g`, `G` 유형을 위해, 출력값은 항상 소수점을 포함합니다.<br>`o`, `x`, `X` 유형을 위해, `0`, `0x`, `0X`는 각각 0이 아닌 숫자에 붙습니다.|

### 폭 필드(Width field)

폭 필드는 출력할 문자의 최소 개수를 지정하며, 보통 표 형태의 출력에서 고정된 길이의 필드를 채울 때 사용합니다. 반면 필드가 더 작아도, 출력이 잘리지는 않습니다.

The Width field specifies a minimum number of characters to output, and is typically used to pad fixed-width fields in tabulated output, where the fields would otherwise be smaller, although it does not cause truncation of oversized fields.

폭 필드가 필요없거나, 숫자 정수값이거나, 또는 별표(*)로 표시한 후, 또다른 인자로부터 전달받은 동적 값일경우에는 생략할 수 있습니다. 예를 들어, `printf("%*d", 5, 10)`의 결과는 다섯 개의 문자인 `   10`입니다.

폭 필드의 일부가 아니더라도, 앞부분의 0은 위에서 언급한 0 패딩값(zero-padding)처럼 해석됩니다. 그리고 `-` 부호는 위에서 언급한 왼쪽 정렬 `-` 플래그로 처리되어 양수값으로 다뤄집니다(a negative value is treated as the positive value in conjunction with the left-alignment - flag also mentioned above).

### 정밀도 필드(Precision field)

정밀도 필드는 일반적으로 특정 포맷 형식에 따라 출력의 최댓값을 지정합니다. 부동 소수점 숫자 형식의 경우, 출력시 반올림하여 표시할 소수점 오른쪽의 총 자리수가 됩니다. 문자열 형식에서는 문자열을 잘라서 출력할 문자의 개수가 됩니다.

정밀도 필드가 필요없거나, 정수형 숫자값 또는 별표(*)로 표시한 후, 또다른 인자로부터 전달받은 동적값일 경우에는 생략할 수 있습니다. 예를 들어, `printf("%.*s", 3, "abcdef")`는 `abc`를 출력합니다.

### 길이 필드(Length field)

> 역주: 길이 필드는 더 학습한 후 번역하는 게 좋을 듯 하여 생략합니다.

### 서식 지정자(서식 필드, Type field)

서식 지정자는 아래처럼 작성할 수 있습니다:

|문자     |설명                                                                 |
|---------|--------------------------------------------------------------------|
|%        |`%` 문자를 출력합니다(이 유형은 어떤 플래그나, 폭 필드, 정밀도 필드, 길이 필드를 허용하지 않습니다).||
|d, i     |부호가 있는 정수값. `%d`와 `%i`는 동일한 값을 출력하지만, 입력을 위해 `scanf()`를 사용할 때는 차이가 있습니다(`%i`를 사용하면 입력값이 `0x`로 시작하면 16진수로, `0`으로 시작할 경우에는 8진수로 해석합니다).|
|u        |10진수의 부호없는 정수를 출력합니다.|
|f, F     |일반적인(normal)(고정 소수점) 더블형 표기법. `f`와 `F`의 차이는 오직 무한수와 NaN을 출력하는 방식입니다(`f`는 `inf`와 `infinity`, `nan`, `F`는 `INF`와 `INFINITY`, `NAN`).|
|e, E     |표준 형태의 더블형 값([-]d.ddd e[+/-]ddd). `E` 변환은 (`e`보다는) `E`를 사용해 지수를 표기합니다. 지수는 항상 최소 두개 이상의 숫자를 포함합니다; 값이 0이면, 지수는 `00`입니다. 윈도우 운영체제에서, 지수는 기본적으로 3개의 숫자를 포함합니다. 예: 1.5e002, 그러나 이는 `Microsoft-specific _set_output_format` 함수에 의해 변경될 수 있습니다.|
|g, G     |지수나 일반적인(normal) 표기의 더블형으로 그 크기에 적절한 형태. `g`는 소문자를, `G`는 대문자를 사용합니다. 이 형식은 소수점 아래의 중요하지 않은 0이 출력되지 않는다는 점에서 고정 소수점 표기로부터 약간 다릅니다. 또한 소수점은 정수에 포함되지 않습니다.|
|x, X     |16진수의 부호없는 정수형. `x`는 소문자를, `X`는 대문자를 사용합니다.|
|o        |8진수의 부호없는 정수형|
|s        |NULL 문자로 종료되는 문자열|
|c        |char (문자)|
|p        |구현-정의한 형식의(in an implementation-defined format) void * (빈 포인터)|
|a, A     |16진수 표기법의 더블형, 0x 또는 0X로 시작합니다. `a`는 소문자를, `A`는 대문자를 사용합니다(C++11 iostreams에는 동일한 작업을 하는 `hexfloat`이 있습니다).|
|n        |아무것도 출력하지 않지만, 정수형 포인터 파라미터에 성공적으로 작성한 문자의 수를 작성합니다.<br>Java: 플랫폼 중립적인(platform neutral) 개행/캐리지 리턴을 나타냅니다.<br>Note: 이는 조작되지 않는 형식의 문자열에 이용될 수 있습니다(This can be utilized in Uncontrolled format string exploits).|

### 커스텀 형식 자리지정자(Custom format placeholders)

이스케이프 문자 기반의 규모가 작은 언어(mini-language)에서 확장 기능을 허용하는 printf와 비슷한 함수들을 일부 구현해 둔 게 있어서, 개발자는 내장된 형식이 아닌 특정 형식을 사용할 수 있습니다. 가장 잘 알려진 것 중 하나는 (더이상 사용되지 않는) glibc의 `register_printf_function()`입니다. 그러나 이는 정적 형식 문자열 체크와 충돌하는 문제로 거의 사용되지 않습니다.또다른 하나는 다양한 문자 형식 이름을 추가할 수 있는 Vstr custom formatters입니다.

(아파치 HTTP 서버처럼) 몇몇 애플리케이션은 각각의 printf와 같은 함수를 내장하고 있고, 그 안에 확장 기능을 내장합니다. 그러나 이들은 모두 `register_printf_function()`가 갖고 있던 것과 동일한 문제가 있습니다.

리눅스 커널의 `printk`는 부가적인 형식 문자들을 추가하여 일반 `%p` 지정을 사용하는 커널 구조들을 출력할 수 있는 다양한 방법을 지원합니다. 예를 들어, `%pI4`는 점으로 구분된 십진수로 IPv4를 출력합니다. 이는 일반 `printf()`와 완전히 호환성을 희생하면서 (`%p`의 부분적인) 정적 문자열 형식 검사를 허용합니다.

`printf`와 같은 기능을 가진 대부분의 C 언어 이외의 언어는 `%s` 형식을 사용하는 기능과 객체를 문자열 표현으로 변환하는 방법으로 이 기능의 부족을 해결합니다. C++은 C로부터 유래한 `printf` 함수를 가지고 있으나, 기호에 따른 완전히 다른 메커니즘을 가지고 있다는 점에서 차이점이 있다.

## 취약점(Vulnerabilities)

###  잘못된 변환 지정(Invalid conversion specifications)

변환 규격의 문법이 유효하지 않으면 동작이 정의되지 않고(`undefined`), 프로그램 종료의 원인이 될 수 있다. 템플릿 문자열의 모든 변환 지정에 대입하기 위해 제공한 함수의 인수가 너무 적거나, 인수가 올바른 유형이 아닐 경우, `undefined`가 반환된다. 초과한 인자는 무시된다. 많은 경우에, 정의되지 않은 동작(undefined behavior)은 "형식 문자열 공격(Format string attack) 보안 취약성을 일으킬 수 있다.

GNU 컴파일러 집합(Collection)과 같은 일부 컴파일러는 printf와 유사한 기능의 포맷 문자열을 정적으로 확인하여 문제에 대해 경고한다(-Wall 또는 -Wformat 플래그 사용시). GCC는 또한 비표준 "format" `__attribute__`가 해당 기능에 적용될 경우, 사용자 정의 printf 형식의 함수에 경고를 발생할 것이다.

### 길이 필드 VS. 표 형태의 출력값에서의 명시적 구분자(Field width versus explicit delimiters in tabular output)

여덟 글자 크기의 3개의 열에, 3개의 정수에 `%8d%8d%8d`와 같은 형식으로 표 형태로 제공하기 위해 필드 길이만 사용하는 건 데이터에 큰 숫자가 있을 경우, 필드 너비가 유지된다는 것을 보장하지 않습니다. 필드 구분이 깨지면 출력 오류를 발생시키기 쉽습니다. 스크립트 내에서 블록을 생성하여 프로그램을 사용하길 권장하는 시스템에서는, 그러한 손상된 데이터는 그 이후의 과정에 손상을 전파할 수 있으며 이는 개발자가 오직 사람의 눈으로 읽을 수 있도록 출력하기를 기대했는지 여부와는 무관하다(In systems which encourage the use of programs as building blocks in scripts, such corrupt data can often be forwarded into and corrupt further processing, regardless of whether the original programmer expected the output would only be read by human eyes). 이러한 문제는 명시적인 구분자, 공백 하나까지 모든 표 형태의 출력 형식에 포함시키면 제거할 수 있다. 간단하게 이전의 위험 요소가 있던 예제를 `%7d %7d %7d`로 변경하면, 숫자가 증가하면 동일한 형식이 적용되지만, 공백을 명시함으로써 출력때 병합으로 되는 오류를 확실히 방지할 수 있다. 이는 문자열 데이터에도 비슷하게 적용할 수 있다.

## 프로그래밍 언어에서의 printf(Programming languages with printf)

이 글에서 소개한 것과 동떨어진 형식 문자열을 사용하거나(AMPL, Elixir 등), JVM 또는 기타 환경에서 구현을 상속하는 언어(Clojure, Scala 등), 그리고 printf의 동작을 모방(emulate)하는 외부 라이브러리를 가졌으나 표준 네이티브 printf가 없는 경우(JavaScript)는 이 목록에 포함되지 않습니다.

- awk (via sprintf)
- C
  - C++ (쉬프트 연산자와 형식이 적용된 출력을 대신하기 위한 기능(manipulators)을 제공합니다. - iostream과 iomanip를 참조하세요.)
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
- Python (via % operator)
- R
- Raku (via printf, sprintf, and fmt)
- Red/System
- Ruby
- Tcl (via format command)
- Transact-SQL (via xp_sprintf)
- Vala (via print() and FileStream.printf())
- printf 유틸리티 명령은 때때로 콘쉘(Korn shell, ksh), 배시(Bourne again shell, bash), 지쉘(Z shell, zsh)의 구현처럼 쉘에 내장된 경우가 있습니다. 이 명령은 C 이스케이프 문자를 형식 문자열로 해석합니다.
