// ----------------------------------------
//             Advent Of Code
//                    
//         ,---.   ,-----.  ,-----. 
//        /  O  \ '  .-.  ''  .--./ 
//       |  .-.  ||  | |  ||  |     
//       |  | |  |'  '-'  ''  '--'\
//       `--' `--' `-----'  `-----' 
//                           
//           Day 1 - Trebuchet
//              Ethan Eill
//
// ----------------------------------------

#include <iostream>
#include <fstream>
#include <string>

//---------------------------------------------------------------------------
/// @brief get the given lines calibration value.
/// @param  string    current_line        current line in check from the input file
/// @return int       calibration_value   the first number in the string * 10, and the last number in the string added together
//---------------------------------------------------------------------------
int get_current_calibration_value(std::string current_line){
    int calibration_value = 0;
    int index = 0;
    bool is_digit_found = false;

    while(!is_digit_found){
        if(isDigit(current_line[index])){
            
        }else{
            index++;
        }
    }

    return calibration_value;
}

int main(int argc, char** argv){

    // Open file and throw error if cant open
    std::ifstream file_pointer;
    file_pointer.open(argv[1], std::ios::in);
    if(!file_pointer){
        std::cout << "Error opening  file!" << std::endl;
        exit(EXIT_FAILURE);
    }

    int calibration_value = 0;
    int current_lines_calibration_value;
    std::string current_line;

    // Loop through and get each line in input file
    while(std::getline(file_pointer, current_line)){



    }   // while loop through file end
    


    return 0;
}