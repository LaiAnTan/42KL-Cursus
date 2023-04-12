#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::getline;

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{
	cout << "ShrubberyCreationForm: Default constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target): AForm("shrubbery creation", target, 147, 137)
{
	cout << "ShrubberyCreationForm: Constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf): AForm(scf)
{
	cout << "ShrubberyCreationForm: Copy constructor called" << endl;
	*this = scf;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &scf)
{
	cout << "ShrubberyCreationForm: Copy assignment operator called" << endl;
	if (this == &scf)
		return (*this);
	this->name = scf.getName();
	this->target = scf.getTarget();
	this->signedBool = scf.getSigned();
	this->signGrade = 145;
	this->execGrade = 137;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "ShrubberyCreationForm: Destructor called" << endl;
}

void	ShrubberyCreationForm::action()
{
	string	line;
	fstream infile;
	fstream	outfile;

	infile.open("tree.txt", fstream::in);
	outfile.open(target.append("_shrubbery").c_str(), fstream::out);

	while (getline(infile, line))
		outfile << line << endl;
	infile.close();
	outfile.close();
	cout << "ShrubberyCreationForm: Shrubbery created" << endl;

}