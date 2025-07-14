* ### Author: Debanil Chanda @github.com
* ### Date: 12th July 2025
* ### Date of upload: 13th July 2025

* # Project Title: Library Management Terminal
* ### Description: Terminal based basic library management system.

* ### functions:
   * Login with correct credentials: *Remember by virtue of its design, the app only works if you enter (Roll number: 102206129,First name: DEBANIL, Last name:CHANDA) as credentials.
   * view LMT databse root directory: *Remember by virtue of its design, always paste the path of the folder where you have kept the extracted file i.e,update in:
   >char folder_path[MAX_PATH_LENGTH] = ".....path..to..the..folder..where...you...have..saved...the..extracted...file\\Library_management_Terminal\\Lectures\\";
   * by default the path is given for 'lecture' dir that is present in this .zip file!
   * change LMT databse  root directory using new path
   * open slides and sheets using slide/sheet options
   * open any file(.pdf,.ppt,.xlsx,.mp4,.mkv etc)  using its path
   * display size of directories with their names


* ### How to Run (Pre-compiled .exe):

   > Ensure you are using WINDOWS:
   * Download the entire 'Library_management_Terminal' folder zip file by clicking 'download zip' under 'code' in the repository and then extract it to unzip at any location on your device.
   * Navigate to the executable file: Go to the 'bin' folder.
   * Double-click 'Library_management_system.exe' to run it.
   * If you encounter missing DLL errors, please refer to the 'Troubleshooting' section.
   * (And in troubleshooting, explain that necessary runtime DLLs are in compiler/mingw64/bin and how to add them to PATH or copy them to bin/).


* ### How to Run the Library Management System (LMS) ? ----->
   >The LMS is a WINDOWS console-based application, meaning it runs within a terminal window like 'Command Prompt' or 'PowerShell' only.


* ### How to Build from Source (if desired):

   * Ensure you have git (github_desktop + git_bash) installed to clone the repository.
   * Alternatively, download the ZIP archive from the repo.
   * Navigate to the project's root directory 'Library_management_Terminal/'.
   * You can use the provided portable GCC compiler located in 'compiler/minGW/bin/'.
   * Open a command prompt or terminal in the project root.
   * Run the following command to compile: 'compiler/minGW/bin/gcc -o bin/Library_management_system.exe src/Library_management_system.c -lwinmm'
   * After successful compilation, the executable will be in the 'bin/' folder.


* ### Features: List key functionalities (view slides, sheets, etc.)

   * ![Zip folder structure:](https://github.com/Debanx3/Library_mangement_Terminal/blob/main/Folder_structure.png "Folder structure for LMT")

   * UI of the application:
   * 
        ![Zip folder structure:](https://github.com/Debanx3/Library_mangement_Terminal/blob/main/Folder_structure.png "Folder structure for LMT")
     
   * Database Path: The original LMT databse path is your 'C:\....' drive where the OS is stores. it will display all directories in your C drive. To update the databse path follow the app       rules while it runs
   * Troubleshooting: Common issues (e.g., "File not found" when opening Reddit.exe – explain it needs the full path to the actual executable, not a shortcut).
   * Contributing: Send a pull request to contribute.....


* ### License (Optional): MIT License
* ### Contact/Credits: Debanil Chanda, [DebanX3@github.com](mailto:debanx3@github.com)



