#ifndef EASY_STRING_H
#define EASY_STRING_H

//Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defs
#define DEFAULT_STRING_SIZE 100
#define DEFAUT_STRING_LIST_SIZE 10

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

//StringList Structure
typedef struct {
    EasyStringArray* strings;
    int size;
    int _impl_size;
}EasyStringList;

//StringSet Structure
typedef struct {
    EasyStringList* stringList;
}EasyStringSet;

//Functions Pre-Declaration: EasyString
int string_check_integrity(const EasyString* string);
EasyString* string_init_with_size(int size);
EasyString* string_init();
EasyString* string_init_with_string(const char* startStr);
int string_reinit(EasyString* src, const EasyString* newStr);
int string_reinit_c_str(EasyString* src, const char* newStr);
int string_append(EasyString* dest, const EasyString* src);
int string_append_c_str(EasyString* dest, const char* src);
int string_append_at_begin(EasyString* dest, const EasyString* src);
int string_append_at_begin_c_str(EasyString* dest, const char* src);
int string_append_at_index(EasyString* dest, const EasyString* src, int index);
int string_append_at_index_c_str(EasyString* dest, const char* src, int index);
const char* string_c_str(const EasyString* string);
int string_equals(const EasyString* str1, const EasyString* str2);
int string_equals_c_str(const char* str1, const char* str2);
EasyStringArray* string_split(const EasyString* string, const EasyString* substring);
EasyStringArray* string_split_c_str(const char* string, const char* substring);
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
void string_delete(EasyString** string);

//Functions Pre-Declaration: EasyStringArray
int string_array_check_integrity(const EasyStringArray* stringArray);
int string_array_check_full_integrity(const EasyStringArray* stringArray);
EasyStringArray* string_array_init(int arrayLength);
int string_array_realloc(EasyStringArray* oldArray, int newSize);
int string_array_length(const EasyStringArray* stringArray);
EasyString* string_array_get(const EasyStringArray* stringArray, int index);
EasyStringArray* string_array_char_by_char(const EasyString* string);
EasyStringArray* string_array_char_by_char_c_str(const char* string);
EasyStringArray* string_array_delete_consecutive_double_occurrences(const EasyStringArray* stringArray, const EasyString* sequence);
EasyStringArray* string_array_delete_consecutive_double_occurrences_c_str(const EasyStringArray* stringArray, const char* sequence);
EasyStringArray* string_array_clone(const EasyStringArray* stringArray);
EasyStringList* string_array_to_string_list(const EasyStringArray* stringArray);
EasyStringSet* string_array_to_string_set(const EasyStringArray* stringArray);
void string_array_delete(EasyStringArray** stringArr);

//Functions Pre-Declaration: EasyStringList
int string_list_check_integrity(const EasyStringList* stringList);
int string_list_check_full_integrity(const EasyStringList* stringList);
EasyStringList* string_list_init();
EasyStringList* string_list_init_with_size(int listStartingSize);
int string_list_defrag(EasyStringList* stringList);
int string_list_defrag_index(EasyStringList* stringList, int index, int skipIntegrityCheck);
EasyString* string_list_get(const EasyStringList* stringList, int index);
int string_list_add(EasyStringList* stringList, const EasyString* string);
int string_list_add_c_str(EasyStringList* stringList, const char* string);
int string_list_add_string_array(EasyStringList* stringList, const EasyStringArray* stringArray);
EasyStringArray* string_list_to_string_array(const EasyStringList* stringList);
int string_list_get_occ(const EasyStringList* stringList, const EasyString* string);
int string_list_get_occ_c_str(const EasyStringList* stringList, const char* string);
int string_list_index_of(const EasyStringList* stringList, const EasyString* string);
int string_list_index_of_c_str(const EasyStringList* stringList, const char* string);
int string_list_contains(const EasyStringList* stringList, const EasyString* string);
int string_list_contains_c_str(const EasyStringList* stringList, const char* string);
int string_list_remove(EasyStringList* stringList, const EasyString* string);
int string_list_remove_c_str(EasyStringList* stringList, const char* string);
int string_list_remove_by_index(EasyStringList* stringList, int index);
int string_list_remove_all(EasyStringList* stringList, const EasyString* string);
int string_list_remove_all_c_str(EasyStringList* stringList, const char* string);
EasyStringList* string_list_clone(const EasyStringList* stringList);
EasyStringSet* string_list_to_string_set(const EasyStringList* stringList);
void string_list_delete(EasyStringList** stringList);

