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
/// @return uint8_t   calibration_value   the first number in the string * 10, and the last number in the string added together
//---------------------------------------------------------------------------
int get_current_calibration_value(std::string current_line){
    uint8_t calibration_value = 0;
    uint16_t index = 0;
    bool is_digit_found = false;

    //std::cout << current_line << std::endl;

    // loop from the start of string until the first digit is found
    while(!is_digit_found){
        // if that digit is found, add that multiplied by 10
        // to the calibration value
        // otherwise, increment to next char in string
        if(isdigit(current_line[index])){
            calibration_value += (current_line[index] - '0') * 10;
            is_digit_found = true;
        }else{
            index++;
        }
    }   // while digit is not found end

    // reset index to end of the string
    index = current_line.size() - 1;
    is_digit_found = false;

    // loop from the end of string until a digit is found
    while(!is_digit_found){
        // if that digit is found, add that
        // to the calibration value
        // otherwise, increment to next char in string
        if(isdigit(current_line[index])){
            calibration_value += (current_line[index] - '0');
            is_digit_found = true;
        }else{
            index--;
        }
    }   // while digit is not found end

    //std::cout << calibration_value << std::endl;
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
        // get this lines current calibration value
        current_lines_calibration_value = get_current_calibration_value(current_line);

        // add that to the final calibration value
        calibration_value += current_lines_calibration_value;
    }   // while loop through file end
    
    std::cout << calibration_value << std::endl;

    return 0;
}