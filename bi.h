rrr#ifndef _BI_H
#define _BI_H

#ifdef _BI_SRC
#define BI_EXT
#else
#define BI_EXT extern
#endif

#include "bgs.h"
#ifdef _BGSSTM32
#pragma arm section rwdata = "UNINITRAM_SEC"
#pragma arm section zidata = "UNINITRAM_SEC"
#endif
//*********************************************------------------------------------------------------------------- Defines --------------------------------------------

//ATT.NE: mai mettere altri mutex in una sezione _MA _MR come regola per evitare deadlock
#define _MA BGSMutexAq(&BI_genAccMutex)
#define _MR BGSMutexRel(&BI_genAccMutex)

//#define COMCOM

//Qui sotto NON deve essere definito!!
//#define COLLCOMEBAR
//#define DEMO

#define BI_BUTMASK 0x00ff
/*#define BI_BACKFILE "../stg/bk.bin"
#define BI_PROGGIOCOFILENAME "../stg/pgioco.bin"
#define BI_PEMPARFILENAME "../stg/parFile.bin"
#define BI_PEMEVFILENAME "../stg/evFile.bin"
#define BI_PEMMANFILENAME "../stg/manFile.bin"	*/
#define BI_INF -1


#define BI_START	0x2000
#define BI_STOP5	0x1000
#define BI_STOP1	0x0100
#define BI_STOP2	0x0200
#define BI_STOP4	0x0800
#define BI_STOP3	0x0400
#define BI_REFILL	0x8000
#define BI_TEST     0x4000
#define BI_ALLKEYS  0xFF00

#define BI_LAMP1	0x0001
#define BI_LAMP2	0x0002
#define BI_LAMP3	0x0004
#define BI_LAMP4	0x0008
#define BI_LAMP5	0x0010
#define BI_LAMPST	0x0020
#define BI_ALLLAMPS	63


//MOD_BK3 inizio
#define BI_HWERR_PEMFILE_EVTOCOM_NOTFOUND 1
#define BI_HWERR_TOOEVTOCOM 2
#define BI_HWERR_TOOEVTOMAN 3
#define BI_HWERR_TOOMANTOCOM 4
#define BI_HWERR_PARWR 5
#define BI_HWERR_EVWR 6
#define BI_HWERR_MANWR 7
#define BI_HWERR_BKOFF 8
#define BI_HWERR_BKON 9
#define BI_HWERR_NOBACKFILE 10
#define BI_HWERR_PARNUMMAX 11
#define BI_HWERR_EVNUMMAX 12
#define BI_HWERR_MANNUMMAX 13
#define BI_HWERR_BIBUFERR 14
#define BI_HWERR_GAMEBUFERR 15
#define BI_HWERR_PEMFILEOPENBASE 256
#define BI_HWERR_PEMFILEREADBASE 260
//MOD_BK3 fine







#define BI_EV_01   0
#define BI_EV_02   1
#define BI_EV_03   2
#define BI_EV_04   3
#define BI_EV_05   4
#define BI_EV_06   5
#define BI_EV_07   6

#define BI_EV_41   7
#define BI_EV_42   8
#define BI_EV_44   9
#define BI_EV_4F  10

#define BI_EV_F1  11
#define BI_EV_0F  12

#define BI_EV_20  13
#define BI_EV_21  14
#define BI_EV_22  15




#define BI_EV_32  16
#define BI_EV_33  17
#define BI_EV_3F  18
#define BI_EV_51  19

#define BI_EV_D1  20
#define BI_EV_D2  21
#define BI_EV_D3  22
#define BI_EV_D4  23
#define BI_EV_D5  24
#define BI_EV_D6  25
#define BI_EV_D7  26
#define BI_EV_D8  27
#define BI_EV_DF  28


//ATTENZIONE: se cambia BI_HOPNUM occorre cambiare qui sotto !!!
//non cambiare l'ordine dei tre qui sotto tra loro
#define BI_EV_ERRCOIN	29
#define BI_EV_ERRHOP0	30
#define BI_EV_ERRHOP1	31

//non cambiare l'ordine dei tre qui sotto tra loro. BI_EV_INCOMCOIN non si verifica mai (salvo in futuro x gett strane) ma serve x come e' fatto il codice
#define BI_EV_INCOMCOIN		32
#define BI_EV_INCOMPHOP0	33
#define BI_EV_INCOMPHOP1	34

