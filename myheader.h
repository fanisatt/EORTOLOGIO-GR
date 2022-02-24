// cd /home/fanisatt/CMAKE/
// gcc -o prog_24 prog_24.c -lSDL_bgi -lSDL2
// gcc -o prog_34.bin prog_34.o input2.o -lSDL_bgi -lSDL2
// zenity --calendar --date-format='%Y-%m-%d , %a'


#include <graphics.h>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define pause while (!(event())) refresh()
#define GR 1
#define EN 0
#define ttf 8

// Set cursor position
void gotoxy(int x, int y);
 
// Clear terminal screen and set cursor to top left
void clrscr();
// ***************************************************
int fileselector( char *popor, char *old , int max);
int Start_strstr(char *big, char *sma);
FILE * read_pipe( char *popor );
int fastmenu_show(short int plbut, char menu[][120], char *but_name, unsigned short int moux, unsigned short int mouy );
char * pedaba_calendar(short int arped);
short int _show_month (unsigned short int xt, unsigned short int yt, unsigned short int uyear,unsigned short int umonth,unsigned short int uday,unsigned short int stamonth);
short int find_dayname (unsigned short int uyear,unsigned short int umonth,unsigned short int uday) ;
//int menu_dbfiles(char *loaddbfile);
//int recent_files_inform (char *ndbpath , char *ndbname) ;
int mystrcpy_lim (unsigned char *str1 , unsigned char * str2 , int orio);
int choise_alert (char *str1,char *str2, short int akyro);
//void * muldbfield_show_button(void *mem_str, unsigned char *pedia, unsigned int ar, unsigned short int orio, unsigned char *but_name, short int *sorton , short int sort_type , short int delon , unsigned short int *disk_dom, unsigned short int *flag_mulsel);
void * mulbutton_show(void *mem_str, unsigned short int ar, unsigned short int orio, char *but_name, short int *sorton,short int delon );
int qnum_input(char *str, int xl,int yt,int xr,int yb,int orio,int num_type);
int qtext_input(char *str, int xl,int yt,int xr,int yb,int orio);
//int criterio_show (int *cochxr , int *cobkxr);
int mystr_show(short int font, unsigned char *mystr, char *headername, unsigned short int moux, unsigned short int mouy, int *cochxr , int *cobkxr );
void _outfanis_colxr(unsigned int font, char *str ,  unsigned short int x, unsigned short int y, unsigned short int xr, int *cchxr, int *cbkxr);
int filehelp_show(short int font, char *filename, char *helpname, unsigned short int moux, unsigned short int mouy, int *cochxr , int *cobkxr ) ;
unsigned short int hlp_txt_scroll (short int font, unsigned short int cur, unsigned char *str, unsigned short int ar, short int xl , short int yt , short int xr , short int yb , int *cochxr , int *cobkxr);
void *prosans_21();
int spec_alert (int id,char *seleo,char *seleo1, char *img_file , int *spbkxr);
//int photofield_show_button(void *mem_str, unsigned int ar, short int arped, short int arped2, short int *sorton , unsigned short int *disk_dom);
//int info_dbsec(short int arped , unsigned short int *ar_dom);
void *proimpact_20();
int smmenu_show(short int plbut, char menu[][120], char *but_name, unsigned short int moux, unsigned short int mouy );
int bmptodisk_new (char *bmpname, unsigned int size_bytes,int width, int height);
void *procaviar_22();
void *convertinp_strstr  (short int left_right, char  *str, short int arped, unsigned short int *how_many, unsigned short int *cur);
void *prosans_18();
int fonts_show(void *mem_str, char *data, unsigned short int ar, unsigned short int orio, char *but_name, short int *sorton,short int delon, int *proxchxr, int *proxbkxr , int *proxslxr );
int info_dbfnt();
void *protimes_18();
void hide_help(unsigned short int xt1, unsigned short int yt1);
void show_help(char *text_help,unsigned short int xt, unsigned short int yt, unsigned short int *xt1 , unsigned short int *yt1);
void *proarial_12();
//int input_compl_search ();
//unsigned short int field_txt_scrollsearch (short int arped, unsigned short int cur, short int xl , short int yt , short int xr , short int yb , unsigned short int orio , int *cochxr , int *cobkxr, int *coslxr);
//unsigned char * convert_and_strstr  (short int arped, unsigned short int *how_many, unsigned short int *cur);
void what_mytime (time_t mytime, char *str);
int mystrcmp (unsigned char *str1 , unsigned char *str2);
int input_dbsearch_text(unsigned char *inp_str , short int arped );
int input_dbsearch_date(unsigned char *iso_str , unsigned char *meg_str, unsigned char *mik_str , short int arped );
int input_dbsearch_num(unsigned char *iso_str , unsigned char *meg_str, unsigned char *mik_str, short int type, short int arped );
int input_cardnum(unsigned char *inp_str);
//int dbfield_show_button(void *mem_str, unsigned char *data, unsigned int ar, unsigned short int orio, unsigned char *but_name, short int *sorton , short int sort_type , short int delon , unsigned short int *disk_dom );
//int info_dbfdata(short int arped , unsigned short int *ar_dom);
void pro_sort_usint (unsigned short int *item,int count);
void qui_sort_usint (unsigned short int *item , int left , int right);
void pro_sort_uint (unsigned int *item,unsigned short int *point,int count);
void qui_sort_uint (unsigned int *item , unsigned short int *point , int left , int right);
void pro_sort_double (double *item,unsigned short int *point,int count);
void qui_sort_double (double *item , unsigned short int *point , int left , int right);
void pro_sort_signedlong (long int *item,unsigned short int *point,int count);
void qui_sort_signedlong (long int *item , unsigned short int *point , int left , int right);
int info_dbfds() ;
//int change_mikrodbpos(short int proel, int dx, int dy, int *xl, int *yt ,int *xr , int *yb);
int mypolystr (unsigned char *mega , unsigned char *mikro);
void _field_txt_show (char *str , unsigned short int cur, short int xl , short int yt , short int xr , short int yb , unsigned short int orio , int *colchxr, int  *colbkxr);
int _outmystr_center_col(unsigned int font, unsigned char *str ,  unsigned short int x, unsigned short int y, unsigned short int xr,unsigned short int yb, int *colchxr, int *colbkxr);
void _outmystr_col(unsigned int font, unsigned char *str ,  unsigned short int x, unsigned short int y, unsigned short int xri,int *xxr, int *bbk);
int mystrcpy (unsigned char *str1 , unsigned char * str2);
void * named_button_load(unsigned short int *ptr_orio, unsigned short int *ptr_ar, char *full_name);
int mytext_toclipboard (char *data);
void qui_sort_24b(void *vitem , unsigned short int *point , int left , int right);
void pro_sort_24b(void *vitem, unsigned short int *point,int count);
int button_show(void *mem, char *data, unsigned short int ar, unsigned short int orio, char *but_name, short int *sorton,short int delon );
void pro_sort_ulong (unsigned long int *item,unsigned short int *point,int count);
void qui_sort_ulong (unsigned long int *item , unsigned short int *point , int left , int right);
void * button_load(unsigned short int *ptr_orio, unsigned short int *ptr_ar, char *but_name);
void _outfanis_colsel(unsigned int font, char *str ,  unsigned short int x, unsigned short int y, unsigned short int xr);
void _outfanis_center_col(unsigned int font, char *str ,  unsigned short int x, unsigned short int y, unsigned short int xr);
void _outfanis_col(unsigned int font, char *str ,  unsigned short int x, unsigned short int y, unsigned short int xr);
int normtext_tomy(char *normstr , char *mystr);
void what_time (char *str);
int mytext_tonorm(unsigned char *mystr , char *normstr, int orio);
int input_alert (int id,char *seleo, char *inp_str, short int orio);
unsigned short int field_txt_scroll (char *str , unsigned short int cur, short int xl , short int yt , short int xr , short int xb , unsigned short int orio , int *cochxr , int *cobkxr);
int _puticon (int x1,int y1,void *mem1,int transp);
int _outnoto_col(int x, int y, char *str, int lang, int *chxr, int *bkxr);
int _outsouv_col(int x, int y, char *str, int lang,int *chxr,int *bkxr);
void _bareacls (int x,int y,int r,int d,int *cbkxr);
void _areacls (int x,int y,int r,int d,int kok,int pra,int mpl);
int _outnoto_colsel(int x, int y, char *str, int lang, int *chxr, int *bkxr, int *selxr);
int _putNOTicon (int x1,int y1,void *mem1);
int _outsouv_colsel(int x, int y, char *str, int lang, int *chxr, int *bkxr, int *selxr);
int text_input(char *str, int xl,int yt,int xr,int yb,int orio);
void pro_sort_int (int *item,unsigned short int *point,int count);
void qui_sort_int (int *item , unsigned short int *point , int left , int right);
int putNOTicon (int x1,int y1,void *mem1);
int outsouv_colsel(int x, int y, char *str, int lang, int *chxr, int *bkxr, int *selxr);
double convert_str(short int len , char *str);
int num_input(char *str, int xl,int yt,int xr,int yb,int orio,int num_type);
int outnoto_colsel(int x, int y, char *str, int lang, int *chxr, int *bkxr, int *selxr);
//int inkualizer (int *chrxr , int *bkgxr , int *selxr);
void bareacls (int x,int y,int r,int d,int *cbkxr);
void information (int id,char *seleo,char *seleo1);
void *sfalmata();
int alert (int id,char *seleo,char *seleo1);
int rgb_choose (int *bkxr , int *chxr) ;
int outsouv_col(int x, int y, char *str, int lang,int *chxr,int *bkxr);
int outnoto_col(int x, int y, char *str, int lang,int *chxr,int *bkxr);
int puticon (int x1,int y1,void *mem1,int transp);
int change_pos(int *xl, int *yt ,int *xr , int *yb);
int change_dim(int xl, int yt ,int *mxright , int *mybottom);
int pontik_rec(int *mxl, int *myt ,int *mxright , int *mybottom) ;
void fontoicW (int x , int y, int red, int green, int blue, void *mem1);
int puticW(int x, int y, void *mem_w);
void *icWtomem (char *filename);
int Wbmptodisk (char *bmpname, unsigned int size_bytes,short int width, short int height);
int outnoto_sma(int x, int y, char *str, int lang);
int outnoto_big(int x, int y, char *str, int lang, int syntx , int synty);
int outnoto(int x, int y, char *str, int lang);
void *pronoto();
void *icontomem (char *filename,int transp);
int bmptodisk (char *bmpname, unsigned int size_bytes,int width, int height);
int input(unsigned char *str, int *pxl,int *pyt,int *pxr,int *pyb,int orio,short int arped,unsigned short int wherp1);
void proinput ();
void fidicls(int x, int y, int x1, int y1 , int red , int green, int blue);
void cls();
int outsouv(int x, int y, char *str, int lang);
void * prosouv();
void areacls (int x,int y,int r,int d,int kok,int pra,int mpl);
void qcls (int kok,int pra,int mpl);
void efecls (int x,int y,int w,int h,int kok,int pra,int mpl);
long int inp_numb();

