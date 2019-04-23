//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GREEN_FOX_COHORT_H
#define GREEN_FOX_COHORT_H

#include <iostream>
#include <vector>
#include "Student.h"
#include "Mentor.h"

class Cohort {
public:
    Cohort(std::string name);

    void addStudent(Student *myStudent);

    void addMentor(Mentor *myMentor);

    void info();

private:
    std::string _name;
    std::vector<Student *> _students;
    std::vector<Mentor *> _mentors;

};

#endif //GREEN_FOX_COHORT_H
