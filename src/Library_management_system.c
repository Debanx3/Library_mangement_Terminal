//Debanil_Chanda_102206129 & Shubham_Rajdev_102206175
//Library management Terminal 
//Windows API used

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h> 

#define SLEEP_TIME_LMT 200
#define MAX_PATH_LENGTH 260
#define Trapa 260

char folder_path[MAX_PATH_LENGTH] = "C:\\Users\\deban\\OneDrive\\Desktop\\c_project_dir\\Library_management_Terminal\\Lectures\\";

	int LOGI_SIGNUP;
	int  roll_number;
	char first_name[10];
	char last_name[10];
	int home_page_option;
	char course_name[30];
	int slide_number;
	int sheet_number;
	int sheet_solution_number;
	int sem_number;
	int question_paper_number;
	int question_paper_solution_number;
	
	
	char update_database_path();
	void home_page();
	void old_lecture_slides();
	void new_lecture_slides();
	void tutorial_sheets();
	void tutorial_solutions();
	void event_manager();
	void old_question_papers();
	void old_question_paper_solutions();
	void display_database();

void get_string_input(const char *prompt, char *buffer, int buffer_size){
    printf("%s", prompt);
    if (fgets(buffer, buffer_size, stdin) == NULL){
        perror("Error reading input");
        buffer[0] = '\0'; 
        return;
    }
    buffer[strcspn(buffer, "\n")] = 0;
}

