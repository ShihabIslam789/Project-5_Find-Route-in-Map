// Created by Shihab Islam
// Created on June 30, 2020
// Implementation of city

#ifndef CITY_HPP_
#define CITY_HPP_
#include <iostream>
#include <vector>
#include <string>

class City
{
public:
	/*
	 Default constructor is parameterized
	**/
	City(std::string name);

	~City();

	/** returns city_name_ **/
	std::string getName()const;

	/** @return adjacent_ contains pointers to the cities that are adjacent  city**/
	std::vector<City*> getAdjacent()const;

	/** returns  'visited_' **/
	bool getVisited()const;

	/** Add city pointer to adjacent vector
		@post is the pointer is not nullptr the new city will be added
	**/
	void addAdjacent(City* city_address);

	/** returns negate 'Visited_' **/
	void setVisited(const bool val);

private:
	/** Returns bool after traversing the 'adjacent_' vector
		checks if city is already included
		returns true if address is found and false if not found or nullptr
	**/
	bool alreadyAdjacent(City* city);
	bool visited_ = false; 
	std::string city_name_; 
	std::vector<City*> adjacent_; 


};

#endif