//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
//  ___________ __  .__                       ___________
//  \_   _____//  |_|  |__ _____    ____      \_   _____/
//   |    __)_\   __\  |  \\__  \  /    \      |    __)_ 
//   |        \|  | |   Y  \/ __ \|   |  \     |        \
//  /_______  /|__| |___|  (____  /___|  / /\ /_______  /
//          \/           \/     \/     \/  \/         \/ 
// 
// Day 1 Trebuchet
// 04-26-2024
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace Trebuchet {

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
	// @brief   Checks command line arguments and opens file
	// @param   ifstream    file pointer 
	// @return  bool        result of solving the problem
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool main_processing_loop(std::ifstream& file_pointer);

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// @brief   Closes file pointer
	// @param   ifstream    file pointer 
	// @return  bool        result of uninitialize
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool uninitialize(std::ifstream& file_pointer);

}	// END namespace Trebuchet