/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:13:19 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:47:51 by znichola         ###   ########.fr       */
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
	protected:
	std::string _name;
	std::string _effects;

	public:
	Fwoosh();
	~Fwoosh();
	Fwoosh(const Fwoosh &other);

	Fwoosh *clone() const;
};

#endif
