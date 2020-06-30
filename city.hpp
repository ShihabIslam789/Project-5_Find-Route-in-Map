
#include "City.hpp"
#include <string>


//Default Constructor
City::City() :name_(""), visited_(false) {
}

//Parameterized Constructor 
//creates city object with given name
//@pre none
//@param name the name of the City object 
//@param visited the visit status of the City object 
//@post creates city object
City::City(std::string name) :name_(name), visited_(false) {
}


//accessor 
//Returns if the City has been visited.
//@pre none
//@return visited_  value 
bool City::getVisited() const {
	return visited_;
}

//accessor 
//Returns the City's name.
//@pre has to have name
//@return name_ of the City 
std::string City::getName() const {
	return name_;
}

// Returns  adjacentCities.
//@pre adjacentCities.size() greater than 0.
//@return adjacentCities of the City 
std::vector<City*> City::getAdjacentCities() {
	return adjacentCities;
}


//mutator
//Changes visited_ to status.
//@pre status == true || status == false
//@param status to be stored in visited_. 
void City::setVisited(bool status) {
	visited_ = status;
}

//Changes the name_ to name.
//@pre nonempty name
//@param name name of city
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