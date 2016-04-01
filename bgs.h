GGG#ifndef _BGSH
#define _BGSH

#ifdef _BGSC
#define BGSEXT
#else
#define BGSEXT extern
#endif


#include <string.h>
#include <stdio.h>
#if defined (_BGSWIN32)
//MOD_ON2 inizio
#include <windows.h>
#elif defined (_BGSSTM32)
	#include "rtl.h"
#else
#error "Piattaforma non definita"
#endif
#include "link.h"
//MOD_ON2 fine
//---------- BAsic types -------------------------------------------------
#define BGSMEGA (1024*1024)
#define BGSVIDEOWIDTH 1024
#define BGSVIDEOHEIGHT 768
#define BGSVIDEO0	0
#define BGSVIDEO1	1
#define BGSDOUBLESCREEN	0

//MOD14NOV
#define IDMSGBOX 0xfffd
#define MSGBOXZ 32765
#define MSGBOXSTRZ 32766

//MOD18NOV qui sotto
#define SD_RESTOREDIFF (1024*1024*1024)

//MOD_BK3 inizio

//Abilitare la define qui sotto per abilitare la cache di scrittura sd card
//#define ENABLE_SDWC

//Abilitare la define qui sotto per abilitare il rinfresco su sd card. Una volta abilitato, il codice sw e' aggiunto ma occorre comunque l'uso di   BGSSDRRefreshOneBlk
//#define ENABLE_SDREF


//MOD_BK3 fine

#define BGSV volatile
typedef unsigned char BGSUC;
typedef unsigned short BGSUS;
typedef unsigned long BGSUL;

typedef BGSUC * BGSUCP;
typedef BGSUS * BGSUSP;
typedef BGSUL * BGSULP;

typedef const unsigned char BGSCUC;
typedef const unsigned short BGSCUS;
typedef const unsigned long BGSCUL;

typedef BGSCUC * BGSCUCP;
typedef BGSCUS * BGSCUSP;
typedef BGSCUL * BGSCULP;

typedef signed char BGSSC;
typedef signed short BGSSS;
typedef signed long BGSSL;

typedef BGSSC * BGSSCP;
typedef BGSSS * BGSSSP;
typedef BGSSL * BGSSLP;

typedef const signed char BGSCSC;
typedef const signed short BGSCSS;
typedef const signed long BGSCSL;

typedef BGSCSC * BGSCSCP;
typedef BGSCSS * BGSCSSP;
typedef BGSCSL * BGSCSLP;

typedef void BGSVOID;
typedef BGSVOID * BGSVOIDP;

typedef BGSUL BGSHANDLE;

typedef BGSUC BGSBOOL;
typedef BGSBOOL * BGSBOOLP;

#if defined (_BGSWIN32)
typedef struct {
  unsigned short w;
  unsigned short h;
  unsigned short nFrame;
  unsigned long textureID;
  char fname[110];
} SOCIMG;
typedef struct {
  unsigned char *fname;
} SOCSND;
#ifndef _EMUL_C_
	extern const SOCIMG vetImage[];
	extern const SOCSND vetSound[];
	extern const unsigned short imageToBlock[][2];
#endif
#elif defined (_BGSSTM32)
typedef struct {
  unsigned short w;
  unsigned short h;
  unsigned short info;
  unsigned short nFrame;
  void * ptr;
} SOCIMG;
typedef struct {
  unsigned long offSD;
  unsigned long bytesNum;
   unsigned long channelsNum;
} SOCSND;
typedef struct {
  void * adr;
  unsigned long size;
} SOCFSD;
#ifndef _LINK_C_
  extern const SOCIMG vetImage[];
  extern const SOCSND vetSound[];
  extern const SOCFSD fSD[];
  extern const unsigned short imageToBlock[][2];
#endif
#endif

#define BGSTRUE 1
#define BGSFALSE 0

//MOD_SDROB
#define SDR_TRGNUM 1000

#if defined (_BGSWIN32)
	#define BGSTHREAD void
	typedef unsigned __int64 BGSUL8;
	#define PRINTFU64CODE "I64u"
#elif defined (_BGSSTM32)
	#define BGSTHREAD __task void
	typedef unsigned long long BGSUL8;
	#define PRINTFU64CODE "llu"
#else
#error "Piattaforma non definita"
#endif

typedef BGSUL8 * BGSUL8P;

//---------- BAsic types end --------


typedef struct _bgstime {
 BGSUC hh;
 BGSUC mm;
 BGSUC ss;
} BGSTIME;
typedef BGSTIME * BGSTIMEP;

