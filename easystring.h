#ifndef EASY_STRING_H
#define EASY_STRING_H

//Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defs
#define DEFAULT_STRING_SIZE 100

//EasyString Structure
typedef struct {
    char* string;
    int size;
    int length;
}EasyString;

//StringArray Structure
typedef struct {
    EasyString** stringArray;
    int length;
}EasyStringArray;

//Functions Pre-Declaration
EasyString* string_init_with_size(int size);
EasyString* string_init();
EasyString* string_init_with_string(const char* startStr);
void string_reinit(EasyString* src, const EasyString* newStr);
void string_reinit_c_str(EasyString* src, const char* newStr);
EasyStringArray* string_array_init(int arrayLength);
EasyString* string_array_get(EasyStringArray* stringArray, int index);
int string_array_length(EasyStringArray* stringArray);
void string_append(EasyString* dest, const EasyString* src);
void string_append_c_str(EasyString* dest, const char* src);
void string_append_at_begin(EasyString* dest, const EasyString* src);
void string_append_at_begin_c_str(EasyString* dest, const char* src);
void string_append_at_index(EasyString* dest, const EasyString* src, int index);
void string_append_at_index_c_str(EasyString* dest, const char* src, int index);
const char* string_c_str(const EasyString* string);
int string_equals(const EasyString* str1, const EasyString* str2);
int string_equals_c_str(const char* str1, const char* str2);
int string_contains(const EasyString* string, const EasyString* substring);
int string_contains_c_str(const char* string, const char* substring);
int string_first_occurrence_index(const EasyString* string, const EasyString* substring);
int string_first_occurrence_index_c_str(const char* string, const char* substring);
int string_first_occurrence_index_from_index(const EasyString* string, const EasyString* substring, int stringStartIndex);
int string_first_occurrence_index_from_index_c_str(const char* string, const char* substring, int stringStartIndex);
EasyString* string_substring(const EasyString* string, int start, int end);
EasyString* string_substring_c_str(const char* string, int start, int end);
int string_occurrences(const EasyString* string, const EasyString* substring);
int string_occurrences_c_str(const char* string, const char* substring);
int string_length(const EasyString* string);
char string_char_at(const EasyString* string, int index);
EasyString* string_replace_first(const EasyString* string, const EasyString* oldSequence, const EasyString* newSequence);
EasyString* string_replace_first_c_str(const char* string, const char* oldSequence, const char* newSequence);
EasyString* string_replace_all(EasyString* string, const EasyString* oldSequence, const EasyString* newSequence);
EasyString* string_replace_all_c_str(const char* string, const char* oldSequence, const char* newSequence);
EasyString* string_clone(const EasyString* string);
EasyString* string_clone_c_str(const char* string);
EasyString* string_replace_occurrence(const EasyString* string, const EasyString* oldSequence, const EasyString* newSequence, int occurrenceNumber);
EasyString* string_replace_occurrence_c_str(const char* string, const char* oldSequence, const char* newSequence, int occurrenceNumber);
EasyStringArray* string_split(const EasyString* string, const EasyString* substring);
EasyStringArray* string_split_c_str(const char* string, const char* substring);
void string_delete(EasyString** string);
void string_array_delete(EasyStringArray** stringArr);

