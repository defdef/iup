/** \file
 * \brief List Control
 *
 * See Copyright Notice in iup.h
 */
 
#ifndef __IUP_LIST_H 
#define __IUP_LIST_H

#ifdef __cplusplus
extern "C" {
#endif


void iupdrvListInitClass(Iclass* ic);
void iupdrvListAddBorders(Ihandle* ih, int *w, int *h);
void iupdrvListAddItemSpace(Ihandle* ih, int *h);
int iupdrvListGetCount(Ihandle* ih);
void iupdrvListAppendItem(Ihandle* ih, const char* value);
void iupdrvListInsertItem(Ihandle* ih, int pos, const char* value);
void iupdrvListRemoveItem(Ihandle* ih, int pos);
void iupdrvListRemoveAllItems(Ihandle* ih);
void iupdrvListConvertXYToItem(Ihandle* ih, int x, int y, int *pos);

int iupListGetPos(Ihandle* ih, const char* name_id);
int iupListSetIdValueAttrib(Ihandle* ih, const char* name_id, const char* value);
void iupListSetInitialItems(Ihandle* ih);
void iupListSingleCallActionCallback(Ihandle* ih, IFnsii cb, int pos);
void iupListMultipleCallActionCallback(Ihandle* ih, IFnsii cb, IFns multi_cb, int* pos, int sel_count);
char* iupListGetNCAttrib(Ihandle* ih);
char* iupListGetPaddingAttrib(Ihandle* ih);
char* iupListGetSpacingAttrib(Ihandle* ih);
void iupListSingleCallDblClickCallback(Ihandle* ih, IFnis cb, int pos);

struct _IcontrolData 
{
  int sb,
      nc,
      spacing,
      horiz_padding, 
      vert_padding,
      last_caret_pos,
      is_multiple,
      is_dropdown,
      has_editbox;
  Imask* mask;
};


#ifdef __cplusplus
}
#endif

#endif
