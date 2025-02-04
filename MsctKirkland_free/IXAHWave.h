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

#if !defined IXAHWAVE_H
#define IXAHWAVE_H

//---------------------------------------------------------------------------
//	INCLUDE FILES
//
#include "IXAHead.h"

//---------------------------------------------------------------------------
//	FORWARD REFERENCES
//
//---------------------------------------------------------------------------
//	CONSTANT DEFINITIONS
//
//---------------------------------------------------------------------------
//	TYPEDEFS
//
//---------------------------------------------------------------------------
//	MACRO DEFINITIONS
//
//---------------------------------------------------------------------------
//	ENUMERATED DATA TYPES
//
//---------------------------------------------------------------------------
//	STRUCTURE DEFINITIONS
//
//---------------------------------------------------------------------------
//	IN-LINE FUNCTION DEFINITIONS
//
//---------------------------------------------------------------------------
//	CLASS DECLARATIONS
//
//	Note that although the following entity is declared as 'struct', it is in fact 
//	a pure abstract class (interface)
//---------------------------------------------------------------------------
//Struct IXAHWave1D
//
//	Interface class to Wavehead1D heads
//
/*!
	\brief		Interface class to Wavehead1D heads
	\par		Description:
				This interface augments IXAHead with Wavehead1D-specific functions. 
				It allows manipulation of physical parameters corresponding to a 1D scalar wave
	\remarks	Default units for physical array bounds, etc., in Waveheads are MICRONS
	\remarks	This class is an interface, i.e. it contains only pure virtual functions and no
				data members.
	\remarks	This class, being an interface, is declared as 'struct' for convenience, compatibility
				with C-clients and following the common practice advocated e.g. by Microsoft
*/
struct XA_API IXAHWave1D : public IXAHead
{
// Constructors
	//! Virtual destructor (needed for proper clean-up)
	virtual ~IXAHWave1D() {}

// Overridables
	//! Returns wavelength
	virtual double GetWl() const = 0;
	//! Returns lower physical boundary
	virtual double GetXlo() const = 0;
	//! Returns higher physical boundary
	virtual double GetXhi() const = 0;
	//! Sets wavelength, lower and higher physical boundaries
	virtual void SetData(double dblWl, double dblXlo, double dblXhi) = 0;
	//! Returns step in physical units
	virtual double GetStep(index_t NumPoints) const = 0;
	//! Resizes the head in accordance with the owner XArray1D
	virtual void Resize(index_t OldNumPoints, index_t NewNumPoints) = 0;
	//! Swaps the lower and upper physical boundaries
	virtual void Flip(void) = 0;
	//! Trims the head in accordance with the owner XArray1D
	virtual void Trim(index_t OldNumPoints, index_t lngLeft, index_t lngRight) = 0;
	//! Pads the head in accordance with the owner XArray1D
	virtual void Pad(index_t OldNumPoints, index_t lngLeft, index_t lngRight) = 0;
	//! Moves the head (separately from the owner XArray1D)
	virtual void Move(index_t NumPoints, long lngMovePoints) = 0;
};

//---------------------------------------------------------------------------
//Struct IXAHWave2D
//
//	Interface class to Wavehead2D heads
//
/*!
	\brief		Interface class to Wavehead2D heads
	\par		Description:
				This interface augments IXAHead with Wavehead2D-specific functions.
				It allows manipulation of physical parameters corresponding to a 2D scalar wave
	\remarks	Default units for physical array bounds, etc., in Waveheads are MICRONS
	\remarks    Here x corresponds to m_dim2 of XArray2D<T>, and y corresponds to m_dim1
	\remarks	This class is an interface, i.e. it contains only pure virtual functions and no
				data members.
	\remarks	This class, being an interface, is declared as 'struct' for convenience, compatibility
				with C-clients and following the common practice advocated e.g. by Microsoft
*/
struct XA_API IXAHWave2D : public IXAHead
{
// Constructors
	//! Virtual destructor (needed for proper clean-up)
	virtual ~IXAHWave2D() {}

// Overridables
	//! Returns wavelength
	virtual double GetWl() const = 0;
	//! Returns lower physical y-boundary
	virtual double GetYlo() const = 0;
	//! Returns higher physical y-boundary
	virtual double GetYhi() const = 0;
	//! Returns lower physical x-boundary
	virtual double GetXlo() const = 0;
	//! Returns higher physical x-boundary
	virtual double GetXhi() const = 0;
	//! Sets wavelength, lower and upper x- and y-boundaries
	virtual void SetData(double dblWl, double dblYlo, double dblYhi, double dblXlo, double dblXhi) = 0;
	//! Returns y-step in physical units
	virtual double GetYStep(index_t NumYPoints) const = 0;
	//! Returns x-step in physical units
	virtual double GetXStep(index_t NumXPoints) const = 0;
	//! Resizes the head in accordance with the owner XArray2D
	virtual void Resize(index_t OldNumYPoints, index_t OldNumXPoints, index_t NewNumYPoints, index_t NewNumXPoints) = 0;
	//! Transposes the head (swaps X and Y dimensions) in accordance with the owner XArray2D
	virtual void Transpose(void) = 0;
	//! Trims the head in accordance with the owner XArray2D
	virtual void Trim(index_t OldNumYPoints, index_t OldNumXPoints, index_t lngYLeft, index_t lngYRight, index_t lngXLeft, index_t lngXRight) = 0;
	//! Pads the head in accordance with the owner XArray2D
	virtual void Pad(index_t OldNumYPoints, index_t OldNumXPoints, index_t lngYLeft, index_t lngYRight, index_t lngXLeft, index_t lngXRight) = 0;
	//! Moves the head (separately from the owner XArray2D)
	virtual void Move(index_t NumYPoints, index_t NumXPoints, long lngMoveYPoints, long lngMoveXPoints) = 0;
};