//Function Pre-Declaration: EasyStringSet
int string_set_check_integrity(const EasyStringSet* stringSet);
int string_set_check_full_integrity(const EasyStringSet* stringSet);
EasyStringSet* string_set_init();
EasyStringSet* string_set_init_with_size(int setStartingSize);
int string_set_add(EasyStringSet* stringSet, const EasyString* string);
int string_set_add_c_str(EasyStringSet* stringSet, const char* string);
int string_set_remove(EasyStringSet* stringSet, const EasyString* string);
int string_set_remove_c_str(EasyStringSet* stringSet, const char* string);
EasyString* string_set_get(const EasyStringSet* stringSet, int index);
int string_set_index_of(const EasyStringSet* stringSet, const EasyString* string);
int string_set_index_of_c_str(const EasyStringSet* stringSet, const char* string);
int string_set_contains(const EasyStringSet* stringSet, const EasyString* string);
int string_set_contains_c_str(const EasyStringSet* stringSet, const char* string);
EasyStringArray* string_set_to_string_array(const EasyStringSet* stringSet);
EasyStringList* string_set_to_string_list(const EasyStringSet* stringSet);
void string_set_delete(EasyStringSet** stringSet);

//Functions Declaration: EasyString
int string_check_integrity(const EasyString* string) {
    return (string == NULL || string->string == NULL || string->length<0 || string->size<=0 || string->length >= string->size)==0;
}
EasyString* string_init_with_size(int size) {
    if(size<0) return NULL;
    if(size == 0) {
        size = DEFAULT_STRING_SIZE;
    }
    EasyString* string = (EasyString*) malloc(sizeof(EasyString));
    if(string == NULL) return NULL;
    string->length = 0;
    string->size = size;
    string->string = (char*) malloc(sizeof(char)*string->size);
    if(string->string == NULL) {
        free(string);
        return NULL;
    }
    string->string[0] = 0;
    return string;
}
EasyString* string_init() {
    return string_init_with_size(DEFAULT_STRING_SIZE);
}
EasyString* string_init_with_string(const char* startStr) {
    if(startStr == NULL) return NULL;
    EasyString* str = string_init_with_size(strlen(startStr)*2);
    if(str == NULL) return NULL;
    if(!string_append_c_str(str, startStr)) {
        string_delete(&str);
        return NULL;
    }
    return str;
}
int string_reinit(EasyString* src, const EasyString* newStr) {
    if(newStr == NULL) return 0;
    return string_reinit_c_str(src, newStr->string);
}
int string_reinit_c_str(EasyString* src, const char* newStr) {
    if(newStr == NULL || !string_check_integrity(src)) return 0;
    free(src->string);
    src->length = 0;
    src->size = strlen(newStr)*2;
    src->string = (char*) malloc(sizeof(char)*src->size);
    src->string[0] = 0;
    return string_append_c_str(src, newStr);
}
int string_append(EasyString* dest, const EasyString* src) {
    if(!string_check_integrity(src)) return 0;
    return string_append_c_str(dest, src->string);
}
int string_append_c_str(EasyString* dest, const char* src) {
    if(src == NULL || !string_check_integrity(dest)) return 0;
    int srcLength = strlen(src);
    if(srcLength<=0) return 1;
    if(dest->length+srcLength >= dest->size) {
        char* temp = (char*) realloc(dest->string, sizeof(char)*(dest->size+(srcLength*2)));
        if(temp == NULL) {
            return 0;
        }
        dest->string = temp;
        dest->size += srcLength*2;
    }
    strcat(dest->string, src);
    dest->length += srcLength;
    return 1;
}
int string_append_at_begin(EasyString* dest, const EasyString* src) {
    if(!string_check_integrity(src)) return 0;
    return string_append_at_begin_c_str(dest, src->string);
}
int string_append_at_begin_c_str(EasyString* dest, const char* src) {
    return string_append_at_index_c_str(dest, src, 0);
}
int string_append_at_index(EasyString* dest, const EasyString* src, int index) {
    if(!string_check_integrity(src)) return 0;
    return string_append_at_index_c_str(dest, src->string, index);
}
int string_append_at_index_c_str(EasyString* dest, const char* src, int index) {
    if(src == NULL || index < 0 || !string_check_integrity(dest) || index >= dest->length) return 0;

    if(strlen(src) == 0) return 1;

    EasyString* newString = string_init();
    if(newString == NULL) return 0;
    EasyString* buffer = string_substring(dest, 0, index);
    if(buffer == NULL) {
        string_delete(&newString);
        return 0;
    }

    string_append(newString, buffer);

    string_delete(&buffer);

    string_append_c_str(newString, src);

    buffer = string_substring(dest, index, dest->length);
    if(buffer == NULL) {
        string_delete(&newString);
        return 0;
    }

    string_append(newString, buffer);

    string_delete(&buffer);

    free(dest->string);
    char* temp;
    temp = (char*) malloc(sizeof(char)*newString->size);
    if(temp == NULL) {
        string_delete(&newString);
        return 0;
    }
    dest->string = temp;
    strcpy(dest->string, newString->string);
    dest->size = newString->size;
    dest->length = newString->length;
    string_delete(&newString);

    return 1;
}
const char* string_c_str(const EasyString* string) {
    if(!string_check_integrity(string)) return NULL;
    return string->string;
}
int string_equals(const EasyString* str1, const EasyString* str2) {
    if(!string_check_integrity(str1) || !string_check_integrity(str2)) return 0;
    return !strcmp(str1->string, str2->string);
}
int string_equals_c_str(const char* str1, const char* str2) {
    if(str1 == NULL || str2 == NULL) return 0;
    return !strcmp(str1, str2);
}
EasyStringArray* string_split(const EasyString* string, const EasyString* substring) {
    if(!string_check_integrity(string) || !string_check_integrity(substring)) return NULL;
    return string_split_c_str(string->string, substring->string);
}
EasyStringArray* string_split_c_str(const char* string, const char* substring) {
    if(string == NULL || substring == NULL) return NULL;

    EasyStringArray* stringArray;

    int stringLength = strlen(string);
    int substringLength = strlen(substring);

    if(stringLength == 0) {
        stringArray = string_array_init(1);
        if(stringArray == NULL) return NULL;
        stringArray->stringArray[0] = string_init_with_string("");
        if(stringArray->stringArray[0] == NULL) {
            string_array_delete(&stringArray);
            return NULL;
        }
        return stringArray;
    }

    if(substringLength == 0) {
        return string_array_char_by_char_c_str(string);
    }

    if(!string_contains_c_str(string, substring)) {
        stringArray = string_array_init(1);
        if(stringArray == NULL) return NULL;
        stringArray->stringArray[0] = string_init_with_string(string);
        if(stringArray->stringArray[0] == NULL) {
            string_array_delete(&stringArray);
            return NULL;
        }
        return stringArray;
    }

    int i = 0;
    int occ;
    EasyString* buffer;
    EasyStringList* stringList = string_list_init();
    if(stringList == NULL) return NULL;

    while(i<stringLength) {
        occ = string_first_occurrence_index_from_index_c_str(string, substring, i);
        if(occ == i) {
            if(!string_list_add_c_str(stringList, "")){
                string_list_delete(&stringList);
                return NULL;
            }
        }else if(occ == -1) {
            buffer = string_substring_c_str(string, i, stringLength);
            if(buffer == NULL) {
                string_list_delete(&stringList);
                return NULL;
            }
            if(!string_list_add(stringList, buffer)) {
                string_list_delete(&stringList);
                string_delete(&buffer);
                return NULL;
            }
            string_delete(&buffer);
            stringArray = string_list_to_string_array(stringList);
            if(stringArray == NULL) {
                string_list_delete(&stringList);
                return NULL;
            }
            string_list_delete(&stringList);
            return stringArray;
        }else {
            buffer = string_substring_c_str(string, i, occ);
            if(buffer == NULL) {
                string_list_delete(&stringList);
                return NULL;
            }
            if(!string_list_add(stringList, buffer)) {
                string_list_delete(&stringList);
                string_delete(&buffer);
                return NULL;
            }
            i += buffer->length;
            string_delete(&buffer);
        }
        i += substringLength;
    }

    stringArray = string_list_to_string_array(stringList);
    if(stringArray == NULL) {
        string_list_delete(&stringList);
        return NULL;
    }

    string_list_delete(&stringList);

    return stringArray;
}
int string_contains(const EasyString* string, const EasyString* substring) {
    if(!string_check_integrity(string) || !string_check_integrity(substring)) return 0;
    return string_contains_c_str(string->string, substring->string);
}
int string_contains_c_str(const char* string, const char* substring) {
    if(string == NULL || substring == NULL) return 0;
    return strstr(string, substring)!=NULL;
}
int string_first_occurrence_index(const EasyString* string, const EasyString* substring) {
    if(!string_check_integrity(string) || !string_check_integrity(substring)) return -1;
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
    if(!string_check_integrity(string) || !string_check_integrity(substring)) return -1;
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
    if(!string_check_integrity(string)) return NULL;
    return string_substring_c_str(string->string, start, end);
}
EasyString* string_substring_c_str(const char* string, int start, int end) {
    if(string == NULL) return NULL;

    int length = strlen(string);
    if(start == end) {
        char temp[3];
        temp[0] = string[start];
        temp[1] = 0;
        return string_init_with_string(temp);
    }
    if(start<0 || end>length) return NULL;

    char* buffer = (char*) malloc(sizeof(char)*length);
    if(buffer == NULL) return NULL;
    strcpy(buffer, &(string[start]));
    buffer[end-start] = 0;
    EasyString* newString = string_init_with_string(buffer);
    if(newString == NULL) {
        free(buffer);
        return NULL;
    }
    free(buffer);
    return newString;
}
int string_length(const EasyString* string) {
    if(!string_check_integrity(string)) return -1;
    return string->length;
}
char string_char_at(const EasyString* string, int index) {
    if(!string_check_integrity(string) || index >= string->length) return -1;
    return string->string[index];
}
EasyString* string_replace_occurrence(const EasyString* string, const EasyString* oldSequence, const EasyString* newSequence, int occurrenceNumber) {
    if(!string_check_integrity(string) || !string_check_integrity(oldSequence) || !string_check_integrity(newSequence)) return NULL;
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
    if(newString == NULL) return NULL;

    EasyString* sub = string_substring_c_str(string, 0, index);
    if(sub == NULL) {
        string_delete(&newString);
        return NULL;
    }

    if(!string_append(newString, sub)) {
        string_delete(&newString);
        string_delete(&sub);
        return NULL;
    }
    string_delete(&sub);

    if(!string_append_c_str(newString, newSequence)) {
        string_delete(&newString);
        return NULL;
    }

    sub = string_substring_c_str(string, index+strlen(oldSequence), strlen(string));
    if(sub == NULL) {
        string_delete(&newString);
        return NULL;
    }

    if(!string_append(newString, sub)){
        string_delete(&sub);
        string_delete(&newString);
        return NULL;
    }
    string_delete(&sub);

    return newString;
}
EasyString* string_replace_first(const EasyString* string, const EasyString* oldSequence, const EasyString* newSequence) {
    if(!string_check_integrity(string) || !string_check_integrity(oldSequence) || !string_check_integrity(newSequence)) return NULL;
    return string_replace_first_c_str(string->string, oldSequence->string, newSequence->string);
}
EasyString* string_replace_first_c_str(const char* string, const char* oldSequence, const char* newSequence) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL || !strlen(string) || !strlen(oldSequence) || !strlen(newSequence)) return NULL;

    EasyString* newString = string_init();
    if(newString == NULL) return NULL;
    EasyString* buffer;
    int oldStringIndex = 0, nextOcc;
    int stringLength = strlen(string);
    int oldSequenceLength = strlen(oldSequence);
    
    nextOcc = string_first_occurrence_index_c_str(string, oldSequence);

    buffer = string_substring_c_str(string, 0, nextOcc);
    if(buffer == NULL) {
        string_delete(&newString);
        return NULL;
    }
    oldStringIndex += buffer->length+oldSequenceLength;
    if(!string_append(newString, buffer)) {
        string_delete(&buffer);
        string_delete(&newString);
        return NULL;
    }
    string_delete(&buffer);
    if(!string_append_c_str(newString, newSequence)) {
        string_delete(&newString);
        return NULL;
    }

    if(oldStringIndex < stringLength) {
        buffer = string_substring_c_str(string, oldStringIndex, stringLength);
        if(buffer == NULL) {
            string_delete(&newString);
            return NULL;
        }
        if(!string_append(newString, buffer)) {
            string_delete(&buffer);
            string_delete(&newString);
            return NULL;
        }
        string_delete(&buffer);
    }

    return newString;
}
EasyString* string_replace_all(EasyString* string, const EasyString* oldSequence, const EasyString* newSequence) {
    if(!string_check_integrity(string) || !string_check_integrity(oldSequence) || !string_check_integrity(newSequence)) return NULL;
    return string_replace_all_c_str(string->string, oldSequence->string, newSequence->string);
}
EasyString* string_replace_all_c_str(const char* string, const char* oldSequence, const char* newSequence) {
    if(string == NULL || oldSequence == NULL || newSequence == NULL || !strlen(string) || !strlen(oldSequence) || !strlen(newSequence)) return NULL;

    EasyString* newString = string_init();
    if(newString == NULL) return NULL;
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
        if(buffer == NULL) {
            string_delete(&newString);
            return NULL;
        }
        oldStringIndex += buffer->length+oldSequenceLength;
        if(!string_append(newString, buffer)) {
            string_delete(&buffer);
            string_delete(&newString);
            return NULL;
        }
        string_delete(&buffer);
        if(!string_append_c_str(newString, newSequence)) {
            string_delete(&newString);
            return NULL;
        }
        nextOcc = string_first_occurrence_index_from_index_c_str(string, oldSequence, nextOcc+oldSequenceLength);
    }

    if(oldStringIndex < stringLength) {
        buffer = string_substring_c_str(string, oldStringIndex, stringLength);
        if(buffer == NULL) {
            string_delete(&newString);
            return NULL;
        }
        if(!string_append(newString, buffer)) {
            string_delete(&buffer);
            string_delete(&newString);
            return NULL;
        }
        string_delete(&buffer);
    }

    return newString;
}
EasyString* string_clone(const EasyString* string) {
    if(!string_check_integrity(string)) return NULL;
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

//Functions Declaration: EasyStringArray
int string_array_check_integrity(const EasyStringArray* stringArray) {
    return (stringArray == NULL || stringArray->length <= 0 || stringArray->stringArray == NULL) == 0;
}
int string_array_check_full_integrity(const EasyStringArray* stringArray) {
    if(!string_array_check_integrity(stringArray)) return 0;
    int i;
    for(i=0;i<stringArray->length;i++) {
        if(!string_check_integrity(stringArray->stringArray[i])) return 0;
    }
    return 1;
}
EasyStringArray* string_array_init(int arrayLength) {
    if(arrayLength<=0) return NULL;
    EasyStringArray* stringArray = (EasyStringArray*) malloc(sizeof(EasyStringArray));
    if(stringArray == NULL) return NULL;
    stringArray->length = arrayLength;
    stringArray->stringArray = (EasyString**) malloc(sizeof(EasyString*)*arrayLength);
    if(stringArray->stringArray == NULL) {
        free(stringArray);
        return NULL;
    }
    int i;
    for(i=0;i<arrayLength;i++) {
        (stringArray->stringArray)[i] = NULL;
    }
    return stringArray;
}
int string_array_realloc(EasyStringArray* oldArray, int newSize) {
    if(!string_array_check_integrity(oldArray)) return 0;
    if(oldArray->length >= newSize) return 1;

    EasyStringArray* newArray = string_array_init(newSize);
    if(newArray == NULL) {
        return 0;
    }

    int i;
    for(i=0;i<oldArray->length;i++) {
        newArray->stringArray[i] = oldArray->stringArray[i];
    }
    for(;i<newArray->length;i++) {
        newArray->stringArray[i] = NULL;
    }

    free(oldArray->stringArray);

    oldArray->stringArray = newArray->stringArray;
    oldArray->length = newArray->length;
    free(newArray);

    return 1;
}
int string_array_length(const EasyStringArray* stringArray) {
    if(!string_array_check_integrity(stringArray)) return -1;
    return stringArray->length;
}
EasyString* string_array_get(const EasyStringArray* stringArray, int index) {
    if(!string_array_check_integrity(stringArray) || index >= stringArray->length) return NULL;
    return stringArray->stringArray[index];
}
EasyStringArray* string_array_char_by_char(const EasyString* string) {
    if(!string_check_integrity(string)) return NULL;
    return string_array_char_by_char_c_str(string->string);
}
EasyStringArray* string_array_char_by_char_c_str(const char* string) {
    if(string == NULL) return NULL;
    int arrayLength = strlen(string);

    EasyStringArray* strArray = string_array_init(arrayLength);
    if(strArray == NULL) {
        return NULL;
    }
    int i;
    EasyString* buffer;
    for(i=0;i<arrayLength;i++) {
        buffer = string_substring_c_str(string, i, i+1);
        if(buffer == NULL) {
            string_array_delete(&strArray);
            return NULL;
        }
        strArray->stringArray[i] = string_init_with_string(buffer->string);
        if(strArray->stringArray[i] == NULL) {
            string_array_delete(&strArray);
            return NULL;
        }
        string_delete(&buffer);
    }

    return strArray;
}
EasyStringArray* string_array_delete_consecutive_double_occurrences(const EasyStringArray* stringArray, const EasyString* sequence) {
    if(!string_check_integrity(sequence)) return NULL;
    return string_array_delete_consecutive_double_occurrences_c_str(stringArray, sequence->string);
}
EasyStringArray* string_array_delete_consecutive_double_occurrences_c_str(const EasyStringArray* stringArray, const char* sequence) {
    if(!string_array_check_integrity(stringArray) || sequence == NULL) return NULL;
    
    int prevIsEmpty, i;
    int newFinalLength = 0, arrIndex;
    
    for(i=0, prevIsEmpty = 0; i<stringArray->length;i++) {
        if(string_equals_c_str(stringArray->stringArray[i]->string, sequence)) {
            if(prevIsEmpty) {
                prevIsEmpty = 0;
                newFinalLength++;
            }else {
                prevIsEmpty = 1;
            }
        } else {
            prevIsEmpty = 0;
            newFinalLength++;
        }
    }

    EasyStringArray* newStringArray = string_array_init(newFinalLength);
    if(newStringArray == NULL) {
        return NULL;
    }

    for(i=0, arrIndex=0, prevIsEmpty = 0; i<stringArray->length;i++) {
        if(string_equals_c_str(stringArray->stringArray[i]->string, sequence)) {
            if(prevIsEmpty) {
                prevIsEmpty = 0;
                newStringArray->stringArray[arrIndex] = string_init_with_string(stringArray->stringArray[i]->string);
                if(newStringArray->stringArray[arrIndex] == NULL) {
                    string_array_delete(&newStringArray);
                    return NULL;
                }
                arrIndex++;
            }else {
                prevIsEmpty = 1;
            }
        } else {
            prevIsEmpty = 0;
            newStringArray->stringArray[arrIndex] = string_init_with_string(stringArray->stringArray[i]->string);
            if(newStringArray->stringArray[arrIndex] == NULL) {
                string_array_delete(&newStringArray);
                return NULL;
            }
            arrIndex++;
        }
    }

    return newStringArray;
}
EasyStringArray* string_array_clone(const EasyStringArray* stringArray) {
    if(!string_array_check_integrity(stringArray)) return NULL;
    EasyStringArray* newStringArray = string_array_init(stringArray->length);
    if(newStringArray == NULL) return NULL;
    int i;
    for(i=0; i<stringArray->length;i++) {
        if(!string_check_integrity(stringArray->stringArray[i])) {
            string_array_delete(&newStringArray);
            return NULL;
        } 
        newStringArray->stringArray[i] = string_init_with_string(stringArray->stringArray[i]->string);
    }

    return newStringArray;
}
EasyStringList* string_array_to_string_list(const EasyStringArray* stringArray) {
    if(!string_array_check_integrity(stringArray)) return NULL;
    EasyStringList* stringList = string_list_init_with_size(stringArray->length*2);
    if(stringList == NULL) return NULL;

    int i;
    for(i=0;i<stringArray->length;i++) {
        if(!string_check_integrity(stringArray->stringArray[i])) {
            string_list_delete(&stringList);
            return NULL;
        }
        string_list_add(stringList, stringArray->stringArray[i]);
    }

    return stringList;
}
EasyStringSet* string_array_to_string_set(const EasyStringArray* stringArray) {
    if(!string_array_check_integrity(stringArray)) return NULL;

    EasyStringSet* stringSet = string_set_init_with_size(stringArray->length);
    if(stringSet == NULL) return NULL;
    int i;
    for(i=0;i<stringArray->length;i++) {
        if(!string_check_integrity(stringArray->stringArray[i])) {
            string_set_delete(&stringSet);
        }
        if(!string_set_contains(stringSet, stringArray->stringArray[i])) {
            string_set_add(stringSet, stringArray->stringArray[i]);
        }
    }
    
    return stringSet;
}
void string_array_delete(EasyStringArray** stringArr) {
    if(stringArr == NULL) return;
    if(*stringArr == NULL) return;
    if((*stringArr)->stringArray == NULL) {
        free(*stringArr);
        return;
    }
    int i;
    for(i=0; i<(*stringArr)->length;i++) {
        string_delete((&(*stringArr)->stringArray[i]));
    }
    free(*stringArr);
    *stringArr = NULL;
}

//Functions Declaration: EasyStringList
int string_list_check_integrity(const EasyStringList* stringList) {
    return (stringList == NULL || stringList->size<0 || stringList->_impl_size<=0 || stringList->size >= stringList->_impl_size || stringList->strings == NULL || !string_array_check_integrity(stringList->strings)) == 0;
}
int string_list_check_full_integrity(const EasyStringList* stringList) {
    if(!string_list_check_integrity(stringList)) return 0;
    return string_array_check_full_integrity(stringList->strings);
}
EasyStringList* string_list_init() {
    return string_list_init_with_size(DEFAUT_STRING_LIST_SIZE);
}
EasyStringList* string_list_init_with_size(int listStartingSize) {
    if(listStartingSize <= 0) return NULL;
    EasyStringList* stringList = (EasyStringList*) malloc(sizeof(EasyStringList));
    if(stringList == NULL) return NULL;
    stringList->size = 0;
    stringList->_impl_size = listStartingSize;
    stringList->strings = string_array_init(listStartingSize);
    if(stringList->strings == NULL) {
        free(stringList);
        return NULL;
    }
    return stringList;
}
int string_list_defrag(EasyStringList* stringList) {
    if(!string_list_check_integrity(stringList)) return 0;
    return string_list_defrag_index(stringList, 0, 1);
}
int string_list_defrag_index(EasyStringList* stringList, int index, int skipIntegrityCheck) {
    if(!skipIntegrityCheck) {
        if(!string_list_check_integrity(stringList)) return 0;
    }
    if(index < 0) return 0;
    if(stringList->size == 0) return 1;
    if(stringList->size-1 == index && stringList->strings->stringArray[index] == NULL) {
        stringList->size--;
        return 1;
    }
    if(stringList->size == index) return 1;
    if(stringList->strings->stringArray[index] != NULL) return string_list_defrag_index(stringList, index+1, 1);

    int i;
    for(i=index+1;i<stringList->size;i++) {
        stringList->strings->stringArray[i-1] = stringList->strings->stringArray[i];
    }

    stringList->strings->stringArray[stringList->size-1] = NULL;
    stringList->size--;

    return string_list_defrag_index(stringList, index+1, 1);
}
EasyString* string_list_get(const EasyStringList* stringList, int index) {
    if(!string_list_check_integrity(stringList) || index < 0) return NULL;
    return stringList->strings->stringArray[index];
}
int string_list_add(EasyStringList* stringList, const EasyString* string) {
    if(!string_check_integrity(string)) return 0;
    return string_list_add_c_str(stringList, string->string);
}
int string_list_add_c_str(EasyStringList* stringList, const char* string) {
    if(!string_list_check_integrity(stringList) || string == NULL) return 0;
    if((stringList->size+1) >= stringList->_impl_size) {
        stringList->_impl_size*=2;
        if(!string_array_realloc(stringList->strings, stringList->_impl_size)) {
            return 0;
        }
    }
    stringList->strings->stringArray[stringList->size] = string_init_with_string(string);
    if(stringList->strings->stringArray[stringList->size] == NULL) {
        return 0;
    }
    stringList->size++;
    return 1;
}
int string_list_add_string_array(EasyStringList* stringList, const EasyStringArray* stringArray) {
    if(!string_list_check_integrity(stringList) || !string_array_check_full_integrity(stringArray)) return 0;
    int i;
    int result = 1;
    for(i=0;i<stringArray->length;i++) {
        result = result && string_list_add_c_str(stringList, stringArray->stringArray[i]->string);
    }
    return result;
}
EasyStringArray* string_list_to_string_array(const EasyStringList* stringList) {
    if(!string_list_check_integrity(stringList)) return NULL;

    EasyStringArray* stringArray = string_array_init(stringList->size);
    if(stringArray == NULL) return NULL;
    int i;
    for(i=0;i<stringList->size;i++) {
        stringArray->stringArray[i] = string_init_with_string(stringList->strings->stringArray[i]->string);
        if(stringArray->stringArray[i] == NULL) {
            string_array_delete(&stringArray);
            return NULL;
        }
    }

    return stringArray;
}
int string_list_get_occ(const EasyStringList* stringList, const EasyString* string){
    if(!string_check_integrity(string)) return -1;
    return string_list_get_occ_c_str(stringList, string->string);
}
int string_list_get_occ_c_str(const EasyStringList* stringList, const char* string) {
    if(!string_list_check_integrity(stringList) || string == NULL) return -1;
    int i;
    int numOcc = 0;
    for(i = 0; i<stringList->size; i++) {
        if(!string_check_integrity(stringList->strings->stringArray[i])) return -1;
        if(string_equals_c_str(stringList->strings->stringArray[i]->string, string)) numOcc++;
    }
    return numOcc;
}
int string_list_index_of(const EasyStringList* stringList, const EasyString* string) {
    if(!string_check_integrity(string)) return -1;
    return string_list_index_of_c_str(stringList, string->string);
}
int string_list_index_of_c_str(const EasyStringList* stringList, const char* string) {
    if(!string_list_check_integrity(stringList) || string == NULL) return -1;
    int i;
    for(i=0;i<stringList->size;i++) {
        if(!string_check_integrity(stringList->strings->stringArray[i])) return -1;
        if(string_equals_c_str(stringList->strings->stringArray[i]->string, string)) return i;
    }
    return -1;
}
int string_list_contains(const EasyStringList* stringList, const EasyString* string) {
    if(!string_check_integrity(string)) return 0;
    return string_list_contains_c_str(stringList, string->string);
}
int string_list_contains_c_str(const EasyStringList* stringList, const char* string) {
    if(!string_list_check_integrity(stringList) || string == NULL) return 0;
    return string_list_index_of_c_str(stringList, string)!=-1;
}
int string_list_remove(EasyStringList* stringList, const EasyString* string) {
    if(!string_check_integrity(string)) return 0;
    return string_list_remove_c_str(stringList, string->string);
}
int string_list_remove_c_str(EasyStringList* stringList, const char* string) {
    if(string == NULL || string_list_check_integrity(stringList)) return 0;
    int index = string_list_index_of_c_str(stringList, string);
    if(index == -1) return 0;
    string_delete(&(stringList->strings->stringArray[index]));
    return string_list_defrag(stringList);
}
int string_list_remove_by_index(EasyStringList* stringList, int index) {
    if(index < 0 || index >= stringList->size || !string_list_check_integrity(stringList)) return 0;
    if(stringList->strings->stringArray[index] == NULL) {
        return string_list_defrag_index(stringList, index, 1);
    }
    string_delete(&(stringList->strings->stringArray[index]));
    return string_list_defrag_index(stringList, 0, 1);
}
int string_list_remove_all(EasyStringList* stringList, const EasyString* string) {
    if(!string_check_integrity(string)) return 0;
    return string_list_remove_all_c_str(stringList, string->string);
}
int string_list_remove_all_c_str(EasyStringList* stringList, const char* string) {
    if(string == NULL || !string_list_check_integrity(stringList)) return 0;
    int numOcc = string_list_get_occ_c_str(stringList, string);
    if(numOcc == -1) return 0;
    int i, result = 1;
    for(i=0;i<numOcc;i++) {
        result = result && string_list_remove_c_str(stringList, string);
    }
    return result;
}
EasyStringList* string_list_clone(const EasyStringList* stringList) {
    if(!string_list_check_integrity(stringList)) return NULL;

    EasyStringList* newStringList = string_list_init_with_size(stringList->size);
    if(newStringList == NULL) return NULL;

    int i;
    for(i=0;i<stringList->size;i++) {
        if(!string_check_integrity(stringList->strings->stringArray[i])) {
            string_list_delete(&newStringList);
            return NULL;
        }
        string_list_add(newStringList, stringList->strings->stringArray[i]);
    }

    return newStringList;
}
EasyStringSet* string_list_to_string_set(const EasyStringList* stringList) {
    if(!string_list_check_integrity(stringList)) return NULL;

    EasyStringSet* stringSet = string_set_init_with_size(stringList->size);
    if(stringSet == NULL) return NULL;

    int i;
    for(i=0;i<stringList->size;i++) {
        if(!string_check_integrity(stringList->strings->stringArray[i])) {
            string_set_delete(&stringSet);
            return NULL;
        }
        if(!string_set_contains(stringSet, stringList->strings->stringArray[i])) {
            string_set_add(stringSet, stringList->strings->stringArray[i]);
        }
    }

    return stringSet;
}
void string_list_delete(EasyStringList** stringList) {
    if(stringList == NULL) return;
    if(*stringList == NULL) return;
    string_array_delete(&((*stringList)->strings));
    (*stringList)->_impl_size = 0;
    (*stringList)->size = 0;
    free(*stringList);
    *stringList = NULL;
}

//Function Declaration: EasyStringSet
int string_set_check_integrity(const EasyStringSet* stringSet) {
    return (stringSet == NULL || !string_list_check_integrity(stringSet->stringList)) == 0;
}
int string_set_check_full_integrity(const EasyStringSet* stringSet) {
    if(!string_set_check_integrity(stringSet)) return 0;
    return string_array_check_full_integrity(stringSet->stringList->strings);
}
EasyStringSet* string_set_init() {
    return string_set_init_with_size(DEFAUT_STRING_LIST_SIZE);
}
EasyStringSet* string_set_init_with_size(int setStartingSize) {

    if(setStartingSize <= 0) return NULL;

    EasyStringSet* stringSet = (EasyStringSet*) malloc(sizeof(EasyStringSet));

    if(stringSet == NULL) return NULL;

    stringSet->stringList = string_list_init_with_size(setStartingSize);

    if(stringSet->stringList == NULL) {
        free(stringSet);
        return NULL;
    }

    return stringSet;
}
int string_set_add(EasyStringSet* stringSet, const EasyString* string) {
    if(!string_check_integrity(string)) return 0;
    return string_set_add_c_str(stringSet, string->string);
}
int string_set_add_c_str(EasyStringSet* stringSet, const char* string) {
    if(string == NULL || stringSet == NULL) return 0;
    if(string_list_contains_c_str(stringSet->stringList, string)) return 0;
    return string_list_add_c_str(stringSet->stringList, string);
}
int string_set_remove(EasyStringSet* stringSet, const EasyString* string) {
    if(!string_check_integrity(string)) return 0;
    return string_set_remove_c_str(stringSet, string->string);
}
int string_set_remove_c_str(EasyStringSet* stringSet, const char* string) {
    if(string == NULL || stringSet == NULL) return 0;
    return string_list_remove_c_str(stringSet->stringList, string);
}
EasyString* string_set_get(const EasyStringSet* stringSet, int index) {
    if(stringSet == NULL) return NULL;
    return string_list_get(stringSet->stringList, index);
}
int string_set_index_of(const EasyStringSet* stringSet, const EasyString* string) {
    if(!string_check_integrity(string)) return -1;
    return string_set_index_of_c_str(stringSet, string->string);
}
int string_set_index_of_c_str(const EasyStringSet* stringSet, const char* string) {
    if(stringSet == NULL || string == NULL) return -1;
    return string_list_index_of_c_str(stringSet->stringList, string);
}
int string_set_contains(const EasyStringSet* stringSet, const EasyString* string) {
    if(!string_check_integrity(string)) return 0;
    return string_set_contains_c_str(stringSet, string->string);
}
int string_set_contains_c_str(const EasyStringSet* stringSet, const char* string) {
    if(stringSet == NULL || string == NULL) return 0;
    return string_list_contains_c_str(stringSet->stringList, string);
}
EasyStringArray* string_set_to_string_array(const EasyStringSet* stringSet) {
    if(!string_set_check_integrity(stringSet)) return NULL;
    return string_array_clone(stringSet->stringList->strings);
}
EasyStringList* string_set_to_string_list(const EasyStringSet* stringSet) {
    if(stringSet == NULL) return NULL;
    return string_list_clone(stringSet->stringList);
}
void string_set_delete(EasyStringSet** stringSet) {
    string_list_delete(&((*stringSet)->stringList));
    free(*stringSet);
    *stringSet = NULL;
}

#endif