#include "ShrubberyCreationForm.hpp"
#include <string>
#include <cstring>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm",145,137),target("default")
{
    std::cout << "ShrubberyCreationForm Default Constructor called " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called " << this->gettarget()<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &other):AForm("ShrubberyCreationForm",145,137),target(other.gettarget())
{
    std::cout << "ShrubberyCreationForm Copy Constructor called " << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const name):AForm("ShrubberyCreationForm",145,137),target(name)
{
     std::cout << "ShrubberyCreationForm Name Constructor called " << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm assignation operator called " << std::endl;
    if(this!=&other)
    {
        AForm::operator=(other);//ka ardyoq kariqy
    }
    return(*this);
}

std::string const& ShrubberyCreationForm:: gettarget() const
{
    return(this->target);
}

void ShrubberyCreationForm::execute_action() const
{
    std::ofstream file((target + "_shrubbery").c_str());
    if(file.is_open())
    {
    file << "    /\\    \n";
    file << "   /  \\   \n";
    file << "  /++++\\  \n";
    file << " /  ++  \\ \n";
    file << "/________\\\n";
    file << "    ||    \n";

        file.close();
    }

}
