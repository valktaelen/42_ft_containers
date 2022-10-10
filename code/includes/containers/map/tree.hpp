/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:10:02 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/28 19:42:35 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * https://www.labri.fr/perso/maylis/ASDF/supports/notes/AVL.html
 */

#ifndef FT_TREE
# define FT_TREE

# include <iostream>
# include <cstddef>
# include "pair.hpp"

namespace ft
{

template <class contentOfNodes>
class Node
{
	public :
		typedef contentOfNodes					pair_type;
		typedef typename pair_type::first_type	key_type;
		typedef typename pair_type::second_type	value_type;

		pair_type*	_content;
		Node*		_parent;
		Node*		_left;
		Node*		_right;
		Node*		_end;

		Node(pair_type* content) {
			this->_content = content;
			this->_parent = this->_left = this->_right = NULL;
		}

		Node(pair_type* content, Node* dad) {
			this->_content = content;
			this->_parent = dad;
			this->_left = this->_right = NULL;
		}

		~Node() {}

		pair_type&	getContent() const {
			return (*(this->_content));
		}

		pair_type*	getPtrContent() const {
			return (this->_content);
		}

		void	changeContent(pair_type* content) {
			this->_content = content;
		}

		static Node*	next(const Node* elem) {
			if (elem->_right)
				return Node::minimum(elem->_right);
			Node*	tmp = elem->_parent;
			Node*	elemTmp = const_cast<Node*>(elem);
			while (tmp && elemTmp != tmp->_left) {
				tmp = tmp->_parent;
				elemTmp = elemTmp->_parent;
			}
			if (!tmp)
				return elem->_end;
			return tmp;
		}

		static Node*	prev(const Node* elem) {
			if (elem->_left)
				return Node::maximum(elem->_left);
			Node*	tmp = elem->_parent;
			Node*	elemTmp = const_cast<Node*>(elem);
			if (tmp && tmp->_end == elem)
				return tmp;
			while (tmp && elemTmp != tmp->_right) {
				tmp = tmp->_parent;
				elemTmp = elemTmp->_parent;
			}
			return tmp;
		}

		static Node* maximum(const Node* tree) {
			if (tree == NULL)
				return NULL;
			Node*	tmp = const_cast<Node*>(tree);
			while (tmp && tmp->_right != NULL)
				tmp = tmp->_right;
			return tmp;
		}

		static Node* minimum(const Node* tree) {
			if (tree == NULL)
				return NULL;
			Node*	tmp = const_cast<Node*>(tree);
			while (tmp && tmp->_left != NULL)
				tmp = tmp->_left;
			return tmp;
		}

	private:

		Node&	operator=(const Node& copy) {
			(this->_content) = (copy._content);
		}

		Node() {
			this->_content = this->_parent = this->_left = this->_right = NULL;
		}

}; // class Node


template <class contentOfNodes, class Alloc, class Compare>
class tree
{
	public:
		typedef Node<contentOfNodes>			node_type;
		typedef Node<const contentOfNodes>		const_node_type;
		typedef typename node_type::pair_type	pair_type;
		typedef typename node_type::key_type	key_type;
		typedef typename node_type::value_type	value_type;
		typedef size_t							size_type;
	private:
		typedef typename Alloc:: template rebind<node_type>::other	alloc_node;

		node_type*	_root;
		size_type	_size;
		Compare		_comp;
		Alloc		_alloc;
		node_type	_end;
		alloc_node	_alloc_node;

		void	destroyNodeContent(node_type*	node) {
			if (node->getPtrContent())
				this->_alloc.destroy(node->getPtrContent());
		}

		void	kickNode(node_type*	node) {
			if (node->getPtrContent()) {
				this->destroyNodeContent(node);
				this->_alloc.deallocate(node->getPtrContent(), 1);
				node->_content = NULL;
			}
		}

		void	putNodeContent(node_type* node, const pair_type& content) {
			if (node->getPtrContent())
				this->destroyNodeContent(node);
			else
				node->_content = this->_alloc.allocate(1);
			std::cout<<"test"<<std::endl;
			this->_alloc.construct(node->_content, content);
		}