//non cambiare l'ordine dei tre qui sotto tra loro
#define BI_EV_NOLISTCOIN	35
#define BI_EV_NOLISTHOP0	36
#define BI_EV_NOLISTHOP1	37

//non cambiare l'ordine dei tre qui sotto tra loro
#define BI_EV_SERCOIN	38
#define BI_EV_SERHOP0	39
#define BI_EV_SERHOP1	40


#define BI_EVNUM 41


#define BI_MAN_90 0
#define BI_MAN_91 1
#define BI_MAN_92 2
#define BI_MAN_93 3
#define BI_MAN_94 4
#define BI_MAN_95 5
#define BI_MAN_96 6
#define BI_MAN_97 7
#define BI_MAN_98 8
#define BI_MAN_99 9
#define BI_MAN_9A 10
#define BI_MAN_9B 11
#define BI_MAN_9C 12
#define BI_MAN_9D 13
#define BI_MAN_9E 14

#define BI_MANNUM 15

#define COSTOPAR 100
#define NUMPARCICLO 28000
#define VINMAX 10000
//MOD_RTP rimossa percm
#define DURMINPAR 4

#define DARETRY_DEFAULT 4
#define DATIME_DEFAULT 0xfab4
#define DATIMEOUT_DEFAULT 2

//MOD_BK3 inizio
#define GAME_BKFILE_USELEN 8191
#define GAME_BKFILE_BUFLEN (1+GAME_BKFILE_USELEN)
#define GAME_BKFILE_LEN (GAME_BKFILE_BUFLEN*2)
//MOD_BK3 fine

#define BI_IDSOGGLEN 7
#define BI_CODEIDLEN 11
#define BI_CODMODLEN 7
#define BI_IDPRODLEN BI_IDSOGGLEN
#define BI_CODSWLEN 7
#define BI_IDSKLEN 7

#define BI_PWDLEN 5
#define BI_IDSOGGNUM 4

#define BI_MSGGIOCOLEN 256
#define BI_MSGGIOCONUM 10

#define BI_PEMPAR 0
#define BI_PEMEV 1
#define BI_PEMMAN 2

#define BI_PEMPARNUMLAW 15000
#define BI_PEMEVNUMLAW 15000
#define BI_PEMMANNUMLAW 1000

#define BI_STATUSSG_COLL 0
#define BI_STATUSSG_PROVEPROD 1
#define BI_STATUSSG_OK 2

typedef struct _msgg {
BGSUC mid;
BGSDATE dataIn;
BGSDATE dataFi;
BGSUC mds;
BGSUL mpg;
BGSUC mtt[BI_MSGGIOCOLEN];
BGSUL mttLen; //utile perche se c'e' per errore uno 0x0 in mezzo e devo rispondere quali msg ho nel buffer, devo comunic anche il pezzo dopo
BGSUC flag;
BGSUL dummy1;
} BI_MSGGIOCO;

#define BI_AVVISILEN	256
typedef struct _avv {
	BGSUC ads;
	BGSUC att[BI_AVVISILEN];
	BGSUL attLen; //utile perche se c'e' per errore uno 0x0 in mezzo e devo rispondere quali msg ho nel buffer, devo comunic anche il pezzo dopo
	BGSUC flag;
	BGSUL dummy1;
} BI_AVVISOGIOCO;

typedef struct _par {		//deve essere sottomultiplo di 512 x scrivere su SD in modo transaz. Se si cambia, verificare la grandezza dei file SD
	BGSDATE date;
	BGSUS dur;
	BGSTIME time;
	BGSUS vin;
	BGSUS aux1;
	BGSUL aux2;
} BI_PAR;

typedef struct _ev { //deve essere sottomultiplo di 512 x scrivere su SD in modo transaz. Se si cambia, verificare la grandezza dei file SD
	BGSDATE date;
	BGSTIME time;
	BGSUC code;
	BGSUC flag;
} BI_EV;

#define BI_NSERTYPE_ZERO 0
#define BI_NSERTYPE_IDSK 1
#define BI_NSERTYPE_COIN 2
#define BI_NSERTYPE_HOP0 3
#define BI_NSERTYPE_HOP1 4

