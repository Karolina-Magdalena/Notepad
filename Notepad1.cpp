//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString nazwapliku="";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{
try {
tresc->Lines->LoadFromFile(OpenDialog1->FileName);
nazwapliku = OpenDialog1->FileName;
}
catch (...)
{
ShowMessage("Bl¹d otwarcia pliku. Upewnij siê, ¿e plik istnieje na dysku");
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
if (SaveDialog1->Execute())
{
try {
tresc->Lines->SaveToFile(SaveDialog1->FileName);
nazwapliku = SaveDialog1->FileName;
}
catch (...)
{
ShowMessage("Zapis zakoñczy³ siê niepowodzeniem!");
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
if (nazwapliku!="")
{
tresc->Lines->SaveToFile(nazwapliku);
}
else
{
Form1->Zapiszjako1Click(MainMenu1);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
if (Application->MessageBoxA("Czy na pewno utworzyæ nowy plik?","PotwierdŸ",
MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
{
tresc->Lines->Clear();
nazwapliku="";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OnKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Shift.Contains(ssCtrl))
{
if ((Key=='s')||(Key=='S'))
{
Form1->Zapisz1Click(MainMenu1);
}
}

if (Shift.Contains(ssCtrl))
{
if ((Key=='o')||(Key=='O'))
{
Form1->Otwrz1Click(MainMenu1);
}
}

if (Shift.Contains(ssCtrl)&&(ssShift))
{
if ((Key=='s')||(Key=='S'))
{
Form1->Zapiszjako1Click(MainMenu1);
}
}
if (Shift.Contains(ssCtrl))
{
if ((Key=='n')||(Key=='N'))
{
Form1->Nowy1Click(MainMenu1);
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
if (Application->MessageBox
("Czy chcesz zapisaæ plik?","PotwierdŸ",
MB_YESNOCANCEL | MB_ICONQUESTION ==IDYES))
{
if (nazwapliku!="")
{
tresc->Lines->SaveToFile(nazwapliku);
}
else
{
Form1->Zapiszjako1Click(MainMenu1);
}
Application->Terminate();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OnClose(TObject *Sender, TCloseAction &Action)
{
if (Application->MessageBox
("Czy na pewno zakoñczy program?","PotwierdŸ",
MB_YESNO | MB_ICONQUESTION) == IDNO)
{
Action=caNone;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Zapraszamy1Click(TObject *Sender)
{
ShellExecute(NULL,"open","https://github.com/Karolina-Magdalena", NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
if (Zawijaniewierszy1->Checked==true)
{
Zawijaniewierszy1->Checked=false;
tresc->WordWrap=false;
tresc->ScrollBars=ssBoth;
}
else
{
Zawijaniewierszy1->Checked=true;
tresc->WordWrap = true;
tresc->ScrollBars=ssVertical;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Czcionka1Click(TObject *Sender)
{
if (FontDialog1->Execute())
{
tresc->Font->Name = FontDialog1->Font->Name;
tresc->Font->Color = FontDialog1->Font->Color;
tresc->Font->Size = FontDialog1->Font->Size;
tresc->Font->Style = FontDialog1->Font->Style;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
ShowMessage("Notatnik powsta³ na podstawie kursu 'Obiektowy C++' na YouTube");
}
//---------------------------------------------------------------------------

