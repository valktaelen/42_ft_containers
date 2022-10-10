/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:03:29 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/29 01:49:35 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR
# define FT_VECTOR_ITERATOR

# include <cstddef>
# include "../../iterators/category.hpp"

namespace ft
{
	template <class T>
	class vectorIterator
	{
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************         types          ***********************/
		/**********************************************************************/
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	private:
		/**********************************************************************/
		/***********************       Attributes       ***********************/
		/**********************************************************************/
		pointer	_ptr;
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************       functions        ***********************/
		/**********************************************************************/
		vectorIterator() : _ptr(NULL) {}
		template <class X>
		vectorIterator(const vectorIterator<X>&	ref) : _ptr(ref.base()) {}
		vectorIterator(const vectorIterator&	ref) : _ptr(ref._ptr) {}
		vectorIterator(pointer	ptr) : _ptr(ptr) {}
		~vectorIterator() {}

		vectorIterator&	operator=(const vectorIterator& ref) {
			if (this != &ref)
				this->_ptr = ref._ptr;
			return (*this);
		}

		vectorIterator&	operator++(void) { 
			++(this->_ptr);
			return (*this);
		}

		vectorIterator	operator++(int) {
			vectorIterator	tmp(*this);
			++(*this);
			return (tmp);
		}

		template <class X>
		bool	operator==(const vectorIterator<X>& it) const {
			return (it.base() == this->_ptr);
		}

		template <class X>
		bool	operator!=(const vectorIterator<X>& it) const {
			return (it.base() != this->_ptr);
		}

		reference	operator*() const {
			return (*(this->_ptr));
		}

		pointer operator->() const {
			return(&(operator*()));
		}

		vectorIterator&	operator--(void) { 
			--(this->_ptr);
			return (*this);
		}

		vectorIterator	operator--(int) {
			vectorIterator	tmp(*this);
			--(*this);
			return (tmp);
		}

		vectorIterator	operator+(const difference_type n) const {
			vectorIterator	tmp(*this);

			tmp += n;
			return (tmp);
		}

		vectorIterator	operator-(const difference_type n) const {
			vectorIterator	tmp(*this);

			tmp -= n;
			return (tmp);
		}

		template <class X>
		bool operator<(const vectorIterator<X>& it)const {
			return (it.base() > this->_ptr);
		}
		template <class X>
		bool operator>(const vectorIterator<X>& it)const {
			return (it.base() < this->_ptr);
		}
		template <class X>
		bool operator<=(const vectorIterator<X>& it)const {
			return (it.base() >= this->_ptr);
		}
		template <class X>
		bool operator>=(const vectorIterator<X>& it)const {
			return (it.base() <= this->_ptr);
		}

		vectorIterator&	operator+=(const difference_type n) {
			this->_ptr += n;
			return (*this);
		}

		vectorIterator&	operator-=(const difference_type n) {
			this->_ptr -= n;
			return (*this);
		}

		reference operator[](const difference_type n) const {
			return (this->_ptr[n]);
		}
		reference operator[](const difference_type n) {
			return (this->_ptr[n]);
		}

		pointer	base() const {return _ptr;}

		/**********************************************************************/
		/***********************       Non member       ***********************/
		/***********************       functions        ***********************/
		/**********************************************************************/
		friend vectorIterator	operator+(difference_type n, const vectorIterator& it) {
			vectorIterator	tmp(it);
			return (tmp += n);
		}

		friend vectorIterator	operator-(difference_type n, const vectorIterator& it) {
			vectorIterator	tmp(it);
			return (tmp -= n);
		}

		friend difference_type	operator-(const vectorIterator& lhs, const vectorIterator& rhs) {
			return (lhs._ptr - rhs._ptr);
		}


	}; // class vectorIterator
	
} // namespace ft

#endif