		void printUtil(node_type* tree, size_type n = 0) {
			if (tree != NULL)
			{
				printUtil(tree->_left, n + 1);
				for (size_type i = 0; i < n; i++)
				{
					std::cout << "    ";
				}
				std::cout << tree->_content->first << " " << tree->_content->second << std::endl;
				printUtil(tree->_right, n + 1);
			}
		}

		void destroy_tree(node_type* tree) {
			if (tree != NULL)
			{
				destroy_tree(tree->_left);
				destroy_tree(tree->_right);
				kickNode(tree);
				_alloc_node.destroy(tree);
				_alloc_node.deallocate(tree, 1);
				//delete tree;
			}
		}

		size_type depth_tree(const node_type* tree) const {
			if (tree == NULL)
				return 0;
			size_type prof_left = depth_tree(tree->_left);
			size_type prof_droit = depth_tree(tree->_right);
			return 1 + ((prof_left > prof_droit) ? prof_left : prof_droit);
		}

		node_type* find_father(const contentOfNodes& element) const {
			if (_size == 0)
				return NULL;

			node_type* father = _root;
			int father_find = 0;
			do
			{
				if (this->_comp(element, father->getContent()) && father->_left != NULL)
					father = father->_left;
				else if (this->_comp(father->getContent(), element) && father->_right != NULL)
					father = father->_right;
				else
					father_find = 1;
			} while (!father_find);
			return father;
		}

		void balance_tree(node_type* tree)
		{
			if (tree == NULL)
				return;
			int balance__root = depth_tree(tree->_right) - depth_tree(tree->_left);
			if (balance__root == 2)
			{
				int balance__right = depth_tree(tree->_right->_right) - depth_tree(tree->_right->_left);
				if (balance__right == -1)
					rotate_right(tree->_right);
				rotate_left(tree);
			}
			else if (balance__root == -2)
			{
				int balance__left = depth_tree(tree->_left->_right) - depth_tree(tree->_left->_left);
				if (balance__left == 1)
					rotate_left(tree->_left);
				rotate_right(tree);
			}
			balance_tree(tree->_parent);
		}

		void rotate_left(node_type* tree)
		{
			if (tree == NULL)
				return;

			node_type* _rightroit = tree->_right;
			if (tree->_parent != NULL) {
				if (tree->_parent->_right == tree)
					tree->_parent->_right = _rightroit;
				else
					tree->_parent->_left = _rightroit;
			}
			_rightroit->_parent = tree->_parent;

			if (_rightroit->_left != NULL)
				_rightroit->_left->_parent = tree;
			tree->_right = _rightroit->_left;

			tree->_parent = _rightroit;
			_rightroit->_left = tree;
			if (tree == _root)
				_root = _rightroit;
		}
		void rotate_right(node_type* tree)
		{
			if (tree == NULL)
				return;

			node_type* _leftauche = tree->_left;
			if (tree->_parent != NULL) {
				if (tree->_parent->_left == tree)
					tree->_parent->_left = _leftauche;
				else
					tree->_parent->_right = _leftauche;
			}
			_leftauche->_parent = tree->_parent;

			if (_leftauche->_right != NULL)
				_leftauche->_right->_parent = tree;
			tree->_left = _leftauche->_right;

			tree->_parent = _leftauche;
			_leftauche->_right = tree;
			if (tree == _root)
				_root = _leftauche;
		}
		tree() {
			throw ("Need Compare in param");
		}

