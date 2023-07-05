/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:13:19 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:55:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include <string>

class ATarget;
class ASpell;
class Dummy;
class Fwoosh;
class Warlock;

class Fwoosh : public ASpell
{
	public:
	Fwoosh();
	~Fwoosh();
	Fwoosh(const Fwoosh &other);

	Fwoosh *clone() const;
};

#endif
