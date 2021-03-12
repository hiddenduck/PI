#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

//1
/*a)
Inicio:
x[15] = {1, 2, 3, 4 ,5 ,6 ,7, 8, 9, 10, 11, 12, 13, 14, 15};
y = 1;
z=4;
Desenvolvimento:
Basicamente, temos um for que incia com um i de 0 a 5, ou seja, dá 5 loops
a cada loop o y é incrementado por 1 int e o z é incrementado por 2 ints, esta incrementação
vai mudar o endereço do pointer para o endereço seguinte de x.
Output: 1 1 4
        2 2 6
        3 3 8
        4 4 10
        5 5 12
*/