	public :
		tree(const Compare& cmp, const Alloc& alloc) : _root(NULL), _size(0), _comp(cmp), _alloc(alloc), _end(node_type(NULL)), _alloc_node(alloc_node()) {}
		tree(const tree& cpy) : _root(NULL), _size(0), _comp(cpy._comp), _alloc(cpy._alloc), _end(node_type(NULL)), _alloc_node(alloc_node()) {
			node_type*	tmp = cpy.minimum();
			while (tmp)
			{
				add(*(tmp->_content));
				if (tmp->_end == node_type::next(tmp))
					break;
				tmp = node_type::next(tmp);
			}
		}
		tree& operator = (const tree& cpy) {
			empty();
			node_type*	tmp = cpy.minimum();
			while (tmp)
			{
				add(*(tmp->_content));
				if (tmp->_end == node_type::next(tmp))
					break;
				tmp = node_type::next(tmp);
			}
			return *this;
		}

		~tree() {
			empty();
		}

		void empty() {
			if (_size > 0)
			{
				destroy_tree(_root->_left);
				destroy_tree(_root->_right);
				kickNode(_root);
				_alloc_node.destroy(_root);
				_alloc_node.deallocate(_root, 1);
				//delete _root;
				_root = NULL;
				_size = 0;
			}
		}
		node_type* find_value(const contentOfNodes& element) const {
			node_type* noeud = _root;
			while (noeud != NULL && !(noeud->getContent().first == element.first))
				if (this->_comp(element, noeud->getContent()))
					noeud = noeud->_left;
				else
					noeud = noeud->_right;
			return noeud;
		}
		node_type* find_value(const key_type& key) const {
			pair_type	tmp(key, value_type());
			return find_value(tmp);
		}

		node_type*	getEnd() {
			return &_end;
		}

		size_type size() const {
			return _size;
		}

		int add(const contentOfNodes& element) {
			if (present(element))
				return 0;

			node_type* father = find_father(element);
			pair_type* tmp = this->_alloc.allocate(1, this->_root);
			this->_alloc.construct(tmp, element);
			node_type* nouveau = _alloc_node.allocate(1, _root);
			_alloc_node.construct(nouveau, node_type(tmp, father));
			//node_type* nouveau = new node_type(tmp, father);
			nouveau->_end = &_end;
			if (nouveau == NULL)
				return 0;

			if (father == NULL)
				_root = nouveau;
			else if (this->_comp(element, father->getContent()))
				father->_left = nouveau;
			else
				father->_right = nouveau;
			++_size;
			balance_tree(nouveau);
			_end._parent = maximum();
			return 1;
		}
		int remove(const contentOfNodes& element) {
			node_type* noeud = find_value(element);
			if (noeud == NULL)
				return 0;
			node_type* parent = noeud->_parent;
			node_type* remplacant = node_type::maximum(noeud->_left);
			if (remplacant == NULL)
			{
				if (noeud == _root)
					_root = noeud->_right;
				else if (noeud->_parent->_left == noeud)
					noeud->_parent->_left = noeud->_right;
				else
					noeud->_parent->_right = noeud->_right;
				if (noeud->_right != NULL)
					noeud->_right->_parent = noeud->_parent;
			}
			else
			{
				_alloc.destroy(noeud->_content);
				_alloc.construct(noeud->_content, remplacant->getContent());
				//noeud->changeContent(remplacant->getPtrContent());
				if (remplacant->_parent->_left == remplacant)
					remplacant->_parent->_left = remplacant->_left;
				else
					remplacant->_parent->_right = remplacant->_left;
				if (remplacant->_left != NULL)
					remplacant->_left->_parent = remplacant->_parent;
				noeud = remplacant;
			}
			kickNode(noeud);
			_alloc_node.destroy(noeud);
			_alloc_node.deallocate(noeud, 1);
			//delete noeud;
			--_size;
			balance_tree(parent);
			_end._parent = maximum();
			return 1;
		}

		int present(const contentOfNodes& element) const {
			return (find_value(element) != NULL);
		}

		node_type* minimum() const {
			return node_type::minimum(_root);
		}

		node_type* maximum() const {
			return node_type::maximum(_root);
		}

		void print() {
			std::cout << "########### Print ##############" << std::endl;
			printUtil(_root);
			std::cout << "################################" << std::endl;
		}

		size_type	max_size() {
			return (this->_alloc.max_size());
		}

}; // class tree

} // namespace ft

#endif
