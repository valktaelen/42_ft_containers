/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:19:18 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/28 19:50:43 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include "pair.hpp"
# include "mapIterator.hpp"
# include "../../iterators/reverse_iterator.hpp"
# include "../../algorithm.hpp"
# include "../../traits.hpp"
# include <memory>
# include <functional>

namespace ft
{

template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
			> class map
{
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************         types          ***********************/
		/**********************************************************************/
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type,mapped_type>		value_type;
		typedef Compare										key_compare;
		
		//template <class Key, class T, class Compare, class Alloc>
		class value_compare
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef ft::mapIterator<value_type>							iterator;
		typedef ft::mapIterator<const value_type>					const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t												size_type;

		private:
			typedef ft::tree<value_type, allocator_type, value_compare>		avl;
			typedef typename avl::node_type									node_type;
			typedef typename avl::const_node_type							const_node_type;
			typedef typename allocator_type:: template rebind<avl>::other	alloc_tree;

			alloc_tree		_alloc;
			key_compare		_compare;
			avl*			_data;
			allocator_type	_alloc_pair;

			
		public:

		~map() {
			_alloc.destroy(_data);
			_alloc.deallocate(_data, 1);
		}
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : _alloc(alloc_tree()), _compare(comp), _data(_alloc.allocate(1) ), _alloc_pair(alloc)
		{
			_alloc.construct(_data, avl(value_compare(_compare), _alloc_pair));
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _alloc(alloc_tree()), _compare(comp), _data(_alloc.allocate(1) ), _alloc_pair(alloc)
		{
			_alloc.construct(_data, avl(value_compare(_compare), _alloc_pair));
			for (InputIterator it = first; it != last; it++)
				this->_data->add(*it);
		}
		map (const map& x) : _alloc(x._alloc), _compare(x._compare), _data(_alloc.allocate(1) ), _alloc_pair(allocator_type())
		{
			_alloc.construct(_data, avl(value_compare(x._compare), _alloc_pair));
			*this = x;
		}
		map& operator= (const map& x) {
			if (&(*this) != &x) {
				clear();
				*(this->_data) = *(x._data);
			}
			return (*this);
		}
		iterator begin() {
			return (iterator(_data->minimum()));
		}
		const_iterator begin() const {
			return (const_iterator((Node<const value_type>*) (_data->minimum())));
		}
		iterator end() {
			return (iterator(_data->getEnd()));
		}
		const_iterator end() const {
			return (const_iterator((Node<const value_type>*) (_data->getEnd())));
		}
		reverse_iterator rbegin() {
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(this->end()));
		}
		reverse_iterator rend() {
			return (reverse_iterator(this->begin()));
		}
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(this->begin()));
		}
		bool empty() const {
			return (size() == 0);
		}
		size_type size() const {
			return (_data->size());
		}
		size_type max_size() const {
			return (this->_data->max_size());
		}
		mapped_type& operator[] (const key_type& k) {
			value_type val(k, mapped_type());
			this->_data->add(val);
			node_type*	node = this->_data->find_value(val);
			return (node->_content->second);
		}
		ft::pair<iterator,bool> insert (const value_type& val) {
			node_type*	node = this->_data->find_value(val);
			this->_data->add(val);
			return ft::pair<iterator,bool>(iterator(node), node == NULL);
		}
		iterator insert (iterator position, const value_type& val) {
			position = iterator(NULL);
			this->_data->add(val);
			node_type*	node = this->_data->find_value(val);
			return iterator(node);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
			for (InputIterator it = first; it != last; it++) {
				insert(*it);
			}
		}
		void erase (iterator position) {
			this->_data->remove(*position);
		}
		size_type erase (const key_type& k) {
			value_type val(k, mapped_type());
			return this->_data->remove(val);
		}
		void erase (iterator first, iterator last) {
			for (iterator it = first; it != last;) {
				iterator tmp(it);
				++tmp;
				erase(it);
				it = tmp;
			}
		}

		void swap (map& x) {
			avl*	tmpAvl = x._data;
			x._data = this->_data;
			this->_data = tmpAvl;
		}

		void clear() {
			_data->empty();
		}
		key_compare key_comp() const {
			return (key_compare());
		}
		value_compare value_comp() const {
			return (value_compare(key_compare()));
		}
		iterator find (const key_type& k) {
			node_type*	tmp = _data->find_value(k);
			if (tmp)
				return (iterator(tmp));
			return end();
		}
		const_iterator find (const key_type& k) const {
			node_type*	tmp = _data->find_value(k);
			if (tmp)
				return (const_iterator((Node<const value_type>*)tmp));
			return (end());
		}
		size_type count (const key_type& k) const {
			if (_data->find_value(k) != NULL)
				return 1;
			return 0;
		}
		iterator lower_bound (const key_type& k) {
			iterator it;
			for (iterator it = begin(); it != end(); it++)
			{
				if (!_compare((*it).first, k))
					return it;
			}
			return begin();
		}
		const_iterator lower_bound (const key_type& k) const {
			const_iterator(lower_bound(k));
		}
		iterator upper_bound (const key_type& k) {
			iterator it;
			for (it = begin(); it != end(); it++)
			{
				if (_compare(k, (*it).first))
					return it;
			}
			return it;
		}
		const_iterator upper_bound (const key_type& k) const {
			const_iterator(upper_bound(k));
		}
		
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}
		ft::pair<iterator,iterator>             equal_range (const key_type& k) {
			return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}
		
		allocator_type get_allocator() const {
			return (allocator_type());
		}

		friend bool operator== (const map& lhs, const map& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			node_type*	node_lhs = lhs._data->minimum();
			node_type*	node_rhs = rhs._data->minimum();
			size_type	i = 0;
			while (i < lhs.size()) {
				if (*(node_lhs->_content) != *(node_rhs->_content))
					return false;
				++i;
				node_lhs = node_type::next(node_lhs);
				node_rhs = node_type::next(node_rhs);
			}
			return true;
		}
		friend bool operator!= (const map& lhs, const map& rhs) {
			return (!(lhs == rhs));
		}
		friend bool operator<  (const map& lhs, const map& rhs) {
			map	lhsCpy	= lhs;
			map	rhsCpy	= rhs;
			return ft::lexicographical_compare(lhsCpy.begin(), lhsCpy.end(), rhsCpy.begin(), rhsCpy.end());
		}
		friend bool operator<= (const map& lhs, const map& rhs) {
			return !(rhs<lhs);
		}
		friend bool operator>  (const map& lhs, const map& rhs) {
			return rhs < lhs;
		}
		friend bool operator>= (const map& lhs, const map& rhs) {
			return !(lhs<rhs);
		}
};

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
	x.swap(y);
}


} // namespace ft

#endif