*This activity has been created as part of the 42 curriculum by ROPHAM.*

# ft_printf

## Description

`ft_printf` est une réimplémentation de la fonction standard `printf` du langage C. Ce projet fait partie du cursus de l'école 42 et a pour objectif de comprendre en profondeur le fonctionnement des fonctions variadiques, c'est-à-dire des fonctions acceptant un nombre variable d'arguments.

Le but est de produire une bibliothèque statique `libftprintf.a` contenant la fonction `ft_printf`, capable d'imiter le comportement du `printf` original pour les conversions les plus courantes, sans utiliser de gestion de buffer.

Ce projet permet de maîtriser :
- Les fonctions variadiques en C (`va_list`, `va_start`, `va_arg`, `va_end`)
- La création d'une bibliothèque statique avec `ar`
- La gestion des différents types de données (entiers, chaînes, pointeurs, hexadécimal)

---

## Instructions


### Compilation

Cloner le dépôt et compiler la bibliothèque :

```bash
git clone <url_du_depot>
cd printf
make
```

Cela génère le fichier `libftprintf.a` à la racine du dépôt.

### Autres commandes make

```bash
make clean    # supprime les fichiers objets (.o)
make fclean   # supprime les fichiers objets et la bibliothèque
make re       # recompile tout depuis zéro
```

### Utilisation dans un projet

Pour utiliser `ft_printf` dans ton propre code :

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Bonjour %s, tu as %d ans !\n", "Alice", 21);
    return (0);
}
```

Compiler avec la bibliothèque :

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o mon_programme
./mon_programme
```

### Conversions supportées

| Spécificateur | Description |
|---|---|
| `%c` | Affiche un caractère |
| `%s` | Affiche une chaîne de caractères |
| `%p` | Affiche un pointeur en hexadécimal |
| `%d` | Affiche un entier décimal signé |
| `%i` | Affiche un entier en base 10 |
| `%u` | Affiche un entier décimal non signé |
| `%x` | Affiche un nombre en hexadécimal minuscules |
| `%X` | Affiche un nombre en hexadécimal majuscules |
| `%%` | Affiche le caractère `%` |

---

## Resources

### Documentation officielle

- [Man page printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) — documentation complète du printf original
- [Man page stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html) — documentation des fonctions variadiques

### Testeur utilisé

- [Francinette 42](https://github.com/xicodomingues/francinette) — testeur 

### Utilisation de l'IA

L'IA (Claude) a été utilisée comme assistant. Voici les tâches pour lesquelles elle a été sollicitée :

- **Compréhension** : explication des fonctions variadiques (`va_list`, `va_start`, `va_arg`, `va_end`).
- **Correction d'erreurs** : identification et explication des erreurs de compilation.
- **Rédaction des mains** : création de main solide pour tester toutes les possibilités.
- **Rédaction du README** : aide à la structuration et à la rédaction de ce document.

Le code final a été entièrement écrit par l'étudiant.

---

## Technique Spécifique

### Architecture générale

Le projet est découpé en plusieurs fichiers, chacun ayant une responsabilité précise :

```
ft_printf.c       → fonction principale + dispatcher
ft_putchar.c      → affiche un caractère, retourne 1
ft_putstr.c       → affiche une chaîne, retourne le nombre de chars
ft_putnbr.c       → affiche un entier signé, retourne le nombre de chars
ft_putunint.c     → affiche un entier non signé, retourne le nombre de chars
ft_puthex.c       → affiche un nombre en hexadécimal (unsigned int)
ft_puthex_long.c  → affiche un nombre en hexadécimal (unsigned long, pour %p)
ft_putptr.c       → affiche un pointeur avec le préfixe 0x ou (nil)
ft_printf.h       → prototypes de toutes les fonctions
```

### Algorithme de ft_printf

La fonction `ft_printf` parcourt la chaîne de format caractère par caractère :

1. Si le caractère courant est `%`, elle avance d'un cran et passe le caractère suivant au **dispatcher** (`ft_dispatcher`).
2. Sinon, elle affiche directement le caractère avec `ft_putchar`.
3. À chaque étape, elle additionne le nombre de caractères écrits dans un compteur `count`.
4. Elle retourne `count` à la fin.

```
ft_printf("Hello %s, tu as %d ans", "Bob", 30)
         ↓
[H][e][l][l][o][ ] → ft_putchar x6
[%][s] → ft_dispatcher('s') → ft_putstr("Bob")
[,][ ][ ] → ft_putchar x3
[%][d] → ft_dispatcher('d') → ft_putnbr(30)
[ ][a][n][s] → ft_putchar x4
```

### Le dispatcher

`ft_dispatcher` est une fonction séparée dans le fichier ft_printf.c qui reçoit le spécificateur de format et la `va_list` par pointeur (`va_list *args`). Elle effectue un simple `if/else if` pour appeler la bonne fonction de conversion.

Le passage par pointeur (`va_list *`) est crucial : sans cela, la `va_list` serait copiée à chaque appel et les arguments seraient mal lus lors d'appels multiples (exemple : `ft_printf("%s %d", "hello", 42)` lirait deux fois le même argument).

### Algorithme de conversion hexadécimale

La conversion en base 16 repose sur la récursion, identique à la conversion décimale (ft_putnbr) mais avec une base différente :

```
255 en hex :
255 / 16 = 15 → récursion
255 % 16 = 15 → 'f'
15 / 16 = 0   → stop
15 % 16 = 15  → 'f'
résultat : "ff"
```

Une string de référence `"0123456789abcdef"` (ou en majuscules) sert de table de correspondance : l'index dans cette string donne directement le caractère à afficher.

### Gestion des cas limites

- **`INT_MIN` (-2147483648)** : le cas le plus piégeux. Faire `n = -n` sur `INT_MIN` provoque un overflow car 2147483648 ne rentre pas dans un `int`. Il est traité séparément avec un `ft_putstr("-2147483648")`.
- **Pointeur NULL (`%p`)** : affiche `(nil)` au lieu de `0x0`, conformément au comportement de `printf` sur Linux.
- **String NULL (`%s`)** : affiche `(null)` conformément au comportement standard.
- **`unsigned int` vs `int`** : `%u` utilise `ft_putunint` qui travaille sur `unsigned int` — pas de gestion du signe, ce qui simplifie la fonction et évite les erreurs de conversion.