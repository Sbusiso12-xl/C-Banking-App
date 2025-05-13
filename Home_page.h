//---------------------------------------------------------------------------

#ifndef Home_pageH
#define Home_pageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class THomePage : public TForm
{
__published:	// IDE-managed Components
	TPageControl *tr;
	TTabSheet *Transactions;
	TTabSheet *pcPersonal_Infomation;
	TStringGrid *stgInfo;
	TLabel *Label1;
	TTabSheet *Deposit_Account;
	TTabSheet *Buy;
	TPanel *Panel1;
	TLabel *Label2;
	TEdit *edtDepositAmount;
	TButton *Deposit;
	TLabel *Label3;
	TImage *Image2;
	TLabel *Balance;
	TImage *Image3;
	TButton *Button1;
	TTabSheet *Tranfer;
	TPageControl *PageControl1;
	TTabSheet *BuyAirtime;
	TTabSheet *BuyElectricity;
	TPanel *Panel2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *edtNumber;
	TEdit *edtAmount;
	TComboBox *NetworkType;
	TButton *Purchase;
	TButton *Validate;
	TPanel *Panel4;
	TLabel *label;
	TEdit *edtBeneficiaryName;
	TLabel *Label8;
	TEdit *edtBeneficiaryNumber;
	TLabel *Label9;
	TEdit *edtMeterNum;
	TButton *Button2;
	TLabel *Label10;
	TEdit *edtAm;
	TLabel *Label11;
	TTabSheet *Home;
	TPanel *Panel5;
	TTimer *Timer1;
	TPanel *Panel6;
	TPanel *Panel7;
	TImage *Image4;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *lblnumber;
	TLabel *Label14;
	TPanel *Panel3;
	TEdit *edtAdd;
	TLabel *Label15;
	TButton *Add;
	TLabel *lblPay;
	TComboBox *names;
	TLabel *Label16;
	TEdit *edtpay;
	TButton *Button3;
	TPanel *Panel8;
	TImage *Image1;
	TShape *Shape1;
	TShape *Shape2;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *lblDisplayName;
	TLabel *lblDisplaySur;
	TLabel *lblIDDisp;
	TLabel *lblAdd;
	TLabel *lblDispAdd;
	TLabel *lblDispcell;
	TLabel *lblCrdcap;
	TLabel *lblCaption;
	TLabel *lblcardusername;
	TLabel *lblaccnr;
	TLabel *lblcardaccountnr;
	TStatusBar *displaybar;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DepositClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ValidateClick(TObject *Sender);
	void __fastcall PurchaseClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall stgInfoClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THomePage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THomePage *HomePage;
//---------------------------------------------------------------------------
#endif
