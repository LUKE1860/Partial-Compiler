#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void add(int int_size, int unsigned_size, char args_identifiers[4][300], int index, char body_identifiers[20][300],int add_count) {
   	bool found = false;
    if (int_size == 1 && add_count == 1 || int_size == 2 && add_count == 1) {
        for (int i = 0; i < index; i++) {
			printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
				printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            int returned_value = 0;
            int arg = rand() % 100;
			printf("First argument value: %d\n", arg);
            int value = atoi(body_identifiers[1]);
			printf("Second argument value: %d\n", value);
            __asm {
		    MOV EAX, arg
            JMP sum
            sum:
             MOV EBX,value
		     ADD EAX, EBX
             JMP end
            end:
             MOV returned_value, EAX
            }
			printf("Result of addition: %d\n", returned_value);

        }
        else {
			printf("Error: Identifier  not found among arguments.\n");
        }

    }
    else if (unsigned_size == 1 && add_count== 1 || unsigned_size == 2 && add_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            unsigned char returned_value = 0;
            unsigned char arg = rand() % 10;
            printf("First argument value: %d\n", arg);
            unsigned char value = atoi(body_identifiers[1]);
            printf("Second argument value: %d\n", value);
            __asm {
                MOV AL, arg
                JMP add_u
                add_u :
                MOV BL, value
                ADD AL, BL
                JMP add_end_u
                    add_end_u :
                MOV returned_value, AL
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
}
void double_add(int int_size, int unsigned_size, char args_identifiers[4][300], int index, char body_identifiers[20][300], int add_count) {
    bool found = false;
    if (int_size == 1 && add_count == 1 || int_size == 2 && add_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            int returned_value = 0;
            int arg = rand() % 100;
            printf("First argument value: %d\n", arg);
            int f_value = atoi(body_identifiers[1]);
			int s_value = atoi(body_identifiers[2]);
			printf("Second argument value: %d\n", f_value);
			printf("Third argument value: %d\n", s_value);
            __asm {
                MOV EAX, arg
                JMP sum
                sum :
                MOV EBX, f_value
                MOV ECX, s_value
                    ADD EAX, EBX
                    ADD EAX, ECX
                    JMP end
                    end :
                MOV returned_value, EAX
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
    else if (unsigned_size == 1 && add_count == 1 || unsigned_size == 2 && add_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            unsigned char returned_value = 0;
            unsigned char arg = rand() % 10;
            printf("First argument value: %d\n", arg);
            unsigned char f_value = atoi(body_identifiers[1]);
			unsigned char s_value = atoi(body_identifiers[2]);
            __asm {
                MOV AL, arg
                JMP add_u
                add_u :
                MOV BL, f_value
                MOV CL, s_value
                    ADD AL, BL
                    ADD AL , CL
                    JMP add_end_u
                    add_end_u :
                MOV returned_value, AL
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
}
void sub(int int_size, int unsigned_size, char args_identifiers[4][300], int index, char body_identifiers[20][300], int sub_count) {
    bool found = false;
    if (int_size == 1 && sub_count == 1 || int_size == 2 && sub_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            int returned_value = 0;
            int arg = rand() % 100;
            printf("First argument value: %d\n", arg);
            int value = atoi(body_identifiers[1]);
            printf("Second argument value: %d\n", value);
            __asm {
                MOV EAX, arg
                JMP sub_i
                sub_i :
                MOV EBX, value
                    SUB EAX, EBX
                    JMP sub_end
                    sub_end :
                MOV returned_value, EAX
            }
            printf("Result of substraction: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
    else if (unsigned_size == 1 && sub_count == 1 || unsigned_size == 2 && sub_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            unsigned char returned_value = 0;
            unsigned char arg = rand() % 10;
            printf("First argument value: %d\n", arg);
            unsigned char value = atoi(body_identifiers[1]);
            printf("Second argument value: %d\n", value);
            __asm {
                MOV AL, arg
                JMP sub_u
                sub_u :
                MOV BL, value
                    SUB AL, BL
                    JMP sub_end_u
                    sub_end_u :
                MOV returned_value, AL
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }
    }

}
void double_sub(int int_size, int unsigned_size, char args_identifiers[4][300], int index, char body_identifiers[20][300], int sub_count) {
    bool found = false;
    if (int_size == 1 && sub_count == 1 || int_size == 2 && sub_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            int returned_value = 0;
            int arg = rand() % 100;
            printf("First argument value: %d\n", arg);
            int f_value = atoi(body_identifiers[1]);
            int s_value = atoi(body_identifiers[2]);
            printf("Second argument value: %d\n", f_value);
            printf("Third argument value: %d\n", s_value);
            __asm {
                MOV EAX, arg
                JMP sum
                sum :
                MOV EBX, f_value
                    MOV ECX, s_value
                    SUB EAX, EBX
                    SUB EAX, ECX
                    JMP end
                    end :
                MOV returned_value, EAX
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
    else if (unsigned_size == 1 && sub_count == 1 || unsigned_size == 2 && sub_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            unsigned char returned_value = 0;
            unsigned char arg = rand() % 10;
            printf("First argument value: %d\n", arg);
            unsigned char f_value = atoi(body_identifiers[1]);
			unsigned char s_value = atoi(body_identifiers[2]);
            __asm {
                MOV AL, arg
                JMP add_u
                add_u :
                MOV BL, f_value
                MOV CL, s_value
                    SUB AL, BL
                    SUB AL, CL
                    JMP add_end_u
                    add_end_u :
                MOV returned_value, AL
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
}
void mul(int int_size, int unsigned_size, char args_identifiers[4][300], int index, char body_identifiers[20][300], int mul_count) {
    bool found = false;
    if (int_size == 1 && mul_count == 1 || int_size == 2 && mul_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            int returned_value = 0;
            int arg = rand() % 100;
            printf("First argument value: %d\n", arg);
            int value = atoi(body_identifiers[1]);
            printf("Second argument value: %d\n", value);
            __asm {
                MOV EAX, arg
                CALL mul_i
                JMP mul_end
                mul_i :
                MOV EBX, value
				MUL EBX
                RET
                mul_end :
                MOV returned_value, EAX
            }
            printf("Result of substraction: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }
    }
    else if (unsigned_size == 1 && mul_count == 1 || unsigned_size == 2 && mul_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            unsigned char returned_value = 0;
            unsigned char arg = rand() % 10;
            printf("First argument value: %d\n", arg);
            unsigned char value = atoi(body_identifiers[1]);
            printf("Second argument value: %d\n", value);
            __asm {
                MOV AL, arg
                CALL mul_u
                JMP mul_end_u
                mul_u:
                MOV BL, value
                MUL BL
                RET
                mul_end_u:
                MOV returned_value, AL
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }
    }
}
void double_mul(int int_size, int unsigned_size, char args_identifiers[4][300], int index, char body_identifiers[20][300], int mul_count) {
    bool found = false;
    if (int_size == 1 && mul_count == 1 || int_size == 2 && mul_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            int returned_value = 0;
            int arg = rand() % 100;
            printf("First argument value: %d\n", arg);
            int f_value = atoi(body_identifiers[1]);
            int s_value = atoi(body_identifiers[2]);
            printf("Second argument value: %d\n", f_value);
            printf("Third argument value: %d\n", s_value);
            __asm {
                MOV EAX, arg
                JMP sum
                sum :
                MOV EBX, f_value
                MUL EBX
                MOV ECX,s_value
                MUL ECX
                 
                    JMP end
                    end :
                MOV returned_value, EAX
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
    else if (unsigned_size == 1 && mul_count == 1 || unsigned_size == 2 && mul_count == 1) {
        for (int i = 0; i < index; i++) {
            printf("Comparing %s and %s\n", args_identifiers[i], body_identifiers[0]);
            if (strcmp(args_identifiers[i], body_identifiers[0]) == 0) {
                printf("Found matching identifier: %s\n", args_identifiers[i]);
                found = true;
            }
        }
        if (found) {
            unsigned char returned_value = 0;
            unsigned char arg = rand() % 10;
            printf("First argument value: %d\n", arg);
            unsigned char f_value = atoi(body_identifiers[1]);
            unsigned char s_value = atoi(body_identifiers[2]);
            __asm {
                MOV AL, arg
                JMP add_u
                add_u :
                MOV BL, f_value
                MOV CL, s_value
                    JMP add_end_u
                    add_end_u :
                MOV returned_value, AL
            }
            printf("Result of addition: %d\n", returned_value);

        }
        else {
            printf("Error: Identifier  not found among arguments.\n");
        }

    }
}
void  main_cycle(char args_identifiers[4][300],int index,int int_count,int unsigned_count,char body_identifiers[20][300],int body_ident_index, char body_values[20][300],int body_value_index,char return_identifier[300], int let_count) {
    char math_operation[20][300];
    int add_count = 0;
	int double_add_count = 0;  
	int sub_count = 0;
	int double_sub_count = 0;
	int mul_count = 0;
    int double_mul_count = 0;
    for (int i = 0; i < body_ident_index; i++) {
        if (strcmp("A", body_identifiers[i]) == 0) {
            add_count++;
        }
        else if (strcmp("DA", body_identifiers[i]) == 0) {
            double_add_count++;
        }
        else if (strcmp("S", body_identifiers[i]) == 0) {
            sub_count++;
        }
        else if (strcmp("DS", body_identifiers[i]) == 0) {
            double_sub_count++;
        }
        else if (strcmp("M", body_identifiers[i]) == 0) {
            mul_count++;
        }
        else if (strcmp("DM", body_identifiers[i]) == 0) {
            double_mul_count++;
        }
	}
    if (add_count == 1) {
        if (let_count == 0) {
            int default_index = 0;
            int math_index = 0;
            int value_index = 0;
            for (int i = 0; i < body_ident_index; i++) {
                if (strcmp("A", body_identifiers[i]) == 0) {
                    math_index = i;
                    break;
                }
            }
            for (int k = 0; k < body_value_index; k++) {
                if (strcmp("A", body_values[k]) == 0) {
                    value_index = k;
                    break;
                }
            }
                for (int j = math_index + 1; j < math_index + 2; j++) {
                    printf("Argument: %s\n", body_identifiers[j]);
                    strcpy(math_operation[default_index], body_identifiers[j]);
                }
				strcpy(math_operation[default_index+1], body_values[value_index+1]);
                add(int_count, unsigned_count, args_identifiers,index,math_operation,add_count);
        }
    }
    else if (double_add_count == 1) {
        if (let_count == 0) {
            int default_index = 0;
            int math_index = 0;
            int value_index = 0;
            int counter = 0;
            char numbers[3][300];
            for (int i = 0; i < body_ident_index; i++) {
                if (strcmp("DA", body_identifiers[i]) == 0) {
                    math_index = i;
                    break;
                }
            }
            for (int k = 0; k < body_value_index; k++) {
				printf("Checking body value: %s\n", body_values[k]);
                if (strcmp("DA", body_values[k]) == 0) {
					strcpy(numbers[counter], body_values[k + 1]);
                    counter++;
					strcpy(numbers[counter], body_values[k + 2]);
                }
            }
            for (int j = math_index + 1; j < math_index + 2; j++) {
                printf("Argument: %s\n", body_identifiers[j]);
                strcpy(math_operation[default_index], body_identifiers[j]);
            }

            strcpy(math_operation[default_index + 1],numbers[0]);
            strcpy(math_operation[default_index + 2], numbers[1]);
            double_add(int_count, unsigned_count, args_identifiers, index, math_operation, double_add_count);
		}
    }
    else if (sub_count == 1) {
        if (let_count == 0) {
            int default_index = 0;
            int math_index = 0;
            int value_index = 0;
            for (int i = 0; i < body_ident_index; i++) {
                if (strcmp("S", body_identifiers[i]) == 0) {
                    math_index = i;
                    break;
                }
            }
            for (int k = 0; k < body_value_index; k++) {
                if (strcmp("S", body_values[k]) == 0) {
                    value_index = k;
                    break;
                }
            }
            for (int j = math_index + 1; j < math_index + 2; j++) {
                printf("Argument: %s\n", body_identifiers[j]);
                strcpy(math_operation[default_index], body_identifiers[j]);
            }
            strcpy(math_operation[default_index + 1], body_values[value_index + 1]);
            printf("%s", math_operation[default_index + 1]);
            sub(int_count, unsigned_count, args_identifiers, index, math_operation, sub_count);
        }
        else {

        }
    }
    else if (double_sub_count == 1) {
        if (let_count == 0) {
            int default_index = 0;
            int math_index = 0;
            int value_index = 0;
            char numbers[3][300];
            int counter = 0;
            for (int i = 0; i < body_ident_index; i++) {
                if (strcmp("DS", body_identifiers[i]) == 0) {
                    math_index = i;
                    break;
                }
            }
            for (int k = 0; k < body_value_index; k++) {
                printf("Checking body value: %s\n", body_values[k]);
                if (strcmp("DS", body_values[k]) == 0) {
                    strcpy(numbers[counter], body_values[k + 1]);
                    counter++;
                    strcpy(numbers[counter], body_values[k + 2]);
                }
            }
            for (int j = math_index + 1; j < math_index + 2; j++) {
                printf("Argument: %s\n", body_identifiers[j]);
                strcpy(math_operation[default_index], body_identifiers[j]);
            }
            strcpy(math_operation[default_index + 1], numbers[0]);
            strcpy(math_operation[default_index + 2], numbers[1]);
            double_sub(int_count, unsigned_count, args_identifiers, index, math_operation, double_sub_count);
		}
        else {

        }
    }
    else if (mul_count == 1) {
        if (let_count == 0) {
            int default_index = 0;
            int math_index = 0;
            int value_index = 0;
            for (int i = 0; i < body_ident_index; i++) {
                if (strcmp("M", body_identifiers[i]) == 0) {
                    math_index = i;
                    break;
                }
            }
            for (int k = 0; k < body_value_index; k++) {
                if (strcmp("M", body_values[k]) == 0) {
                    value_index = k;
                    break;
                }
            }
            for (int j = math_index + 1; j < math_index + 2; j++) {
                printf("Argument: %s\n", body_identifiers[j]);
                strcpy(math_operation[default_index], body_identifiers[j]);
            }
            strcpy(math_operation[default_index + 1], body_values[value_index + 1]);
            mul(int_count, unsigned_count, args_identifiers, index, math_operation, mul_count);
        }
    }
    else if (double_mul_count == 1) {
        if (let_count == 0) {
            int default_index = 0;
            int math_index = 0;
            int value_index = 0;
			char numbers[3][300];
            int counter = 0;
            for (int i = 0; i < body_ident_index; i++) {
                if (strcmp("DM", body_identifiers[i]) == 0) {
                    math_index = i;
                    break;
                }
            }
            for (int k = 0; k < body_value_index; k++) {
                if (strcmp("DM", body_values[k]) == 0) {
                    strcpy(numbers[counter], body_values[k + 1]);
                    counter++;
                    strcpy(numbers[counter], body_values[k + 2]);
                }
            }
            for (int j = math_index + 1; j < math_index + 2; j++) {
                printf("Argument: %s\n", body_identifiers[j]);
                strcpy(math_operation[default_index], body_identifiers[j]);
            }
            strcpy(math_operation[default_index + 1], numbers[0]);
            strcpy(math_operation[default_index + 2], numbers[1]);
            double_mul(int_count, unsigned_count, args_identifiers, index, math_operation, double_mul_count);
        }
    }
}
//turn arguments into strings
//there are errors here
void structure_determination(char args[4][300],char body[30][300],char return_value[1][300],int args_length, int body_length) {
    int index = 0;
    int let_count = 0;
	int body_ident_index = 0;
    int body_value_index = 0;
    char args_identifiers[4][300];
	char body_identifiers[20][300];
	char body_values[20][300];
    int int_count = 0;
	int unsigned_count = 0;
    char return_identifier[300];
    for (int i = 0; i < args_length; i++) {
        if (strcmp("int", args[i]) == 0) {
			int_count++;
        }
        else if (strcmp("unsigned", args[i]) == 0) {
			unsigned_count++;
		}
        else {
            strcpy(args_identifiers[index], args[i]);
            index++;
        }
    }
    for (int j = 0; j < body_length; j++) {
        if (strcmp("LET", body[j])==0) {
			let_count++;
            strcpy(body_identifiers[body_ident_index], "L");
            body_ident_index++;
            strcpy(body_values[body_value_index], "L");
			body_value_index++;
            for (int k = j + 1; k < j + 3;k++) {
                if (isalpha(body[k][0])) {
					strcpy(body_identifiers[body_ident_index], body[k]);
					body_ident_index++;
                }
                else {
					strcpy(body_values[body_value_index], body[k]);
					body_value_index++;
                }
            }
        }
        else if (strcmp("ADD", body[j]) == 0) {
			strcpy(body_identifiers[body_ident_index],"A");
            body_ident_index++;
            strcpy(body_values[body_value_index], "A");
            body_value_index++;
            for (int k = j+1; k < j+3; k++) {
                if (isalpha(body[k][0])) {
					printf("Identifier: %s\n", body[k]);
					strcpy(body_identifiers[body_ident_index],body[k]);
                    body_ident_index++;
                }
                else {
                    strcpy(body_values[body_value_index], body[k]);
                    body_value_index++;
				}
			}
        }
        else if (strcmp("DOUBLE_ADD", body[j]) == 0) {
            strcpy(body_identifiers[body_ident_index], "DA");
            body_ident_index++;
            strcpy(body_values[body_value_index], "DA");
            body_value_index++;
            for (int k = j+1; k < j + 4; k++) {
                if (isalpha(body[k][0])) {
                    strcpy(body_identifiers[body_ident_index], body[k]);
                    body_ident_index++;
                }
                else {
                    strcpy(body_values[body_value_index], body[k]);
					body_value_index++;
                }
            }
        }
        else if (strcmp("SUB", body[j]) == 0) {
            strcpy(body_identifiers[body_ident_index], "S");
            body_ident_index++;
            strcpy(body_values[body_value_index], "S");
            body_value_index++;
            for (int k = j+1; k < j + 3; k++) {
                if (isalpha(body[k][0])) {
                    strcpy(body_identifiers[body_ident_index], body[k]);
                    body_ident_index++;
                }
                else {
                    strcpy(body_values[body_value_index], body[k]);
					body_value_index++;
                }
            }
        }
        else if (strcmp("DOUBLE_SUB", body[j])==0) {
            strcpy(body_identifiers[body_ident_index], "DS");
            body_ident_index++;
            strcpy(body_values[body_value_index], "DS");
            body_value_index++;
            for (int k = j+1; k < j + 4; k++) {
                if (isalpha(body[k][0])) {
					strcpy(body_identifiers[body_ident_index], body[k]);
					body_ident_index++;
                }
                else {
					strcpy(body_values[body_value_index], body[k]);
					body_value_index++;
                }
            }
        }
        else if (strcmp("MUL", body[j]) == 0) {
            strcpy(body_identifiers[body_ident_index], "M");
            body_ident_index++;
            strcpy(body_values[body_value_index], "M");
            body_value_index++;
            for (int k = j + 1; k < j + 3; k++) {
                if (isalpha(body[k][0])) {
                    strcpy(body_identifiers[body_ident_index], body[k]);
					body_ident_index++;
                }
                else {
                    strcpy(body_values[body_value_index], body[k]);
					body_value_index++;
                }
            }
        }
        else if (strcmp("DOUBLE_MUL", body[j]) == 0) {
            strcpy(body_identifiers[body_ident_index], "DM");
            body_ident_index++;
            strcpy(body_values[body_value_index], "DM");
            body_value_index++;
            for (int k = j + 1; k < j + 4; k++) {
                if (isalpha(body[k][0])) {
                    strcpy(body_identifiers[body_ident_index], body[k]);
					body_ident_index++;
                }
                else {
                    strcpy(body_values[body_value_index], body[k]);
					body_value_index++;
                }
            }
        }

        
	}
    if (strcmp("VOID", return_value[0]) == 0) {
		strcpy(return_identifier, "void");
    }
    else if (strcmp("INT", return_value[0]) == 0) {
		strcpy(return_identifier, "int");
	}
    else if (strcmp("UNSIGNED", return_value[0]) == 0) {
		strcpy(return_identifier, "unsigned");
    }
	main_cycle(args_identifiers, index, int_count, unsigned_count, body_identifiers, body_ident_index, body_values, body_value_index, return_identifier, let_count);
}
void divide_into_three(char buffer[300]) {
    char temp[300]="";
    int length = strlen(buffer);
    int value_count = 0;
	int body_count = 0;
	int return_count = 0;
    char* occurences_of_body = strchr(buffer, 'B');
    char* occurences_of_return = strchr(buffer, 'R');
    char args[4][300];
    char body[30][300];
    int args_length = 0;
	int body_length = 0;    
    char* splitter;
    char* counter;
    char return_value[1][300];
    for (int i = 0; i < length; i++) {
        int l = strlen(temp);
		temp[l] = buffer[i];
		temp[l + 1] = '\0';
        if (strstr(temp, "VALUES:") != NULL && value_count == 0) {
            char f_another_temp[300] = "";
            char s_another_temp[300] = "";
            for (int j = i + 1; j < occurences_of_body - buffer; j++) {
                int l = strlen(f_another_temp);
                f_another_temp[l] = buffer[j];
                f_another_temp[l + 1] = '\0';
            }

            int count = 0;
            int num = 0;
			size_t destination_size = sizeof(s_another_temp);
			strncpy(s_another_temp, f_another_temp,destination_size);
            s_another_temp[destination_size - 1] = '\0';
            counter=strtok(s_another_temp, " ");
            while (counter != NULL) {
				count += 1;
				counter = strtok(NULL, " ");
			}
			splitter=strtok(f_another_temp, " ");
            while (splitter != NULL) {
                if (num >= count) {
                    break;
                }
                strcpy(args[num], splitter);
                num++;
                splitter = strtok(NULL, " ");
            }
            value_count++;
			args_length = count;
        }
        else if (strstr(temp, "BODY:") != NULL && body_count == 0) {
            char f_another_temp[300] = "";
			char s_another_temp[300] = "";
            for (int j = i + 1; j < occurences_of_return - buffer; j++) {
                int l = strlen(f_another_temp);
                f_another_temp[l] = buffer[j];
                f_another_temp[l + 1] = '\0';
            }
            int count = 0;
            int num = 0;
            size_t destination_size = sizeof(s_another_temp);
            strncpy(s_another_temp, f_another_temp, destination_size);
            s_another_temp[destination_size - 1] = '\0';
            counter = strtok(s_another_temp, " ");
            while (counter != NULL) {
                count += 1;
                counter = strtok(NULL, " ");
            }
			splitter = strtok(f_another_temp, " ");
            while (splitter != NULL) {
                if (num >= count) {
                    break;
                }
                strcpy(body[num], splitter);
                num++;
                splitter = strtok(NULL, " ");
            }
			body_count++;
			body_length = count;
        }
        else if (strstr(temp,"RETURN:") != NULL && return_count == 0) {
            char another_temp[300] = "";
            for (int j = i + 1; j < length;j++) {
                int l = strlen(another_temp);
                another_temp[l] = buffer[j];
                another_temp[l + 1] = '\0';
            }
            strcpy(return_value[0], another_temp);
            return_count++;

        }
       
    }
	structure_determination(args, body, return_value, args_length, body_length);
}
int main() {
    srand(time(NULL));
    FILE* fptr;

    // Open a file in read mode
    fptr = fopen("format.mffd", "r");

    // Store the content of the file
    char myString[300];

    // If the file exist
    if (fptr != NULL) {
    while (fgets(myString, 300, fptr)) {
    }
}
    else {
        printf("Not able to open the file.");
        return;
}
    // Close the file
    fclose(fptr);
	divide_into_three(myString);

}