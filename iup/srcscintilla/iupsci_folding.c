/** \file
 * \brief Scintilla control: Folding
 *
 * See Copyright Notice in "iup.h"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#undef SCI_NAMESPACE
#include <Scintilla.h>

#include "iup.h"

#include "iup_object.h"
#include "iup_attrib.h"
#include "iup_str.h"

#include "iupsci_folding.h"
#include "iupsci.h"

/***** FOLDING *****
--SCI_VISIBLEFROMDOCLINE(int docLine)
--SCI_DOCLINEFROMVISIBLE(int displayLine)
--SCI_SHOWLINES(int lineStart, int lineEnd)
--SCI_HIDELINES(int lineStart, int lineEnd)
--SCI_GETLINEVISIBLE(int line)
--SCI_GETALLLINESVISIBLE
SCI_SETFOLDLEVEL(int line, int level)
SCI_GETFOLDLEVEL(int line)
SCI_SETFOLDFLAGS(int flags)
--SCI_GETLASTCHILD(int line, int level)
--SCI_GETFOLDPARENT(int line)
--SCI_SETFOLDEXPANDED(int line, bool expanded)
--SCI_GETFOLDEXPANDED(int line)
--SCI_CONTRACTEDFOLDNEXT(int lineStart)
SCI_TOGGLEFOLD(int line)
--SCI_ENSUREVISIBLE(int line)
--SCI_ENSUREVISIBLEENFORCEPOLICY(int line)
*/

int iupScintillaSetFoldFlagsAttrib(Ihandle* ih, const char* value)
{
  if (iupStrEqualNoCase(value, "LEVELNUMBERS"))
    iupScintillaSendMessage(ih, SCI_SETFOLDFLAGS, SC_FOLDFLAG_LEVELNUMBERS, 0);
  else if (iupStrEqualNoCase(value, "LINEBEFORE_EXPANDED"))
    iupScintillaSendMessage(ih, SCI_SETFOLDFLAGS, SC_FOLDFLAG_LINEBEFORE_EXPANDED, 0);
  else if (iupStrEqualNoCase(value, "LINEBEFORE_CONTRACTED"))
    iupScintillaSendMessage(ih, SCI_SETFOLDFLAGS, SC_FOLDFLAG_LINEBEFORE_CONTRACTED, 0);
  else if (iupStrEqualNoCase(value, "LINEAFTER_EXPANDED"))
    iupScintillaSendMessage(ih, SCI_SETFOLDFLAGS, SC_FOLDFLAG_LINEAFTER_EXPANDED, 0);
  else  /* LINEAFTER_CONTRACTED */
    iupScintillaSendMessage(ih, SCI_SETFOLDFLAGS, SC_FOLDFLAG_LINEAFTER_CONTRACTED, 0);

  return 0;
}

char* iupScintillaGetFoldLevelAttrib(Ihandle* ih, int line)
{
  int level = iupScintillaSendMessage(ih, SCI_GETFOLDLEVEL, line, 0);

  if (level & SC_FOLDLEVELWHITEFLAG)
    return "WHITEFLAG";
  else if (level & SC_FOLDLEVELHEADERFLAG)
    return "HEADERFLAG";
  else if (level & SC_FOLDLEVELNUMBERMASK)
    return "NUMBERMASK";
  else  /* SC_FOLDLEVELBASE */
    return "BASE";
}

int iupScintillaSetFoldLevelAttrib(Ihandle* ih, int line, const char* value)
{
  if (iupStrEqualNoCase(value, "WHITEFLAG"))
    iupScintillaSendMessage(ih, SCI_SETFOLDLEVEL, line, SC_FOLDLEVELWHITEFLAG);
  else if (iupStrEqualNoCase(value, "HEADERFLAG"))
    iupScintillaSendMessage(ih, SCI_SETFOLDLEVEL, line, SC_FOLDLEVELHEADERFLAG);
  else if (iupStrEqualNoCase(value, "NUMBERMASK"))
    iupScintillaSendMessage(ih, SCI_SETFOLDLEVEL, line, SC_FOLDLEVELNUMBERMASK);
  else  /* BASE */
    iupScintillaSendMessage(ih, SCI_SETFOLDLEVEL, line, SC_FOLDLEVELBASE);

  return 0;
}

int iupScintillaSetFoldToggleAttrib(Ihandle* ih, const char* value)
{
  int line, level;
  
  iupStrToInt(value, &line);
  level = iupScintillaSendMessage(ih, SCI_GETFOLDLEVEL, line, 0);

  if (level & SC_FOLDLEVELHEADERFLAG)
  {
    iupScintillaSendMessage(ih, SCI_TOGGLEFOLD, line, 0);
    return 0;
  }

  return 0;
}
