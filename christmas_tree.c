// --- include --- //
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// --- function --- //
/** 
* @brief count the number of characters in a string
* @param char* str (a word or a sentence)
* @return int (the length of the string)
*/
int my_strlen(char* string){
    int index= 0;
    while(string[index] != '\0'){
        index += 1;
    }
    return index;
}

/**
* @brief convert a string into an int
* @param char* string (string to convert)
* @return int 0 (if the string doesn't contain a number)
*         or
*         int final_int (the number in the string)
*/
int my_atoi(char* param_1){
    int length_p1 = my_strlen(param_1);

    int* number = malloc(sizeof(int) * 10);
    int index = 0;
    int negatif = 0;

    while (index < 10) {
        number[index] = index;
        index += 1;
    }

    index = 0;
    if(param_1[0] == '-'){
        index = 1;
        negatif = 1;
    }
    
    int* string_to_p_int = malloc(sizeof(int) * length_p1);
    while (index < length_p1) {
        if (param_1[index] < 48 || 57 < param_1[index]) {
            return 0;
        }
        string_to_p_int[index] = number[(int)param_1[index] - 48];
        index += 1;
    }

    index = 0;
    int place = 1;
    int final_int = 0;
    while (index < length_p1) {
        final_int += string_to_p_int[length_p1 -1 - index] * place;
        place *= 10;
        index += 1;
    }

    free(string_to_p_int);
    free(number);
    return final_int;
}

/**
* @brief round a number down
* @param int number (the number to round)
* @return int round (the number round down)
*/
int round_int(int number){
    int round = 0;
    while (round <= number) {
        round += 1;
    }
    return round;
}

/**
* @brief calculate the number of stars in the last line of the last level before the trunk
* @param int height (the number of level of the tree and the width of the trunk)
* @return int length (the length of the last line of the last level before the trunk)
*/
int max_length(int 	height){
    int add = 0;
    int index = 2;

    while (index <= height) {
        if (index % 2 == 1){
            add += 1;
        }
        index += 1;
    }

    int length = 2 * ((3 * height) + (add * round_int(height * 0.5 - 1))) + 1;
    return length;
}

/**
* @brief print a certain number of time a given character
* @param int number (the number of character to print)
*        char character (the character to print)
* @return none
*/
void print_n_character(int number, char character){
    int index = 0;
    while(index < number){
        write(1,&character,1);
        index += 1;
    }
}

/**
* @brief print one level of the tree
* @param int height (the width and height of the trunk)
*        int max_length (the length of the last line of the '*' character to print)
*        int max_spine (the maximum of spine on this level)
*        int number_star (the number of spine on the first line of this level)
* @return int number_star_final (the number of stars on the last line of this level)
*/
int spine(int heigth, int max_length, int max_spine, int number_star){
    int index_spine = 0;
    int number_star_final = number_star;
    while (index_spine < max_spine) {
        print_n_character((max_length - number_star_final) / 2 ,' ');
        print_n_character(number_star_final, '*');
        write(1,"\n",1);
        number_star_final += 2;
        index_spine += 1;
    }
    return number_star_final;
}

/**
* @brief print all of the spines to form a tree without a trunk
* @param int height (the width and height of the trunk)
*        int max_length (the length of the last line of the '*' character to print)
* @return none
*/
void tree(int heigth, int max_length){
    int index_heigth = 2;
    int number_star = 1;
    int max_spine = 4;

    while (index_heigth <= heigth + 1) {
        number_star = spine(heigth, max_length, max_spine, number_star) - 2 * round_int(index_heigth * 0.5);
        max_spine += 1;
        index_heigth += 1;
    }
}

/**
* @brief print the trunk of the spine tree
* @param int height (the width and height of the trunk)
*        int max_length (the length of the last line of the '*' character to print)
* @return none
*/
void trunk(int height, int max_length){
    int index_truck = 0;
    int add = 0;

    if (height % 2 == 0) {
        add = 1;
    }

    while (index_truck < height) {
        print_n_character((max_length - height) / 2 + add ,' ');
        print_n_character(height, '|');
        write(1,"\n",1);
        index_truck += 1;
    }
}

/**
* @brief print a pine tree with the number of level given by the height
* @param int height (the number of level of the tree and the width of the trunk)
* @return none
*/
void my_chrismas_tree(int height){
    int length = max_length(height);
    tree(height, length);
    trunk(height, length);
}

// --- main --- //
int main(int ac, char ** av){
    if(ac == 1 || av[1][0] == '0'){
        return 0;
    }
    my_chrismas_tree(my_atoi(av[1]));
}