void open_any_file_by_path(){
    printf("\n\t\t+ Welcome to the Any File Opener>");
    printf("\n\t\t  |-Please enter the FULL path to the file you want to open (e.g., C:\\Path\\To\\File.exe): \n\t\t  ");
    char user_file_path[MAX_PATH_LENGTH];
    get_string_input("", user_file_path, sizeof(user_file_path));

    FILE *fp = fopen(user_file_path, "rb");
    if (fp != NULL) {
        fclose(fp); 
        printf("\t\t   |-Attempting to open: %s\n", user_file_path);
        ShellExecute(NULL, "open", user_file_path, NULL, NULL, SW_SHOWNORMAL);
        printf("\t\t   |-File open command issued. Check your desktop/taskbar.\n");
    } else {
        printf("\t\t|-Error: File not found at path: %s\n", user_file_path);
        perror("\t\t  Reason"); 
    }
}	
void open_file(const char *subfolder, int identifier, const char *file_prefix, const char *extension){
		const char *allowed_extensions[] = {
            "txt", "docx", "xlsx", "ppt", "pdf", "mp4", "mkv"
        };
        int num_allowed_extensions = sizeof(allowed_extensions) / sizeof(allowed_extensions[0]);
        int is_allowed = 0; 
        char lower_extension[10];
        strncpy(lower_extension, extension, sizeof(lower_extension) - 1);
        lower_extension[sizeof(lower_extension) - 1] = '\0';
        for(int i = 0; lower_extension[i]; i++){
            lower_extension[i] = tolower((unsigned char)lower_extension[i]);
        }
        for(int i = 0; i < num_allowed_extensions; i++){
            if(strcmp(lower_extension, allowed_extensions[i]) == 0){
                is_allowed = 1;
                break;
            }
        }
        if (!is_allowed){
            printf("\t\t|-Error: File type '.%s' is not allowed.\n", extension);
            printf("\t\t  Allowed types: .txt, .docx, .xlsx, .ppt, .pdf, .mp4, .mkv\n");
            return; 
        }
        char full_file_path[MAX_PATH_LENGTH];
        snprintf(full_file_path, MAX_PATH_LENGTH, "%s\\%s\\SEM_%d\\%s\\%s%d.%s",
                 folder_path, subfolder, sem_number, course_name, file_prefix, identifier, extension);

        FILE *fp = fopen(full_file_path, "rb");
        if(fp != NULL){
            fclose(fp);
            printf("\t\t|-Opening file: %s\n", full_file_path);
            ShellExecute(NULL, "open", full_file_path, NULL, NULL, SW_SHOWNORMAL);
            printf("\t\t|-File opened successfully.\n");
        } 
		else{
            printf("\t\t|-Error: File not found at path: %s\n", full_file_path);
            perror("\t\t  Reason");
        }
}
	void clear_input_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
	void display_interface(){
    	printf("\t\tPreparing to run.....");
    	for(int k = 0; k < 15; k++){	
       			printf(".");
       			Sleep(Trapa); 
		}
        printf("\n");
        printf("\t\t");
        printf("=======================================LIBRARY MANAGEMENT SYSTEM========================================");
        printf("\n");
        printf("\t\t");
        printf("                                Welcome to the Library Management Terminal!");
        printf("\n\t\t========================================================================================================\n\t\t");
        printf("\n");
        printf("\t\t");
        printf("\033[1;32m                       ____            ____      ___    _________________\033[0m"); 
        printf("\n"); printf("\t\t");
        printf("\033[1;32m                       |@@@|           |@@@\\    /@@@|   |@@@@@@@@@@@@@@@|\033[0m"); printf("\n"); printf("\t\t");
        printf("\033[1;32m                       |@@@|           |@@@@\\  /@@@@|   |@@@@@@@@@@@@@@@|\033[0m"); printf("\n"); printf("\t\t");
        printf("\033[1;31m                       |@@@|           |@@@@@\\/@@@@@|         |@@@|\033[0m"); printf("\n"); printf("\t\t");
        printf("\033[1;31m                       |@@@|_______    |@@@@@@@@@@@@|         |@@@|\033[0m"); printf("\n"); printf("\t\t");
        printf("\033[1;34m                       |@@@@@@@@@@@|   |@@@@|\\/|@@@@|         |@@@|\033[0m"); printf("\n"); printf("\t\t");
        printf("\033[1;34m                       |@@@@@@@@@@@|   |@@@@|  |@@@@|         |@@@|\033[0m"); printf("\n"); 
        printf("\n\t\t=======================================================================================================\n\t\t");
        printf("                          > Made by:\t\tDEBANIL_CHANDA(102206129)\n\t\t\t\t\t\t\t\tSHUBHAM_RAJDEV(102206175)");
        printf("\n\t\t=======================================================================================================");
       }
       void login_or_signup(){
       		printf("\n\t\t> To enter the LMS, login: (or signup)"); printf("\n");
       		printf("\n\t\t+ To login to your account:                                            \033[1;32mPRESS '11'\033[0m");
       	    printf("\n\t\t+ To signup to the LMS:                                                \033[1;32mPRESS '22'\033[0m");
       	    printf("\n\t\t> Enter option: ");  
			scanf("%d",&LOGI_SIGNUP); clear_input_buffer();
				if(LOGI_SIGNUP == 11){
       				printf("\t\t> Loading.....");
       				for(int l = 0; l < 15; l++){	
       					printf(".");
       					Sleep(SLEEP_TIME_LMT); 
			   		}
					printf("\n\n\t\t> Enter your roll number: "); 
					scanf("%d",&roll_number); clear_input_buffer();
					printf("\t\t> Enter the first name (BLOCK LETTERS): ");
					scanf("%9s",&first_name); 
					printf("\t\t> Enter the last name (BLOCK LETTERS): ");
					scanf("%9s",&last_name);
					printf("\n\t\t=======================================================================================================");
					if(roll_number == 102206129 && strcmp(first_name,"DEBANIL") == 0 && strcmp(last_name,"CHANDA") == 0){
						printf("\n\t\tWelcome! %9s%9s(%d) to the LMT",first_name,last_name,roll_number);
					}
					else if(roll_number == 102206175 && strcmp(first_name,"SHUBHAM") == 0 && strcmp(last_name,"RAJDEV") == 0){
						printf("\n\t\tWelcome! %9s%9s(%d) to the LMT",first_name,last_name,roll_number);
					}
					else{
						printf("\n\t\tWarning! your credentials don't match");
					}
			}
	   			else if(LOGI_SIGNUP == 22){
					printf("\t\tEnter your details---->");
					printf("\n\t\tEnter your roll number: "); 
					scanf("%d",&roll_number); 
					clear_input_buffer();
					printf("\t\tEnter the first name: ");
					scanf("%9s",&first_name); 
					printf("\t\tEnter the last name: ");
					scanf("%9s",&last_name); 
					printf("\t\t========================================================================================");
					printf("\n\n\t\tSign up successfull! %9s%9s (%d) to the LMT",first_name,last_name,roll_number);
				}
}
       void home_page(){
       	 do{
       		printf("\n\t\t> Loading Home Page.....");
       		for(int k = 0; k < 15; k++){	
       			printf(".");
       			Sleep(SLEEP_TIME_LMT); 
			   }
            printf("\n\n\t\t+ To view old lecture slides from LMT database:                        \033[1;32mPRESS '1'\033[0m");
            printf("\n\t\t+ To view new lecture slides from LMT database:                        \033[1;32mPRESS '2'\033[0m");
            printf("\n\t\t+ To view tutorial sheets from LMT databse:                            \033[1;32mPRESS '3'\033[0m");
            printf("\n\t\t+ To view tutorial solutions from LMT databse:                         \033[1;32mPRESS '4'\033[0m");
            printf("\n\t\t+ To view upcoming events from LMT database:                           \033[1;32mPRESS '5'\033[0m");
       		printf("\n\t\t+ To view old question papers from LMT database:                       \033[1;32mPRESS '6'\033[0m");
       		printf("\n\t\t+ To view old question paper sols from LMT databse:                    \033[1;32mPRESS '7'\033[0m");
       		printf("\n\t\t+ To view LMT database:                                                \033[1;32mPRESS '8'\033[0m");
       		printf("\n\t\t+ To update LMT databse path:                                          \033[1;32mPRESS '9'\033[0m");
       		printf("\n\t\t+ To open any file from the disk drives by it's path:                  \033[1;32mPRESS '10'\033[0m");
       		printf("\n\t\t");
       		printf("\n\t\t=============================================================================================");
       		printf("\n\t\t\033[0;32m^ To open a file, from LMT databse first update the database path to the root directory c_project_dir\033[0m");
       		printf("\n\t\t> Enter option (enter 0 to terminate session): ");
			scanf("%d",&home_page_option);
			clear_input_buffer();
			printf("\t\t> Loading.....");
       				for(int l = 0; l < 15; l++){	
       					printf(".");
       					Sleep(SLEEP_TIME_LMT);
					}
			switch(home_page_option){			
				case 1: old_lecture_slides();
						break;
				case 2: new_lecture_slides();
						break;
				case 3:	tutorial_sheets();
						break;
				case 4: tutorial_solutions();
						break;
				case 5:	event_manager();
						break;
				case 6:	old_question_papers();
						break;
				case 7:	old_question_paper_solutions();
						break;
				case 8:	display_database();
						break;
				case 9: update_database_path();
						break;
				case 10: open_any_file_by_path(); 
                        break;
				default: printf("\n\t\tPage does not exist! session terminated...");
						break;
			}
	 	  }
	 		while(home_page_option != 0);
	 	}
	   void old_lecture_slides(){
	   		printf("\n\t\t+ Welcome to old lecture slides>");
	   		printf("\n\t\t	|-Enter slide number: ");	
			scanf("%d",&slide_number); 
			clear_input_buffer();
	   		printf("\t\t	|-Enter semester number: ");				
			scanf("%d",&sem_number); 
			clear_input_buffer();
	   		get_string_input("\t\t        |-Enter course name (max 29 chars): ", course_name, sizeof(course_name));
	   		char extension[10];
    		get_string_input("\t\t        |-Enter file extension (e.g., pdf, ppt, docx, mkv): ", extension, sizeof(extension));
    		open_file("Lectures", slide_number, "SL", extension);	
	   }
	   void new_lecture_slides(){
	   		printf("\n\t\t+ Welcome to new lecture slides>");
	   		printf("\n\t\t  |-Enter slide number: ");					
			scanf("%d",&slide_number);
			clear_input_buffer();
	   		printf("\t\t  |-Enter semester number: ");				
			scanf("%d",&sem_number);
			clear_input_buffer();
	   		get_string_input("\t\t  |-Enter course name (max 29 chars): ", course_name, sizeof(course_name));
	   		char extension[10];
    		get_string_input("\t\t  |-Enter file extension (e.g., pdf, ppt, docx, mkv): ", extension, sizeof(extension));
    		open_file("Lectures", slide_number, "SL", extension);			   		
	   }
	   void tutorial_sheets(){
	   		printf("\n\t\t+ Welcome to tutorial sheets>");
	   		printf("\n\t\t  |-Enter sheet number: ");					
			scanf("%d",&sheet_number);
			clear_input_buffer();
	   		printf("\t\t  |-Enter semester number: ");				
			scanf("%d",&sem_number);
			clear_input_buffer();
	   		get_string_input("\t\t  |-Enter course name (max 29 chars): ", course_name, sizeof(course_name));
	   		char extension[10];
    		get_string_input("\t\t  |-Enter file extension (e.g., pdf, ppt, docx, mkv): ", extension, sizeof(extension));
    		open_file("Lectures", slide_number, "SL", extension); 		
	   }
	   void tutorial_solutions(){
	   		printf("\n\t\t+ Welcome to tutorial solutions>");
	   		printf("\n\t\t  |-Enter sheet solution number: ");					
			scanf("%d",&sheet_solution_number);
			clear_input_buffer();
	   		printf("\t\t  |-Enter semester number: ");				
			scanf("%d",&sem_number);
			clear_input_buffer();
	   		get_string_input("\t\t  |-Enter course name (max 29 chars): ", course_name, sizeof(course_name));
	   		char extension[10];
    		get_string_input("\t\t  |-Enter file extension (e.g., pdf, ppt, docx, mkv): ", extension, sizeof(extension));
    		open_file("Lectures", slide_number, "SL", extension);	 		
	   }
	   void event_manager(){
	   		printf("\n\t\t+ Welcome to event manager>");
	   		printf("\n\t\t  |-Enter semester number: ");				
			scanf("%d",&sem_number);
			clear_input_buffer();
	   		get_string_input("\t\t  |-Enter course name (max 29 chars): ", course_name, sizeof(course_name)); 		
	   }
	   void old_question_papers(){
	   		printf("\n\t\t+ Welcome to old question papers>");
	   		printf("\n\t\t  |-Enter semester number: ");				
			scanf("%d",&sem_number);
			clear_input_buffer();
			printf("\t\t  |-Enter question paper number: ");				
			scanf("%d",&question_paper_number);
			clear_input_buffer();
	   		get_string_input("\t\t  |-Enter course name (max 29 chars): ", course_name, sizeof(course_name));
	   		char extension[10];
    		get_string_input("\t\t  |-Enter file extension (e.g., pdf, ppt, docx, mkv): ", extension, sizeof(extension));
    		open_file("Lectures", slide_number, "SL", extension);	 		
	   }
	   void old_question_paper_solutions(){
	   		printf("\n\t\t+ Welcome to old question paper solutions>");
	   		printf("\n\t\t  |-Enter semester number: ");				
			scanf("%d",&sem_number);
			clear_input_buffer();
			printf("\t\t  |-Enter question paper solution number: ");				
			scanf("%d",&question_paper_solution_number);
			clear_input_buffer();
	   		get_string_input("\t\t  |-Enter course name (max 29 chars): ", course_name, sizeof(course_name));
	   		char extension[10];
    		get_string_input("\t\t        |-Enter file extension (e.g., pdf, ppt, docx, mkv): ", extension, sizeof(extension));
    		open_file("Lectures", slide_number, "SL", extension);		
	   }
	   void display_database(){
		DIR *d;
		struct dirent *dir;
		d = opendir(folder_path);
	   	printf("\n\t\t+ The LMT databse:");
	   	if(d){
        		printf("\n\t\t  Files in '%s':\n", folder_path);
        		while((dir = readdir(d)) != NULL){
            		if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
            			float dir_d_name_size = (0.001)*(sizeof(dir->d_name));
                		printf("\t\t\t\t|- %s\t\t%f KB\n", dir->d_name, dir_d_name_size);
            		}
        		}
        		closedir(d);
    		} 
			else{
        		perror("Unable to open directory");
    		}
	   }
	   char update_database_path(){
	   		printf("\n\t\t+ Enter the new database path: ");
	   		get_string_input("",folder_path,sizeof(folder_path));
	   		printf("\t\t\t|-Database Updated!");
	   		return 'A';
	   }
    void main(void){
        display_interface();
        login_or_signup();
        home_page();	
    }
    
	