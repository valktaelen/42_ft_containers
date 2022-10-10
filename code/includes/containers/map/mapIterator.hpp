/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:52:57 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/29 01:49:54 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_ITERATOR
# define FT_MAP_ITERATOR

# include "../../iterators/category.hpp"
# include "tree.hpp"
# include "tree.hpp"
# include <cstddef>

namespace ft
{

template <class PairContent>
class mapIterator
{
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************         types          ***********************/
		/**********************************************************************/
		typedef PairContent						value_type;
		typedef ptrdiff_t						difference_type;
		typedef PairContent*					pointer;
		typedef PairContent&					reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef ft::Node<PairContent>			node_type;
		typedef ft::Node<PairContent>*			nodePointer;
	private:
		/**********************************************************************/
		/***********************       Attributes       ***********************/
		/**********************************************************************/
		typedef ft::Node<const PairContent>*	const_nodePointer;
		nodePointer	_nodePtr;
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************       functions        ***********************/
		/**********************************************************************/
		mapIterator() : _nodePtr(NULL) {}
		mapIterator(const mapIterator&	ref) : _nodePtr(ref._nodePtr) {}
		template <class X>
		mapIterator(const mapIterator<X>&	ref) : _nodePtr((nodePointer)(ref.base())) {}
		template <class X>
		mapIterator(ft::Node<X>*	ptr) : _nodePtr(ptr) {}
		mapIterator(nodePointer	ptr) : _nodePtr(ptr) {}
		~mapIterator() {}

		nodePointer	base() const {return _nodePtr;}

		mapIterator&	operator=(const mapIterator& ref) {
			if (this != &ref)
				this->_nodePtr = ref._nodePtr;
			return (*this);
		}

		mapIterator&	operator++(void) { 
			this->_nodePtr = node_type::next(this->_nodePtr);
			return (*this);
		}

		mapIterator	operator++(int) {
			mapIterator	tmp(*this);
			this->operator++();
			return (tmp);
		}

		template <class X>
		bool	operator==(const mapIterator<X>& it) const {
			return (it.base()->_content == this->_nodePtr->_content);
		}

		template <class X>
		bool	operator!=(const mapIterator<X>& it) const {
			return (it.base()->_content != this->_nodePtr->_content);
		}

		reference	operator*() const {
			return (*(this->_nodePtr->_content));
		}

		pointer operator->() const {
			return(&(operator*()));
		}

		mapIterator&	operator--(void) {
			this->_nodePtr = node_type::prev(this->_nodePtr);
			return (*this);
		}

		mapIterator	operator--(int) {
			mapIterator	tmp(*this);
			this->operator--();
			return (tmp);
		}
}; // class mapIterator

} // namespace ft

#endif