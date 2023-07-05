/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:55:49 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 13:02:48 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph() :
	ASpell("Polymorph", "turned into critter")
	{}

Polymorph::Polymorph(const Polymorph &other) :
	ASpell(other._name, other._effects)
	{}

Polymorph::~Polymorph() {}

Polymorph *Polymorph::clone() const {	return new Polymorph(); }
