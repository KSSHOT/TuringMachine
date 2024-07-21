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

## Estados y Transiciones

La máquina de Turing implementada tiene los siguientes estados y transiciones para procesar cadenas con la estructura `*|...|*|...|*`:

1. **Estado 1**:
   - **Condición**: Si el símbolo actual es `*`.
   - **Acción**: Cambia el símbolo a `X`, mueve la cinta a la derecha y cambia al estado 2.
   - **Transición**: `*` → `X`, mover a la derecha.

2. **Estado 2**:
   - **Condición**: Si el símbolo actual es `*` o `|`.
   - **Acción**: Deja el símbolo sin cambios y mueve la cinta a la derecha. Permanece en el estado 2 si el símbolo es `|`, cambia al estado 3 si el símbolo es `*`.
   - **Transición**: `*` → `*`, `|` → `|`, mover a la derecha.

3. **Estado 3**:
   - **Condición**: Si el símbolo actual es `*` o `|`.
   - **Acción**: Cambia el símbolo a `X` si es `*`, mueve la cinta a la izquierda y cambia al estado 4. Deja el símbolo sin cambios y mueve la cinta a la derecha si es `|`.
   - **Transición**: `*` → `X`, mover a la izquierda; `|` → `|`, mover a la derecha.

4. **Estado 4**:
   - **Condición**: Si el símbolo actual es `*`, `|`, o `X`.
   - **Acción**: Cambia el símbolo a `a` si es `|`, mueve la cinta a la derecha y cambia al estado 5. Deja el símbolo sin cambios y mueve la cinta a la izquierda si es `*` o `X`.
   - **Transición**: `*` → `*`, `|` → `a`, mover a la derecha; `X` → `X`, mover a la izquierda.

5. **Estado 5**:
   - **Condición**: Si el símbolo actual es `*`, `|`, `X`, o el final de la cadena (`\0`).
   - **Acción**: Cambia el símbolo a `|` si es `X` o `|`, mueve la cinta a la derecha si es `X` o `|`. Cambia el símbolo a `|` y mueve la cinta a la izquierda si es el final de la cadena.
   - **Transición**: `*` → `*`, `|` → `|`, `X` → `X`, mover a la derecha; `\0` → `|`, mover a la izquierda.

6. **Estado 6**:
   - **Condición**: Si el símbolo actual es `*`, `|`, `X`, o `a`.
   - **Acción**: Cambia el símbolo a `|` si es `a`, mueve la cinta a la izquierda y cambia al estado 4. Deja el símbolo sin cambios y mueve la cinta a la izquierda si es `*`, `|`, o `X`.
   - **Transición**: `*` → `*`, `|` → `|`, `X` → `X`, mover a la izquierda; `a` → `|`, mover a la izquierda.

7. **Estado 7**:
   - **Condición**: Si el símbolo actual es `*` o `|`.
   - **Acción**: Cambia el símbolo a `*` si es `*`, mueve la cinta a la derecha y cambia al estado 8. Deja el símbolo sin cambios y mueve la cinta a la derecha si es `|`.
   - **Transición**: `*` → `*`, mover a la derecha; `|` → `|`, mover a la derecha.

8. **Estado 8**:
   - **Condición**: Si el símbolo actual es `*`, `|`, o el final de la cadena (`\0`).
   - **Acción**: Cambia el símbolo a `*` si es `X`, mueve la cinta a la derecha y cambia al estado 9. Deja el símbolo sin cambios y mueve la cinta a la derecha si es `|`. Cambia el símbolo a `*` y mueve la cinta a la izquierda si es el final de la cadena.
   - **Transición**: `X` → `*`, mover a la derecha; `|` → `|`, mover a la derecha; `\0` → `*`, mover a la izquierda.

9. **Estado 9**:
   - **Condición**: Si el símbolo actual es `*`, `|`, `X`, o el final de la cadena (`\0`).
   - **Acción**: Cambia el símbolo a `*` si es `X`, mueve la cinta a la izquierda y cambia al estado 9. Deja el símbolo sin cambios y mueve la cinta a la izquierda si es `*`, `|`, o `X`. Imprime "CADENA ACEPTADA" y termina si se encuentra un `X` en el final de la cadena.
   - **Transición**: `*` → `*`, `|` → `|`, `X` → `*`, mover a la izquierda; `\0` → `X`, aceptar cadena.

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
