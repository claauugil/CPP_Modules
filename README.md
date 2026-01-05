
# 🧩 C++ - Módulo 00
**Tema:** namespaces, clases, funciones miembro, iostream, listas de inicialización, static, const.
Norma: C++98 – sin printf, malloc/free, using namespace, STL (hasta módulo 08).

## ex00 – Megaphone

Programa que imprime los argumentos en mayúsculas.
* Sin argumentos:
```bash
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## ex01 – My Awesome PhoneBook

Agenda con 8 contactos máx.

`ADD`: añadir contacto(campos no vacíos)

`SEARCH`: lista formateada + ver detalles por índice

`EXIT`: salir

---

# 🧩 C++ - Módulo 01  
**Temas:** Memoria dinámica, referencias y punteros a miembros  

| Ejercicio | Nombre | Descripción |
|-----------|--------|-------------|
| 🧟 **ex00** | BraiiiiiiinnnzzzZ | Clase `Zombie` con método `announce()`. Crea zombies en **heap** o **stack**. Practica `new`, `delete` y destructores. |
| 🧟‍♂️ **ex01** | Moar brainz! | Función `zombieHorde(int N, std::string name)` que crea **N zombies** en una sola reserva de memoria. Manejo de `new[]` y `delete[]`. |
| 🧠 **ex02** | HI THIS IS BRAIN | Muestra direcciones y valores de una `std::string`, un puntero y una referencia. Comparación de su comportamiento. |
| ⚔️ **ex03** | Unnecessary violence | Clases `Weapon`, `HumanA` (usa referencia) y `HumanB` (usa puntero). Demuestra diferencias entre referencias y punteros. |
| 📝 **ex04** | Sed is for losers | Reemplaza todas las apariciones de una cadena por otra en un archivo y guarda el resultado en `<filename>.replace`. Sin `std::string::replace`. |
| 😡 **ex05** | Harl 2.0 | Clase `Harl` con niveles (`DEBUG`, `INFO`, `WARNING`, `ERROR`). Usa **punteros a funciones miembro** en lugar de `if/else` anidados. |
| 🎚️ **ex06** | Harl filter | Filtra los mensajes de `Harl` desde un nivel dado hacia arriba usando `switch`. |

---
# 🧩 C++ - Módulo 02

**Tema:** Polimorfismo ad-hoc, sobrecarga de operadores y forma canónica ortodoxa.

### Ejercicios 📚

- **ex00:** Clase `Fixed` básica con constructor, copia, asignación y destructor.  
  Guarda un número fijo con 8 bits fraccionales.

- **ex01:** Añade constructores para int y float, convierte Fixed a float/int,  
  y sobrecarga operador `<<` para imprimir.

- **ex02:** Sobrecarga operadores comparación, aritméticos,  
  y pre/post incremento/decremento. Métodos estáticos `min` y `max`.

---
# 🧩 C++ - Módulo 03
**Tema:** Herencia, clases derivadas y múltiples herencias.  

| Ejercicio | Nombre | Descripción |
|-----------|--------|-------------|
| 🤖 **ex00** | Aaaaand... OPEN! | Clase `ClapTrap` con atributos `name`, `hit points`, `energy points` y `attack damage`. Métodos: `attack()`, `takeDamage()`, `beRepaired()`. Práctica de constructores, destructores y mensajes por consola. |
| 🛡️ **ex01** | Serena, my love! | Clase `ScavTrap` que hereda de `ClapTrap`. Hit points y energy points distintos. Añade método especial `guardGate()` y muestra mensajes distintos de construcción y ataque. |
| 💥 **ex02** | Repetitive work | Clase `FragTrap` que hereda de `ClapTrap`. Hit points y energy points aumentados. Añade método especial `highFivesGuys()` y mensajes propios de construcción/ataque. |
| 💎 **ex03** | Now it’s weird! | Clase `DiamondTrap` que hereda de **FragTrap** y **ScavTrap**. Mezcla atributos y métodos de ambos padres, añade método especial `whoAmI()` que muestra su nombre y el de ClapTrap. Maneja correctamente la creación de la instancia ClapTrap única. |

# 🧩 C++ - Módulo 04
**Tema:** Polimorfismo por subtipos, clases abstractas e interfaces.  

| Ejercicio | Nombre | Descripción |
|-----------|--------|-------------|
| 🐶🐱 **ex00** | Polymorphism | Clase base `Animal` con atributo protegido `type` y método virtual `makeSound()`. Clases derivadas `Dog` y `Cat` implementan sonidos específicos. Incluye `WrongAnimal` y `WrongCat` para demostrar el error al no usar funciones virtuales. |
| 🧠 **ex01** | I don’t want to set the world on fire | Implementa clase `Brain` con array de 100 `std::string`. `Dog` y `Cat` contienen un `Brain*` privado. Se gestionan con `new`/`delete`. Se prueban destructores correctos, gestión de memoria y **deep copy**. |
| 🚫 **ex02** | Abstract class | La clase `Animal` ya no debe poder instanciarse directamente. Se convierte en clase abstracta, asegurando que solo clases derivadas (`Dog`, `Cat`) puedan usarse. |

---

# 🧩 C++ - Módulo 05  
**Tema:** Excepciones, clases abstractas, herencia y control de acceso.

| Ejercicio | Nombre | Descripción |
|-----------|--------|-------------|
| 🧑‍💼 **ex00** | Bureaucrat | Clase `Bureaucrat` con `name` constante y `grade` (1 = más alto, 150 = más bajo). Implementa incremento/decremento de grado con **excepciones** (`GradeTooHighException`, `GradeTooLowException`). Introduce `try`, `throw` y `catch` heredando de `std::exception`. |
| 📝 **ex01** | Form | Clase `Form` que puede ser firmada por un `Bureaucrat` si su grado es suficiente. Practica el uso de **atributos const**, validación de rangos y manejo de excepciones. Relación entre clases sin herencia. |
| 📄 **ex02** | AForm | Versión abstracta de `Form`. Introduce **clases abstractas** y **polimorfismo**. Implementa `execute()` con comprobaciones comunes y formularios concretos con comportamiento específico. |
| 🏭 **ex03** | Intern | Clase fábrica `Intern` que crea formularios dinámicamente según un nombre. Practica el **factory pattern**, uso de punteros a la clase base `AForm` y manejo de errores cuando el formulario no existe. |
