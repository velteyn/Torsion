/////////////////////////////////////////////////////////////////////////
// File:        wx/cocoa/taskbar.h
// Purpose:     Defines wxTaskBarIcon class
// Author:      David Elliott
// Modified by:
// Created:     2004/01/24
// RCS-ID:      $Id: taskbar.h,v 1.4 2004/10/22 15:42:11 DE Exp $
// Copyright:   (c) 2004 David Elliott
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////

#ifndef _WX_COCOA_TASKBAR_H__
#define _WX_COCOA_TASKBAR_H__

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "taskbar.h"
#endif

#include "wx/icon.h"

class WXDLLEXPORT wxIcon;
class WXDLLEXPORT wxMenu;

class wxTaskBarIconCocoaImpl;

class WXDLLEXPORT wxTaskBarIcon : public wxTaskBarIconBase
{
    friend class wxTaskBarIconCocoaImpl;
    DECLARE_DYNAMIC_CLASS_NO_COPY(wxTaskBarIcon)
public:
    //type of taskbar item to create (currently only DOCK is implemented)
    enum wxTaskBarIconType
    {   DOCK
    ,   CUSTOM_STATUSITEM
//    ,   STATUSITEM // TODO: Implement using NSStatusItem w/o custom NSView
//    ,   MENUEXTRA // Menu extras require undocumented hacks
    ,   DEFAULT_TYPE = CUSTOM_STATUSITEM
    };

    // Only one wxTaskBarIcon can be of the Dock type so by default
    // create NSStatusItem for maximum source compatibility.
    wxTaskBarIcon(wxTaskBarIconType iconType = DEFAULT_TYPE);
    virtual ~wxTaskBarIcon();

    bool SetIcon(const wxIcon& icon, const wxString& tooltip = wxEmptyString);
    bool RemoveIcon();
    bool PopupMenu(wxMenu *menu); //, int x, int y);
protected:
    wxTaskBarIconCocoaImpl *m_impl;
};

#endif // _WX_COCOA_TASKBAR_H__
