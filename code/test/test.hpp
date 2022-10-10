/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:26:20 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/17 17:41:55 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST
# define FT_TEST

# ifndef NAMESPACE
#  define NAMESPACE ft
# endif

/******************************************************************************/
/***************************       Test for time    ***************************/
/******************************************************************************/

# define TEST_FILE_TIME "time"

# include <sys/time.h>
# include <fstream>

/******************************************************************************/
/***************************      Environnement     ***************************/
/******************************************************************************/

# define STR_IMPL(A) #A
# define STR(A) STR_IMPL(A)

# define DIR_INCLUDES ../includes

/******************************************************************************/
/***************************          Tools         ***************************/
/******************************************************************************/

/*
equal
lexicographical_compare
*/
# define HEADER_ALGORITHM algorithm.hpp

/*
pair
make_pair
*/
# define HEADER_PAIR containers/map/pair.hpp

/*
is_integral
enable_if
*/
# define HEADER_TRAITS traits.hpp

/******************************************************************************/
/***************************        Iterators       ***************************/
/******************************************************************************/

/*
iterators_traits
*/
# define HEADER_ITERATORS_TRAITS iterators/iterators_traits.hpp

/*
reverse_iterator
*/
# define HEADER_REVERSE_ITERATOR iterators/reverse_iterator.hpp

/******************************************************************************/
/***************************       Containers       ***************************/
/******************************************************************************/

/*
stack
*/
# define HEADER_STACK containers/stack.hpp

/*
vector
*/
# define HEADER_VECTOR containers/vector/vector.hpp

/*
map
*/
# define HEADER_MAP containers/map/map.hpp

#endif
