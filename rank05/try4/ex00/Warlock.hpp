#pragma once

#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::endl;

class Warlock
{
	private:
	string _name;
	string _title;

	Warlock();
	Warlock(const Warlock &o);
	Warlock & operator=(const Warlock &o);

	public:
	Warlock(const string &name, const string &title) : _name(name), _title(title)
	{ cout << _name << ": This looks like another boring day." << endl; }

	~Warlock()
	{ cout << _name << ": My job here is done!" << endl; }

	const string & getName() const { return _name; }
	const string & getTitle() const { return _title; }

	void setTitle(const string &title) { _title = title; }

	void introduce() const
	{ cout << _name << ": I am " << _name << ", " << _title << "!" << endl; }

};