typedef const struct evd {
	BGSUC manLev;  //0 nessun interv. richiesto. 1 eserc   2 prod app    3 prod SG
	BGSUC manSuggId; //se manLev<2 don't care, altrimenti indice manut suggerita per sbloccare l'evento
	BGSUC manMod; //se manLev<2 don't care, se manLev==2 vale 1 se una qualunque altra manut fatta dal prod app (o SG ovviamente) sblocca l'evento. Se manLEv==3 serve ripro quindi di nuovo don't care
	BGSUC manNserType; //tipo di seriale suggerito
	BGSUC AAMSCode;
	BGSUC str[25];
} BI_EV_DESC;

#define BI_NSERLEN 16





typedef struct _man {	//deve essere sottomultiplo di 512 x scrivere su SD in modo transaz. Se si cambia, verificare la grandezza dei file SD
	BGSDATE date;
	BGSTIME time;
	BGSUS inter;
	BGSUC nSer[BI_NSERLEN];
	BGSUC idSogg[BI_IDSOGGLEN];
	BGSUC aux1;
} BI_MAN;


typedef const struct _mand {
	BGSUC level;
	BGSUC idm;
	BGSUC str[25];
} BI_MAN_DESC;
//-------------------  coins -----------

#define BI_COINSNUM 3


#define BI_COINNONE 255
#define BI_COIN50C 0
#define BI_COIN1E 1
#define BI_COIN2E 2

/*I codici qui sotto, detti E (extra) sono utilizzati xche comodi per fare maschere per certe tabelle. Per passare dai c=0,1,2 a quelli si fara' 1<<c */
#define BI_COINENONE 255
#define BI_COINE50C 1
#define BI_COINE1E 2
#define BI_COINE2E 4

//MOD_CCTALK2_EAGLE inizio
#define BI_CCTALKCOINCODENUM 6
#define BI_CCTALKCOINSETNUM 2
//MOD_CCTALK2_EAGLE fine

//------------- tipi di hopper possibili --------------------
#define BI_HOPCOINNUM 2
#define BI_HOPTYPEDESCLEN 40
typedef const struct _hopType {
	BGSUC coins[BI_HOPCOINNUM];//monete accettate. Prima sempre !=BI_COINNONE e in ordine crescente
	BGSUC desc[BI_HOPTYPEDESCLEN];
} BI_HOPTYPE;

//Codici base hopper di base
#define BI_HOPTYPE_50C 0
#define BI_HOPTYPE_1E 1
#define BI_HOPTYPE_2E 2
#define BI_HOPTYPE_DISC 3
#define BI_HOPTYPE_MM12E 4
#define BI_HOPTYPE_NONE 5
//ATT.:se modifico qui sopra, aggiornare qui sotto
#define BI_HOPTYPE_NUM 6


//Codici extra per hopper base, usati dove occorrono maschere di bit (BI_HopDescTab)
#define BI_HOPTYPEE_50C 1
#define BI_HOPTYPEE_1E 2
#define BI_HOPTYPEE_2E 4
#define BI_HOPTYPEE_DISC 8
#define BI_HOPTYPEE_MM12E 16





//--- descrittori hopper veri e propri ---------------------------------
#define BI_HOPDESCSTRLEN 30
typedef const struct _hopdes {
	BGSCUC s246[BI_HOPDESCSTRLEN];
	BGSCUC s245[BI_HOPDESCSTRLEN];
	BGSCUC s244[BI_HOPDESCSTRLEN];
	BGSUL caps; //maschera dei tipi di hopper che un hopper puo supportare, in codifica extra
	BGSBOOL (*const hopInit)(BGSUC hopNum);
	BGSVOID (*const stopCmd)(BGSUC hopNum);
	BGSBOOL (*const startPay)(BGSUC hopNum);
	BGSBOOL (*const checkPayStatus)(BGSUC hopNum,BGSUSP dispPtr);
	BGSVOID (*const checkPayEnd)(BGSUC hopNum,BGSUSP dispPtr);
} BI_HOPDESC;

#define BI_HOPDESCNUM (sizeof(BI_HopDescTab)/sizeof(BI_HOPDESC))

#define BI_HOPNUM 2
#define BI_USERTHREADSNUM (1+1+BI_HOPNUM)


