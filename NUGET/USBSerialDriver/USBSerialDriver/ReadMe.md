# Read Me 
This is a dll that is written to give basic access to the USB Serial interface (technically any COM interface). This library is written to be able to be accessed by both managed and unmanaged code, and is specifically exporting some CLI/C++ classes to managed and some C++ classes to unmanaged. When using the unmanaged functions this dll is exposing C++ classes and therefore can only be used in a C++ project. Please note this is all from the windows programming perspective and is intended to be used with Visual Studio.
## Constructing the Managed Portion of the DLL
VS (Visual Studio) provides a template for "CLR DLL Library" under the available templates, using this will expedite the switches for setting the project to use the CLR tool set and make a single accessible CLI Class to start. However to convert a project that was built as a native C++ project to a CLI\C++ project do the following. 

Please note that a walk through is not being linked for this part of the walk through as I don't have a link to a walkthrough for how to do this. Constructing CLI/C++ projects that utilize CLR is something I have had to do on many occaisions during my time at IBM Watson and Virtek Vision International
### How to construct a CLI\C++ project
* If not starting from a DLL project set the output type of the project to be a DLL project.
* Turn on the CLR (Common Language Runtime) tool set for the project, this can be found under:
  * "Properties > Configuration Properties > C\C++ > General > Common Language RunTime Support"
* Go through the properties of all of the .cpp files and turn off CLR on files used by unmanaged classes
* Build the project
    * When running the build after the initial switch to CLR VS will output a bunch of errors such as complaints about the PCH (PreCompiled Headers) as CLI classes cannot create PCH and will need to be changed to use, and native C++ classes will not be able to use the PCH so they will need to be set to create or have them turned off. There are also several flags related to the debugging database and symbols settings that won't work for the CLI classes that may need to be changed
