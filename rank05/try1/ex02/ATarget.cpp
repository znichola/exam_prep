/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:27:27 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:04:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

#include <ostream>

ATarget::ATarget() {}
ATarget::ATarget(const ATarget &other) :
	_type(other._type)
	{}
ATarget::~ATarget() {}

ATarget::ATarget(const std::string &type) :
	_type(type)
	{}

ATarget &ATarget::operator=(const ATarget &other)
{
	_type = other._type;
	return *this;
}


const std::string &ATarget::getType() const { return _type; }

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " had been " << spell.getEffects() << "!" << std::endl;
}