//---------- descrittori gettoniere -----------------
//MOD_CCTALK2_EAGLE inizio
#define BI_COINACCDESCSTRLEN 30
typedef const struct _coindes {
	BGSCUC s246[BI_COINACCDESCSTRLEN];
	BGSCUC s244[BI_COINACCDESCSTRLEN];
	BGSCUC set;	
} BI_COINACCDESC;

#define BI_COINACCDESCNUM (sizeof(BI_CoinAccDescTab)/sizeof(BI_COINACCDESC))



//------struttura coin generale usata per tener tutto raggruppato. -----------
//------Si potrebbe togliere. Esiste una sola costante di questo tipo
typedef const struct _coinde {
	BGSUL val[BI_COINSNUM];
	BGSUC codes210[BI_CCTALKCOINSETNUM][BI_COINSNUM];
	BGSUC codes231[BI_CCTALKCOINSETNUM][BI_COINSNUM];
	BGSUC codes229[BI_CCTALKCOINSETNUM][BI_CCTALKCOINCODENUM];
} BI_COINS;
//MOD_CCTALK2_EAGLE fine

//--------------- Descrittore delle configurazioni di hopper/coin possibili

typedef const struct _chconf {
	BGSUC hop[BI_HOPNUM];
	BGSUC coinsE;//elenco possibili combinazioni monete accettabili, codifica extra (E)
	BGSUC str[70];
} BI_COINHOPCONF;

#define BI_COINHOPCONFNUM 21
#define BI_COINHOPCCTALKSTRLEN 20
#define BI_COINHOPSTRLEN 50

//-------- struttara dello stato (variabile) di coins e hopper ------------
//-------- Usata come unica variabile, fatta per raggrupapre tutto. Si potrebbe togliere
typedef struct _coinHopStatus {
	BGSUC hopSer[BI_HOPNUM][4];//il seriale: il byte 3 e' >0 se si deve fare il check del seriale (il main lo setta sempre prima di avviare i thread)
	BGSUL hopLev[BI_HOPNUM];
	BGSUL hopLevIni[BI_HOPNUM];
	BGSUL hopLevMax[BI_HOPNUM];
	BGSUL cashLev;
	BGSUS payTotAmount;
	BGSUS payTempAmount;
	BGSUC hopReq[BI_HOPNUM];
	BGSUC hopConnStr[BI_HOPNUM][BI_COINHOPSTRLEN];//stringa dispositivo. Aggiornata appena rilevato qualcosa, altrimenti "NESSUN DISP...."
	BGSUC hopConn[BI_HOPNUM];//situazione di connessione: NA,unused, disconeesso, oppure indice dell'hopper connesso
	BGSUC lastHopConnOk[BI_HOPNUM]; //Mi dice l'id dell'ultimo hopper trovato che ha passato tutti i test (omologato, seriale,ecc..) e che quindi all'accesnione macchina, potrebbe avere un pagam. in corso.
									//Lo uso all'inizio per dare prima di tutto il cmd di stop quando hopConn vale ancora  BI_DEVCONN_NA. Se per sfortuna, da spento lo avevo cambiato con uno che ha un altro cmd di stop, il comando che do io non sara' efficace, dara' un errore a cui non faro' caso. Pazienza
	BGSUC hopPayStatus[BI_HOPNUM]; //attivo pronto, sospeso al pagamento, richiesto pagamento, in pagamento. Fa testo se l'hop e' usato e connesso
	BGSUC payExtra; //parametri addizionali per richiesta pagam, e risultato pagamento
	BGSUC payRes;
	BGSUC conf;
	BGSUC coinSer[4];//il seriale: il byte 3 e' >0 se si deve fare il check del seriale (il main lo setta sempre prima di avviare i thread)
	BGSUC sorterPaths[1+BI_HOPNUM]; //lo 0 e' quello della cassa poi hop0.......
	BGSUC coinAccReq;
	BGSUC coinAccConnStr[BI_COINHOPSTRLEN];//stringa dispositivo. Aggiornata appena rilevato qualcosa, altrimenti "NESSUN DISP...."
	BGSUC coinAccConn;
	BGSBOOL coinAccEn;
} BI_COINHOPSTATUS;





#define BI_HOPLEVDEF 20000
#define BI_HOPLEVMAXDEF 30000

