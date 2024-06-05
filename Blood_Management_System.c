#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BLOOD_GROUPS 100

struct Blood_Group {
    char Blood_Type[10];
    int quantity;
};

void Add_Blood_Group(struct Blood_Group *Blood_Groups, int *count);
void Delete_Blood_Group(struct Blood_Group *Blood_Groups, int *count, const char *Blood_Type);
int Search_Blood_Group(struct Blood_Group *Blood_Groups, int count, const char *Blood_Type);
void Create_Blood_Group_Package(struct Blood_Group *Blood_Groups, int count, const char *packageDetails);
void Display_Blood_Groups(struct Blood_Group *Blood_Groups, int count);
void Update_Blood_Quantity(struct Blood_Group *Blood_Groups, int count, const char *Blood_Type, int quantity);

int main() {
    struct Blood_Group Blood_Groups[MAX_BLOOD_GROUPS];
    int count = 0;
    int choice;
    char Blood_Type[10];
    int quantity;

    while (1) {
        printf("\nBlood Bank Management System\n");
        printf("1. Add Blood Group\n");
        printf("2. Delete Blood Group\n");
        printf("3. Search Blood Group\n");
        printf("4. Display Blood Groups\n");
        printf("5. Update Blood Quantity\n");
        printf("6. Create Blood Group Package\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Add_Blood_Group(Blood_Groups, &count);
                break;
            case 2:
                printf("Enter blood type to delete: ");
                scanf("%s", Blood_Type);
                Delete_Blood_Group(Blood_Groups, &count, Blood_Type);
                break;
            case 3:
                printf("Enter blood type to search: ");
                scanf("%s", Blood_Type);
                if (Search_Blood_Group(Blood_Groups, count, Blood_Type) != -1) {
                    printf("Blood group found.\n");
                } else {
                    printf("Blood group not found.\n");
                }
                break;
            case 4:
                Display_Blood_Groups(Blood_Groups, count);
                break;
            case 5:
                printf("Enter blood type to update: ");
                scanf("%s", Blood_Type);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                Update_Blood_Quantity(Blood_Groups, count, Blood_Type, quantity);
                break;
            case 6:
                Create_Blood_Group_Package(Blood_Groups, count, "PackageDetails");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Add Blood Group
void Add_Blood_Group(struct Blood_Group *Blood_Groups, int *count) {
    if (*count >= MAX_BLOOD_GROUPS) {
        printf("Blood group array is full!\n");
        return;
    }
    char Blood_Type[10];
    int quantity;
    printf("Enter blood type: ");
    scanf("%s", Blood_Type);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    strcpy(Blood_Groups[*count].Blood_Type, Blood_Type);
    Blood_Groups[*count].quantity = quantity;
    (*count)++;
    printf("Blood group added successfully.\n");
}

// Delete Blood Group
void Delete_Blood_Group(struct Blood_Group *Blood_Groups, int *count, const char *Blood_Type) {
    int index = Search_Blood_Group(Blood_Groups, *count, Blood_Type);
    if (index == -1) {
        printf("Blood group not found.\n");
        return;
    }
    for (int i = index; i < *count - 1; i++) {
        Blood_Groups[i] = Blood_Groups[i + 1];
    }
    (*count)--;
    printf("Blood group deleted successfully.\n");
}

// Search Blood Group
int Search_Blood_Group(struct Blood_Group *Blood_Groups, int count, const char *Blood_Type) {
    for (int i = 0; i < count; i++) {
        if (strcmp(Blood_Groups[i].Blood_Type, Blood_Type) == 0) {
            return i;
        }
    }
    return -1;
}

// Display Blood Group
void Display_Blood_Groups(struct Blood_Group *Blood_Groups, int count) {
    if (count == 0) {
        printf("No blood groups available.\n");
        return;
    }
    printf("Available blood groups:\n");
    for (int i = 0; i < count; i++) {
        printf("Blood Type: %s, Quantity: %d\n", Blood_Groups[i].Blood_Type, Blood_Groups[i].quantity);
    }
}

// Update Blood Quantity
void Update_Blood_Quantity(struct Blood_Group *Blood_Groups, int count, const char *Blood_Type, int quantity) {
    int index = Search_Blood_Group(Blood_Groups, count, Blood_Type);
    if (index == -1) {
        printf("Blood group not found.\n");
        return;
    }
    Blood_Groups[index].quantity = quantity;
    printf("Blood quantity updated successfully.\n");
}

// Blood Group Packages
void Create_Blood_Group_Package(struct Blood_Group *Blood_Groups, int count, const char *packageDetails) {
    printf("Creating blood group package: %s\n", packageDetails);
    Display_Blood_Groups(Blood_Groups, count);
}
