*Cette activité a été créée dans le cadre du cursus de 42 par ropham et mamenego*

# PUSH SWAP

## Description

Push Swap est un projet d'algorithmique qui consiste à trier une pile de nombres entiers en utilisant un ensemble d'opérations limité et deux piles : la pile A et la pile B.

L'objectif est de trier la pile A dans l'ordre croissant (du bas vers le haut) en utilisant le moins d'opérations possible. Le programme reçoit une liste d'entiers en argument et affiche sur la sortie standard la séquence d'opérations à effectuer pour trier la pile.

Les opérations disponibles sont :
- `sa`, `sb`, `ss` : swap des deux premiers éléments d'une pile
- `pa`, `pb` : push le premier élément d'une pile vers l'autre
- `ra`, `rb`, `rr` : rotate vers le haut
- `rra`, `rrb`, `rrr` : rotate vers le bas

## Instructions

### Compilation

```bash
make
```

Cela compile les librairies libft et ft_printf puis génère le binaire `push_swap`.

### Exécution

```bash
./push_swap [STRATÉGIE] <liste de nombres>
```

Stratégies disponibles (optionnelles) :
- `--simple` : tri par sélection O(n²), adapté aux petits stacks
- `--medium` : tri par chunks O(n√n), adapté aux stacks moyens
- `--complex` : tri radix LSD O(n log n), adapté aux grands stacks
- `--adaptive` : sélection automatique de la stratégie selon le niveau de désordre (défaut)

Exemples :
```bash
./push_swap 3 1 2 5 4
./push_swap --complex 42 17 3 99 56 1
./push_swap --adaptive 5 4 3 2 1
```

### Nettoyage

```bash
make clean    # supprime les fichiers objets
make fclean   # supprime les fichiers objets et le binaire
make re       # recompile tout depuis zéro
```

## Arborescence

```
.
├── Makefile                    # compilation du projet et des librairies
├── push_swap.h                 # header principal : structures, enums, prototypes
├── main.c                      # point d'entrée : parsing, sélection et lancement de la stratégie
│
├── algo/
│   ├── sort_case.c             # sort_three, sort_four, sort_five : cas simples ≤ 5 éléments
│   ├── sort_simple.c           # tri par sélection O(n²) pour petits stacks
│   ├── sort_medium.c           # tri par chunks O(n√n) pour stacks moyens
│   └── sort_complex.c          # tri radix LSD O(n log n) pour grands stacks
│
├── operations/
│   ├── opp.c                   # pa, pb, sa, sb, ss : push et swap
│   ├── rotate.c                # ra, rb, rr : rotations vers le haut
│   └── rotate2.c               # rra, rrb, rrr : rotations vers le bas
│
├── parsing/
│   ├── parsingarg.c            # validation et chargement des arguments dans la pile
│   └── parseflag.c             # détection et parsing de la stratégie via flags
│
├── strategies/
│   ├── choose.c                # sélection et dispatch de la stratégie, sort_dispatcher, adaptive_sort
│   └── compute_disorder.c      # calcul du taux de désordre de la pile A
│
└── utils/
    └── utils.c                 # fonctions utilitaires : is_sorted, is_empty, top, indice, is_int_range
```

## Resources

### Références

- [Radix Sort - GeeksForGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Algorithme de tri par sélection](https://fr.wikipedia.org/wiki/Tri_par_s%C3%A9lection)
- [Tri par chunks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- Documentation officielle de 42 : sujet Push Swap

### Utilisation de l'IA

L'IA (Claude, Anthropic) a été utilisée comme outil de support tout au long du projet :
- Aide à la rédaction du README
- Compréhension de certaines notions algorithmiques, notamment les flags de compilation et le fonctionnement du radix sort
- Compréhension et clarification du sujet
- Sessions de débogage : identification des bugs logiques dans les fonctions sort

## Répartition des tâches

**ropham** : algorithmes de tri (sort simple, medium, complex), 11 opérations de stack, fonctions helpers, sort cases (sort_three, sort_four, sort_five), débogage, README

**mamenego** : parsing, parsing flag, algorithme adaptatif, stratégies (choose et compute_disorder), fonctions helpers, débogage, Makefile, sort cases

### Organisation

Nous avons défini la répartition du travail en amont puis travaillé chacun de notre côté de manière autonome. Plusieurs points d'avancement ont été réalisés au cours du projet pour synchroniser notre travail et identifier les ajustements nécessaires. Une session de débogage commune a été menée en fin de projet pour valider le bon fonctionnement de l'ensemble avant le push final.