#define BI_DEVCONN_NA 255
#define BI_DEVCONN_SERERR 254
#define BI_DEVCONN_UNCON 253
#define BI_DEVCONN_NOLIST 252
#define BI_DEVCONN_INCOMP 251
//questo qui sotto deve avere il numero minore degli altri
#define BI_DEVCONN_UNUSED 250

//non cambiare quelli sotto i 128, sono fatti cosi perche SUSP pot4ebbe essere un range di valori che poi decrementano verso lo 0 (READY)
#define BI_HOPPAYST_READY 0
#define BI_HOPPAYST_SUSP 1
#define BI_HOPPAYST_PAY 128
#define BI_HOPPAYST_START 129



#define BI_COINHOPREQNONE 0
#define BI_COINHOPREQSTOP 1
#define BI_COINHOPREQSTOPACK 2





#define BI_HOPPAYTIMEOUT 15000

#define BI_CHA BI_Crit0Aq();
#define BI_CHANR BI_Crit0AqNoRead();/*MOD_BK3A*/
#define BI_CHR(x) BI_Crit0Rel((x));

#define DEB(x) {printf(x);}

//*********************************************------------------------------------------------------------------- Variabili visibili anche agli altri file --------------------------------------------
BI_EXT BGSUL BI_cntTotIn,BI_cntTotOt,BI_cntIn,BI_cntOt,BI_cntNp,BI_cntCl,BI_cntTotIn3112,BI_cntTotOt3112,BI_cntOtLast,BI_cntOtLast2,BI_durTot,BI_durTotLast,BI_durTotLast2;
BI_EXT BGSUC BI_lastYearUpdate3112;
BI_EXT BGSUL BI_refill,BI_perIn,BI_perOut,BI_crediti;
BI_EXT BGSUS BI_impErariale,BI_gestPerc,BI_gestGior,BI_esercentePerc;
BI_EXT BGSDATE BI_perDate;
BI_EXT BGSUC BI_statusSG;
BI_EXT BGSUC BI_statusAct;
BI_EXT BGSUS BI_statusBlk;//US e non UC perche in caso di 9EXX con XX=0 voglio poter creare il blocco 0x00 anche se dubito che succedera'
BI_EXT BGSUC BI_statusCom;
BI_EXT BGSUS BI_statusLastRetCode;
BI_EXT BGSUC BI_statusStartUp;
BI_EXT BGSUC BI_status_12_6;
BI_EXT BGSUS BI_parToCom,BI_evToCom,BI_manToCom,BI_evToMan;
BI_EXT BGSUL BI_parNum,BI_evNum,BI_manNum;

BI_EXT BGSDATE BI_dataInizioCiclo;
BI_EXT BGSUC BI_codeId[BI_CODEIDLEN];
BI_EXT BGSUC BI_codMod[BI_CODMODLEN],BI_codSW[BI_CODSWLEN],BI_idSk[BI_IDSKLEN];
BI_EXT BI_MSGGIOCO BI_msgGioco[BI_MSGGIOCONUM];
BI_EXT BI_AVVISOGIOCO BI_avvisoGioco;
BI_EXT BGSMUTEX BI_genAccMutex;
BI_EXT BI_COINHOPSTATUS BI_chSt;//fatta corta di nome perche usata spesso

BI_EXT BGSUC BI_idSoggTab[BI_IDSOGGNUM][BI_IDSOGGLEN];
BI_EXT BGSUC BI_idSoggPwdTab[BI_IDSOGGNUM][BI_PWDLEN];

extern BGSFILE gameBackupFile;

extern BI_EV_DESC BI_EventTab[BI_EVNUM];
extern BI_MAN_DESC BI_ManTab[BI_MANNUM+1];
extern BI_HOPTYPE BI_HopTypeTab[BI_HOPTYPE_NUM];
extern BI_COINHOPCONF BI_CoinHopConfTab[];
extern BI_COINS BI_Coins;
extern BGSCUC BI_deviceConStrTab[][100];

