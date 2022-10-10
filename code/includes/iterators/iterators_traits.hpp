/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:11:11 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/13 19:55:48 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATORS_TRAITS
# define FT_ITERATORS_TRAITS

# include <cstddef>
# include "category.hpp"

namespace ft
{

// Prototype

template <class Iterator> class iterator_traits;
template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;

template <class Iterator> class iterator_traits{
	public:
	typedef typename	Iterator::difference_type	difference_type;
	typedef typename	Iterator::value_type		value_type;
	typedef typename	Iterator::pointer			pointer;
	typedef typename	Iterator::reference			reference;
	typedef typename	Iterator::iterator_category	iterator_category;
};

template <class T> class iterator_traits<T*>{
	public:
	typedef	ptrdiff_t						difference_type;
	typedef	T								value_type;
	typedef	T*								pointer;
	typedef	T&								reference;
	typedef	ft::random_access_iterator_tag	iterator_category;
};

template <class T> class iterator_traits<const T*>{
	public:
	typedef	ptrdiff_t						difference_type;
	typedef	T								value_type;
	typedef	T*								pointer;
	typedef	T&								reference;
	typedef	ft::random_access_iterator_tag	iterator_category;
};


} // namespace ft


#endif
