// created by Shihab Islam
// created on June 30,2020
// Routemap implementation to print the road needed to get to a destination

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>
#include "City.hpp"
#include "RouteMap.hpp"


RouteMap::RouteMap() {}; // Default constructor

RouteMap::RouteMap(std::string input_file_name) { // Paramiterized constructor
	readMap(input_file_name);
};

/** Default Destructor
	@post delete all cities stored in the map and will deallocate pointers
**/
RouteMap::~RouteMap() {
	for (int i = 0; i < cities_.size(); ++i)delete cities_[i];
	for (int i = 0; i < route_.size(); ++i)route_.pop();
};

/**
@param input_file_name of a csv file representing a route map where the first
 line is a comma-separated list of city names, and the remainder is a
 comma-separated list of city-pairs of the form A-B, indicating that B
 is adjacent to A (i.e. there is an arrow in the map going from A to B)
@post this depends on your design, the input data representing the map must
 have been stored. Adjacent cities must be stored and explored in the
 same order in which they are read from the input file
**/
bool RouteMap::readMap(std::string input_file_name) {
	std::fstream file(input_file_name);
	std::string line;
	if (file.is_open())
	{
		getline(file, line);
		makeCities(line);

		//	Read the rest of the file line by line after each comma
		while (getline(file, line)) {
			addAdjacentCities(line);
		};
		return true;
	}

	return false;
};

/**
@return a pointer to the city found at position, where
 0 <= position <= n-1, and n is the number of cities,
 and cities are stored in the same order in which they appear
 in the input file
**/
City* RouteMap::getCity(size_t position) {
	if (position >= 0 && position < cities_.size()) {
		return cities_[position];
	}
	return nullptr;
};

/**
@return true if there is a route from origin to destination, false otherwise
@post if a route is found from origin to destination, it will print it to
 standard output in the form “ORIGIN -> ... -> DESTINATION\n”
**/
bool RouteMap::isRoute(City* origin, City* destination) {
	route_.push(origin);
	origin->setVisited(true);
	City* currentCity = origin;

	while (currentCity != destination && route_.size() > 0) {
		if (nextCity(route_.top()) == nullptr) {

			route_.pop();

		}
		else if (nextCity(route_.top()) != nullptr) {

			route_.push(nextCity(route_.top()));
			route_.top()->setVisited(true);
			currentCity = route_.top();

			if (route_.top() == destination) {

				printRoute();
				return true;

			}
			
		}
		else if (route_.empty()) {
			return false;
		}
		
	};
	return false;	
};



void RouteMap::printRoute() {
	std::stack<City*> output;
	while (!route_.empty()) {
		output.push(route_.top());
		route_.pop();
	}
	while (!output.empty()) {
		if (output.size() == 1) {
			std::cout << output.top()->getName() << std::endl;
		}
		else {
			std::cout << output.top()->getName() << " -> ";
		}
		output.pop();
	}
};

/** Determine if there are adjacent cities that can be visited and return pointer
	@param City pointer to the current city currenlty at
	returns pointer to unvisited city or nullpointer if no path forward
**/
City* RouteMap::nextCity(const City* cityptr) {
	for (int i = 0; i < cityptr->getAdjacent().size(); ++i)
	{
		if (!cityptr->getAdjacent()[i]->getVisited()) return cityptr->getAdjacent()[i];
	}
	return nullptr;
};

/** Instanciate and add cities to the 'cities_' vector
	@param first line of the file
	@post All cities will be added to the 'cities_' vector
**/
void RouteMap::makeCities(const std::string fileLineOne) {
	std::stringstream line(fileLineOne);
	std::string city;
	while (getline(line, city, ',')) {
		if (!cityExists(city)) {
			City* c = new City(city);
			cities_.push_back(c);
		}
	};
};

/** Take the expected input and add the adjacent cities
	@param string input from first calls
	@post all city and adjacent pairs from the line
	will have the adjacent cities added the 'adjacent_' vector
**/
void RouteMap::addAdjacentCities(const std::string fileLine) {
	std::stringstream line(fileLine);
	std::string city = "", adjacent = "";
	while (getline(line, city, '-') && getline(line, adjacent, ',')) {
		cities_[indexByName(city)]->addAdjacent(cities_[indexByName(adjacent)]);
	};
};

/** Return the index of a city if found 
	@param takes city name
	returns if city is found in 'cities_' return index 
*/
int RouteMap::indexByName(const std::string city) {
	if (cityExists(city))
	{
		for (int i = 0; i < cities_.size(); ++i)
		{
			if (city == cities_[i]->getName())return i;
		}
	}
	return -1;
};

/**	traverse 'cities_' vector and check if city is available
	@param string to be compared to city names in the 'cities_' vector
	returns true if city has been created 
**/
bool RouteMap::cityExists(std::string city_name) {
	for (int i = 0; i < cities_.size(); ++i)
	{
		if (cities_[i]->getName() == city_name) return true;
	}
	return false;
};