/*
------------------------------------------------------------------------
Modifications 2019 T.E. Gureyev

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

---------------------- NO WARRANTY ------------------
THIS PROGRAM IS PROVIDED AS-IS WITH ABSOLUTELY NO WARRANTY
OR GUARANTEE OF ANY KIND, EITHER EXPRESSED OR IMPLIED,
INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL THE AUTHOR BE LIABLE
FOR DAMAGES RESULTING FROM THE USE OR INABILITY TO USE THIS
PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA
BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR
THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH
ANY OTHER PROGRAM). 
------------------------------------------------------------------------
*/
//---------------------------------------------------------------------------
//	INCLUDE FILES
#include "stdafx.h"
#include "time.h"
#ifdef _WIN32
	#include "windows.h"
#endif
#include "XA_ini.h"
//---------------------------------------------------------------------------
//	LOCAL CONSTANT DEFINITIONS
//
//---------------------------------------------------------------------------
//	LOCAL MACRO DEFINITIONS
//
//---------------------------------------------------------------------------
//	LOCAL ENUMERATED DATA TYPES
//
//---------------------------------------------------------------------------
//	LOCAL STRUCTURE DEFINITIONS
//
//---------------------------------------------------------------------------
//	LOCAL IN-LINE FUNCTION DEFINITIONS
//
//---------------------------------------------------------------------------
//	GLOBAL FUNCTION PROTOTYPES
//
//---------------------------------------------------------------------------
//	LOCAL FUNCTION PROTOTYPES
//
//---------------------------------------------------------------------------
//	GLOBAL DATA DEFINITIONS
//
//---------------------------------------------------------------------------
//	STATIC DATA DEFINITIONS
//
/////////////////////////////////////////////////////////////////////////////
//
namespace xar
{
	//! Displays a simple message either in a console window or in a message box depending on the type of the project
	void DMessage(const string message_string)
	{
		#ifdef _WINDOWS_
			//AfxMessageBox(message_string.c_str(), MB_ICONINFORMATION);
		#else
			printf("%s\n", message_string.c_str());
		#endif
	}


	// A variant of the DMessage function with a simple pre-formatting added 
	//! Displays warnings formed from exception.what() strings
	void DWhat(const string what_out) 
	{
		string strTemp("WARNING: ");
		strTemp += what_out.c_str();
		strTemp += " !";
		#ifdef _WINDOWS_
			//AfxMessageBox(strTemp.c_str(), MB_ICONEXCLAMATION);
		#else
			printf("\n%s\n", strTemp.c_str());
		#endif
	}

	int _matherr(struct _exception* pE)
	//This function replaces the standard _matherr function referred to in <math.h> to make the
	//handling of errors produced by functions from math.h consistent with VO exception handling convention
	//NOTE!!!: if this function were 'inline', it would not be called by math.h functions
	//NOTE!!!: it has been noticed that this function is only called in the Debug project, and is not
	//called the Release project whether it is linked with CRT statically or dynamically.
	//NOTE the following extract from MSDN:
	//For special error handling, you can provide a different definition of _matherr. 
	//If you use the dynamically linked version of the C run-time library (MSVCRT.DLL),
	//you can replace the default _matherr routine in a client executable with a user-defined version. 
	//However(!!!!), you cannot replace the default _matherr routine in a DLL client of MSVCRT.DLL.
	{
		char description[128];
		switch (pE->type)
		{
		case _DOMAIN:
			strcpy(description, "argument domain error");
			break;
		case _SING:
			strcpy(description, "argument singularity");
			break;
		case _OVERFLOW:
			strcpy(description, "overflow range error");
			break;
		case _PLOSS:
			strcpy(description, "partial loss of significance");
			break;
		case _TLOSS:
			strcpy(description, "total loss of significance");
			break;
		case _UNDERFLOW:
			//strcpy(description, "the result is too small to be represented"); // (This condition is not currently supported.)
			return int(pE->type);
			break;
		default:
			strcpy(description, "unknown math error");
		}
		throw std::runtime_error(description);
		return int(pE->type);
	}


	double ExeTimer(bool initialize)
	{
		static double oldtime = 0.0;
		
		#ifdef _WIN32
			double newtime = (double)GetTickCount() / 1000.0;
		#else
			double newtime = (double)time(NULL);
		#endif
		double temp = newtime - oldtime;

		if (initialize) oldtime = newtime;

		return temp;
	}


	string ExeTimer1()
	{
		double dtemp = ExeTimer(true);

		char buffer[128];
		sprintf(buffer, "%g", dtemp);

		return string(buffer);
	}

}

/////////////////////////////////////////////////////////////////////////////
//
//	End of Module
//
