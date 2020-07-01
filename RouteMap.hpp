// created by Shihab Islam
// created on June 30,2020
// an interface for Routemap

#ifndef RouteMap_Hpp
#define RouteMap_Hpp
#include "City.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <stack> 
#include <iostream>

class RouteMap
{
public:
	RouteMap(); // Default constructor
	RouteMap(std::string input_file_name); // Paramiterized constructor

	/** 
	@post will delete all cities stored  deallocate all pointers
	**/
	~RouteMap();

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
	 standard output in the form “ORIGIN -> ... -> DESTINATION\n”
	**/
	bool isRoute(City* origin, City* destination);

	
	void print();
private:
	
	//	print contents of 'route_' 
	void printRoute();
	/** check if there are adjacent cities that can be visited 
		@param City pointer to the current city at location
		returns pointer to unvisited city or nullpointer if no path forward
	**/
	City* nextCity(const City* cityptr);

	
	/** add cities to the 'cities_' vector		
		@param first line of the file
		@post All cities will be added to the 'cities_' vector
	**/
	void makeCities(const std::string fileLineOne);

	/** Take the expected input and add the adjacent cities	
		@param string input from primary function call
		@post all city and adjacent pairs provided by the line
	**/
	void addAdjacentCities(const std::string fileLine);

	/** Return the index of a city if found 
		@param takes city name
		returns if city is found in 'cities_' return index 
	**/
	int indexByName(const std::string city);

	/**	traverse 'cities_' vector and check if city is available
		@param string to be compared to city names in the 'cities_' vector
		returns true if city has been created already
	**/
	bool cityExists(std::string city_name);


	std::vector<City*> cities_; 
	std::stack<City*> route_;


};
#endif