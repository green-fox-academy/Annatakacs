//
// Created by Takacs Anna on 2019-04-23.
//
#include <iostream>
#include "Sponsor.h"

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) : Person(name, age, gender)
{
    _hiredStudents = 0;
    _company = company;
}

Sponsor::Sponsor()
{
    _company = "Google";
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << getname() << " , a " << getage() << " year old " << getgenderAsString() << " who represents " << _company << " and hired " << _hiredStudents << " students so far." << std::endl;
}

void Sponsor::hire()
{
  _hiredStudents++;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}