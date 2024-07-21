# Máquina de Turing en C

## Descripción

Este proyecto implementa una máquina de Turing en C que procesa cadenas de conjuntos de caracteres `|` delimitadas por el caracter `*`. La máquina de Turing simula el procesamiento de cadenas para realizar una simple suma y valida si siguen una estructura específica. La Máquina de Turing es una máquina teórica que manipula símbolos en una cinta de acuerdo con una serie de reglas predefinidas. El proyecto incluye una funcionalidad para generar cadenas aleatorias con una longitud especificada y para leer y procesar cadenas ingresadas por el usuario.

## Funcionalidades

- **Generación de Cadenas Aleatorias**: Crea una cadena de caracteres delimitada por `*` y `|` con longitudes especificadas.
- **Procesamiento de Cadenas**: Simula el comportamiento de una máquina de Turing para procesar y validar cadenas de caracteres.
- **Registro de Ejecución**: Registra el estado y las transiciones de la máquina de Turing en un archivo de texto llamado `Maquina_de_Turing.txt`.
- **Interfaz de Usuario**: Proporciona un menú simple para elegir entre ingresar una cadena manualmente o generar una cadena aleatoria.

## Estructura del Código

- `aleatorio_en_rango(int minimo, int maximo)`: Función para generar un número aleatorio en un rango especificado.
- `cadena_aleatoria(int longitud1, int longitud2, char destino[])`: Función para generar una cadena aleatoria con la estructura `*|...|*|...|*`.
- `menu()`: Función para mostrar el menú y obtener la elección del usuario.
- `imprimir(char *cad, char c, int est, int i)`: Función para imprimir el estado actual de la máquina de Turing y registrar el proceso en un archivo.
- `TuringM(char cad[])`: Función que simula el comportamiento de la máquina de Turing.
- `main()`: Función principal que maneja la interfaz de usuario y llama a las funciones correspondientes.

## Instrucciones de Uso

1. **Compilar el Código**: Utiliza un compilador de C para compilar el archivo fuente. Por ejemplo, si estás usando `gcc`, puedes compilar el código con el siguiente comando:
    ```bash
    gcc -o maquina_de_turing maquina_de_turing.c
    ```

2. **Ejecutar el Programa**: Una vez compilado, ejecuta el programa con el siguiente comando:
    ```bash
    ./maquina_de_turing
    ```

3. **Interacción con el Programa**:
    - **Ingresar Cadena**: Selecciona la opción 1 en el menú e ingresa una cadena de caracteres para procesar.
    - **Generar Cadena**: Selecciona la opción 2 en el menú para generar una cadena aleatoria con longitudes especificadas.
    - **Salir**: Selecciona la opción 3 para salir del programa.

4. **Ver Resultados**: Los resultados del procesamiento de la máquina de Turing se registran en el archivo `Maquina_de_Turing.txt`. Revisa este archivo para ver el estado de la máquina y el procesamiento de la cadena.

## Ejemplo de Uso

Aquí tienes un ejemplo de cómo usar el programa:

1. **Ejecutar el Programa**:
    ```bash
    ./maquina_de_turing
    ```

2. **Seleccionar una Opción del Menú**:
    - Para ingresar una cadena manualmente, elige la opción 1 y proporciona una cadena.
    - Para generar una cadena aleatoria, elige la opción 2 y proporciona las longitudes deseadas.

3. **Verificar el Registro**:
    - Abre el archivo `Maquina_de_Turing.txt` para ver los registros del procesamiento.
  
## Ejemplos de Cadenas de Entrada

La máquina de Turing acepta cadenas que cumplen con la siguiente estructura: `*|...|*|...|*`, donde cada conjunto de `|` está delimitado por `*`, con un total de tres asteriscos en la cadena. A continuación, se muestran algunos ejemplos de cadenas válidas:

- `*|*|*`
- `*|||*||*`
- `*||*||||*`
- `*||||*||||*`

Estos ejemplos siguen la estructura correcta y serán aceptados por la máquina de Turing.

## Estados y Transiciones de la Máquina de Turing

La máquina de Turing implementada en este proyecto tiene 9 estados. A continuación se describe el comportamiento de la máquina para cada estado:

1. **Estado 1**:
    - **Transición**: Si encuentra un `*`, lo reemplaza por `X`, avanza a la derecha y cambia al estado 2.
    - **Transición**: Si no encuentra un `*`, la máquina cambia al estado 0 (rechaza la cadena).