//---------------------------------------------------------------------------
//Struct IXAHWave3D
//
//	Interface class to Wavehead3D heads
//
/*!
	\brief		Interface class to Wavehead3D heads
	\par		Description:
				This interface augments IXAHead with Wavehead3D-specific functions.
				It allows manipulation of physical parameters corresponding to a 3D scalar wave
	\remarks	Default units for physical array bounds, etc., in Waveheads are MICRONS
	\remarks    Here x corresponds to m_dim3 of XArray3D<T>, y corresponds to m_dim2 and z cprresponds to m_dim1
	\remarks	This class is an interface, i.e. it contains only pure virtual functions and no
				data members.
	\remarks	This class, being an interface, is declared as 'struct' for convenience, compatibility
				with C-clients and following the common practice advocated e.g. by Microsoft
*/
struct XA_API IXAHWave3D : public IXAHead
{
// Constructors
	//! Virtual destructor (needed for proper clean-up)
	virtual ~IXAHWave3D() {}

// Overridables
	//! Returns wavelength
	virtual double GetWl() const = 0;
	//! Returns lower physical z-boundary
	virtual double GetZlo() const = 0;
	//! Returns higher physical z-boundary
	virtual double GetZhi() const = 0;
	//! Returns lower physical y-boundary
	virtual double GetYlo() const = 0;
	//! Returns higher physical y-boundary
	virtual double GetYhi() const = 0;
	//! Returns lower physical x-boundary
	virtual double GetXlo() const = 0;
	//! Returns higher physical x-boundary
	virtual double GetXhi() const = 0;
	//! Sets wavelength, lower and upper x-, y- and z-boundaries
	virtual void SetData(double dblWl, double dblZlo, double dblZhi, double dblYlo, double dblYhi, double dblXlo, double dblXhi) = 0;
	//! Returns z-step in physical units
	virtual double GetZStep(index_t NumZPoints) const = 0;	
	//! Returns y-step in physical units
	virtual double GetYStep(index_t NumYPoints) const = 0;
	//! Returns x-step in physical units
	virtual double GetXStep(index_t NumXPoints) const = 0;
	//! Resizes the head in accordance with the owner XArray3D
	virtual void Resize(index_t OldNumZPoints, index_t OldNumYPoints, index_t OldNumXPoints, index_t NewNumZPoints, index_t NewNumYPoints, index_t NewNumXPoints) = 0;
	//! Trims the head in accordance with the owner XArray3D
	virtual void Trim(index_t OldNumZPoints, index_t OldNumYPoints, index_t OldNumXPoints, index_t lngZLeft, index_t lngZRight, index_t lngYLeft, index_t lngYRight, index_t lngXLeft, index_t lngXRight) = 0;
	//! Pads the head in accordance with the owner XArray3D
	virtual void Pad(index_t OldNumZPoints, index_t OldNumYPoints, index_t OldNumXPoints, index_t lngZLeft, index_t lngZRight, index_t lngYLeft, index_t lngYRight, index_t lngXLeft, index_t lngXRight) = 0;
	//! Moves the head (separately from the owner XArray3D)
	virtual void Move(index_t NumZPoints, index_t NumYPoints, index_t NumXPoints, long lngMoveZPoints, long lngMoveYPoints, long lngMoveXPoints) = 0;
};
//---------------------------------------------------------------------------
//	EXTERNAL DATA DECLARATIONS
//
//---------------------------------------------------------------------------
//	EXTERNAL FUNCTION PROTOTYPES
//
// Class Factory functions for WaveheadND classes
// (implemented in IXAHWave.cpp)
//
//! Creates a Wavehead1D object and returns an interface pointer to it
XA_API IXAHWave1D* CreateWavehead1D();
//! Creates a Wavehead2D object and returns an interface pointer to it
XA_API IXAHWave2D* CreateWavehead2D();
//! Creates a Wavehead3D object and returns an interface pointer to it
XA_API IXAHWave3D* CreateWavehead3D();

#endif //IXAHWAVE_H
/////////////////////////////////////////////////////////////////////////////
//
//	End of Header File
//
