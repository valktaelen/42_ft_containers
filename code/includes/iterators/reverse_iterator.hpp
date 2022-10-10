/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:19:52 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/28 01:49:42 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR
# define FT_REVERSE_ITERATOR

# include "iterators_traits.hpp"

namespace ft
{

template <class Iterator>
class reverse_iterator {
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************         types          ***********************/
		/**********************************************************************/
		typedef				Iterator											iterator_type;
		typedef typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iterator>::pointer				pointer	;
		typedef typename	ft::iterator_traits<Iterator>::reference			reference;

	private:
		iterator_type	_it;

	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************        functions       ***********************/
		/**********************************************************************/

		iterator_type	getIterator() {return _it;}

		reverse_iterator() : _it() {}

		explicit reverse_iterator (const iterator_type it) : _it(it) {}

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) {}

		~reverse_iterator() {};

		iterator_type base() const {
			return (this->_it);
		}

		reference operator*() const {
			iterator_type	tmp = _it;
			return (*(--tmp));
		}

		reverse_iterator operator+ (const difference_type n) const {
			return (reverse_iterator(this->_it - n));
		}

		reverse_iterator operator- (const difference_type n) const {
			return (reverse_iterator(this->_it + n));
		}

		reverse_iterator& operator++() {
			--(this->_it);
			return *this;
		}

		reverse_iterator  operator++(int) {
			reverse_iterator tmp(*this);
			--(this->_it);
			return tmp;
		}

		reverse_iterator& operator--() {
			++(this->_it);
			return *this;
		}

		reverse_iterator  operator--(int) {
			reverse_iterator tmp(*this);
			++(this->_it);
			return tmp;
		}

		reverse_iterator& operator+= (difference_type n) {
			this->_it -= n;
			return *this;
		}

		reverse_iterator& operator-= (difference_type n) {
			this->_it += n;
			return *this;
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return (*(*this + n));
		}

		/**********************************************************************/
		/***********************       Non member       ***********************/
		/***********************       functions        ***********************/
		/**********************************************************************/

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator& it) {
			reverse_iterator	tmp(it);
			return (tmp += n);
		}

		friend reverse_iterator	operator-(difference_type n, const reverse_iterator& it) {
			reverse_iterator	tmp(it);
			return (tmp -= n);
		}

		friend difference_type	operator-(const reverse_iterator& lhs, const reverse_iterator& rhs) {
			return (lhs._ptr - rhs._ptr);
		}


}; //class reverse_iterator

template <class _Iter1, class _Iter2>
bool	operator==(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
bool	operator<(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() > __y.base();
}

template <class _Iter1, class _Iter2>
bool	operator!=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() != __y.base();
}

template <class _Iter1, class _Iter2>
bool	operator>(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
bool	operator>=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() <= __y.base();
}

template <class _Iter1, class _Iter2>
bool	operator<=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() >= __y.base();
}

} // namespace ft


#endif
