#pragma once

#include <string>

using namespace System;

/// <summary>
/// This is a static class used to hold all of the necessary interop conversion functions
/// </summary>
namespace InteropTools
{
	public ref class Interop
	{
	private:
		/// <summary>
		/// This is lifted from the microsoft documentation for how to marshal strings (I can never remember how to make ANSI strings)
		/// https://docs.microsoft.com/en-us/cpp/dotnet/how-to-convert-system-string-to-standard-string?view=msvc-160
		/// </summary>
		/// <param name="sourceString">This is the managed string being converted</param>
		/// <param name="outputString">This is the output unmanaged string after conversion</param>
		static void MarshalToNativeString(String^ sourceString, std::string& outputString)
		{
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sourceString)).ToPointer();
			outputString = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

	public:
		/// <summary>
		/// This is just a convinence function so this can be used without needed to construct and assign these variables over and over
		/// </summary>
		/// <param name="sourceString"></param>
		/// <returns></returns>
		static std::string MarshalString(String^ sourceString)
		{
			std::string outputString;
			MarshalToNativeString(sourceString, outputString);
			return outputString;
		}
	};
}


