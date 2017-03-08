# Cramer

## Introducción
La regla de cramer nos ayuda a resolver un sistema de ecuaciones
lineales, incluso podemos resolver para una sola incognita sin tener que
resolver para todo el sistema a partir del uso de determinantes de
matrices. Recibe este nombre en honor a Gabriel Cramer (1704-1752).
Para sistemas de ecuaciones lineales de más de tres incognitas se vuelve
muy costoso debido a que, computacionalemente, es ineficiente el cálculo de
determinantes para grandes matrices. Empero, como no es necesario pivotar
matrices, es más eficiente que la eliminación gaussiana para matrices pequeñas.

siendo Ax = b un sistema de ecuaciones, A es la matriz de coeficientes, x =
(x1, ..., xn) es el vector de incógnitas y b es el vector de términos
independientes. Entonces la solución al sistema es:

xi = det(Ai) / det(A)

donde Ai es la matriz resultante de reemplazar la i-ésima columna de A por b.

## Requisitos
Para poder calcular la determinante de la matriz de coeficientes A, esta debe
de ser cuadrada. Ademas, su determinante ha de ser no nulo.

## Qué es un determinante
Una determinante es un objeto matemático que son muy útiles en el
análisis y solución de sistemas de ecuaciones lineales. Las determinantes
solo están definidas para matrices cuadradas. Suele denotarse det(A), |A| o
en notación de componentes es Σ(±a1 b2 c3 ...), D(a1 b2 c3) o |a1 b2 c3 ...|.

## Diagrama de flujo


## Control de iteraciones
Tenemos que iterar sobre las columnas de A para reemplazarlas por b, el vector
columna de terminos independientes y calcular su determinante.
No se necesitan de más loops si el código está bien vectorizado.

## Código
```octave
function [ X ] = cramer( A, b )

[n m] = size(A);

if n ~= m
  error('A must be a square matrix');
elseif n ~= size(b)(1)
  error('A and b sizes do not match');
end

X = zeros(n, 1);
S = zeros(n, 1);
delta = det(A);

for i=1:n
  temp = A;
  temp(:, i) = b;
  S(i) = det(temp);
end

X = S ./ delta;

end % cramer
```

## Pruebas con 2 y 3 incógnitas


## Conclusiones
La regla de cramer es especialmente útil si queremos resolver una sola incógnita
del sistema de ecuaciones o si la matriz de coeficientes es pequeña. Por otro
lado no es recomendado utilizar este método para matrices grandes puesto que
el calculo de las determinantes en tales matrices resulta muy costoso
computacionalemente.
