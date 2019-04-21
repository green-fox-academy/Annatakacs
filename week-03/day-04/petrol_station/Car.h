//
// Created by Takacs Anna on 2019-04-18.
//

#ifndef PETROL_STATION_CAR_H
#define PETROL_STATION_CAR_H


class Car {
public:
    Car(int capacity, int gasAmount);

    void setgasAmount(int gasAmount);

    void setcapacity(int capacity);

    int getgasAmount();

    int getcapacity();

    bool isFull();

    void fill();


private:
    int _gasAmount;
    int _capacity;
};


#endif //PETROL_STATION_CAR_H
