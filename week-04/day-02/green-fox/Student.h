//
// Created by Takacs Anna on 2019-04-23.
//

#ifndef GREEN_FOX_STUDENT_H
#define GREEN_FOX_STUDENT_H

#include <iostream>
#include "Person.h"


class Student : public Person {
public:
    Student(std::string name, int age, Gender gender, std::string previousOrganization);

    Student();

    void getGoal() override;

    void introduce() override;

    void skipDays(int numberOfDays);

private:
    std::string _previousOrganization;
    int _skippedDays;

};


#endif //GREEN_FOX_STUDENT_H