extern int my_esc;
extern int my_err;
extern char eid[44] ;

extern  unsigned char etm[22][3] ;

extern unsigned short int unico[69][2];

extern struct viewporttype info;
extern struct viewporttype *info_p ;


extern void *greek_addr, *souv_addr , *mem_sarial;
extern void *mem_small  , *mem_times , *mem_sans , *mem_caviar , *mem_impact ;

extern struct fansouv {
    char who;
    short int wid;
    short int hei;
    void *where;
} souv[165] ; // Σύνολο χαρακτήρων +1//

extern struct fansouv nouv[165] , sarial[165] , times18[165] , sanser18[165], caviar22[165] , impact20[165] ,  sanser21[165] ;
extern struct fansouv *gouv;

extern struct fansouv *myfont[ttf];
extern short int myfont_hei[ttf];
extern short int myfont_wid[ttf];
extern char myfont_name [ttf][20]; 

extern struct fachars {
unsigned int scacod [57];
unsigned char faprint [57][2];
unsigned int sort [57][2];
} engl , grek ;

extern char user_name[36];
extern char file_1[1024];
extern char file_2[1024];
extern char str1kb[1386];
extern unsigned char file_3[512];
extern char path_name[512];
extern short int keyb_gr  ;
extern short int keyb_us  ;

