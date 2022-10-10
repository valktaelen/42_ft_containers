/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:07:23 by aartiges          #+#    #+#             */
/*   Updated: 2022/09/08 04:10:32 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_CATEGORY
# define FT_ITERATOR_CATEGORY

namespace ft
{
	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag {};
	struct	bidirectional_iterator_tag {};
	struct	random_access_iterator_tag {};
} // namespace ft

#endif