//Functions Declaration
EasyString* string_init_with_size(int size) {
    if(size<0) return NULL;
    if(size == 0) {
        size = DEFAULT_STRING_SIZE;
    }
    EasyString* string = (EasyString*) malloc(sizeof(EasyString));
    string->length = 0;
    string->size = size;
    string->string = (char*) malloc(sizeof(char)*string->size);
    string->string[0] = 0;
    return string;
}
EasyString* string_init() {
    return string_init_with_size(DEFAULT_STRING_SIZE);
}
EasyString* string_init_with_string(const char* startStr) {
    if(startStr == NULL) return NULL;
    EasyString* str = string_init_with_size(strlen(startStr)*2);
    string_append_c_str(str, startStr);
    return str;
}
void string_reinit(EasyString* src, const EasyString* newStr) {
    if(src == NULL || newStr == NULL) return;
    string_reinit_c_str(src, newStr->string);
}
void string_reinit_c_str(EasyString* src, const char* newStr) {
    if(src == NULL || newStr == NULL) return;
    free(src->string);
    src->length = 0;
    src->size = strlen(newStr)*2;
    src->string = (char*) malloc(sizeof(char)*src->size);
    src->string[0] = 0;
    string_append_c_str(src, newStr);
}
EasyStringArray* string_array_init(int arrayLength) {
    if(arrayLength<=0) return NULL;
    EasyStringArray* stringArray = (EasyStringArray*) malloc(sizeof(EasyStringArray));
    stringArray->length = arrayLength;
    stringArray->stringArray = (EasyString**) malloc(sizeof(EasyString**)*arrayLength);
    return stringArray;
}
int string_array_length(EasyStringArray* stringArray) {
    if(stringArray == NULL) return -1;
    return stringArray->length;
}
void string_append(EasyString* dest, const EasyString* src) {
    if(dest == NULL || src == NULL) return;
    string_append_c_str(dest, src->string);
}
void string_append_c_str(EasyString* dest, const char* src) {
    if(dest == NULL || src == NULL) return;
    int srcLength = strlen(src);
    if(srcLength<=0) return;
    if(dest->length+srcLength >= dest->size) {
        dest->string = (char*) realloc(dest->string, sizeof(char)*(dest->size+(srcLength*2)));
    }
    strcat(dest->string, src);
    dest->size += srcLength*2;
    dest->length += srcLength;
}
void string_append_at_begin(EasyString* dest, const EasyString* src) {
    if(dest == NULL || src == NULL) return;
    string_append_at_begin_c_str(dest, src->string);
}
void string_append_at_begin_c_str(EasyString* dest, const char* src) {
    string_append_at_index_c_str(dest, src, 0);
}
void string_append_at_index(EasyString* dest, const EasyString* src, int index) {
    if(dest == NULL || src == NULL) return;
    string_append_at_index_c_str(dest, src->string, index);
}
void string_append_at_index_c_str(EasyString* dest, const char* src, int index) {
    if(dest == NULL || src == NULL || index < 0 || dest->length < index || !strlen(src)) return;

    EasyString* newString = string_init();
    EasyString* buffer = string_substring(dest, 0, index);

    string_append(newString, buffer);

    string_delete(&buffer);

    string_append_c_str(newString, src);

    buffer = string_substring(dest, index, dest->length);

    string_append(newString, buffer);

    string_delete(&buffer);

    free(dest->string);
    dest->string = (char*) malloc(sizeof(char)*newString->size);
    strcpy(dest->string, newString->string);
    dest->size = newString->size;
    dest->length = newString->length;
    string_delete(&newString);
}
const char* string_c_str(const EasyString* string) {
    if(string == NULL) return NULL;
    return string->string;
}
int string_equals(const EasyString* str1, const EasyString* str2) {
    return !strcmp(str1->string, str2->string);
}
int string_equals_c_str(const char* str1, const char* str2) {
    return !strcmp(str1, str2);
}
int string_contains(const EasyString* string, const EasyString* substring) {
    return string_contains_c_str(string->string, substring->string);
}
int string_contains_c_str(const char* string, const char* substring) {
    return strstr(string, substring)!=NULL;
}
int string_first_occurrence_index(const EasyString* string, const EasyString* substring) {
    if(string == NULL || substring == NULL) return -1;
    return string_first_occurrence_index_c_str(string->string, substring->string);
}
int string_first_occurrence_index_c_str(const char* string, const char* substring) {
    if((string == NULL || substring == NULL) || !strlen(string) || !strlen(substring) || (strlen(substring) > strlen(string)) || !string_contains_c_str(string, substring)) return -1;
    return strstr(string, substring)-string;
}
int string_first_occurrence_index_from_index(const EasyString* string, const EasyString* substring, int stringStartIndex) {
    if(string == NULL || substring == NULL) return -1;
    return string_first_occurrence_index_from_index_c_str(string->string, substring->string, stringStartIndex);
}
int string_first_occurrence_index_from_index_c_str(const char* string, const char* substring, int stringStartIndex) {
    if((string == NULL || substring == NULL) || !strlen(string) || !strlen(substring) || (strlen(substring) > strlen(string)) || !string_contains_c_str(string, substring) || (stringStartIndex > ((int) strlen(string))) || (stringStartIndex < 0)) return -1;
    const char* address = strstr(&(string[stringStartIndex]), substring);
    if(address == NULL) return -1;
    return address-string;
}
int string_occurrences(const EasyString* string, const EasyString* substring) {
    if(string == NULL || substring == NULL) return -1;
    return string_occurrences_c_str(string->string, substring->string);
}
int string_occurrences_c_str(const char* string, const char* substring) {

    if(string == NULL || substring == NULL || (strlen(string) < strlen(substring))) return -1;

    if(!string_contains_c_str(string, substring)) return 0;

    if(!strcmp(string, substring)) return 1;

    int numOcc = 0, i;

    i = string_first_occurrence_index_from_index_c_str(string, substring, 0);

    while(i != -1) {
        numOcc++;
        i = string_first_occurrence_index_from_index_c_str(string, substring, i+strlen(substring));
    }

    return numOcc;
}
EasyString* string_substring(const EasyString* string, int start, int end) {
    if(string == NULL) return NULL;
    return string_substring_c_str(string->string, start, end);
}
EasyString* string_substring_c_str(const char* string, int start, int end) {
    if(string == NULL) return NULL;

    int length = strlen(string);
    if(start == end) {
        return string_init_with_string("");
    }
    if(start<0 || end>length) return NULL;

    char* buffer = (char*) malloc(sizeof(char)*length);
    strcpy(buffer, &(string[start]));
    buffer[end-start] = 0;
    EasyString* newString = string_init_with_string(buffer);
    free(buffer);
    return newString;
}
EasyString* string_array_get(EasyStringArray* stringArray, int index) {
    if(stringArray == NULL || index < 0 || index > stringArray->length) return NULL;
    return stringArray->stringArray[index];
}
int string_length(const EasyString* string) {
    if(string == NULL) return -1;
    return string->length;
}
char string_char_at(const EasyString* string, int index) {
    if(string == NULL || index >= string->length) return -1;
    return string->string[index];
}
EasyString* string_replace_occurrence(const EasyString* string, const EasyString* oldSequence, const EasyString* newSequence, int occurrenceNumber) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL) return NULL;
    return string_replace_occurrence_c_str(string->string, oldSequence->string, newSequence->string, occurrenceNumber);
}
EasyString* string_replace_occurrence_c_str(const char* string, const char* oldSequence, const char* newSequence, int occurrenceNumber) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL || occurrenceNumber < 1 || !strlen(string) || !strlen(oldSequence) || !strlen(newSequence) || (strlen(oldSequence) > strlen(string))) return NULL;

    int numOcc = string_occurrences_c_str(string, oldSequence);

    if(numOcc < occurrenceNumber) return NULL;

    int index, i;
    
    for(i = 0, index = 0; i < occurrenceNumber; i++) {
        index = string_first_occurrence_index_from_index_c_str(string, oldSequence, index);
        index += strlen(oldSequence);
    }

    index -= strlen(oldSequence);

    EasyString* newString = string_init();
    EasyString* sub = string_substring_c_str(string, 0, index);

    string_append(newString, sub);
    string_delete(&sub);

    string_append_c_str(newString, newSequence);

    sub = string_substring_c_str(string, index+strlen(oldSequence), strlen(string));

    string_append(newString, sub);
    string_delete(&sub);

    return newString;
}
EasyStringArray* string_split(const EasyString* string, const EasyString* substring) {
    if(string == NULL || substring == NULL) return NULL;
    return string_split_c_str(string->string, substring->string);
}
EasyStringArray* string_split_c_str(const char* string, const char* substring) {
    if(string == NULL || substring == NULL || !strlen(string) || !strlen(substring) || (strlen(substring) > strlen(string))) return NULL;

    int arrayLength = string_occurrences_c_str(string, substring);

    if(!arrayLength) return NULL;

    arrayLength++;

    if(arrayLength<=0) return NULL;

    int i, stringIndex = 0, occurrence;
    EasyStringArray* stringArray = string_array_init(arrayLength);
    EasyString* buffer;

    for(i=0;i<arrayLength;i++) {
        occurrence = string_first_occurrence_index_from_index_c_str(string, substring, stringIndex);
        buffer = string_substring_c_str(string, stringIndex, occurrence);
        stringArray->stringArray[i] = string_init_with_string(buffer->string);
        free(buffer);
        stringIndex = occurrence+strlen(substring);
    }

    return stringArray;
}
EasyString* string_replace_first(const EasyString* string, const EasyString* oldSequence, const EasyString* newSequence) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL) return NULL;
    return string_replace_first_c_str(string->string, oldSequence->string, newSequence->string);
}
EasyString* string_replace_first_c_str(const char* string, const char* oldSequence, const char* newSequence) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL || !strlen(string) || !strlen(oldSequence) || !strlen(newSequence)) return NULL;

    EasyString* newString = string_init();
    EasyString* buffer;
    int oldStringIndex = 0, nextOcc;
    int stringLength = strlen(string);
    int oldSequenceLength = strlen(oldSequence);
    
    nextOcc = string_first_occurrence_index_c_str(string, oldSequence);

    buffer = string_substring_c_str(string, 0, nextOcc);
    oldStringIndex += buffer->length+oldSequenceLength;
    string_append(newString, buffer);
    string_delete(&buffer);
    string_append_c_str(newString, newSequence);

    if(oldStringIndex < stringLength) {
        buffer = string_substring_c_str(string, oldStringIndex, stringLength);
        string_append(newString, buffer);
        string_delete(&buffer);
    }

    return newString;
}
EasyString* string_replace_all(EasyString* string, const EasyString* oldSequence, const EasyString* newSequence) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL) return NULL;
    return string_replace_all_c_str(string->string, oldSequence->string, newSequence->string);
}
EasyString* string_replace_all_c_str(const char* string, const char* oldSequence, const char* newSequence) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL || !strlen(string) || !strlen(oldSequence) || !strlen(newSequence)) return NULL;

    EasyString* newString = string_init();
    EasyString* buffer;
    int oldStringIndex = 0, nextOcc;
    int stringLength = strlen(string);
    int oldSequenceLength = strlen(oldSequence);

    nextOcc = string_first_occurrence_index_c_str(string, oldSequence);

    if(nextOcc == -1) {
        string_delete(&newString);
        return string_clone_c_str(string);
    }

    while(nextOcc != -1) {
        buffer = string_substring_c_str(string, oldStringIndex, nextOcc);
        oldStringIndex += buffer->length+oldSequenceLength;
        string_append(newString, buffer);
        string_delete(&buffer);
        string_append_c_str(newString, newSequence);
        nextOcc = string_first_occurrence_index_from_index_c_str(string, oldSequence, nextOcc+oldSequenceLength);
    }

    if(oldStringIndex < stringLength) {
        buffer = string_substring_c_str(string, oldStringIndex, stringLength);
        string_append(newString, buffer);
        string_delete(&buffer);
    }

    return newString;
}
EasyString* string_clone(const EasyString* string) {
    if(string == NULL) return NULL;
    return string_init_with_string(string->string);
}
EasyString* string_clone_c_str(const char* string) {
    if(string == NULL) return NULL;
    return string_init_with_string(string);
}
void string_delete(EasyString** string) {
    if(string == NULL) return;
    if(*string == NULL) return;
    if((*string)->string != NULL) {
        free((*string)->string);
    }
    free(*string);
    *string = NULL;
}
void string_array_delete(EasyStringArray** stringArr) {
    if(stringArr == NULL) return;
    if(*stringArr == NULL) return;
    int i;
    for(i=0; i<(*stringArr)->length;i++) {
        string_delete((&(*stringArr)->stringArray[i]));
    }
    free(*stringArr);
    *stringArr = NULL;
}

#endif