typedef struct _bgsdate {
 BGSUC dd;
 BGSUC mm;
 BGSUC yy;
} BGSDATE;
typedef BGSDATE * BGSDATEP;


#if defined (_BGSWIN32)
#define BGS_PROGSTARTADD 0
#define BGS_PROGLEN 1024
#define BGSGET2BE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+1);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+0);}
#define BGSGET4BE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+3);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+2);*((BGSUCP)&(v)+2)=*((BGSUCP)(buf)+1);*((BGSUCP)&(v)+3)=*((BGSUCP)(buf)+0);}
#define BGSGET8BE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+7);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+6);*((BGSUCP)&(v)+2)=*((BGSUCP)(buf)+5);*((BGSUCP)&(v)+3)=*((BGSUCP)(buf)+4); \
	*((BGSUCP)&(v)+4)=*((BGSUCP)(buf)+3);*((BGSUCP)&(v)+5)=*((BGSUCP)(buf)+2);*((BGSUCP)&(v)+6)=*((BGSUCP)(buf)+1);*((BGSUCP)&(v)+7)=*((BGSUCP)(buf)+0);}
#define BGSSET2BE(v,buf) {*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+1);}
#define BGSSET4BE(v,buf) {*((BGSUCP)(buf)+3)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+2)=*((BGSUCP)&(v)+1);*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+2);*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+3);}
#define BGSSET8BE(v,buf) {*((BGSUCP)(buf)+7)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+6)=*((BGSUCP)&(v)+1);*((BGSUCP)(buf)+5)=*((BGSUCP)&(v)+2);*((BGSUCP)(buf)+4)=*((BGSUCP)&(v)+3); \
	*((BGSUCP)(buf)+3)=*((BGSUCP)&(v)+4);*((BGSUCP)(buf)+2)=*((BGSUCP)&(v)+5);*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+6);*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+7);}

#define BGSGET2LE(v,buf) {(v)=*(BGSUSP)(buf);}
#define BGSGET4LE(v,buf) {(v)=*(BGSULP)(buf);}
#define BGSSET2LE(v,buf) {*(BGSUSP)(buf)=(v);}
#define BGSSET4LE(v,buf) {*(BGSULP)(buf)=(v);}

#define BGS_EXTSRAM
#define BGS_BACKUPRAM
#define BGS_AROM

#elif defined (_BGSSTM32)
extern char Image$$ER_IROM2$$Base[];
extern char Image$$ER_IROM2$$Length[];
#define BGS_PROGSTARTADD (BGSUL)Image$$ER_IROM2$$Base
#define BGS_PROGLEN (BGSUL)Image$$ER_IROM2$$Length
//MOD_EC inizio
extern char Image$$ER_AROM$$Base[];
extern char Image$$ER_AROM$$Length[];
#define BGS_AROMSTARTADD (BGSUL)Image$$ER_AROM$$Base
#define BGS_AROMLEN (BGSUL)Image$$ER_AROM$$Length
//MOD_EC fine
#define BGSGET2BE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+1);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+0);}
#define BGSGET4BE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+3);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+2);*((BGSUCP)&(v)+2)=*((BGSUCP)(buf)+1);*((BGSUCP)&(v)+3)=*((BGSUCP)(buf)+0);}
#define BGSGET8BE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+7);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+6);*((BGSUCP)&(v)+2)=*((BGSUCP)(buf)+5);*((BGSUCP)&(v)+3)=*((BGSUCP)(buf)+4); \
	*((BGSUCP)&(v)+4)=*((BGSUCP)(buf)+3);*((BGSUCP)&(v)+5)=*((BGSUCP)(buf)+2);*((BGSUCP)&(v)+6)=*((BGSUCP)(buf)+1);*((BGSUCP)&(v)+7)=*((BGSUCP)(buf)+0);}
#define BGSSET2BE(v,buf) {*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+1);}
#define BGSSET4BE(v,buf) {*((BGSUCP)(buf)+3)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+2)=*((BGSUCP)&(v)+1);*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+2);*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+3);}
#define BGSSET8BE(v,buf) {*((BGSUCP)(buf)+7)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+6)=*((BGSUCP)&(v)+1);*((BGSUCP)(buf)+5)=*((BGSUCP)&(v)+2);*((BGSUCP)(buf)+4)=*((BGSUCP)&(v)+3); \
	*((BGSUCP)(buf)+3)=*((BGSUCP)&(v)+4);*((BGSUCP)(buf)+2)=*((BGSUCP)&(v)+5);*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+6);*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+7);}

