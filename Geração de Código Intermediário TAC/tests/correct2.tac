// tac table of tests/correct2.c
.table
int a_2
int b_2
float c_2
float a_3
char str_1[] = "======================================================="
int str_1_size = 55
char str_2[] = "======================================================="
int str_2_size = 55
char str_3[] = "======================================================="
int str_3_size = 55
char str_4[] = "=====                  0 + 1 = ?                  ====="
int str_4_size = 55
char str_5[] = "======================================================="
int str_5_size = 55
char str_6[] = "======================================================="
int str_6_size = 55
char str_7[] = "======================================================="
int str_7_size = 55
float answer_3
char str_8[] = "R: "
int str_8_size = 3
char str_9[] = "resposta errada!"
int str_9_size = 16
char str_10[] = "resposta ainda errada, mas quase la!"
int str_10_size = 36
char str_11[] = "resposta correta!"
int str_11_size = 17
char str_12[] = "resposta negativa!"
int str_12_size = 18
char str_13[] = "it's easy as "
int str_13_size = 13
char str_14[] = " "
int str_14_size = 1
int b_3
float c_3
char str_15[] = " "
int str_15_size = 1

// tac code of tests/correct2.c
.code
_writeString:
mov $1023, 0

_writeChar:
mov $1022, #1
mov $1022, $1022[$1023]
print $1022
sub $1022, $1023, #0
add $1023, $1023, 1
brnz _writeChar, $1022
return

_writeStringln:
call _writeString, 2
println
return


_without_return_0:
return 0

_float_five_or_one_0:
mul $0, a_2, b_2
inttofl $1020, $0
mul $1, $1020, c_2

return $1

_main_0:
mov a_3, 1.0
param str_1_size
mov $1021, &str_1
param $1021
call _writeStringln, 2
param str_2_size
mov $1021, &str_2
param $1021
call _writeStringln, 2
param str_3_size
mov $1021, &str_3
param $1021
call _writeStringln, 2
param str_4_size
mov $1021, &str_4
param $1021
call _writeStringln, 2
param str_5_size
mov $1021, &str_5
param $1021
call _writeStringln, 2
param str_6_size
mov $1021, &str_6
param $1021
call _writeStringln, 2
param str_7_size
mov $1021, &str_7
param $1021
call _writeStringln, 2
minus $2, 1
inttofl $2, $2
mov answer_3, $2
L0:
seq $3, answer_3, a_3
not $3, $3
jump L1
L3:
jump L0
L2:
param str_8_size
mov $1021, &str_8
param $1021
call _writeString, 2
scanf answer_3
sleq $4, answer_3, a_3
not $4, $4
brz L4, $4
param str_9_size
mov $1021, &str_9
param $1021
call _writeStringln, 2
jump L5
L4:
inttofl $1020, 0
seq $5, answer_3, $1020
fltoint $5, $5
brz L6, $5
param str_10_size
mov $1021, &str_10
param $1021
call _writeStringln, 2
jump L7
L6:
seq $6, answer_3, a_3
brz L8, $6
param str_11_size
mov $1021, &str_11
param $1021
call _writeStringln, 2
jump L9
L8:
param str_12_size
mov $1021, &str_12
param $1021
call _writeStringln, 2
L9:
L7:
L5:
jump L3
L1:
brnz L2, $3
param str_13_size
mov $1021, &str_13
param $1021
call _writeString, 2
call _without_return_0, 0
pop $7
print $7
call _without_return_0, 0
pop $8
not $9, $8
print $9
param str_14_size
mov $1021, &str_14
param $1021
call _writeString, 2
inttofl $1020, 5
mov c_3, $1020
fltoint $1019, a_3
mov a_2, $1019
fltoint $1019, a_3
mov b_2, $1019
mov $1019, c_3
mov c_2, $1019

call _float_five_or_one_0, 0
pop $10
inttofl $1020, 2
mul $11, $1020, $10
fltoint $11, $11
mov b_3, $11
print b_3
param str_15_size
mov $1021, &str_15
param $1021
call _writeString, 2
add $12, b_3, 1
println $12
inttofl $1020, b_3
mul $13, a_3, $1020
fltoint $1019, a_3
mov a_2, $1019
fltoint $1019, a_3
mov b_2, $1019
mov $1019, a_3
mov c_2, $1019

call _float_five_or_one_0, 0
pop $14
div $15, $13, $14
return $15

main:
call _main_0, 0
