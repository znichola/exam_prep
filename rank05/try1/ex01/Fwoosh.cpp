/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:14:52 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:47:40 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

Fwoosh::Fwoosh() :
	ASpell("Fwoosh", "fwoooshed")
	{}

Fwoosh::Fwoosh(const Fwoosh &other) :
	ASpell(other._name, other._effects)
	{}

Fwoosh::~Fwoosh() {}

Fwoosh *Fwoosh::clone() const {	return new Fwoosh(); }