#define BGSGET2LE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+0);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+1);}
#define BGSGET4LE(v,buf) {*((BGSUCP)&(v)+0)=*((BGSUCP)(buf)+0);*((BGSUCP)&(v)+1)=*((BGSUCP)(buf)+1);*((BGSUCP)&(v)+2)=*((BGSUCP)(buf)+2);*((BGSUCP)&(v)+3)=*((BGSUCP)(buf)+3);}
#define BGSSET2LE(v,buf) {*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+1);}
#define BGSSET4LE(v,buf) {*((BGSUCP)(buf)+0)=*((BGSUCP)&(v)+0);*((BGSUCP)(buf)+1)=*((BGSUCP)&(v)+1);*((BGSUCP)(buf)+2)=*((BGSUCP)&(v)+2);*((BGSUCP)(buf)+3)=*((BGSUCP)&(v)+3);}

#define BGS_EXTSRAM __attribute__ ((section ("EXTSRAM_SEC"),zero_init))
#define BGS_BACKUPRAM __attribute__ ((section ("BACKUPRAM_SEC"),zero_init))
#define BGS_AROM __attribute__((section("_AROM")))


#else

#error "Piattaforma non definita"
#endif

#define BGSDOALPHA	0xFF000000

#define BGSMIN(x,y) ((x)<(y)?(x):(y))
#define BGSMAX(x,y) ((x)>(y)?(x):(y))

//metterli da 0xf000 in su, perhce' i piu bassi li puo' usare l'utente
#define BGS_HWERR_CANCFLASH 0xf001
#define BGS_HWERR_SDREAD    0xf002
#define BGS_HWERR_SDWRITE   0xf003
#define BGS_HWERR_FILE      0xf004
#define BGS_HWERR_TRANSFDDR    0xf005
#define BGS_HWERR_EPRCHK	0xf006 /*MOD_EC*/

//--------- Mutex ----------------------------------------------------------------------
#if defined (_BGSWIN32)
typedef HANDLE BGSMUTEX;
#else
typedef OS_MUT BGSMUTEX;
#endif

typedef BGSMUTEX * BGSMUTEXP;
//---------- End Mutex ------------
//---------- File -----------------

typedef enum
{
  BGSFILERAM = 1,
  BGSFILESD = 2,
  BGSFILEEPROM = 3
} BGSFILETYPE;

typedef struct _bgsfile{
BGSUC fileName[20];
BGSVOIDP ptr;
BGSUL maxLen;
BGSFILETYPE fileType;
BGSUL flags;
}BGSFILE;
//---------- End File -------------


//-------- COM ---------------------------------------------------------------------
#define BGS_COMNUM 3

#define BGS_COM0 0
#define BGS_COM1 1
#define BGS_COM2 2

#define BGS_COMBAUDNUM 8
#define BGS_COM1200 0
#define BGS_COM2400 1
#define BGS_COM4800 2
#define BGS_COM9600 3
#define BGS_COM19200 4
#define BGS_COM38400 5
#define BGS_COM57600 6
#define BGS_COM115200 7

#define BGS_COMPARNUM 3
#define BGS_COMPARNONE 0
#define BGS_COMPAREVEN 1
#define BGS_COMPARODD  2

#define BGS_COMDTR 0
#define BGS_COMRTS 1
//----------- End COM -------------


//------------Values ------------------------------------------------------------------
#define BGS_INVALIDHANDLE ((BGSHANDLE)0xffffffff)

//BGS_ERROR, when returned into a BGSSL will be -1
#define BGS_ERROR 0xffffffff

#define BGS_PWR_RESETBIT 2
#define BGS_PWR_HARDBIT 1


#define BGS_TAMP_IDLE 0xff
#define BGS_TAMP_ARMED 0xfe
#define BGS_TAMP_TRIG 0xfc
#define BGS_TAMP_ACK 0xf8

#define BGS_PWROFF_IDLE 0xff
#define BGS_PWROFF_ARMED 0xfe
#define BGS_PWROFF_TRIG 0xfc

#define BGSSNDCHANNELSNUM 3
#define BGSVOLNUM 10

#define ROSSO 0x0000ff
#define GIALLO 0x00ffff
#define VERDE 0x00ff00
#define AZZURRO 0xffff00
#define BLU 0xff0000
#define VIOLA 0xff00ff
#define BIANCO 0xffffff
#define NERO 0x000001
#define GRIGIOS 0x606060
#define GRIGIO 0x808080
#define GRIGIOC 0x969696


//-------------End Values -----------------


BGSEXT BGSUL bgsFirstDDRBaseAdrUL;
BGSEXT BGSMUTEX _graMutex; //MOD_MUT

