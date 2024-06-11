#include <stdio.h>
#include <stdlib.h>
#include <dialog.h>
#include <unistd.h>


// Renaming structure to avoid the
// repetitive use of struct keyword
typedef struct ToDo todo;

// Declaration of structure
struct ToDo {
    // char array as data part
    char buffer[101];

    // Pointer part to access addresses
    todo* next;

    // Count variable for counting
    // the number of nodes
    int count;
};

// Declare start pointer as null in
// the beginning
todo* start = NULL;


// Driver Code
int main()
{

    init_dialog(stdin, stdout);
    char* choice;

    while (1) {


            char *modes[] =
    {
        "1", "To see your ToDo list",
        "2", "To create new ToDo",
        "3", "To delete your ToDo",
        "4", "Exit",

    };
    dlg_clr_result();
    init_dialog(stdin, stdout);
    dialog_menu("TO DO APP", "Choose an option.", 0, 0, 0, 4, modes);
    end_dialog();

        choice=dialog_vars.input_result;
        switch (*choice) {

        // Calling functions defined
        // below as per the user input
        case '1':
  
    init_dialog(stdin, stdout);
    dialog_msgbox("TO DO APP", "Choose an option.", 0, 0,1);
    end_dialog();
            break;
            
        case '2':

    init_dialog(stdin, stdout);
    dialog_msgbox("TO DO APP", "Choose an option.", 0, 0,1);
    end_dialog();
            break;
            
        case '3':

    init_dialog(stdin, stdout);
    dialog_msgbox("TO DO APP", "Choose an option.", 0, 0,1);
    end_dialog();
            break;
            
        case '4':
        system("clear");
            exit(1);
	    
            break;
            
        default:
            printf("\nInvalid Choice :-(\n");

        }
    }
    system("clear");
    return 0;
}
