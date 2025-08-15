Setup Instructions


Extract the Project:

Unzip the submitted .zip file to a directory (e.g., C:\Users\lasyr\Desktop\ZaLes\School\2025\UNISA\COS2614 - Programming Contemporary Concepts\assignment3\).
Ensure the folder structure preserves LibraryManagementSystem and LibraryUtils as sibling directories.


Configure the Project:

Open Qt Creator.
Go to File > Open File or Project and select LibraryManagementSystem/LibraryManagementSystem.pro.
In the "Configure Project" dialog, select the appropriate Qt kit (e.g., Desktop Qt 5.3.0 MinGW 32-bit).
Build LibraryUtils First: Open LibraryUtils/LibraryUtils.pro, set to "Release" mode, and build the project (Build > Build Project "LibraryUtils") to generate the static library. Ensure the build directory (e.g., build-LibraryUtils-...) is a sibling to the LibraryManagementSystem build directory.
The LIBS path in LibraryManagementSystem.pro uses a relative path and should automatically link to the built LibraryUtils library.


Build the Main Application:

Return to the LibraryManagementSystem project in Qt Creator.
Set the build configuration to "Release".
Clean and build the project (Build > Clean All, then Build > Build Project "LibraryManagementSystem").
Check the "Compile Output" pane for any errors.


Run the Program:

Click the "Run" button (green play icon) in Qt Creator.
Alternatively, navigate to the build directory (e.g., build-LibraryManagementSystem-Desktop_Qt_5_3_0_MinGW_32bit-Release) and double-click the executable (LibraryManagementSystem.exe), ensuring library_data.txt is in the same directory.



Usage Instructions

Add a Book:
Enter Title, Author, ID, and Genre in the respective fields.
Click "Add Book" to add it to the list and save to library_data.txt.


Add a Magazine:
Enter Title, Author, ID, and Issue Number in the respective fields.
Click "Add Magazine" to add it to the list and save.


Search:
Type a partial title in the "Title Book" field and click "Search" to filter the list.
Clear the field and click "Search" to show all items.


Borrow/Return:
Select an item from the list and click "Borrow/Return" to toggle its status.
The status updates and is saved to library_data.txt.


Exit:
Close the application to save the current list to library_data.txt.



Notes

The program creates library_data.txt in the build directory if it doesn’t exist.
Ensure all paths in .pro files match your local setup to avoid build errors.
The code is documented with comments for clarity and compiles without errors in Qt Creator.

Troubleshooting

Build Errors: Verify include paths in .pro files and rebuild LibraryUtils first.
Missing Library: Check the LIBS path in LibraryManagementSystem.pro and rebuild LibraryUtils with a matching build directory structure.
File Not Found: Ensure library_data.txt is in the working directory or create an empty file manually.
