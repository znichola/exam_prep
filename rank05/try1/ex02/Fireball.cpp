/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:55:49 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 13:04:17 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball() :
	ASpell("Fireball", "burnt to a crisp")
	{}

Fireball::Fireball(const Fireball &other) :
	ASpell(other._name, other._effects)
	{}

Fireball::~Fireball() {}

Fireball *Fireball::clone() const {	return new Fireball(); }
