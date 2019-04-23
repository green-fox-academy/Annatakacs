//
// Created by Takacs Anna on 2019-04-23.
//

#include "Cohort.h"

Cohort::Cohort(std::string name)
{
    _name = name;
}

void Cohort::addStudent(Student *myStudent)
{
    _students.push_back(myStudent);
}

void Cohort::addMentor(Mentor *myMentor)
{
    _mentors.push_back(myMentor);
}

void Cohort::info()
{
    std::cout << "The " << _name << " cohort has " << _students.size() << " students and " << _mentors.size()
              << " mentors." << std::endl;
}