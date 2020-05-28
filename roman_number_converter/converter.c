 /*
  RMIT University Vietnam
  Course: EEET2448 Computing Engineering
  Semester: 2019A
  Assessment: Assignment 2
  Author: Your name (e.g. Nguyen Van Minh)
  ID: Your student id (e.g. 1234567)
  Created date: dd/mm/yyyy (e.g. 31/03/2017)
  Acknowledgement: If you use any resources, acknowledge here. Failure to do so will be considered as plagiarism.
*/

#include <stdio.h>
#include <string.h>

int roman_to_integer(char roman);

int convert_number (char *roman_char);

int main(int argc, char const *argv[]) {
    //open file to read
    FILE *i = fopen("input.txt", "r");
    //open file to write
    FILE *o = fopen("output.txt", "w");
    //declare array to store Roman numeral with maximum length is 15 which is the greatest number of character of Roman numerals from 0 to 4000
    char roman[16];
    //operate until EOF is reached
    while (fscanf(i, "%[^\n]", roman) == 1) {
        fprintf(o, "%d\n", convert_number(roman));
        //scan to next Roman numeral
        fscanf(i, "%*[^[I, V, X, L, C, D, M]]");
    }
    //close files
    fclose(i);
    fclose(o);
    return 0;
}

//assign integer values to equivalent Roman characters
int roman_to_integer(char roman) {
    switch (roman) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
    }
}

//convert Roman numeral to decimal number
int convert_number (char *roman_char) {
    int converted_decimal = 0;
    //stop and return value when the last character of the Romamn numeral is converted
    while (*roman_char != '\0') {
        //check special cases when subtraction is used
        if (*roman_char == 'I' || *roman_char == 'X' || *roman_char == 'C') {
            //specail cases happen when the value of current Roman character is smaller than that of the next Roman character
            if (roman_to_integer(*roman_char) < roman_to_integer(*(roman_char + 1))) {
                converted_decimal = converted_decimal - roman_to_integer(*roman_char);
            } else {
                converted_decimal = converted_decimal + roman_to_integer(*roman_char);
            }
        } else {
            converted_decimal = converted_decimal + roman_to_integer(*roman_char);
        }
        ++roman_char;
    }
    return converted_decimal;
}
