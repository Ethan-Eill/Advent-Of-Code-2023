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

#include "Processing.h"

namespace Cube_Conundrum {
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PRIVATE VARIABLES
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static constexpr uint16_t num_cubes[]{ 12, 13, 14 };

	static const std::string colors[]{ "red", "green", "blue"};

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PRIVATE FUNCTIONS
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART1 Gets the game id from provided string
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static uint16_t get_game_id(std::string curr_line)
	{
		uint16_t game_id = 0;
		uint16_t string_index = 0;

		// find first digit in string
		while (!isdigit(curr_line[string_index])) {
			string_index++;
		}

		
		while (isdigit(curr_line[string_index])) {
			// subtracting 48 gives the number value
			game_id += (uint16_t)(curr_line[string_index] - 48);
		}

	}	// END get_game_id

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PUBLIC FUNCTIONS
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Checks command line arguments and opens file
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool initialize(
		int argc,
		char* argv,
		std::ifstream& file_pointer)
	{
        bool result = true;

        // Check for expected command line arguments
        if (2 > argc) {
            printf("FATAL ERROR: Not enough command line args!\n");
            result &= false;
            return result;
        }

        // Open the input file
        file_pointer.open(argv, std::ios::in);
        if (!file_pointer) {
            printf("FATAL ERROR: Error opening file!");
            result &= false;
            return result;
        }

        return result;


	}	// END initialize()

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART 1 Returns the sum of all valid games IDs
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool sum_of_valid_games(
		std::ifstream& file_pointer,
		uint32_t& sum) 
	{
		bool result = true;



		return result;
	}	// END sum_of_valid_games()	

}	// END namespace Cube_Conundrum