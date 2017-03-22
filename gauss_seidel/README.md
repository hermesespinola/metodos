# Gauss Seidel y Jacobi

## Introducción y antecedentes (para qué sirven y qué resuelven) los métodos
Los metodos de Jácobi y de Gauss-Seidel consisten en obtener una ecuación de
de recurrencia y proponer un vector solución inicial, después se hacen las
iteraciones necesarias hasta que la diferencia entre dos vectores de approximación
consecutivos cumplan con la tolerancia de error definida.

resuelven equaciones lineales de la forma AX = b, donde A es la matriz de coeficientes,
X es el vector de incógnitas y b el vector de terminos independientes.

## Requisitos de los métodos
Para el método de Jacobi la matriz de coeficientes debe de ser diagonalmente
dominante. Esto es, el valor absoluto del elemento de la diagonal de esa fila
es estrictamente mayor que la norma del resto de elementos de esa fila.

## Diferencias entre uno y otro método
Mientras que en el método de Jacobi se utiliza el valor de las incógnitas para
determinar una nueva aproximación, en el de Gauss-Seidel se va utilizando los
valores de las incógnitas recien calculadas en la misma iteración, y no en la
siguiente.

## Diagramas de flujo
*se lo debo*

## ¿Es un método iterativo? (¿si?, ¿no?, ¿por qué?)
Los métodos de Gauss-Seidel y de Jacobi son métodos iterativos porque cumplen con
la definición de método iterativo. En un método iterativo se tiene que:
1. Inicia con una aproximación inicial (Semilla).
2. Ejecuta una serie de cálculos para llegar a una nueva aproximación en la que
se espera tenga un error menor a la aproximación anterior. Esto se conoce como
ecuación de recurrencia.
3. Se repite el paso anterior, utilizando la aproximación obtenida en el paso
anterior como aproximación semilla.

## Código en C++


## Criterio de convergencia de los métodos
Cuando después de las suficientes iteraciones el error sea menor al error minimo
definido se considera que el método convergío exitosamente. En general, si la
matriz de coeficientes original del sistema de ecuaciones es **diagonalmente dominante**,
el método de converge.

## Relajación
En optimización matemática, la Relajación es una aproximación a un problema difícil
por medio de un problema cercano que es más facil de resolver.

## Pruebas y resultados con sistemas de 3 o 4 incógnitas


## Casos de falla y lo que tu programa hace en estos casos


## Conclusiones
