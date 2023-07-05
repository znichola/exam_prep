/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:54:36 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 13:08:38 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

#include <string>

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
	Polymorph();
	~Polymorph();
	Polymorph(const Polymorph &other);

	Polymorph *clone() const;
};

#endif
