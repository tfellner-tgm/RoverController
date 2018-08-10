# RoverController

## Requirements

To devolop and execute: Visual Studio
To view the Model: Enterprise Architect

## Development and Execution

Open the solution file (```RoverCommunicationsLib.sln```).
Set RoverController as the StartUp Project.
On the right side in the Solution Explorer, 
* right click RoverController and under Configuration Properties > C/C++ > General > Additional Include Directories add the RoverCommunicationLib folder
* right click RoverCommunicationsLib and under Configuration Properties > Librarian > General > Additional Dependencies add these libraries ``` WS2_32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib```
Now you can start developing the RoverController.