extern SDL_Event sdlev;
extern int win_id ;
extern int chxr[3];
extern int bkxr[3];
extern int slxr[3];

extern char *sfalma;
extern int topbkxr[3];
extern int topchxr[3];
extern int topslxr[3];
extern int dbbkxr[3];
extern int dbchxr[3];
extern int dbslxr[3];
extern int bkxr1[3];
extern int chxr1[3];
extern int slxr1[3];
extern int eisag[3];
extern int delerg[3];
extern int klperg[3];
extern int sxedom[3];
extern int parous[3];
extern int parous[3];
extern int klperg[3];
extern int syncardchxr[3];
extern int syncardbkxr[3];
extern unsigned short int mmed[24];


extern struct db_bu {
    unsigned short int butt_orio;
    unsigned short int butt_ar;
    unsigned char butt_name[128];
    void *mem_butt;
    unsigned char butt_data[128];
    int butt_elem;
    unsigned short int butt_sorton;
} dbbut [10];

extern struct ope_bu {
     unsigned short int butt_orio;
    unsigned short int butt_ar;
    unsigned char butt_name[40];
    void *mem_butt;
    unsigned char butt_data[40];
    int butt_elem;
    unsigned short int butt_sorton;
} open_buts ;

// struct Data Base Fields (dbfds)
extern struct {
     unsigned short int fd_orio;
    unsigned short int fd_ar;
    unsigned char fd_name[40];
    void *mem_fd;
    unsigned char fd_data[40];
    int fd_elem;
    unsigned short int fd_sorton;
} dbfds ;

