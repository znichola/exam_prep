/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:20:15 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 13:02:21 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall() :
	ATarget("Inconspicuous Red-brick Wall")
	{}

BrickWall::BrickWall(const BrickWall &other) :
	ATarget(other._type)
	{}

BrickWall::~BrickWall() {}

BrickWall *BrickWall::clone() const { return new BrickWall(); }
