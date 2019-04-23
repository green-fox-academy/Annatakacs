//
// Created by Takacs Anna on 2019-04-23.
//

#include "Student.h"

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) : Person(name, age, gender)
{
    _previousOrganization = previousOrganization;
    _skippedDays = 0;
}

Student::Student()
{
    _previousOrganization = "The School of Life";
}

void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::introduce()
{
    std::cout << "Hi, I'm " << getname() << " , a " << getage() << " year old " << getgenderAsString() << " from " << _previousOrganization << " who skipped " << _skippedDays << "days from the course already." << std::endl;
}

void Student::skipDays(int numberOfDays)
{
    _skippedDays += numberOfDays;
}