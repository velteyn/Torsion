/////////////////////////////////////////////////////////////////////////////
// Name:        src/palmos/joystick.cpp
// Purpose:     wxJoystick class
// Author:      William Osborne - minimal working wxPalmOS port
// Modified by:
// Created:     10/13/04
// RCS-ID:      $Id: joystick.cpp,v 1.4 2005/01/24 07:38:51 ABX Exp $
// Copyright:   (c) William Osborne
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "joystick.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "wx/string.h"
#include "wx/window.h"
#include "wx/palmos/joystick.h"

IMPLEMENT_DYNAMIC_CLASS(wxJoystick, wxObject)

// Attributes
////////////////////////////////////////////////////////////////////////////

wxJoystick::wxJoystick(int joystick)
{
};

wxPoint wxJoystick::GetPosition() const
{
    return wxPoint(0, 0);
}

int wxJoystick::GetZPosition() const
{
    return 0;
}

int wxJoystick::GetButtonState() const
{
    return 0;
}

int wxJoystick::GetPOVPosition() const
{
    return -1;
}

int wxJoystick::GetPOVCTSPosition() const
{
    return -1;
}

int wxJoystick::GetRudderPosition() const
{
    return 0;
}

int wxJoystick::GetUPosition() const
{
    return 0;
}

int wxJoystick::GetVPosition() const
{
    return 0;
}

int wxJoystick::GetMovementThreshold() const
{
    return 0;
}

void wxJoystick::SetMovementThreshold(int threshold)
{
}

// Capabilities
////////////////////////////////////////////////////////////////////////////

int wxJoystick::GetNumberJoysticks()
{
    return 0;
}

bool wxJoystick::IsOk() const
{
    return false;
}

int wxJoystick::GetManufacturerId() const
{
    return 0;
}

int wxJoystick::GetProductId() const
{
    return 0;
}

wxString wxJoystick::GetProductName() const
{
    return wxEmptyString;
}

int wxJoystick::GetXMin() const
{
    return 0;
}

int wxJoystick::GetYMin() const
{
    return 0;
}

int wxJoystick::GetZMin() const
{
    return 0;
}

int wxJoystick::GetXMax() const
{
    return 0;
}

int wxJoystick::GetYMax() const
{
    return 0;
}

int wxJoystick::GetZMax() const
{
    return 0;
}

int wxJoystick::GetNumberButtons() const
{
    return 0;
}

int wxJoystick::GetNumberAxes() const
{
    return 0;
}

int wxJoystick::GetMaxButtons() const
{
    return 0;
}

int wxJoystick::GetMaxAxes() const
{
    return 0;
}

int wxJoystick::GetPollingMin() const
{
    return 0;
}

int wxJoystick::GetPollingMax() const
{
    return 0;
}

int wxJoystick::GetRudderMin() const
{
    return 0;
}

int wxJoystick::GetRudderMax() const
{
    return 0;
}

int wxJoystick::GetUMin() const
{
    return 0;
}

int wxJoystick::GetUMax() const
{
    return 0;
}

int wxJoystick::GetVMin() const
{
    return 0;
}

int wxJoystick::GetVMax() const
{
    return 0;
}


bool wxJoystick::HasRudder() const
{
    return false;
}

bool wxJoystick::HasZ() const
{
    return false;
}

bool wxJoystick::HasU() const
{
    return false;
}

bool wxJoystick::HasV() const
{
    return false;
}

bool wxJoystick::HasPOV() const
{
    return false;
}

bool wxJoystick::HasPOV4Dir() const
{
    return false;
}

bool wxJoystick::HasPOVCTS() const
{
    return false;
}

// Operations
////////////////////////////////////////////////////////////////////////////

bool wxJoystick::SetCapture(wxWindow* win, int pollingFreq)
{
    return false;
}

bool wxJoystick::ReleaseCapture()
{
    return false;
}

