#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 10 // Maximum length of the name field

struct record {
    char date[12];
    int id; 
    char name[MAX_NAME_LENGTH + 1]; // +1 for null terminator
    unsigned int total;
    int percentage;
};

void add() {
    FILE *fp;
    struct record st;
    char date[12];
    time_t current_time = time(NULL); // Get current time
    struct tm *time_info = localtime(&current_time); // Convert to local time

    // Open file for appending in binary mode
    fp = fopen("Fileprac.txt", "ab");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Format current date
    sprintf(date, "%02d/%02d/%d", time_info->tm_mday, time_info->tm_mon + 1, time_info->tm_year + 1900);
    strcpy(st.date, date);

    // Input id
    printf("Enter the id: ");
    scanf("%d", &st.id);

    // Input name
    printf("Enter the name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", st.name); // No need for & for strings

    // Input total
    printf("Enter the total: ");
    scanf("%u", &st.total);

    // Added successfully
    printf("Added successfully\n");

    // Write record to file
    fwrite(&st, sizeof(st), 1, fp);

    // Close file
    fclose(fp);
}

int main() {
    add(); // Call add function
    return 0;
}
