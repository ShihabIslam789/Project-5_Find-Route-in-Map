// Created by Shihab Islam
// Created on June 30, 2020
// Implementation of city

#include "City.hpp"
#include <string>


//Default Constructor
City::City() :name_(""), visited_(false) {
}

//Parameterized Constructor 
//creates city object with the gvien name
//@param the name of the City object 
//@param the visit status of the City object 
//returns  a created city object
City::City(std::string name) :name_(name), visited_(false) {
}


//accessor function
//Returns visited_ if the city has indeed been visited 
bool City::getVisited() const {
	return visited_;
}

//accessor function
//Returns city_ name once visted
std::string City::getName() const {
	return name_;
}

// Returns the adjacent city that has or needs to be visted
//returns adjacentCities of the City 
std::vector<City*> City::getAdjacentCities() {
	return adjacentCities;
}


//mutator function
// returns  visited_ variable to status
//@param status is stored in visited_. 
void City::setVisited(bool status) {
	visited_ = status;
}

//Changes the name_ to name.
//@param  name of city
void City::setName(std::string name) {
	name_ = name;
}

//Adds a City to Adjacent
//@pre name nonempty
//@param pointer to cities
void City::addAdjacentCity(City* name) {
	adjacentCities.push_back(name);
}

//Checks forany not-visited adjacent cities.
bool City::notVisitedAdjacentCities() {
	for (int i = 0; i < adjacentCities.size(); i++) {
		if (!adjacentCities[i]->getVisited()) {
			return true;
		}
	}
	return false;
}