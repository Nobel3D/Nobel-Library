#include "NMessageBox.h"
#include <Windows.h>

using namespace NobelLib;
using namespace NobelLib::Graphics;

NMessageBox::NMessageBox()
{

}
NMessageBox::~NMessageBox()
{

}
NMessageBoxResult NMessageBox::Show(NString msgb_sText, NString msgb_sCaption, NMessageBoxButton msgb_nButton, NMessageBoxIcon msgb_nIcon)
{
	return NMessageBoxResult (MessageBox(NULL, msgb_sText.toUnicode(), msgb_sCaption.toUnicode(), msgb_nIcon | msgb_nButton));
}