/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:18:14 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 13:02:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#include <string>

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	protected:
	std::string _type;

	public:
	BrickWall();
	virtual ~BrickWall();
	BrickWall(const BrickWall &other);

	BrickWall *clone() const;
};

#endif
