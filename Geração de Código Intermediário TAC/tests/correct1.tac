// tac table of tests/correct1.c
.table
int j_1
float i_1
int k_1
int p_1
float num_3
int n_3
int ctd_3
char str_1[] = "Insira um numero igual ou maior do que 1..."
int str_1_size = 43
char str_2[] = ", "
int str_2_size = 2
char str_3[] = "."
int str_3_size = 1
float i_9
char str_4[] = "Insira um numero: "
int str_4_size = 18
float j_9
char str_5[] = "O dobro eh: "
int str_5_size = 12
char str_6[] = "O oposto simetrico eh: "
int str_6_size = 23
int numeros_seguintes_9
char str_7[] = "Seus "
int str_7_size = 5
char str_8[] = " numeros seguintes sao: "
int str_8_size = 24
char str_9[] = "Ate mais!"
int str_9_size = 9

// tac code of tests/correct1.c
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


_twice_0:
inttofl $1020, 0
mov i_1, $1020
fltoint $1020, 1.0
mov j_1, $1020
or $0, 0, j_1
mov p_1, $0
minus $1, 2
minus $2, p_1
mul $3, $1, $2
mov k_1, $3
inttofl $1020, 0
seq $4, i_1, $1020
fltoint $4, $4
not $5, $4
add $6, $5, k_1
return $6

_zero_0:
or $7, 0, 0
and $8, 0, 1
or $9, $7, $8
and $10, 1, 0
and $11, 1, 1
and $12, $10, $11
or $13, $9, $12
return $13

_printN_0:
slt $14, n_3, 1
brz L0, $14
param str_1_size
mov $1021, &str_1
param $1021
call _writeStringln, 2
minus $15, 1
return $15
jump L1
L0:
mov ctd_3, 1
L2:
sleq $16, ctd_3, n_3
jump L3
L5:
add $17, ctd_3, 1
mov ctd_3, $17
jump L2
L4:
inttofl $1020, ctd_3
add $18, num_3, $1020
print $18
seq $19, ctd_3, n_3
not $19, $19
brz L6, $19
param str_2_size
mov $1021, &str_2
param $1021
call _writeString, 2
jump L7
L6:
param str_3_size
mov $1021, &str_3
param $1021
call _writeStringln, 2
L7:
jump L5
L3:
brnz L4, $16
L1:
return 0

_main_0:
param str_4_size
mov $1021, &str_4
param $1021
call _writeString, 2
scanf i_9
fltoint $1019, j_9
mov j_1, $1019

call _twice_0, 0
pop $20
inttofl $20, $20
mov j_9, $20
param str_5_size
mov $1021, &str_5
param $1021
call _writeString, 2
mul $21, i_9, j_9
println $21
param str_6_size
mov $1021, &str_6
param $1021
call _writeString, 2
call _zero_0, 0
pop $22
inttofl $1020, $22
sub $23, $1020, i_9

println $23
mov numeros_seguintes_9, 20
param str_7_size
mov $1021, &str_7
param $1021
call _writeString, 2
print numeros_seguintes_9
param str_8_size
mov $1021, &str_8
param $1021
call _writeString, 2
mov $1019, i_9
mov num_3, $1019
mov $1019, numeros_seguintes_9
mov n_3, $1019

call _printN_0, 0
pop $24
param str_9_size
mov $1021, &str_9
param $1021
call _writeStringln, 2
return 123456789

main:
call _main_0, 0
