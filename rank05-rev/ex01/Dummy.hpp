#ifndef DUMMY
# define DUMMY

#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
	Dummy();
	~Dummy();

	virtual ATarget * clone() const;
};

#endif
