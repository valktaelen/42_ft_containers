/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:01:48 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/28 18:21:13 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR
# define FT_VECTOR

# include <memory>
# include <stdexcept>
# include "../../iterators/iterators_traits.hpp"
# include "../../traits.hpp"
# include "../../iterators/reverse_iterator.hpp"
# include "./vectorIterator.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************         types          ***********************/
		/**********************************************************************/
		typedef T													value_type;
		typedef Alloc												allocator_type;
		// Ref
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		// Ptr
		typedef	typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		// Iterators
		typedef			ft::vectorIterator<			value_type>			iterator;
		typedef			ft::vectorIterator<const	value_type>			const_iterator;
		typedef			ft::reverse_iterator<iterator>					reverse_iterator;
		typedef			ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		// Type info
		typedef size_t												size_type;
	private:
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		pointer			_tab;
	public:
		explicit vector (const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _tab(NULL) {}
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n), _tab(this->_alloc.allocate(n))
		{
			for (size_type	i = 0; i < n; i++) {
				this->_tab[i] = val;
			}
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			: _alloc(alloc), _size(0), _capacity(0), _tab(NULL) 
		{
			this->insert(this->begin(), first, last);
		}
		vector (const vector& x) : _alloc(x._alloc), _size(0), _capacity(0), _tab(NULL) {
			this->insert(this->begin(), x.begin(), x.end());
		}

		~vector() {
			this->clear();
			this->_alloc.deallocate(this->_tab, this->_capacity);
		}

		vector&	operator=(const vector& x) {
			if (this != &x) {
				this->clear();
				this->_alloc.deallocate(this->_tab, this->_capacity);
				this->_capacity = x._capacity;
				if (_capacity)
					this->_tab = this->_alloc.allocate(this->_capacity);
				else
					this->_tab = NULL;
				for (size_type i = 0; i < x.size(); i++)
					this->push_back(x[i]);
			}
			return (*this);
		}

		iterator begin() {
			return (iterator(this->_tab));
		}
		
		const_iterator begin() const {
			return (const_iterator(this->_tab));
		}

		iterator end() {
			return (iterator(this->_tab + this->_size));
		}

		const_iterator end() const {
			return (const_iterator(this->_tab + this->_size));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(this->end()));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator rend(){
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend() const{
			return (const_reverse_iterator(this->begin()));
		}

		allocator_type get_allocator() const {
			return (allocator_type());
		}

		size_type size() const {
			return (this->_size);
		}

		size_type max_size() const {
			return (this->_alloc.max_size());
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < this->_size) {
				while (n != this->_size) {
					this->pop_back();
				}
			} else if (n > this->_size) {
				while (n != this->_size) {
					this->push_back(val);
				}
			}
		}

		size_type capacity() const {
			return (this->_capacity);
		}

		bool empty() const {
			return (this->_size == 0);
		}

		void reserve (size_type n) {
			if (n > this->max_size())
				throw std::length_error("error::vector::size_max");
			if (this->_capacity < n) {
				pointer	tmp = this->_alloc.allocate(n, this->_tab);
				iterator	new_it = iterator(tmp);
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					*new_it = *it;
					++new_it;
				}
				this->_alloc.deallocate(this->_tab, this->_capacity);
				this->_tab = tmp;
				this->_capacity = n;
			}
		}

		reference operator[] (size_type n) {
			return (this->_tab[n]);
		}

		const_reference operator[] (size_type n) const {
			return (this->_tab[n]);
		}

		reference at (size_type n) {
			if (n >= this->_size)
				throw std::out_of_range("out_of_range");
			return (this->_tab[n]);
		}

		const_reference at (size_type n) const {
			if (n >= this->_size)
				throw std::out_of_range("out_of_range");
			return (this->_tab[n]);
		}

		reference front() {
			return (*(this->_tab));
		}

		const_reference front() const {
			return (*(this->_tab));
		}

		reference back() {
			return (*(this->_tab + this->_size - 1));
		}

		const_reference back() const {
			return (*(this->_tab + this->_size - 1));
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
			size_type	len = last - first;
			size_type	tmpSize = this->_size;
			if (this->_size + len < this->_capacity) {
				this->insert(this->end(), first, last);
				for (size_type i = 0; i < tmpSize; i++)
				{
					erase(this->begin());
				}
			} else {
				pointer	tmp = this->_alloc.allocate(len, this->_tab);
				size_type	i = 0;
				for (InputIterator it = first; it != last; it++) {
					tmp[i++] = *it;
				}
				this->clear();
				this->_alloc.deallocate(this->_tab, this->_capacity);
				this->_tab = tmp;
				this->_capacity = len;
				this->_size = len;
			}
		}

		void assign (size_type n, const value_type& val) {
			this->clear();
			this->resize(n, val);
		}

		void push_back (const value_type& val) {
			if (_size + 1 <= _capacity) {
				this->_alloc.construct(&(_tab[_size]), val);
				++_size;
			} else
				insert(this->end(), 1, val);
		}

		void pop_back() {
			if (this->_size)
				this->_alloc.destroy(this->_tab + (--(this->_size)));
		}

		iterator insert (iterator position, const value_type& val) {
			size_type	pos = position - this->begin();
			insert(position, 1, val);
			return (iterator(this->_tab + pos));
		}

		void insert (iterator position, size_type n, const value_type& val) {
			iterator	endIterator = this->end();
			size_type	len = this->_size + n;
			if (len <= this->_capacity) {
				iterator	tmp = this->end() + (n - 1);
				for (iterator	it = this->end() - 1; it != position - 1; it--) {
					/*if (tmp < this->end())
						this->_alloc.destroy(&(*tmp));*/
					this->_alloc.construct(&(*tmp), *it);
					//*tmp = *it;
					--tmp;
				}
				for (iterator	it = position; it != position + n; it++) {
					/*if (it < this->end())
						this->_alloc.destroy(&(*tmp));*/
					this->_alloc.construct(&(*it), val);
					//*it = val;
				}
			} else {
				size_type	cap = (len < 2 * this->_capacity ? 2 * this->_capacity : len);
				pointer		tmp = this->_alloc.allocate(cap, this->_tab);
				iterator	new_it = iterator(tmp);
				for (iterator	it = this->begin(); it != position; it++) {
					this->_alloc.construct(&(*new_it), *it);
					//*new_it = *it;
					++new_it;
				}
				for (size_type i = 0; i < n; i++) {
					this->_alloc.construct(&(*new_it), val);
					//*new_it = val;
					++new_it;
				}
				for (iterator	it = position; it != this->end(); it++) {
					this->_alloc.construct(&(*new_it), *it);
					//*new_it = *it;
					++new_it;
				}
				this->clear();
				this->_alloc.deallocate(this->_tab, this->_capacity);
				this->_tab = tmp;
				this->_capacity = cap;
			}
			this->_size = len;
		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
			while (last != first) {
				--last;
				position = this->insert(position, *last);
			}
		}

		iterator erase (iterator position) {
			iterator	it = position;
			for (iterator it = position; it + 1 != this->end(); it++)
				*it = *(it + 1);
			this->pop_back();
			return (position);
		}

		iterator erase (iterator first, iterator last) {
			size_type	len = last - first;
			iterator	tmp = first;
			while (tmp + len != this->end()) {
				*tmp = *(tmp + len);
				++tmp;
			}
			for (size_type i = 0; i < len && this->_size; i++)
			{
				this->pop_back();
			}
			return first;
		}

		void swap (vector& x) {
			allocator_type	alloc = this->_alloc;
			size_type		capacity = this->_capacity;
			size_type		size = this->_size;
			pointer			tab = this->_tab;
			this->_alloc = x._alloc;
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->_tab = x._tab;
			x._alloc = alloc;
			x._capacity = capacity;
			x._size = size;
			x._tab = tab;
		}

		void clear() {
			while (this->_size) {
				this->pop_back();
			}
		}

		friend bool operator== (const vector& lhs, const vector& rhs) {
			size_type i = 0;
			size_type min = (lhs.size()<rhs.size() ? lhs.size() : rhs.size());
			while (i < min) {
				if (lhs[i] != rhs[i])
					return false;
				++i;
			}
			return true;
		}
		friend bool operator!= (const vector& lhs, const vector& rhs) {
			return (!(lhs == rhs));
		}
		friend bool operator<  (const vector& lhs, const vector& rhs) {
			size_type i = 0;
			size_type min = (lhs.size()<rhs.size() ? lhs.size() : rhs.size());
			while (i < min) {
				if (lhs[i] >= rhs[i])
					return false;
				++i;
			}
			return true;
		}
		friend bool operator<= (const vector& lhs, const vector& rhs) {
			return !(rhs<lhs);
		}
		friend bool operator>  (const vector& lhs, const vector& rhs) {
			return rhs < lhs;
		}
		friend bool operator>= (const vector& lhs, const vector& rhs) {
			return !(lhs<rhs);
		}

};
template <class T>
void swap (vector<T>& x, vector<T>& y) {
	x.swap(y);
}

}

#endif