2. **Estado 2**:
    - **Transición**: Si encuentra un `*`, lo mantiene como `*`, avanza a la derecha y cambia al estado 3.
    - **Transición**: Si encuentra un `|`, lo mantiene como `|`, avanza a la derecha y permanece en el estado 2.
    - **Transición**: Si no encuentra `*` ni `|`, la máquina cambia al estado 0 (rechaza la cadena).

3. **Estado 3**:
    - **Transición**: Si encuentra un `*`, lo reemplaza por `X`, retrocede a la izquierda y cambia al estado 4.
    - **Transición**: Si encuentra un `|`, lo mantiene como `|`, avanza a la derecha y permanece en el estado 3.
    - **Transición**: Si no encuentra `*` ni `|`, la máquina cambia al estado 0 (rechaza la cadena).

4. **Estado 4**:
    - **Transición**: Si encuentra un `*`, lo mantiene como `*`, retrocede a la izquierda y permanece en el estado 4.
    - **Transición**: Si encuentra un `|`, lo reemplaza por `a`, avanza a la derecha y cambia al estado 5.
    - **Transición**: Si encuentra un `X`, lo mantiene como `X`, avanza a la derecha y cambia al estado 7.
    - **Transición**: Si no encuentra `*`, `|` ni `X`, la máquina cambia al estado 0 (rechaza la cadena).

5. **Estado 5**:
    - **Transición**: Si encuentra un `*`, lo mantiene como `*`, avanza a la derecha y permanece en el estado 5.
    - **Transición**: Si encuentra un `|`, lo mantiene como `|`, avanza a la derecha y permanece en el estado 5.
    - **Transición**: Si encuentra un `X`, lo mantiene como `X`, avanza a la derecha y permanece en el estado 5.
    - **Transición**: Si encuentra el final de la cadena (`\0`), reemplaza el carácter con `|`, avanza a la izquierda y cambia al estado 6.

6. **Estado 6**:
    - **Transición**: Si encuentra un `*`, lo mantiene como `*`, retrocede a la izquierda y permanece en el estado 6.
    - **Transición**: Si encuentra un `|`, lo mantiene como `|`, retrocede a la izquierda y permanece en el estado 6.
    - **Transición**: Si encuentra un `X`, lo mantiene como `X`, retrocede a la izquierda y permanece en el estado 6.
    - **Transición**: Si encuentra un `a`, lo reemplaza por `|`, retrocede a la izquierda y cambia al estado 4.

7. **Estado 7**:
    - **Transición**: Si encuentra un `*`, lo mantiene como `*`, avanza a la derecha y cambia al estado 8.
    - **Transición**: Si encuentra un `|`, lo mantiene como `|`, avanza a la derecha y permanece en el estado 7.
    - **Transición**: Si no encuentra `*` ni `|`, la máquina cambia al estado 0 (rechaza la cadena).

8. **Estado 8**:
    - **Transición**: Si encuentra un `X`, lo reemplaza por `*`, avanza a la derecha y permanece en el estado 8.
    - **Transición**: Si encuentra un `|`, lo mantiene como `|`, avanza a la derecha y permanece en el estado 8.
    - **Transición**: Si encuentra el final de la cadena (`\0`), reemplaza el carácter con `*`, avanza a la izquierda y cambia al estado 9.

9. **Estado 9**:
    - **Transición**: Si encuentra un `*`, lo mantiene como `*`, retrocede a la izquierda y permanece en el estado 9.
    - **Transición**: Si encuentra un `|`, lo mantiene como `|`, retrocede a la izquierda y permanece en el estado 9.
    - **Transición**: Si encuentra un `X`, lo reemplaza por `*`, acepta la cadena y permanece en el estado 9.

Si la cadena no es aceptada, el estado cambia al 0 y la máquina rechaza la cadena.

## Archivos del Proyecto

- `maquina_de_turing.c`: Código fuente principal de la máquina de Turing.
- `Maquina_de_Turing.txt`: Archivo de registro que almacena el estado y las transiciones de la máquina de Turing.

## Contribuciones

Si deseas contribuir al proyecto, por favor sigue estos pasos:

1. Realiza un fork del repositorio.
2. Crea una rama con tus cambios (`git checkout -b nombre-de-tu-rama`).
3. Realiza los cambios y haz un commit (`git commit -am 'Descripción de los cambios'`).
4. Sube tus cambios (`git push origin nombre-de-tu-rama`).
5. Crea un pull request.

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.

## Contacto

Para cualquier duda o comentario, puedes contactarme a través de [davshot78@outlook.com] o abrir un issue en el repositorio.

---

¡Gracias por visitar mi proyecto de Máquina de Turing!
