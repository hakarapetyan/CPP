#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main()
{
    Animal *index[20];
    for(int i =0;i<10;i++)
        index[i]=new Dog();
     for(int j =10;j<20;j++)
        index[j]=new Cat();
    for(int l = 0;l < 20; l++)
        index[l]->makeSound(); 
    for (int k =0;k<20;k++)
        delete index[k];
}