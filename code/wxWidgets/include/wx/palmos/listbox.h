/////////////////////////////////////////////////////////////////////////////
// Name:        wx/palmos/listbox.h
// Purpose:     wxListBox class
// Author:      William Osborne - minimal working wxPalmOS port
// Modified by:
// Created:     10/13/04
// RCS-ID:      $Id: listbox.h,v 1.3 2005/02/13 17:07:56 VZ Exp $
// Copyright:   (c) William Osborne
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_LISTBOX_H_
#define _WX_LISTBOX_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma interface "listbox.h"
#endif

#if wxUSE_LISTBOX

// ----------------------------------------------------------------------------
// simple types
// ----------------------------------------------------------------------------

#if wxUSE_OWNER_DRAWN
  class WXDLLEXPORT wxOwnerDrawn;

  // define the array of list box items
  #include  "wx/dynarray.h"

  WX_DEFINE_EXPORTED_ARRAY_PTR(wxOwnerDrawn *, wxListBoxItemsArray);
#endif // wxUSE_OWNER_DRAWN

// forward decl for GetSelections()
class wxArrayInt;

// ----------------------------------------------------------------------------
// List box control
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxListBox : public wxListBoxBase
{
public:
    // ctors and such
    wxListBox();
    wxListBox(wxWindow *parent, wxWindowID id,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            int n = 0, const wxString choices[] = NULL,
            long style = 0,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxListBoxNameStr)
    {
        Create(parent, id, pos, size, n, choices, style, validator, name);
    }
    wxListBox(wxWindow *parent, wxWindowID id,
            const wxPoint& pos,
            const wxSize& size,
            const wxArrayString& choices,
            long style = 0,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxListBoxNameStr)
    {
        Create(parent, id, pos, size, choices, style, validator, name);
    }

    bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0, const wxString choices[] = NULL,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListBoxNameStr);
    bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListBoxNameStr);

    virtual ~wxListBox();

    // implement base class pure virtuals
    virtual void Clear();
    virtual void Delete(int n);

    virtual int GetCount() const;
    virtual wxString GetString(int n) const;
    virtual void SetString(int n, const wxString& s);
    virtual int FindString(const wxString& s) const;

    virtual bool IsSelected(int n) const;
    virtual void DoSetSelection(int n, bool select);
    virtual int GetSelection() const;
    virtual int GetSelections(wxArrayInt& aSelections) const;

    virtual int DoAppend(const wxString& item);
    virtual void DoInsertItems(const wxArrayString& items, int pos);
    virtual void DoSetItems(const wxArrayString& items, void **clientData);

    virtual void DoSetFirstItem(int n);

    virtual void DoSetItemClientData(int n, void* clientData);
    virtual void* DoGetItemClientData(int n) const;
    virtual void DoSetItemClientObject(int n, wxClientData* clientData);
    virtual wxClientData* DoGetItemClientObject(int n) const;

    // wxCheckListBox support
#if wxUSE_OWNER_DRAWN
    bool MSWOnMeasure(WXMEASUREITEMSTRUCT *item);
    bool MSWOnDraw(WXDRAWITEMSTRUCT *item);

    // plug-in for derived classes
    virtual wxOwnerDrawn *CreateLboxItem(size_t n);

    // allows to get the item and use SetXXX functions to set it's appearance
    wxOwnerDrawn *GetItem(size_t n) const { return m_aItems[n]; }

    // get the index of the given item
    int GetItemIndex(wxOwnerDrawn *item) const { return m_aItems.Index(item); }
#endif // wxUSE_OWNER_DRAWN

    // Windows-specific code to set the horizontal extent of the listbox, if
    // necessary. If s is non-NULL, it's used to calculate the horizontal
    // extent. Otherwise, all strings are used.
    virtual void SetHorizontalExtent(const wxString& s = wxEmptyString);

    // Windows callbacks
    bool MSWCommand(WXUINT param, WXWORD id);

    virtual wxVisualAttributes GetDefaultAttributes() const
    {
        return GetClassDefaultAttributes(GetWindowVariant());
    }

    static wxVisualAttributes
    GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL)
    {
        return GetCompositeControlsDefaultAttributes(variant);
    }

protected:
    WXDWORD MSWGetStyle(long style, WXDWORD *exstyle) const;

    // free memory (common part of Clear() and dtor)
    void Free();

    int m_noItems;
    int m_selected;

    virtual wxSize DoGetBestSize() const;

#if wxUSE_OWNER_DRAWN
    // control items
    wxListBoxItemsArray m_aItems;
#endif

private:
    DECLARE_DYNAMIC_CLASS_NO_COPY(wxListBox)
};

#endif // wxUSE_LISTBOX

#endif
    // _WX_LISTBOX_H_
