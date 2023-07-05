/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:18:14 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:47:58 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

#include <string>

class ATarget;
class ASpell;
class Dummy;
class Fwoosh;
class Warlock;

class Dummy : public ATarget
{
	protected:
	std::string _type;

	public:
	Dummy();
	virtual ~Dummy();
	Dummy(const Dummy &other);

	Dummy *clone() const;
};

#endif