// struct Data Base Field Data (dbfdata)
extern struct {
    unsigned short int fd_orio;
    unsigned int fd_ar;
    unsigned char fd_name[40];
    void *mem_fd;
    unsigned char fd_data[40];
    int fd_elem;
    unsigned short int fd_sorton;
    short int fd_sort_type ;
    unsigned short int fd_arped;
} dbfdata;

/*
struct criterio {
    union {
    unsigned int gitem[3];
    long int litem[3];
    double fitem[3];
    } numcr ;
 
    unsigned char sample [3][26];
    unsigned char sample_t [22] ;
    unsigned char sample_tcode[22];
    void *mem_ghost ;
    short int cron ;
    short int cron_1;
} ;
*/
//extern struct criterio *multicr[100];

extern short int dbmaxbut ;           // Πόσα συνολικά buttons είναι φορτωμένα ! (μέχρι 10 / 0-9 / αρχική τιμή -1)
extern short int delon ; //Καλαθάκι αχρήστων για τη button show !

/*
struct fanfield {
    short int finum ;
    unsigned char finame[30];                // field name=label
    short int fitype;       // 0-6 : text, list gen, list spec, int number , float numb , photo-image , date
    unsigned short int fiorio; // Μέγιστος αριθμός χαρακτήρων
    short int ficode;            // τετραψήφιος κωδικός
    unsigned char filistname[25];  //List Name (specific)
    unsigned short int fixt;  // field data xt - yt ....
    unsigned short int fiyt;
    unsigned short int fiwid;
    unsigned short int fihei;
    unsigned short int filaxt;  // field label xt-yt...
    unsigned short int filayt;
    unsigned short int filawid;
    unsigned short int filahei;    
    unsigned short int fipg; // Σελίδα στην οποία εμφανίζεται !
    int fibkxr[3];                         // field and field name colors
    int fichxr[3];
    int fislxr[3];
    short int fivar[7];
    // 0 : Δεδομένα εντός πλαισίου ΝΑΙ - ΌΧΙ 
    // 1 : Θέση δεδομέν. κλειδωμ.      //     //
    // 2 : Απόκρυψη δεδομένων         //     //
    // 3 : Ορατό όνομα πεδίου          //      //
    // 4 : Όνομα πεδίου σε πλαίσιο  //       //
    //5  : Θέση Ονόμ. πεδ. κλειδ.     //      //
    //6 :  Προκατ font                     //       //
    short int fifont;
    unsigned short int fifo_hei;
    unsigned short int fifo_wid; 
    time_t fiwhen;
} ;
*/
//extern struct fanfield *ptr_pedio[100];         // Μέγιστος αριθμός πεδίων
//extern struct fanlabel *ptr_etiket[50];        // Μέγιστος αριθμός ετικετών

