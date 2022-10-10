# ft_containers

## Infos sur le projet

Recoder des conteneurs de la librairie standard c++ tout en respectant la version c++98 dans son propre namespace `ft`.

Les conteneurs concernés sont map, vector et stack.

Pour cela ces fonctionnalités seront recodés iterators_traits, reverse_iterator, enable_if, is_integral, equal and/or lexicographical_compare, std::pair et std::make_pair.

## Utilisation

### Headers à inclure

Le dossier d'inclusion est `includes/`

#### Les conteneurs
```c
#include "containers/stack.hpp"
#include "containers/vector/vector.hpp"
#include "containers/map/map.hpp"
```

#### Les outils
```c
/*
equal
lexicographical_compare
*/
#include "algorithm.hpp"

/*
pair
make_pair
*/
#include "containers/map/pair.hpp"

/*
is_integral
enable_if
*/
#include "traits.hpp"
```
#### Les iterateurs
```c
/*
iterators_traits
*/
#include "iterators/iterators_traits.hpp"

/*
reverse_iterator
*/
#include "iterators/reverse_iterator.hpp"
```

### Lancer le projet

`make` compilera 2 executables un `ft_containers` (`namespace ft`) 
et un `ft_containers_std` qui est compilé avec la librairie standard (`namespace std`)

#### Tests unitaire
Lancer `make test`.

Pour changer les infos de compilations des sources, toutes les informations à changer
sont dans `test/test.hpp`.