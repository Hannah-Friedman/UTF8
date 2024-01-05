#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int my_utf8_encode(char *input, char *output){
    int i = 0;
    char temp[5];
    int index = 0;

    // while we haven't reached the end yet
    while (input[i] != '\0'){


        // check to see which code point the current charachter falls into 
        if ((unsigned char)input[i] >= 0x00 && (unsigned char)input[i] <= 0x7F){
           
            // assign each byte to the next index in output
            output[index++] = input[i];
            output[index++] = '\0';

        }
        else if ( (unsigned char)input[i] >= 0xC0 && (unsigned char)input[i] <= 0xDF && 
        (unsigned char)input[i+1] >= 0x80 && (unsigned char)input[i+1] <= 0xBF )
        {
           
            output[index++] = input[i];
            output[index++] = input[i+1];
            output[index++] = '\0';

        }
        else if ((unsigned char)input[i] >= 0xE0 && (unsigned char)input[i] <= 0xEF && 
                (unsigned char)input[i+1] >= 0x80 && (unsigned char)input[i+1] <= 0xBF &&
                (unsigned char)input[i+2] >= 0x80 && (unsigned char)input[i+2] <= 0xBF) 
        {
           
            output[index++] = input[i];
            output[index++] = input[i+1];
            output[index++] = input[i+2];
            output[index++] = '\0';

        }
        else if ((unsigned char)input[i] >= 0xF0 && (unsigned char)input[i] <= 0xF7 && 
                (unsigned char)input[i+1] >= 0x80 && (unsigned char)input[i+1] <= 0xBF &&
                (unsigned char)input[i+2] >= 0x80 && (unsigned char)input[i+2] <= 0xBF &&
                (unsigned char)input[i+3] >= 0x80 && (unsigned char)input[i+3] <= 0xBF) 
        {
            
            output[index++] = input[i];
            output[index++] = input[i+1];
            output[index++] = input[i+2];
            output[index++] = input[i+3];
            output[index++] = '\0';

        }
        i+=1;

    }

    // terminating charachter 
    output[index] = '\0';

    return 0;
}


int my_utf8_decode(unsigned char *input, unsigned char *output) {
    int i = 0;
    int j = 0;

    // while we haven't reached the end yet
    while (input[i] != '\0') {


         // check to see which code point the current charachter falls into 
        if ((unsigned char)input[i] >= 0x00 && (unsigned char)input[i] <= 0x7F){
            return 0;
        }
        else if ( (unsigned char)input[i] >= 0xC0 && (unsigned char)input[i] <= 0xDF && 
        (unsigned char)input[i+1] >= 0x80 && (unsigned char)input[i+1] <= 0xBF )
        {
            return 0;
        }
        else if ((unsigned char)input[i] >= 0xE0 && (unsigned char)input[i] <= 0xEF && 
                (unsigned char)input[i+1] >= 0x80 && (unsigned char)input[i+1] <= 0xBF &&
                (unsigned char)input[i+2] >= 0x80 && (unsigned char)input[i+2] <= 0xBF) 
        {
            return 0;
        }
        else if ((unsigned char)input[i] >= 0xF0 && (unsigned char)input[i] <= 0xF7 && 
                (unsigned char)input[i+1] >= 0x80 && (unsigned char)input[i+1] <= 0xBF &&
                (unsigned char)input[i+2] >= 0x80 && (unsigned char)input[i+2] <= 0xBF &&
                (unsigned char)input[i+3] >= 0x80 && (unsigned char)input[i+3] <= 0xBF)
        {
            return 0;
        }
    }
    return 1;
}


