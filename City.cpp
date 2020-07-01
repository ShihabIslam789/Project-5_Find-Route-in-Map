// Created by Shihab Islam
// Created on June 30, 2020
// Implementation of city

#include <iostream>
#include <vector>
#include <string>
#include "city.hpp"


/**
 Default constructor is parameterized
**/
City::City(std::string name) : city_name_(name) {};

/**
	@post all pointers in the 'adjacent' vector will be set to nullptr
**/
City::~City() {
	for (int i = 0; i < adjacent_.size(); ++i)
	{
		adjacent_[i] = nullptr;
	}
};

/** returns city_name_ **/
std::string City::getName()const {
	return city_name_;
};

/** returns adjacent_ variable contains pointers to the cities that are	adjacent to the current city **/
std::vector<City*> City::getAdjacent()const {
	return adjacent_;
};

/** returns  'visited_' **/
bool City::getVisited()const {
	return visited_;
};

/** Add city pointer to adjacent vector
 @post is the pointer  not nullptr then new city will be added
**/
void City::addAdjacent(City* city_address) {
	if (!alreadyAdjacent(city_address))adjacent_.push_back(city_address);
};

/** returns negate 'Visited_' **/
void City::setVisited(const bool val) {
	visited_ = val;
};




/** Returns bool after traversing the 'adjacent_' vector
	@return true if address is found and false if not found or nullptr
**/
bool City::alreadyAdjacent(City* city) {
	for (int i = 0; i < adjacent_.size(); ++i) {
		if (adjacent_[i] == city)return true;
	}
	return false;
};