* Add a new managed class, this will have the "ref" keyword and use the structure: \<public ref class USBSerialDataController\> 
  * The keyword ref tells the compiler that this is a managed CLI\C++ class (Common Lanaguage Interface) and that is can be used by C#
  * When making CLI class with the "ref" keyword its best practice to encapsulate the class in a namespace else it will be difficult to use in C# as there will not be any available "using \<namespace\>" containing the CLI\C++ class
  * To include unmanaged code use "#include" as normal
  * To import managed code use "using namespace \<namespace name\>" this can be used to include other ref classes or C# classes and objects
  * Unmanaged class members and functions that take unmanaged arguments cannot be accessed by non-CLI managed classes (C#)
  * Managed class members and functions that take managed arguments cannot be accessed by non-CLI unmanaged classes (native C++)
  * C# argument names must be proceeded with ^ to signify the reference to the managed object type
  * The CLI CPP files can mix managed and unmanaged code, this gives an easy way to convert from managed to unmanaged and unmanaged to managed data
  * Due to the fact that managed and unmanaged memory use different systems to determine where and how variables are being stored, object references can't be maintained between a managed and unmanaged object i.e. a void * to a managed object can't be kept in a C++ class

### How to Access a CLI\C++ class from C#
* Add the CLI\C++ project as a reference
* Add the using statement for the namespace that contains the required classes
  * Not only CLI\C++ ref calsses can be included by C#
  * The included class must have a CPP file with CLR turned on 
* Construct and instance, access static, call an instance of a singleton, etc. of the CLI class needed in the C# layer 
* This CLI\C++ class should be used as a bridge between the C# and the C++ as this will simplify the inlcudes (this will simplify mixing the languages).
### How to Access a CLI\C++ class from C# (Inside the same project)
* Turn on CLR for the CPP file of the C++ class
* Add the CLI\C++ .h file in an include statement at the top of the file using the CLI class
  * Note that if including the CLI\C++ classes managed into an unmanaged class the following must be done
    * Turn on CLR for the CPP file containing the unmanaged class
    * Isolate this unmanaged C++ class from the other C++ classes using this class as a bridge i.e. keep the CLI\C++ references out of the .h file for the non-CLI C++ class. Make the reference to the managed code for the CPP file (this will simplify mixing the languages)
## Constructing the Unmanaged Portion of the DLL
As with the Managed DLL instructions VS provides a new project template for creating a C++ DLL project, if making a new project that only needs to be used as a C\C++ DLL this template works well. Instructions for how to construct this type of DLL can be found here: https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170 .

I suggest that if making a mixed DLL (managed and unmanaged that can be consumed by managed or unmanaged), start with the CLR DLL project template as there are more overall switches to make CLR work.

The following instructions are for constructing a DLL that uses a ".LIB" to map the functions in the dll, please keep in mind there are several different DLL types that can be made and different linking strategies however this DLL is using the .LIB to link the functions in this DLL as this is just a straight forward linking method.
### How to Construct C\C++ DLL From an existing project
* If the project is not already a DLL project change the project output to be a DLL type output
* Add a new "dllmain.cpp" entry point (an example can be created by deploying a sample project from VS or can be found in the link in the abstract for this section). 
  * This file will give the application using it some base information for how to load the library, and if not using the a .lib or a definition file (i.e. a hot load from _load library) it will allow the application to construct the required "documents" for the library
* In the precompiled header for the project or the stdafx (or any common header) create a preprocessor to manage the export/import to/from the dll. This preprocessor should have the following form:
``` 
#ifdef <export preprocessor> (typically <LibraryName>_EXPORTS) 
    #define <API preprocessor> (Typically <LibraryName>_API) __declspec(dllexport) 
#else 
    #define <API preprocessor> (Must be the same as the one chosen above)  __declspec(dllimport) 
#endif
```

* * The above preprocessors do the following things
* * * Lets the system know if the preprocessor is to export the functions into the DLL in a way that can be imported (the dll will contain all of the functions written, but will only index those functions designated with a dll export. These fucntion references will be added to the .lib file)
* * * Lets the system know if the proprocessor is for import from the DLL and when used by an application will allow for the required functions to be loaded from the DLL
* * * The state is determined by the inlcusion or exclusion of the  \<export preprocessor\> if its added to the project then the application will try to export the targets, if the preprocessor is absent from the project the application will try to import the targets from the library
* Add this preprocessor to the preprocessors of the project for all build modes that can create the native C++ compatible dll (This is missing from the VS and should still be done if working on a new dll project)
  * The preprocessors for the project can be found:  "Properties > Configuration Properties > C\C++ > Preprocessor > Preprocessor Definitions"
* Make a new header file for export
  * A project can have as many as needed
  * This can be a class however, if the DLL exports classes, class functions or any class members it will only be usable by other C++ projects. However if only exporting functions than many C-style languages can use the constructed DLL if only functions, structs, and values are exported (C and VB will be able to consume the new DLL)
* Identify the export targets and prepend them with the API preprocessor \<API preprocessor\>
  * If nothing is added as export no .Lib file will be constructed at build, this can be helpful during troubleshooting and to ensure the exports were added correctly
* Once all of the export targets have had the API preprocessor prepended to it, build the project, this should create an .EXP file, .LIB file and the .DLL file.

### How to Access the C++ from a C++ Application (or other library)
* Copy the header files from the DLL that contain export targets to a headers folder that is accessible to the application that will consume the library (technically the project DLL directory can work if the dll source code doesn't need to be hidden)
* Copy the .dll and the .lib to a libraries folder that is accessible to the application that will consume the library
* From the C++ Application (or other Library) navigate to the additional includes and add the headers directory to the additional includes
  * Properties > Configuration Properties > C/C++ > General > Additional Includes Directories
* From the C++ Application (or other Library) add the library direcotry to the Additional Library Directories
  * Properties > Configuration Properties > Linker > General > Additional Library Directories
* From the C++ Application (or other Library) add the .lib file to the Additional Dependencies so that the exported values can be discoverable
  * Properties > Configuration Properties > Linker > Input > Additional Dependencies
* The last step is copying the dll into the output directory this can be done with the post build events and an xcopy statement, but can also be done manually. To do it manually build the project once, after it fails copy the .dll and the .lib into the output directory (debug, release, etc.) and build again.
* The DLL functions and headers can now be used and included