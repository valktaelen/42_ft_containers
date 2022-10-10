/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:20:59 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/16 12:56:53 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK
# define FT_STACK

#include "./vector/vector.hpp"


namespace ft {

template <class T, class Container = ft::vector<T> >
class stack
{
	public:
		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************         types          ***********************/
		/**********************************************************************/

		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		/**********************************************************************/
		/***********************         Member         ***********************/
		/***********************        functions       ***********************/
		/**********************************************************************/

		explicit stack (const container_type& ctnr = container_type())
		{
			this->c = ctnr;
		}

		bool empty() const
		{
			return (this->c.empty());
		}

		size_type size() const
		{
			return (this->c.size());
		}

		value_type& top()
		{
			return (this->c.back());
		}

		const value_type& top() const
		{
			return (this->c.back());
		}

		void push (const value_type& val)
		{
			this->c.push_back(val);
		}

		void pop()
		{
			this->c.pop_back();
		}

	/**************************************************************************/
	/*************************       Non member       *************************/
	/*************************        functions       *************************/
	/**************************************************************************/

	//template <class T, class Container> friend
	friend bool operator== (const stack& lhs, const stack& rhs)
	{
		return (lhs.c == rhs.c);
	}

	//template <class T, class Container> friend
	friend bool operator!= (const stack& lhs, const stack& rhs)
	{
		return !(lhs == rhs);
	}

	//template <class T, class Container> friend
	friend bool operator<  (const stack& lhs, const stack& rhs)
	{
		return (lhs.c < rhs.c);
	}

	//template <class T, class Container> friend
	friend bool operator<= (const stack& lhs, const stack& rhs)
	{
		return !(lhs > rhs);
	}

	//template <class T, class Container> friend
	friend bool operator>  (const stack& lhs, const stack& rhs)
	{
		return (lhs.c > rhs.c);
	}

	//template <class T, class Container> friend
	friend bool operator>= (const stack& lhs, const stack& rhs)
	{
		return !(lhs < rhs);
	}

	protected:
		//typedef typename container_type::iterator container_iterator;
		container_type	c;
};

}

#endif