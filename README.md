# CCT
**A C/C++ Calc Tool (in CLI)**

## Usage
You can compile using the following command
```shell
g++ main.cpp -o cct.exe
```

Then use it to calc.

## Gramma
+ ### d
You can use it to convert any base between binary and thirty-sixth.
```
[ In ]  << d 10 2 4651 //Decimal to binary
[ Out ] >> 1001000101011
[ In ]  << d 16 2 40F //Hexadecimal to binary
[ Out ] >> 10000001111
[ In ]  << d 10 36 445841 //Decimal to 36 base
[ Out ] >> 9K0H
```
+ ### p
Pseudo function/assembly type parsing.

Any C/C++type is digitally stored, and you can use it to convert numbers to corresponding types.

Type Abbreviation List(Currently not supported for wchar_t)
|Type|Abbreviation|
|:-:|:-:|
|c|char|
|uc|unsigned char|
|sc|signed char|
|i|int|
|ui|unsigned int|
|sdi|signed int|
|sti|short int|
|usi|unsigned short int|
|ssi|signed short int|
|li|long int|
|sli|signed long int|
|uli|unsigned long int|
|f|float|
|d|double|
|ld|long double|

```
[ In ]  << p f i 2.5 // Convert float to int
[ Out ] >> [0:0-4B]:1075838976
[ In ]  << p i f 1075838976
[ Out ] >> [0:0-4B]:2.5 // Convert int to float
[ In ]  << p i c 1075838976 // Convert int to char
[ Out ] >> [0:0-1B]: //It could be a control character, so it's not visible
[ Out ] >> [1:1-2B]:
[ Out ] >> [2:2-3B]:
[ Out ] >> [3:3-4B]:@
```
+ ### exit
Enter exit to exit.