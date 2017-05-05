% Newton-Raphson
% Hermes Espínola
% 11 Febrero 2017

Newton-Raphson es un método abierto, sólo requiere un valor de inicio x, que emplea una fórmula para predecir la raíz. El problema con esta clase de métodos es que a veces divergen o se alejan de la raíz verdadera a medida que se avanza en el cálculo. Entoces, ¿por qué utilizarlos? Pues porque cuando sí convergen, en general, lo hacen mucho más rápido que los métodos cerrados.

De las fórmulas para localizar raíces, la de Newton-Raphson puede que sea la más ampliamente utilizada. Si el valor inicial para la raíz es x_i, entonces se puede trazar una tangente desde el punto [x_i, f(x_i)] de la curva; comunmente el punto donde dicha tangente cruza el eje x representa una aproximación mejorada de la raíz. EL método se deduce a partir de la interpretación geométrica basada en la serie de Taylor.

**$$f'(x_i) = f(x_i)-1/(x_i-x_{i+1}) \rightarrow x_i+1 = x_i – f(x_i)/f'(x_i)$$**

## Diagrama de flujo

<!-- ![diagrama de Newton-Raphson](/../screenshots/newton-raphson-diagrama.png) -->

```cpp
#include <iostream>
#include <cmath>

#define MINERR 1E-6

using namespace std;

typedef double (* vFunctionCall)(double x);

double newtonRaphson(vFunctionCall fun, vFunctionCall der, double x) {
  int i = 0;
  double x1, y, dy, err;

  do {
    x1 = x;               // make x equal to the last calculated value.
    y = fun(x1);         //  evaluate the function.
    dy = der(x1);       //   evaluate the derivative of the function.
    x = x1 - (y / dy); //    calculate the next guess from x, y and dy.
    err = abs(x-x1);
    i++;
  } while(err >= MINERR);

  cout << "error iterativo: " << err << endl;
  cout << "# iteraciones: " << i << endl;
  return x1;
}
```

¿Cuál es el criterio de terminación que se utiliza? Con base en la serie de Taylor, tenemos que la velocidad de la convergencia está expresada por *E_{i+1} = O(E_{i^2})*; de esta manera el error debe de ser proporcional al cuadrado del error anterior, **es decir**, el número de cifras significativas de precisión aproximadamente se duplica en cada iteración.

En general, el método de Newton’Raphson es muy eficiente, pero hay situaciones en donde se comporta de manera deficiente. Por ejemplo, en el caso de raíces múltiples e inclusive en raíces simples se nos pueden llegar a presentar algunas dificultades, como por ejemplo convergencia lenta o casos en el que un punto de inflexión* se encuentra en la vecindad de una raíz.

> UN PUNTO DE INFLEXIÓN, EN UNA FUNCIÓN MATEMÁTICA, ES UN PUNTODONDE LOS VALORES DE UNA FUNCIÓN CONTINUA X PASAN DE UN TIPO DE CONCAVIDAD A OTRA. LA CURVA “ATRAVIESA” LA TANGENTE. MATEMÁTICAMENTE LA DERIVADA SEGUNDA DE LA FUNCIÓN F EN EL PUNTO DE INFLEXIÓN ES CERO, O NO EXISTE.

No hay ningún criterio general de convergencia para el método, esta depende de la naturaleza de la función y de la exactitud del valor inicial, hay que tener un valor inicial lo suficientemente cercano a la raíz, sin embargo, para algunas funciones ninguno funcionará. Hay que tener conocimiento del problema mediante otros recursos alternativos (gráficas por ejemplo) para hacer una buena predicción y entender ampliamente el comportamiento de la función.

---

## Pruebas

- Casos de exito:

| f(x) | f'(x) | x_0 | iteraciones | Resultado |  Error |
| :------------- |:------ | :---- | :------------- | :----- | :--- |
| x ^ 2 - 4 | 2x | 1 | 5 | 2 | 9.29223e-08 |
| x ^ 2 - 4 | 2x | -100 | 10 | -2 | 5.08772e-09 |
| x ^ 3 - x - 11 | 3x^2 - 1 | 1 | 8 | 2.37365  | 6.88196e-09 |
| atan(x) | 1/(x^2 + 1) | 1.39174 | 17 | 5.05277e-13 | 5.05277e-13 |

- Casos frontera:

| f(x) | f'(x) | x_0 | iteraciones | Resultado |  Error |
| :------------- |:------ | :---- | :------------- | :----- | :--- |
| cos(3x) - x | 3sin(3x) - 1 | -4 | -0.887726 | 553 | 2.54268e-07 |

- Casos de falla:

| f(x) | f'(x) | x_0 | iteraciones | Resultado |  Error |
| :------------- |:------ | :---- | :------------- | :----- | :--- |
| x ^ 3 - x - 11 | 3x^2 - 1 | 0 (punto de inflexión) | infinito | Se cicla | Se cicla |
| atan(x) | 1(x^2 + 1) | 1.39175 | 23 | infinito | nan |
| $\sqrt[3]{x}$ | $1/(3x^(2/3)$ | 0.001 | infinito | Diverge | Diverge |
