//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
//  ___________ __  .__                       ___________
//  \_   _____//  |_|  |__ _____    ____      \_   _____/
//   |    __)_\   __\  |  \\__  \  /    \      |    __)_ 
//   |        \|  | |   Y  \/ __ \|   |  \     |        \
//  /_______  /|__| |___|  (____  /___|  / /\ /_______  /
//          \/           \/     \/     \/  \/         \/ 
// 
// Day 2 Cube Conundrum
// 04-27-2024
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#pragma once

#include <iostream>
#include <fstream>
#include <string>

// uncomment the #define for the part of the problem you
// would like to run
#define PART_1
//#define PART_2

namespace Cube_Conundrum {

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// @brief   Checks command line arguments and opens file
	// @param   int         number of command line arguments
	// @param   char*       command line arg for file
	// @param   ifstream    file pointer 
	// @return  bool        result of init
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool initialize(
		int argc,
		char* argv,
		std::ifstream& file_pointer);

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// @brief   Returns the sum of all valid games IDs
	// @param   ifstream    file pointer 
	// @param   uint32      sum of all valid games IDs
	// @return  bool        result of init
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool sum_of_valid_games(
		std::ifstream& file_pointer,
		uint32_t& sum);

}	// END namespace Cube_Conundrum