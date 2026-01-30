# 🎯 C++ Modules - 42 Madrid

> Mis soluciones a los ejercicios de C++98, desde los fundamentos hasta la STL avanzada

---

## 📚 Módulos

- [00 - Fundamentos](#-módulo-00---fundamentos)
- [01 - Gestión de Memoria](#-módulo-01---gestión-de-memoria)
- [02 - Sobrecarga de Operadores](#-módulo-02---sobrecarga-de-operadores)
- [03 - Herencia](#-módulo-03---herencia)
- [04 - Polimorfismo](#-módulo-04---polimorfismo)
- [05 - Excepciones](#️-módulo-05---excepciones)
- [06 - Conversión de Tipos](#-módulo-06---conversión-de-tipos)
- [07 - Templates](#-módulo-07---templates)
- [08 - STL Básica](#-módulo-08---stl-básica)
- [09 - STL Avanzada](#-módulo-09---stl-avanzada)

---

## 🌟 Módulo 00 - Fundamentos

**Conceptos:** `namespaces` · `clases` · `iostream` · `static` · `const`  
**Norma:** C++98 (sin printf, malloc/free, using namespace, STL)

<table>
<tr>
<td width="50%">

### 📣 Megaphone
Programa que convierte argumentos a mayúsculas.

**Características:**
- Lee argumentos desde la línea de comandos
- Convierte todo a UPPERCASE
- Sin args: `"* LOUD AND UNBEARABLE FEEDBACK NOISE *"`

**Implementa:**
- Uso básico de `iostream`
- Manipulación de strings en C++
- Funciones de transformación

</td>
<td width="50%">

### 📒 PhoneBook
Una agenda con capacidad limitada.

**Características:**
- Máximo 8 contactos
- Comando `ADD`: nuevo contacto
- Comando `SEARCH`: lista + detalles
- Comando `EXIT`: salir del programa
- Campos obligatorios (no vacíos)

**Implementa:**
- Clases y atributos privados
- Arrays de objetos
- Validación de entrada
- Formateo de salida

</td>
</tr>
</table>

---

## 🧠 Módulo 01 - Gestión de Memoria

**Conceptos:** Memoria dinámica · Referencias · Punteros a miembros

<table>
<tr>
<td width="33%">

### 🧟 BraiiiiiiinnnzzzZ
Clase `Zombie` básica.

**Reto:** Crear zombies tanto en **stack** como en **heap** y entender cuándo usar cada uno.

**Solución incluye:**
- Operador `new` y `delete`
- Destructores automáticos
- Gestión de memoria

</td>
<td width="33%">

### 🧟‍♂️ Moar brainz!
Horda de zombies.

**Reto:** Crear N zombies con una sola asignación de memoria.

**Función clave:**
```cpp
Zombie* zombieHorde(int N, std::string name)
```

**Solución incluye:**
- Arrays dinámicos (`new[]`)
- Liberación correcta (`delete[]`)

</td>
<td width="33%">

### 🧠 HI THIS IS BRAIN
Punteros vs Referencias.

**Muestra:**
- Direcciones de memoria
- Valores almacenados
- Diferencias fundamentales

**Conceptos:**
- `std::string str`
- `std::string* ptr`
- `std::string& ref`

</td>
</tr>
</table>

<table>
<tr>
<td width="33%">

### ⚔️ Unnecessary violence
Sistema de combate simple.

**Clases:**
- `Weapon` - arma modificable
- `HumanA` - usa **referencia** (siempre tiene arma)
- `HumanB` - usa **puntero** (arma opcional)

**Demuestra la diferencia crucial entre referencias y punteros**

</td>
<td width="33%">

### 📝 Sed is for losers
Reemplazo de texto en archivos.

**Funcionalidad:**
- Lee archivo de entrada
- Reemplaza todas las ocurrencias
- Guarda en `<filename>.replace`

**Restricción:** Sin usar `std::string::replace`

</td>
<td width="33%">

### 😡 Harl 2.0 + 🎚️ Filter
Sistema de logging con niveles.

**Niveles:**
- `DEBUG` 🐛
- `INFO` ℹ️
- `WARNING` ⚠️
- `ERROR` ❌

**Técnica:** Punteros a funciones miembro (sin if/else anidados)

</td>
</tr>
</table>

---

## 🔢 Módulo 02 - Sobrecarga de Operadores

**Conceptos:** Polimorfismo ad-hoc · Forma canónica ortodoxa · Punto fijo

### 📊 Evolución de la clase Fixed

```
Fixed básico  →  Fixed con conversiones  →  Fixed con operadores completos
   (ex00)              (ex01)                      (ex02)
```

<table>
<tr>
<td width="33%">

**ex00: Fundamentos**
- Constructor por defecto
- Constructor de copia
- Operador de asignación
- Destructor
- Valor fijo (8 bits fraccionarios)

</td>
<td width="33%">

**ex01: Conversiones**
- Constructor desde `int`
- Constructor desde `float`
- Conversión a `float`
- Conversión a `int`
- Sobrecarga de `<<`

</td>
<td width="33%">

**ex02: Operadores**
- Comparación: `>` `<` `>=` `<=` `==` `!=`
- Aritméticos: `+` `-` `*` `/`
- Incremento: `++i` `i++`
- Decremento: `--i` `i--`
- Estáticos: `min()` `max()`

</td>
</tr>
</table>

---

## 🤖 Módulo 03 - Herencia

**Conceptos:** Clases derivadas · Herencia múltiple · Problema del diamante

### 🔄 Jerarquía de Clases

```
                    ClapTrap
                   /        \
              ScavTrap    FragTrap
                   \        /
                  DiamondTrap
```

| Clase | HP | Energy | Damage | Habilidad especial |
|-------|-------|---------|--------|-------------------|
| 🤖 **ClapTrap** | 10 | 10 | 0 | `attack()` · `takeDamage()` · `beRepaired()` |
| 🛡️ **ScavTrap** | 100 | 50 | 20 | `guardGate()` - modo guardián |
| 💥 **FragTrap** | 100 | 100 | 30 | `highFivesGuys()` - high five positivo |
| 💎 **DiamondTrap** | 100 | 50 | 30 | `whoAmI()` - identidad dual |

**Reto del ex03:** Resolver el problema del diamante con herencia virtual

---

## 🐾 Módulo 04 - Polimorfismo

**Conceptos:** Clases abstractas · Interfaces · Virtual · Deep copy

### 🧬 Sistema de Animales

<table>
<tr>
<td width="50%">

**ex00 - ex01: Polimorfismo básico**

```cpp
Animal* animals[4];
animals[0] = new Dog();
animals[1] = new Cat();
```

**Características:**
- Clase base `Animal` con `makeSound()` virtual
- Clase `Brain` con 100 ideas
- Deep copy en constructores de copia
- Destructores virtuales

</td>
<td width="50%">

**ex02: Clase abstracta**

```cpp
// Animal ya NO se puede instanciar
Animal* a = new Animal(); // ❌ Error
Animal* d = new Dog();    // ✅ OK
```

**Conversión a abstracta:**
- `makeSound()` = función virtual pura
- Solo instancias de clases derivadas

</td>
</tr>
</table>

**Contraste con WrongAnimal:** Demuestra qué pasa sin funciones virtuales

---

## ⚠️ Módulo 05 - Excepciones

**Conceptos:** try-catch · throw · std::exception · Factory pattern

### 🏢 Sistema Burocrático

<table>
<tr>
<td width="50%">

#### Jerarquía de clases

```
    Bureaucrat
        |
      Form (ex01)
        |
     AForm (ex02)
    /  |  \
   /   |   \
Shrubbery Presidential RobotomyRequest
```

</td>
<td width="50%">

#### Sistema de rangos

| Rango | Significado |
|-------|-------------|
| 1 | 🏆 Máximo poder |
| 75 | Firmar formularios básicos |
| 150 | 📊 Mínimo poder |
| 0 o >150 | ⚠️ Excepción |

</td>
</tr>
</table>

**ex00:** Burocrático simple con excepciones de rango  
**ex01:** Formularios que requieren firma  
**ex02:** Formularios abstractos con ejecución  
**ex03:** Becario (Intern) como factory de formularios

---

## 🔄 Módulo 06 - Conversión de Tipos

**Conceptos:** Casts · RTTI · Serialización · type detection

<table>
<tr>
<td width="33%">

### 🔢 ScalarConverter
Conversión de literales.

**Entrada:** `string` literal  
**Salida:** `char`, `int`, `float`, `double`

**Maneja:**
- Números normales
- Pseudo-literales (`nan`, `inf`, `-inff`)
- Casos imposibles
- No imprimibles

**Cast:** Explícito según tipo

</td>
<td width="33%">

### 🔐 Serializer
Serialización de punteros.

**Funciones:**
```cpp
uintptr_t serialize(Data* ptr)
Data* deserialize(uintptr_t raw)
```

**Concepto:**
- Conversión puntero ↔ entero
- `reinterpret_cast`
- Diferencia representación/valor

</td>
<td width="33%">

### 🧬 Identify type
Identificación en tiempo de ejecución.

**Jerarquía:**
```
Base
 ├─ A
 ├─ B
 └─ C
```

**Técnica:** `dynamic_cast`
- Con punteros
- Con referencias
- Sin usar `typeid`

</td>
</tr>
</table>

---

## 📐 Módulo 07 - Templates

**Conceptos:** Funciones template · Clases template · Genericidad

<table>
<tr>
<td width="33%">

### 🔄 Funciones básicas

**Implementar:**
```cpp
template<typename T>
void swap(T& a, T& b)

template<typename T>
T min(T a, T b)

template<typename T>
T max(T a, T b)
```

**Regla:** Si son iguales, devolver el segundo

</td>
<td width="33%">

### 🔧 Función iter

**Prototipo:**
```cpp
template<typename T>
void iter(T* array, 
          size_t len, 
          void (*f)(T&))
```

**Aplica una función a cada elemento del array**

</td>
<td width="33%">

### 🗂️ Clase Array

**Características:**
- Constructor vacío y con tamaño
- Deep copy automática
- Operador `[]` con bounds checking
- Función `size()`
- Excepción si índice inválido

</td>
</tr>
</table>

---

## 📦 Módulo 08 - STL Básica

**Conceptos:** Contenedores · Iteradores · Algoritmos estándar

<table>
<tr>
<td width="33%">

### 🔍 easyfind

**Objetivo:** Encontrar un entero en un contenedor.

**Uso:**
```cpp
std::vector<int> v;
easyfind(v, 42);
```

**Requiere:**
- Template genérico
- `std::find`
- Manejo de "no encontrado"

</td>
<td width="33%">

### 📏 Span

**Almacena N enteros con límite.**

**Métodos:**
- `addNumber(int)`
- `addRange(iter, iter)`
- `shortestSpan()`
- `longestSpan()`

**Optimizado para grandes volúmenes**

</td>
<td width="33%">

### 🧬 MutantStack

**Stack iterable.**

**Hereda de:** `std::stack<T>`

**Añade:**
- `begin()` / `end()`
- `rbegin()` / `rend()`

**Se comporta como stack pero permite recorrido**

</td>
</tr>
</table>

---

## 🚀 Módulo 09 - STL Avanzada

**Conceptos:** Contenedores avanzados · Algoritmos complejos · Optimización

<table>
<tr>
<td width="33%">

### ₿ Bitcoin Exchange

**Entrada:** Archivo con `date | value`

**Funcionalidad:**
- Valida fechas (YYYY-MM-DD)
- Valida valores (0-1000)
- Busca fecha más cercana en DB
- Calcula valor BTC

**Contenedor recomendado:** `std::map`

</td>
<td width="33%">

### 🧮 RPN Calculator

**Notación polaca inversa**

**Ejemplo:**
```
Input:  "3 4 + 2 *"
Output: 14
```

**Restricciones:**
- Operandos < 10
- Operadores: + - * /
- Sin decimales

**Contenedor recomendado:** `std::stack`

</td>
<td width="33%">

### ⚡ PmergeMe

**Algoritmo:** Ford-Johnson (merge-insert)

**Requisitos:**
- Ordena ≥3000 números
- Dos implementaciones (dos contenedores)
- Mide tiempos de ejecución
- Compara eficiencia

**Enfoque:** Optimización y complejidad

</td>
</tr>
</table>

---

<div align="center">

### 🌟 42 Madrid - C++ Modules

**Norma C++98** · **Orthodox Canonical Form** · **No STL hasta Módulo 08**

</div>