#ifdef _BGSCPLUSPLUS
extern "C" {
#endif


//-------------- Prototypes --------------------------------------------------------------
BGSBOOL BGSTamperSetStatus(BGSUC id,BGSUC newStatus)   ;
BGSUC BGSTamperGetStatus(BGSUC id,BGSTIME *time,BGSDATE *date);
BGSVOID BGSLastPwrOffSetStatus(BGSUC newStatus);
BGSUC BGSLastPwrOffGetStatus(BGSTIME *ti,BGSDATE *da);
BGSBOOL BGSTamperIsOpen(BGSUC id);//MOD_SIC6 modificato prot
BGSBOOL BGSIsPwrOn(BGSVOID);
BGSUS BGSGetBatLev(BGSUC id);
BGSUL BGSGetInitStatus(BGSVOID);
BGSVOID BGSSetInitStatus(BGSUL newStatus);
BGSBOOL BGSCheckLoadMacroBlock(BGSUS blockID); //MOD_MUT
BGSVOID BGSLoadMacroBlock(BGSUS blockID);
BGSVOID BGSUnloadMacroBlock(BGSUS blockID);
BGSVOID BGSSoundSetVolume(BGSUC lev);
BGSVOID BGSSoundPlay(BGSUL id,BGSUC chan,BGSBOOL cycle);
BGSVOID BGSSoundStop(BGSUC chan);
BGSBOOL BGSSoundIsPlaying(BGSUC chan);
BGSVOID BGSMicroReset(void);
BGSUL BGSThreadBegin(BGSTHREAD (*func)(void *),BGSUC pry,BGSUL8P stack,BGSUS stackSize,BGSVOIDP arg);
BGSVOID	BGSThreadExit(BGSVOID);
BGSVOID BGSThreadYield(BGSVOID);
BGSVOID BGSMutexInit(BGSMUTEXP mutex);
BGSVOID BGSMutexAq(BGSMUTEXP mutex);
BGSVOID BGSMutexRel(BGSMUTEXP mutex);
BGSVOID BGSRegisterHandler10ms(BGSVOID (*func)(BGSVOID));//MODQ26L
BGSVOID BGSSetInt10ms(BGSBOOL on);  //MODQ26L
BGSBOOL BGSTransactionalCheck(BGSVOID);

BGSVOID BGSFWrite(BGSVOIDP buf,BGSUL num,BGSUL pos,BGSFILE* fH);
BGSVOID BGSFRead(BGSVOIDP buf,BGSUL num,BGSUL pos,BGSFILE *fH);
BGSVOID BGSFErase(BGSFILE *file);
BGSUL   BGSFLen(BGSFILE *file);
BGSVOID BGSFCopy(BGSUL n,BGSUL srcOff,BGSFILE *srcFile,BGSUL dstOff,BGSFILE *dstFile, BGSUC flag);

BGSVOID BGSInterrupt(BGSBOOL en);
BGSVOID BGSGetTimeDate(BGSTIMEP time,BGSDATEP date);
BGSVOID BGSCtrlDate(BGSDATE *da,BGSBOOL incMonthOnDayOvf);
BGSVOID BGSSetTimeDate(BGSTIMEP time,BGSDATEP date);
BGSUL BGSGetMS(BGSVOID);
BGSVOID BGSSleepMS(BGSUS mS);
BGSVOID BGSPauseUS(BGSUL uS);
BGSVOID BGSNoShutAq(BGSVOID);
BGSVOID BGSNoShutRel(BGSVOID);
BGSUS BGSGetInpLev(BGSUS mask);
BGSUS BGSGetInpTrans(BGSUS mask);
BGSVOID BGSZeroFirstInpTrans(BGSUS mask);
BGSVOID BGSZeroAllInpTrans(BGSUS mask);
BGSVOID BGSSetOut(BGSUS mask,BGSUC value);
BGSVOID BGSEnableOut(BGSBOOL en);
BGSBOOL BGSResetCom(BGSUC comNum,BGSUC baudCode,BGSUC nBit,BGSUC nStop,BGSUC parCode);
BGSBOOL BGSWriteCom(BGSUC comNum,BGSVOIDP buf,BGSUL num);
BGSUL BGSReadCom(BGSUC comNum,BGSVOIDP buf,BGSUL num,BGSUL timeOutMS);
BGSBOOL BGSSetComCtrl(BGSUC comNum,BGSUC sig,BGSBOOL val);
BGSVOID BGSMicroReset(void);
BGSUL BGSRand(BGSUL num);
BGSVOID BGSNumToStringR(BGSUCP str, BGSSL num,BGSSL n);
BGSBOOL BGSMemoryRead(BGSVOIDP buf,BGSUL offset, BGSUL num);
BGSBOOL BGSMemoryWrite(BGSVOIDP buf,BGSUL offset, BGSUL num);
BGSBOOL BGSMemoryIsValid(BGSVOID);//MOD_SIC6 modificato prot
BGSBOOL BGSMemoryWasValidAtStartup(BGSVOID);

BGSVOID BGSMemoryInit(BGSTIME *ti,BGSDATE *da);//MOD_SIC6 modificato prot
BGSUL BGSKeyGet(BGSUL mask);
BGSUL BGSKeyLev(BGSUL mask);
BGSVOID BGSKeySet(BGSUL mask);
BGSVOID BGSKeyRst(BGSUL mask);
BGSVOID BGSAddCenteredBox(BGSUS id,BGSSS w,BGSSS h,BGSSS z,BGSUC alpha);
BGSVOID BGSMessageBox(BGSUCP msg, BGSBOOL show);
BGSVOID BGSDelMessageBox(BGSVOID);
BGSVOID BGSHWError(BGSUS code);

BGSVOID BGSAddImage(BGSUC video,BGSUS id_obj,BGSSS x,BGSSS y,BGSSS z,BGSUS w,BGSUS h,BGSUS x0,BGSUS y0,BGSUS id_img,BGSUS foto,BGSUC alpha,BGSUL jolly);
BGSVOID BGSAddImageFast(BGSUC video,BGSUS id_obj,BGSSS x,BGSSS y,BGSSS z,BGSUS id_img,BGSUS foto,BGSUC alpha,BGSBOOL doAlpha);
BGSVOID BGSAddString(BGSUC video,BGSUS id_obj,BGSSS x,BGSSS y,BGSSS z,BGSUS id_img,BGSUC alpha,BGSUL jolly,BGSUC *str);
BGSVOID BGSDelObj(BGSUC video,BGSUS id_obj);
BGSVOID BGSRepImage(BGSUC video,BGSUS id_obj,BGSSS x,BGSSS y,BGSSS z,BGSUS w,BGSUS h,BGSUS x0,BGSUS y0,BGSUS id_img,BGSUS foto,BGSUC alpha,BGSUL jolly);
BGSVOID BGSRepImageFast(BGSUC video,BGSUS id_obj,BGSSS x,BGSSS y,BGSSS z,BGSUS id_img,BGSUS foto,BGSUC alpha,BGSBOOL doAlpha);
BGSVOID BGSRepString(BGSUC video,BGSUS id_obj,BGSSS x,BGSSS y,BGSSS z,BGSUS id_img,BGSUC alpha,BGSUL jolly,BGSUC *str);
BGSVOID BGSRenderList(BGSUC video, BGSSS z_start);
BGSVOID BGSSetRenderTime(BGSUL delta);//MOD_RENDERTIME
BGSVOID BGSPrintConsole(BGSUCP str);
BGSVOID BGSAspettaQ(BGSVOID);
BGSVOID BGSCopyScreenToScreen(BGSUC videoDst,BGSUC onBackBufDst,BGSUC videoSrc,BGSUC onBackBufSrc);
BGSVOID BGSClearScreen(BGSUC video,BGSUC flag);
BGSVOID BGSClearRenderList(BGSUC video);
BGSVOID BGSInitRenderList(BGSVOID);
BGSUS BGSGetKeyTrans(BGSUS mask);
BGSUS BGSGetKeyLev(BGSUS mask);
BGSVOID BGSSetKeyTrans(BGSUS mask,BGSBOOL val);
BGSUS BGSGetAllExtIO(BGSVOID);
BGSVOID BGSSetAllExtIO(BGSUS data);
BGSVOID BGSSetExtIO(BGSUS mask, BGSBOOL val);
BGSVOID BGSSetLed(BGSUC led,BGSUC val);
BGSVOID BGSToggleLed(BGSUC led);
BGSUL BGSRandHW(BGSVOID);
BGSBOOL BGSSDRRefreshOneBlk(BGSVOID);//MOD_SDROB
BGSVOID BGSSDRForceRefresh(BGSVOID);//MOD_SDROB//MOD_BK3
BGSVOID BGSSdrRefreshPwrUp(BGSVOID);//MOD_SDROB
BGSVOID BGSEprChk(BGSVOID); //MOD_EC
#ifdef _BGSCPLUSPLUS
}
#endif

//QUESTO INCLUDE DEVE STARE QUI
#if defined (_BGSWIN32)
#include "hwwin32.h"
#endif













#endif
