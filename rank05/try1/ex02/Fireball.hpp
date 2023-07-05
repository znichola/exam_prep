/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:54:36 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 13:04:07 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#include <string>

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
	Fireball();
	~Fireball();
	Fireball(const Fireball &other);

	Fireball *clone() const;
};

#endif
