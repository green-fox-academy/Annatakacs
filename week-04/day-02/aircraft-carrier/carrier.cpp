#include "carrier.h"
#include <sstream>

Carrier::Carrier(int initalAmmo, int healthPoints, int storeOfAmmo)
{
    _initialAmmo = initalAmmo;
    _healthPoints = healthPoints;
    _storeOfAmmo = storeOfAmmo;
}

void Carrier::add(Aircraft *aircraft)
{
    _aircrafts.push_back(aircraft);
}

void Carrier::fill()
{
    int ammoNeeded = 0;
    for (int j = 0; j < _aircrafts.size(); ++j) {
        ammoNeeded += _aircrafts.at(j)->neededAmmo();
    }
    try {
        if (_storeOfAmmo == 0) {
            throw 1;
        }
        if (_storeOfAmmo < ammoNeeded) {
            for (int i = 0; i < _aircrafts.size(); ++i) {
                _storeOfAmmo = _aircrafts.at(i)->refillPriority(_storeOfAmmo);
            }
        } else {
            for (int i = 0; i < _aircrafts.size(); ++i) {
                _storeOfAmmo = _aircrafts.at(i)->refill(_storeOfAmmo);
            }
        }
    } catch (int &e) {
        std::cerr << "We are out of ammo!" << std::endl;
    }
}


void Carrier::fight(Carrier *carrier)
{
    int damage = 0;
    for (int i = 0; i < _aircrafts.size(); ++i) {
        damage += _aircrafts.at(i)->fight();
    }
    carrier->_healthPoints -= damage;
}

std::string Carrier::getStatus()
{
    std::string stream;
    int damage = 0;
    for (int i = 0; i < _aircrafts.size(); ++i) {
        damage += _aircrafts.at(i)->allDamage();
    }
    if (_healthPoints > 0) {
        stream = "HP: " + std::to_string(_healthPoints) + ", Aircraft count: " + std::to_string(_aircrafts.size()) +
                 ", Ammo Storage: " + std::to_string(_storeOfAmmo) + ", Total damage: " + std::to_string(damage) +
                 "\n";
        for (int i = 0; i < _aircrafts.size(); ++i) {
            stream += _aircrafts.at(i)->getStatus() + "\n";
        }
    } else {
        stream = "It's dead, Jim :( \n";
    }
    return stream;
}