//********************************************-------------------------------------------------------------------Prots ------------
BGSVOID KeyExtend( BGSUCP KeySource, BGSULP KeyDestination);
BGSVOID DES3_ECB_mode( BGSUC  *Input, BGSUC  *Output, BGSUL *KeySchedule, BGSUC  Operation);
BGSUL BILog2(BGSUL num);
BGSVOID BIPutAndGetVar(BGSVOIDP var,BGSUL size,BGSBOOL powerOn); //tipicamente da usarsi con BI_BK
BGSVOID BIRegistraParAndUpdateCnt(BGSUS vin,BGSUS dur,BGSUS aux1,BGSUL aux2);
BGSUL BIEventToManLev(BGSUC code);
BGSVOID BIGetEventiTotNumAndToManNum(BGSULP totNum,BGSULP numToMan);
BGSVOID BIDecrEvToMan(void);
BGSUL BIGetOldestEventsToMan(BI_EV *evBuf,BGSUL max);
BGSVOID BIRegistraEvento(BGSUC code,BGSBOOL daComunicare,BGSTIME *ti,BGSDATE *da,BGSUCP dateTimeStr);
BGSUC BIGetEventToManMaxLev(BGSUCP evCode);
BGSBOOL BIEventNeedingManPresent(BGSUC code);
BGSVOID BIRegistraMan(BI_MAN *man);
BGSUL BIGetPEMNum(BGSUC code);
BGSUL BIGetPEMByAge(BGSUC code,BGSUL refNum,BGSUL age,BGSUL num,BGSVOIDP buf);
BGSUC BIGetStatusSG(BGSVOID);
BGSVOID BISetStatusSG(BGSUC st);
BGSUC BIGetStatusAct(BGSVOID);
BGSBOOL BI_TestGetStatus(BGSVOID);
BGSVOID BI_TestSetStatus(BGSBOOL running);
BGSVOID BI_RefillSetStatus(BGSBOOL running);
BGSVOID BI_CoinAccEnable(BGSBOOL val);
BGSVOID BI_EnableSincro(BGSBOOL val);
BGSSL BICompareTimeDate(BGSTIME *t0,BGSDATE *d0,BGSTIME *t1,BGSDATE *d1);
BGSVOID BIDateToDMYPointed(BGSDATEP date,BGSUCP str);
BGSVOID BI_Crit0Aq(BGSVOID);
BGSVOID BI_Crit0AqNoRead(BGSVOID); //MOD_BK3A
BGSVOID BI_Crit0Rel(BGSBOOL modified);
BGSUL BIBufBEToNumeric(BGSUCP buf,BGSUL bytesNum,BGSUCP str,BGSUL minChr);
BGSSL BI_CheckIfOkForGame(BGSUCP str,BGSBOOL start);
BGSUL BI_CCTalk(BGSUC dev,BGSUC cmdCode,BGSUCP inPar,BGSUL inParLen,BGSUCP rispDataBuf,BGSUL maxRispDataLen,BGSBOOL manageErr);//MOD_SQ6
BGSUC BI_HopGetMinCoin(BGSUC hopNum);
BGSSL BI_HopGetUsedNum(BGSVOID);
BGSBOOL BI_HopOkForGame(BGSVOID);//MOD_SQ6
BGSBOOL BI_HopperStartPayment(BGSUC mask,BGSUS amount); //MOD_SQ6
BGSBOOL BI_HopperCheckPaymentStatus(BGSUSP toBePaidPtr,BGSUCP payResPtr); //MOD_SQ6
BGSUC BI_GetCoinHoppResultString(BGSUC device,BGSUCP str);
BGSVOID BI_LaunchCHThreads(BGSVOID);
BGSVOID BIWaitForCHConn(BGSVOID);
BGSVOID BI_CoinHoppStop(BGSVOID);
BGSVOID GameSaveRestore(BGSBOOL powerOn);
BGSVOID BIMsgGiocoAndAvvisoReset(BGSUC dispLen,BGSUL incStepMS,BGSUL incStepCar);
BGSVOID BIMsgGiocoGetString(BGSUCP str);
BGSVOID BIAvvisoGiocoGetString(BGSUCP str);
BGSVOID BIAzzeraOnStatusSGChange(BGSVOID);
BGSVOID BI_CheckCntTotIn(BGSVOID); //MOD_MEM
BGSVOID BI_HWError(BGSUS code);//MOD_BK3
BGSUS BI_CRC16CCITT(BGSVOIDP buf, BGSUL len);//MOD_BK3
#endif

