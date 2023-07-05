/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:20:15 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:48:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

Dummy::Dummy() :
	ATarget("Target Practice Dummy")
	{}

Dummy::Dummy(const Dummy &other) :
	ATarget(other._type)
	{}

Dummy::~Dummy() {}

Dummy *Dummy::clone() const { return new Dummy(); }
