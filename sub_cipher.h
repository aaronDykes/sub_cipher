#ifndef _SUB_CHIPER
#define _SUB_CHIPER

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define alphabet            26
#define encrypted_length(X) sizeof(X) / sizeof(X[0])

static struct freq {
	int  *char_freq;
	int  *alpha_sort[alphabet];
	char *str;
} freq = {NULL, {0}, NULL};

typedef struct freq Freq;

static void frequency_analysis(Freq *);
static void sort_frequency(Freq *);  // Must sort this array
static void display_freq_analysis(Freq *);
static void input(Freq *);
static void swap_ch(Freq *, char, char);
static void str_cop(char *, char *);

static char cipher[] =
    "MDTNOHQY NDG XQQH TLHYREKTRQG, DHG RNQYQ VQEQ GOYREOXKRQG RL RNQ DXVQNE, "
    "VNOTN XQZDH KYOHZ RNQM OH 1944. QDYQ LC MDOHRQHDHTQ VDY HLR D YRELHZ "
    "BLOHR LC RNQ YZ-41. EQMLFDS LC RNQ TLFQE OHFLSFQG EQMLFOHZ\n\n";

static char cipher2[] =
    "KIJ I OBUXIGFUIT UFPXBR LBYFUB OIEFGH QJB SD ZXB PRFGUFPTB SD JTFLFGH ZKS "
    "PRFGZBL JZRFPJ IHIFGJZ SGB IGSZXBR IUUSRLFGH ZS I PRBJURFABL PTIG ZS "
    "HBGBRIZB ZXB UFPXBR BNQFYITBGZJ.\n\n";

static char cipher3[] =
    "TG OZCHS YWFA UADHWEAS GYA AVTXPW MAHZO GYA HAFAH ZR STFTJTZV. VTVAGAAV "
    "RZUGI-RTFA OWJ GZZ HWGA; TR TG YWS MAAV TVGUZSCEAS TV 1942, TG EZCHS YWFA "
    "EYWVXAS GYA EZCUJA ZR GYA OWU.\n\n";

static char cipher4[] =
    "YBZXYSSU TBKXKTYSXN WXLV SKTB LW YJL HSG-JLXO VZMSO KPRBKASYN JSXS "
    "JXZYYSU LU YBS WZMSO AKNS, KUO YBS LYBSX YBZXYSSU LW SKTB LU YBS YLR KUO "
    "ALYYLV\n\n";

static char cipher5[] =
    "HXQ SQOIBED XBC B SUUC XQBC DHBOH WE HXQ PUEDHOLPHWUE UG IQPXBEWPBR "
    "POATHUCQKWPQD JQGUOQ HXQ JQSWEEWES UG VUORC VBO WW VWHX QEWSIB, BEC "
    "CQKQRUTQC QFPQRRQEH QEPWTXQOQC HQRQTOWEHQO CQKWPQD VWHX HXQ H-52D "
    "BEC\n\n";

static char mapping[] =
    "\tA <------> V\n\tB <------> T\n\tC <------> F\n\tD <------> I\n\tE "
    "<------> Y\n\tG <------> L\n\tH <------> S\n\tJ <------> R\n\tK <------> "
    "W\n\tM <------> X\n\tN <------> U\n\tO <------> P\n\tQ <------> Z\n\n";

static char common[] = "ETAOIN SHRDLU\n\n";

#endif
