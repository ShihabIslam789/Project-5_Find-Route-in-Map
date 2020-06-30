// created by Shihab Islam
// created on June 30,2020
// an interface for Routemap

#ifndef RouteMap_Hpp
#define RouteMap_Hpp

#include "City.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stack> 

class RouteMap {
public:

	//Default Constructor
	//Creates  object of the RouteMap class with default value.
	RouteMap();

	//Parameterized Constructor 
	//@param input_file_name the name of the input csv file
	//returns City objects that are added to the vector locations_
	RouteMap(std::string input_file_name);


	/**
	@param input_file_name of a csv file representing a route map where the first
			line is a comma-separated list of city names, and the remainder is a
		comma-separated list of city-pairs of the form A-B, indicating that B
		is adjacent to A (i.e. there is an arrow in the map going from A to B)
	@post this depends on your design, the input data representing the map must
		  have been stored. Adjacent cities must be stored and explored in the
		  same order in which they are read from the input file
	**/
	bool readMap(std::string input_file_name);

	/**
	@return a pointer to the city found at position, where
		 0 <= position <= n-1, and n is the number of cities,
		 and cities are stored in the same order in which they appear
		 in the input file
	**/
	City* getCity(size_t position);

	/**
	@return true if there is a route from origin to destination, false otherwise
	@post if a route is found from origin to destination, it will print it to
		  standard output in the form “ORIGIN -> ... -> DESTINATION\n”**/
	bool isRoute(City* origin, City* destination);

	//prints path if able to find it
	//@param list.empty != true
	//returns location within the list
	void printLocations(std::stack<City*> list);

	//Finds any city in the cariable locations_
	//@param name nonempty
	//returns city pointer
	City* findCity(std::string name);

private:
	std::vector<City*> locations_;
};

#endif