extern char savedbpath[768] , LDdbfile[1024] ;
extern char *loaddbfile;
extern char str1024 [2048];        // Γενικής Χρήσης str
extern int pdaba[4] , pdaca;
extern unsigned short int dblasize, dbfisize , dbplgr , dbplera, dbpg , dbcurpage , dbar , dbrecxr , dbscrxr ,dbmag , dbtop , dbselxr , dbred , dbgreen , dbblack , dbyel , dbhelpcol ;
extern short int dbfinum , dblanum ;
extern unsigned char dbtime[100];
extern time_t loctime , metatime , protime ;
extern char *ptr_char;
extern struct tm *diary;
extern FILE *fpdb  , *fpcard ;
extern unsigned short int dbkey , prodbkey;
extern unsigned char synolo_butstr[230]; //Για τα 10 ονόματα των 10 το πολύ φορτωμένων λιστών
extern unsigned char* synolo_fds , *synolo_fdata ;
extern unsigned int size_fds ;
extern unsigned int size_fdata;
//extern char mmestr[24][110];
//extern unsigned int Xt,Xb,Yt,Yb,Wt,Wb,Ht,Hb ; // Menu Line , x and y Coordinates / Width - Height of screen elements 
//extern unsigned short int topinfxt, topinfyt , topinfxb, topdbnamext, toppgxt , dbcard , dbtotcardxt , dbtotcardxb;
//extern char top_str[40] , card_str [10];
//extern void *memx1 , *memy1 , *memx2 , *memy2 ; // Δέσμευση μνήμης για τις συντεταγμένες όλων των rectangles (πεδία + labels) - απόδοση της μνήμης σε int * και στο τέλος απελευθέρωση των memx... 
//extern unsigned short int *dbx1 , *dby1 , *dbx2 , *dby2 ; // Εδώ είναι τα arrays των συντεταγμένων.
//extern short int dbrecs ; // (Το άθροισμα των στοιχείων που αντιστοιχούν σε rectangles στις σελίδες της βάσης δεδομένων)
//extern short int db_elem[150][2] ;
//extern void *memk[100];
//extern unsigned short int limk[100] , xlimk[100] , xlim , xmemk ;
extern unsigned char *keimk;
//extern unsigned short int curk[100];
//extern unsigned int dbcardsize , alma_deigma ;
extern time_t cardwhen ;

extern union {
    unsigned int ldate;
    unsigned char mydate[4]; // mydate[3]=0 , mydate[2]=year-1900 , mydate[1]=month , mydate[0]=day;
} cardiary;

extern union {
    unsigned short int wotim;
    unsigned char dyomikra[2];
} dysena;

extern unsigned short int hdhlpxt , hdhlpyt ;
extern int * baserg ;
extern short int seflag ;
extern struct {
     unsigned short int fn_orio;
    unsigned short int fn_ar;
    unsigned char fn_name[30];
    void *mem_fn;
    unsigned char fn_data[20];
    int fn_elem;
    unsigned short int fn_sorton;
} dbfnt;

extern unsigned char  *synolo_fnts ;
extern unsigned int size_fnts;
extern void *inp_mem_ghost ;
extern unsigned short int gocards , firstcrit; // gocards = πόσες κάρτες ικανοποιούν κριτήρια , firstcrit = ο α/α της πρώτης κάρτας ...
extern char submenu[15][120];
extern unsigned short int dbaspro;

extern struct {
    unsigned int fd_ar;
    unsigned short int fd_sorton;
    void *mem_fd;
} dbsec;

extern unsigned int size_sec ;
extern unsigned char *synolo_sec ;
extern int helpchxr[3] , helpbkxr[3] ;
extern FILE *fpch ;
extern char missing[40];
extern unsigned short int *epil_pos ;
extern unsigned short int tot_opts;
extern short int user_opts;
extern unsigned short int mulsel ;
//extern unsigned char crits[65534]; // Αν είναι 1 τότε η κάρτα ικανοποιεί τα κριτήρια εύρεσης.
extern char *dropfile;
extern unsigned char langex ;
extern short int logand ;
extern unsigned char normdeigma[22] ;
extern int fide_fpdb , fide_fpcard ;
extern char big_char [3096];
extern int status, fsel_code ;
extern char efarm_path[26] ;
extern int nofire , nochrom ;
extern void *remem;
extern pid_t pid ;
extern char *orisma[3];
extern SDL_DisplayMode DM;
