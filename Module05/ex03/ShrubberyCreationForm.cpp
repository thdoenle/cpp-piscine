#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("nowhere", 145, 137)
{
	std::cout << "Default SCForm made" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: AForm(src)
{
	std::cout << "Copy SCForm made" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: AForm(target, 145, 137)
{
	std::cout << target << " SCForm made" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "SCForm destroyed" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	setIsSigned(rhs.getIsSigned());
	return *this;
}

void ShrubberyCreationForm::performAction(std::string const & target) const
{
	std::string fileName = target + "_shrubbery";
	std::ofstream file(fileName.c_str());

	if (!file.is_open())
		throw FileFailedToWriteException();
	file.clear();
	file << "            .        +          .      .          ." << std::endl;
	file << "     .            _        .                    ." << std::endl;
	file << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
	file << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
	file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
	file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
	file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
	file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
	file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
	file << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
	file << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
	file << "                    \\::.  :\\/:'  /              +" << std::endl;
	file << "   .                 `.:.  /:'  }      ." << std::endl;
	file << "           .           ):_(:;   \\           ." << std::endl;
	file << "                      /:. _/ ,  |" << std::endl;
	file << "                   . (|::.     ,`                  ." << std::endl;
	file << "     .                |::.    {\\" << std::endl;
	file << "                      |::.\\  \\ `." << std::endl;
	file << "                      |:::(\\    |" << std::endl;
	file << "              O       |:::/{ }  |                  (o" << std::endl;
	file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
	file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
	file << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
}

const char * ShrubberyCreationForm::FileFailedToWriteException::what(void) const throw()
{
	return "SCFORM ERROR: File failed to write";
}