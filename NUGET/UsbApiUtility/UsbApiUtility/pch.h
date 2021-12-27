// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H
// add additional preprocessors here

#ifdef DRIVER_EXPORTS
#define DRIVER_API __declspec(dllexport) 
#else
#define DRIVER_API __declspec(dllimport) 
#endif

//This warning is for ensuring that when an enum is used in a switch that all values are checked
//I have some converters added to this library that rely on bridging managed and unmanaged components
#pragma warning(error : 4061)

// add headers that you want to pre-compile here

#endif //PCH_H