int my_utf8_check(char *string) {
    int i = 0;

    // if the string is empty 
    if (string == NULL || string[0] == '\0'){
        return 0;
    }

    // while we haven't reached the end yet
    while (string[i] != '\0') {
        // check to see if each charachter falls into a valid code point 
        if ((unsigned char)string[i] >= 0x00 && (unsigned char)string[i] <= 0x7F){

            // if we've reached the end of string
            if (string[i+1] == '\0') {
                 return 0;

            }
        }
        else if ( (unsigned char)string[i] >= 0xC0 && (unsigned char)string[i] <= 0xDF && 
        (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF )
        {
            
            if (string[i+2] == '\0') {
                 return 0;

            }
        }
        else if ((unsigned char)string[i] >= 0xE0 && (unsigned char)string[i] <= 0xEF && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF) 
        {
            
            if (string[i+3] == '\0') {
                 return 0;

            }
        }
        else if ((unsigned char)string[i] >= 0xF0 && (unsigned char)string[i] <= 0xF7 && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF &&
                (unsigned char)string[i+3] >= 0x80 && (unsigned char)string[i+3] <= 0xBF)
        {
            
            if (string[i+4] == '\0') {
                 return 0;

            }
        }
        i++;
    }
    return 1;
}


int my_utf8_strlen(char *string){
    int result = 0 ;
    int i = 0;
   
    // while we haven't reached the end yet
    while (string[i] != '\0') {

        // check to see which code point the current charachter falls into 
        if ((unsigned char)string[i] >= 0x00 && (unsigned char)string[i] <= 0x7F){
            
            // if we've reached this point, we've reached the end of a charchter
            result+=1;
            
            // if we've reached the end of the string
            if (string[i+1] == '\0') {
                return result; 
            }

        }
        else if ( (unsigned char)string[i] >= 0xC0 && (unsigned char)string[i] <= 0xDF && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF )
        {
            
            result+=1;
            if (string[i+2] == '\0') {
                 return result; 
            }

        }
        else if ((unsigned char)string[i] >= 0xE0 && (unsigned char)string[i] <= 0xEF && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF) 
        {
            
            result+=1;
            if (string[i+3] == '\0') {
                 return result; 
            }

        }
        else if ((unsigned char)string[i] >= 0xF0 && (unsigned char)string[i] <= 0xF7 && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF &&
                (unsigned char)string[i+3] >= 0x80 && (unsigned char)string[i+3] <= 0xBF)
        {

            result+=1;
            if (string[i+4] == '\0') {
                 return result; 
            }

        }
        i++;
    }
    return result;
}


char *my_utf8_charat(unsigned char *string, int index){
    int i = 0;
    int counter = 0;
    int numBits = 0;

    // if the string is empty
    if (string == NULL || string[0] == '\0'){
        return "";
    }
    
    // if the index is outside the length of the string
    if (index > my_utf8_strlen((char *)string)) {
        return "";
    }

    // to address for spaces between charachters 
    if (index != 0) {
        index = index + index;
    }

    // while we haven't reached the end yet
    while (string[i] != '\0') {

         // check to see which code point the current charachter falls into 
        if ((unsigned char)string[i] >= 0x00 && (unsigned char)string[i] <= 0x7F){
            numBits = 1;
        }

        else if ( (unsigned char)string[i] >= 0xC0 && (unsigned char)string[i] <= 0xDF && 
        (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF )
        {
            numBits = 2;
        }
        else if ((unsigned char)string[i] >= 0xE0 && (unsigned char)string[i] <= 0xEF && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF) 
        {
            numBits = 3;
        }
        else if ((unsigned char)string[i] >= 0xF0 && (unsigned char)string[i] <= 0xF7 && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF &&
                (unsigned char)string[i+3] >= 0x80 && (unsigned char)string[i+3] <= 0xBF)
        {
            numBits = 4;
        }
        // if we've made it to our desired index
        if (counter == index) {
            char *temp = malloc(numBits + 1);
            // get the charachter at index (i) and make it numBits long
            for (int j = 0; j < numBits; j++) {
                temp[j] = string[i+j];
            }
            temp[numBits] = '\0';
            return temp;
        }
        i++;
        counter++;
    }
    return "";
}


int my_utf8_strcmp(char *string1, char *string2) {
    int i;

    // if neither of the strings have reached the end
    for (i=0; string1[i] != '\0' && string2[i] != '\0'; i++){
        // if the charachters don't equal each other
        if (string1[i] != string2[i]) {
            return 1;
        }
    }
    // if we've reached the end of both strings
    if (string1[i] == '\0' && string2[i] == '\0'){
        return 0;
    } else {
        return 1;
    }
}

// returns how many bits are used to represent a specific charahcter 
int num_bits(char *string){
    int result = 0 ;
    int i = 0;

    // if the string is empty 
    if (string == NULL || string[0] == '\0'){
        return 0;
    }

    // while we haven't reached the end yet
    while (string[i] != '\0') {

         // check to see which code point the current charachter falls into 
        if ((unsigned char)string[i] >= 0x00 && (unsigned char)string[i] <= 0x7F){
            return 1;
        }
        else if ( (unsigned char)string[i] >= 0xC0 && (unsigned char)string[i] <= 0xDF && 
        (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF )
        {
            return 2;
        }
        else if ((unsigned char)string[i] >= 0xE0 && (unsigned char)string[i] <= 0xEF && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF) 
        {
            return 3;
        }
        else if ((unsigned char)string[i] >= 0xF0 && (unsigned char)string[i] <= 0xF7 && 
                (unsigned char)string[i+1] >= 0x80 && (unsigned char)string[i+1] <= 0xBF &&
                (unsigned char)string[i+2] >= 0x80 && (unsigned char)string[i+2] <= 0xBF &&
                (unsigned char)string[i+3] >= 0x80 && (unsigned char)string[i+3] <= 0xBF)
        {
            return 4;
        }
    }
    return 0;
}

char* detect_language(unsigned int letter) {
    char *result;

    // if the charachter falls between these codepoints
    if (letter >= 0x20 && letter <= 0x7F) {
        result = "English";
    }
    else if(letter >= 0x590 && letter <= 0x5FF) {
        result = "Hebrew";
    }
    else if(letter >= 0x600 && letter <= 0x6FF) {
        result = "Arabic";
    }
    else {
        result = "Other";
    }
    return result;
}





// ****************************TESTING*************************** //
// ****************************TESTING*************************** //



// test encode
int test_encode(char *output, char *input){
    my_utf8_encode(output, input);
    if (input == output){
        printf("TEST ENCODE PASSED\n");
        return 0;
    }
    printf("TEST ENCODE FAILED\n");
    return 1;
}

// test decode
int test_decode(unsigned char *output, unsigned char *input){
    my_utf8_decode(output, input);
    if (input == output){
        printf("TEST DECODE PASSED\n");
        return 0;
    }
    else {
        printf("TEST DECODE FAILED\n");
    }
    return 1;

}

// test check
int test_check(char *string, char* check) {
    char* fail= "fail";
    if (my_utf8_check(string) == 0 || my_utf8_check(string) == 1 && *check == *fail ){
        printf("TEST CHECK PASSED\n");
        return 0;
    }
    else {
        printf("TEST CHECK FAILED\n");
    }
    return 1;
}

// test str len
int test_len(char *string, int length) {
    if (my_utf8_strlen(string) == length){
        printf("TEST LENGTH PASSED\n");
        return 0;
    }
    else {
        printf("TEST LENGTH FAILED\n");
    }
    return 1;
}

// test char at
int test_charat(unsigned char *string, int index, char *check) {
    char* r = my_utf8_charat(string, index);
    if (*r == *check){
        printf("TEST CHARACHTER AT PASSED\n");
        return 0;
    }
    printf("TEST CHARACHTER AT FAILED\n");
    return 1;
}

// test str cmp
int test_strcmp(char *string1, char *string2, char* check) {
    char* fail= "fail";
    if (my_utf8_strcmp(string1, string2) == 0 || my_utf8_strcmp(string1, string2) == 1 && *check == *fail ){
        printf("TEST STRING COMPARISON PASSED\n");
        return 0;
    }
    printf("TEST STRING COMPARISON FAILED\n");
    return 1;
}


// test num bits
int test_numBits(char *string, int check) {
    if (num_bits(string) == check){
        printf("TEST NUMBER OF BITS PASSED\n");
        return 0;
    }
    printf("TEST NUMBER OF BITS FAILED\n");
    return 1;
}

// test language 
int test_language(unsigned int letter, char *check) {
    if (detect_language(letter) == check){
        printf("TEST DETECT LANGUAGE PASSED\n");
        return 0;
    }
    printf("TEST DETECT LANGUAGE FAILED\n");
    return 1;
}



int main(void) {

    unsigned char *string = (unsigned char *)"אריה";
    unsigned char *string_long = (unsigned char *)"אריאריהאריאריהאריהההאאריהאריהריה";

    unsigned char *string1 = (unsigned char *)"";
    char output1[20];
    unsigned char* output2[20];

    // encode test
    test_encode("\u05D0\u05E8\u05D9\u05D4", output1);
    
    // decode test
    test_decode(string, *output2);

    // check test
    test_check("\xD7\x90\xD7\xA8\xD7\x99\xD7\x94", "pass"); 
    test_check("", "pass"); 
    test_check("\x7E\x81", "fail"); 
    test_check("\xD8\xA7\xD9\x84\xD8\xB9\xD8\xB1\xD8\xA8\xD9\x8A", "fail"); 
    test_check("\xE4\xB8\xA4\xE4\xBD\x9C", "fail"); 
    test_check("\xC3\x28\x98\xC2\xA9", "fail"); 
    test_check("\xE6\x97\xA5\xE6\x9C\xAC\xE8\xAA\x9E", "pass"); 

    
    // length test
    test_len("אריה", 4);
    test_len("ה", 1); 
    test_len("", 0); 
    test_len("אריהאריהאריהאריהאריהאריאריהאריהאריהאריהאריהאריהאריהאריההאריהאריה", 64);
    test_len("مرحبًا", 6);
    test_len("你好", 2);
    test_len("😬😢", 2);
    
    
    // charachter at test
    test_charat(string, 0, "א"); 
    test_charat(string, 2, "י"); 
    test_charat(string1, 0, "");
    test_charat(string1, 3, "");
    test_charat(string, 5, "");
    test_charat(string_long, 31, "ה");



    // string comparison test
    test_strcmp("אריה", "אריה", "pass"); 
    test_strcmp("אריה", "ארה", "fail"); 
    test_strcmp("", "", "pass");
    test_strcmp("אריה", "אריהאריה", "fail");
    test_strcmp("😬", "😬", "pass");



    // numbits test
    test_numBits("א", 2);
    test_numBits("㗂", 3);
    test_numBits("𨉟", 4);
    test_numBits("", 0);
    test_numBits("😬", 4);


    // detect language test
    test_language('a', "English"); 
    test_language(L'א', "Hebrew"); 
    test_language(L'ا', "Arabic"); 
    test_language(L'𨉟', "Other"); 
    test_language(L'😬', "Other"); 


}