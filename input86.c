#include </home/fanisatt/CMAKE2/myheader.h>

// SKATOYLES

int num_input(char *str, int xl,int yt,int xr,int yb,int orio,int num_type)
{
//extern short int keyb_gr ;
//extern short int keyb_us ;
SDL_Cursor* cursor;
register int i ,f ;
int mx , my , x , y , shift , size , size_cu, x1, y1 , x2, y2, col_cu, bkr, bkg, bkb, epr, epg, epb ,elax, diafy , epr1,epg1,epb1;
unsigned int time_metr ,ektos ;
unsigned char what ,secr ;
unsigned short int us_flag=1, ch_mod,ch_scan,curst , curend , elxor , ch1 ,ypo , mowid;
unsigned short int pre_paste=0, diak ,diaf1, diaf2,maxline, a, port=0 ;
const Uint8 *state ;
void *mem1 , *mem_cu , *mem_power;
int *mem_int ;
char *clipbo;
int pos[orio+1][2] ;
short int pros ,wrap ;
char ch,cha,chb;
short int start=0;
short int bh , tab=0;
int red,green,blue;
int main_cur[3] , ins_cur[3];

union whatcols{
unsigned int lor ;
unsigned char rgb[4];
} co ;

unsigned short int wherp=0 , pre_cur=0, cur=0, ar=0, ins=0 ;
unsigned short int vam[3];
static unsigned int warn ;
static int xl1,yt1,xr1,yb1;
unsigned char klik ;

float neg, alfa ;

elax=mowid=gouv[16].wid;
bh=gouv[16].hei;
for (f=17;f<26;f++) {
    if (bh<gouv[f].hei) bh=gouv[f].hei;
    mowid+=gouv[f].wid;
    if (elax > gouv[f].wid) continue ; else elax=gouv[f].wid;}
if ((yb-yt+1)<bh) return (-1) ; // Κωδικός που δείχνει ότι το ύψος του πλαισίου δεν κάνει... !!
mowid /= 10 ;
if (xl1!=xl || yt1!=yt || xr1!=xr || yb1!=yb) {
    warn=0;
    xl1=xl ; yt1=yt; xr1=xr; yb1=yb;
}
if ( ((orio*mowid*9/10) > (xr-xl+1)) && (!warn) ) {warn=1; information (30-keyb_gr,0,0);}
vam[0]=0;
bkr=bkxr[0] ; bkg=bkxr[1] ;bkb=bkxr[2];  // ΕΔΩ καθορίζεται το backround color !!!
epr =slxr[0] ; epg=slxr[1] ;  epb=slxr[2] ; // ΕΔΩ παίρνει τις τιμές χρώματος όταν επιλέγεται κείμενο !!
main_cur[0] = 255-((epr+bkr)/2) ; main_cur[1] = 255-((epg+bkg)/2) ; main_cur[2] = 255-((epb+bkb)/2) ; // Κύριο χρώμα του κέρσορα !  
setrgbpalette(4099,main_cur[0],main_cur[1],main_cur[2]); // To 4099 κύριο χρώμα του κέρσορα
ins_cur[0] = 255-((epr+chxr[0])/2) ; ins_cur[1] = 255-((epr+chxr[1])/2) ; ins_cur[2] = 255-((epr+chxr[2])/2) ; // To "Insert" χρώμα του κέρσορα !
setrgbpalette(4100,ins_cur[0],ins_cur[1],ins_cur[2]); // To 4100 = insert χρώμα του κέρσορα
epr1 = epr + 70; if (epr1>255) epr1=255;
epg1 = epg + 50; if (epg1>255) epg1=255;
epb1 = epb + 40; if (epb1>255) epb1=255;

// dh=(2*bh)-1;
if (orio<=0) return 0;

// *pxl=xl; *pyt=yt; *pxr=xr ; *pyb = yb;
elax=(xr-xl)/elax ; // ELAXISTH XVRHTIKOTHTA GRAMMHS ANALOGA TO MEGISTO PLATOS

size=imagesize(xl,yt,xr,yb);
mem1=malloc(size);
if (!mem1) { printf ("Out of memory") ; return 0; }
size_cu=imagesize(0,0,1,(bh-1));
mem_cu=malloc(size_cu);
if (!mem_cu) { printf ("Out of memory") ; free (mem1); return 0; }
getimage(xl,yt,xr,yb,mem1);
x=xl ; y=yt;
//diaf1=yb-yt+1; diaf2=diaf1/bh;maxline=diaf2; ektos=yt+(diaf2*bh);
maxline=1;ektos=yt+bh;
col_cu = 4099; //green=15; // blue=20;
time_metr=0;
diak=0;
pos[0][0]=xl ; pos[0][1]=yt;
for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
x1=x ; y1=y;
//ELEGXOS TOY ALFARIUMHTIKOY str kai parousiash tou keimenou //

            // ELEGXOS !!
    ypo=0;
    what=str[0];
    if (what !=255) {
        f=0; diaf2=0;
        while ( (what!=255) && (orio-f) ) {
            switch (num_type) {
                case 0:
                case 1: //Θετικός ακέραιος
                    if ( (what>15) && (what<26) ) {f++;what=str[f];continue;}
                    diaf2=1;break;

                case 2: //Αρνητικός ή θετικός ακέραιος
                    if ( (what==13) && (!f) ) {f++;what=str[f];continue;}
                    if ( (what>15) && (what<26) ) {f++;what=str[f];continue;}
                    diaf2=1;break;

                case 3 : // Float
                    if ( (what==13) && (!f) ) {f++;what=str[f];continue;}
                    if ( (what>15) && (what<26) ) {f++;what=str[f];continue;}
                    if ( (what==12) && (f) && (!ypo) ) {
                        if (str[f-1]!=13){
                        ypo=1; f++;what=str[f];continue;}}
                    diaf2=1;break;
                    
            }
            break ;
        } 
        
        str[f]=255; diaf1=f;
        ar=diaf1;
                     
       // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ       
        x1=xl ; y1=yt;
        for (a=0; a<ar; a++) {
        what=str[a];
        if (what==200) str[a]=16;
        wrap=0 ;  
        if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }
        pos[a][0]=x1 ; pos[a][1]=y1 ;
        what=str[a];
        x1+=gouv[what].wid;
        }
            str[ar]=255 ;
            pos[ar][0]=x1 ; pos[ar][1]=y1;
            // for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
            // ΝΕΑ ΕΜΦΑΝΙΣΗ
                        
           
        x1=xl; y1=yt;
       
        for (a=wherp; a<ar; a++) {
        what=str[a];
 
        x1=pos[a][0]; y1=pos[a][1];
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) continue;
        
        // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
        setcolor(COLOR (red,green,blue));
        _putpixel(x1+i , y1+f);}}
        }
        refresh();
        x=pos[cur][0] ; y=pos[cur][1];
    } 

Enarjh :

for(;;) {


            time_metr++;
        if (time_metr>150000) {
            time_metr=0;
            if (!diak) {
            getimage(x,y,x+1,y+bh-1,mem_cu);   
            diak=1;
            setrgbcolor(col_cu); 
            for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
            _putpixel(x+i,y+f) ;} }
            refresh() ; 
            }
            else {putimage(x,y,mem_cu,0); refresh() ; diak=0;}}
    
    
if (!SDL_PollEvent(&sdlev)) continue;
    
    switch (sdlev.type) {
    
    case SDL_MOUSEMOTION:
    mx=sdlev.motion.x ; my=sdlev.motion.y;

    
    if (mx>xl && mx<xr && my>yt && my<yb) {
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
   SDL_SetCursor(cursor);continue;}
   
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
   SDL_SetCursor(cursor);
    continue;
    
        
    case SDL_MOUSEBUTTONDOWN:
    if(sdlev.button.button==SDL_BUTTON_LEFT) {   
        auto int pev ;
        mx = sdlev.button.x ; my= sdlev.button.y ;
        klik= sdlev.button.clicks; 
                
        
        // Μέσα στο Κείμενο κλίκ....
        if ( mx>xr || mx<xl || my>yb || my<yt ) goto DROMO;
        if (vam[0]) {                              //σβηνω κερσορα - ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb)) ;  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            x1= pos[a][0] ; what=str[a];
           
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}            
            refresh();
            vam[0]=0;
            }
        if (!ar) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1]; 
        diaf1=2*xr;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
       curst= --f;
       chb=0;
       if (curst>=ar) {chb=1; curst=ar-1;}
       
               if (klik>1) {
           
            f=curst=0;
            vam[1]=0;
            what=str[f];
            while (what<200) {what=str[++f];}
            vam[2] = f ;
            if (vam[1]==vam[2]) continue ;
            if (!f) continue ;
            vam[2] = (f==ar) ? f-1 : f ;
            vam[0]=1;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (epr,epg,epb)); 
            for (a=vam[1]; a<=vam[2]; a++) {
            y1=pos[a][1] ;
            if (y1<yt) continue ;
            if (y1>=ektos) break ;
            what=str[a];
            x1=pos[a][0] ; 
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
            }
            refresh();  
            goto DIPLO_KLn ;

    }
    
        do {
        
        pev = SDL_PollEvent(&sdlev);
       mx = sdlev.button.x ; my= sdlev.button.y ;
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1];
        diaf1=2*xr;
        //if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
    curend= --f;
    if (curend>=ar) curend=ar-1;
      
    if(!vam[0]) {
        // ΒΑΦΩ ΑΡΧΙΚΑ //
        if (curst==curend) continue ;
        vam[0]=1;
        
        if (curend<curst) { vam[1]=curend ; vam[2]=curst ; pros=0; curst=vam[1]; curend=vam[2]; }
        else { pros=1 ; vam[1]=curst; vam[2]=curend ; }
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1= pos[a][1] ;
        
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
    
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f); } f++ ;}
        }
        refresh();continue ;}
        
        if (pros) {
        
        if (curend>vam[2]) {
       
       // Βάφω από vam[2] έως νέο curend //
             setcolor (COLOR (epr,epg,epb));  
       for (a=vam[2]+1; a<=curend; a++) {
       what=str[a];
       x1=pos[a][0] ; y1= pos[a][1] ;
      
       mem_int=gouv[what].where ;
       for(f=0; f<gouv[what].hei ; f++) {
       for(i=0;i<gouv[what].wid;i++) {
       co.lor = *mem_int++;
       if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
  
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
        }   
       vam[2]=curend; vam[0]=1;
       refresh();continue ;}
            
     if ((curend<vam[2]) && (curend>vam[1])) {
           //ξεβάφω MONON.. //
          setcolor (COLOR (bkr,bkg,bkb));  
        for (a=curend; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
       
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
         
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[2]=curend;
        vam[0]=1;
        refresh();continue ;
    }       
    
    if (curend<=vam[1]) {
        
    // Ξεβάφω από vam[1] έως vam[2] //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }       
        
        if (curend==vam[1])  {vam[0]=0 ; curst=curend ; refresh(); continue ;}
        vam[2] = curst ; vam[1]=curend ; pros=0; vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        curst=vam[1] ; curend=vam[2];
        continue ;}}
        else {
        // Από εδώ και πέρα σημαίνει pros=0 //
        
        if (curend<curst) {
            // Βάφω από curend έως vam1 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=curend; a<=vam[1]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
       
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        vam[1]=curend; curst=vam[1];vam[0]=1;continue;}
        
        if ( (curend>vam[1]) && (curend<vam[2]) ) {
        //ξεβάφω MONON.. //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<curend; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }            
        refresh(); vam[1]=curend ; curst=vam[1]; continue; }
        
        if (curend >= vam[2]) {
        // Ξεβάφω από vam1 έως vam2 //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }
        
        if (curend==vam[2]) {curst=curend ; vam[0]=0 ; continue ; }
        
        vam[1]=vam[2]; vam[2]=curend; curst=vam[1]; pros=1;vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
      
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();continue;}}       
        
    }  while (!pev || sdlev.type!=SDL_MOUSEBUTTONUP) ; 
    
DIPLO_KLn :
    cur=curst;
    if ( (!vam[0]) && (cur==ar-1) && (chb) ) cur=ar ;
    x=pos[cur][0] ; y=pos[cur][1];
    continue;}
    
    // Right Click Menu !!                            Right Click Menu !!    
    
                                                                                    
              continue ;
             
    case SDL_KEYDOWN:
        ch_scan=sdlev.key.keysym.scancode;
        ch_mod=SDL_GetModState();
     
        switch (ch_scan) { // Φεύγοντας από την switch με break πάμε για εκτύπωση !!
            
            case SDL_SCANCODE_ESCAPE :
                goto DROMO;
                                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;
                    }
                str[ar]=255; putimage(xl,yt,mem1,0);  free(mem1) ; free(mem_cu);                              
                  cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                SDL_SetCursor(cursor);refresh() ; ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;return 0;
            
                               
                    case SDL_SCANCODE_BACKSPACE :
                 
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                what=str[a]; if(what==12) ypo=0; 
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                printf("vam1: %u , vam2 : %u, ar = %u \n",vam[1], vam[2], ar);
                cur = vam[1] ;
esot_anadiat:  
                // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ NUM IMPUT
                if (str[0] == 12) {
                    for (a=ar-1;a>0;a--) {str[a]=str[a-1];}
                    str[0]=16;
                }
                x1=xl ; y1=yt;
                
                for (a=0; a<ar; a++) {
                what=str[a];
                pos[a][0]=x1 ; pos[a][1]=y1 ;
                x1+=gouv[what].wid;
                if ( x1 > xr-2) { x1=xr-2;
                    for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    }
                    ar=a ; break; }

                }
                
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                    
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                    
               
                x1=pos[a][0]; y1=pos[a][1];
                if (y1>=ektos) break ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                }
                x=pos[cur][0] ; y=pos[cur][1];
                 refresh();
                pre_cur=0;pre_paste=0;
                continue;
                }                
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
               
                if (cur==ar) {
                    what=str[ar-1];
                    if(what==12) ypo=0; 
                    x1=pos[ar-1][0] ; y1=pos[ar-1][1] ;
                    pos[ar][0]=pos[ar][1]=-1;
                    if (what!=200) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x1;i<=x1+gouv[what].wid;i++) { for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}
                    }
                    refresh();
                    x=x1; y=y1;
                    ar--; cur--; str[ar]=255;
                    }
                    
                else {
                        // if ( (str[cur]==12) && !(cur-1) ) continue;
                        if(str[cur-1]==12) ypo=0; 
                        x1=pos[cur-1][0]; y1=pos[cur-1][1]; 
                        cur--;
                        for(f=cur;f<ar;f++) str[f]=str[f+1];
                        ar--;
                       
entos_back :
                         // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if ( (y1+bh) >=yt) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                
                secr=(cur) ? 1 : 0 ;                
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];   
                if ( (y1<yt) && (secr) ) {
                    f=0; while (pos[f][1]!=y1) f++;
                    secr=cur-f;
                    //while (pos[cur-secr][1] != xl) secr++;
                    diaf1=abs(pos[cur-secr][1] - yt);
                    pos [cur-secr][1]=yt;
                    x1=xl ; y1=yt;
                    for (f=0 ; f<cur-secr ; f++) pos[f][1]+=diaf1;
                }
                        
                for (a=cur-secr; a<ar; a++) {
                    
                    what=str[a];
                    
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    } break; }

                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if ( (y1>=ektos) || (y1<yt) ) { x1+=gouv[what].wid; wrap--; continue ; }
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;
                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 x=pos[cur][0] ; y=pos[cur][1];
                 if (y<yt) { 
                     while (y<yt) {cur++; y = pos[cur][1] ; }
                     x=pos[cur][0] ; 
                }
                
                }
                continue;
  
                
                                  
                    case SDL_SCANCODE_DELETE :
                 
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; if(what==12) ypo=0;  
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                cur = vam[1] ;
                goto esot_anadiat;}
                
                                           
                 if (cur==ar) continue ;
                 if(str[cur]==12) ypo=0; 
                 // if ( (str[cur+1]==12) && (!cur) ) continue;
                 x1=pos[cur][0] ; y1 = pos[cur][1];
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for(f=cur;f<ar;f++) str[f]=str[f+1];
                 ar--;
                                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                what=str[a];
                
                wrap=0;                
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    } break ; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if (y1>=ektos) {x1+=gouv[what].wid;wrap--; continue;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;   
                    } while (wrap>=0);
                }
                 refresh();
                 if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 continue; 
  
                
                    case SDL_SCANCODE_END :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f<=ar ; f++) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1];
                 continue ;
              
                    case SDL_SCANCODE_TAB :
                        tab=1;
                        goto DROMO ;
                 
                
                    case SDL_SCANCODE_HOME :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));   
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                 
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f>0 ; f--) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = ++f ; if ( (cur==1) && (pos[0][1]==y) ) cur=0;
                 x=pos[cur][0] ; y=pos[cur][1];    
                   continue ;
                
                                 
                    case SDL_SCANCODE_INSERT :
                        
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                  
                  col_cu = (col_cu==4099) ? 4100 : 4099 ;
                  ins=abs(ins-1);
                 
                   continue ;
                  
                    case SDL_SCANCODE_LEFT :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                          //ΣΒΗΝΩ CURSOR
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                cur-- ; y=pos[cur][1];
                x=pos[cur][0]; 
                continue;
                
                    case SDL_SCANCODE_RIGHT :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                                  
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 cur++ ;
                 y=pos[cur][1];
                x=pos[cur][0]; 

                 continue;                
                 
                 case SDL_SCANCODE_RCTRL :
                 case SDL_SCANCODE_LCTRL :
                 continue;

                    case SDL_SCANCODE_V :  //PASTE
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME V 
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                        {                        
      
 // ΑΝΤΙΓΡΑΦΩ ΟΣΑ ΕΠΙΤΡΕΠΕΤΑΙ ΑΠΟ ΤΟ SYSTEM CLIPBOARD αναλόγως του insert //
        if (!SDL_HasClipboardText()) continue;
        clipbo=SDL_GetClipboardText();
        if (clipbo==NULL) continue;
        if ( (orio==ar) && (!vam[0]) ) {SDL_free(clipbo); continue ;}
        
        
        if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
       y1= pos[a][1] ;
        if (y1>=ektos || y1<yt) continue ;
         what=str[a]; if(what==12) ypo=0; 
        x1= pos[a][0] ; 
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[0]=0;
        // Εσωτερική Αναδιάταξη !
        cur = vam[1] ;
        for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
        diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
        
        }
        if(!ins) elxor=orio-ar; else elxor=orio-cur;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        if (!ins) {
            
            for(f=ar,i=0; (f>=cur) ; f--,i++) str[orio-i]=str[f];
            diaf1=orio-i+1;}
    
f=0 ; a=0 ; 
ch=clipbo[f];
    while ( (ch!='\0') && (elxor) ) {
        if (ch<0) {f++;ch=clipbo[f]; continue;}
        else {
            if (ch=='\n') {f++;ch=clipbo[f]; continue;}
            for(i=0;i<95;i++) {if (ch!=gouv[i].who) continue ; else break ;}
            if (i==95) {f++; ch=clipbo[f];continue;}    
            switch (num_type) {
                case 0:
                case 1: //Θετικός ακέραιος
                    if ( (i>15) && (i<26) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    break;

                case 2: //Αρνητικός ή θετικός ακέραιος
                    if ( (i==13) && (!(cur+a)) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    if ( (i>15) && (i<26) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    break;
                    
                case 3 : // Float
                    if ( (i==13) && (!(cur+a)) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    if ( (i>15) && (i<26) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    if ( (i==12) && ((cur+a)) && (!ypo)) {
                        if (str[cur+a-1] != 13) {
                        ypo=1; str[cur+a]=i ; a++ ; elxor-- ;break;}}
            }
f++; ch=clipbo[f];
        }
    }
    
         if (!ins) ar +=a ; else {
             if (cur+a > ar) ar=(cur+a); }
         if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
         SDL_free(clipbo);
        goto esot_anadiat;}                        
                 
                   }
        break;
                  
                        case SDL_SCANCODE_C :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME C (* Copy) //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                                if (!vam[0]) continue;
                                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                                size=0;
                                for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) size++;
                                    else if ( (what>94) && (what<164) ) size+=2;
                                    else size++; }
                                    size++;
                                    clipbo=malloc(size);
                                    if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                                    a=0;
                                    for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) {
                                        clipbo[a]=gouv[what].who; a++;}
                                    else if ( (what>94) && (what<164) ) {
                                        cha=((unico[what-95][0]/256)-255);
                                        chb = (unico[what-95][0] % 256);
                                        clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                                    else if (what==200) {clipbo[a]='\n' ; a++;}}
                                    clipbo[a]='\0';
                                    size=SDL_SetClipboardText(clipbo);
                                    if (!size) {
                                       
                                        setcolor (COLOR (epr1,epg1,epb1));  
                                        for (a=vam[1]; a<=vam[2]; a++) {
                                        y1=pos[a][1] ;
                                        if (y1<yt || y1>=ektos) continue;
                                        what=str[a];
                                        x1=pos[a][0] ; 
                                        mem_int=gouv[what].where ;
                                        for(f=0; f<gouv[what].hei ; f++) {
                                        for(i=0;i<gouv[what].wid;i++) {
                                        co.lor = *mem_int++;
                                        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                                        refresh();
                                    } 
                                    free(clipbo);
                                    continue;  }
                    break ;
                    
                 
DROMO :
                    case SDL_SCANCODE_RETURN :
                    case 88 :
                 
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ;diak=0;}
                    
                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;
                    }
                    
              // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ ENDEXOMENVS
                if (str[0]==12) {
                for (a=ar-1;a>0;a--) {str[a]=str[a-1];}
                str[0]=16;
                
                x1=xl ; y1=yt;
                for (a=0; a<ar; a++) {
                what=str[a];
                
                wrap=0 ;  
                                

                pos[a][0]=x1 ; pos[a][1]=y1 ;
                what=str[a];
                 x1+=gouv[what].wid;
                 
                }
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                    
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                x1=pos[a][0]; y1=pos[a][1];
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                _putpixel(x1+i , y1+f);}}
                }
                 refresh();
                }
                    
                    free(mem1) ; free(mem_cu);         
                    str[ar]=255;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh(); diaf1=ar; ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; if (!tab) return diaf1; else return -9 ;
                    
                                 
                }
                        
                    
            //ΕΛΕΓΧΟΣ ΠΡΙΝ ΤΗΝ ΕΚΤΥΠΩΣΗ ΕΝΟΣ ΧΑΡΑΚΤΗΡΑ //
            if (vam[0]) {                              // ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb));   
            for (a=vam[1]; a<=vam[2]; a++) {
             y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            what=str[a];
            x1= pos[a][0] ;
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
            }
            refresh();
            vam[0]=0;
            }
            // if ( (num_type) && (ch_scan<30 || ch_scan>39) ) continue ;
                
            if (ch_scan<57) {
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME CHAR
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        shift=1 ; break ;
                    default : shift = 0; }
                  
            what = engl.sort[ch_scan][shift] ;
            
            a=0; 
            switch (num_type) {
                case 0:
                case 1: //Θετικός ακέραιος
                    if ( (what>15) && (what<26) ) {a=1 ; break;}
                    break;
                    
                case 2: //Αρνητικός ή θετικός ακέραιος
                    if ( (what==13) && (!cur) ) {a=1 ; break;}
                    if ( (what>15) && (what<26) ) {a=1 ; break;}
                   break;
                   
                case 3 : // Float
                    if ( (what==13) && (!cur) ) {a=1 ; break;}
                    if ( (what>15) && (what<26) ) {a=1 ; break;}
                    if ( (what==12) && (cur) && (!ypo) ) {
                        if (str[cur-1]!=13) {
                        ypo=1; a=1 ; break;}}
            }
            if (!a) continue ;
            if ( (x+gouv[what].wid) > xr-2) continue ;
            
            typechar:
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            
            if (cur==ar) {
            if ( orio==ar ) continue ;
   
            str[ar]=what ; ar++; cur++; str[ar]=255 ;
            wrap=0;
             
            do {
            pos[(cur-1-wrap)][0]=x ; pos[(cur-1-wrap)][1]=y ;
            what=str[cur-1-wrap];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x+i , y+f);}}
            refresh();
            x=x+gouv[what].wid;
            wrap--;
            }while (wrap>=0);
            pos[cur][0]=x; pos[cur][1]=y;
            refresh();
                     }
            
            else {                               // cur != ar
             
               if (!ins) {
                    if ( orio==ar ) continue ;
                    if ( (!cur) && (str[0]==13) ) continue ;
                    ar++;
                    for(f=ar; f>cur; f--) str[f]=str[f-1];
                   str[cur]=what ;
                   if ( (what) && (ar<orio) && (cur) ) {
                           if (str[cur+1] && (!str[cur-1])) {
                               ar++;
                               for(f=ar; f>cur+1; f--) str[f]=str[f-1];
                               str[cur+1]=0;
                           }
                       }
            }
                if ( (str[cur]==12) && (what!=12) ) ypo=0;    
                str[cur]=what;
                f=0;i=0;
                while (pos[cur-f][0]!=xl) f++;
                if ((cur-f)) {
                i = f+1;
                while ( pos[cur-i][0] !=xl ) {
                    if (str[cur-i]!=200) i++;
                    else {i=0;break;} }}
                secr = (i) ? i : f ;
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];
                
                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur-secr; a<ar; a++) {
                    what=str[a];
                        
                    if (what==200) {pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh;  continue ;}
                    wrap=0;            
                    if ((x1+gouv[what].wid) > xr-2) { ar=a ; for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    } break ; }

                        
                    do { 
                    pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;     
                    what=str[a-wrap];
                    if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                    
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;
                    wrap--;
                    }while (wrap>=0);
                }
                
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) {cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else {x=x1; y=y1;}
                                     
                }

                continue ;
              }
              continue;

    case SDL_WINDOWEVENT :
    refresh(); continue;

    default:
    continue;
   }
 } 
}

int text_input(char *str, int xl,int yt,int xr,int yb,int orio)
{
SDL_Cursor* cursor;
register int i ,f ;
int mx , my , x , y , shift , size , size_cu, x1, y1 , x2, y2, yep, col_cu, bkr, bkg, bkb, epr, epg, epb ,elax, diafy , epr1,epg1,epb1;
unsigned int time_metr ,ektos ;
unsigned char what ,secr ;
unsigned short int us_flag, ch_mod,ch_scan,caps_lock,ton=0,dial=0,met=0, curst , curend , elxor , ch1 ,mowid;
unsigned short int pre_paste=0, diak ,diaf1, diaf2,maxline, a, port=0 ;
unsigned short int outmen; 
const Uint8 *state ;
void *mem1 , *mem_cu , *mem_power ;
int *mem_int ;
char *clipbo;
int pos[orio+1][2] ;
short int pros ,bh, wrap ,tab=0 ;
char ch,cha,chb;
int red,green,blue;
int main_cur[3] , ins_cur[3];


union whatcols{
unsigned int lor ;
unsigned char rgb[4];
} co ;

static short int gr_flag ;
unsigned short int wherp , pre_cur, cur, ar, vam[3] , ins ;
unsigned char klik ;

float neg, alfa ;

switch (langex) {
    
    case 0:
        if (keyb_gr) { gr_flag=1; us_flag=0; } 
        else { gr_flag=0 ; us_flag=1; }
        break ;
        
    case 1:
        us_flag=1; gr_flag=0;
        break ;
        
    case 2:
        us_flag=0; gr_flag=1;
}

elax=mowid=gouv[0].wid;
bh=gouv[0].hei;
for (f=1;f<164;f++) {
    if (bh<gouv[f].hei) bh=gouv[f].hei;
    mowid+=gouv[f].wid;
    if (elax > gouv[f].wid) continue ; else elax=gouv[f].wid;}
if ( (yb-yt+1)<bh ) return (-1) ; // Κωδικός που δείχνει ότι το ύψος του πλαισίου δεν κάνει... !!
mowid /= 164 ;
if ( (orio*mowid) > (xr-xl+1) ) return (-2) ; // Κωδικός που δείχνει ότι δεν γίνεται edit εδώ λόγω χώρου !!
cur=0;ar=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;
bkr=bkxr[0] ; bkg=bkxr[1] ;bkb=bkxr[2];  // ΕΔΩ καθορίζεται το backround color !!!
epr =slxr[0] ; epg=slxr[1] ;  epb=slxr[2] ; // ΕΔΩ παίρνει τις τιμές χρώματος όταν επιλέγεται κείμενο !!
main_cur[0] = 255-((epr+bkr)/2) ; main_cur[1] = 255-((epg+bkg)/2) ; main_cur[2] = 255-((epb+bkb)/2) ; // Κύριο χρώμα του κέρσορα !  
setrgbpalette(5099,main_cur[0],main_cur[1],main_cur[2]); // To 5099 κύριο χρώμα του κέρσορα
ins_cur[0] = 255-((epr+chxr[0])/2) ; ins_cur[1] = 255-((epr+chxr[1])/2) ; ins_cur[2] = 255-((epr+chxr[2])/2) ; // To "Insert" χρώμα του κέρσορα !
setrgbpalette(5100,ins_cur[0],ins_cur[1],ins_cur[2]); // To 5100 = insert χρώμα του κέρσορα
epr1 = epr + 70; if (epr1>255) epr1=255;
epg1 = epg + 50; if (epg1>255) epg1=255;
epb1 = epb + 40; if (epb1>255) epb1=255;

if (orio<=0) return 0;

elax=(xr-xl)/elax ; // ELAXISTH XVRHTIKOTHTA GRAMMHS ANALOGA TO MEGISTO PLATOS

size=imagesize(xl,yt,xr,yb);
mem1=malloc(size);
if (!mem1) { printf ("Out of memory") ; return 0; }
size_cu=imagesize(0,0,1,(bh-1));
mem_cu=malloc(size_cu);
if (!mem_cu) { printf ("Out of memory") ; free (mem1); return 0; }
getimage(xl,yt,xr,yb,mem1);

areacls(xl,yt,xr,yb,bkr,bkg,bkb);
x=xl ; y=yt;
// diaf1=yb-yt+1; diaf2=diaf1/bh;maxline=diaf2; ektos=yt+(diaf2*bh);
maxline=1;ektos=yt+bh;

// ELEGSOS GIA CAPS LOCK PATHMENO XVRIS MPERDEMA ME ALLA PLHKTRA //
SDL_FlushEvent (SDL_KEYDOWN);
state = SDL_GetKeyboardState(NULL);
ch_mod=SDL_GetModState();
caps_lock = ( (ch_mod==8192) || (ch_mod==12288) ) ? 1 : 0 ;

col_cu = 5099; 
time_metr=0;
diak=0;
pos[0][0]=xl ; pos[0][1]=yt;
for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
x1=x ; y1=y;
//ELEGXOS TOY ALFARIUMHTIKOY str kai parousiash tou keimenou //

            // ELEGXOS !! 
    what=str[0];
    if (what !=255) {
        f=0; diaf2=0;
        while ( (what!=255) && (orio-f) ) {
        if (what==200) {str[f]=0; f++;what=str[f];continue;}
        if ( (what>=0) && (what<164) ) {f++;what=str[f];continue;}
        else {str[f]=0; f++;what=str[f];continue;}
            } 
        str[f]=255; diaf1=f;
        ar=diaf1;cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;
                     
       // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ       
        x1=xl ; y1=yt;
        
        for (a=0; a<ar; a++) {
        what=str[a];
        pos[a][0]=x1 ; pos[a][1]=y1 ;
        x1+=gouv[what].wid;
        if (x1 > xr-2) {ar=a+1 ; x1=xr-2 ; break ; }

        }
            str[ar]=255 ;
            pos[ar][0]=x1 ; pos[ar][1]=y1;
            // for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}  (έχει ήδη γίνει αυτό)
            // ΝΕΑ ΕΜΦΑΝΙΣΗ
            
        x1=xl; y1=yt;
       
        for (a=0; a<ar; a++) {
        what=str[a];         

        x1=pos[a][0]; y1=pos[a][1];
        if (y1>=ektos) break ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) continue;

        // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
        setcolor(COLOR (red,green,blue));
        _putpixel(x1+i , y1+f);}}
        }
        refresh();
        x=pos[cur][0] ; y=pos[cur][1];

    } 

Enarjh :

for(;;) {

    time_metr++;
if (time_metr>150000) {
    time_metr=0;
    if (!diak) {
    getimage(x,y,x+1,y+bh-1,mem_cu);   
    diak=1;
    setrgbcolor(col_cu); 
    for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
    _putpixel(x+i,y+f) ;} }
    refresh() ; 
    }
    else {putimage(x,y,mem_cu,0); refresh() ; diak=0;}}
    
if (!SDL_PollEvent(&sdlev)) continue;
    
    switch (sdlev.type) {
    
    case SDL_MOUSEMOTION:
    mx=sdlev.motion.x ; my=sdlev.motion.y;
    SDL_FlushEvent(SDL_MOUSEMOTION);

    if (mx>xl && mx<xr && my>yt && my<yb) {
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
   SDL_SetCursor(cursor);continue;}
   
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
   SDL_SetCursor(cursor);
    continue;
    
    case SDL_MOUSEWHEEL :
            
        continue ;
        
    case SDL_MOUSEBUTTONDOWN:
    if(sdlev.button.button==SDL_BUTTON_LEFT) {   
        auto int pev ;
        mx = sdlev.button.x ; my= sdlev.button.y ;
        klik= sdlev.button.clicks; 
        // Μέσα στο Κείμενο κλίκ....
        if ( mx>xr || mx<xl || my>yb || my<yt ) goto DROMO;
        if (vam[0]) {                              //σβηνω κερσορα - ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb)) ;  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            x1= pos[a][0] ; what=str[a];
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}            
            refresh();
            vam[0]=0;
            }
        if (!ar) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1]; 
        diaf1=2*xr;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
       curst= --f;
       chb=0;
       if (curst>=ar) {chb=1; curst=ar-1;}
       
        if (klik>1) {
           
            f=curst=0;
            vam[1]=0;
            what=str[f];
            while (what<200) {what=str[++f];}
            vam[2] = f ;
            if (vam[1]==vam[2]) continue ;
            if (!f) continue ;
            vam[2] = (f==ar) ? f-1 : f ;
            vam[0]=1;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (epr,epg,epb)); 
            for (a=vam[1]; a<=vam[2]; a++) {
            y1=pos[a][1] ;
            if (y1<yt) continue ;
            if (y1>=ektos) break ;
            what=str[a];
            x1=pos[a][0] ; 
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
            }
            refresh();  
            goto DIPLO_KLt ;

    }
       
        do {
        pev = SDL_PollEvent(&sdlev);
       mx = sdlev.button.x ; my= sdlev.button.y ;
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1];
        diaf1=2*xr;
        //if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
    curend= --f;
    if (curend>=ar) curend=ar-1;
      
    if(!vam[0]) {
        // ΒΑΦΩ ΑΡΧΙΚΑ //
        if (curst==curend) continue ;
        vam[0]=1;
        
        if (curend<curst) { vam[1]=curend ; vam[2]=curst ; pros=0; curst=vam[1]; curend=vam[2]; }
        else { pros=1 ; vam[1]=curst; vam[2]=curend ; }
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1= pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) { for(i=x1;i<xr-1;i++)  {_putpixel (i,f); }}refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
    
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f); } f++ ;}
        }
        refresh();continue ;}
        
        if (pros) {
        
        if (curend>vam[2]) {
       
       // Βάφω από vam[2] έως νέο curend //
             setcolor (COLOR (epr,epg,epb));  
       for (a=vam[2]+1; a<=curend; a++) {
       what=str[a];
       x1=pos[a][0] ; y1= pos[a][1] ;
      
       if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh(); continue ;}
       mem_int=gouv[what].where ;
       for(f=0; f<gouv[what].hei ; f++) {
       for(i=0;i<gouv[what].wid;i++) {
       co.lor = *mem_int++;
       if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
  
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
        }   
       vam[2]=curend; vam[0]=1;
       refresh();continue ;}
            
     if ((curend<vam[2]) && (curend>vam[1])) {
           //ξεβάφω MONON.. //
          setcolor (COLOR (bkr,bkg,bkb));  
        for (a=curend; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
       
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
         
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[2]=curend;
        vam[0]=1;
        refresh();continue ;
    }       
    
    if (curend<=vam[1]) {
        
    // Ξεβάφω από vam[1] έως vam[2] //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }       
        
        if (curend==vam[1])  {vam[0]=0 ; curst=curend ; refresh(); continue ;}
        vam[2] = curst ; vam[1]=curend ; pros=0; vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        curst=vam[1] ; curend=vam[2];
        continue ;}}
        else {
        // Από εδώ και πέρα σημαίνει pros=0 //
        
        if (curend<curst) {
            // Βάφω από curend έως vam1 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=curend; a<=vam[1]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
       
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        vam[1]=curend; curst=vam[1];vam[0]=1;continue;}
        
        if ( (curend>vam[1]) && (curend<vam[2]) ) {
        //ξεβάφω MONON.. //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<curend; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }            
        refresh(); vam[1]=curend ; curst=vam[1]; continue; }
        
        if (curend >= vam[2]) {
        // Ξεβάφω από vam1 έως vam2 //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }
        
        if (curend==vam[2]) {curst=curend ; vam[0]=0 ; continue ; }
        
        vam[1]=vam[2]; vam[2]=curend; curst=vam[1]; pros=1;vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
      
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();continue;}}       
        
    }  while (!pev || sdlev.type!=SDL_MOUSEBUTTONUP) ; 

DIPLO_KLt :
    cur=curst;
    if ( (!vam[0]) && (cur==ar-1) && (chb) ) cur=ar ;
    x=pos[cur][0] ; y=pos[cur][1];
    continue;}
    
    // Right Click Menu !!                            Right Click Menu !!    

             
    case SDL_KEYDOWN:
        ch_scan=sdlev.key.keysym.scancode;
        ch_mod=SDL_GetModState();
        if (keyb_gr) {
        state=SDL_GetKeyboardState(NULL);
        if ((state[SDL_SCANCODE_RALT] || state[SDL_SCANCODE_LALT]) && (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])) { us_flag=abs (us_flag-1) ; gr_flag=abs(gr_flag-1) ; ton=0; dial=0; 
        if (us_flag) {ton=0;dial=0;}
        continue ;}
        }
        
        switch (ch_scan) { // Φεύγοντας από την switch με break πάμε για εκτύπωση !!
            
            case SDL_SCANCODE_ESCAPE :  
                goto DROMO ;
                                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;
                    }
                str[ar]=255; putimage(xl,yt,mem1,0);  free(mem1) ; free(mem_cu);                              
                  cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                  langex = (us_flag) ? 1 : 2 ;
                SDL_SetCursor(cursor);refresh() ; return 0;
            
            case SDL_SCANCODE_SEMICOLON : //Τόνος για Ελληνικά

                if (!gr_flag) break ;
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME TONO - Περίπτωση διαλυτικών //
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        dial=1 ; continue ;
                    default : ton = 1; continue;}
                    
                    case SDL_SCANCODE_BACKSPACE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
esot_anadiat:  
                // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ 
                
                x1=xl ; y1=yt;
                
                for (a=0; a<ar; a++) {
                what=str[a];
                pos[a][0]=x1 ; pos[a][1]=y1 ;
                x1+=gouv[what].wid;
                if ( x1 > xr-2) { x1=xr-2; ar=a ; break; }
                }
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                     
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                    
                if (what==200) continue ;
                x1=pos[a][0]; y1=pos[a][1];
                if (y1>=ektos) break ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                }
                x=pos[cur][0] ; y=pos[cur][1];
                 refresh();
                pre_cur=0;pre_paste=0;
                continue ;
                }                
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
               
                if (cur==ar) {
                    what=str[ar-1];
                    x1=pos[ar-1][0] ; y1=pos[ar-1][1] ;
                    pos[ar][0]=pos[ar][1]=-1;
                    if (what!=200) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x1;i<=x1+gouv[what].wid;i++) { for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}
                    }
                    refresh();
                    x=x1; y=y1;
                    ar--; cur--; str[ar]=255;
                    }
                    
                else {
                         
                        x1=pos[cur-1][0]; y1=pos[cur-1][1]; 
                        cur--;
                        for(f=cur;f<ar;f++) str[f]=str[f+1];
                        ar--;
                       
entos_back :
                         // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if ( (y1+bh) >=yt) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                
                secr=(cur) ? 1 : 0 ;                
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];   
                if ( (y1<yt) && (secr) ) {
                    f=0; while (pos[f][1]!=y1) f++;
                    secr=cur-f;
                    //while (pos[cur-secr][1] != xl) secr++;
                    diaf1=abs(pos[cur-secr][1] - yt);
                    pos [cur-secr][1]=yt;
                    x1=xl ; y1=yt;
                    for (f=0 ; f<cur-secr ; f++) pos[f][1]+=diaf1;
                }
                        
                for (a=cur-secr; a<ar; a++) {
                    
                    what=str[a];
                    
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }

                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if ( (y1>=ektos) || (y1<yt) ) { x1+=gouv[what].wid; wrap--; continue ; }
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 x=pos[cur][0] ; y=pos[cur][1];
                 if (y<yt) { 
                     while (y<yt) {cur++; y = pos[cur][1] ; }
                     x=pos[cur][0] ; 
                }
                
                }
                continue ;
  
                
                    case SDL_SCANCODE_CAPSLOCK :
                        caps_lock = abs (caps_lock-1) ; 
                    continue ;
                
                    case SDL_SCANCODE_DELETE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
                goto esot_anadiat;}
                
                                           
                 if (cur==ar) continue ;
                 x1=pos[cur][0] ; y1 = pos[cur][1];
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for(f=cur;f<ar;f++) str[f]=str[f+1];
                 ar--;
                                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                what=str[a];
                
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh; continue ;}
                wrap=0;                
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if (y1>=ektos) {x1+=gouv[what].wid;wrap--; continue;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;   
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 if (x1>xr-2) x1=xr-2 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 continue ; 
  
                
                    case SDL_SCANCODE_END :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f<=ar ; f++) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1];
                 continue ;
                
                
                    case SDL_SCANCODE_HOME :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));   
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                 
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f>0 ; f--) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = ++f ; if ( (cur==1) && (pos[0][1]==y) ) cur=0;
                 x=pos[cur][0] ; y=pos[cur][1];    
                   continue ;
                
                    case SDL_SCANCODE_HELP :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                   continue ;
                   
                    case SDL_SCANCODE_TAB :
                        tab=1;
                        goto DROMO ;
                
                    case SDL_SCANCODE_INSERT :
                if (keyb_gr) {ton=0 ; dial=0 ;}       
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                  
                  col_cu = (col_cu==5099) ? 5100 : 5099 ;
                  ins=abs(ins-1);
 
                          refresh();
                   continue ;
                  
                    case SDL_SCANCODE_LEFT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                          //ΣΒΗΝΩ CURSOR
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                cur-- ; y=pos[cur][1];
                x=pos[cur][0]; 
                continue ;
                
                    case SDL_SCANCODE_RIGHT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                                  
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 cur++ ;
                 y=pos[cur][1];
                x=pos[cur][0]; 
                   continue ;
                        

                    case SDL_SCANCODE_V :  //PASTE
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME V 
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                        {                        
      
 // ΑΝΤΙΓΡΑΦΩ ΟΣΑ ΕΠΙΤΡΕΠΕΤΑΙ ΑΠΟ ΤΟ SYSTEM CLIPBOARD αναλόγως του insert //
        if (!SDL_HasClipboardText()) continue;
        clipbo=SDL_GetClipboardText();
        if (clipbo==NULL) continue;
        if ( (orio==ar) && (!vam[0]) ) {SDL_free(clipbo); continue ;}
        
        if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
       y1= pos[a][1] ;
        if (y1>=ektos || y1<yt) continue ;
         what=str[a];
        x1= pos[a][0] ; 
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[0]=0;
        // Εσωτερική Αναδιάταξη !
        cur = vam[1] ;
        for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
        diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
        
        }
        if(!ins) elxor=orio-ar; else elxor=orio-cur;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        if (!ins) {
            
            for(f=ar,i=0; (f>=cur) ; f--,i++) str[orio-i]=str[f];
            diaf1=orio-i+1;}
            // Προσδιορισμός του Pre_Paste
            
        if (!pre_cur) {
        f=cur;
        if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                } else pre_paste=0;} 
                   else pre_paste=0;

        f=0 ; a=0 ;
        ch=clipbo[f];
        while ( (ch!='\0') && (elxor) ) {
            if (ch<0) {
                
                f++ ; ch1= ( (256*ch) + clipbo[f] ) ;
                for (i=0 ; i<69 ; i++) {
                    if (ch1==unico[i][0]) {
                        str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                        if (i==69) {str[cur+a]=0 ; a++ ; elxor--; f--; }
                f++; ch=clipbo[f];continue;
             }
            else {
                if (ch=='\n') {f++; ch=clipbo[f]; continue;}
                for(i=0;i<95;i++) {
                    if (ch==gouv[i].who) {
                        str[cur+a]=i ; a++ ; elxor-- ;break;}}
                        if (i==95) {str[cur+a]=0 ; a++ ; elxor--;}
                f++;ch=clipbo[f];
                  }
        }
         if (!ins) ar +=a ; else {
             if (cur+a > ar) ar=(cur+a); }
         if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
         SDL_free(clipbo);
        goto esot_anadiat;}                        
                 
                   }
        break;
                  
                        case SDL_SCANCODE_C :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME C (* Copy) //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                                if (!vam[0]) continue;
                                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                                size=0;
                                for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) size++;
                                    else if ( (what>94) && (what<164) ) size+=2;
                                    else size++; }
                                    size++;
                                    clipbo=malloc(size);
                                    if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                                    a=0;
                                    for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) {
                                        clipbo[a]=gouv[what].who; a++;}
                                    else if ( (what>94) && (what<164) ) {
                                        cha=((unico[what-95][0]/256)-255);
                                        chb = (unico[what-95][0] % 256);
                                        clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                                    else if (what==200) {clipbo[a]='\n' ; a++;}}
                                    clipbo[a]='\0';
                                    size=SDL_SetClipboardText(clipbo);
                                    if (!size) {
                                       
                                        setcolor (COLOR (epr1,epg1,epb1));  
                                        for (a=vam[1]; a<=vam[2]; a++) {
                                        y1=pos[a][1] ;
                                        if (y1<yt || y1>=ektos) continue;
                                        what=str[a];
                                        x1=pos[a][0] ; 
                                        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
                                        mem_int=gouv[what].where ;
                                        for(f=0; f<gouv[what].hei ; f++) {
                                        for(i=0;i<gouv[what].wid;i++) {
                                        co.lor = *mem_int++;
                                        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                                        refresh();
                                    } 
                                    free(clipbo);
                                    continue;  }
                    break ;
                    
                    case SDL_SCANCODE_RCTRL :
                    case SDL_SCANCODE_LCTRL :
                        continue;
                    
DROMO :
                    case SDL_SCANCODE_RETURN :
                    case 88 :

                    if(diak) {putimage(x,y,mem_cu,0); refresh() ;}
                    
                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();}
                    
                    free(mem1) ; free(mem_cu);         
                    str[ar]=255;
                    langex = (us_flag) ? 1 : 2 ;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh(); diaf1=ar; ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;  if (!tab) return diaf1; else return -9 ;
                                 
                }
                        
                    
            //ΕΛΕΓΧΟΣ ΠΡΙΝ ΤΗΝ ΕΚΤΥΠΩΣΗ ΕΝΟΣ ΧΑΡΑΚΤΗΡΑ //
            if (vam[0]) {                              // ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb));   
            for (a=vam[1]; a<=vam[2]; a++) {
             y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            what=str[a];
            x1= pos[a][0] ;
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
            }
            refresh();
            vam[0]=0;
            }
                
            if (ch_scan<57) {
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME CHAR
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        shift=1 ; break ;
                    default : shift = 0; }
                  
                  // To caps_lock αντιστρέφει το shift για τα Α έως Ζ //
                    if (ch_scan>3 && ch_scan<30) {
                        if (caps_lock) shift = abs (shift-1) ;}
            what = (gr_flag) ? grek.sort[ch_scan][shift] : engl.sort[ch_scan][shift] ;
            if (!gr_flag) goto typechar ;
            if (dial) {
                switch (gouv[what].who) {
                    case 'i' :
                    case 'y' :
                    case 'I' :
                    case 'Y' :
                        met+=2 ; dial=0 ; break ;
                    default : dial=0 ; met=0 ;}}
                    
            if (ton) {
                switch (gouv[what].who) { 
                    case 'I' :
                    case 'Y' :    
                    met=1 ; ton=0 ; break ;
                case 'a' :
                case 'e' :               
                case 'h' :                  
                case 'i' :                    
                case 'o' :                    
                case 'y' :                   
                case 'v' :                   
                case 'A' :
                case 'E' :
                case 'H' :
               case 'O':
               case 'V' :
                   met+=1 ; ton =0 ; break ;
                default : met=0 ; ton=0;}}
                
            what += met ; met=0 ;
            

            typechar:
            if ( (x+gouv[what].wid) > xr-2) continue ;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            
            if (cur==ar) {
            if ( orio==ar ) continue ;
            str[ar]=what ; ar++; cur++; str[ar]=255 ;
            wrap=0;                
            
            do {
            pos[(cur-1-wrap)][0]=x ; pos[(cur-1-wrap)][1]=y ;
            what=str[cur-1-wrap];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x+i , y+f);}}
            refresh();
            x=x+gouv[what].wid;
            wrap--;
            }while (wrap>=0);
            pos[cur][0]=x; pos[cur][1]=y;
            refresh();
                     }
            
            else {                               // cur != ar
             
               if (!ins) {
                    if ( orio==ar ) continue ;
                    ar++;
                    for(f=ar; f>cur; f--) str[f]=str[f-1];
                   str[cur]=what ;
                   if ( (what) && (ar<orio) && (cur) ) {
                           if (str[cur+1] && (!str[cur-1])) {
                               ar++;
                               for(f=ar; f>cur+1; f--) str[f]=str[f-1];
                               str[cur+1]=0;
                           }
                       }
            }
                    
                str[cur]=what;
                f=0;i=0;
                while (pos[cur-f][0]!=xl) f++;
                if ((cur-f)) {
                i = f+1;
                while ( pos[cur-i][0] !=xl ) {
                    if (str[cur-i]!=200) i++;
                    else {i=0;break;} }}
                secr = (i) ? i : f ;
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];
                
                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur-secr; a<ar; a++) {
                    what=str[a];
                        
                    wrap=0;            
                    if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }
                        
                    do { 
                    pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;     
                    what=str[a-wrap];
                    if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                    
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;
                    wrap--;
                    }while (wrap>=0);
                }
                
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) {cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else {x=x1; y=y1;}
                    
                }
                continue ;

              }
              continue;
       

    case SDL_WINDOWEVENT :
    refresh(); continue;

    default:
    continue;
    
   }

} 

}

int qtext_input(char *str, int xl,int yt,int xr,int yb,int orio)
{
SDL_Cursor* cursor;
register int i ,f ;
int mx , my , x , y , shift , size , size_cu, x1, y1 , x2, y2, yep, col_cu, bkr, bkg, bkb, epr, epg, epb ,elax, diafy , epr1,epg1,epb1;
unsigned int time_metr ,ektos ;
unsigned char what ,secr ;
unsigned short int us_flag, ch_mod,ch_scan,caps_lock,ton=0,dial=0,met=0, curst , curend , elxor , ch1 ,mowid;
unsigned short int pre_paste=0, diak ,diaf1, diaf2,maxline, a, port=0 ;
unsigned short int outmen; 
const Uint8 *state ;
void *mem1 , *mem_cu , *mem_power ;
int *mem_int ;
char *clipbo;
int pos[orio+1][2] ;
short int pros ,bh, wrap ,tab=0 ;
char ch,cha,chb;
int red,green,blue;
int main_cur[3] , ins_cur[3];


union whatcols{
unsigned int lor ;
unsigned char rgb[4];
} co ;

static short int gr_flag ;
unsigned short int wherp , pre_cur, cur, ar, vam[3] , ins ;
unsigned char klik ;
float neg, alfa ;

switch (langex) {
    
    case 0:
        if (keyb_gr) { gr_flag=1; us_flag=0; } 
        else { gr_flag=0 ; us_flag=1; }
        break ;
        
    case 1:
        us_flag=1; gr_flag=0;
        break ;
        
    case 2:
        us_flag=0; gr_flag=1;
}
elax=mowid=gouv[0].wid;
bh=gouv[0].hei;
for (f=1;f<164;f++) {
    if (bh<gouv[f].hei) bh=gouv[f].hei;
    mowid+=gouv[f].wid;
    if (elax > gouv[f].wid) continue ; else elax=gouv[f].wid;}
if ( (yb-yt+1)<bh ) return (-1) ; // Κωδικός που δείχνει ότι το ύψος του πλαισίου δεν κάνει... !!
mowid /= 164 ;
if ( (orio*mowid) > (xr-xl+1) ) return (-2) ; // Κωδικός που δείχνει ότι δεν γίνεται edit εδώ λόγω χώρου !!
cur=0;ar=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;
bkr=bkxr[0] ; bkg=bkxr[1] ;bkb=bkxr[2];  // ΕΔΩ καθορίζεται το backround color !!!
epr =slxr[0] ; epg=slxr[1] ;  epb=slxr[2] ; // ΕΔΩ παίρνει τις τιμές χρώματος όταν επιλέγεται κείμενο !!
main_cur[0] = 255-((epr+bkr)/2) ; main_cur[1] = 255-((epg+bkg)/2) ; main_cur[2] = 255-((epb+bkb)/2) ; // Κύριο χρώμα του κέρσορα !  
setrgbpalette(5099,main_cur[0],main_cur[1],main_cur[2]); // To 5099 κύριο χρώμα του κέρσορα
ins_cur[0] = 255-((epr+chxr[0])/2) ; ins_cur[1] = 255-((epr+chxr[1])/2) ; ins_cur[2] = 255-((epr+chxr[2])/2) ; // To "Insert" χρώμα του κέρσορα !
setrgbpalette(5100,ins_cur[0],ins_cur[1],ins_cur[2]); // To 5100 = insert χρώμα του κέρσορα
epr1 = epr + 70; if (epr1>255) epr1=255;
epg1 = epg + 50; if (epg1>255) epg1=255;
epb1 = epb + 40; if (epb1>255) epb1=255;

if (orio<=0) return 0;

elax=(xr-xl)/elax ; // ELAXISTH XVRHTIKOTHTA GRAMMHS ANALOGA TO MEGISTO PLATOS

size=imagesize(xl,yt,xr,yb);
mem1=malloc(size);
if (mem1==NULL) {printf ("Out of Memory \n"); return 0 ; }
size_cu=imagesize(0,0,1,(bh-1));
mem_cu=malloc(size_cu);
if (mem_cu==NULL) {printf ("Out of Memory \n"); free(mem1); return 0 ; }
getimage(xl,yt,xr,yb,mem1);

areacls(xl,yt,xr,yb,bkr,bkg,bkb);
x=xl ; y=yt;
// diaf1=yb-yt+1; diaf2=diaf1/bh;maxline=diaf2; ektos=yt+(diaf2*bh);
maxline=1;ektos=yt+bh;

// ELEGSOS GIA CAPS LOCK PATHMENO XVRIS MPERDEMA ME ALLA PLHKTRA //
SDL_FlushEvent (SDL_KEYDOWN);
state = SDL_GetKeyboardState(NULL);
ch_mod=SDL_GetModState();
caps_lock = ( (ch_mod==8192) || (ch_mod==12288) ) ? 1 : 0 ;

col_cu = 5099; 
time_metr=0;
diak=0;
pos[0][0]=xl ; pos[0][1]=yt;
for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
x1=x ; y1=y;
//ELEGXOS TOY ALFARIUMHTIKOY str kai parousiash tou keimenou //

            // ELEGXOS !! 
    what=str[0];
    if (what !=255) {
        f=0; diaf2=0;
        while ( (what!=255) && (orio-f) ) {
        if (what==200) {str[f]=0; f++;what=str[f];continue;}
        if ( (what>=0) && (what<164) ) {f++;what=str[f];continue;}
        else {str[f]=0; f++;what=str[f];continue;}
            } 
        str[f]=255; diaf1=f;
        ar=diaf1;cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;
                     
       // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ       
        x1=xl ; y1=yt;
        
        for (a=0; a<ar; a++) {
        what=str[a];
        pos[a][0]=x1 ; pos[a][1]=y1 ;
        x1+=gouv[what].wid;
        if (x1 > xr-2) {ar=a+1 ; x1=xr-2 ; break ; }

        }
            str[ar]=255 ;
            pos[ar][0]=x1 ; pos[ar][1]=y1;
            // for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}  (έχει ήδη γίνει αυτό)
            // ΝΕΑ ΕΜΦΑΝΙΣΗ
            
        x1=xl; y1=yt;
       
        for (a=0; a<ar; a++) {
        what=str[a];         

        x1=pos[a][0]; y1=pos[a][1];
        if (y1>=ektos) break ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) continue;

        // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
        setcolor(COLOR (red,green,blue));
        _putpixel(x1+i , y1+f);}}
        }
        refresh();
        x=pos[cur][0] ; y=pos[cur][1];

    } 

Enarjh :

for(;;) {

    time_metr++;
if (time_metr>150000) {
    time_metr=0;
    if (!diak) {
    getimage(x,y,x+1,y+bh-1,mem_cu);   
    diak=1;
    setrgbcolor(col_cu); 
    for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
    _putpixel(x+i,y+f) ;} }
    refresh() ; 
    }
    else {putimage(x,y,mem_cu,0); refresh() ; diak=0;}}
    
if (!SDL_PollEvent(&sdlev)) continue;
    
    switch (sdlev.type) {
    
    case SDL_MOUSEMOTION:
    //while (SDL_PollEvent(&sdlev) && sdlev.type ==SDL_MOUSEMOTION) continue;
    mx=sdlev.motion.x ; my=sdlev.motion.y;
    SDL_FlushEvent(SDL_MOUSEMOTION);
    if (mx>xl && mx<xr && my>yt && my<yb) {
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
   SDL_SetCursor(cursor);continue;}
   
   if ( mx>xr || mx<xl || my>yb || my<yt ) goto DROMO;
   
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
   SDL_SetCursor(cursor);
    continue;
    
    case SDL_MOUSEWHEEL :
            
        continue ;
        
    case SDL_MOUSEBUTTONDOWN:
    if(sdlev.button.button==SDL_BUTTON_LEFT) {   
        auto int pev ;
        mx = sdlev.button.x ; my= sdlev.button.y ;
        klik= sdlev.button.clicks; 
        // Μέσα στο Κείμενο κλίκ....
        if ( mx>xr || mx<xl || my>yb || my<yt ) goto DROMO;
        if (vam[0]) {                              //σβηνω κερσορα - ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb)) ;  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            x1= pos[a][0] ; what=str[a];
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}            
            refresh();
            vam[0]=0;
            }
        if (!ar) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1]; 
        diaf1=2*xr;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
       curst= --f;
       chb=0;
       if (curst>=ar) {chb=1; curst=ar-1;}
       
        if (klik>1) {
           
            f=curst=0;
            vam[1]=0;
            what=str[f];
            while (what<200) {what=str[++f];}
            vam[2] = f ;
            if (vam[1]==vam[2]) continue ;
            if (!f) continue ;
            vam[2] = (f==ar) ? f-1 : f ;
            vam[0]=1;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (epr,epg,epb)); 
            for (a=vam[1]; a<=vam[2]; a++) {
            y1=pos[a][1] ;
            if (y1<yt) continue ;
            if (y1>=ektos) break ;
            what=str[a];
            x1=pos[a][0] ; 
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
            }
            refresh();  
            goto DIPLO_KLt ;

    }
       
        do {
        pev = SDL_PollEvent(&sdlev);
       mx = sdlev.button.x ; my= sdlev.button.y ;
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1];
        diaf1=2*xr;
        //if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
    curend= --f;
    if (curend>=ar) curend=ar-1;
      
    if(!vam[0]) {
        // ΒΑΦΩ ΑΡΧΙΚΑ //
        if (curst==curend) continue ;
        vam[0]=1;
        
        if (curend<curst) { vam[1]=curend ; vam[2]=curst ; pros=0; curst=vam[1]; curend=vam[2]; }
        else { pros=1 ; vam[1]=curst; vam[2]=curend ; }
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1= pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) { for(i=x1;i<xr-1;i++)  {_putpixel (i,f); }}refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
    
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f); } f++ ;}
        }
        refresh();continue ;}
        
        if (pros) {
        
        if (curend>vam[2]) {
       
       // Βάφω από vam[2] έως νέο curend //
             setcolor (COLOR (epr,epg,epb));  
       for (a=vam[2]+1; a<=curend; a++) {
       what=str[a];
       x1=pos[a][0] ; y1= pos[a][1] ;
      
       if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh(); continue ;}
       mem_int=gouv[what].where ;
       for(f=0; f<gouv[what].hei ; f++) {
       for(i=0;i<gouv[what].wid;i++) {
       co.lor = *mem_int++;
       if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
  
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
        }   
       vam[2]=curend; vam[0]=1;
       refresh();continue ;}
            
     if ((curend<vam[2]) && (curend>vam[1])) {
           //ξεβάφω MONON.. //
          setcolor (COLOR (bkr,bkg,bkb));  
        for (a=curend; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
       
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
         
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[2]=curend;
        vam[0]=1;
        refresh();continue ;
    }       
    
    if (curend<=vam[1]) {
        
    // Ξεβάφω από vam[1] έως vam[2] //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }       
        
        if (curend==vam[1])  {vam[0]=0 ; curst=curend ; refresh(); continue ;}
        vam[2] = curst ; vam[1]=curend ; pros=0; vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        curst=vam[1] ; curend=vam[2];
        continue ;}}
        else {
        // Από εδώ και πέρα σημαίνει pros=0 //
        
        if (curend<curst) {
            // Βάφω από curend έως vam1 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=curend; a<=vam[1]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
       
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        vam[1]=curend; curst=vam[1];vam[0]=1;continue;}
        
        if ( (curend>vam[1]) && (curend<vam[2]) ) {
        //ξεβάφω MONON.. //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<curend; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }            
        refresh(); vam[1]=curend ; curst=vam[1]; continue; }
        
        if (curend >= vam[2]) {
        // Ξεβάφω από vam1 έως vam2 //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }
        
        if (curend==vam[2]) {curst=curend ; vam[0]=0 ; continue ; }
        
        vam[1]=vam[2]; vam[2]=curend; curst=vam[1]; pros=1;vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
      
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();continue;}}       
        
    }  while (!pev || sdlev.type!=SDL_MOUSEBUTTONUP) ; 

DIPLO_KLt :
    cur=curst;
    if ( (!vam[0]) && (cur==ar-1) && (chb) ) cur=ar ;
    x=pos[cur][0] ; y=pos[cur][1];
    continue;}
    
    // Right Click Menu !!                            Right Click Menu !!    

             
    case SDL_KEYDOWN:
        ch_scan=sdlev.key.keysym.scancode;
        ch_mod=SDL_GetModState();
        if (keyb_gr) {
        state=SDL_GetKeyboardState(NULL);
        if ((state[SDL_SCANCODE_RALT] || state[SDL_SCANCODE_LALT]) && (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])) { us_flag=abs (us_flag-1) ; gr_flag=abs(gr_flag-1) ; ton=0; dial=0; 
        if (us_flag) {ton=0;dial=0;}
        continue ;}
        }
        
        switch (ch_scan) { // Φεύγοντας από την switch με break πάμε για εκτύπωση !!
            
            case SDL_SCANCODE_ESCAPE :  
                goto DROMO ;
                                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;
                    }
                str[ar]=255; putimage(xl,yt,mem1,0);  free(mem1) ; free(mem_cu);                              
                  cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                  langex = (us_flag) ? 1 : 2 ;
                SDL_SetCursor(cursor);refresh() ; return 0;
            
            case SDL_SCANCODE_SEMICOLON : //Τόνος για Ελληνικά

                if (!gr_flag) break ;
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME TONO - Περίπτωση διαλυτικών //
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        dial=1 ; continue ;
                    default : ton = 1; continue;}
                    
                    case SDL_SCANCODE_BACKSPACE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
esot_anadiat:  
                // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ 
                
                x1=xl ; y1=yt;
                
                for (a=0; a<ar; a++) {
                what=str[a];
                pos[a][0]=x1 ; pos[a][1]=y1 ;
                x1+=gouv[what].wid;
                if ( x1 > xr-2) { x1=xr-2; ar=a ; break; }
                }
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                     
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                    
                if (what==200) continue ;
                x1=pos[a][0]; y1=pos[a][1];
                if (y1>=ektos) break ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                }
                x=pos[cur][0] ; y=pos[cur][1];
                 refresh();
                pre_cur=0;pre_paste=0;
                continue ;
                }                
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
               
                if (cur==ar) {
                    what=str[ar-1];
                    x1=pos[ar-1][0] ; y1=pos[ar-1][1] ;
                    pos[ar][0]=pos[ar][1]=-1;
                    if (what!=200) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x1;i<=x1+gouv[what].wid;i++) { for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}
                    }
                    refresh();
                    x=x1; y=y1;
                    ar--; cur--; str[ar]=255;
                    }
                    
                else {
                         
                        x1=pos[cur-1][0]; y1=pos[cur-1][1]; 
                        cur--;
                        for(f=cur;f<ar;f++) str[f]=str[f+1];
                        ar--;
                       
entos_back :
                         // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if ( (y1+bh) >=yt) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                
                secr=(cur) ? 1 : 0 ;                
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];   
                if ( (y1<yt) && (secr) ) {
                    f=0; while (pos[f][1]!=y1) f++;
                    secr=cur-f;
                    //while (pos[cur-secr][1] != xl) secr++;
                    diaf1=abs(pos[cur-secr][1] - yt);
                    pos [cur-secr][1]=yt;
                    x1=xl ; y1=yt;
                    for (f=0 ; f<cur-secr ; f++) pos[f][1]+=diaf1;
                }
                        
                for (a=cur-secr; a<ar; a++) {
                    
                    what=str[a];
                    
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }

                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if ( (y1>=ektos) || (y1<yt) ) { x1+=gouv[what].wid; wrap--; continue ; }
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 x=pos[cur][0] ; y=pos[cur][1];
                 if (y<yt) { 
                     while (y<yt) {cur++; y = pos[cur][1] ; }
                     x=pos[cur][0] ; 
                }
                
                }
                continue ;
  
                
                    case SDL_SCANCODE_CAPSLOCK :
                        caps_lock = abs (caps_lock-1) ; 
                    continue ;
                
                    case SDL_SCANCODE_DELETE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
                goto esot_anadiat;}
                
                                           
                 if (cur==ar) continue ;
                 x1=pos[cur][0] ; y1 = pos[cur][1];
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for(f=cur;f<ar;f++) str[f]=str[f+1];
                 ar--;
                                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                what=str[a];
                
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh; continue ;}
                wrap=0;                
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if (y1>=ektos) {x1+=gouv[what].wid;wrap--; continue;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;   
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 if (x1>xr-2) x1=xr-2 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 continue ; 
  
                
                    case SDL_SCANCODE_END :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f<=ar ; f++) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1];
                 continue ;
                
                
                    case SDL_SCANCODE_HOME :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));   
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                 
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f>0 ; f--) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = ++f ; if ( (cur==1) && (pos[0][1]==y) ) cur=0;
                 x=pos[cur][0] ; y=pos[cur][1];    
                   continue ;
                
                    case SDL_SCANCODE_HELP :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                   continue ;
                   
                    case SDL_SCANCODE_TAB :
                        tab=1;
                        goto DROMO ;
                
                    case SDL_SCANCODE_INSERT :
                if (keyb_gr) {ton=0 ; dial=0 ;}       
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                  
                  col_cu = (col_cu==5099) ? 5100 : 5099 ;
                  ins=abs(ins-1);
 
                          refresh();
                   continue ;
                  
                    case SDL_SCANCODE_LEFT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                          //ΣΒΗΝΩ CURSOR
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                cur-- ; y=pos[cur][1];
                x=pos[cur][0]; 
                continue ;
                
                    case SDL_SCANCODE_RIGHT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                                  
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 cur++ ;
                 y=pos[cur][1];
                x=pos[cur][0]; 
                   continue ;
                        

                    case SDL_SCANCODE_V :  //PASTE
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME V 
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                        {                        
      
 // ΑΝΤΙΓΡΑΦΩ ΟΣΑ ΕΠΙΤΡΕΠΕΤΑΙ ΑΠΟ ΤΟ SYSTEM CLIPBOARD αναλόγως του insert //
        if (!SDL_HasClipboardText()) continue;
        clipbo=SDL_GetClipboardText();
        if (clipbo==NULL) continue;
        if ( (orio==ar) && (!vam[0]) ) {SDL_free(clipbo); continue ;}
        
        if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
       y1= pos[a][1] ;
        if (y1>=ektos || y1<yt) continue ;
         what=str[a];
        x1= pos[a][0] ; 
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[0]=0;
        // Εσωτερική Αναδιάταξη !
        cur = vam[1] ;
        for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
        diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
        
        }
        if(!ins) elxor=orio-ar; else elxor=orio-cur;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        if (!ins) {
            
            for(f=ar,i=0; (f>=cur) ; f--,i++) str[orio-i]=str[f];
            diaf1=orio-i+1;}
            // Προσδιορισμός του Pre_Paste
            
        if (!pre_cur) {
        f=cur;
        if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                } else pre_paste=0;} 
                   else pre_paste=0;

        f=0 ; a=0 ;
        ch=clipbo[f];
        while ( (ch!='\0') && (elxor) ) {
            if (ch<0) {
                
                f++ ; ch1= ( (256*ch) + clipbo[f] ) ;
                for (i=0 ; i<69 ; i++) {
                    if (ch1==unico[i][0]) {
                        str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                        if (i==69) {str[cur+a]=0 ; a++ ; elxor--; f--; }
                f++; ch=clipbo[f];continue;
             }
            else {
                if (ch=='\n') {f++; ch=clipbo[f]; continue;}
                for(i=0;i<95;i++) {
                    if (ch==gouv[i].who) {
                        str[cur+a]=i ; a++ ; elxor-- ;break;}}
                        if (i==95) {str[cur+a]=0 ; a++ ; elxor--;}
                f++;ch=clipbo[f];
                  }
        }
         if (!ins) ar +=a ; else {
             if (cur+a > ar) ar=(cur+a); }
         if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
         SDL_free(clipbo);
        goto esot_anadiat;}                        
                 
                   }
        break;
                  
                        case SDL_SCANCODE_C :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME C (* Copy) //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                                if (!vam[0]) continue;
                                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                                size=0;
                                for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) size++;
                                    else if ( (what>94) && (what<164) ) size+=2;
                                    else size++; }
                                    size++;
                                    clipbo=malloc(size);
                                    if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                                    a=0;
                                    for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) {
                                        clipbo[a]=gouv[what].who; a++;}
                                    else if ( (what>94) && (what<164) ) {
                                        cha=((unico[what-95][0]/256)-255);
                                        chb = (unico[what-95][0] % 256);
                                        clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                                    else if (what==200) {clipbo[a]='\n' ; a++;}}
                                    clipbo[a]='\0';
                                    size=SDL_SetClipboardText(clipbo);
                                    if (!size) {
                                       
                                        setcolor (COLOR (epr1,epg1,epb1));  
                                        for (a=vam[1]; a<=vam[2]; a++) {
                                        y1=pos[a][1] ;
                                        if (y1<yt || y1>=ektos) continue;
                                        what=str[a];
                                        x1=pos[a][0] ; 
                                        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
                                        mem_int=gouv[what].where ;
                                        for(f=0; f<gouv[what].hei ; f++) {
                                        for(i=0;i<gouv[what].wid;i++) {
                                        co.lor = *mem_int++;
                                        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                                        refresh();
                                    } 
                                    free(clipbo);
                                    continue;  }
                    break ;
                    
                    case SDL_SCANCODE_RCTRL :
                    case SDL_SCANCODE_LCTRL :
                        continue;
                    
DROMO :
                    case SDL_SCANCODE_RETURN :
                    case 88 :

                    if(diak) {putimage(x,y,mem_cu,0); refresh() ;}
                    
                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();}
                    
                    free(mem1) ; free(mem_cu);         
                    str[ar]=255;
                    langex = (us_flag) ? 1 : 2 ;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh(); diaf1=ar; ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;  if (!tab) return diaf1; else return -9 ;
                                 
                }
                        
                    
            //ΕΛΕΓΧΟΣ ΠΡΙΝ ΤΗΝ ΕΚΤΥΠΩΣΗ ΕΝΟΣ ΧΑΡΑΚΤΗΡΑ //
            if (vam[0]) {                              // ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb));   
            for (a=vam[1]; a<=vam[2]; a++) {
             y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            what=str[a];
            x1= pos[a][0] ;
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
            }
            refresh();
            vam[0]=0;
            }
                
            if (ch_scan<57) {
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME CHAR
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        shift=1 ; break ;
                    default : shift = 0; }
                  
                  // To caps_lock αντιστρέφει το shift για τα Α έως Ζ //
                    if (ch_scan>3 && ch_scan<30) {
                        if (caps_lock) shift = abs (shift-1) ;}
            what = (gr_flag) ? grek.sort[ch_scan][shift] : engl.sort[ch_scan][shift] ;
            if (!gr_flag) goto typechar ;
            if (dial) {
                switch (gouv[what].who) {
                    case 'i' :
                    case 'y' :
                    case 'I' :
                    case 'Y' :
                        met+=2 ; dial=0 ; break ;
                    default : dial=0 ; met=0 ;}}
                    
            if (ton) {
                switch (gouv[what].who) { 
                    case 'I' :
                    case 'Y' :    
                    met=1 ; ton=0 ; break ;
                case 'a' :
                case 'e' :               
                case 'h' :                  
                case 'i' :                    
                case 'o' :                    
                case 'y' :                   
                case 'v' :                   
                case 'A' :
                case 'E' :
                case 'H' :
               case 'O':
               case 'V' :
                   met+=1 ; ton =0 ; break ;
                default : met=0 ; ton=0;}}
                
            what += met ; met=0 ;
            

            typechar:
            if ( (x+gouv[what].wid) > xr-2) continue ;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            
            if (cur==ar) {
            if ( orio==ar ) continue ;
            str[ar]=what ; ar++; cur++; str[ar]=255 ;
            wrap=0;                
            
            do {
            pos[(cur-1-wrap)][0]=x ; pos[(cur-1-wrap)][1]=y ;
            what=str[cur-1-wrap];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x+i , y+f);}}
            refresh();
            x=x+gouv[what].wid;
            wrap--;
            }while (wrap>=0);
            pos[cur][0]=x; pos[cur][1]=y;
            refresh();
                     }
            
            else {                               // cur != ar
             
               if (!ins) {
                    if ( orio==ar ) continue ;
                    ar++;
                    for(f=ar; f>cur; f--) str[f]=str[f-1];
                   str[cur]=what ;
                   if ( (what) && (ar<orio) && (cur) ) {
                           if (str[cur+1] && (!str[cur-1])) {
                               ar++;
                               for(f=ar; f>cur+1; f--) str[f]=str[f-1];
                               str[cur+1]=0;
                           }
                       }
            }
                    
                str[cur]=what;
                f=0;i=0;
                while (pos[cur-f][0]!=xl) f++;
                if ((cur-f)) {
                i = f+1;
                while ( pos[cur-i][0] !=xl ) {
                    if (str[cur-i]!=200) i++;
                    else {i=0;break;} }}
                secr = (i) ? i : f ;
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];
                
                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur-secr; a<ar; a++) {
                    what=str[a];
                        
                    wrap=0;            
                    if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }
                        
                    do { 
                    pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;     
                    what=str[a-wrap];
                    if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                    
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;
                    wrap--;
                    }while (wrap>=0);
                }
                
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) {cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else {x=x1; y=y1;}
                    
                }
                continue ;

              }
              continue;
       

    case SDL_WINDOWEVENT :
    refresh(); continue;

    default:
    continue;
    
   }

} 

}

int qnum_input(char *str, int xl,int yt,int xr,int yb,int orio,int num_type)
{
//extern short int keyb_gr ;
//extern short int keyb_us ;
SDL_Cursor* cursor;
register int i ,f ;
int mx , my , x , y , shift , size , size_cu, x1, y1 , x2, y2, col_cu, bkr, bkg, bkb, epr, epg, epb ,elax, diafy , epr1,epg1,epb1;
unsigned int time_metr ,ektos ;
unsigned char what ,secr ;
unsigned short int us_flag=1, ch_mod,ch_scan,curst , curend , elxor , ch1 ,ypo , mowid;
unsigned short int pre_paste=0, diak ,diaf1, diaf2,maxline, a, port=0 ;
const Uint8 *state ;
void *mem1 , *mem_cu , *mem_power;
int *mem_int ;
char *clipbo;
int pos[orio+1][2] ;
short int pros ,wrap ;
char ch,cha,chb;
short int start=0;
short int bh , tab=0;
int red,green,blue;
int main_cur[3] , ins_cur[3];

union whatcols{
unsigned int lor ;
unsigned char rgb[4];
} co ;

unsigned short int wherp=0 , pre_cur=0, cur=0, ar=0, ins=0 ;
unsigned short int vam[3];
static unsigned int warn ;
static int xl1,yt1,xr1,yb1;
unsigned char klik ;
float neg, alfa ;

elax=mowid=gouv[16].wid;
bh=gouv[16].hei;
for (f=17;f<26;f++) {
    if (bh<gouv[f].hei) bh=gouv[f].hei;
    mowid+=gouv[f].wid;
    if (elax > gouv[f].wid) continue ; else elax=gouv[f].wid;}
if ((yb-yt+1)<bh) return (-1) ; // Κωδικός που δείχνει ότι το ύψος του πλαισίου δεν κάνει... !!
mowid /= 10 ; 
if (xl1!=xl || yt1!=yt || xr1!=xr || yb1!=yb) {
    warn=0;
    xl1=xl ; yt1=yt; xr1=xr; yb1=yb;
}
if ( ((orio*mowid*9/10) > (xr-xl+1)) && (!warn) ) {warn=1; information (30-keyb_gr,0,0);}
vam[0]=0;
bkr=bkxr[0] ; bkg=bkxr[1] ;bkb=bkxr[2];  // ΕΔΩ καθορίζεται το backround color !!!
epr =slxr[0] ; epg=slxr[1] ;  epb=slxr[2] ; // ΕΔΩ παίρνει τις τιμές χρώματος όταν επιλέγεται κείμενο !!
main_cur[0] = 255-((epr+bkr)/2) ; main_cur[1] = 255-((epg+bkg)/2) ; main_cur[2] = 255-((epb+bkb)/2) ; // Κύριο χρώμα του κέρσορα !  
setrgbpalette(4099,main_cur[0],main_cur[1],main_cur[2]); // To 4099 κύριο χρώμα του κέρσορα
ins_cur[0] = 255-((epr+chxr[0])/2) ; ins_cur[1] = 255-((epr+chxr[1])/2) ; ins_cur[2] = 255-((epr+chxr[2])/2) ; // To "Insert" χρώμα του κέρσορα !
setrgbpalette(4100,ins_cur[0],ins_cur[1],ins_cur[2]); // To 4100 = insert χρώμα του κέρσορα
epr1 = epr + 70; if (epr1>255) epr1=255;
epg1 = epg + 50; if (epg1>255) epg1=255;
epb1 = epb + 40; if (epb1>255) epb1=255;

// dh=(2*bh)-1;
if (orio<=0) return 0;

// *pxl=xl; *pyt=yt; *pxr=xr ; *pyb = yb;
elax=(xr-xl)/elax ; // ELAXISTH XVRHTIKOTHTA GRAMMHS ANALOGA TO MEGISTO PLATOS

size=imagesize(xl,yt,xr,yb);
mem1=malloc(size);
if (mem1==NULL) {printf ("Out of Memory \n"); return 0 ; }
size_cu=imagesize(0,0,1,(bh-1));
mem_cu=malloc(size_cu);
if (mem_cu==NULL) {printf ("Out of Memory \n"); free(mem1); return 0 ; }
getimage(xl,yt,xr,yb,mem1);
x=xl ; y=yt;
//diaf1=yb-yt+1; diaf2=diaf1/bh;maxline=diaf2; ektos=yt+(diaf2*bh);
maxline=1;ektos=yt+bh;
col_cu = 4099; //green=15; // blue=20;
time_metr=0;
diak=0;
pos[0][0]=xl ; pos[0][1]=yt;
for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
x1=x ; y1=y;
//ELEGXOS TOY ALFARIUMHTIKOY str kai parousiash tou keimenou //

            // ELEGXOS !!
    ypo=0;
    what=str[0];
    if (what !=255) {
        f=0; diaf2=0;
        while ( (what!=255) && (orio-f) ) {
            switch (num_type) {
                case 0:
                case 1: //Θετικός ακέραιος
                    if ( (what>15) && (what<26) ) {f++;what=str[f];continue;}
                    diaf2=1;break;

                case 2: //Αρνητικός ή θετικός ακέραιος
                    if ( (what==13) && (!f) ) {f++;what=str[f];continue;}
                    if ( (what>15) && (what<26) ) {f++;what=str[f];continue;}
                    diaf2=1;break;

                case 3 : // Float
                    if ( (what==13) && (!f) ) {f++;what=str[f];continue;}
                    if ( (what>15) && (what<26) ) {f++;what=str[f];continue;}
                    if ( (what==12) && (f) && (!ypo) ) {
                        if (str[f-1]!=13){
                        ypo=1; f++;what=str[f];continue;}}
                    diaf2=1;break;
                    
            }
            break ;
        } 
        
        str[f]=255; diaf1=f;
        ar=diaf1;
                     
       // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ       
        x1=xl ; y1=yt;
        for (a=0; a<ar; a++) {
        what=str[a];
        if (what==200) str[a]=16;
        wrap=0 ;  
        if ((x1+gouv[what].wid) > xr-2) { ar=a ; break ; }
        pos[a][0]=x1 ; pos[a][1]=y1 ;
        what=str[a];
        x1+=gouv[what].wid;
        }
            str[ar]=255 ;
            pos[ar][0]=x1 ; pos[ar][1]=y1;
            // for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
            // ΝΕΑ ΕΜΦΑΝΙΣΗ
                        
           
        x1=xl; y1=yt;
       
        for (a=wherp; a<ar; a++) {
        what=str[a];
 
        x1=pos[a][0]; y1=pos[a][1];
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) continue;

        // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
        setcolor(COLOR (red,green,blue));
        _putpixel(x1+i , y1+f);}}
        }
        refresh();
        x=pos[cur][0] ; y=pos[cur][1];
    } 

Enarjh :

for(;;) {

    time_metr++;
if (time_metr>150000) {
    time_metr=0;
    if (!diak) {
    getimage(x,y,x+1,y+bh-1,mem_cu);   
    diak=1;
    setrgbcolor(col_cu); 
    for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
    _putpixel(x+i,y+f) ;} }
    refresh() ; 
    }
    else {putimage(x,y,mem_cu,0); refresh() ; diak=0;}}
    
if (!SDL_PollEvent(&sdlev)) continue;
    
    switch (sdlev.type) {
    
    case SDL_MOUSEMOTION:
    //while (SDL_PollEvent(&sdlev) && sdlev.type ==SDL_MOUSEMOTION) continue;
    mx=sdlev.motion.x ; my=sdlev.motion.y;
    SDL_FlushEvent(SDL_MOUSEMOTION);
    
    if (mx>xl && mx<xr && my>yt && my<yb) {
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
   SDL_SetCursor(cursor);continue;}
   
   if ( mx>xr || mx<xl || my>yb || my<yt ) goto DROMO;
   
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
   SDL_SetCursor(cursor);
    continue;
    
        
    case SDL_MOUSEBUTTONDOWN:
    if(sdlev.button.button==SDL_BUTTON_LEFT) {   
        auto int pev ;
        mx = sdlev.button.x ; my= sdlev.button.y ;
        klik= sdlev.button.clicks; 
                
        
        // Μέσα στο Κείμενο κλίκ....
        if ( mx>xr || mx<xl || my>yb || my<yt ) goto DROMO;
        if (vam[0]) {                              //σβηνω κερσορα - ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb)) ;  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            x1= pos[a][0] ; what=str[a];
           
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}            
            refresh();
            vam[0]=0;
            }
        if (!ar) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1]; 
        diaf1=2*xr;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
       curst= --f;
       chb=0;
       if (curst>=ar) {chb=1; curst=ar-1;}
       
               if (klik>1) {
           
            f=curst=0;
            vam[1]=0;
            what=str[f];
            while (what<200) {what=str[++f];}
            vam[2] = f ;
            if (vam[1]==vam[2]) continue ;
            if (!f) continue ;
            vam[2] = (f==ar) ? f-1 : f ;
            vam[0]=1;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (epr,epg,epb)); 
            for (a=vam[1]; a<=vam[2]; a++) {
            y1=pos[a][1] ;
            if (y1<yt) continue ;
            if (y1>=ektos) break ;
            what=str[a];
            x1=pos[a][0] ; 
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
            }
            refresh();  
            goto DIPLO_KLn ;

    }
    
        do {
        pev = SDL_PollEvent(&sdlev);
       mx = sdlev.button.x ; my= sdlev.button.y ;
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1];
        diaf1=2*xr;
        //if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
    curend= --f;
    if (curend>=ar) curend=ar-1;
      
    if(!vam[0]) {
        // ΒΑΦΩ ΑΡΧΙΚΑ //
        if (curst==curend) continue ;
        vam[0]=1;
        
        if (curend<curst) { vam[1]=curend ; vam[2]=curst ; pros=0; curst=vam[1]; curend=vam[2]; }
        else { pros=1 ; vam[1]=curst; vam[2]=curend ; }
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1= pos[a][1] ;
        
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
    
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f); } f++ ;}
        }
        refresh();continue ;}
        
        if (pros) {
        
        if (curend>vam[2]) {
       
       // Βάφω από vam[2] έως νέο curend //
             setcolor (COLOR (epr,epg,epb));  
       for (a=vam[2]+1; a<=curend; a++) {
       what=str[a];
       x1=pos[a][0] ; y1= pos[a][1] ;
      
       mem_int=gouv[what].where ;
       for(f=0; f<gouv[what].hei ; f++) {
       for(i=0;i<gouv[what].wid;i++) {
       co.lor = *mem_int++;
       if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
  
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
        }   
       vam[2]=curend; vam[0]=1;
       refresh();continue ;}
            
     if ((curend<vam[2]) && (curend>vam[1])) {
           //ξεβάφω MONON.. //
          setcolor (COLOR (bkr,bkg,bkb));  
        for (a=curend; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
       
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
         
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[2]=curend;
        vam[0]=1;
        refresh();continue ;
    }       
    
    if (curend<=vam[1]) {
        
    // Ξεβάφω από vam[1] έως vam[2] //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }       
        
        if (curend==vam[1])  {vam[0]=0 ; curst=curend ; refresh(); continue ;}
        vam[2] = curst ; vam[1]=curend ; pros=0; vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        curst=vam[1] ; curend=vam[2];
        continue ;}}
        else {
        // Από εδώ και πέρα σημαίνει pros=0 //
        
        if (curend<curst) {
            // Βάφω από curend έως vam1 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=curend; a<=vam[1]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
       
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        vam[1]=curend; curst=vam[1];vam[0]=1;continue;}
        
        if ( (curend>vam[1]) && (curend<vam[2]) ) {
        //ξεβάφω MONON.. //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<curend; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }            
        refresh(); vam[1]=curend ; curst=vam[1]; continue; }
        
        if (curend >= vam[2]) {
        // Ξεβάφω από vam1 έως vam2 //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }
        
        if (curend==vam[2]) {curst=curend ; vam[0]=0 ; continue ; }
        
        vam[1]=vam[2]; vam[2]=curend; curst=vam[1]; pros=1;vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
      
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();continue;}}       
        
    }  while (!pev || sdlev.type!=SDL_MOUSEBUTTONUP) ; 
DIPLO_KLn :
    cur=curst;
    if ( (!vam[0]) && (cur==ar-1) && (chb) ) cur=ar ;
    x=pos[cur][0] ; y=pos[cur][1];
    continue;}
    
    // Right Click Menu !!                            Right Click Menu !!    
    
                                                                                    
              continue ;
             
    case SDL_KEYDOWN:
        ch_scan=sdlev.key.keysym.scancode;
        ch_mod=SDL_GetModState();
     
        switch (ch_scan) { // Φεύγοντας από την switch με break πάμε για εκτύπωση !!
            
            case SDL_SCANCODE_ESCAPE :
                goto DROMO;
                                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;
                    }
                str[ar]=255; putimage(xl,yt,mem1,0);  free(mem1) ; free(mem_cu);                              
                  cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                SDL_SetCursor(cursor);refresh() ; ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;return 0;
            
                               
                    case SDL_SCANCODE_BACKSPACE :
                 
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                what=str[a]; if(what==12) ypo=0; 
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                printf("vam1: %u , vam2 : %u, ar = %u \n",vam[1], vam[2], ar);
                cur = vam[1] ;
esot_anadiat:  
                // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ NUM IMPUT
                if (str[0] == 12) {
                    for (a=ar-1;a>0;a--) {str[a]=str[a-1];}
                    str[0]=16;
                }
                x1=xl ; y1=yt;
                
                for (a=0; a<ar; a++) {
                what=str[a];
                pos[a][0]=x1 ; pos[a][1]=y1 ;
                x1+=gouv[what].wid;
                if ( x1 > xr-2) { x1=xr-2;
                    for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    }
                    ar=a ; break; }

                }
                
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                    
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                    
               
                x1=pos[a][0]; y1=pos[a][1];
                if (y1>=ektos) break ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                }
                x=pos[cur][0] ; y=pos[cur][1];
                 refresh();
                pre_cur=0;pre_paste=0;
                continue;
                }                
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
               
                if (cur==ar) {
                    what=str[ar-1];
                    if(what==12) ypo=0; 
                    x1=pos[ar-1][0] ; y1=pos[ar-1][1] ;
                    pos[ar][0]=pos[ar][1]=-1;
                    if (what!=200) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x1;i<=x1+gouv[what].wid;i++) { for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}
                    }
                    refresh();
                    x=x1; y=y1;
                    ar--; cur--; str[ar]=255;
                    }
                    
                else {
                        // if ( (str[cur]==12) && !(cur-1) ) continue;
                        if(str[cur-1]==12) ypo=0; 
                        x1=pos[cur-1][0]; y1=pos[cur-1][1]; 
                        cur--;
                        for(f=cur;f<ar;f++) str[f]=str[f+1];
                        ar--;
                       
entos_back :
                         // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if ( (y1+bh) >=yt) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                
                secr=(cur) ? 1 : 0 ;                
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];   
                if ( (y1<yt) && (secr) ) {
                    f=0; while (pos[f][1]!=y1) f++;
                    secr=cur-f;
                    //while (pos[cur-secr][1] != xl) secr++;
                    diaf1=abs(pos[cur-secr][1] - yt);
                    pos [cur-secr][1]=yt;
                    x1=xl ; y1=yt;
                    for (f=0 ; f<cur-secr ; f++) pos[f][1]+=diaf1;
                }
                        
                for (a=cur-secr; a<ar; a++) {
                    
                    what=str[a];
                    
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    } break; }

                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if ( (y1>=ektos) || (y1<yt) ) { x1+=gouv[what].wid; wrap--; continue ; }
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 x=pos[cur][0] ; y=pos[cur][1];
                 if (y<yt) { 
                     while (y<yt) {cur++; y = pos[cur][1] ; }
                     x=pos[cur][0] ; 
                }
                
                }
                continue;
  
                
                                  
                    case SDL_SCANCODE_DELETE :
                 
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; if(what==12) ypo=0;  
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                cur = vam[1] ;
                goto esot_anadiat;}
                
                                           
                 if (cur==ar) continue ;
                 if(str[cur]==12) ypo=0; 
                 // if ( (str[cur+1]==12) && (!cur) ) continue;
                 x1=pos[cur][0] ; y1 = pos[cur][1];
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for(f=cur;f<ar;f++) str[f]=str[f+1];
                 ar--;
                                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                what=str[a];
                
                wrap=0;                
                if ((x1+gouv[what].wid) > xr-2) { ar=a ; for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    } break ; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if (y1>=ektos) {x1+=gouv[what].wid;wrap--; continue;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;   
                    } while (wrap>=0);
                }
                 refresh();
                 if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 continue; 
  
                
                    case SDL_SCANCODE_END :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f<=ar ; f++) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1];
                 continue ;
              
                    case SDL_SCANCODE_TAB :
                        tab=1;
                        goto DROMO ;
                 
                
                    case SDL_SCANCODE_HOME :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));   
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                 
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f>0 ; f--) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = ++f ; if ( (cur==1) && (pos[0][1]==y) ) cur=0;
                 x=pos[cur][0] ; y=pos[cur][1];    
                   continue ;
                
                                 
                    case SDL_SCANCODE_INSERT :
                        
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                  
                  col_cu = (col_cu==4099) ? 4100 : 4099 ;
                  ins=abs(ins-1);
                 
                   continue ;
                  
                    case SDL_SCANCODE_LEFT :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (!cur) continue ;
                          //ΣΒΗΝΩ CURSOR
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                cur-- ; y=pos[cur][1];
                x=pos[cur][0]; 
                continue;
                
                    case SDL_SCANCODE_RIGHT :
                  
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                                  
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;
                }                 
                 if (cur==ar) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 cur++ ;
                 y=pos[cur][1];
                x=pos[cur][0]; 

                 continue;                
                 
                 case SDL_SCANCODE_RCTRL :
                 case SDL_SCANCODE_LCTRL :
                 continue;

                    case SDL_SCANCODE_V :  //PASTE
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME V 
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                        {                        
      
 // ΑΝΤΙΓΡΑΦΩ ΟΣΑ ΕΠΙΤΡΕΠΕΤΑΙ ΑΠΟ ΤΟ SYSTEM CLIPBOARD αναλόγως του insert //
        if (!SDL_HasClipboardText()) continue;
        clipbo=SDL_GetClipboardText();
        if (clipbo==NULL) continue;
        if ( (orio==ar) && (!vam[0]) ) {SDL_free(clipbo); continue ;}
        
        
        if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
       y1= pos[a][1] ;
        if (y1>=ektos || y1<yt) continue ;
         what=str[a]; if(what==12) ypo=0; 
        x1= pos[a][0] ; 
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[0]=0;
        // Εσωτερική Αναδιάταξη !
        cur = vam[1] ;
        for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
        diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
        
        }
        if(!ins) elxor=orio-ar; else elxor=orio-cur;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        if (!ins) {
            
            for(f=ar,i=0; (f>=cur) ; f--,i++) str[orio-i]=str[f];
            diaf1=orio-i+1;}
    
f=0 ; a=0 ; 
ch=clipbo[f];
    while ( (ch!='\0') && (elxor) ) {
        if (ch<0) {f++;ch=clipbo[f]; continue;}
        else {
            if (ch=='\n') {f++;ch=clipbo[f]; continue;}
            for(i=0;i<95;i++) {if (ch!=gouv[i].who) continue ; else break ;}
            if (i==95) {f++; ch=clipbo[f];continue;}    
            switch (num_type) {
                case 0:
                case 1: //Θετικός ακέραιος
                    if ( (i>15) && (i<26) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    break;

                case 2: //Αρνητικός ή θετικός ακέραιος
                    if ( (i==13) && (!(cur+a)) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    if ( (i>15) && (i<26) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    break;
                    
                case 3 : // Float
                    if ( (i==13) && (!(cur+a)) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    if ( (i>15) && (i<26) ) {str[cur+a]=i ; a++ ; elxor-- ;break;}
                    if ( (i==12) && ((cur+a)) && (!ypo)) {
                        if (str[cur+a-1] != 13) {
                        ypo=1; str[cur+a]=i ; a++ ; elxor-- ;break;}}
            }
f++; ch=clipbo[f];
        }
    }
    
         if (!ins) ar +=a ; else {
             if (cur+a > ar) ar=(cur+a); }
         if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
         SDL_free(clipbo);
        goto esot_anadiat;}                        
                 
                   }
        break;
                  
                        case SDL_SCANCODE_C :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME C (* Copy) //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                                if (!vam[0]) continue;
                                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                                size=0;
                                for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) size++;
                                    else if ( (what>94) && (what<164) ) size+=2;
                                    else size++; }
                                    size++;
                                    clipbo=malloc(size);
                                    if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                                    a=0;
                                    for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) {
                                        clipbo[a]=gouv[what].who; a++;}
                                    else if ( (what>94) && (what<164) ) {
                                        cha=((unico[what-95][0]/256)-255);
                                        chb = (unico[what-95][0] % 256);
                                        clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                                    else if (what==200) {clipbo[a]='\n' ; a++;}}
                                    clipbo[a]='\0';
                                    size=SDL_SetClipboardText(clipbo);
                                    if (!size) {
                                       
                                        setcolor (COLOR (epr1,epg1,epb1));  
                                        for (a=vam[1]; a<=vam[2]; a++) {
                                        y1=pos[a][1] ;
                                        if (y1<yt || y1>=ektos) continue;
                                        what=str[a];
                                        x1=pos[a][0] ; 
                                        mem_int=gouv[what].where ;
                                        for(f=0; f<gouv[what].hei ; f++) {
                                        for(i=0;i<gouv[what].wid;i++) {
                                        co.lor = *mem_int++;
                                        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                                        refresh();
                                    } 
                                    free(clipbo);
                                    continue;  }
                    break ;
                    
                 
DROMO :
                    case SDL_SCANCODE_RETURN :
                    case 88 :
                 
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ;diak=0;}
                    
                    if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));   
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;
                    }
                    
              // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ ENDEXOMENVS
                if (str[0]==12) {
                for (a=ar-1;a>0;a--) {str[a]=str[a-1];}
                str[0]=16;
                
                x1=xl ; y1=yt;
                for (a=0; a<ar; a++) {
                what=str[a];
                
                wrap=0 ;  
                                

                pos[a][0]=x1 ; pos[a][1]=y1 ;
                what=str[a];
                 x1+=gouv[what].wid;
                 
                }
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                    
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                x1=pos[a][0]; y1=pos[a][1];
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                _putpixel(x1+i , y1+f);}}
                }
                 refresh();
                }
                    
                    free(mem1) ; free(mem_cu);         
                    str[ar]=255;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh(); diaf1=ar; ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; if (!tab) return diaf1; else return -9 ;
                    
                                 
                }
                        
                    
            //ΕΛΕΓΧΟΣ ΠΡΙΝ ΤΗΝ ΕΚΤΥΠΩΣΗ ΕΝΟΣ ΧΑΡΑΚΤΗΡΑ //
            if (vam[0]) {                              // ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb));   
            for (a=vam[1]; a<=vam[2]; a++) {
             y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            what=str[a];
            x1= pos[a][0] ;
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
            }
            refresh();
            vam[0]=0;
            }
            // if ( (num_type) && (ch_scan<30 || ch_scan>39) ) continue ;
                
            if (ch_scan<57) {
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME CHAR
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        shift=1 ; break ;
                    default : shift = 0; }
                  
            what = engl.sort[ch_scan][shift] ;
            
            a=0; 
            switch (num_type) {
                case 0:
                case 1: //Θετικός ακέραιος
                    if ( (what>15) && (what<26) ) {a=1 ; break;}
                    break;
                    
                case 2: //Αρνητικός ή θετικός ακέραιος
                    if ( (what==13) && (!cur) ) {a=1 ; break;}
                    if ( (what>15) && (what<26) ) {a=1 ; break;}
                   break;
                   
                case 3 : // Float
                    if ( (what==13) && (!cur) ) {a=1 ; break;}
                    if ( (what>15) && (what<26) ) {a=1 ; break;}
                    if ( (what==12) && (cur) && (!ypo) ) {
                        if (str[cur-1]!=13) {
                        ypo=1; a=1 ; break;}}
            }
            if (!a) continue ;
            if ( (x+gouv[what].wid) > xr-2) continue ;
            
            typechar:
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            
            if (cur==ar) {
            if ( orio==ar ) continue ;
   
            str[ar]=what ; ar++; cur++; str[ar]=255 ;
            wrap=0;
             
            do {
            pos[(cur-1-wrap)][0]=x ; pos[(cur-1-wrap)][1]=y ;
            what=str[cur-1-wrap];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x+i , y+f);}}
            refresh();
            x=x+gouv[what].wid;
            wrap--;
            }while (wrap>=0);
            pos[cur][0]=x; pos[cur][1]=y;
            refresh();
                     }
            
            else {                               // cur != ar
             
               if (!ins) {
                    if ( orio==ar ) continue ;
                    if ( (!cur) && (str[0]==13) ) continue ;
                    ar++;
                    for(f=ar; f>cur; f--) str[f]=str[f-1];
                   str[cur]=what ;
                   if ( (what) && (ar<orio) && (cur) ) {
                           if (str[cur+1] && (!str[cur-1])) {
                               ar++;
                               for(f=ar; f>cur+1; f--) str[f]=str[f-1];
                               str[cur+1]=0;
                           }
                       }
            }
                if ( (str[cur]==12) && (what!=12) ) ypo=0;    
                str[cur]=what;
                f=0;i=0;
                while (pos[cur-f][0]!=xl) f++;
                if ((cur-f)) {
                i = f+1;
                while ( pos[cur-i][0] !=xl ) {
                    if (str[cur-i]!=200) i++;
                    else {i=0;break;} }}
                secr = (i) ? i : f ;
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];
                
                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur-secr; a<ar; a++) {
                    what=str[a];
                        
                    if (what==200) {pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh;  continue ;}
                    wrap=0;            
                    if ((x1+gouv[what].wid) > xr-2) { ar=a ; for (f=a;f<ar;f++) {
                        if (str[f]==12) ypo=0;
                    } break ; }

                        
                    do { 
                    pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;     
                    what=str[a-wrap];
                    if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                    
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;
                    wrap--;
                    }while (wrap>=0);
                }
                
                 refresh();
                                  if (x1>xr-2) x1=xr-2 ;
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) {cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else {x=x1; y=y1;}
                                     
                }

                continue ;
              }
              continue;

    case SDL_WINDOWEVENT :
    refresh(); continue;

    default:
    continue;
   }
 } 
}


int input(unsigned char *str, int *pxl,int *pyt,int *pxr,int *pyb,int orio,short int arped, unsigned short int wherp1)
{
SDL_Cursor* cursor;
register int i ,f ;
int mx , my , x , y , shift , size , size_cu, x1, y1 , x2, y2, yep, col_cu, xep , xet , yet , bkr, bkg, bkb, epr, epg, epb ,elax, proyt , proyt1, olohei , metektos, metektos1 , x3 , y3 ,bary1, bary2, diafy , epr1,epg1,epb1,tab=0;
int xl,yt,xr,yb , user_ans ,orio1;
unsigned int time_metr ,ektos ;
unsigned char what ,secr ,file_flag,esc_go;
unsigned short int ch_mod,ch_scan,caps_lock,ton=0,dial=0,met=0, curst , curend , elxor , ch1 , bar=0 ,ano_ar , inp_info=0 , fnd_but=0;
unsigned short int blo_pre_cur=0, pre_paste=0, diak ,maxline, a, port=0 ,tent=0 ,marrs=0 , leks, meg_leks, ken_parag, parag ;
unsigned short int outmen , meg_par, par_leks, big_par, undo_max=5 , fonter=0 , linker = 0 ; 
int blosta, bloend ,diaf3 , diaf1, diaf2 ;
const Uint8 *state ;
void *mem1 , *mem_cu , *mem_under , *mem_flgr ,*mem_undscr, *mem_flusa , *mem_enter , *mem_power, *mem_bar , *mem_rmenu ;
void *mem_undrme, *mem_tent, *mem_arrs , *mem_find ,*mem_fonter ;
void *mem_efedr1 , *mem_efedr2 , *mem_info , *mem_link ;
int *mem_int ;
char *clipbo ;
char *clipbo1;
int pos[orio+1][2] ;
short int pros ,bh, wrap ,kyk, kyk1 ;
char ch,cha,chb;
short int rmed[12] , start=0;
char rmestrgr[12][26];
char rmestren[12][26];
int red,green,blue;
int cbrown[3];
int main_cur[3] , ins_cur[3];
char str1 [100];
int ichxr[3], ibkxr[3] , islxr[3] ; 
int proxchxr[3] , proxbkxr[3] , proxslxr[3] ;
char *loadfile ;
int pedaba [4] , pedaca;
FILE *fp ,*fpundo , *fpex;
int selpal=3456;
union whatcols{
unsigned int lor ;
unsigned char rgb[4];
} co ;
int pras[3] , galaz[3] , kokin[3];
int *chrpnt[3] , sel_red[3] , selred;
unsigned char *ghost;
unsigned short int hlpxt , hlpyt ;
static short int gr_flag , us_flag ;
static unsigned short int wherp , pre_cur, cur, ar, vam[3] , ins ;
static char savefile [512];
static short int undo ,undo_firfile , undo_lasfile , inf_crit;
static unsigned short int how_many , cur_ghost;
unsigned char klik;
int fide_fp , fide_undo ;
float neg, alfa ;
shlp=0;

switch (langex) {
    
    case 0:
        if (keyb_gr) { gr_flag=1; us_flag=0; } 
        else { gr_flag=0 ; us_flag=1; }
        break ;
        
    case 1:
        us_flag=1; gr_flag=0;
        break ;
        
    case 2:
        us_flag=0; gr_flag=1;
}


// Περίπτωση UNDO
epimeno :
if (undo==2) {
    wherp1=0 ; 
    if (inp_mem_ghost) free(inp_mem_ghost);
    ghost=inp_mem_ghost=0;
    do {
        //sprintf(file_1,"%s%s%d%s",path_name,"TMP/undo",undo_lasfile,".dat");
        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
        fpundo=fopen(file_1,"rb");
        if (fpundo!=NULL) break;
        undo_lasfile--;
        if (undo_lasfile<undo_firfile) {
            undo=0; undo_firfile=1; undo_lasfile=0 ; cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;break ;}
    } while (fpundo==NULL);
    if (undo) {
        fread (&cur,2,1,fpundo);
        fread (&ar,2,1,fpundo);
        if (orio<ar) {
            fclose (fpundo) ; fpundo=NULL ;
            cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; 
            vam[0]=0;
            undo=0; 
            undo_firfile=1; undo_lasfile=0 ;
            str[ar]=255;
            if (keyb_gr) information (0,"Απροσδιόριστο σφάλμα !!",0) ;
            else information (0,"Unknown Error !!",0) ;
            goto DIAFYGH ;
        }
        fread (str,1,ar,fpundo);
        fread (vam,2,3,fpundo);
        fread (&wherp,2,1,fpundo);
        fread (&pre_cur,2,1,fpundo);
        fread (&ins,2,1,fpundo);
        fread (&gr_flag,2,1,fpundo);
        fread (savefile,1,512,fpundo);
        fread (pxl,4,1,fpundo);
        fread (pyt,4,1,fpundo);
        fread (pxr,4,1,fpundo);
        fread (pyb,4,1,fpundo);
        fread (&orio1,4,1,fpundo);
        
        if ( ferror(fpundo) ) {
            clearerr(fpundo);fclose(fpundo); 
            remove(file_1);
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) {
                undo=0;
                undo_firfile=1; undo_lasfile=0 ; cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;
            } 
            else goto epimeno;
        }
        else {
            str[ar]=255;
            fclose (fpundo);
            remove(file_1);
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) {
                undo=0;
                undo_firfile=1; undo_lasfile=0 ;
            } else undo=1;
            if (orio!=orio1) { 
                cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;undo=0; undo_firfile=1; undo_lasfile=0 ;}
        } 
    }
}
else if (undo==3) {
    wherp1=0 ;
    if (inp_mem_ghost) free(inp_mem_ghost);
    ghost=inp_mem_ghost=0;
    strcpy(file_1,user_path);
    strcat(file_1,".EORT_SETTINGS/TMP/snapshot.dat");
    fpundo=fopen(file_1,"rb");
    if (fpundo!=NULL) {
        fread (&cur,2,1,fpundo);
        fread (&ar,2,1,fpundo);
        if (orio>ar) { 
            fread (str,1,ar,fpundo); 
            fread (vam,2,3,fpundo);
            fread (&wherp,2,1,fpundo);
            fread (&pre_cur,2,1,fpundo);
            fread (&ins,2,1,fpundo);
            fread (&gr_flag,2,1,fpundo);
            fread (savefile,1,512,fpundo);
            fread (pxl,4,1,fpundo);
            fread (pyt,4,1,fpundo);
            fread (pxr,4,1,fpundo);
            fread (pyb,4,1,fpundo);
            fread (&orio1,4,1,fpundo);
            if ( ferror(fpundo) ) {clearerr(fpundo);cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;}
        }
        else {cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;}
        if (orio1!=orio) {cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;}
        fclose (fpundo);
        str[ar]=255;
    }
    undo=0; undo_firfile=1; undo_lasfile=0 ;   
}
else if (!undo) {undo_firfile=1; undo_lasfile=0 ;}

DIAFYGH:
elax=gouv[0].wid;
bh=gouv[0].hei;
for (f=1;f<164;f++) {
    if (bh<gouv[f].hei) bh=gouv[f].hei;
    if (elax > gouv[f].wid) continue ; else elax=gouv[f].wid;}
chrpnt[0]=pras; chrpnt[1]=kokin; chrpnt[2]=galaz;
pras[0]=50; pras[1]=205; pras[2]=50;
galaz[0]=100; galaz[1]=149; galaz[2]=237;
kokin[0]=255; kokin[1]=0; kokin[2]=127;
cbrown[0]=44 ; cbrown[1]=31 ; cbrown[2]=22;
xl=*pxl ; yt=*pyt ; xr=*pxr ; yb = *pyb;
bkr=bkxr[0] ; bkg=bkxr[1] ;bkb=bkxr[2];  // ΕΔΩ καθορίζεται το backround color !!!
epr =slxr[0] ; epg=slxr[1] ;  epb=slxr[2] ; // ΕΔΩ παίρνει τις τιμές χρώματος όταν επιλέγεται κείμενο !!
setrgbpalette(selpal,epr,epg,epb);
for (f=0 ; f<3 ; f++) {
    sel_red[f]=slxr[f]+20;
    if(sel_red[f]>255) sel_red[f]=255;
}
selred=4567;
setrgbpalette(selred,sel_red[0] , sel_red[1] , sel_red[2] ) ;
main_cur[0] = 255-((epr+bkr)/2) ; main_cur[1] = 255-((epg+bkg)/2) ; main_cur[2] = 255-((epb+bkb)/2) ; // Κύριο χρώμα του κέρσορα !  
setrgbpalette(99,main_cur[0],main_cur[1],main_cur[2]); // To 99 κύριο χρώμα του κέρσορα
ins_cur[0] = 255-((epr+chxr[0])/2) ; ins_cur[1] = 255-((epr+chxr[1])/2) ; ins_cur[2] = 255-((epr+chxr[2])/2) ; // To "Insert" χρώμα του κέρσορα !
setrgbpalette(100,ins_cur[0],ins_cur[1],ins_cur[2]); // To 100 = insert χρώμα του κέρσορα
epr1 = epr + 70; if (epr1>255) epr1=255;
epg1 = epg + 50; if (epg1>255) epg1=255;
epb1 = epb + 40; if (epb1>255) epb1=255;
// dh=(2*bh)-1;
if (yb+34>=info.bottom) yb=info.bottom-34 ;
if (xr>=info.right-15) xr=info.right-15;
if ( (yb-yt) < bh+22 ) {yt=yb-bh-22 ; while ( (yt<info.top+1) && (yb<info.bottom-35) ) {yb++;yt=yb-bh-22 ;}}
if ( (xr-xl)  < 225) { xl=xr-225 ; while ( (xl<info.left+1) && (xr<info.right-15) ) {xr++ ;  xl=xr-225 ;}}   
if (orio<=0) return 0;
xep=xr-224;
xet=xr ; 
yep=yb+2;yet=yep+33;
*pxl=xl; *pyt=yt; *pxr=xr ; *pyb = yb;
elax=(xr-xl)/elax ; // ELAXISTH XVRHTIKOTHTA GRAMMHS ANALOGA TO MEGISTO PLATOS
setrgbpalette(10,0,255,127) ; // Light Green=10
setrgbpalette(11,255,99,71) ; // Tomato=11
setrgbpalette(12,0,255,255) ; // Light Blue=12
ichxr[0]=51; ichxr[1]=228; ichxr[2]=114;
ibkxr[0]=ibkxr[1]=0; ibkxr[2]=117;
islxr[0]=62 ; islxr[1]=40; islxr[2]=47;
blosta = bloend = -1;
size=imagesize(xl,yt,xr,yb);
mem1=malloc(size);
if (!mem1) { printf ("Out of memory") ; return 0; }
size_cu=imagesize(0,0,1,(bh-1));
mem_cu=malloc(size_cu);
if (!mem_cu) { printf ("Out of memory") ; free (mem1); return 0; }
getimage(xl,yt,xr,yb,mem1);
bareacls(xl,yt,xr,yt+19,cbrown);
setcolor (COLOR (180,0,0)) ;   // Rectangle Color !!
rectangle (xl,yt,xr,yt+19) ; 
strcpy(file_1,path_name);
strcat(file_1,"ICD/hand_17.ico");
mem_arrs=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/info_17.ico");
mem_info=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/Search_17.ico");
mem_find=icontomem(file_1,255);

strcpy(file_1,path_name);
strcat(file_1,"ICD/Fonter_17.ico");
mem_fonter=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/ext_link.ico");
mem_link=icontomem(file_1,255);

_puticon(xl+1,yt+1,mem_arrs,255);
_puticon(xr-18,yt+1,mem_info,255);
_puticon(xr-36,yt+1,mem_find,255);
_puticon(xr-54,yt+1,mem_fonter,255);

_puticon(xl+19,yt+1,mem_link,255);



    if (keyb_gr) strcpy (str1024,"Επεξεργασία Σημειώσεων"); 
    else strcpy (str1024,"Edit Notes");
    normtext_tomy(str1024,0);
    _outmystr_center_col(0, str1024,xl+37, yt+1, xr-87,yt+19, chrpnt[2],cbrown); 

refresh();
yt+=20;
areacls(xl,yt,xr,yb,bkr,bkg,bkb);
setcolor (COLOR (180,0,0)) ;   // Rectangle Color !!
rectangle (xl,yt,xr,yb) ; 
xl+=1 ; yt++ ; xr-- ; yb--;
x=xl ; y=yt;
diaf1=yb-yt+1; diaf2=diaf1/bh;maxline=diaf2; ektos=yt+(diaf2*bh);
refresh();
strcpy(file_1,path_name);
strcat(file_1,"ICD/und_inp.ico");
mem_under=icontomem(file_1,255);

if (keyb_gr) {
    strcpy(file_1,path_name);
    strcat(file_1,"ICD/gr_flag.ico");
    mem_flgr=icontomem(file_1,255);
    sprintf (rmestrgr[0] , "Sv'se vw..");
    sprintf (rmestrgr[1] , "Eish'gage Arxei'o");
    sprintf (rmestrgr[2] , "Sv'se..");
    sprintf (rmestrgr[3] , "Arxh' Mplo'k");
    sprintf (rmestrgr[4] , "Te'low Mplo'k");
    sprintf (rmestrgr[5] , "Diagrafh' Mplo'k");
    sprintf (rmestrgr[6] , "Antigrafh'");
    sprintf (rmestrgr[7] , "Epiko'llhsh");
    sprintf (rmestrgr[8] , "Sv'se vw kei'meno");
    sprintf (rmestrgr[9] , "Ana'kthsh stigmio'typ.");
    sprintf (rmestrgr[10] , "Diagrafh' O'la");
    sprintf (rmestrgr[11] , "Fy'ge..");
    }
    sprintf (rmestren[0] , "Save as");
    sprintf (rmestren[1] , "Insert ..");
    sprintf (rmestren[2] , "Save ..");
    sprintf (rmestren[3] , "Block Start");
    sprintf (rmestren[4] , "Block End");
    sprintf (rmestren[5] , "Delete Block");
    sprintf (rmestren[6] , "Copy..'");
    sprintf (rmestren[7] , "Paste..");
    sprintf (rmestren[8] , "Save as .txt");
    sprintf (rmestren[9] , "Load Snapshot");
    sprintf (rmestren[10] , "Delete All");
    sprintf (rmestren[11] , "GO...");    
    
strcpy(file_1,path_name);
strcat(file_1,"ICD/usa_flag.ico");
mem_flusa=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/Inp_menu.ico");
mem_rmenu=icontomem(file_1,255);
size=imagesize(xep,yep,xet,yet);
mem_undscr=malloc(size);
if (!mem_undscr) { printf ("Out of memory") ; free (mem1); return 0; }
getimage(xep,yep,xet,yet,mem_undscr);
putimage(xep,yep,mem_under,0); refresh();
size=imagesize(xep+136,yep+4,xep+179,yep+30);
mem_enter=malloc(size);
if (!mem_enter) { printf ("Out of memory") ; free (mem1); free (mem_undscr) ; return 0; }
getimage(xep+136,yep+4,xep+179,yep+30,mem_enter);
size=imagesize(xep+182,yep+4,xep+223,yep+30);
mem_tent=malloc(size);
if(!mem_tent) {printf ("Out of memory") ; free (mem1); free (mem_undscr) ; free(mem_enter); return 0;}
getimage(xep+182,yep+4,xep+223,yep+30,mem_tent);
size=imagesize (xr+3,yt-1,xr+13,yb);
mem_bar=malloc(size);
if (mem_bar==NULL) {printf ("Memory Problem") ; free (mem1); free (mem_undscr) ; free(mem_enter); free(mem_tent); return (0); }
getimage (xr+3,yt-1,xr+13,yb,mem_bar);

pedaba[0]=22111963; pedaba[1]=404976; pedaba[2]=99; pedaba[3]=167330;

// ELEGSOS GIA CAPS LOCK PATHMENO XVRIS MPERDEMA ME ALLA PLHKTRA //
SDL_FlushEvent (SDL_KEYDOWN);
state = SDL_GetKeyboardState(NULL);
ch_mod=SDL_GetModState();
caps_lock = ( (ch_mod==8192) || (ch_mod==12288) ) ? 1 : 0 ;

if (caps_lock) {
       for (f=3;f<29;f++) {
       mem_int=(mem_under+8+(f*225*4));
       for(i=48 ; i<84;i++) {
       co.lor= *(mem_int+i);
       setcolor ( COLOR ( co.rgb[2] , co.rgb[1] , (co.rgb[0] +100)) );
        
       _putpixel (xep+i,yep+f);}} 
       refresh();} 
col_cu = 99; 
time_metr=0;
diak=0;
pos[0][0]=xl ; pos[0][1]=yt;
for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
x1=x ; y1=y;
ghost = inp_mem_ghost ;
//ELEGXOS TOY ALFARIUMHTIKOY str kai parousiash tou keimenou //
    what=str[0];
    if (what !=255) {
        f=0; diaf2=0;
        while ( (what!=255) && (orio-f) ) {
        if (what==200) {f++;what=str[f];continue;}
        if ( (what>=0) && (what<164) ) {f++;what=str[f];continue;}
        diaf2=1; break; 
            } 
        str[f]=255; diaf1=f;
        if ( (!ar) || (ar!=diaf1) || (diaf2) ) {
        ar=diaf1;cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;undo=0; undo_firfile=1; undo_lasfile=0 ;}                    
       // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ       
        x1=xl ; y1=yt;
        for (a=0; a<ar; a++) {
        what=str[a];
        if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ; x1=xl ; y1+=bh; continue ;}
        wrap=0 ;  
        if ((x1+gouv[what].wid) > xr-2) {
            if ( (what) ) {  
                i=a;
                while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                i++;wrap--;
                if (elax<wrap+1) wrap=0;}
                x1=xl ; y1+=bh; }
        
        do {
        pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
        what=str[a-wrap];
            x1+=gouv[what].wid;
            wrap--;
            } while (wrap>=0);
        }
            str[ar]=255 ;
            pos[ar][0]=x1 ; pos[ar][1]=y1;
            // ΝΕΑ ΕΜΦΑΝΙΣΗ                
            
        if (wherp) {
        f=0;
        while (pos[wherp-f][0] != xl) f++;
        wherp-=f;
        diaf1=(pos[wherp][1]-yt);
        for (i=0;i<=ar;i++) pos[i][1]-=diaf1;
        wherp1=0;
        }
        
        else if (wherp1) 
        {
        if (wherp1>=ar) wherp1=ar-1;
        f=0;
        while (pos[wherp1-f][0] != xl) f++;
        wherp1-=f;
        diaf1=(pos[wherp1][1]-yt);
        for (i=0;i<=ar;i++) pos[i][1]-=diaf1;
        wherp=wherp1;
        cur=wherp1;
        }
        
        while (pos[cur][1]>=ektos) {
            f=wherp;
            while (pos[f][1]==yt) f++;
            wherp=f;
                for (i=0;i<=ar;i++) pos[i][1]-=bh;}
       
        for (a=wherp; a<ar; a++) {
            what=str[a];
            if (what==200) continue ;
            y1=pos[a][1];
            if (y1>=ektos) break ;
            x1=pos[a][0];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) {
                if (!ghost) continue;
                if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                else continue ;
            }
            

            // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
            setcolor(COLOR (red,green,blue));
            _putpixel(x1+i , y1+f);}}
            if(!ghost) continue ;
            if (ghost[a]) {
                while (f<bh) {
                setrgbcolor(selred);
                for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
            }
        }
        refresh();
        x=pos[cur][0] ; y=pos[cur][1];
        if (vam[0]) {                              // βάφω 
                // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
        setrgbcolor (selpal);  
        for (a=vam[1]; a<=vam[2]; a++) {
        y1=pos[a][1] ;
        if (y1<yt) continue ;
        if (y1>=ektos) break ;
        what=str[a];
        x1=pos[a][0] ; 
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
            refresh();              
        }
        // ELEGXOS GIA PLEYRIKH MPARA
        proyt=abs(pos[0][1]-yt) ;
        metektos = pos[ar][1]- yt - ( (maxline-1)*bh );
        if ( (!proyt) && (metektos<=0) ) goto Enarjh ;
        bar=1;
        setcolor (COLOR (0,255,0) );  
        rectangle (xr+3,yt-1,xr+13,yb);
        setcolor (COLOR (0,0,0) );  
        for (f=xr+4 ; f<xr+13 ; f++) {
            for (i=yt ; i < yb; i++) _putpixel (f,i); }
        olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
        y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
        y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;
        if (y1==y2) y2++;
        bary1=y1 ; bary2=y2;
        setcolor (COLOR (255,165,0) );  
        for (f=xr+4 ; f<xr+13 ; f++) {
            for (i=y1 ; i < y2; i++) _putpixel (f,i); }
        refresh();
    }
    else {cur=0;ar=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0; wherp1=0; pre_cur=0;ins=0;undo=0; undo_firfile=1; undo_lasfile=0 ;}

Enarjh :
if (gr_flag) {us_flag=0 ; putimage(xep+5,yep+4,mem_flgr,0);}
refresh();

if (ins) {
col_cu = 100 ;
for (f=3;f<29;f++) {
mem_int=(mem_under+8+(f*225*4));
for(i=95 ; i<129;i++) {
    co.lor= *(mem_int+i-1);
    setcolor ( COLOR ( co.rgb[2]  , co.rgb[1] , co.rgb[0] +ins*70) );
    _putpixel (xep+i,yep+f);}} 
    refresh();
}


    for(;;) {
        
if (!shlp) {
        time_metr++;
    if (time_metr>150000) {
        time_metr=0;
        if (!diak) {
        getimage(x,y,x+1,y+bh-1,mem_cu);   
        diak=1;
        setrgbcolor(col_cu); 
        for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
        _putpixel(x+i,y+f) ;} }
        refresh() ; 
        }
        else {putimage(x,y,mem_cu,0); refresh() ; diak=0;}}
}

if (!SDL_PollEvent(&sdlev)) continue;
    
    switch (sdlev.type) {
    
    case SDL_MOUSEMOTION:
        if ( (secwin) && (sdlev.motion.windowID == sdlwin2) ) { continue ;}
    mx=sdlev.motion.x ; my=sdlev.motion.y;

    if (mx>xl && mx<xl+18 && my>yt-21 && my<yt) { // Στην κεφαλίδα
    
        if (inp_info) {puticon(xr-18,yt-20,mem_info,255); inp_info=0;hide_help_inp(hlpxt , hlpyt);}
        else if (fnd_but) {puticon(xr-36,yt-20,mem_find,255); fnd_but=0;hide_help_inp(hlpxt , hlpyt);}
        else if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
        
        if (!marrs) {
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
            SDL_SetCursor(cursor);
            marrs=1;
            putNOTicon(xl,yt-20,mem_arrs);
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            show_help_inp("Μετακίνηση Παραθύρου", xl+20 , yt+10 , &hlpxt , &hlpyt) ;
            
            continue ;}
            else continue ;
        }
    
    if (marrs) {
        marrs=0;
        puticon(xl,yt-20,mem_arrs,255);
        hide_help_inp(hlpxt , hlpyt);
 }

    if (mx>xr-18 && mx<xr+1 && my>yt-21 && my<yt) {  // Info Button
        
        if (fnd_but) {puticon(xr-36,yt-20,mem_find,255); fnd_but=0;hide_help_inp(hlpxt , hlpyt);}
        else if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
        
        
        if (!inp_info) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          inp_info=1;
          putNOTicon(xr-18,yt-20,mem_info);
          if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
          show_help_inp("Γενικά στοιχεία για το κείμενο", xr-18 , yt+10 , &hlpxt , &hlpyt) ;
          
          continue; }
          else continue;
        }
    
    if (inp_info) {
        puticon(xr-18,yt-20,mem_info,255); inp_info=0;hide_help_inp(hlpxt , hlpyt);}
        
            
    if (mx>xr-36 && mx<xr-18 && my>yt-21 && my<yt) {  // Search Button
        
        if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
        
        
        if (!fnd_but) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          fnd_but=1;
          putNOTicon(xr-36,yt-20,mem_find);
            
            mytext_tonorm (normdeigma , str1kb , 20) ;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            sprintf (str1024 , "Αριστ. κλικ : Αναζήτηση [%s] - Δεξί κλικ : Εισαγωγή του προς αναζήτηση δείγματος",str1kb);
                
            

        show_help_inp (str1024 , xr-18, yt+10, &hlpxt , &hlpyt) ;
          continue; }
          else continue;
        }
    
    if (fnd_but) {puticon(xr-36,yt-20,mem_find,255); fnd_but=0;hide_help_inp(hlpxt , hlpyt);}
    
    if (mx>xr-54 && mx<xr-36 && my>yt-21 && my<yt) {  // Fonts Button
        
        if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
    
        
        if (!fonter) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          fonter=1;
          putNOTicon(xr-54,yt-20,mem_fonter);
          if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
          show_help_inp("Επιλογή Γραμματοσειράς (προσωρινή χρήση)", xr-54 , yt+10 , &hlpxt , &hlpyt) ;
          
          continue; }
          else continue;
        }
    
    if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
    
    
    
        if (mx>xl+18 && mx<xl+37 && my>yt-21 && my<yt) {  // LINKER !!
        
        if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        
        
        if (!linker) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          linker=1;
          putNOTicon(xl+19,yt-20,mem_link);
          if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
          
          show_help_inp("Επιλεγμένο κείμενο ως διαδικτυακός σύνδεσμος", xl+50 , yt+10 , &hlpxt , &hlpyt) ;
          
          continue; }
          else continue;
        }
    
    if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
    

          
    if (mx>xep+135 && mx<xep+180 && my>yep && my<yet) { // Κλείσε παράθυρο εισαγωγής
        
        if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        
        if (!port) {
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);
        port=1;
        
        for (f=4;f<31;f++) {
        mem_int=(mem_under+ 8+ (f*225*4));
        for(i=136 ; i < 178; i++) {
        co.lor= *(mem_int+i);
        setcolor ( COLOR (co.rgb[2]  , co.rgb[1] +20 , co.rgb[0]+60 ) );
        _putpixel (xep+i,yep+f);}} 
        refresh(); 
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        show_help_inp("Kλείσιμο παραθύρου", xep+135 , yet+1 , &hlpxt , &hlpyt) ;
        
        continue ;}
        else continue ;
        continue; }

    if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
    
    
    
    if (mx>xep+182 && mx<xet && my>yep && my<yet) { // Αλλαγή Διαστάσεων
        
        if (!tent) {
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);
        tent=1;
        
        for (f=4;f<31;f++) {
        mem_int=(mem_under+ 8+ (f*225*4));
        for(i=182 ; i < 223; i++) {
        co.lor= *(mem_int+i);
        setcolor ( COLOR (co.rgb[2]  , co.rgb[1] +20 , co.rgb[0]+60 ) );
        _putpixel (xep+i,yep+f);}} 
        refresh(); 
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        show_help_inp("Αλλαγή Διαστάσεων", xep+182 , yet+1 , &hlpxt , &hlpyt) ;
        
        continue ;}
        else continue ;
        continue; }

    if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);hide_help_inp(hlpxt , hlpyt);}
    
    if ( (keyb_gr) && mx>xep+2 && mx<xep+43 && my>yep && my<yet) {
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);continue;}
        
     if (bar) {
         if (mem_small) hide_help_inp(hlpxt , hlpyt);
         if (mx>xr+3 && mx<xr+14 && my>yt && my<yb) {
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);continue;}}
        
    
    if (mx>xl && mx<xr && my>yt && my<yb) {
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
   SDL_SetCursor(cursor);continue;}
   
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
   SDL_SetCursor(cursor);
   if (mem_small) hide_help_inp(hlpxt , hlpyt);
    continue;
    
    case SDL_MOUSEWHEEL :
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        if(sdlev.wheel.y > 0) { // scroll up
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                if (pos[0][1]==yt) {cur=0; x=xl ; y=yt; continue;}
                diaf2=(maxline>3) ? 3 : maxline ;
                f=cur;
                while (pos[f][1]>=yt) f--;
                while ( (pos[f][1] >=(yt-diaf2*bh)) && (f>=0) ) f--;
                f++; cur=f ;
                diaf1=yt-pos[f][1]; diaf1 /= bh;
                for (i=0;i<=ar;i++) pos[i][1] += (diaf1*bh);
                x=xl ; y=yt;
                // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();

  if (vam[0]) {                              // βάφω 
                       // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setrgbcolor (selpal); 
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
                 goto barovios ;                
        }
        else if (sdlev.wheel.y < 0) { // scroll down
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 if (pos[ar][1]<ektos ) {cur=ar; x=pos[ar][0]; y=pos[ar][1]; continue ;}
                 diaf2=(maxline>3) ? 3 : maxline ;
                 
                 f=cur;
                 while (pos[f][1] > yt) f--;
                 while (pos[f][0] !=xl) f--;
                 while ( pos[f][1]<(yt+diaf2*bh) ) f++;
                 cur=f;
                 for (i=0;i<=ar;i++) pos[i][1]-=(diaf2*bh);
                 x1=x=xl; y1=y=yt;
                 // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();
                                  
                if (vam[0]) {                              // βάφω 
                
                        // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setcolor (COLOR (epr,epg,epb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
                 goto barovios ;
        }
            
        continue ;
        
    case SDL_MOUSEBUTTONDOWN:
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
    if(sdlev.button.button==SDL_BUTTON_LEFT) {   
        auto int pev ;
        mx = sdlev.button.x ; my= sdlev.button.y ;
        klik= sdlev.button.clicks; 
                
        if (mx>xep && mx<xet && my>yb && my<yet) { // Choose ok ,flag , change dimensions
            diaf1=(mx-xep)/45;
            switch (diaf1) {
                case 0:
                    if (!keyb_gr) continue;
                    us_flag=abs (us_flag-1) ; gr_flag=abs(gr_flag-1) ; ton=0; dial=0; 
                    if (us_flag) putimage(xep+5,yep+4,mem_flusa,0);
                    else putimage(xep+5,yep+4,mem_flgr,0);
                    continue; 
                    
                case 1:
                case 2:
                    continue;
                    
                case 3: // (FYGE (Return) me pontiki)
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        diaf1 = f;} else diaf1 = 0;
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; cur_ghost=0;}
                    fidicls (xl,yt,xr,yb,0,0,0);
                    putimage(xl-1,yt-21,mem1,0); putimage(xep,yep,mem_undscr,0);free(mem_undscr);free(mem1) ; free(mem_cu); free(mem_flusa); free(mem_enter);free(mem_tent);  free(mem_under); 
                    if (bar) { putimage (xr+3,yt-1,mem_bar,0); refresh(); }
                    free(mem_bar); if (keyb_gr) free(mem_flgr); free(mem_rmenu); free(mem_arrs); free(mem_info); str[ar]=255;
                    free(mem_find); free(mem_fonter); free(mem_link);
                    langex = (us_flag) ? 1 : 2 ;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh();  ar=0; undo=0; undo_firfile=1; undo_lasfile=0 ; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; return diaf1;
                
                case 4:
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter);  free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    change_dim(xl, yt-21 ,pxr , pyb);  
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    str[ar]=255;
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);free(mem_bar);
                    langex = (us_flag) ? 1 : 2 ;
                    free(mem1);
                    refresh();
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS GIA ALLAGH DIASTASEVN !!!
          }
        }
        if (inp_info) {
            if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
            if (!ar) continue ;
            x2=(info.right-info.left-400)/2;
            y2=(info.bottom-info.top-320)/2;
            mem_power=malloc( (imagesize(x2,y2,x2+399,y2+299)) );
            if (!mem_power) {information(2-keyb_gr,0,0) ; continue;}
            getimage (x2,y2,x2+399,y2+299,mem_power);
            setcolor(COLOR(255,0,0));
            rectangle(x2,y2,x2+399,y2+299);
            rectangle(x2+1,y2+1,x2+398,y2+298);
            x2+=2; y2+=2 ;
            _areacls(x2,y2,x2+396,y2+296,ibkxr[0],ibkxr[1],ibkxr[2]);
            meg_leks=parag=ken_parag=leks=meg_par=par_leks=big_par=0;
            
            for (f=0;f<ar;f++) {
                
                what=str[f];
                if (what==200) {
                    secr= (f) ? str[f-1] : 0 ;
                    if (secr==200) ken_parag++; else { 
                        parag++; 
                        if (par_leks>meg_par) {
                        meg_par=par_leks ;
                        big_par=parag;}
                        par_leks=0;
                    }
                continue;
                }
                
                if (what>42) {
                    i=0;
                    while ( (f<ar) && (what!=200) && (what>42) ) {
                        what=str[++f]; i++;}}
                else continue ;
                        
                if (i>1) { leks++; par_leks++;}
                if (i>meg_leks) meg_leks=i;
                if (what==200) { 
                    parag++; 
                    if (par_leks>meg_par) {
                        meg_par=par_leks ;
                        big_par=parag;}
                        par_leks=0;
                        
                    }
                
            }
            
            if (keyb_gr) {
            _outnoto_colsel (x2+120,y2+4," ENHMERVSH ",1,ichxr,ibkxr,islxr);
            
            f=46;
            sprintf (str1," Me'gisto O'rio Xarakth'rvn : %d " , orio);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Ariumo'w Xarakth'rvn : %d " , ar);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
             sprintf (str1," Diaue'simow xv'row : %d xarak. " , orio-ar);
            _outsouv_colsel (x2+5,y2+f,str1,1,ichxr,ibkxr,islxr);
            f+=24;
            sprintf (str1," Le'jeiw  : %d " , leks);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Mh'kow megaly'terhw le'jhw : %d xarak." , meg_leks);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Para'grafoi : %d " , parag);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Megaly'terh para'gr. No %d me %d le'jeiw" , big_par, meg_par);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Kene'w Para'grafoi : %d " , ken_parag);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=36;
                }
            else {
                
            _outnoto_colsel (x2+135,y2+4," BRIEFING ",0,ichxr,ibkxr,islxr);

            f=46;
            sprintf (str1," Characters max limit : %d " , orio);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Characters number : %d " , ar);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
             sprintf (str1," Available space : %d char. " , orio-ar);
            _outsouv_colsel (x2+5,y2+f,str1,0,ichxr,ibkxr,islxr);
            f+=24;
            
            sprintf (str1," Words  : %d " , leks);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Bigger word length : %d char." , meg_leks);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Paragraphs : %d " , parag);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Bigger paragr. No %d - %d words" , big_par, meg_par);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Empty Paragraphs : %d " , ken_parag);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=36;
                }
                
            setcolor(COLOR(ichxr[0],ichxr[1],ichxr[2])); 
            line(x2+110,y2+29,x2+275,y2+29);
            line(x2+115,y2+32,x2+270,y2+32);
            line (x2+4,y2+f,x2+393,y2+f); f+=3;
            line(x2+9,y2+f,x2+388,y2+f);
            _putNOTicon(x2+378,y2+4,mem_info);
            refresh();
            
            f=0;i=0;
            while ( event() != 1 ) {
            f++;    
            if (f>100000) {f=0; 
                if (!i) {i=1; 
                    //_bareacls(x2+378,y2+4,x2+396,y2+22,ibkxr); 
                    puticon(x2+378,y2+4,mem_info,255);} 
                else { i=0 ; putNOTicon(x2+378,y2+4,mem_info);}
                } }
            
            x2-=2 ; y2-=2;
            putimage (x2,y2,mem_power,0);
            while (SDL_PollEvent(&sdlev)) continue;
            refresh();
          inp_info=0;
          puticon(xr-18,yt-20,mem_info,255);
          free (mem_power);
            continue;
        }
        
        if (fnd_but) {
            if (!ar) {fnd_but=0; puticon(xr-36,yt-20,mem_find,255); continue ;}
            if (keyb_gr) {ton=0 ; dial=0 ;}
            if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
            if (ghost) { // Ψάχνει το επόμενο ... ανακυκλώνοντας το ψάξιμο !
                if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));  
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];   x1= pos[a][0] ;
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;pre_cur=0;
                }
                f=cur;
                while ( (ghost[f]) && (f<ar) ) f++;
                if (f==ar) f=0;
                while ( (!ghost[f]) && (f<ar) ) f++;
                if (f==ar) f=cur_ghost;
                cur=f;
                y=pos[cur][1];
                if (y<ektos && y>=yt) {x=pos[cur][0];  continue ;}
                if (cur) {
                    f=0;
                    while (pos[cur-f][0] !=xl)  f++;
                    diaf3=pos[cur-f][1]-yt;
                    for (i=0;i<=ar;i++) pos[i][1]-=diaf3;
                    ano_ar=cur-f;
                    }
                else ano_ar=0;
                x=pos[cur][0] ; y=pos[cur][1]; 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                refresh();
                
                for (a=ano_ar; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                refresh ();
            }
            
            else { // Ψάχνει για πρώτη φορά....δεν ζητάει όμως κριτήρια !
                convertinp_strstr  (0, str, arped, &how_many, &cur_ghost);
                ghost=inp_mem_ghost;
                if (!ghost) {
                    if(!inf_crit) {
                        inf_crit=1;
                        information (48-keyb_gr,0,0);
                    }
                      else {                 
                    if (!how_many) {
                        if (keyb_gr) information (0,"Δεν βρέθηκε τίποτε !",0);
                        else information(0,"Nothing found !",0);
                    }}
                fnd_but=0; puticon(xr-36,yt-20,mem_find,255); 
                continue ;}
                if (keyb_gr) sprintf(str1024,"Προέκυψε ταύτιση σε %d σημεία!", how_many);
                else sprintf(str1024,"Identity occurred in %d points!", how_many);
                information(0,str1024,0);
                if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));  
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];   x1= pos[a][0] ;
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;pre_cur=0;
                }
                cur=cur_ghost;
                y=pos[cur][1];
                x=pos[cur][0]; 
                if (cur) {
                    f=0;
                    while (pos[cur-f][0] !=xl)  f++;
                    diaf3=pos[cur-f][1]-yt;
                    for (i=0;i<=ar;i++) pos[i][1]-=diaf3;
                    ano_ar=cur-f;
                    }
                else ano_ar=0;
                x=pos[cur][0] ; y=pos[cur][1]; 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                refresh();
                
                for (a=ano_ar; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                refresh();
            }
            
            goto barovios ;
        }
        
        if (fonter) {
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    for (f=0 ; f<3 ; f++) { proxchxr[f]=chxr[f] ; proxbkxr[f]=bkxr[f] ; proxslxr[f]=slxr[f] ; }  
                    user_ans=inp_fonts_show((char *) NULL, dbfnt.mem_fn, dbfnt.fn_data, dbfnt.fn_ar, dbfnt.fn_orio, dbfnt.fn_name, &dbfnt.fn_sorton,0, chxr, bkxr, slxr );
                    for (f=0 ; f<3 ; f++) { chxr[f] = proxchxr[f] ; bkxr[f] = proxbkxr[f] ; slxr[f] = proxslxr[f] ; }  
                    if (user_ans<0) continue;
                    gouv=myfont[user_ans];
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter); free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    str[ar]=255;
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);free(mem_bar);
                    langex = (us_flag) ? 1 : 2 ;
                    free(mem1);
                    refresh();
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS ALLAGH FONT !!!
        }
        
        
        if (linker) {
            
            if (mem_small) hide_help_inp(hlpxt , hlpyt);
            if (!vam[0]) continue ;
            if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
            
            i=0;f=vam[1];
            what=str[f];
            do {
                if (what>163) break ;
                str1024[i++]=what;
                f++; what=str[f];
            }while (f<=vam[2] && i<1380);
            str1024[i]=255;
            mytext_tonorm(str1024,str1kb,1380);
            if (!Start_strstr(str1kb,"https://")) {continue;}
            if (keyb_gr) normtext_tomy ("Επιλέξατε..",str1024);
            else normtext_tomy ("Choose..",str1024);
            for (f=0 ; f<3 ; f++) { proxchxr[f]=chxr[f] ; proxbkxr[f]=bkxr[f] ; proxslxr[f]=slxr[f] ; }
            user_ans=fastmenu_show(2, submenu, str1024, xl+37,yt-20);
            for (f=0 ; f<3 ; f++) { chxr[f] = proxchxr[f] ; bkxr[f] = proxbkxr[f] ; slxr[f] = proxslxr[f]; }
            if (user_ans<0) continue ;

            
            i=0;
            switch (user_ans) { 

                case 0 :
                    if (nofire) {i=1 ; break;}
                    strcpy (big_char,str1kb);
                    orisma[2]=big_char;
                    pid = fork();
                    if (pid<0) {perror("Fork...");break;}
                    else if (pid==0) {execl("/usr/bin/firefox","firefox","--new-tab",orisma[2],(char *)NULL); _exit(1);}
                    else {waitpid(pid,&status,WNOHANG);}
                    break ;
                    
                case 1 :
                    if (nochrom) {i=1; break;}
                    strcpy (big_char,str1kb);
                    orisma[2]=big_char;
                    pid = fork();
                    pid = fork () ;
                    if (pid<0) {perror("Fork...");break;}
                    else if ( !pid ) {
                        //pid=getpid();
                        execl("/usr/bin/google-chrome","google-chrome",orisma[2],(char *)NULL); 
                        _exit (1); 
                        }
                    else waitpid(pid,&status,WNOHANG);
                    break ;
            }
            
            if (i==1) {
                if (keyb_gr) strcpy (str1024,"Mh εγκατεστημένος browser!");
                else strcpy (str1024,"Browser not installed!");
                information (0,str1024,0);
            }

            continue ;            
                
        }
        
        
        if (mx>xl && mx<xl+18 && my>yt-21 && my<yt) {
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter); free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                     f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;            
                    change_pos(pxl, pyt ,pxr , pyb);  
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    str[ar]=255;
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);free(mem_bar);
                    langex = (us_flag) ? 1 : 2 ;
                    free(mem1);
                    refresh();
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS GIA ALLAGH UESHS  !!!
            
        }
        
        if ( mx>xr+14 || mx<xl-1 || my>yb+1 || my<yt-20 ) goto DROMO;
        
        // KLIK STHN MPARA !!
        if (bar) {
           
          if (mx>xr+3 && mx<xr+14 && my>yt && my<yb) {
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
            SDL_SetCursor(cursor);
            if (my<bary1) goto PAGEUP ;
            if (my>bary2) goto PAGEDOWN ;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            y3=bary1 + (bary2-bary1+1)/2 ;
            
            esc_go=0;
            do {
           
                while (SDL_PollEvent(&sdlev)) 
                { 
                    esc_go=0;
                    switch (sdlev.type) {
                        case SDL_MOUSEMOTION :
                            my= sdlev.button.y ;
                            SDL_FlushEvent(SDL_MOUSEMOTION);
                            break ;
                            
                        case SDL_MOUSEBUTTONUP :
                            esc_go=1;
                            
                        default :
                            break ;
                    }
                    break ;
           }

            if (my>yb) my=yb;
            if(my<yt) my=yt;
            if (y3==my) continue;
            diafy=my-y3;
            
            f=cur;
            if (f) {
                while (pos[f][1]!=yt) f--;
                while (pos[f][0]!=xl) f--;
                ano_ar=f; } else ano_ar=cur;
                y2=pos[ano_ar][1];
                
            if (diafy<0) {
                if (!cur) continue;
                if (!ano_ar) {cur=0; continue;}
                diafy=abs(diafy);
                
                diaf2=( diafy*(olohei/bh) ) / (yb-yt-1) ; // Σε πόσες γραμμές αντιστοιχούν τα pixels
                if (!diaf2) continue;
                
                do {
                if (pos[0][1] <= (yt - ( diaf2*bh)) ) {for (i=0;i<=ar;i++) pos[i][1]+=diaf2*bh; break ;}
                else diaf2--;
                } while (diaf2);
                if (!diaf2) continue;
                f=ano_ar;
                while (pos[f][1]!=y2) f--;
                while (pos[f][0]!=xl) f--;
                cur=f;}
                else {
                    if (cur==ar) continue;
                    if (pos[ar][1]<ektos) continue ;
                    diaf2=( diafy*(olohei/bh) ) / (yb-yt-1) ; // Σε πόσες γραμμές αντιστοιχούν τα pixels
                     if (!diaf2) continue;
                      do {
                        if (pos[ar][1] >= yt + ( diaf2*bh) ) {for (i=0;i<=ar;i++) pos[i][1] -= diaf2*bh; break ;}
                        else diaf2--;
                        } while (diaf2);
                        if (!diaf2) continue;
                        f=ano_ar;
                        while (pos[f][1]!=y2) f++;
                    cur=f;}
            
               x1=x=xl; y1=y=yt;
               
                 // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }
                    

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();
                
                if (vam[0]) {                              // βάφω 
                
                        // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setrgbcolor (selpal);
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
               proyt1=abs(pos[0][1]-yt) ;
               metektos1 = pos[ar][1]- yt - ( (maxline-1)*bh );
               if ( (!proyt1) && (metektos1<=0) ) {
               putimage (xr+3,yt-1,mem_bar,0);
               bar=0;
               refresh();
               continue ;}
               if (proyt1==proyt && metektos1==metektos) continue;
               proyt=proyt1 ; metektos=metektos1;
               olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
               setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
               y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
               y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;     
                if (y1==y2) y2++;
               bary1=y1 ; bary2=y2;
               setcolor (COLOR (255,165,0) );  
               for (f=xr+4 ; f<xr+13 ; f++) {
                    for (i=y1 ; i < y2; i++) _putpixel (f,i); }
               y3=bary1 + (bary2-bary1+1)/2 ;
                refresh();
            } while (sdlev.type!=SDL_MOUSEBUTTONUP && (bar) && (!esc_go) ) ; 
            if (keyb_gr) {ton=0 ; dial=0 ;}
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
            SDL_SetCursor(cursor);
            x=pos[cur][0] ; y=pos[cur][1];
            continue ;
        }
        }
        
        
        // Μέσα στο Κείμενο κλίκ....
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        if (keyb_gr) {ton=0 ; dial=0 ;}
        if (vam[0]) {                              //σβηνω κερσορα - ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb)) ;  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            x1= pos[a][0] ; what=str[a];
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}            
            refresh();
            vam[0]=0;pre_cur=0;
            }
            
        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
            
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            f=cur;
            if (f) {
                while (pos[f][1]!=yt) f--;
                while (pos[f][0]!=xl) f--;
                ano_ar=f; } else ano_ar=cur;
                
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;cur_ghost=0;
        }
        
        if (!ar) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1]; 
        diaf1=2*xr;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
       curst= --f;
       chb=0;
       if (curst>=ar) {chb=1; curst=ar-1;}
       if (klik>1) {
           
            f=curst;
            if (f) {
                while (pos[f][0]!=xl) f--;
            }
            curst=f;
            i=f;
            what=str[i];
            while ( (what!=200) && (i) ) {what=str[--i];}
            vam[1] = (i) ? i+1 : 0 ;
            //vam[1]=f;
            what=str[f];
            while (what<200) {what=str[++f];}
            vam[2] = f ;
            if (vam[1]==vam[2]) continue ;
            if (!f) continue ;
            vam[2] = (f==ar) ? f-1 : f ;
            vam[0]=1;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setrgbcolor (selpal);  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1=pos[a][1] ;
            if (y1<yt) continue ;
            if (y1>=ektos) break ;
            what=str[a];
            x1=pos[a][0] ; 
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
            }
            refresh();  
            goto DIPLO_KL ;

    }
        do {
        pev = SDL_PollEvent(&sdlev);
       //while (SDL_PollEvent(&sdlev) && sdlev.type ==SDL_MOUSEMOTION) continue;
       mx = sdlev.button.x ; my= sdlev.button.y ;
       SDL_FlushEvent(SDL_MOUSEMOTION);
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1];
        diaf1=2*xr;
        //if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
    curend= --f;
    
    if (curend>=ar) curend=ar-1;
      
    if(!vam[0]) {
        // ΒΑΦΩ ΑΡΧΙΚΑ //
        if (curst==curend) continue ;
        vam[0]=1;
        
        if (curend<curst) { vam[1]=curend ; vam[2]=curst ; pros=0; curst=vam[1]; curend=vam[2]; }
        else { pros=1 ; vam[1]=curst; vam[2]=curend ; }
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1= pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) { for(i=x1;i<xr-1;i++)  {_putpixel (i,f); }}refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
    
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f); } f++ ;}
        }
        refresh();continue ;}
        
        if (pros) {
        
        if (curend>vam[2]) {
       
       // Βάφω από vam[2] έως νέο curend //
             setcolor (COLOR (epr,epg,epb));  
       for (a=vam[2]+1; a<=curend; a++) {
       what=str[a];
       x1=pos[a][0] ; y1= pos[a][1] ;
      
       if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh(); continue ;}
       mem_int=gouv[what].where ;
       for(f=0; f<gouv[what].hei ; f++) {
       for(i=0;i<gouv[what].wid;i++) {
       co.lor = *mem_int++;
       if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
  
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
        }   
       vam[2]=curend; vam[0]=1;
       refresh();continue ;}
            
     if ((curend<vam[2]) && (curend>vam[1])) {
           //ξεβάφω MONON.. //
          setcolor (COLOR (bkr,bkg,bkb));  
        for (a=curend; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
       
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
         
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[2]=curend;
        vam[0]=1;
        refresh();continue ;
    }       
    
    if (curend<=vam[1]) {
        
    // Ξεβάφω από vam[1] έως vam[2] //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }       
        
        if (curend==vam[1])  {vam[0]=0 ; curst=curend ; refresh(); continue ;}
        vam[2] = curst ; vam[1]=curend ; pros=0; vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        curst=vam[1] ; curend=vam[2];
        continue ;}}
        else {
        // Από εδώ και πέρα σημαίνει pros=0 //
        
        if (curend<curst) {
            // Βάφω από curend έως vam1 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=curend; a<=vam[1]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
       
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        vam[1]=curend; curst=vam[1];vam[0]=1;continue;}
        
        if ( (curend>vam[1]) && (curend<vam[2]) ) {
        //ξεβάφω MONON.. //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<curend; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }            
        refresh(); vam[1]=curend ; curst=vam[1]; continue; }
        
        if (curend >= vam[2]) {
        // Ξεβάφω από vam1 έως vam2 //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }
        
        if (curend==vam[2]) {curst=curend ; vam[0]=0 ; continue ; }
        
        vam[1]=vam[2]; vam[2]=curend; curst=vam[1]; pros=1;vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
      
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();continue;}}       
        
    }  while (!pev || sdlev.type!=SDL_MOUSEBUTTONUP) ;
DIPLO_KL:
    cur = curst;
    if ( (!vam[0]) && (cur==ar-1) && (chb) ) cur=ar ;
    if (vam[0]) {
    // ENHMEVSH pre_cur !!!
    blosta=-1 ; bloend=-1; blo_pre_cur=0;
    f=vam[1];
    if (f) {    while (pos[f][1]>yt) f--;
                  while (pos[f][0]!=xl) f--;
                  pre_cur=f;
            } else pre_cur=0;}
    x=pos[cur][0] ; y=pos[cur][1];
    continue;}
    
    // Right Click Menu !!                            Right Click Menu !!    
    
    else if (sdlev.button.button==SDL_BUTTON_RIGHT) { 
        
        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
        
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            f=cur;
        if (f) {
            while (pos[f][1]!=yt) f--;
            while (pos[f][0]!=xl) f--;
            ano_ar=f; } else ano_ar=cur;
            
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; cur_ghost=0;
    }
        
         
        if (fnd_but) {
            if (!ar) {fnd_but=0; puticon(xr-36,yt-20,mem_find,255); continue ;}
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            if (keyb_gr) {ton=0 ; dial=0 ;}
            convertinp_strstr  (1, str, arped, &how_many, &cur_ghost);
            ghost=inp_mem_ghost;
            if (!ghost)  {
                if (!how_many) {
                    if (keyb_gr) information (0,"Δεν βρέθηκε τίποτε !",0);
                    else information(0,"Nothing found !",0);
                    }
                continue ; }
            if (keyb_gr) sprintf(str1024,"Προέκυψε ταύτιση σε %d σημεία!", how_many);
            else sprintf(str1024,"Identity occurred in %d points!", how_many);
            information (0,str1024,0);
            if (vam[0]) {                              // ξεβάφω
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;pre_cur=0;
            }
            cur=cur_ghost;
            y=pos[cur][1];
            x=pos[cur][0]; 
            if (cur) {
                f=0;
                while (pos[cur-f][0] !=xl)  f++;
                diaf3=pos[cur-f][1]-yt;
                for (i=0;i<=ar;i++) pos[i][1]-=diaf3;
                ano_ar=cur-f;
                }
            else ano_ar=0;
            x=pos[cur][0] ; y=pos[cur][1]; 
            setcolor (COLOR(bkr,bkg,bkb));  
            for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
            refresh();
            
            for (a=ano_ar; a<ar; a++) {
                what=str[a];
                if (what==200) continue ;
                y1=pos[a][1];
                if (y1>=ektos) break ;
                x1=pos[a][0];
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) {
                    if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                    else continue ;
                }

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                _putpixel(x1+i , y1+f);}}
                if (ghost[a]) {
                    while (f<bh) {
                    setrgbcolor(selred);
                    for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                }
            }
            refresh();
            
            goto barovios ;
        }
      
        
         if (!diak) {
        getimage(x,y,x+1,y+bh-1,mem_cu);   
        diak=1;
        setrgbcolor(col_cu); 
        for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
        _putpixel(x+i,y+f) ;} }
        refresh() ; 
                        }
                           
         if ( (!vam[0]) && (ar) ) {
         what=str[cur];
         if (what<164) {
         setcolor (COLOR (epr,epg,epb));  
         mem_int=gouv[what].where ;
         for(f=0; f<gouv[what].hei ; f++) {
         for(i=0;i<gouv[what].wid;i++) {
         co.lor = *mem_int++;     
         if (! co.lor) _putpixel(x+i , y+f);}}
         while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
         } }
         
        if (keyb_gr) {ton=0 ; dial=0 ;}
       
        mx = sdlev.button.x ; my= sdlev.button.y ;
        if (mx<= info.left) mx=info.left+1;
        if (my<= info.top) my=info.top+1;
        size=imagesize (0,0,181,259);
        mem_undrme=malloc(size);
        if (mem_undrme==NULL) {printf ("Memory Problem \n") ; continue ;}
        x2= ((mx+180)<info.right) ? mx : info.right-181;
        y2= ((my+258)<info.bottom-40) ? my : info.bottom-299 ;
        getimage (x2-1,y2-1,x2+180,y2+258,mem_undrme);
        // ZVGRAFIZEI MENU
        start=0;
        _areacls (x2-1,y2-1,x2+180,y2+240,180,180,180);
        setrgbpalette(18,180,180,180); // Color of area behind circles = 18
        setrgbpalette(20,128,255,0); // Light Green = 20
        _bareacls (x2-1,y2+241,x2+180,y2+258,cbrown);
        //putimage(x2,y2,mem_rmenu,0);
        // My putimage
         mem_int=(mem_rmenu +8);
        for (f=0;f<240;f++) {
           for(i=0 ; i < 180; i++) {
        co.lor= *(mem_int++);
        if (co.rgb[3]) {setcolor(COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
         
        _putpixel (x2+i,y2+f);}}} 
        refresh(); 
        rmed[11]=0;
        rmed[0] = (ar) ? 0 : 1 ;
        rmed[1] = ( (orio==ar) && (!vam[0]) ) ? 1 : 0 ;
        rmed[2] = (savefile[0]=='\0') ? 1 : 0 ;
        rmed[5]=1;
        if (vam[0]) {
            rmed[3] = rmed[4] = 2;
            rmed[5]=0; blosta=-1 ; bloend=-1; blo_pre_cur=0;
                        }
        else        {
            rmed[3] = (ar) ? 0 : 1;
            rmed[4] = ( (blosta<0) || (cur<=blosta) ) ? 1 : 0 ;
                       }
            
        if ((blosta>=0) && (bloend>blosta)) rmed[5]=0 ;
        
        rmed[6] = ( (vam[0]) || (!rmed[5]) ) ? 0 : 1 ;
        rmed[7] = (SDL_HasClipboardText()) ? 0 : 1 ;
        if (!rmed[7]) rmed[7] = ( (orio==ar) && (!vam[0]) ) ? 1 : 0 ;
        rmed[8] = (ar) ? 0 : 1;
        rmed[9] = (undo) ? 0 : 1;
        rmed[10] = (ar) ? 0 : 1 ;
        kyk1=-1; outmen=1;
        esc_go=0;
        
        SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
        do {
        SDL_PollEvent(&sdlev);
        if (sdlev.type!=SDL_MOUSEMOTION && sdlev.type!=SDL_KEYDOWN) continue;
        if ( (secwin) && (sdlev.motion.windowID == sdlwin2) ) { continue ;}
        mx=sdlev.motion.x ; my=sdlev.motion.y;
        SDL_FlushEvent(SDL_MOUSEMOTION);
        if ( sdlev.type==SDL_KEYDOWN ) {
            if (sdlev.key.keysym.scancode==SDL_SCANCODE_ESCAPE ) {mx=x2+170;my=y2+230; esc_go=1;}
            else continue ;}
        if (mx>x2 && mx<x2+180 && my>y2 && my < y2+240 ) {
        if (outmen) {
        outmen=0;
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);}
        x1=(mx-x2)/60;
        y1=(my-y2)/60;
        kyk=(y1*3) + x1 ;
        
        if (!start) {
        setrgbcolor(10+rmed[kyk]);
        mem_efedr1 = mem_rmenu+8+ (y1*43200)+ (x1*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
           
        if ((*mem_int++)) continue;
        _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
        refresh();
        kyk1=kyk;
        x3=x1 ; y3 = y1 ;
        start=1;
        if (keyb_gr) outsouv_col (x2+1,y2+241,rmestrgr[kyk],1,chrpnt[rmed[kyk]],cbrown);
        else outsouv_col (x2+1,y2+241,rmestren[kyk],0,chrpnt[rmed[kyk]],cbrown);
        continue ;}
        
        if (kyk==kyk1) continue ;
        //EPANAFEREI XRVMA EPILOGHS
        setrgbcolor (18); 
        mem_efedr1 = mem_rmenu+8+(y3*43200)+ (x3*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
        if ((*mem_int++)) continue;
        _putpixel (x2+x3*60+i-1,y2+y3*60+f-1);}}
        _bareacls (x2-1,y2+241,x2+180,y2+258,cbrown);
        
        // XRVMATIZEI NEA EPILOGH
        kyk1=kyk ; x3=x1 ; y3 = y1 ;
        setrgbcolor (10+rmed[kyk]);
        mem_efedr1 = mem_rmenu+8+(y1*43200)+ (x1*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
        if ((*mem_int++)) continue;
        _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
        if (keyb_gr) outsouv_col (x2+1,y2+241,rmestrgr[kyk],1,chrpnt[rmed[kyk]],cbrown);
        else outsouv_col (x2+1,y2+241,rmestren[kyk],0,chrpnt[rmed[kyk]],cbrown);
        refresh();
        continue ;    
        }
        else {
       
        if (start) {
        setrgbcolor(18);
        mem_efedr1 = mem_rmenu+8+(y3*43200)+ (x3*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
        if ((*mem_int++)) continue;
        _putpixel (x2+x3*60+i-1,y2+y3*60+f-1);}}
        bareacls (x2-1,y2+241,x2+180,y2+258,cbrown);
        start=0; kyk1=-1;} 
        if (outmen) continue;
        outmen=1;
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
        SDL_SetCursor(cursor);
        continue ;   
        }
        
        
        } while ( (sdlev.type !=SDL_MOUSEBUTTONDOWN || (outmen) ) && (!esc_go) ) ;

       
        
        if( (sdlev.button.button==SDL_BUTTON_RIGHT) || (esc_go) ) { putimage (x2-1,y2-1,mem_undrme,0);
         if ( (!vam[0]) && (ar) ) {
         what=str[cur];
         if (what<164) {
         setcolor (COLOR (bkr,bkg,bkb));  
         mem_int=gouv[what].where ;
         for(f=0; f<gouv[what].hei ; f++) {
         for(i=0;i<gouv[what].wid;i++) {
         co.lor = *mem_int++;
         if (! co.lor) _putpixel(x+i , y+f);}}
         while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
         } }        
        free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
        SDL_SetCursor(cursor); continue;}
        else if (sdlev.button.button==SDL_BUTTON_LEFT) {
            
            auto int pev ;
            
            switch (kyk) {
                
                case 0: 
                    
                    // Save as file with ZENITY -  Save as
                    if (!ar) break ;
                    
                    if (savefile[0]=='\0') sprintf (file_2,"%s%s",user_path,eggr_str);
                    else {
                        i=strlen(savefile);
                        while (savefile[i]!='/' && (i) ) i--;
                        for (f=0;f<=i && f<255;f++) file_2[f]=savefile[f];
                        file_2[f]='\0';
                    }
                    if (keyb_gr) strcpy (file_1,"Eπιλέξτε και ΣΩΣΤΕ");
                    else strcpy (file_1,"Choose and SAVE");
                    //sprintf(savefile,"zenity --file-selection --save --title=%s --filename=%s --file-filter='*.inp' --confirm-overwrite > %s%s",file_1,file_2,path_name,"zenity.txt");
                    //system(savefile);
                    //refresh();
                    //sprintf (savefile,"%s%s",path_name,"zenity.txt");
                    //fp = fopen(savefile,"r");
                    //if (fp==NULL) {savefile[0]='\0'; break;}
                    
                    if (!fsel_code) { savefile[0]='\0'; break;}
                    
                    switch (fsel_code) {
                        
                                                    
                        case 1 : //yad
                            sprintf (big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.inp --center --width=%d --height=%d",efarm_path,file_1,file_2,(int) (2*DM.w/3) , (int) (2*DM.h/3) ) ;
                            break ;
                            
                        case 2 : //kdialog
                            sprintf (big_char,"%s --getsavefilename %s",efarm_path,file_2);
                            break;
                            
                        case 3 : //zenity
                            sprintf(big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.inp",efarm_path,file_1,file_2);

                    }
                    
                    

                    f = fileselector( big_char, savefile , 512);
                    if (!f) { savefile[0]='\0'; break;}
                    
                    diaf1=strlen(savefile); 
                    if ( (!diaf1)  || (diaf1>507) ) {savefile[0]='\0'; break;}
                    
                    for (f=1;f<diaf1;f++) {
                    if (savefile[f]!='.') continue ;
                    else {for (a=f ; a<diaf1 ; a++) savefile[a]='\0';}
                    break;}
                    
                    strcat(savefile,".inp");
                                        
                    mem_efedr2=str;
                    fp=fopen(savefile,"wb");
                    if (fp==NULL) {savefile[0]='\0'; break;}
                    fide_fp = fileno (fp) ;
                    fwrite (pedaba,4,4,fp);
                    fwrite (&ar,2,1,fp);
                    fwrite (mem_efedr2, ar,1, fp);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =0 ; y1 = 0;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp);
                    break ;
                
                case 1:
                    // LOAD FILE with Zenity !!
                    
                    // Ενεργοποίηση UNDO
                    if (ar) {
                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
                        
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                        undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    }
                    
                    if (vam[0]) {                              // αναδιατάσσω εσωτερικά το str
                    vam[0]=2;
                    for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                    diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                    cur=vam[1];
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    }
                    if(!ins) elxor=orio-ar; else elxor=orio-cur;
                    if (!elxor) break ;
                                                        
                    mem_efedr1=malloc(1024);
                    if (mem_efedr1==NULL) {printf ("Out of Memory"); break;}
                    loadfile=mem_efedr1;
                    
                    if (savefile[0]=='\0') sprintf (file_2,"%s%s",user_path,eggr_str);
                    else {
                        i=strlen(savefile);
                        while (savefile[i]!='/' && (i) ) i--;
                        for (f=0;f<=i && f<255;f++) file_2[f]=savefile[f];
                        file_2[f]='\0';
                    }
                    if (keyb_gr) strcpy (file_1,"Eπιλέξτε και ΦΟΡΤΩΣΤΕ");
                    else strcpy (file_1,"Choose and LOAD");
                    
                    //sprintf(loadfile,"zenity --file-selection --title=%s --filename=%s > %s%s",file_1,file_2, path_name,"zenity.txt");
                    //system(loadfile);
                    //refresh();
                    //sprintf (loadfile,"%s%s",path_name,"zenity.txt");
                    //fp = fopen(loadfile,"r");
                    //if (fp==NULL) {free (mem_efedr1) ; break;}
                    //f=0;
                    //do {
                    //loadfile[f]= (char) getc(fp);
                    //f++;
                    //}while ( (!feof(fp)) && (f<512) );
                    //fclose(fp);
                    //if (f<3) {free(mem_efedr1) ; break;}
                    //f-=2; loadfile[f]='\0';
                    if (!fsel_code) { free(mem_efedr1) ; break; }
                    
                    switch (fsel_code) {
                        case 1 : //yad
                            sprintf (big_char,"%s --file-selection --title=\"%s\" --filename=%s --center --width=%d --height=%d",efarm_path,file_1,file_2,(int) (2*DM.w/3) , (int) (2*DM.h/3) ) ;
                            break ;
                            
                        case 2 : //kdialog
                            sprintf (big_char,"%s --getopenfilename %s",efarm_path,file_2);
                            break;
                            
                        case 3 : //zenity
                            sprintf(big_char,"%s --file-selection --title=\"%s\" --filename=%s",efarm_path,file_1,file_2);
                     }

                    f = fileselector( big_char, loadfile , 1024);
                    if (!f) { free(mem_efedr1) ; break; }
                    
                    diaf2=strlen(loadfile);
                    if ( !diaf2 ) {free(mem_efedr1) ; break;}
                   
                    file_flag=0;
                    fp=fopen(loadfile,"rb");
                    if (fp==NULL) {free (mem_efedr1) ; break;}
                    for (f=0 ; f<4 ; f++) {
                    fread(&pedaca,4,1,fp);
                    if (feof(fp)) { file_flag=1; break; }
                    if (pedaca!=pedaba[f]) {file_flag=1;break;}}
                    
                    if (!ins) {
                        for(f=ar,i=0;f>=cur;f--,i++) str[orio-i]=str[f];
                        diaf1=orio-i+1;}
                        
                          // Προσδιορισμός του Pre_Paste
            
                    if (!pre_cur) {
                    f=cur;
                    if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                    } else pre_paste=0;} 
                   else pre_paste=0;
                    
                    a=0;
                    if (!file_flag) {
                    // It is rather an .inp file - ok !!
                    strcpy(savefile,loadfile);
                    fread(&diaf2,2,1,fp);
                    cha=0;
                    do {
                        if (feof(fp)) break;
                        fread(&what,1,1,fp);
                        if ( what>=0 && what<164 ) cha=1;
                        if ( what==200 || (cha) ) {str[cur+a]=what;
                        diaf2-- ; a++ ; elxor-- ;cha=0;}
                        else break;
                    } while ( (diaf2) && (elxor) );
                    }
                    else
                    {                       
                    // It is not an .inp file - May be it is a text file ....
                    if (ferror(fp)) clearerr(fp);
                    fclose (fp);
                    fp=fopen(loadfile,"r");
                    //user_ans=(keyb_gr) ? alert(3,NULL,NULL) : alert(4,NULL,NULL);
                    if (fp!=NULL) {
                    fread(&ch,1,1,fp);
                    
                    while ( (ch!='\0') && (elxor) ) {
                    if (feof(fp)) break;
                    
                    if ( ch<0) {
                    if (keyb_gr){
                    fread(&cha,1,1,fp);
                    if (feof(fp)) break;
                    ch1= ( (256*ch) + cha ) ;
                    for (i=0 ; i<69 ; i++) {
                        if (ch1==unico[i][0]) {
                            str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                            if (i==69) {str[cur+a]=0; a++;elxor--;ch=cha;continue;}
                    fread(&ch,1,1,fp); continue;}
                    else {str[cur+a]=0; a++;elxor--;fread(&ch,1,1,fp); continue;}}
                    
                    else {
                    if (ch=='\n') {str[cur+a]=200; a++;elxor--; fread(&ch,1,1,fp); continue;}
                    for(i=0;i<95;i++) {
                        if (ch==gouv[i].who) {
                            str[cur+a]=i ; a++ ; elxor-- ;break;}}
                            if (i==95) {str[cur+a]=0; a++;elxor--;}
                    fread(&ch,1,1,fp);
                  } } 
                        
                    }}
                    if (fp!=NULL) {
                        if (ferror(fp)) {printf ("Disk Error \n"); clearerr(fp);}
                        fclose (fp);
                    }
                    if (!ins) ar +=a ; else {
                    if (cur+a > ar) ar=(cur+a); }
                    str[ar]=255;
                    if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
                 
                    free(mem_efedr1) ;
                    putimage (x2-1,y2-1,mem_undrme,0);
                    free(mem_undrme);
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);
                   
                    if (vam[0]==2) vam[0]=0;
                    goto esot_anadiat;
                                   
                case 2: // Save ..
                    if (rmed[2]) {
                        information(8-keyb_gr,NULL,NULL);
                        break;}
                    user_ans = alert(0,"Save data to :",savefile);
                    if (user_ans !=1) break;
                    clipbo = strstr(savefile,".inp");
                    if (clipbo!=NULL) {
                    mem_efedr2=str;
                    fp=fopen(savefile,"wb");
                    if (fp==NULL) {savefile[0]='\0'; break;}
                    fide_fp = fileno (fp) ;
                    fwrite (pedaba,4,4,fp);
                    fwrite (&ar,2,1,fp);
                    fwrite (mem_efedr2, ar,1, fp);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =2 ; y1 = 0;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp); break;}
                    else {
                    clipbo=strstr(savefile,".txt");
                    if (clipbo!=NULL) {
                    size=1024;        
                    clipbo=malloc(size);
                    if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; } 
                    fp=fopen(savefile,"w");
                    if (fp==NULL) {savefile[0]='\0'; free(clipbo); break;}
                    fide_fp = fileno (fp) ;
                    i=0;
                    for (f=0 ; f<ar ; f++) {
                    if (i>=size-4) {
                            size+=1024;
                            remem=realloc(clipbo,size);
                            if (!remem) {if(clipbo) free(clipbo);}
                            clipbo=remem;
                            if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; }
                    }
                    what=str[f];
                    if (what<95) {clipbo[i++]=gouv[what].who;}
                    else if ( (what>94) && (what<164) ) {
                        cha=((unico[what-95][0]/256)-255);
                        chb = (unico[what-95][0] % 256);
                        clipbo[i++]=cha; clipbo[i++]=chb;}
                        //putc(cha,fp); putc(chb,fp);}
                      
                       else if (what==200) {clipbo[i]='\0'; fprintf (fp,"%s\n",clipbo); i=0; }                    
                    } 
                    if (i) {clipbo[i] ='\0'; fprintf (fp,"%s",clipbo);}
                    free(clipbo);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =2 ; y1 = 0;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp);                    
                    break ;}
                    savefile[0]='\0';
                    break ;}
                    
                                        
                case 3: // ΑΡΧΗ ΜΠΛΟΚ
                    if (rmed[3]) {
                        if (vam[0]) { information(12-keyb_gr,NULL,NULL); }
                        break;}
                    if (bloend>0) {
                        if (cur>=bloend) {blosta=-1 ; bloend=-1 ; blo_pre_cur=0; break ;}}
                    f=blosta=cur;
                // ENHMEVSH blo_pre_cur !!!
                    
                    if (f) {    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    blo_pre_cur=f;
                            } else blo_pre_cur=0;
                     x1 =0 ; y1 = 1;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                            
                    break;
                    
                case 4: //ΤΕΛΟΣ ΜΠΛΟΚ
                     if (rmed[4]) {
                          if (vam[0]) { information(12-keyb_gr,NULL,NULL); }
                          else if (blosta==-1) { information(10-keyb_gr,NULL,NULL); }
                         break;}
                     bloend= (cur==ar) ? cur-1 : cur ;
                     if (bloend<0) bloend=0;
                     vam[0]=1;vam[1]=blosta;vam[2]=bloend;pre_cur=blo_pre_cur;
                     blosta=-1 ; bloend=-1 ; blo_pre_cur=0;
                     
                     //PRASINO XROMA
                     x1 =1 ; y1 = 1;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                        
                     putimage (x2-1,y2-1,mem_undrme,0);
                    free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);
                    // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    setcolor (COLOR (epr,epg,epb));  
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1=pos[a][1] ;
                    if (y1<yt) continue ;
                    if (y1>=ektos) break ;
                    what=str[a];
                    x1=pos[a][0] ; 
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                    refresh();
                    continue;
                    break ;
                
                case 5: // DIAGRAFH DELETE BLOCK
                if (rmed[5]) {
                     if (!vam[0]) { information(14-keyb_gr,NULL,NULL); }
                    break;}

                // Ενεργοποίηση UNDO
                if (ar) {
                undo_lasfile++;
                sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                fpundo=fopen(file_1,"wb");
                if ( fpundo!=NULL ) {
                fide_undo = fileno (fpundo) ;
                undo=1;
                f=cur;
                if (f) {while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    wherp = f;} else wherp = 0;
                fwrite (&cur,2,1,fpundo);
                fwrite (&ar,2,1,fpundo);
                fwrite (str,1,ar,fpundo);
                fwrite(vam,2,3,fpundo);
                fwrite (&wherp,2,1,fpundo);
                fwrite(&pre_cur,2,1,fpundo);
                fwrite(&ins,2,1,fpundo);
                fwrite(&gr_flag,2,1,fpundo);
                fwrite(savefile,1,512,fpundo);
                fwrite (pxl,4,1,fpundo);
                fwrite (pyt,4,1,fpundo);
                fwrite (pxr,4,1,fpundo);
                fwrite (pyb,4,1,fpundo);
                fwrite (&orio,4,1,fpundo);
                if (ferror(fpundo)) { 
                    clearerr(fpundo); fclose(fpundo);
                    undo_lasfile--;
                    if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                }
                else {
                fdatasync (fide_undo);
                fsync (fide_undo);
                fclose(fpundo);
                    if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}

                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                        undo_firfile++;}
                    }
                }
                else {
                    undo_lasfile--;
                    if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                }
                }
                
                x1 =2 ; y1 = 1;
                setrgbcolor(20);
                mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                for (f=0;f<59;f++) {
                mem_int=(mem_efedr1+(f*720));
                for (i=0;i<59;i++) {
                if ((*mem_int++)) continue;
                _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                    refresh(); 
                putimage (x2-1,y2-1,mem_undrme,0);
                free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                SDL_SetCursor(cursor);                         
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                cur = (vam[1]) ? vam[1]-1 : 0 ;
                goto esot_anadiat;  
                                    
                case 6: // Copy to Clipboard
                     if (rmed[6]) break;
                     x1 =0 ; y1 = 2;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                     putimage (x2-1,y2-1,mem_undrme,0);
                    free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);                         
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    size=0;
                    for (f=vam[1] ; f<=vam[2] ; f++) {
                        what=str[f];
                        if (what<95) size++;
                        else if ( (what>94) && (what<164) ) size+=2;
                        else size++; }
                        size++;
                        clipbo=malloc(size);
                        if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                        a=0;
                        for (f=vam[1] ; f<=vam[2] ; f++) {
                        what=str[f];
                        if (what<95) {
                            clipbo[a]=gouv[what].who; a++;}
                        else if ( (what>94) && (what<164) ) {
                            cha=((unico[what-95][0]/256)-255);
                            chb = (unico[what-95][0] % 256);
                            clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                        else if (what==200) {clipbo[a]='\n' ; a++;}}
                        clipbo[a]='\0';
                        size=SDL_SetClipboardText(clipbo);
                        if (!size) {
                        
                        setcolor (COLOR (epr1,epg1,epb1));  
                            for (a=vam[1]; a<=vam[2]; a++) {
                            y1=pos[a][1] ;
                            if (y1<yt || y1>=ektos) continue;
                            what=str[a];
                            x1=pos[a][0] ; 
                            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
                            mem_int=gouv[what].where ;
                            for(f=0; f<gouv[what].hei ; f++) {
                            for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                            refresh();
                        } 
                        free(clipbo);
                        continue;
                                       
                case 7: // Paste from Clipboard
                     if (rmed[7]) break;
                     if (!SDL_HasClipboardText()) break;
                     clipbo=SDL_GetClipboardText();
                    if (clipbo==NULL) break;
                    
                    // PRASINO XROMA
                    x1 =1 ; y1 = 2;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh();                    

                    // Ενεργοποίηση UNDO
                    if (ar) {
                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                                // Τσεκάρω για snapshot...
                            strcpy(file_2,user_path);
                            strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                            fpundo=fopen(file_2,"rb");
                            if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
 
                            a=undo_lasfile-undo_max;
                            sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                            rename (file_1,file_2);
                            undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    }
                        
                    putimage (x2-1,y2-1,mem_undrme,0);
                    if (!vam[0]) {
                    what=str[cur];
                    if (what<164) {
                    setcolor (COLOR (bkr,bkg,bkb));  
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (! co.lor) _putpixel(x+i , y+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
                    } }   
                    free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);     

                    if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    setcolor (COLOR (bkr,bkg,bkb));  
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ; 
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    vam[0]=2;
                    // Εσωτερική Αναδιάταξη !
                    cur = vam[1] ;
                    for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                    diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                    }
                    
                    if(!ins) elxor=orio-ar; else elxor=orio-cur;
                    if ( (!elxor) && (!vam[0]) ) {SDL_free(clipbo); continue;} 
                    if (vam[0]==2) vam[0]=0;
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    if (!ins) {
                        for(f=ar,i=0;f>=cur;f--,i++) str[orio-i]=str[f];
                        diaf1=orio-i+1;}
                        
                                 // Προσδιορισμός του Pre_Paste
            
                    if (!pre_cur) {
                    f=cur;
                    if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                } else pre_paste=0;} 
                   else pre_paste=0;
                        
                    f=0 ; a=0 ;
                    ch=clipbo[f];
                    while ( (ch!='\0') && (elxor) ) {
                        if (ch<0) {
                            
                            f++ ; ch1= ( (256*ch) + clipbo[f] ) ;
                            for (i=0 ; i<69 ; i++) {
                                if (ch1==unico[i][0]) {
                                    str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                                    if (i==69) {str[cur+a]=0 ; a++ ; elxor--; f--; }
                            f++; ch=clipbo[f];continue;
                         }
                        else {
                            if (ch=='\n') {str[cur+a]=200; a++;elxor--; f++; ch=clipbo[f]; continue;}
                            for(i=0;i<95;i++) {
                                if (ch==gouv[i].who) {
                                    str[cur+a]=i ; a++ ; elxor-- ;break;}}
                                    if (i==95) {str[cur+a]=0 ; a++ ; elxor--;}
                            f++;ch=clipbo[f];
                            }
                    }
                    if (!ins) ar +=a ; else {
                        if (cur+a > ar) ar=(cur+a); }
                     if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
                    SDL_free(clipbo);
                    goto esot_anadiat;
                    
                case 8: // Save as .txt
                    if (!ar) break ;
                    
                    if (savefile[0]=='\0') sprintf (file_2,"%s%s",user_path,eggr_str);
                    else {
                        i=strlen(savefile);
                        while (savefile[i]!='/' && (i) ) i--;
                        for (f=0;f<=i && f<255;f++) file_2[f]=savefile[f];
                        file_2[f]='\0';
                    }
                    if (keyb_gr) strcpy (file_1,"Eπιλέξτε και ΣΩΣΤΕ");
                    else strcpy (file_1,"Choose and SAVE");
                    //sprintf(savefile,"zenity --file-selection --title=%s --filename=%s --file-filter='*.txt' --save --confirm-overwrite > %s%s",file_1,file_2,path_name,"zenity.txt");
                    //system(savefile);
                    //refresh();
                    //sprintf (savefile,"%s%s",path_name,"zenity.txt");
                    //fp = fopen(savefile,"r");
                    //if (fp==NULL) {savefile[0]='\0'; break;}
                    //f=0;
                    //do {
                    //savefile[f]= (char) getc(fp);
                    //f++;
                    //}while ( (!feof(fp)) && (f<510) );
                    //fclose(fp);
                    //if (f<3) {savefile[0]='\0'; break;}
                    //f-=2; savefile[f]='\0';
                    if (!fsel_code) { savefile[0]='\0'; break;}
                    switch (fsel_code) {
                        case 1 : //yad
                            sprintf (big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.txt --center --width=%d --height=%d",efarm_path,file_1,file_2,(int) (2*DM.w/3) , (int) (2*DM.h/3) ) ;
                            break ;
                            
                        case 2 : //kdialog
                            sprintf (big_char,"%s --getsavefilename %s",efarm_path,file_2);
                            break;
                            
                        case 3 : //zenity
                            sprintf(big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.txt",efarm_path,file_1,file_2);

                    }

                    f = fileselector( big_char, savefile , 512);
                    if (!f) { savefile[0]='\0'; break;}
                    
                    diaf1=strlen(savefile); 
                    if ( (!diaf1)  || (diaf1>507) ) {savefile[0]='\0'; break;}
                    for (f=1;f<diaf1;f++) {
                    if (savefile[f]!='.') continue ;
                    else {for (a=f ; a<strlen(savefile) ; a++) savefile[a]='\0';}
                    break;}
                    
                    strcat(savefile,".txt");
                    size=1024;        
                    clipbo=malloc(size);
                   
                    if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; } 
                    fp=fopen(savefile,"w");
                    if (fp==NULL) {savefile[0]='\0'; free(clipbo); break;}
                    fide_fp = fileno (fp) ;
                    i=0;
                    for (f=0 ; f<ar ; f++) {
                    if (i>=size-4) {
                            size+=1024;
                            remem=realloc(clipbo,size);
                            if (!remem) {if(clipbo) free(clipbo);}
                            clipbo=remem;
                            if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; }
                    }
                    what=str[f];
                    if (what<95) {clipbo[i++]=gouv[what].who;}
                    else if ( (what>94) && (what<164) ) {
                        cha=((unico[what-95][0]/256)-255);
                        chb = (unico[what-95][0] % 256);
                        clipbo[i++]=cha; clipbo[i++]=chb;}
                        //putc(cha,fp); putc(chb,fp);}
                      
                       else if (what==200) {clipbo[i]='\0'; fprintf (fp,"%s\n",clipbo); i=0; }                    
                    } 
                    if (i) {clipbo[i] ='\0'; fprintf (fp,"%s",clipbo);}
                    free(clipbo);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =2 ; y1 = 2;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp);
                    break ;                   
                               
                case 9: // Undo
                        i=0;
                    if (!undo) {
                        strcpy(file_1,user_path);
                        strcat(file_1,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_1,"rb");
                        if (fpundo!=NULL) {
                        if (keyb_gr) user_ans=alert(0,"Δεν έχει σωθεί στιγμιότυπο για επαναφορά !" ,"Υπάρχει όμως ένα παλαιότερο - ίσως άσχετο. Θέλετε να φορτωθεί ;");
                        else user_ans=alert(0,"There is not a relative snapshot !","There is an older snapshot - perhaps irrele-  vant. Do you want to try it ?");
                        fclose(fpundo);
                        if (user_ans!=1) break ;
                        i=1;
                        }
                        else {information(24-keyb_gr,0,0);break;}
                    }
                    undo=2+i;
                    putimage (x2-1,y2-1,mem_undrme,0);
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    free(mem_undrme);
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter); free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);
                    free(mem_bar);
                    free(mem1);
                    refresh();
                    ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);
                    if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; cur_ghost=0;}
                    langex = (us_flag) ? 1 : 2 ;
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS LOGV UNDO !!!
                                        
                case 10: // Delete All
                    if (!ar) break;
                    
                    // Ενεργοποίηση UNDO

                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
   
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                        undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    
                    
                     // PRASINO XROMA
                    x1 =1 ; y1 = 3;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh();          
                        
                    putimage (x2-1,y2-1,mem_undrme,0);
                    if (!vam[0]) {
                    what=str[cur];
                    if (what<164) {
                    setcolor (COLOR (bkr,bkg,bkb));  
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (! co.lor) _putpixel(x+i , y+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
                    } }        
                        free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                        SDL_SetCursor(cursor);
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    cur=0;ar=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;start=0,pre_paste=0;ton=0 ; dial=0 ;
                    str[cur]=255;
                    blosta = bloend = -1;
                    pos[0][0]=xl ; pos[0][1]=yt;
                    for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                    x1=x =xl ; y1=y=yt;
                    if (bar) { putimage (xr+3,yt-1,mem_bar,0); bar=0; }
                    setcolor (COLOR(bkr,bkg,bkb));  
                    for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                    refresh();
                    if (inp_mem_ghost) { free(inp_mem_ghost); ghost=inp_mem_ghost=0; cur_ghost=0;} 
                    continue ;
                    
                case 11:
                    break ;
                
            }
        
        //SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
        do {pev = SDL_PollEvent(&sdlev);
            if (sdlev.type == SDL_MOUSEBUTTONDOWN) { SDL_FlushEvent(SDL_MOUSEBUTTONDOWN); }
            else break ;
        } while (pev && sdlev.type == SDL_MOUSEBUTTONDOWN );
        
         putimage (x2-1,y2-1,mem_undrme,0);
         if (!vam[0]) {
         what=str[cur];
         if (what<164) {
         setcolor (COLOR (bkr,bkg,bkb));  
         mem_int=gouv[what].where ;
         for(f=0; f<gouv[what].hei ; f++) {
         for(i=0;i<gouv[what].wid;i++) {
         co.lor = *mem_int++;
         if (! co.lor) _putpixel(x+i , y+f);}}
         while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
         } }        
            free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
            SDL_SetCursor(cursor);     
            if (vam[0]==2) {vam[0]=0 ; goto esot_anadiat;}        
        }
                                                                }                                                                                    
              continue ;
             
    case SDL_KEYDOWN:
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        ch_scan=sdlev.key.keysym.scancode;
        ch_mod=SDL_GetModState();
        if (keyb_gr) {
        state=SDL_GetKeyboardState(NULL);
        if ((state[SDL_SCANCODE_RALT] || state[SDL_SCANCODE_LALT]) && (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])) { us_flag=abs (us_flag-1) ; gr_flag=abs(gr_flag-1) ; ton=0; dial=0; 
        if (us_flag) {
            ton=0 ; dial=0 ; putimage(xep+5,yep+4,mem_flusa,0);continue;}
        else {putimage(xep+5,yep+4,mem_flgr,0);
        continue ;}
        }}
        switch (ch_scan) { // Φεύγοντας από την switch με break πάμε για εκτύπωση !!
            
            case SDL_SCANCODE_ESCAPE :  
DROMO:
                f=cur;
                if (f) {while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    diaf1 = f;} else diaf1 = 0;
                    
                if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; }
                if (mem_small) hide_help_inp(hlpxt , hlpyt);
                str[ar]=255; putimage(xl-1,yt-21,mem1,0); putimage(xep,yep,mem_undscr,0);free(mem_undscr); free(mem1) ; free(mem_cu); 
                free(mem_under); free(mem_flusa);  free(mem_enter); free(mem_tent);if (keyb_gr) free(mem_flgr); 
                if (bar) { putimage (xr+3,yt-1,mem_bar,0); refresh(); } 
                if (mem_bar) free(mem_bar);  
                free(mem_rmenu);
                free(mem_find); free(mem_fonter); free(mem_link);
                langex = (us_flag) ? 1 : 2 ;
                free(mem_arrs); free(mem_info); cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                SDL_SetCursor(cursor);refresh() ; ar=0;undo=0; undo_firfile=1; undo_lasfile=0 ;
                cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; return diaf1;
            
            case SDL_SCANCODE_SEMICOLON : //Τόνος για Ελληνικά

                if (!gr_flag) break ;
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME TONO - Περίπτωση διαλυτικών //
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        dial=1 ; continue ;
                    default : ton = 1; continue;}
                    
                    case SDL_SCANCODE_BACKSPACE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                    
                    // Ενεργοποίηση UNDO

                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
                     
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                            undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }

                    
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
                if (inp_mem_ghost) {free(inp_mem_ghost); ghost=inp_mem_ghost=0;}
esot_anadiat:  
                // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ 
                
                x1=xl ; y1=yt;
                for (a=0; a<ar; a++) {
                what=str[a];
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ; x1=xl ; y1+=bh; continue ;}
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) {
                    if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;}
                        x1=xl ; y1+=bh; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 // ΝΕΑ ΕΜΦΑΝΙΣΗ
                //diaf2=cur;
                //if (diaf2) {while (pos [diaf2][0]!=xl) diaf2--;
                //if ( (pos[diaf2][1]-pos[0][1]) >= maxline*bh) {
                //diaf1=(pos[diaf2][1]-yt);
                //for (i=0;i<=ar;i++) pos[i][1]-=diaf1;}
                //else diaf2=0;
                //}
                
                if (pre_cur) {
                f=0;
                while (pos[pre_cur-f][0] != xl) f++;
                pre_cur-=f;
                diaf1=(pos[pre_cur][1]-yt);
                for (i=0;i<=ar;i++) pos[i][1]-=diaf1;}
                else {
                    if (pre_paste) {
                    pre_cur=pre_paste;
                    f=0;
                    while (pos[pre_cur-f][0] != xl) f++;
                    pre_cur-=f;
                    diaf1=(pos[pre_cur][1]-yt);
                    for (i=0;i<=ar;i++) pos[i][1]-=diaf1;}}
                    
                while (pos[cur][1]>=ektos) {
                    f=pre_cur;
                    while (pos[f][1]==yt) f++;
                    pre_cur=f;
                     for (i=0;i<=ar;i++) pos[i][1]-=bh;}
                     
                if (pos[cur][1]<yt) {
                f=cur;
                while (pos[cur][1]<yt) { for (i=0;i<=ar;i++) pos[i][1]+=bh; } 
                while (pos[f][0] != xl) f--;   
                pre_cur=f;}
                    
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                    
                if (what==200) continue ;
                x1=pos[a][0]; y1=pos[a][1];
                if (y1>=ektos) break ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                }
                x=pos[cur][0] ; y=pos[cur][1];
                 refresh();
                pre_cur=0;pre_paste=0;
                goto barovios ;
                }
                
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                    setcolor (COLOR (bkr,bkg,bkb)) ;
                    for (a=ano_ar; a<ar; a++) {
                        if (!ghost[a]) continue ;
                        what=str[a];
                        if (what==200) continue ;
                        y1=pos[a][1];
                        if (y1>=ektos) break ; 
                        x1=pos[a][0];
                        mem_int=gouv[what].where ;
                        for(f=0; f<gouv[what].hei ; f++) {
                            for(i=0;i<gouv[what].wid;i++) {
                                co.lor = *mem_int++;
                                if (!co.lor) _putpixel(x1+i , y1+f);}}
                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                    refresh();
                    free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;
                            
                }
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
               
                if (cur==ar) {
                    what=str[ar-1];
                    x1=pos[ar-1][0] ; y1=pos[ar-1][1] ;
                    pos[ar][0]=pos[ar][1]=-1;
                    if (what!=200 && y1>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x1;i<=x1+gouv[what].wid;i++) { for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}
                    }
                    refresh();
                    x=x1; y=y1;
                    ar--; cur--; str[ar]=255;
                    
                    if (y<yt) {
                        for (f=0;f<=ar;f++) pos[f][1]+=bh;
                        f=0;
                        if (cur) {
                            while ( pos[cur-f][0] != xl ) f++;
                        }
                        
                        for (a=cur-f ; a<ar ; a++) {
                        what=str[a];
                        if (what==200) break ;
                        x1=pos[a][0]; y1=pos[a][1];
                        //if (y1>=ektos) break ;
                        mem_int=gouv[what].where ;
                        for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                        co.lor = *mem_int++;
                        if (!co.lor) continue;

                        // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                        setcolor(COLOR (red,green,blue));
                        _putpixel(x1+i , y1+f);}}
                        }
                        refresh();
                        x=pos[cur][0] ; y=pos[cur][1];
                        }
                    }
                    
                else {
                         
                        x1=pos[cur-1][0]; y1=pos[cur-1][1]; 
                        cur--;
                        for(f=cur;f<ar;f++) str[f]=str[f+1];
                        ar--;
                       
entos_back :
                         // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if ( (y1+bh) >=yt) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                
                secr=(cur) ? 1 : 0 ;                
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];   
                if ( (y1<yt) && (secr) ) {
                    f=0; while (pos[f][1]!=y1) f++;
                    secr=cur-f;
                    //while (pos[cur-secr][1] != xl) secr++;
                    diaf1=abs(pos[cur-secr][1] - yt);
                    pos [cur-secr][1]=yt;
                    x1=xl ; y1=yt;
                    for (f=0 ; f<cur-secr ; f++) pos[f][1]+=diaf1;
                }
                        
                for (a=cur-secr; a<ar; a++) {
                    
                    what=str[a];
                    
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ; x1=xl ; y1+=bh; continue ;}
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) {
                    if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}}
                                            }
                                        }  
                x1=xl ; y1+=bh; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if ( (y1>=ektos) || (y1<yt) ) { x1+=gouv[what].wid; wrap--; continue ; }
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 x=pos[cur][0] ; y=pos[cur][1];
                 if (y<yt) { 
                     while (y<yt) {cur++; y = pos[cur][1] ; }
                     x=pos[cur][0] ; 
                }
                
                }
                goto barovios ;
  
                
                    case SDL_SCANCODE_CAPSLOCK :
                        caps_lock = abs (caps_lock-1) ; 
                        for (f=3;f<29;f++) {
                            mem_int=(mem_under+8+(f*225*4));
                            for(i=48 ; i<84;i++) {
                            co.lor= *(mem_int+i);
                            setcolor ( COLOR ( co.rgb[2] , co.rgb[1] , (co.rgb[0] +caps_lock*100)) );
                             
                            _putpixel (xep+i,yep+f);}} 
                            refresh(); 
                    continue ;
                
                    case SDL_SCANCODE_DELETE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                    
                    // Ενεργοποίηση UNDO

                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
                      
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                            undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    
                    
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
                if (inp_mem_ghost) {free(inp_mem_ghost); ghost=inp_mem_ghost=0;}
                goto esot_anadiat;}
                
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;
                }
                
                                           
                 if (cur==ar) continue ;
                 x1=pos[cur][0] ; y1 = pos[cur][1];
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for(f=cur;f<ar;f++) str[f]=str[f+1];
                 ar--;
                                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                what=str[a];
                
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh; continue ;}
                wrap=0;                
                if ((x1+gouv[what].wid) > xr-2) {
                        if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}}
                                            }
                                        }  
                    x1=xl ; y1+=bh; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if (y1>=ektos) {x1+=gouv[what].wid;wrap--; continue;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;   
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 goto barovios ; 
  
                
                    case SDL_SCANCODE_END :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;pre_cur=0;
                }

                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f<=ar ; f++) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1];
                 continue ;
                
                
                    case SDL_SCANCODE_HOME :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));   
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                 
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 if (!cur) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f>0 ; f--) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = ++f ; if ( (cur==1) && (pos[0][1]==y) ) cur=0;
                 x=pos[cur][0] ; y=pos[cur][1];    
                   continue ;
                
                    case SDL_SCANCODE_HELP :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                   continue ;
                   
                    case SDL_SCANCODE_TAB :
                    tab=1;
                    goto DROMO ;
                
                    case SDL_SCANCODE_INSERT :
                if (keyb_gr) {ton=0 ; dial=0 ;}       
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                  col_cu = (col_cu==99) ? 100 : 99 ;
                  ins=abs(ins-1);
                  for (f=3;f<29;f++) {
                  mem_int=(mem_under+8+(f*225*4));
                          for(i=95 ; i<129;i++) {
                          co.lor= *(mem_int+i-1);
                          setcolor ( COLOR ( co.rgb[2]  , co.rgb[1] , co.rgb[0] +ins*70) );
                          _putpixel (xep+i,yep+f);}} 
                          refresh();
                   continue ;
                  
                    case SDL_SCANCODE_LEFT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 if (!cur) continue ;
                          //ΣΒΗΝΩ CURSOR
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                cur-- ; y=pos[cur][1];
                 if ( y < yt ) {
                     size=imagesize(xl,yt,xr-1,ektos-bh);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                     getimage(xl,yt,xr-1,ektos-bh,mem_power);
                     putimage (xl,yt+bh,mem_power,0); refresh(); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=yt ; f<yt+bh; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]+=bh;
                     a=cur; y1=y=yt;
                     while (pos[a][0] != xl) a--;
                     while (pos[a][1]==y) {
                     what=str[a];
                    if (what==200) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    }
                x=pos[cur][0]; 
                goto barovios ;
                
                    case SDL_SCANCODE_RIGHT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                                  
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 if (cur==ar) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 cur++ ;
                 y=pos[cur][1];
                  if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     a=cur; y1=y=ektos-bh;
                     //while (pos[a][0] != xl) a--;
                     while (pos[a][1]==y && (a<ar) ) {
                     what=str[a];
                    if (what==200 ) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    refresh();
                    }
                x=pos[cur][0]; 
                   goto barovios ;
                
                    case SDL_SCANCODE_UP :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)   _putpixel(x1+i , y1+f);}}
               
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                } 
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                y1=y; x1=x;
                if (y==yt) {
                a=cur;
                while (pos[a][0] > xl) a--;
                if (!a) continue;
                size=imagesize(xl,yt,xr-1,ektos-bh);
                mem_power=malloc(size);
                if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                getimage(xl,yt,xr-1,ektos-bh,mem_power);
                putimage (xl,yt+bh,mem_power,0); free (mem_power);
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<xr;i++) {for (f=yt ; f<yt+bh; f++) _putpixel (i,f);}
                for(i=ar;i>=0;i--) pos[i][1]+=bh;
                a--;
                while (pos[a][0] != xl) a--;
                y1=yt;
                while (pos[a][1]==yt) {
                what=str[a];
                if (what==200) break ;
                x1=pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                x1+=gouv[what].wid;a++;}
                y1=yt+bh;
                x1=pos[cur][0];
                 }
            
            diaf1=2*xr;
                 for(f=cur;f>=0;f--) {if (pos[f][1]!=y1) break;}
                 while (pos[f][1]==y1-bh) {
                     diaf2=abs(pos[f][0]-x1);
                     if (diaf2<diaf1) {diaf1=diaf2;f--;continue;}
                     else break;
                 }
                 cur = ++f;
                 x=pos[cur][0] ; y=pos[cur][1] ;
                 goto barovios ;
                   
                
                    case SDL_SCANCODE_DOWN :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)   _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 x1=x ; y1=y;
                 if (pos[ar][1]==y1) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    if (y==ektos-bh) {
                    size=imagesize(xl,yt+bh,xr-1,yb);
                    mem_power=malloc(size);
                    if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                    getimage(xl,yt+bh,xr-1,yb,mem_power);
                    putimage (xl,yt,mem_power,0); free (mem_power);
                    setcolor (COLOR(bkr,bkg,bkb));  
                    for (i=xl;i<xr;i++) {for (f=y ; f<=yb; f++) _putpixel (i,f);}
                    for(i=ar;i>=0;i--) pos[i][1]-=bh;
                    a=cur;
                    while (pos[a][1]<y) a++;
                    while (pos[a][1]==y && (a<ar) ) {
                    what=str[a];
                    if (what==200 ) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    x1=x;y1-=bh;y=y1;
                    }
                 
                 diaf1=2*xr;
                 for(f=cur;f<=ar;f++) {if (pos[f][1]!=y1)  break;}
                
                 while ( (pos[f][1]==y1+bh) && (f<=ar) ) {
                     diaf2=abs(pos[f][0]-x1);
                     if (diaf2<diaf1) {diaf1=diaf2;f++;continue;}
                     else break;
                 }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1] ;
                 goto barovios ;
                                  
                    case SDL_SCANCODE_PAGEDOWN :
PAGEDOWN :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
               
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 if (pos[ar][1]<ektos ) {cur=ar; x=pos[ar][0]; y=pos[ar][1]; continue ;}
                 
                 
                 f=cur;
                 while (pos[f][1]<ektos) f++;
                 cur=f;
                 for (i=0;i<=ar;i++) pos[i][1]-=(maxline*bh);
                 x1=x=xl; y1=y=yt;
                 // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();
                                  
                if (vam[0]) {                              // βάφω 
                
                        // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setrgbcolor (selpal);  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
                goto barovios ;
                
                    case SDL_SCANCODE_PAGEUP :
PAGEUP :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                if (pos[0][1]==yt) {cur=0; x=xl ; y=yt; continue;}
               
                f=cur;
                while (pos[f][1]>=yt) f--;
                while ( (pos[f][1] >=(yt-maxline*bh)) && (f>=0) ) f--;
                f++; cur=f ;
                diaf1=yt-pos[f][1]; diaf1 /= bh;
                for (i=0;i<=ar;i++) pos[i][1] += (diaf1*bh);
                x1=x=xl ; y1=y=yt;
                // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();

                if (vam[0]) {                              // βάφω 
                       // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setcolor (COLOR (epr,epg,epb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
barovios :
  if ( (!bar) ) {
                    proyt=abs(pos[0][1]-yt) ;
                    metektos = pos[ar][1]- yt - ( (maxline-1)*bh );
                    
                    if ( (!proyt) && (metektos<=0) ) continue ;
                    bar=1;
                    setcolor (COLOR (0,255,0) );  
                    rectangle (xr+3,yt-1,xr+13,yb);
                    setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
                    olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
                    y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
                    y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;
                     if (y1==y2) y2++;
                    bary1=y1 ; bary2=y2;
                    setcolor (COLOR (255,165,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                    refresh();
                    continue ;
                            }
        else
                            {
               proyt1=abs(pos[0][1]-yt) ;
               metektos1 = pos[ar][1]- yt - ( (maxline-1)*bh );
               if ( (!proyt1) && (metektos1<=0) ) {
               putimage (xr+3,yt-1,mem_bar,0);
               bar=0;
                refresh();
               continue ;}
               if (proyt1==proyt && metektos1==metektos) continue;
               proyt=proyt1 ; metektos=metektos1;
               olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
               setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
               y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
               y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;     
                if (y1==y2) y2++;
               bary1=y1 ; bary2=y2;
               setcolor (COLOR (255,165,0) );  
               for (f=xr+4 ; f<xr+13 ; f++) {
                    for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                refresh();
                            }
                 continue;                

                    case SDL_SCANCODE_V :  //PASTE
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME V 
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                        {                        
      
 // ΑΝΤΙΓΡΑΦΩ ΟΣΑ ΕΠΙΤΡΕΠΕΤΑΙ ΑΠΟ ΤΟ SYSTEM CLIPBOARD αναλόγως του insert //
        if (!SDL_HasClipboardText()) continue;
        if ( (orio==ar) && (!vam[0]) ) continue ;
        clipbo=SDL_GetClipboardText();
        if (clipbo==NULL) continue;
        
           
        // Ενεργοποίηση UNDO
        if (ar) {
        undo_lasfile++;
        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
        fpundo=fopen(file_1,"wb");
        if ( fpundo!=NULL ) {
        fide_undo = fileno (fpundo) ;
        undo=1;
        f=cur;
        if (f) {while (pos[f][1]>yt) f--;
            while (pos[f][0]!=xl) f--;
            wherp = f;} else wherp = 0;
        fwrite (&cur,2,1,fpundo);
        fwrite (&ar,2,1,fpundo);
        fwrite (str,1,ar,fpundo);
        fwrite(vam,2,3,fpundo);
        fwrite (&wherp,2,1,fpundo);
        fwrite(&pre_cur,2,1,fpundo);
        fwrite(&ins,2,1,fpundo);
        fwrite(&gr_flag,2,1,fpundo);
        fwrite(savefile,1,512,fpundo);
        fwrite (pxl,4,1,fpundo);
        fwrite (pyt,4,1,fpundo);
        fwrite (pxr,4,1,fpundo);
        fwrite (pyb,4,1,fpundo);
        fwrite (&orio,4,1,fpundo);
        if (ferror(fpundo)) { 
            clearerr(fpundo); fclose(fpundo);
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
        }
        else {
            fdatasync (fide_undo);
        fsync (fide_undo);
        fclose(fpundo);
            if (undo_lasfile>undo_max) {
                    // Τσεκάρω για snapshot...
                strcpy(file_2,user_path);
                strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                fpundo=fopen(file_2,"rb");
                if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
               
                a=undo_lasfile-undo_max;
                sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                rename (file_1,file_2);
                undo_firfile++;}
            }
        }
        else {
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
        }
        }
        
        if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
       y1= pos[a][1] ;
        if (y1>=ektos || y1<yt) continue ;
         what=str[a];
        x1= pos[a][0] ; 
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[0]=0;
        // Εσωτερική Αναδιάταξη !
        cur = vam[1] ;
        for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
        diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
        if (inp_mem_ghost) {free(inp_mem_ghost); ghost=inp_mem_ghost=0;}
        }
        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                f=cur;
            if (f) {
                while (pos[f][1]!=yt) f--;
                while (pos[f][0]!=xl) f--;
                ano_ar=f; } else ano_ar=cur;
                
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
        }
        if(!ins) elxor=orio-ar; else elxor=orio-cur;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        if (!ins) {
            
            for(f=ar,i=0; (f>=cur) ; f--,i++) str[orio-i]=str[f];
            diaf1=orio-i+1;}
            // Προσδιορισμός του Pre_Paste
            
        if (!pre_cur) {
        f=cur;
        if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                } else pre_paste=0;} 
                   else pre_paste=0;

        f=0 ; a=0 ;
        ch=clipbo[f];
        while ( (ch!='\0') && (elxor) ) {
            if (ch<0) {
                
                f++ ; ch1= ( (256*ch) + clipbo[f] ) ;
                for (i=0 ; i<69 ; i++) {
                    if (ch1==unico[i][0]) {
                        str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                        if (i==69) {str[cur+a]=0 ; a++ ; elxor--; f--; }
                f++; ch=clipbo[f];continue;
             }
            else {
                if (ch=='\n') {str[cur+a]=200; a++;elxor--; f++; ch=clipbo[f]; continue;}
                for(i=0;i<95;i++) {
                    if (ch==gouv[i].who) {
                        str[cur+a]=i ; a++ ; elxor-- ;break;}}
                        if (i==95) {str[cur+a]=0 ; a++ ; elxor--;}
                f++;ch=clipbo[f];
                  }
        }
         if (!ins) {ar+=a;} else {
             if (cur+a > ar) ar=(cur+a); }
         if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
         SDL_free(clipbo);
        goto esot_anadiat;}                        
                 
                   }
        break;
                  
                        case SDL_SCANCODE_C :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME C (* Copy) //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                                if (!vam[0]) continue;
                                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                                size=0;
                                for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) size++;
                                    else if ( (what>94) && (what<164) ) size+=2;
                                    else size++; }
                                    size++;
                                    clipbo=malloc(size);
                                    if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                                    a=0;
                                    for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) {
                                        clipbo[a]=gouv[what].who; a++;}
                                    else if ( (what>94) && (what<164) ) {
                                        cha=((unico[what-95][0]/256)-255);
                                        chb = (unico[what-95][0] % 256);
                                        clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                                    else if (what==200) {clipbo[a]='\n' ; a++;}}
                                    clipbo[a]='\0';
                                    size=SDL_SetClipboardText(clipbo);
                                    if (!size) {
                                       
                                        setcolor (COLOR (epr1,epg1,epb1));  
                                        for (a=vam[1]; a<=vam[2]; a++) {
                                        y1=pos[a][1] ;
                                        if (y1<yt || y1>=ektos) continue;
                                        what=str[a];
                                        x1=pos[a][0] ; 
                                        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
                                        mem_int=gouv[what].where ;
                                        for(f=0; f<gouv[what].hei ; f++) {
                                        for(i=0;i<gouv[what].wid;i++) {
                                        co.lor = *mem_int++;
                                        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                                        refresh();
                                    } 
                                    free(clipbo);
                                    continue;  }
                    break ;
                    
                    case SDL_SCANCODE_RCTRL :
                    case SDL_SCANCODE_LCTRL :
                        continue;
                    
                    case SDL_SCANCODE_RETURN :
                    case 88 :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME ENTER //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                    {
                        if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        diaf1 = f;} else diaf1 = 0;
                    fidicls (xl,yt,xr,yb,0,0,0);
                    putimage(xl-1,yt-21,mem1,0); putimage(xep,yep,mem_undscr,0);free(mem_undscr);free(mem1) ; free(mem_cu); free(mem_flusa); free(mem_enter);free(mem_tent);  free(mem_under); 
                    if (bar) { putimage (xr+3,yt-1,mem_bar,0); refresh(); }
                    if (mem_bar) free(mem_bar); 
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu); free(mem_arrs); free(mem_info);free(mem_find); free(mem_fonter);  free(mem_link);
                    str[ar]=255;
                    if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; }
                    langex = (us_flag) ? 1 : 2 ;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh();  ar=0; undo=0; undo_firfile=1; undo_lasfile=0 ; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; return diaf1;
                    }
                    default :
                    {

                        if (keyb_gr) {ton=0 ; dial=0 ;}
                        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        if (vam[0]) {                              // ξεβάφω
                        setcolor (COLOR (bkr,bkg,bkb));  
                        for (a=vam[1]; a<=vam[2]; a++) {
                         y1= pos[a][1] ;
                        if (y1>=ektos || y1<yt) continue ;
                        what=str[a];
                        x1= pos[a][0] ;
                        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }continue ;}
                        mem_int=gouv[what].where ;
                        for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                        co.lor = *mem_int++;
                        if (!co.lor) _putpixel(x1+i , y1+f);}}
                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                        }
                        refresh();
                        vam[0]=0; pre_cur=0;
                        }
                        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                            f=cur;
                        if (f) {
                            while (pos[f][1]!=yt) f--;
                            while (pos[f][0]!=xl) f--;
                            ano_ar=f; } else ano_ar=cur;
                            
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                        }
                        
                        if (cur==ar) {
                            if (orio==ar) continue ;
                            pos[cur][0]=x; pos[cur][1]=y;
                            str[cur]=200;
                            ar++ ; cur ++;
                            str[ar]=255;
                            x=xl; y+=bh ;
                            pos[ar][0]=x ; pos[ar][1]=y;
                             if (y == ektos) {
                                size=imagesize(xl,yt+bh,xr-1,yb);
                                mem_power=malloc(size);
                                if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                                getimage(xl,yt+bh,xr-1,yb,mem_power);
                                putimage (xl,yt,mem_power,0); free (mem_power);
                                setcolor (COLOR(bkr,bkg,bkb));  
                                for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                                for(i=ar;i>=0;i--) pos[i][1]-=bh;
                                refresh();
                                y-=bh;  }
                            
                            goto barovios;
                        }
                        
                        if(!ins) {
                            if (orio==ar) continue ;
                            ar++; for(f=ar;f>cur;f--) str[f]=str[f-1];}
                        str[cur]=200;
                        x1=x ; y1=y;
                
                 anadiat :
                          // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    
                if (what==200) {pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh; continue ;}
                wrap=0;
                if ((x1+gouv[what].wid) > xr-2) { 
                        if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}refresh();}
                                            }
                                        }  
                x1=xl ; y1+=bh; }
                
                do{
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ; 
                what=str[a-wrap];
                if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                wrap--;    
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) { cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else { x=x1 ; y=y1;}
                 if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     a=cur; y-=bh;
                     x1=xl ; y1=y;
                     while (pos[a][1]==y) {
                     what=str[a];
                     if (what>=200) break ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}refresh();}
                        
                 } goto barovios; }
                                 
                }
                        
                
            //ΕΛΕΓΧΟΣ ΠΡΙΝ ΤΗΝ ΕΚΤΥΠΩΣΗ ΕΝΟΣ ΧΑΡΑΚΤΗΡΑ //
            if (vam[0]) {                              // ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb));   
            for (a=vam[1]; a<=vam[2]; a++) {
             y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            what=str[a];
            x1= pos[a][0] ;
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
            }
            refresh();
            vam[0]=0;pre_cur=0;
            }
            
            if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    f=cur;
                if (f) {
                    while (pos[f][1]!=yt) f--;
                    while (pos[f][0]!=xl) f--;
                    ano_ar=f; } else ano_ar=cur;
                    
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;
            }
                
                
            if (ch_scan<57) {
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME CHAR
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        shift=1 ; break ;
                    default : shift = 0; }
                  
                  // To caps_lock αντιστρέφει το shift για τα Α έως Ζ //
                    if (ch_scan>3 && ch_scan<30) {
                        if (caps_lock) shift = abs (shift-1) ;}
            what = (gr_flag) ? grek.sort[ch_scan][shift] : engl.sort[ch_scan][shift] ;
            if (!gr_flag) goto typechar ;
            if (dial) {
                switch (gouv[what].who) {
                    case 'i' :
                    case 'y' :
                    case 'I' :
                    case 'Y' :
                        met+=2 ; dial=0 ; break ;
                    default : dial=0 ; met=0 ;}}
                    
            if (ton) {
                switch (gouv[what].who) { 
                    case 'I' :
                    case 'Y' :    
                    met=1 ; ton=0 ; break ;
                case 'a' :
                case 'e' :               
                case 'h' :                  
                case 'i' :                    
                case 'o' :                    
                case 'y' :                   
                case 'v' :                   
                case 'A' :
                case 'E' :
                case 'H' :
               case 'O':
               case 'V' :
                   met+=1 ; ton =0 ; break ;
                default : met=0 ; ton=0;}}
                
            what += met ; met=0 ;
            
            typechar:
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            
            if (cur==ar) {
            if ( orio==ar ) continue ;
            str[ar]=what ; ar++; cur++; str[ar]=255 ;
            wrap=0;
            if ( (x+gouv[what].wid) > xr-2) {  
               if ( (what) ) {  
               i=cur-1;
               while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
               i++;wrap--;
               if (elax<wrap+1) wrap=0;
               if ( (wrap) ) {
               x1=pos[i][0];y1=pos[i][1];
               if ((y1>=yt) && (y1<ektos)) {
               setcolor (COLOR(bkr,bkg,bkb));  
               for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                    }
                }
            x = xl ; y+=bh ;
            }
            if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     y-=bh;
                     refresh();
                }
                 
            
            do {
            pos[(cur-1-wrap)][0]=x ; pos[(cur-1-wrap)][1]=y ;
            what=str[cur-1-wrap];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x+i , y+f);}}
            refresh();
            x=x+gouv[what].wid;
            wrap--;
            }while (wrap>=0);
            pos[cur][0]=x; pos[cur][1]=y;
            refresh();
                     }
            
            else {                               // cur != ar
             
               if (!ins) {
                    if ( orio==ar ) continue ;
                    ar++;
                    for(f=ar; f>cur; f--) str[f]=str[f-1];
                   str[cur]=what ;
                   if ( (what) && (ar<orio) && (cur) ) {
                           if (str[cur+1] && (!str[cur-1])) {
                               ar++;
                               for(f=ar; f>cur+1; f--) str[f]=str[f-1];
                               str[cur+1]=0;
                           }
                       }
            }
                    
                str[cur]=what;
                f=0;i=0;
                while (pos[cur-f][0]!=xl) f++;
                if ((cur-f)) {
                i = f+1;
                while ( pos[cur-i][0] !=xl ) {
                    if (str[cur-i]!=200) i++;
                    else {i=0;break;} }}
                secr = (i) ? i : f ;
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];
                
                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur-secr; a<ar; a++) {
                    what=str[a];
                        
                    if (what==200) {pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh;  continue ;}
                    wrap=0;            
                    if ((x1+gouv[what].wid) > xr-2) { 
                        if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}}
                                            }
                                        }  
                    x1=xl ; y1+=bh; }
                        
                    do { 
                    pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;     
                    what=str[a-wrap];
                    if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                    
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;
                    wrap--;
                    }while (wrap>=0);
                }
                
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) {cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else {x=x1; y=y1;}
                 
                 if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     a=cur; y-=bh;
                     x1=x ; y1=y;
                     while (pos[a][1]==y) {
                     what=str[a];
                     if (what>=200) break ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    refresh();
                }
                
                if (y<yt)   {
                    size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt,xr-1,ektos-bh,mem_power);
                     putimage (xl,yt+bh,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=yt ; f<yt+bh; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]+=bh;
                     a=cur; y1=yt;
                     while (pos[a][0]!=xl) a--;
                     while (pos[a][1]==y1) {
                     what=str[a];
                     if (what==200) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    a++;
                    }
                    refresh();
                    y=yt;
                                }
                    
                }
  if ( (!bar) ) {
                    proyt=abs(pos[0][1]-yt) ;
                    metektos = pos[ar][1]- yt - ( (maxline-1)*bh );
                    
                    if ( (!proyt) && (metektos<=0) ) continue ;
                    bar=1;
                    setcolor (COLOR (0,255,0) );  
                    rectangle (xr+3,yt-1,xr+13,yb);
                    setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
                    olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
                    y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
                    y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;
                     if (y1==y2) y2++;
                    setcolor (COLOR (255,165,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                    refresh();
                    continue ;
                            }
        else
                            {
               proyt1=abs(pos[0][1]-yt) ;
               metektos1 = pos[ar][1]- yt - ( (maxline-1)*bh );
               if ( (!proyt1) && (metektos1<=0) ) {
               putimage (xr+3,yt-1,mem_bar,0);
               bar=0;
                refresh();
               continue ;}
               if (proyt1==proyt && metektos1==metektos) continue;
               proyt=proyt1 ; metektos=metektos1;
               olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
               setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
               y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
               y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;     
                if (y1==y2) y2++;
               setcolor (COLOR (255,165,0) );  
               for (f=xr+4 ; f<xr+13 ; f++) {
                    for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                refresh();
                            }
                continue ;
              }
              continue;
       
    case SDL_QUIT:
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        goto DROMO;
    continue ;

    case SDL_WINDOWEVENT :
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
    refresh(); continue;

    default:
    continue;
    
        }
    } 
}

// END INPUT

int diary_input(unsigned char *str, int *pxl,int *pyt,int *pxr,int *pyb,int orio,short int arped, unsigned short int wherp1, char  *diary_filename)
{
SDL_Cursor* cursor;
register int i ,f ;
int mx , my , x , y , shift , size , size_cu, x1, y1 , x2, y2, yep, col_cu, xep , xet , yet , bkr, bkg, bkb, epr, epg, epb ,elax, proyt , proyt1, olohei , metektos, metektos1 , x3 , y3 ,bary1, bary2, diafy , epr1,epg1,epb1,tab=0;
int xl,yt,xr,yb , user_ans ,orio1;
unsigned int time_metr ,ektos ;
unsigned char what ,secr ,file_flag,esc_go;
unsigned short int ch_mod,ch_scan,caps_lock,ton=0,dial=0,met=0, curst , curend , elxor , ch1 , bar=0 ,ano_ar , inp_info=0 , fnd_but=0;
unsigned short int blo_pre_cur=0, pre_paste=0, diak ,maxline, a, port=0 ,tent=0 ,marrs=0 , leks, meg_leks, ken_parag, parag ;
unsigned short int outmen , meg_par, par_leks, big_par, undo_max=5 , fonter=0 , linker = 0 ; 
int blosta, bloend ,diaf3 , diaf1, diaf2 ;
const Uint8 *state ;
void *mem1 , *mem_cu , *mem_under , *mem_flgr ,*mem_undscr, *mem_flusa , *mem_enter , *mem_power, *mem_bar , *mem_rmenu ;
void *mem_undrme, *mem_tent, *mem_arrs , *mem_find ,*mem_fonter ;
void *mem_efedr1 , *mem_efedr2 , *mem_info , *mem_link ;
int *mem_int ;
char *clipbo ;
char *clipbo1;
int pos[orio+1][2] ;
short int pros ,bh, wrap ,kyk, kyk1 ;
char ch,cha,chb;
short int rmed[12] , start=0;
char rmestrgr[12][26];
char rmestren[12][26];
int red,green,blue;
int cbrown[3];
int main_cur[3] , ins_cur[3];
char str1 [100];
int ichxr[3], ibkxr[3] , islxr[3] ; 
int proxchxr[3] , proxbkxr[3] , proxslxr[3] ;
char *loadfile ;
int pedaba [4] , pedaca;
FILE *fp ,*fpundo , *fpex;
int selpal=3456;
union whatcols{
unsigned int lor ;
unsigned char rgb[4];
} co ;
int pras[3] , galaz[3] , kokin[3];
int *chrpnt[3] , sel_red[3] , selred;
unsigned char *ghost;
unsigned short int hlpxt , hlpyt ;
static short int gr_flag , us_flag ;
static unsigned short int wherp , pre_cur, cur, ar, vam[3] , ins ;
static char savefile [512];
static short int undo ,undo_firfile , undo_lasfile , inf_crit;
static unsigned short int how_many , cur_ghost;
unsigned char klik;
int fide_fp , fide_undo ;
float neg, alfa ;
shlp=0;

switch (langex) {
    
    case 0:
        if (keyb_gr) { gr_flag=1; us_flag=0; } 
        else { gr_flag=0 ; us_flag=1; }
        break ;
        
    case 1:
        us_flag=1; gr_flag=0;
        break ;
        
    case 2:
        us_flag=0; gr_flag=1;
}


// Περίπτωση UNDO
epimeno :
if (undo==2) {
    wherp1=0 ; 
    if (inp_mem_ghost) free(inp_mem_ghost);
    ghost=inp_mem_ghost=0;
    do {
        //sprintf(file_1,"%s%s%d%s",path_name,"TMP/undo",undo_lasfile,".dat");
        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
        fpundo=fopen(file_1,"rb");
        if (fpundo!=NULL) break;
        undo_lasfile--;
        if (undo_lasfile<undo_firfile) {
            undo=0; undo_firfile=1; undo_lasfile=0 ; cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;break ;}
    } while (fpundo==NULL);
    if (undo) {
        fread (&cur,2,1,fpundo);
        fread (&ar,2,1,fpundo);
        if (orio<ar) {
            fclose (fpundo) ; fpundo=NULL ;
            cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; 
            vam[0]=0;
            undo=0; 
            undo_firfile=1; undo_lasfile=0 ;
            str[ar]=255;
            if (keyb_gr) information (0,"Απροσδιόριστο σφάλμα !!",0) ;
            else information (0,"Unknown Error !!",0) ;
            goto DIAFYGH ;
        }
        fread (str,1,ar,fpundo);
        fread (vam,2,3,fpundo);
        fread (&wherp,2,1,fpundo);
        fread (&pre_cur,2,1,fpundo);
        fread (&ins,2,1,fpundo);
        fread (&gr_flag,2,1,fpundo);
        fread (savefile,1,512,fpundo);
        fread (pxl,4,1,fpundo);
        fread (pyt,4,1,fpundo);
        fread (pxr,4,1,fpundo);
        fread (pyb,4,1,fpundo);
        fread (&orio1,4,1,fpundo);
        
        if ( ferror(fpundo) ) {
            clearerr(fpundo);fclose(fpundo); 
            remove(file_1);
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) {
                undo=0;
                undo_firfile=1; undo_lasfile=0 ; cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;
            } 
            else goto epimeno;
        }
        else {
            str[ar]=255;
            fclose (fpundo);
            remove(file_1);
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) {
                undo=0;
                undo_firfile=1; undo_lasfile=0 ;
            } else undo=1;
            if (orio!=orio1) { 
                cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;undo=0; undo_firfile=1; undo_lasfile=0 ;}
        } 
    }
}
else if (undo==3) {
    wherp1=0 ;
    if (inp_mem_ghost) free(inp_mem_ghost);
    ghost=inp_mem_ghost=0;
    strcpy(file_1,user_path);
    strcat(file_1,".EORT_SETTINGS/TMP/snapshot.dat");
    fpundo=fopen(file_1,"rb");
    if (fpundo!=NULL) {
        fread (&cur,2,1,fpundo);
        fread (&ar,2,1,fpundo);
        if (orio>ar) { 
            fread (str,1,ar,fpundo); 
            fread (vam,2,3,fpundo);
            fread (&wherp,2,1,fpundo);
            fread (&pre_cur,2,1,fpundo);
            fread (&ins,2,1,fpundo);
            fread (&gr_flag,2,1,fpundo);
            fread (savefile,1,512,fpundo);
            fread (pxl,4,1,fpundo);
            fread (pyt,4,1,fpundo);
            fread (pxr,4,1,fpundo);
            fread (pyb,4,1,fpundo);
            fread (&orio1,4,1,fpundo);
            if ( ferror(fpundo) ) {clearerr(fpundo);cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;}
        }
        else {cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;}
        if (orio1!=orio) {cur=ar=wherp=pre_cur=ins=0; savefile[0]='\0'; vam[0]=0;}
        fclose (fpundo);
        str[ar]=255;
    }
    undo=0; undo_firfile=1; undo_lasfile=0 ;   
}
else if (!undo) {undo_firfile=1; undo_lasfile=0 ;}

DIAFYGH:
elax=gouv[0].wid;
bh=gouv[0].hei;
for (f=1;f<164;f++) {
    if (bh<gouv[f].hei) bh=gouv[f].hei;
    if (elax > gouv[f].wid) continue ; else elax=gouv[f].wid;}
chrpnt[0]=pras; chrpnt[1]=kokin; chrpnt[2]=galaz;
pras[0]=50; pras[1]=205; pras[2]=50;
galaz[0]=100; galaz[1]=149; galaz[2]=237;
kokin[0]=255; kokin[1]=0; kokin[2]=127;
cbrown[0]=44 ; cbrown[1]=31 ; cbrown[2]=22;
xl=*pxl ; yt=*pyt ; xr=*pxr ; yb = *pyb;
bkr=bkxr[0] ; bkg=bkxr[1] ;bkb=bkxr[2];  // ΕΔΩ καθορίζεται το backround color !!!
epr =slxr[0] ; epg=slxr[1] ;  epb=slxr[2] ; // ΕΔΩ παίρνει τις τιμές χρώματος όταν επιλέγεται κείμενο !!
setrgbpalette(selpal,epr,epg,epb);
for (f=0 ; f<3 ; f++) {
    sel_red[f]=slxr[f]+20;
    if(sel_red[f]>255) sel_red[f]=255;
}
selred=4567;
setrgbpalette(selred,sel_red[0] , sel_red[1] , sel_red[2] ) ;
main_cur[0] = 255-((epr+bkr)/2) ; main_cur[1] = 255-((epg+bkg)/2) ; main_cur[2] = 255-((epb+bkb)/2) ; // Κύριο χρώμα του κέρσορα !  
setrgbpalette(99,main_cur[0],main_cur[1],main_cur[2]); // To 99 κύριο χρώμα του κέρσορα
ins_cur[0] = 255-((epr+chxr[0])/2) ; ins_cur[1] = 255-((epr+chxr[1])/2) ; ins_cur[2] = 255-((epr+chxr[2])/2) ; // To "Insert" χρώμα του κέρσορα !
setrgbpalette(100,ins_cur[0],ins_cur[1],ins_cur[2]); // To 100 = insert χρώμα του κέρσορα
epr1 = epr + 70; if (epr1>255) epr1=255;
epg1 = epg + 50; if (epg1>255) epg1=255;
epb1 = epb + 40; if (epb1>255) epb1=255;
// dh=(2*bh)-1;
if (yb+34>=info.bottom) yb=info.bottom-34 ;
if (xr>=info.right-15) xr=info.right-15;
if ( (yb-yt) < bh+22 ) {yt=yb-bh-22 ; while ( (yt<info.top+1) && (yb<info.bottom-35) ) {yb++;yt=yb-bh-22 ;}}
if ( (xr-xl)  < 225) { xl=xr-225 ; while ( (xl<info.left+1) && (xr<info.right-15) ) {xr++ ;  xl=xr-225 ;}}   
if (orio<=0) return 0;
xep=xr-224;
xet=xr ; 
yep=yb+2;yet=yep+33;
*pxl=xl; *pyt=yt; *pxr=xr ; *pyb = yb;
elax=(xr-xl)/elax ; // ELAXISTH XVRHTIKOTHTA GRAMMHS ANALOGA TO MEGISTO PLATOS
setrgbpalette(10,0,255,127) ; // Light Green=10
setrgbpalette(11,255,99,71) ; // Tomato=11
setrgbpalette(12,0,255,255) ; // Light Blue=12
ichxr[0]=51; ichxr[1]=228; ichxr[2]=114;
ibkxr[0]=ibkxr[1]=0; ibkxr[2]=117;
islxr[0]=62 ; islxr[1]=40; islxr[2]=47;
blosta = bloend = -1;
size=imagesize(xl,yt,xr,yb);
mem1=malloc(size);
if (!mem1) { printf ("Out of memory") ; return 0; }
size_cu=imagesize(0,0,1,(bh-1));
mem_cu=malloc(size_cu);
if (!mem_cu) { printf ("Out of memory") ; free (mem1); return 0; }
getimage(xl,yt,xr,yb,mem1);
bareacls(xl,yt,xr,yt+19,galaz);
setcolor (COLOR (180,0,0)) ;   // Rectangle Color !!
rectangle (xl,yt,xr,yt+19) ; 
strcpy(file_1,path_name);
strcat(file_1,"ICD/hand_17.ico");
mem_arrs=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/info_17.ico");
mem_info=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/Search_17.ico");
mem_find=icontomem(file_1,255);

strcpy(file_1,path_name);
strcat(file_1,"ICD/Fonter_17.ico");
mem_fonter=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/ext_link.ico");
mem_link=icontomem(file_1,255);

_puticon(xl+1,yt+1,mem_arrs,255);
_puticon(xr-18,yt+1,mem_info,255);
_puticon(xr-36,yt+1,mem_find,255);
_puticon(xr-54,yt+1,mem_fonter,255);

_puticon(xl+19,yt+1,mem_link,255);



    strcpy (str1024,diary_filename); 
    
    normtext_tomy(str1024,0);
    _outmystr_center_col(0, str1024,xl+37, yt+1, xr-87,yt+19, cbrown , galaz); 

refresh();
yt+=20;
areacls(xl,yt,xr,yb,bkr,bkg,bkb);
setcolor (COLOR (180,0,0)) ;   // Rectangle Color !!
rectangle (xl,yt,xr,yb) ; 
xl+=1 ; yt++ ; xr-- ; yb--;
x=xl ; y=yt;
diaf1=yb-yt+1; diaf2=diaf1/bh;maxline=diaf2; ektos=yt+(diaf2*bh);
refresh();
strcpy(file_1,path_name);
strcat(file_1,"ICD/und_inp.ico");
mem_under=icontomem(file_1,255);

if (keyb_gr) {
    strcpy(file_1,path_name);
    strcat(file_1,"ICD/gr_flag.ico");
    mem_flgr=icontomem(file_1,255);
    sprintf (rmestrgr[0] , "Sv'se vw..");
    sprintf (rmestrgr[1] , "Eish'gage Arxei'o");
    sprintf (rmestrgr[2] , "Sv'se..");
    sprintf (rmestrgr[3] , "Arxh' Mplo'k");
    sprintf (rmestrgr[4] , "Te'low Mplo'k");
    sprintf (rmestrgr[5] , "Diagrafh' Mplo'k");
    sprintf (rmestrgr[6] , "Antigrafh'");
    sprintf (rmestrgr[7] , "Epiko'llhsh");
    sprintf (rmestrgr[8] , "Sv'se vw kei'meno");
    sprintf (rmestrgr[9] , "Ana'kthsh stigmio'typ.");
    sprintf (rmestrgr[10] , "Diagrafh' O'la");
    sprintf (rmestrgr[11] , "Fy'ge..");
    }
    sprintf (rmestren[0] , "Save as");
    sprintf (rmestren[1] , "Insert ..");
    sprintf (rmestren[2] , "Save ..");
    sprintf (rmestren[3] , "Block Start");
    sprintf (rmestren[4] , "Block End");
    sprintf (rmestren[5] , "Delete Block");
    sprintf (rmestren[6] , "Copy..'");
    sprintf (rmestren[7] , "Paste..");
    sprintf (rmestren[8] , "Save as .txt");
    sprintf (rmestren[9] , "Load Snapshot");
    sprintf (rmestren[10] , "Delete All");
    sprintf (rmestren[11] , "GO...");    
    
strcpy(file_1,path_name);
strcat(file_1,"ICD/usa_flag.ico");
mem_flusa=icontomem(file_1,255);
strcpy(file_1,path_name);
strcat(file_1,"ICD/Inp_menu.ico");
mem_rmenu=icontomem(file_1,255);
size=imagesize(xep,yep,xet,yet);
mem_undscr=malloc(size);
if (!mem_undscr) { printf ("Out of memory") ; free (mem1); return 0; }
getimage(xep,yep,xet,yet,mem_undscr);
putimage(xep,yep,mem_under,0); refresh();
size=imagesize(xep+136,yep+4,xep+179,yep+30);
mem_enter=malloc(size);
if (!mem_enter) { printf ("Out of memory") ; free (mem1); free (mem_undscr) ; return 0; }
getimage(xep+136,yep+4,xep+179,yep+30,mem_enter);
size=imagesize(xep+182,yep+4,xep+223,yep+30);
mem_tent=malloc(size);
if(!mem_tent) {printf ("Out of memory") ; free (mem1); free (mem_undscr) ; free(mem_enter); return 0;}
getimage(xep+182,yep+4,xep+223,yep+30,mem_tent);
size=imagesize (xr+3,yt-1,xr+13,yb);
mem_bar=malloc(size);
if (mem_bar==NULL) {printf ("Memory Problem") ; free (mem1); free (mem_undscr) ; free(mem_enter); free(mem_tent); return (0); }
getimage (xr+3,yt-1,xr+13,yb,mem_bar);

pedaba[0]=22111963; pedaba[1]=404976; pedaba[2]=99; pedaba[3]=167330;

// ELEGSOS GIA CAPS LOCK PATHMENO XVRIS MPERDEMA ME ALLA PLHKTRA //
SDL_FlushEvent (SDL_KEYDOWN);
state = SDL_GetKeyboardState(NULL);
ch_mod=SDL_GetModState();
caps_lock = ( (ch_mod==8192) || (ch_mod==12288) ) ? 1 : 0 ;

if (caps_lock) {
       for (f=3;f<29;f++) {
       mem_int=(mem_under+8+(f*225*4));
       for(i=48 ; i<84;i++) {
       co.lor= *(mem_int+i);
       setcolor ( COLOR ( co.rgb[2] , co.rgb[1] , (co.rgb[0] +100)) );
        
       _putpixel (xep+i,yep+f);}} 
       refresh();} 
col_cu = 99; 
time_metr=0;
diak=0;
pos[0][0]=xl ; pos[0][1]=yt;
for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
x1=x ; y1=y;
ghost = inp_mem_ghost ;
//ELEGXOS TOY ALFARIUMHTIKOY str kai parousiash tou keimenou //
    what=str[0];
    if (what !=255) {
        f=0; diaf2=0;
        while ( (what!=255) && (orio-f) ) {
        if (what==200) {f++;what=str[f];continue;}
        if ( (what>=0) && (what<164) ) {f++;what=str[f];continue;}
        diaf2=1; break; 
            } 
        str[f]=255; diaf1=f;
        if ( (!ar) || (ar!=diaf1) || (diaf2) ) {
        ar=diaf1;cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;undo=0; undo_firfile=1; undo_lasfile=0 ;}                    
       // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ       
        x1=xl ; y1=yt;
        for (a=0; a<ar; a++) {
        what=str[a];
        if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ; x1=xl ; y1+=bh; continue ;}
        wrap=0 ;  
        if ((x1+gouv[what].wid) > xr-2) {
            if ( (what) ) {  
                i=a;
                while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                i++;wrap--;
                if (elax<wrap+1) wrap=0;}
                x1=xl ; y1+=bh; }
        
        do {
        pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
        what=str[a-wrap];
            x1+=gouv[what].wid;
            wrap--;
            } while (wrap>=0);
        }
            str[ar]=255 ;
            pos[ar][0]=x1 ; pos[ar][1]=y1;
            // ΝΕΑ ΕΜΦΑΝΙΣΗ                
            
        if (wherp) {
        f=0;
        while (pos[wherp-f][0] != xl) f++;
        wherp-=f;
        diaf1=(pos[wherp][1]-yt);
        for (i=0;i<=ar;i++) pos[i][1]-=diaf1;
        wherp1=0;
        }
        
        else if (wherp1) 
        {
        if (wherp1>=ar) wherp1=ar-1;
        f=0;
        while (pos[wherp1-f][0] != xl) f++;
        wherp1-=f;
        diaf1=(pos[wherp1][1]-yt);
        for (i=0;i<=ar;i++) pos[i][1]-=diaf1;
        wherp=wherp1;
        cur=wherp1;
        }
        
        while (pos[cur][1]>=ektos) {
            f=wherp;
            while (pos[f][1]==yt) f++;
            wherp=f;
                for (i=0;i<=ar;i++) pos[i][1]-=bh;}
       
        for (a=wherp; a<ar; a++) {
            what=str[a];
            if (what==200) continue ;
            y1=pos[a][1];
            if (y1>=ektos) break ;
            x1=pos[a][0];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) {
                if (!ghost) continue;
                if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                else continue ;
            }
            

            // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
            setcolor(COLOR (red,green,blue));
            _putpixel(x1+i , y1+f);}}
            if(!ghost) continue ;
            if (ghost[a]) {
                while (f<bh) {
                setrgbcolor(selred);
                for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
            }
        }
        refresh();
        x=pos[cur][0] ; y=pos[cur][1];
        if (vam[0]) {                              // βάφω 
                // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
        setrgbcolor (selpal);  
        for (a=vam[1]; a<=vam[2]; a++) {
        y1=pos[a][1] ;
        if (y1<yt) continue ;
        if (y1>=ektos) break ;
        what=str[a];
        x1=pos[a][0] ; 
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
            refresh();              
        }
        // ELEGXOS GIA PLEYRIKH MPARA
        proyt=abs(pos[0][1]-yt) ;
        metektos = pos[ar][1]- yt - ( (maxline-1)*bh );
        if ( (!proyt) && (metektos<=0) ) goto Enarjh ;
        bar=1;
        setcolor (COLOR (0,255,0) );  
        rectangle (xr+3,yt-1,xr+13,yb);
        setcolor (COLOR (0,0,0) );  
        for (f=xr+4 ; f<xr+13 ; f++) {
            for (i=yt ; i < yb; i++) _putpixel (f,i); }
        olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
        y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
        y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;
        if (y1==y2) y2++;
        bary1=y1 ; bary2=y2;
        setcolor (COLOR (255,165,0) );  
        for (f=xr+4 ; f<xr+13 ; f++) {
            for (i=y1 ; i < y2; i++) _putpixel (f,i); }
        refresh();
    }
    else {cur=0;ar=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0; wherp1=0; pre_cur=0;ins=0;undo=0; undo_firfile=1; undo_lasfile=0 ;}

Enarjh :
if (gr_flag) {us_flag=0 ; putimage(xep+5,yep+4,mem_flgr,0);}
refresh();

if (ins) {
col_cu = 100 ;
for (f=3;f<29;f++) {
mem_int=(mem_under+8+(f*225*4));
for(i=95 ; i<129;i++) {
    co.lor= *(mem_int+i-1);
    setcolor ( COLOR ( co.rgb[2]  , co.rgb[1] , co.rgb[0] +ins*70) );
    _putpixel (xep+i,yep+f);}} 
    refresh();
}

for(;;) {
    
if (!shlp) {
        time_metr++;
    if (time_metr>150000) {
        time_metr=0;
        if (!diak) {
        getimage(x,y,x+1,y+bh-1,mem_cu);   
        diak=1;
        setrgbcolor(col_cu); 
        for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
        _putpixel(x+i,y+f) ;} }
        refresh() ; 
        }
        else {putimage(x,y,mem_cu,0); refresh() ; diak=0;}}
}

if (!SDL_PollEvent(&sdlev)) continue;
    
    switch (sdlev.type) {
    
    case SDL_MOUSEMOTION:
        
        if ( (secwin) && (sdlev.motion.windowID == sdlwin2) ) { continue ;}
    mx=sdlev.motion.x ; my=sdlev.motion.y;

    if (mx>xl && mx<xl+18 && my>yt-21 && my<yt) { // Στην κεφαλίδα
    
        if (inp_info) {puticon(xr-18,yt-20,mem_info,255); inp_info=0;hide_help_inp(hlpxt , hlpyt);}
        else if (fnd_but) {puticon(xr-36,yt-20,mem_find,255); fnd_but=0;hide_help_inp(hlpxt , hlpyt);}
        else if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
        
        if (!marrs) {
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
            SDL_SetCursor(cursor);
            marrs=1;
            putNOTicon(xl,yt-20,mem_arrs);
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            show_help_inp("Μετακίνηση Παραθύρου", xl+50 , yt+10 , &hlpxt , &hlpyt) ;
            
            continue ;}
            else continue ;
        }
    
    if (marrs) {
        marrs=0;
        puticon(xl,yt-20,mem_arrs,255);
        hide_help_inp(hlpxt , hlpyt);
 }

    if (mx>xr-18 && mx<xr+1 && my>yt-21 && my<yt) {  // Info Button
        
        if (fnd_but) {puticon(xr-36,yt-20,mem_find,255); fnd_but=0;hide_help_inp(hlpxt , hlpyt);}
        else if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
        
        
        if (!inp_info) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          inp_info=1;
          putNOTicon(xr-18,yt-20,mem_info);
          if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
          show_help_inp("Γενικά στοιχεία για το κείμενο", xr-18 , yt+10 , &hlpxt , &hlpyt) ;
          
          continue; }
          else continue;
        }
    
    if (inp_info) {
        puticon(xr-18,yt-20,mem_info,255); inp_info=0;hide_help_inp(hlpxt , hlpyt);}
        
            
    if (mx>xr-36 && mx<xr-18 && my>yt-21 && my<yt) {  // Search Button
        
        if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
        
        
        if (!fnd_but) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          fnd_but=1;
          putNOTicon(xr-36,yt-20,mem_find);
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                mytext_tonorm (normdeigma , str1kb , 20) ;
                if (keyb_gr) sprintf (str1024 , "Αριστ. κλικ : Αναζήτηση [%s] - Δεξί κλικ : Εισαγωγή του προς αναζήτηση δείγματος",str1kb);
                else sprintf (str1024 , "Left Click : Search [%s] - Right Click : Input text sample for searching" ,str1kb);
            
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        show_help_inp (str1024 , xr-18, yt+10, &hlpxt , &hlpyt) ;
          continue; }
          else continue;
        }
    
    if (fnd_but) {puticon(xr-36,yt-20,mem_find,255); fnd_but=0;hide_help_inp(hlpxt , hlpyt);}
    
    if (mx>xr-54 && mx<xr-36 && my>yt-21 && my<yt) {  // Fonts Button
        
        if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        else if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
    
        
        if (!fonter) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          fonter=1;
          putNOTicon(xr-54,yt-20,mem_fonter);
          if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
          show_help_inp("Επιλογή Γραμματοσειράς (προσωρινή χρήση)", xr-54 , yt+10 , &hlpxt , &hlpyt) ;
          
          continue; }
          else continue;
        }
    
    if (fonter) {fonter=0 ; puticon(xr-54,yt-20,mem_fonter,255); hide_help_inp(hlpxt , hlpyt);}
    
    
    
        if (mx>xl+18 && mx<xl+37 && my>yt-21 && my<yt) {  // LINKER !!
        
        if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
        else if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        
        
        if (!linker) {
            
          cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
          SDL_SetCursor(cursor);
          linker=1;
          putNOTicon(xl+19,yt-20,mem_link);
          if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
          show_help_inp("Επιλεγμένο κείμενο ως διαδικτυακός σύνδεσμος", xl+50 , yt+10 , &hlpxt , &hlpyt) ;
          
          continue; }
          else continue;
        }
    
    if (linker) {linker=0 ; puticon(xl+19,yt-20,mem_link,255); hide_help_inp(hlpxt , hlpyt);}
    

          
    if (mx>xep+135 && mx<xep+180 && my>yep && my<yet) { // Κλείσε παράθυρο εισαγωγής
        
        if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);refresh();hide_help_inp(hlpxt , hlpyt);}
        
        if (!port) {
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);
        port=1;
        
        for (f=4;f<31;f++) {
        mem_int=(mem_under+ 8+ (f*225*4));
        for(i=136 ; i < 178; i++) {
        co.lor= *(mem_int+i);
        setcolor ( COLOR (co.rgb[2]  , co.rgb[1] +20 , co.rgb[0]+60 ) );
        _putpixel (xep+i,yep+f);}} 
        refresh(); 
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        show_help_inp("Kλείσιμο παραθύρου", xep+135 , yet+1 , &hlpxt , &hlpyt) ;
        
        continue ;}
        else continue ;
        continue; }

    if (port) {port=0; putimage(xep+136,yep+4,mem_enter,0);refresh(); hide_help_inp(hlpxt , hlpyt);}
    
    
    
    if (mx>xep+182 && mx<xet && my>yep && my<yet) { // Αλλαγή Διαστάσεων
        
        if (!tent) {
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);
        tent=1;
        
        for (f=4;f<31;f++) {
        mem_int=(mem_under+ 8+ (f*225*4));
        for(i=182 ; i < 223; i++) {
        co.lor= *(mem_int+i);
        setcolor ( COLOR (co.rgb[2]  , co.rgb[1] +20 , co.rgb[0]+60 ) );
        _putpixel (xep+i,yep+f);}} 
        refresh(); 
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        show_help_inp("Αλλαγή Διαστάσεων", xep+182 , yet+1 , &hlpxt , &hlpyt) ;
        
        continue ;}
        else continue ;
        continue; }

    if (tent) {tent=0; putimage(xep+182,yep+4,mem_tent,0);hide_help_inp(hlpxt , hlpyt);}
    
    if ( (keyb_gr) && mx>xep+2 && mx<xep+43 && my>yep && my<yet) {
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);continue;}
        
     if (bar) {
         if (mem_small) hide_help_inp(hlpxt , hlpyt);
         if (mx>xr+3 && mx<xr+14 && my>yt && my<yb) {
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);continue;}}
        
    
    if (mx>xl && mx<xr && my>yt && my<yb) {
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
   SDL_SetCursor(cursor);continue;}
   
   cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
   SDL_SetCursor(cursor);
   if (mem_small) hide_help_inp(hlpxt , hlpyt);
    continue;
    
    case SDL_MOUSEWHEEL :
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        if(sdlev.wheel.y > 0) { // scroll up
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                if (pos[0][1]==yt) {cur=0; x=xl ; y=yt; continue;}
                diaf2=(maxline>3) ? 3 : maxline ;
                f=cur;
                while (pos[f][1]>=yt) f--;
                while ( (pos[f][1] >=(yt-diaf2*bh)) && (f>=0) ) f--;
                f++; cur=f ;
                diaf1=yt-pos[f][1]; diaf1 /= bh;
                for (i=0;i<=ar;i++) pos[i][1] += (diaf1*bh);
                x=xl ; y=yt;
                // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();

  if (vam[0]) {                              // βάφω 
                       // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setrgbcolor (selpal); 
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
                 goto barovios ;                
        }
        else if (sdlev.wheel.y < 0) { // scroll down
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 if (pos[ar][1]<ektos ) {cur=ar; x=pos[ar][0]; y=pos[ar][1]; continue ;}
                 diaf2=(maxline>3) ? 3 : maxline ;
                 
                 f=cur;
                 while (pos[f][1] > yt) f--;
                 while (pos[f][0] !=xl) f--;
                 while ( pos[f][1]<(yt+diaf2*bh) ) f++;
                 cur=f;
                 for (i=0;i<=ar;i++) pos[i][1]-=(diaf2*bh);
                 x1=x=xl; y1=y=yt;
                 // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();
                                  
                if (vam[0]) {                              // βάφω 
                
                        // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setcolor (COLOR (epr,epg,epb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
                 goto barovios ;
        }
            
        continue ;
        
    case SDL_MOUSEBUTTONDOWN:
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
    if(sdlev.button.button==SDL_BUTTON_LEFT) {   
        auto int pev ;
        mx = sdlev.button.x ; my= sdlev.button.y ;
        klik= sdlev.button.clicks; 
                
        if (mx>xep && mx<xet && my>yb && my<yet) { // Choose ok ,flag , change dimensions
            diaf1=(mx-xep)/45;
            switch (diaf1) {
                case 0:
                    if (!keyb_gr) continue;
                    us_flag=abs (us_flag-1) ; gr_flag=abs(gr_flag-1) ; ton=0; dial=0; 
                    if (us_flag) putimage(xep+5,yep+4,mem_flusa,0);
                    else putimage(xep+5,yep+4,mem_flgr,0);
                    continue; 
                    
                case 1:
                case 2:
                    continue;
                    
                case 3: // (FYGE (Return) me pontiki)
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        diaf1 = f;} else diaf1 = 0;
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; cur_ghost=0;}
                    fidicls (xl,yt,xr,yb,0,0,0);
                    putimage(xl-1,yt-21,mem1,0); putimage(xep,yep,mem_undscr,0);free(mem_undscr);free(mem1) ; free(mem_cu); free(mem_flusa); free(mem_enter);free(mem_tent);  free(mem_under); 
                    if (bar) { putimage (xr+3,yt-1,mem_bar,0); refresh(); }
                    if (mem_bar) free(mem_bar); 
                    if (keyb_gr) free(mem_flgr); free(mem_rmenu); free(mem_arrs); free(mem_info); str[ar]=255;
                    free(mem_find); free(mem_fonter); free(mem_link);
                    langex = (us_flag) ? 1 : 2 ;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh();  ar=0; undo=0; undo_firfile=1; undo_lasfile=0 ; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; return diaf1;
                
                case 4:
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter);  free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    change_dim(xl, yt-21 ,pxr , pyb);  
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    str[ar]=255;
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);free(mem_bar);
                    langex = (us_flag) ? 1 : 2 ;
                    free(mem1);
                    refresh();
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS GIA ALLAGH DIASTASEVN !!!
          }
        }
        if (inp_info) {
            if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
            if (!ar) continue ;
            x2=(info.right-info.left-400)/2;
            y2=(info.bottom-info.top-320)/2;
            mem_power=malloc( (imagesize(x2,y2,x2+399,y2+299)) );
            if (!mem_power) {information(2-keyb_gr,0,0) ; continue;}
            getimage (x2,y2,x2+399,y2+299,mem_power);
            setcolor(COLOR(255,0,0));
            rectangle(x2,y2,x2+399,y2+299);
            rectangle(x2+1,y2+1,x2+398,y2+298);
            x2+=2; y2+=2 ;
            _areacls(x2,y2,x2+396,y2+296,ibkxr[0],ibkxr[1],ibkxr[2]);
            meg_leks=parag=ken_parag=leks=meg_par=par_leks=big_par=0;
            
            for (f=0;f<ar;f++) {
                
                what=str[f];
                if (what==200) {
                    secr= (f) ? str[f-1] : 0 ;
                    if (secr==200) ken_parag++; else { 
                        parag++; 
                        if (par_leks>meg_par) {
                        meg_par=par_leks ;
                        big_par=parag;}
                        par_leks=0;
                    }
                continue;
                }
                
                if (what>42) {
                    i=0;
                    while ( (f<ar) && (what!=200) && (what>42) ) {
                        what=str[++f]; i++;}}
                else continue ;
                        
                if (i>1) { leks++; par_leks++;}
                if (i>meg_leks) meg_leks=i;
                if (what==200) { 
                    parag++; 
                    if (par_leks>meg_par) {
                        meg_par=par_leks ;
                        big_par=parag;}
                        par_leks=0;
                        
                    }
                
            }
            
            if (keyb_gr) {
            _outnoto_colsel (x2+120,y2+4," ENHMERVSH ",1,ichxr,ibkxr,islxr);
            
            f=46;
            sprintf (str1," Me'gisto O'rio Xarakth'rvn : %d " , orio);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Ariumo'w Xarakth'rvn : %d " , ar);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
             sprintf (str1," Diaue'simow xv'row : %d xarak. " , orio-ar);
            _outsouv_colsel (x2+5,y2+f,str1,1,ichxr,ibkxr,islxr);
            f+=24;
            sprintf (str1," Le'jeiw  : %d " , leks);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Mh'kow megaly'terhw le'jhw : %d xarak." , meg_leks);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Para'grafoi : %d " , parag);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Megaly'terh para'gr. No %d me %d le'jeiw" , big_par, meg_par);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Kene'w Para'grafoi : %d " , ken_parag);
            _outsouv_col (x2+5,y2+f,str1,1,ichxr,ibkxr);
            f+=36;
                }
            else {
                
            _outnoto_colsel (x2+135,y2+4," BRIEFING ",0,ichxr,ibkxr,islxr);

            f=46;
            sprintf (str1," Characters max limit : %d " , orio);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Characters number : %d " , ar);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
             sprintf (str1," Available space : %d char. " , orio-ar);
            _outsouv_colsel (x2+5,y2+f,str1,0,ichxr,ibkxr,islxr);
            f+=24;
            
            sprintf (str1," Words  : %d " , leks);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Bigger word length : %d char." , meg_leks);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Paragraphs : %d " , parag);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Bigger paragr. No %d - %d words" , big_par, meg_par);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=24;
            sprintf (str1," Empty Paragraphs : %d " , ken_parag);
            _outsouv_col (x2+5,y2+f,str1,0,ichxr,ibkxr);
            f+=36;
                }
                
            setcolor(COLOR(ichxr[0],ichxr[1],ichxr[2])); 
            line(x2+110,y2+29,x2+275,y2+29);
            line(x2+115,y2+32,x2+270,y2+32);
            line (x2+4,y2+f,x2+393,y2+f); f+=3;
            line(x2+9,y2+f,x2+388,y2+f);
            _putNOTicon(x2+378,y2+4,mem_info);
            refresh();
            
            f=0;i=0;
            while ( event() != 1 ) {
            f++;    
            if (f>100000) {f=0; 
                if (!i) {i=1; 
                    //_bareacls(x2+378,y2+4,x2+396,y2+22,ibkxr); 
                    puticon(x2+378,y2+4,mem_info,255);} 
                else { i=0 ; putNOTicon(x2+378,y2+4,mem_info);}
                } }
            
            x2-=2 ; y2-=2;
            putimage (x2,y2,mem_power,0);
            while (SDL_PollEvent(&sdlev)) continue;
            refresh();
          inp_info=0;
          puticon(xr-18,yt-20,mem_info,255);
          free (mem_power);
            continue;
        }
        
        if (fnd_but) {
            if (!ar) {fnd_but=0; puticon(xr-36,yt-20,mem_find,255); continue ;}
            if (keyb_gr) {ton=0 ; dial=0 ;}
            if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
            if (ghost) { // Ψάχνει το επόμενο ... ανακυκλώνοντας το ψάξιμο !
                if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));  
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];   x1= pos[a][0] ;
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;pre_cur=0;
                }
                f=cur;
                while ( (ghost[f]) && (f<ar) ) f++;
                if (f==ar) f=0;
                while ( (!ghost[f]) && (f<ar) ) f++;
                if (f==ar) f=cur_ghost;
                cur=f;
                y=pos[cur][1];
                if (y<ektos && y>=yt) {x=pos[cur][0];  continue ;}
                if (cur) {
                    f=0;
                    while (pos[cur-f][0] !=xl)  f++;
                    diaf3=pos[cur-f][1]-yt;
                    for (i=0;i<=ar;i++) pos[i][1]-=diaf3;
                    ano_ar=cur-f;
                    }
                else ano_ar=0;
                x=pos[cur][0] ; y=pos[cur][1]; 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                refresh();
                
                for (a=ano_ar; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                refresh ();
            }
            
            else { // Ψάχνει για πρώτη φορά....δεν ζητάει όμως κριτήρια !
                convertinp_strstr  (0, str, arped, &how_many, &cur_ghost);
                ghost=inp_mem_ghost;
                if (!ghost) {
                    if(!inf_crit) {
                        inf_crit=1;
                        information (48-keyb_gr,0,0);
                    }
                      else {                 
                    if (!how_many) {
                        if (keyb_gr) information (0,"Δεν βρέθηκε τίποτε !",0);
                        else information(0,"Nothing found !",0);
                    }}
                fnd_but=0; puticon(xr-36,yt-20,mem_find,255); 
                continue ;}
                if (keyb_gr) sprintf(str1024,"Προέκυψε ταύτιση σε %d σημεία!", how_many);
                else sprintf(str1024,"Identity occurred in %d points!", how_many);
                information(0,str1024,0);
                if (vam[0]) {                              // ξεβάφω
                    setcolor (COLOR (bkr,bkg,bkb));  
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];   x1= pos[a][0] ;
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    refresh();
                    vam[0]=0;pre_cur=0;
                }
                cur=cur_ghost;
                y=pos[cur][1];
                x=pos[cur][0]; 
                if (cur) {
                    f=0;
                    while (pos[cur-f][0] !=xl)  f++;
                    diaf3=pos[cur-f][1]-yt;
                    for (i=0;i<=ar;i++) pos[i][1]-=diaf3;
                    ano_ar=cur-f;
                    }
                else ano_ar=0;
                x=pos[cur][0] ; y=pos[cur][1]; 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                refresh();
                
                for (a=ano_ar; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                refresh();
            }
            
            goto barovios ;
        }
        
        if (fonter) {
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    for (f=0 ; f<3 ; f++) { proxchxr[f]=chxr[f] ; proxbkxr[f]=bkxr[f] ; proxslxr[f]=slxr[f] ; }  
                    user_ans=inp_fonts_show((char *) NULL, dbfnt.mem_fn, dbfnt.fn_data, dbfnt.fn_ar, dbfnt.fn_orio, dbfnt.fn_name, &dbfnt.fn_sorton,0, chxr, bkxr, slxr );
                    for (f=0 ; f<3 ; f++) { chxr[f] = proxchxr[f] ; bkxr[f] = proxbkxr[f] ; slxr[f] = proxslxr[f] ; }  
                    if (user_ans<0) continue;
                    gouv=myfont[user_ans];
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter); free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    str[ar]=255;
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);free(mem_bar);
                    langex = (us_flag) ? 1 : 2 ;
                    free(mem1);
                    refresh();
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS ALLAGH FONT !!!
        }
        
        
        if (linker) {
            
            if (mem_small) hide_help_inp(hlpxt , hlpyt);
            if (!vam[0]) continue ;
            if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
            
            i=0;f=vam[1];
            what=str[f];
            do {
                if (what>163) break ;
                str1024[i++]=what;
                f++; what=str[f];
            }while (f<=vam[2] && i<1380);
            str1024[i]=255;
            mytext_tonorm(str1024,str1kb,1380);
            if (!Start_strstr(str1kb,"https://")) {continue;}
            if (keyb_gr) normtext_tomy ("Επιλέξατε..",str1024);
            else normtext_tomy ("Choose..",str1024);
            for (f=0 ; f<3 ; f++) { proxchxr[f]=chxr[f] ; proxbkxr[f]=bkxr[f] ; proxslxr[f]=slxr[f] ; }
            user_ans=fastmenu_show(2, submenu, str1024, xl+37,yt-20);
            for (f=0 ; f<3 ; f++) { chxr[f] = proxchxr[f] ; bkxr[f] = proxbkxr[f] ; slxr[f] = proxslxr[f]; }
            if (user_ans<0) continue ;

            
            i=0;
            switch (user_ans) { 

                case 0 :
                    if (nofire) {i=1 ; break;}
                    strcpy (big_char,str1kb);
                    orisma[2]=big_char;
                    pid = fork();
                    if (pid<0) {perror("Fork...");break;}
                    else if (pid==0) {execl("/usr/bin/firefox","firefox","--new-tab",orisma[2],(char *)NULL); _exit(1);}
                    else {waitpid(pid,&status,WNOHANG);}
                    break ;
                    
                case 1 :
                    if (nochrom) {i=1; break;}
                    strcpy (big_char,str1kb);
                    orisma[2]=big_char;
                    pid = fork();
                    pid = fork () ;
                    if (pid<0) {perror("Fork...");break;}
                    else if ( !pid ) {
                        //pid=getpid();
                        execl("/usr/bin/google-chrome","google-chrome",orisma[2],(char *)NULL); 
                        _exit (1); 
                        }
                    else waitpid(pid,&status,WNOHANG);
                    break ;
            }
            
            if (i==1) {
                if (keyb_gr) strcpy (str1024,"Mh εγκατεστημένος browser!");
                else strcpy (str1024,"Browser not installed!");
                information (0,str1024,0);
            }

            continue ;            
                
        }
        
        
        if (mx>xl && mx<xl+18 && my>yt-21 && my<yt) {
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter); free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                     f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;            
                    change_pos(pxl, pyt ,pxr , pyb);  
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    str[ar]=255;
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);free(mem_bar);
                    langex = (us_flag) ? 1 : 2 ;
                    free(mem1);
                    refresh();
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS GIA ALLAGH UESHS  !!!
            
        }
        
        if ( mx>xr+14 || mx<xl-1 || my>yb+1 || my<yt-20 ) goto DROMO;
        
        // KLIK STHN MPARA !!
        if (bar) {
           
          if (mx>xr+3 && mx<xr+14 && my>yt && my<yb) {
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
            SDL_SetCursor(cursor);
            if (my<bary1) goto PAGEUP ;
            if (my>bary2) goto PAGEDOWN ;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            y3=bary1 + (bary2-bary1+1)/2 ;
            
            esc_go=0;
            do {
           
                while (SDL_PollEvent(&sdlev)) 
                { 
                    esc_go=0;
                    switch (sdlev.type) {
                        case SDL_MOUSEMOTION :
                            my= sdlev.button.y ;
                            SDL_FlushEvent(SDL_MOUSEMOTION);
                            break ;
                            
                        case SDL_MOUSEBUTTONUP :
                            esc_go=1;
                            
                        default :
                            break ;
                    }
                    break ;
           }

            if (my>yb) my=yb;
            if(my<yt) my=yt;
            if (y3==my) continue;
            diafy=my-y3;
            
            f=cur;
            if (f) {
                while (pos[f][1]!=yt) f--;
                while (pos[f][0]!=xl) f--;
                ano_ar=f; } else ano_ar=cur;
                y2=pos[ano_ar][1];
                
            if (diafy<0) {
                if (!cur) continue;
                if (!ano_ar) {cur=0; continue;}
                diafy=abs(diafy);
                
                diaf2=( diafy*(olohei/bh) ) / (yb-yt-1) ; // Σε πόσες γραμμές αντιστοιχούν τα pixels
                if (!diaf2) continue;
                
                do {
                if (pos[0][1] <= (yt - ( diaf2*bh)) ) {for (i=0;i<=ar;i++) pos[i][1]+=diaf2*bh; break ;}
                else diaf2--;
                } while (diaf2);
                if (!diaf2) continue;
                f=ano_ar;
                while (pos[f][1]!=y2) f--;
                while (pos[f][0]!=xl) f--;
                cur=f;}
                else {
                    if (cur==ar) continue;
                    if (pos[ar][1]<ektos) continue ;
                    diaf2=( diafy*(olohei/bh) ) / (yb-yt-1) ; // Σε πόσες γραμμές αντιστοιχούν τα pixels
                     if (!diaf2) continue;
                      do {
                        if (pos[ar][1] >= yt + ( diaf2*bh) ) {for (i=0;i<=ar;i++) pos[i][1] -= diaf2*bh; break ;}
                        else diaf2--;
                        } while (diaf2);
                        if (!diaf2) continue;
                        f=ano_ar;
                        while (pos[f][1]!=y2) f++;
                    cur=f;}
            
               x1=x=xl; y1=y=yt;
               
                 // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }
                    

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();
                
                if (vam[0]) {                              // βάφω 
                
                        // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setrgbcolor (selpal);
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
               proyt1=abs(pos[0][1]-yt) ;
               metektos1 = pos[ar][1]- yt - ( (maxline-1)*bh );
               if ( (!proyt1) && (metektos1<=0) ) {
               putimage (xr+3,yt-1,mem_bar,0);
               bar=0;
               refresh();
               continue ;}
               if (proyt1==proyt && metektos1==metektos) continue;
               proyt=proyt1 ; metektos=metektos1;
               olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
               setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
               y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
               y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;     
                if (y1==y2) y2++;
               bary1=y1 ; bary2=y2;
               setcolor (COLOR (255,165,0) );  
               for (f=xr+4 ; f<xr+13 ; f++) {
                    for (i=y1 ; i < y2; i++) _putpixel (f,i); }
               y3=bary1 + (bary2-bary1+1)/2 ;
                refresh();
            } while (sdlev.type!=SDL_MOUSEBUTTONUP && (bar) && (!esc_go) ) ; 
            if (keyb_gr) {ton=0 ; dial=0 ;}
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
            SDL_SetCursor(cursor);
            x=pos[cur][0] ; y=pos[cur][1];
            continue ;
        }
        }
        
        
        // Μέσα στο Κείμενο κλίκ....
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        if (keyb_gr) {ton=0 ; dial=0 ;}
        if (vam[0]) {                              //σβηνω κερσορα - ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb)) ;  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            x1= pos[a][0] ; what=str[a];
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}            
            refresh();
            vam[0]=0;pre_cur=0;
            }
            
        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
            
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            f=cur;
            if (f) {
                while (pos[f][1]!=yt) f--;
                while (pos[f][0]!=xl) f--;
                ano_ar=f; } else ano_ar=cur;
                
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;cur_ghost=0;
        }
        
        if (!ar) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1]; 
        diaf1=2*xr;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
       curst= --f;
       chb=0;
       if (curst>=ar) {chb=1; curst=ar-1;}
       if (klik>1) {
           
            f=curst;
            if (f) {
                while (pos[f][0]!=xl) f--;
            }
            curst=f;
            i=f;
            what=str[i];
            while ( (what!=200) && (i) ) {what=str[--i];}
            vam[1] = (i) ? i+1 : 0 ;
            //vam[1]=f;
            what=str[f];
            while (what<200) {what=str[++f];}
            vam[2] = f ;
            if (vam[1]==vam[2]) continue ;
            if (!f) continue ;
            vam[2] = (f==ar) ? f-1 : f ;
            vam[0]=1;
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setrgbcolor (selpal);  
            for (a=vam[1]; a<=vam[2]; a++) {
            y1=pos[a][1] ;
            if (y1<yt) continue ;
            if (y1>=ektos) break ;
            what=str[a];
            x1=pos[a][0] ; 
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
            }
            refresh();  
            goto DIPLO_KL ;

    }
        do {
        pev = SDL_PollEvent(&sdlev);
       //while (SDL_PollEvent(&sdlev) && sdlev.type ==SDL_MOUSEMOTION) continue;
       mx = sdlev.button.x ; my= sdlev.button.y ;
       SDL_FlushEvent(SDL_MOUSEMOTION);
        if (mx>xr || mx<xl) continue;
        if (my>yb || my<yt) continue;
        y1=(my-yt)/bh ;
        y1=yt+(y1*bh);
        if (y1>= ektos || y1<yt) continue;
        if(y1>pos[ar][1]) y1=pos[ar][1];
        diaf1=2*xr;
        //if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        f = 0 ;
        while (pos[f][1]!=y1) f++ ;
        while (pos[f][1]==y1) {
            diaf2=abs (pos[f][0]-mx);
            if (diaf2<diaf1) {diaf1=diaf2 ; f++ ; continue ; }
            else break; }
    curend= --f;
    
    if (curend>=ar) curend=ar-1;
      
    if(!vam[0]) {
        // ΒΑΦΩ ΑΡΧΙΚΑ //
        if (curst==curend) continue ;
        vam[0]=1;
        
        if (curend<curst) { vam[1]=curend ; vam[2]=curst ; pros=0; curst=vam[1]; curend=vam[2]; }
        else { pros=1 ; vam[1]=curst; vam[2]=curend ; }
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1= pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) { for(i=x1;i<xr-1;i++)  {_putpixel (i,f); }}refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
    
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f); } f++ ;}
        }
        refresh();continue ;}
        
        if (pros) {
        
        if (curend>vam[2]) {
       
       // Βάφω από vam[2] έως νέο curend //
             setcolor (COLOR (epr,epg,epb));  
       for (a=vam[2]+1; a<=curend; a++) {
       what=str[a];
       x1=pos[a][0] ; y1= pos[a][1] ;
      
       if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }refresh(); continue ;}
       mem_int=gouv[what].where ;
       for(f=0; f<gouv[what].hei ; f++) {
       for(i=0;i<gouv[what].wid;i++) {
       co.lor = *mem_int++;
       if (!co.lor) { _putpixel(x1+i , y1+f); continue;}}}
  
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
        }   
       vam[2]=curend; vam[0]=1;
       refresh();continue ;}
            
     if ((curend<vam[2]) && (curend>vam[1])) {
           //ξεβάφω MONON.. //
          setcolor (COLOR (bkr,bkg,bkb));  
        for (a=curend; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
       
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
         
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[2]=curend;
        vam[0]=1;
        refresh();continue ;
    }       
    
    if (curend<=vam[1]) {
        
    // Ξεβάφω από vam[1] έως vam[2] //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }       
        
        if (curend==vam[1])  {vam[0]=0 ; curst=curend ; refresh(); continue ;}
        vam[2] = curst ; vam[1]=curend ; pros=0; vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        curst=vam[1] ; curend=vam[2];
        continue ;}}
        else {
        // Από εδώ και πέρα σημαίνει pros=0 //
        
        if (curend<curst) {
            // Βάφω από curend έως vam1 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=curend; a<=vam[1]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
       
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();
        vam[1]=curend; curst=vam[1];vam[0]=1;continue;}
        
        if ( (curend>vam[1]) && (curend<vam[2]) ) {
        //ξεβάφω MONON.. //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<curend; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }            
        refresh(); vam[1]=curend ; curst=vam[1]; continue; }
        
        if (curend >= vam[2]) {
        // Ξεβάφω από vam1 έως vam2 //
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1 = pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh();continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        //else setcolor (COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
        // 
        //_putpixel(x1+i , y1+f);}}
        //setcolor (COLOR (bkr,bkg,bkb));  
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}              
        }
        
        if (curend==vam[2]) {curst=curend ; vam[0]=0 ; continue ; }
        
        vam[1]=vam[2]; vam[2]=curend; curst=vam[1]; pros=1;vam[0]=1;
        // Βάφω από vam1 έως vam2 //
        setcolor (COLOR (epr,epg,epb));  
        for (a=vam[1]; a<=vam[2]; a++) {
        what=str[a];
        x1=pos[a][0] ; y1=pos[a][1] ;
        if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f); }}
      
       while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
        }
        refresh();continue;}}       
        
    }  while (!pev || sdlev.type!=SDL_MOUSEBUTTONUP) ;
DIPLO_KL:
    cur = curst;
    if ( (!vam[0]) && (cur==ar-1) && (chb) ) cur=ar ;
    if (vam[0]) {
    // ENHMEVSH pre_cur !!!
    blosta=-1 ; bloend=-1; blo_pre_cur=0;
    f=vam[1];
    if (f) {    while (pos[f][1]>yt) f--;
                  while (pos[f][0]!=xl) f--;
                  pre_cur=f;
            } else pre_cur=0;}
    x=pos[cur][0] ; y=pos[cur][1];
    continue;}
    
    // Right Click Menu !!                            Right Click Menu !!    
    
    else if (sdlev.button.button==SDL_BUTTON_RIGHT) { 
        
        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
        
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            f=cur;
        if (f) {
            while (pos[f][1]!=yt) f--;
            while (pos[f][0]!=xl) f--;
            ano_ar=f; } else ano_ar=cur;
            
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; cur_ghost=0;
    }
        
         
        if (fnd_but) {
            if (!ar) {fnd_but=0; puticon(xr-36,yt-20,mem_find,255); continue ;}
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            if (keyb_gr) {ton=0 ; dial=0 ;}
            convertinp_strstr  (1, str, arped, &how_many, &cur_ghost);
            ghost=inp_mem_ghost;
            if (!ghost)  {
                if (!how_many) {
                    if (keyb_gr) information (0,"Δεν βρέθηκε τίποτε !",0);
                    else information(0,"Nothing found !",0);
                    }
                continue ; }
            if (keyb_gr) sprintf(str1024,"Προέκυψε ταύτιση σε %d σημεία!", how_many);
            else sprintf(str1024,"Identity occurred in %d points!", how_many);
            information (0,str1024,0);
            if (vam[0]) {                              // ξεβάφω
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;pre_cur=0;
            }
            cur=cur_ghost;
            y=pos[cur][1];
            x=pos[cur][0]; 
            if (cur) {
                f=0;
                while (pos[cur-f][0] !=xl)  f++;
                diaf3=pos[cur-f][1]-yt;
                for (i=0;i<=ar;i++) pos[i][1]-=diaf3;
                ano_ar=cur-f;
                }
            else ano_ar=0;
            x=pos[cur][0] ; y=pos[cur][1]; 
            setcolor (COLOR(bkr,bkg,bkb));  
            for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
            refresh();
            
            for (a=ano_ar; a<ar; a++) {
                what=str[a];
                if (what==200) continue ;
                y1=pos[a][1];
                if (y1>=ektos) break ;
                x1=pos[a][0];
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) {
                    if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                    else continue ;
                }

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                _putpixel(x1+i , y1+f);}}
                if (ghost[a]) {
                    while (f<bh) {
                    setrgbcolor(selred);
                    for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                }
            }
            refresh();
            
            goto barovios ;
        }
      
        
         if (!diak) {
        getimage(x,y,x+1,y+bh-1,mem_cu);   
        diak=1;
        setrgbcolor(col_cu); 
        for (f=0;f<bh;f++) { for (i=0;i<2;i++) {
        _putpixel(x+i,y+f) ;} }
        refresh() ; 
                        }
                           
         if ( (!vam[0]) && (ar) ) {
         what=str[cur];
         if (what<164) {
         setcolor (COLOR (epr,epg,epb));  
         mem_int=gouv[what].where ;
         for(f=0; f<gouv[what].hei ; f++) {
         for(i=0;i<gouv[what].wid;i++) {
         co.lor = *mem_int++;     
         if (! co.lor) _putpixel(x+i , y+f);}}
         while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
         } }
         
        if (keyb_gr) {ton=0 ; dial=0 ;}
       
        mx = sdlev.button.x ; my= sdlev.button.y ;
        if (mx<= info.left) mx=info.left+1;
        if (my<= info.top) my=info.top+1;
        size=imagesize (0,0,181,259);
        mem_undrme=malloc(size);
        if (mem_undrme==NULL) {printf ("Memory Problem \n") ; continue ;}
        x2= ((mx+180)<info.right) ? mx : info.right-181;
        y2= ((my+258)<info.bottom-40) ? my : info.bottom-299 ;
        getimage (x2-1,y2-1,x2+180,y2+258,mem_undrme);
        // ZVGRAFIZEI MENU
        start=0;
        _areacls (x2-1,y2-1,x2+180,y2+240,180,180,180);
        setrgbpalette(18,180,180,180); // Color of area behind circles = 18
        setrgbpalette(20,128,255,0); // Light Green = 20
        _bareacls (x2-1,y2+241,x2+180,y2+258,cbrown);
        //putimage(x2,y2,mem_rmenu,0);
        // My putimage
         mem_int=(mem_rmenu +8);
        for (f=0;f<240;f++) {
           for(i=0 ; i < 180; i++) {
        co.lor= *(mem_int++);
        if (co.rgb[3]) {setcolor(COLOR (co.rgb[2],co.rgb[1],co.rgb[0]));
         
        _putpixel (x2+i,y2+f);}}} 
        refresh(); 
        rmed[11]=0;
        rmed[0] = (ar) ? 0 : 1 ;
        rmed[1] = ( (orio==ar) && (!vam[0]) ) ? 1 : 0 ;
        rmed[2] = (savefile[0]=='\0') ? 1 : 0 ;
        rmed[5]=1;
        if (vam[0]) {
            rmed[3] = rmed[4] = 2;
            rmed[5]=0; blosta=-1 ; bloend=-1; blo_pre_cur=0;
                        }
        else        {
            rmed[3] = (ar) ? 0 : 1;
            rmed[4] = ( (blosta<0) || (cur<=blosta) ) ? 1 : 0 ;
                       }
            
        if ((blosta>=0) && (bloend>blosta)) rmed[5]=0 ;
        
        rmed[6] = ( (vam[0]) || (!rmed[5]) ) ? 0 : 1 ;
        rmed[7] = (SDL_HasClipboardText()) ? 0 : 1 ;
        if (!rmed[7]) rmed[7] = ( (orio==ar) && (!vam[0]) ) ? 1 : 0 ;
        rmed[8] = (ar) ? 0 : 1;
        rmed[9] = (undo) ? 0 : 1;
        rmed[10] = (ar) ? 0 : 1 ;
        kyk1=-1; outmen=1;
        esc_go=0;
        
        SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
        do {
        SDL_PollEvent(&sdlev);
        if (sdlev.type!=SDL_MOUSEMOTION && sdlev.type!=SDL_KEYDOWN) continue;
        if ( (secwin) && (sdlev.motion.windowID == sdlwin2) ) { continue ;}
        mx=sdlev.motion.x ; my=sdlev.motion.y;
        if ( sdlev.type==SDL_KEYDOWN ) {
            if (sdlev.key.keysym.scancode==SDL_SCANCODE_ESCAPE ) {mx=x2+170;my=y2+230; esc_go=1;}
            else continue ;}
        if (mx>x2 && mx<x2+180 && my>y2 && my < y2+240 ) {
        if (outmen) {
        outmen=0;
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        SDL_SetCursor(cursor);}
        x1=(mx-x2)/60;
        y1=(my-y2)/60;
        kyk=(y1*3) + x1 ;
        
        if (!start) {
        setrgbcolor(10+rmed[kyk]);
        mem_efedr1 = mem_rmenu+8+ (y1*43200)+ (x1*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
           
        if ((*mem_int++)) continue;
        _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
        refresh();
        kyk1=kyk;
        x3=x1 ; y3 = y1 ;
        start=1;
        if (keyb_gr) outsouv_col (x2+1,y2+241,rmestrgr[kyk],1,chrpnt[rmed[kyk]],cbrown);
        else outsouv_col (x2+1,y2+241,rmestren[kyk],0,chrpnt[rmed[kyk]],cbrown);
        continue ;}
        
        if (kyk==kyk1) continue ;
        //EPANAFEREI XRVMA EPILOGHS
        setrgbcolor (18); 
        mem_efedr1 = mem_rmenu+8+(y3*43200)+ (x3*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
        if ((*mem_int++)) continue;
        _putpixel (x2+x3*60+i-1,y2+y3*60+f-1);}}
        _bareacls (x2-1,y2+241,x2+180,y2+258,cbrown);
        
        // XRVMATIZEI NEA EPILOGH
        kyk1=kyk ; x3=x1 ; y3 = y1 ;
        setrgbcolor (10+rmed[kyk]);
        mem_efedr1 = mem_rmenu+8+(y1*43200)+ (x1*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
        if ((*mem_int++)) continue;
        _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
        if (keyb_gr) outsouv_col (x2+1,y2+241,rmestrgr[kyk],1,chrpnt[rmed[kyk]],cbrown);
        else outsouv_col (x2+1,y2+241,rmestren[kyk],0,chrpnt[rmed[kyk]],cbrown);
        refresh();
        continue ;    
        }
        else {
       
        if (start) {
        setrgbcolor(18);
        mem_efedr1 = mem_rmenu+8+(y3*43200)+ (x3*240);
        for (f=0;f<59;f++) {
        mem_int=(mem_efedr1+(f*720));
        for (i=0;i<59;i++) {
        if ((*mem_int++)) continue;
        _putpixel (x2+x3*60+i-1,y2+y3*60+f-1);}}
        bareacls (x2-1,y2+241,x2+180,y2+258,cbrown);
        start=0; kyk1=-1;} 
        if (outmen) continue;
        outmen=1;
        cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
        SDL_SetCursor(cursor);
        continue ;   
        }
        
        
        } while ( (sdlev.type !=SDL_MOUSEBUTTONDOWN || (outmen) ) && (!esc_go) ) ;

       
        
        if( (sdlev.button.button==SDL_BUTTON_RIGHT) || (esc_go) ) { putimage (x2-1,y2-1,mem_undrme,0);
         if ( (!vam[0]) && (ar) ) {
         what=str[cur];
         if (what<164) {
         setcolor (COLOR (bkr,bkg,bkb));  
         mem_int=gouv[what].where ;
         for(f=0; f<gouv[what].hei ; f++) {
         for(i=0;i<gouv[what].wid;i++) {
         co.lor = *mem_int++;
         if (! co.lor) _putpixel(x+i , y+f);}}
         while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
         } }        
        free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
        SDL_SetCursor(cursor); continue;}
        else if (sdlev.button.button==SDL_BUTTON_LEFT) {
            
            auto int pev ;
            switch (kyk) {
                
                case 0: 
                    
                    // Save as file with ZENITY -  Save as
                    if (!ar) break ;
                    
                    if (savefile[0]=='\0') sprintf (file_2,"%s%s",user_path,eggr_str);
                    else {
                        i=strlen(savefile);
                        while (savefile[i]!='/' && (i) ) i--;
                        for (f=0;f<=i && f<255;f++) file_2[f]=savefile[f];
                        file_2[f]='\0';
                    }
                    if (keyb_gr) strcpy (file_1,"Eπιλέξτε και ΣΩΣΤΕ");
                    else strcpy (file_1,"Choose and SAVE");
                    //sprintf(savefile,"zenity --file-selection --save --title=%s --filename=%s --file-filter='*.inp' --confirm-overwrite > %s%s",file_1,file_2,path_name,"zenity.txt");
                    //system(savefile);
                    //refresh();
                    //sprintf (savefile,"%s%s",path_name,"zenity.txt");
                    //fp = fopen(savefile,"r");
                    //if (fp==NULL) {savefile[0]='\0'; break;}
                    
                    if (!fsel_code) { savefile[0]='\0'; break;}
                    
                    switch (fsel_code) {
                        
                                                    
                        case 1 : //yad
                            sprintf (big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.inp --center --width=%d --height=%d",efarm_path,file_1,file_2,(int) (2*DM.w/3) , (int) (2*DM.h/3) ) ;
                            break ;
                            
                        case 2 : //kdialog
                            sprintf (big_char,"%s --getsavefilename %s",efarm_path,file_2);
                            break;
                            
                        case 3 : //zenity
                            sprintf(big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.inp",efarm_path,file_1,file_2);

                    }
                    
                    

                    f = fileselector( big_char, savefile , 512);
                    if (!f) { savefile[0]='\0'; break;}
                    
                    diaf1=strlen(savefile); 
                    if ( (!diaf1)  || (diaf1>507) ) {savefile[0]='\0'; break;}
                    
                    for (f=1;f<diaf1;f++) {
                    if (savefile[f]!='.') continue ;
                    else {for (a=f ; a<diaf1 ; a++) savefile[a]='\0';}
                    break;}
                    
                    strcat(savefile,".inp");
                                        
                    mem_efedr2=str;
                    fp=fopen(savefile,"wb");
                    if (fp==NULL) {savefile[0]='\0'; break;}
                    fide_fp = fileno (fp) ;
                    fwrite (pedaba,4,4,fp);
                    fwrite (&ar,2,1,fp);
                    fwrite (mem_efedr2, ar,1, fp);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =0 ; y1 = 0;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp);
                    break ;
                
                case 1:
                    // LOAD FILE with Zenity !!
                    
                    // Ενεργοποίηση UNDO
                    if (ar) {
                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
                        
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                        undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    }
                    
                    if (vam[0]) {                              // αναδιατάσσω εσωτερικά το str
                    vam[0]=2;
                    for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                    diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                    cur=vam[1];
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    }
                    if(!ins) elxor=orio-ar; else elxor=orio-cur;
                    if (!elxor) break ;
                                                        
                    mem_efedr1=malloc(1024);
                    if (mem_efedr1==NULL) {printf ("Out of Memory"); break;}
                    loadfile=mem_efedr1;
                    
                    if (savefile[0]=='\0') sprintf (file_2,"%s%s",user_path,eggr_str);
                    else {
                        i=strlen(savefile);
                        while (savefile[i]!='/' && (i) ) i--;
                        for (f=0;f<=i && f<255;f++) file_2[f]=savefile[f];
                        file_2[f]='\0';
                    }
                    if (keyb_gr) strcpy (file_1,"Eπιλέξτε και ΦΟΡΤΩΣΤΕ");
                    else strcpy (file_1,"Choose and LOAD");
                    
                    //sprintf(loadfile,"zenity --file-selection --title=%s --filename=%s > %s%s",file_1,file_2, path_name,"zenity.txt");
                    //system(loadfile);
                    //refresh();
                    //sprintf (loadfile,"%s%s",path_name,"zenity.txt");
                    //fp = fopen(loadfile,"r");
                    //if (fp==NULL) {free (mem_efedr1) ; break;}
                    //f=0;
                    //do {
                    //loadfile[f]= (char) getc(fp);
                    //f++;
                    //}while ( (!feof(fp)) && (f<512) );
                    //fclose(fp);
                    //if (f<3) {free(mem_efedr1) ; break;}
                    //f-=2; loadfile[f]='\0';
                    if (!fsel_code) { free(mem_efedr1) ; break; }
                    
                    switch (fsel_code) {
                        case 1 : //yad
                            sprintf (big_char,"%s --file-selection --title=\"%s\" --filename=%s --center --width=%d --height=%d",efarm_path,file_1,file_2,(int) (2*DM.w/3) , (int) (2*DM.h/3) ) ;
                            break ;
                            
                        case 2 : //kdialog
                            sprintf (big_char,"%s --getopenfilename %s",efarm_path,file_2);
                            break;
                            
                        case 3 : //zenity
                            sprintf(big_char,"%s --file-selection --title=\"%s\" --filename=%s",efarm_path,file_1,file_2);
                     }

                    f = fileselector( big_char, loadfile , 1024);
                    if (!f) { free(mem_efedr1) ; break; }
                    
                    diaf2=strlen(loadfile);
                    if ( !diaf2 ) {free(mem_efedr1) ; break;}
                   
                    file_flag=0;
                    fp=fopen(loadfile,"rb");
                    if (fp==NULL) {free (mem_efedr1) ; break;}
                    for (f=0 ; f<4 ; f++) {
                    fread(&pedaca,4,1,fp);
                    if (feof(fp)) { file_flag=1; break; }
                    if (pedaca!=pedaba[f]) {file_flag=1;break;}}
                    
                    if (!ins) {
                        for(f=ar,i=0;f>=cur;f--,i++) str[orio-i]=str[f];
                        diaf1=orio-i+1;}
                        
                          // Προσδιορισμός του Pre_Paste
            
                    if (!pre_cur) {
                    f=cur;
                    if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                    } else pre_paste=0;} 
                   else pre_paste=0;
                    
                    a=0;
                    if (!file_flag) {
                    // It is rather an .inp file - ok !!
                    strcpy(savefile,loadfile);
                    fread(&diaf2,2,1,fp);
                    cha=0;
                    do {
                        if (feof(fp)) break;
                        fread(&what,1,1,fp);
                        if ( what>=0 && what<164 ) cha=1;
                        if ( what==200 || (cha) ) {str[cur+a]=what;
                        diaf2-- ; a++ ; elxor-- ;cha=0;}
                        else break;
                    } while ( (diaf2) && (elxor) );
                    }
                    else
                    {                       
                    // It is not an .inp file - May be it is a text file ....
                    if (ferror(fp)) clearerr(fp);
                    fclose (fp);
                    fp=fopen(loadfile,"r");
                    //user_ans=(keyb_gr) ? alert(3,NULL,NULL) : alert(4,NULL,NULL);
                    if (fp!=NULL) {
                    fread(&ch,1,1,fp);
                    
                    while ( (ch!='\0') && (elxor) ) {
                    if (feof(fp)) break;
                    
                    if ( ch<0) {
                    if (keyb_gr){
                    fread(&cha,1,1,fp);
                    if (feof(fp)) break;
                    ch1= ( (256*ch) + cha ) ;
                    for (i=0 ; i<69 ; i++) {
                        if (ch1==unico[i][0]) {
                            str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                            if (i==69) {str[cur+a]=0; a++;elxor--;ch=cha;continue;}
                    fread(&ch,1,1,fp); continue;}
                    else {str[cur+a]=0; a++;elxor--;fread(&ch,1,1,fp); continue;}}
                    
                    else {
                    if (ch=='\n') {str[cur+a]=200; a++;elxor--; fread(&ch,1,1,fp); continue;}
                    for(i=0;i<95;i++) {
                        if (ch==gouv[i].who) {
                            str[cur+a]=i ; a++ ; elxor-- ;break;}}
                            if (i==95) {str[cur+a]=0; a++;elxor--;}
                    fread(&ch,1,1,fp);
                  } } 
                        
                    }}
                    if (fp!=NULL) {
                    if (ferror(fp)) {printf ("Disk Error \n"); clearerr(fp);}
                    fclose (fp);
                    }
                    if (!ins) ar +=a ; else {
                    if (cur+a > ar) ar=(cur+a); }
                    str[ar]=255;
                    if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
                 
                    free(mem_efedr1) ;
                    putimage (x2-1,y2-1,mem_undrme,0);
                    free(mem_undrme);
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);
                   
                    if (vam[0]==2) vam[0]=0;
                    goto esot_anadiat;
                                   
                case 2: // Save ..
                    if (rmed[2]) {
                        information(8-keyb_gr,NULL,NULL);
                        break;}
                    user_ans = alert(0,"Save data to :",savefile);
                    if (user_ans !=1) break;
                    clipbo = strstr(savefile,".inp");
                    if (clipbo!=NULL) {
                    mem_efedr2=str;
                    fp=fopen(savefile,"wb");
                    if (fp==NULL) {savefile[0]='\0'; break;}
                    fide_fp = fileno (fp) ;
                    fwrite (pedaba,4,4,fp);
                    fwrite (&ar,2,1,fp);
                    fwrite (mem_efedr2, ar,1, fp);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =2 ; y1 = 0;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp); break;}
                    else {
                    clipbo=strstr(savefile,".txt");
                    if (clipbo!=NULL) {
                    size=1024;        
                    clipbo=malloc(size);
                    if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; } 
                    fp=fopen(savefile,"w");
                    if (fp==NULL) {savefile[0]='\0'; free(clipbo); break;}
                    fide_fp = fileno (fp) ;
                    i=0;
                    for (f=0 ; f<ar ; f++) {
                    if (i>=size-4) {
                            size+=1024;
                            remem=realloc(clipbo,size);
                            if (!remem) {if(clipbo) free(clipbo);}
                            clipbo=remem;
                            if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; }
                    }
                    what=str[f];
                    if (what<95) {clipbo[i++]=gouv[what].who;}
                    else if ( (what>94) && (what<164) ) {
                        cha=((unico[what-95][0]/256)-255);
                        chb = (unico[what-95][0] % 256);
                        clipbo[i++]=cha; clipbo[i++]=chb;}
                        //putc(cha,fp); putc(chb,fp);}
                      
                       else if (what==200) {clipbo[i]='\0'; fprintf (fp,"%s\n",clipbo); i=0; }                    
                    } 
                    if (i) {clipbo[i] ='\0'; fprintf (fp,"%s",clipbo);}
                    free(clipbo);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =2 ; y1 = 0;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp);                    
                    break ;}
                    savefile[0]='\0';
                    break ;}
                    
                                        
                case 3: // ΑΡΧΗ ΜΠΛΟΚ
                    if (rmed[3]) {
                        if (vam[0]) { information(12-keyb_gr,NULL,NULL); }
                        break;}
                    if (bloend>0) {
                        if (cur>=bloend) {blosta=-1 ; bloend=-1 ; blo_pre_cur=0; break ;}}
                    f=blosta=cur;
                // ENHMEVSH blo_pre_cur !!!
                    
                    if (f) {    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    blo_pre_cur=f;
                            } else blo_pre_cur=0;
                     x1 =0 ; y1 = 1;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                            
                    break;
                    
                case 4: //ΤΕΛΟΣ ΜΠΛΟΚ
                     if (rmed[4]) {
                          if (vam[0]) { information(12-keyb_gr,NULL,NULL); }
                          else if (blosta==-1) { information(10-keyb_gr,NULL,NULL); }
                         break;}
                     bloend= (cur==ar) ? cur-1 : cur ;
                     if (bloend<0) bloend=0;
                     vam[0]=1;vam[1]=blosta;vam[2]=bloend;pre_cur=blo_pre_cur;
                     blosta=-1 ; bloend=-1 ; blo_pre_cur=0;
                     
                     //PRASINO XROMA
                     x1 =1 ; y1 = 1;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                        
                     putimage (x2-1,y2-1,mem_undrme,0);
                    free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);
                    // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                    if(diak) {putimage(x,y,mem_cu,0); refresh(); diak=0;}
                    setcolor (COLOR (epr,epg,epb));
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1=pos[a][1] ;
                    if (y1<yt) continue ;
                    if (y1>=ektos) break ;
                    what=str[a];
                    x1=pos[a][0] ; 
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                    refresh();
                    continue;
                    break ;
                
                case 5: // DIAGRAFH DELETE BLOCK
                if (rmed[5]) {
                     if (!vam[0]) { information(14-keyb_gr,NULL,NULL); }
                    break;}

                // Ενεργοποίηση UNDO
                if (ar) {
                undo_lasfile++;
                sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                fpundo=fopen(file_1,"wb");
                if ( fpundo!=NULL ) {
                fide_undo = fileno (fpundo) ;
                undo=1;
                f=cur;
                if (f) {while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    wherp = f;} else wherp = 0;
                fwrite (&cur,2,1,fpundo);
                fwrite (&ar,2,1,fpundo);
                fwrite (str,1,ar,fpundo);
                fwrite(vam,2,3,fpundo);
                fwrite (&wherp,2,1,fpundo);
                fwrite(&pre_cur,2,1,fpundo);
                fwrite(&ins,2,1,fpundo);
                fwrite(&gr_flag,2,1,fpundo);
                fwrite(savefile,1,512,fpundo);
                fwrite (pxl,4,1,fpundo);
                fwrite (pyt,4,1,fpundo);
                fwrite (pxr,4,1,fpundo);
                fwrite (pyb,4,1,fpundo);
                fwrite (&orio,4,1,fpundo);
                if (ferror(fpundo)) { 
                    clearerr(fpundo); fclose(fpundo);
                    undo_lasfile--;
                    if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                }
                else {
                fdatasync (fide_undo);
                fsync (fide_undo);
                fclose(fpundo);
                    if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}

                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                        undo_firfile++;}
                    }
                }
                else {
                    undo_lasfile--;
                    if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                }
                }
                
                x1 =2 ; y1 = 1;
                setrgbcolor(20);
                mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                for (f=0;f<59;f++) {
                mem_int=(mem_efedr1+(f*720));
                for (i=0;i<59;i++) {
                if ((*mem_int++)) continue;
                _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                    refresh(); 
                putimage (x2-1,y2-1,mem_undrme,0);
                free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                SDL_SetCursor(cursor);                         
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                cur = (vam[1]) ? vam[1]-1 : 0 ;
                goto esot_anadiat;  
                                    
                case 6: // Copy to Clipboard
                     if (rmed[6]) break;
                     x1 =0 ; y1 = 2;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                     putimage (x2-1,y2-1,mem_undrme,0);
                    free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);                         
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    size=0;
                    for (f=vam[1] ; f<=vam[2] ; f++) {
                        what=str[f];
                        if (what<95) size++;
                        else if ( (what>94) && (what<164) ) size+=2;
                        else size++; }
                        size++;
                        clipbo=malloc(size);
                        if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                        a=0;
                        for (f=vam[1] ; f<=vam[2] ; f++) {
                        what=str[f];
                        if (what<95) {
                            clipbo[a]=gouv[what].who; a++;}
                        else if ( (what>94) && (what<164) ) {
                            cha=((unico[what-95][0]/256)-255);
                            chb = (unico[what-95][0] % 256);
                            clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                        else if (what==200) {clipbo[a]='\n' ; a++;}}
                        clipbo[a]='\0';
                        size=SDL_SetClipboardText(clipbo);
                        if (!size) {
                        
                        setcolor (COLOR (epr1,epg1,epb1));  
                            for (a=vam[1]; a<=vam[2]; a++) {
                            y1=pos[a][1] ;
                            if (y1<yt || y1>=ektos) continue;
                            what=str[a];
                            x1=pos[a][0] ; 
                            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
                            mem_int=gouv[what].where ;
                            for(f=0; f<gouv[what].hei ; f++) {
                            for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                            refresh();
                        } 
                        free(clipbo);
                        continue;
                                       
                case 7: // Paste from Clipboard
                     if (rmed[7]) break;
                     if (!SDL_HasClipboardText()) break;
                     clipbo=SDL_GetClipboardText();
                    if (clipbo==NULL) break;
                    
                    // PRASINO XROMA
                    x1 =1 ; y1 = 2;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh();                    

                    // Ενεργοποίηση UNDO
                    if (ar) {
                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                                // Τσεκάρω για snapshot...
                            strcpy(file_2,user_path);
                            strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                            fpundo=fopen(file_2,"rb");
                            if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
 
                            a=undo_lasfile-undo_max;
                            sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                            rename (file_1,file_2);
                            undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    }
                        
                    putimage (x2-1,y2-1,mem_undrme,0);
                    if (!vam[0]) {
                    what=str[cur];
                    if (what<164) {
                    setcolor (COLOR (bkr,bkg,bkb));  
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (! co.lor) _putpixel(x+i , y+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
                    } }   
                    free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);     

                    if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    setcolor (COLOR (bkr,bkg,bkb));  
                    for (a=vam[1]; a<=vam[2]; a++) {
                    y1= pos[a][1] ;
                    if (y1>=ektos || y1<yt) continue ;
                    what=str[a];
                    x1= pos[a][0] ; 
                    if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                    }
                    vam[0]=2;
                    // Εσωτερική Αναδιάταξη !
                    cur = vam[1] ;
                    for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                    diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                    }
                    
                    if(!ins) elxor=orio-ar; else elxor=orio-cur;
                    if ( (!elxor) && (!vam[0]) ) {SDL_free(clipbo); continue;} 
                    if (vam[0]==2) vam[0]=0;
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    if (!ins) {
                        for(f=ar,i=0;f>=cur;f--,i++) str[orio-i]=str[f];
                        diaf1=orio-i+1;}
                        
                                 // Προσδιορισμός του Pre_Paste
            
                    if (!pre_cur) {
                    f=cur;
                    if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                } else pre_paste=0;} 
                   else pre_paste=0;
                        
                    f=0 ; a=0 ;
                    ch=clipbo[f];
                    while ( (ch!='\0') && (elxor) ) {
                        if (ch<0) {
                            
                            f++ ; ch1= ( (256*ch) + clipbo[f] ) ;
                            for (i=0 ; i<69 ; i++) {
                                if (ch1==unico[i][0]) {
                                    str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                                    if (i==69) {str[cur+a]=0 ; a++ ; elxor--; f--; }
                            f++; ch=clipbo[f];continue;
                         }
                        else {
                            if (ch=='\n') {str[cur+a]=200; a++;elxor--; f++; ch=clipbo[f]; continue;}
                            for(i=0;i<95;i++) {
                                if (ch==gouv[i].who) {
                                    str[cur+a]=i ; a++ ; elxor-- ;break;}}
                                    if (i==95) {str[cur+a]=0 ; a++ ; elxor--;}
                            f++;ch=clipbo[f];
                            }
                    }
                    if (!ins) ar +=a ; else {
                        if (cur+a > ar) ar=(cur+a); }
                     if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
                    SDL_free(clipbo);
                    goto esot_anadiat;
                    
                case 8: // Save as .txt
                    if (!ar) break ;
                    
                    if (savefile[0]=='\0') sprintf (file_2,"%s%s",user_path,eggr_str);
                    else {
                        i=strlen(savefile);
                        while (savefile[i]!='/' && (i) ) i--;
                        for (f=0;f<=i && f<255;f++) file_2[f]=savefile[f];
                        file_2[f]='\0';
                    }
                    if (keyb_gr) strcpy (file_1,"Eπιλέξτε και ΣΩΣΤΕ");
                    else strcpy (file_1,"Choose and SAVE");
                    //sprintf(savefile,"zenity --file-selection --title=%s --filename=%s --file-filter='*.txt' --save --confirm-overwrite > %s%s",file_1,file_2,path_name,"zenity.txt");
                    //system(savefile);
                    //refresh();
                    //sprintf (savefile,"%s%s",path_name,"zenity.txt");
                    //fp = fopen(savefile,"r");
                    //if (fp==NULL) {savefile[0]='\0'; break;}
                    //f=0;
                    //do {
                    //savefile[f]= (char) getc(fp);
                    //f++;
                    //}while ( (!feof(fp)) && (f<510) );
                    //fclose(fp);
                    //if (f<3) {savefile[0]='\0'; break;}
                    //f-=2; savefile[f]='\0';
                    if (!fsel_code) { savefile[0]='\0'; break;}
                    switch (fsel_code) {
                        case 1 : //yad
                            sprintf (big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.txt --center --width=%d --height=%d",efarm_path,file_1,file_2,(int) (2*DM.w/3) , (int) (2*DM.h/3) ) ;
                            break ;
                            
                        case 2 : //kdialog
                            sprintf (big_char,"%s --getsavefilename %s",efarm_path,file_2);
                            break;
                            
                        case 3 : //zenity
                            sprintf(big_char,"%s --file-selection --save --confirm-overwrite --title=\"%s\" --filename=%s --file-filter=*.txt",efarm_path,file_1,file_2);

                    }

                    f = fileselector( big_char, savefile , 512);
                    if (!f) { savefile[0]='\0'; break;}
                    
                    diaf1=strlen(savefile); 
                    if ( (!diaf1)  || (diaf1>507) ) {savefile[0]='\0'; break;}
                    for (f=1;f<diaf1;f++) {
                    if (savefile[f]!='.') continue ;
                    else {for (a=f ; a<strlen(savefile) ; a++) savefile[a]='\0';}
                    break;}
                    
                    strcat(savefile,".txt");
                    size=1024;        
                    clipbo=malloc(size);
                   
                    if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; } 
                    fp=fopen(savefile,"w");
                    if (fp==NULL) {savefile[0]='\0'; free(clipbo); break;}
                    fide_fp = fileno (fp) ;
                    i=0;
                    for (f=0 ; f<ar ; f++) {
                    if (i>=size-4) {
                            size+=1024;
                            remem=realloc(clipbo,size);
                            if (!remem) {if(clipbo) free(clipbo);}
                            clipbo=remem;
                            if (clipbo==NULL) {printf ("Out of Memory \n"); savefile[0]='\0' ; break ; }
                    }
                    what=str[f];
                    if (what<95) {clipbo[i++]=gouv[what].who;}
                    else if ( (what>94) && (what<164) ) {
                        cha=((unico[what-95][0]/256)-255);
                        chb = (unico[what-95][0] % 256);
                        clipbo[i++]=cha; clipbo[i++]=chb;}
                        //putc(cha,fp); putc(chb,fp);}
                      
                       else if (what==200) {clipbo[i]='\0'; fprintf (fp,"%s\n",clipbo); i=0; }                    
                    } 
                    if (i) {clipbo[i] ='\0'; fprintf (fp,"%s",clipbo);}
                    free(clipbo);
                    if (ferror(fp)) {printf ("Disk Error \n"); savefile[0]='\0' ; clearerr(fp);}
                    else { x1 =2 ; y1 = 2;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh(); 
                    }
                    fdatasync (fide_fp);
                    fsync (fide_fp);
                    fclose (fp);
                    break ;                   
                               
                case 9: // Undo
                        i=0;
                    if (!undo) {
                        strcpy(file_1,user_path);
                        strcat(file_1,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_1,"rb");
                        if (fpundo!=NULL) {
                        if (keyb_gr) user_ans=alert(0,"Δεν έχει σωθεί στιγμιότυπο για επαναφορά !" ,"Υπάρχει όμως ένα παλαιότερο - ίσως άσχετο. Θέλετε να φορτωθεί ;");
                        else user_ans=alert(0,"There is not a relative snapshot !","There is an older snapshot - perhaps irrele-  vant. Do you want to try it ?");
                        fclose(fpundo);
                        if (user_ans!=1) break ;
                        i=1;
                        }
                        else {information(24-keyb_gr,0,0);break;}
                    }
                    undo=2+i;
                    putimage (x2-1,y2-1,mem_undrme,0);
                    if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    free(mem_undrme);
                    free(mem_cu); 
                    free(mem_under); 
                    free(mem_flusa);  
                    free(mem_enter); 
                    free(mem_tent);
                    free(mem_arrs);
                    free(mem_info);
                    free(mem_find); free(mem_fonter); free(mem_link);
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu);
                    putimage(xep,yep,mem_undscr,0); free (mem_undscr);
                    putimage(xl-1,yt-21,mem1,0);
                    if (bar) putimage (xr+3,yt-1,mem_bar,0);
                    free(mem_bar);
                    free(mem1);
                    refresh();
                    ar=0; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                    SDL_SetCursor(cursor);
                    if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; cur_ghost=0;}
                    langex = (us_flag) ? 1 : 2 ;
                    return -10 ; // EIDIKH PERIPTVSH EPISTROFHS LOGV UNDO !!!
                                        
                case 10: // Delete All
                    if (!ar) break;
                    
                    // Ενεργοποίηση UNDO

                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
   
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                        undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    
                    
                     // PRASINO XROMA
                    x1 =1 ; y1 = 3;
                    setrgbcolor(20);
                    mem_efedr1 = mem_rmenu+(y1*43200)+ (x1*240);
                    for (f=0;f<59;f++) {
                    mem_int=(mem_efedr1+(f*720));
                    for (i=0;i<59;i++) {
                    if ((*mem_int++)) continue;
                    _putpixel (x2+x1*60+i-1,y2+y1*60+f-1);}}
                        refresh();          
                        
                    putimage (x2-1,y2-1,mem_undrme,0);
                    if (!vam[0]) {
                    what=str[cur];
                    if (what<164) {
                    setcolor (COLOR (bkr,bkg,bkb));  
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (! co.lor) _putpixel(x+i , y+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
                    } }        
                        free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                        SDL_SetCursor(cursor);
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    cur=0;ar=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;start=0,pre_paste=0;ton=0 ; dial=0 ;
                    str[cur]=255;
                    blosta = bloend = -1;
                    pos[0][0]=xl ; pos[0][1]=yt;
                    for (f=1;f<=orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                    x1=x =xl ; y1=y=yt;
                    if (bar) { putimage (xr+3,yt-1,mem_bar,0); bar=0; }
                    setcolor (COLOR(bkr,bkg,bkb));  
                    for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                    refresh();
                    if (inp_mem_ghost) { free(inp_mem_ghost); ghost=inp_mem_ghost=0; cur_ghost=0;} 
                    continue ;
                    
                case 11:
                    break ;
                
            }
            
         do {pev = SDL_PollEvent(&sdlev);
            if (sdlev.type == SDL_MOUSEBUTTONDOWN) { SDL_FlushEvent(SDL_MOUSEBUTTONDOWN); }
            else break ;
        } while (pev && sdlev.type == SDL_MOUSEBUTTONDOWN );
        
         putimage (x2-1,y2-1,mem_undrme,0);
         if (!vam[0]) {
         what=str[cur];
         if (what<164) {
         setcolor (COLOR (bkr,bkg,bkb));  
         mem_int=gouv[what].where ;
         for(f=0; f<gouv[what].hei ; f++) {
         for(i=0;i<gouv[what].wid;i++) {
         co.lor = *mem_int++;
         if (! co.lor) _putpixel(x+i , y+f);}}
         while (f<bh) {for(i=0;i<gouv[what].wid;i++)  {_putpixel(x+i , y+f);} f++ ;} refresh();
         } }        
            free(mem_undrme);cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
            SDL_SetCursor(cursor);     
            if (vam[0]==2) {vam[0]=0 ; goto esot_anadiat;}        
        }
                                                                }                                                                                    
              continue ;
             
    case SDL_KEYDOWN:
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        ch_scan=sdlev.key.keysym.scancode;
        ch_mod=SDL_GetModState();
        if (keyb_gr) {
        state=SDL_GetKeyboardState(NULL);
        if ((state[SDL_SCANCODE_RALT] || state[SDL_SCANCODE_LALT]) && (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])) { us_flag=abs (us_flag-1) ; gr_flag=abs(gr_flag-1) ; ton=0; dial=0; 
        if (us_flag) {
            ton=0 ; dial=0 ; putimage(xep+5,yep+4,mem_flusa,0);continue;}
        else {putimage(xep+5,yep+4,mem_flgr,0);
        continue ;}
        }}
        switch (ch_scan) { // Φεύγοντας από την switch με break πάμε για εκτύπωση !!
            
            case SDL_SCANCODE_ESCAPE :  
DROMO:
                f=cur;
                if (f) {while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    diaf1 = f;} else diaf1 = 0;
                    
                if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; }
                if (mem_small) hide_help_inp(hlpxt , hlpyt);
                str[ar]=255; putimage(xl-1,yt-21,mem1,0); putimage(xep,yep,mem_undscr,0);free(mem_undscr); free(mem1) ; free(mem_cu); 
                free(mem_under); free(mem_flusa);  free(mem_enter); free(mem_tent);if (keyb_gr) free(mem_flgr); 
                if (bar) { putimage (xr+3,yt-1,mem_bar,0); refresh(); }
                if (mem_bar) free(mem_bar);
                free(mem_rmenu);
                free(mem_find); free(mem_fonter); free(mem_link);
                langex = (us_flag) ? 1 : 2 ;
                free(mem_arrs); free(mem_info); cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
                SDL_SetCursor(cursor);refresh() ; ar=0;undo=0; undo_firfile=1; undo_lasfile=0 ;
                cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; return diaf1;
            
            case SDL_SCANCODE_SEMICOLON : //Τόνος για Ελληνικά

                if (!gr_flag) break ;
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME TONO - Περίπτωση διαλυτικών //
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        dial=1 ; continue ;
                    default : ton = 1; continue;}
                    
                    case SDL_SCANCODE_BACKSPACE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                    
                    // Ενεργοποίηση UNDO

                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
                     
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                            undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }

                    
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; 
                ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
                if (inp_mem_ghost) {free(inp_mem_ghost); ghost=inp_mem_ghost=0;}
esot_anadiat:  
                // ΕΣΩΤΕΡΙΚΗ ΑΝΑΔΙΑΤΑΞΗ 
                
                x1=xl ; y1=yt;
                for (a=0; a<ar; a++) {
                what=str[a];
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ; x1=xl ; y1+=bh; continue ;}
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) {
                    if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;}
                        x1=xl ; y1+=bh; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 str[ar]=255 ;
                 pos[ar][0]=x1 ; pos[ar][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 // ΝΕΑ ΕΜΦΑΝΙΣΗ
                //diaf2=cur;
                //if (diaf2) {while (pos [diaf2][0]!=xl) diaf2--;
                //if ( (pos[diaf2][1]-pos[0][1]) >= maxline*bh) {
                //diaf1=(pos[diaf2][1]-yt);
                //for (i=0;i<=ar;i++) pos[i][1]-=diaf1;}
                //else diaf2=0;
                //}
                
                if (pre_cur) {
                f=0;
                while (pos[pre_cur-f][0] != xl) f++;
                pre_cur-=f;
                diaf1=(pos[pre_cur][1]-yt);
                for (i=0;i<=ar;i++) pos[i][1]-=diaf1;}
                else {
                    if (pre_paste) {
                    pre_cur=pre_paste;
                    f=0;
                    while (pos[pre_cur-f][0] != xl) f++;
                    pre_cur-=f;
                    diaf1=(pos[pre_cur][1]-yt);
                    for (i=0;i<=ar;i++) pos[i][1]-=diaf1;}}
                    
                while (pos[cur][1]>=ektos) {
                    f=pre_cur;
                    while (pos[f][1]==yt) f++;
                    pre_cur=f;
                     for (i=0;i<=ar;i++) pos[i][1]-=bh;}
                     
                if (pos[cur][1]<yt) {
                f=cur;
                while (pos[cur][1]<yt) { for (i=0;i<=ar;i++) pos[i][1]+=bh; } 
                while (pos[f][0] != xl) f--;   
                pre_cur=f;}
                    
                x1=xl; y1=yt;
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                for (a=pre_cur; a<ar; a++) {
                what=str[a];
                    
                if (what==200) continue ;
                x1=pos[a][0]; y1=pos[a][1];
                if (y1>=ektos) break ;
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                }
                x=pos[cur][0] ; y=pos[cur][1];
                 refresh();
                pre_cur=0;pre_paste=0;
                goto barovios ;
                }
                
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                    setcolor (COLOR (bkr,bkg,bkb)) ;
                    for (a=ano_ar; a<ar; a++) {
                        if (!ghost[a]) continue ;
                        what=str[a];
                        if (what==200) continue ;
                        y1=pos[a][1];
                        if (y1>=ektos) break ; 
                        x1=pos[a][0];
                        mem_int=gouv[what].where ;
                        for(f=0; f<gouv[what].hei ; f++) {
                            for(i=0;i<gouv[what].wid;i++) {
                                co.lor = *mem_int++;
                                if (!co.lor) _putpixel(x1+i , y1+f);}}
                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                    refresh();
                    free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;
                            
                }
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
               
                if (cur==ar) {
                    what=str[ar-1];
                    x1=pos[ar-1][0] ; y1=pos[ar-1][1] ;
                    pos[ar][0]=pos[ar][1]=-1;
                    if (what!=200 && y1>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x1;i<=x1+gouv[what].wid;i++) { for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}
                    }
                    refresh();
                    x=x1; y=y1;
                    ar--; cur--; str[ar]=255;
                    
                    if (y<yt) {
                        for (f=0;f<=ar;f++) pos[f][1]+=bh;
                        f=0;
                        if (cur) {
                            while ( pos[cur-f][0] != xl ) f++;
                        }
                        
                        for (a=cur-f ; a<ar ; a++) {
                        what=str[a];
                        if (what==200) break ;
                        x1=pos[a][0]; y1=pos[a][1];
                        //if (y1>=ektos) break ;
                        mem_int=gouv[what].where ;
                        for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                        co.lor = *mem_int++;
                        if (!co.lor) continue;

                        // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                        setcolor(COLOR (red,green,blue));
                        _putpixel(x1+i , y1+f);}}
                        }
                        refresh();
                        x=pos[cur][0] ; y=pos[cur][1];
                        }
                    }
                    
                else {
                         
                        x1=pos[cur-1][0]; y1=pos[cur-1][1]; 
                        cur--;
                        for(f=cur;f<ar;f++) str[f]=str[f+1];
                        ar--;
                       
entos_back :
                         // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if ( (y1+bh) >=yt) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                
                secr=(cur) ? 1 : 0 ;                
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];   
                if ( (y1<yt) && (secr) ) {
                    f=0; while (pos[f][1]!=y1) f++;
                    secr=cur-f;
                    //while (pos[cur-secr][1] != xl) secr++;
                    diaf1=abs(pos[cur-secr][1] - yt);
                    pos [cur-secr][1]=yt;
                    x1=xl ; y1=yt;
                    for (f=0 ; f<cur-secr ; f++) pos[f][1]+=diaf1;
                }
                        
                for (a=cur-secr; a<ar; a++) {
                    
                    what=str[a];
                    
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ; x1=xl ; y1+=bh; continue ;}
                wrap=0 ;  
                if ((x1+gouv[what].wid) > xr-2) {
                    if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}}
                                            }
                                        }  
                x1=xl ; y1+=bh; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if ( (y1>=ektos) || (y1<yt) ) { x1+=gouv[what].wid; wrap--; continue ; }
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 x=pos[cur][0] ; y=pos[cur][1];
                 if (y<yt) { 
                     while (y<yt) {cur++; y = pos[cur][1] ; }
                     x=pos[cur][0] ; 
                }
                
                }
                goto barovios ;
  
                
                    case SDL_SCANCODE_CAPSLOCK :
                        caps_lock = abs (caps_lock-1) ; 
                        for (f=3;f<29;f++) {
                            mem_int=(mem_under+8+(f*225*4));
                            for(i=48 ; i<84;i++) {
                            co.lor= *(mem_int+i);
                            setcolor ( COLOR ( co.rgb[2] , co.rgb[1] , (co.rgb[0] +caps_lock*100)) );
                             
                            _putpixel (xep+i,yep+f);}} 
                            refresh(); 
                    continue ;
                
                    case SDL_SCANCODE_DELETE :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                    
                    // Ενεργοποίηση UNDO

                    undo_lasfile++;
                    sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
                    fpundo=fopen(file_1,"wb");
                    if ( fpundo!=NULL ) {
                    fide_undo = fileno (fpundo) ;
                    undo=1;
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        wherp = f;} else wherp = 0;
                    fwrite (&cur,2,1,fpundo);
                    fwrite (&ar,2,1,fpundo);
                    fwrite (str,1,ar,fpundo);
                    fwrite(vam,2,3,fpundo);
                    fwrite (&wherp,2,1,fpundo);
                    fwrite(&pre_cur,2,1,fpundo);
                    fwrite(&ins,2,1,fpundo);
                    fwrite(&gr_flag,2,1,fpundo);
                    fwrite(savefile,1,512,fpundo);
                    fwrite (pxl,4,1,fpundo);
                    fwrite (pyt,4,1,fpundo);
                    fwrite (pxr,4,1,fpundo);
                    fwrite (pyb,4,1,fpundo);
                    fwrite (&orio,4,1,fpundo);
                    if (ferror(fpundo)) { 
                        clearerr(fpundo); fclose(fpundo);
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    else {
                    fdatasync (fide_undo);
                    fsync (fide_undo);
                    fclose(fpundo);
                        if (undo_lasfile>undo_max) {
                            // Τσεκάρω για snapshot...
                        strcpy(file_2,user_path);
                        strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                        fpundo=fopen(file_2,"rb");
                        if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
                      
                        a=undo_lasfile-undo_max;
                        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                        rename (file_1,file_2);
                            undo_firfile++;}
                        }
                    }
                    else {
                        undo_lasfile--;
                        if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
                    }
                    
                    
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); };continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                vam[0]=0;
                for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
                diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
                cur = vam[1]; // ? vam[1]-1 : 0 ;
                if (inp_mem_ghost) {free(inp_mem_ghost); ghost=inp_mem_ghost=0;}
                goto esot_anadiat;}
                
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;
                }
                
                                           
                 if (cur==ar) continue ;
                 x1=pos[cur][0] ; y1 = pos[cur][1];
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for(f=cur;f<ar;f++) str[f]=str[f+1];
                 ar--;
                                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                what=str[a];
                
                if (what==200) { pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh; continue ;}
                wrap=0;                
                if ((x1+gouv[what].wid) > xr-2) {
                        if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}}
                                            }
                                        }  
                    x1=xl ; y1+=bh; }
                
                do {
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;
                what=str[a-wrap];
                if (y1>=ektos) {x1+=gouv[what].wid;wrap--; continue;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                 wrap--;   
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 for (f=ar+1;f<orio;f++) {pos[f][0]=-1 ; pos[f][1]=-1;}
                 goto barovios ; 
  
                
                    case SDL_SCANCODE_END :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];   x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0;pre_cur=0;
                }

                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f<=ar ; f++) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1];
                 continue ;
                
                
                    case SDL_SCANCODE_HOME :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));   
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a]; x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                 
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 if (!cur) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 for (f=cur; f>0 ; f--) {
                     if (pos[f][1]==y) continue ; else break ; }
                 cur = ++f ; if ( (cur==1) && (pos[0][1]==y) ) cur=0;
                 x=pos[cur][0] ; y=pos[cur][1];    
                   continue ;
                
                    case SDL_SCANCODE_HELP :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                   continue ;
                   
                    case SDL_SCANCODE_TAB :
                    tab=1;
                    goto DROMO ;
                
                    case SDL_SCANCODE_INSERT :
                if (keyb_gr) {ton=0 ; dial=0 ;}       
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                 y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ;
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                  col_cu = (col_cu==99) ? 100 : 99 ;
                  ins=abs(ins-1);
                  for (f=3;f<29;f++) {
                  mem_int=(mem_under+8+(f*225*4));
                          for(i=95 ; i<129;i++) {
                          co.lor= *(mem_int+i-1);
                          setcolor ( COLOR ( co.rgb[2]  , co.rgb[1] , co.rgb[0] +ins*70) );
                          _putpixel (xep+i,yep+f);}} 
                          refresh();
                   continue ;
                  
                    case SDL_SCANCODE_LEFT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
              
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 if (!cur) continue ;
                          //ΣΒΗΝΩ CURSOR
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                cur-- ; y=pos[cur][1];
                 if ( y < yt ) {
                     size=imagesize(xl,yt,xr-1,ektos-bh);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                     getimage(xl,yt,xr-1,ektos-bh,mem_power);
                     putimage (xl,yt+bh,mem_power,0); refresh(); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=yt ; f<yt+bh; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]+=bh;
                     a=cur; y1=y=yt;
                     while (pos[a][0] != xl) a--;
                     while (pos[a][1]==y) {
                     what=str[a];
                    if (what==200) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    }
                x=pos[cur][0]; 
                goto barovios ;
                
                    case SDL_SCANCODE_RIGHT :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) _putpixel(x1+i , y1+f);}}
                                  
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 if (cur==ar) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 cur++ ;
                 y=pos[cur][1];
                  if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     a=cur; y1=y=ektos-bh;
                     //while (pos[a][0] != xl) a--;
                     while (pos[a][1]==y && (a<ar) ) {
                     what=str[a];
                    if (what==200 ) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    refresh();
                    }
                x=pos[cur][0]; 
                   goto barovios ;
                
                    case SDL_SCANCODE_UP :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)   _putpixel(x1+i , y1+f);}}
               
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                } 
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                y1=y; x1=x;
                if (y==yt) {
                a=cur;
                while (pos[a][0] > xl) a--;
                if (!a) continue;
                size=imagesize(xl,yt,xr-1,ektos-bh);
                mem_power=malloc(size);
                if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                getimage(xl,yt,xr-1,ektos-bh,mem_power);
                putimage (xl,yt+bh,mem_power,0); free (mem_power);
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<xr;i++) {for (f=yt ; f<yt+bh; f++) _putpixel (i,f);}
                for(i=ar;i>=0;i--) pos[i][1]+=bh;
                a--;
                while (pos[a][0] != xl) a--;
                y1=yt;
                while (pos[a][1]==yt) {
                what=str[a];
                if (what==200) break ;
                x1=pos[a][0] ; 
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                x1+=gouv[what].wid;a++;}
                y1=yt+bh;
                x1=pos[cur][0];
                 }
            
            diaf1=2*xr;
                 for(f=cur;f>=0;f--) {if (pos[f][1]!=y1) break;}
                 while (pos[f][1]==y1-bh) {
                     diaf2=abs(pos[f][0]-x1);
                     if (diaf2<diaf1) {diaf1=diaf2;f--;continue;}
                     else break;
                 }
                 cur = ++f;
                 x=pos[cur][0] ; y=pos[cur][1] ;
                 goto barovios ;
                   
                
                    case SDL_SCANCODE_DOWN :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
                if (vam[0]) {                              // ξεβάφω
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                setcolor (COLOR (bkr,bkg,bkb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1= pos[a][1] ;
                if (y1>=ektos || y1<yt) continue ;
                what=str[a];
                x1= pos[a][0] ; 
                if (what==200) { for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)   _putpixel(x1+i , y1+f);}}
                
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                }
                refresh();
                vam[0]=0; pre_cur=0;
                }
                if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                    if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        f=cur;
                    if (f) {
                        while (pos[f][1]!=yt) f--;
                        while (pos[f][0]!=xl) f--;
                        ano_ar=f; } else ano_ar=cur;
                        
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                }
                 x1=x ; y1=y;
                 if (pos[ar][1]==y1) continue ;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    if (y==ektos-bh) {
                    size=imagesize(xl,yt+bh,xr-1,yb);
                    mem_power=malloc(size);
                    if (mem_power==NULL) {printf ("Memory not Enough \n") ; continue ;}
                    getimage(xl,yt+bh,xr-1,yb,mem_power);
                    putimage (xl,yt,mem_power,0); free (mem_power);
                    setcolor (COLOR(bkr,bkg,bkb));  
                    for (i=xl;i<xr;i++) {for (f=y ; f<=yb; f++) _putpixel (i,f);}
                    for(i=ar;i>=0;i--) pos[i][1]-=bh;
                    a=cur;
                    while (pos[a][1]<y) a++;
                    while (pos[a][1]==y && (a<ar) ) {
                    what=str[a];
                    if (what==200 ) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    x1=x;y1-=bh;y=y1;
                    }
                 
                 diaf1=2*xr;
                 for(f=cur;f<=ar;f++) {if (pos[f][1]!=y1)  break;}
                
                 while ( (pos[f][1]==y1+bh) && (f<=ar) ) {
                     diaf2=abs(pos[f][0]-x1);
                     if (diaf2<diaf1) {diaf1=diaf2;f++;continue;}
                     else break;
                 }
                 cur = --f;
                 x=pos[cur][0] ; y=pos[cur][1] ;
                 goto barovios ;
                                  
                    case SDL_SCANCODE_PAGEDOWN :
PAGEDOWN :
                 if (keyb_gr) {ton=0 ; dial=0 ;}
               
                 if (cur==ar) continue;
                 if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                 if (pos[ar][1]<ektos ) {cur=ar; x=pos[ar][0]; y=pos[ar][1]; continue ;}
                 
                 
                 f=cur;
                 while (pos[f][1]<ektos) f++;
                 cur=f;
                 for (i=0;i<=ar;i++) pos[i][1]-=(maxline*bh);
                 x1=x=xl; y1=y=yt;
                 // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();
                                  
                if (vam[0]) {                              // βάφω 
                
                        // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setrgbcolor (selpal);  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
                goto barovios ;
                
                    case SDL_SCANCODE_PAGEUP :
PAGEUP :
                if (keyb_gr) {ton=0 ; dial=0 ;}
                if (!cur) continue;
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                if (pos[0][1]==yt) {cur=0; x=xl ; y=yt; continue;}
               
                f=cur;
                while (pos[f][1]>=yt) f--;
                while ( (pos[f][1] >=(yt-maxline*bh)) && (f>=0) ) f--;
                f++; cur=f ;
                diaf1=yt-pos[f][1]; diaf1 /= bh;
                for (i=0;i<=ar;i++) pos[i][1] += (diaf1*bh);
                x1=x=xl ; y1=y=yt;
                // ANADIATAJH 
                setcolor (COLOR(bkr,bkg,bkb));  
                for (i=xl;i<=xr;i++) {for (f=yt ; f<=yb; f++) _putpixel (i,f);}
                
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ;
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) {
                        if (!ghost) continue;
                        if (ghost[a]) {setrgbcolor (selred) ;  _putpixel(x1+i , y1+f); continue ; }
                        else continue ;
                    }

                    // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                    setcolor(COLOR (red,green,blue));
                    _putpixel(x1+i , y1+f);}}
                    if(!ghost) continue ;
                    if (ghost[a]) {
                        while (f<bh) {
                        setrgbcolor(selred);
                        for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}
                    }
                }
                 refresh();

                if (vam[0]) {                              // βάφω 
                       // ΒΑΦΩ ΑΠΟ vam(1) έως vam(2)
                setcolor (COLOR (epr,epg,epb));  
                for (a=vam[1]; a<=vam[2]; a++) {
                y1=pos[a][1] ;
                if (y1<yt) continue ;
                if (y1>=ektos) break ;
                what=str[a];
                x1=pos[a][0] ; 
                if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}    
                }
                refresh();}
barovios :
  if ( (!bar) ) {
                    proyt=abs(pos[0][1]-yt) ;
                    metektos = pos[ar][1]- yt - ( (maxline-1)*bh );
                    
                    if ( (!proyt) && (metektos<=0) ) continue ;
                    bar=1;
                    setcolor (COLOR (0,255,0) );  
                    rectangle (xr+3,yt-1,xr+13,yb);
                    setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
                    olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
                    y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
                    y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;
                     if (y1==y2) y2++;
                    bary1=y1 ; bary2=y2;
                    setcolor (COLOR (255,165,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                    refresh();
                    continue ;
                            }
        else
                            {
               proyt1=abs(pos[0][1]-yt) ;
               metektos1 = pos[ar][1]- yt - ( (maxline-1)*bh );
               if ( (!proyt1) && (metektos1<=0) ) {
               putimage (xr+3,yt-1,mem_bar,0);
               bar=0;
                refresh();
               continue ;}
               if (proyt1==proyt && metektos1==metektos) continue;
               proyt=proyt1 ; metektos=metektos1;
               olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
               setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
               y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
               y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;     
                if (y1==y2) y2++;
               bary1=y1 ; bary2=y2;
               setcolor (COLOR (255,165,0) );  
               for (f=xr+4 ; f<xr+13 ; f++) {
                    for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                refresh();
                            }
                 continue;                

                    case SDL_SCANCODE_V :  //PASTE
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME V 
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                        {                        
      
 // ΑΝΤΙΓΡΑΦΩ ΟΣΑ ΕΠΙΤΡΕΠΕΤΑΙ ΑΠΟ ΤΟ SYSTEM CLIPBOARD αναλόγως του insert //
        if (!SDL_HasClipboardText()) continue;
        if ( (orio==ar) && (!vam[0]) ) continue ;
        clipbo=SDL_GetClipboardText();
        if (clipbo==NULL) continue;
        
           
        // Ενεργοποίηση UNDO
        if (ar) {
        undo_lasfile++;
        sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",undo_lasfile,".dat");
        fpundo=fopen(file_1,"wb");
        if ( fpundo!=NULL ) {
        fide_undo = fileno (fpundo) ;
        undo=1;
        f=cur;
        if (f) {while (pos[f][1]>yt) f--;
            while (pos[f][0]!=xl) f--;
            wherp = f;} else wherp = 0;
        fwrite (&cur,2,1,fpundo);
        fwrite (&ar,2,1,fpundo);
        fwrite (str,1,ar,fpundo);
        fwrite(vam,2,3,fpundo);
        fwrite (&wherp,2,1,fpundo);
        fwrite(&pre_cur,2,1,fpundo);
        fwrite(&ins,2,1,fpundo);
        fwrite(&gr_flag,2,1,fpundo);
        fwrite(savefile,1,512,fpundo);
        fwrite (pxl,4,1,fpundo);
        fwrite (pyt,4,1,fpundo);
        fwrite (pxr,4,1,fpundo);
        fwrite (pyb,4,1,fpundo);
        fwrite (&orio,4,1,fpundo);
        if (ferror(fpundo)) { 
            clearerr(fpundo); fclose(fpundo);
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
        }
        else {
            fdatasync (fide_undo);
        fsync (fide_undo);
        fclose(fpundo);
            if (undo_lasfile>undo_max) {
                    // Τσεκάρω για snapshot...
                strcpy(file_2,user_path);
                strcat(file_2,".EORT_SETTINGS/TMP/snapshot.dat");
                fpundo=fopen(file_2,"rb");
                if (fpundo!=NULL) {fclose (fpundo); remove (file_2);}
               
                a=undo_lasfile-undo_max;
                sprintf(file_1,"%s%s%d%s",user_path,".EORT_SETTINGS/TMP/undo",a,".dat");
                rename (file_1,file_2);
                undo_firfile++;}
            }
        }
        else {
            undo_lasfile--;
            if (undo_lasfile<undo_firfile) { undo=0; undo_firfile=1; undo_lasfile=0 ;}
        }
        }
        
        if (vam[0]) {                              // ξεβάφω - αναδιατάσσω το str
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        setcolor (COLOR (bkr,bkg,bkb));  
        for (a=vam[1]; a<=vam[2]; a++) {
       y1= pos[a][1] ;
        if (y1>=ektos || y1<yt) continue ;
         what=str[a];
        x1= pos[a][0] ; 
        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); } continue ;}
        mem_int=gouv[what].where ;
        for(f=0; f<gouv[what].hei ; f++) {
        for(i=0;i<gouv[what].wid;i++) {
        co.lor = *mem_int++;
        if (!co.lor) _putpixel(x1+i , y1+f);}}
        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
        }
        vam[0]=0;
        // Εσωτερική Αναδιάταξη !
        cur = vam[1] ;
        for (a=vam[1],f=vam[2]+1 ; f<=ar ; f++,a++) str[a]=str[f] ;
        diaf1=(vam[2]-vam[1]+1);  if (vam[2]==ar) diaf1--; ar -= diaf1;
        if (inp_mem_ghost) {free(inp_mem_ghost); ghost=inp_mem_ghost=0;}
        }
        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                f=cur;
            if (f) {
                while (pos[f][1]!=yt) f--;
                while (pos[f][0]!=xl) f--;
                ano_ar=f; } else ano_ar=cur;
                
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
        }
        if(!ins) elxor=orio-ar; else elxor=orio-cur;
        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
        if (!ins) {
            
            for(f=ar,i=0; (f>=cur) ; f--,i++) str[orio-i]=str[f];
            diaf1=orio-i+1;}
            // Προσδιορισμός του Pre_Paste
            
        if (!pre_cur) {
        f=cur;
        if (f) {
                    while (pos[f][1]>yt) f--;
                    while (pos[f][0]!=xl) f--;
                    pre_paste=f;
                } else pre_paste=0;} 
                   else pre_paste=0;

        f=0 ; a=0 ;
        ch=clipbo[f];
        while ( (ch!='\0') && (elxor) ) {
            if (ch<0) {
                
                f++ ; ch1= ( (256*ch) + clipbo[f] ) ;
                for (i=0 ; i<69 ; i++) {
                    if (ch1==unico[i][0]) {
                        str[cur+a]=unico[i][1];  elxor--; a++; break;}}
                        if (i==69) {str[cur+a]=0 ; a++ ; elxor--; f--; }
                f++; ch=clipbo[f];continue;
             }
            else {
                if (ch=='\n') {str[cur+a]=200; a++;elxor--; f++; ch=clipbo[f]; continue;}
                for(i=0;i<95;i++) {
                    if (ch==gouv[i].who) {
                        str[cur+a]=i ; a++ ; elxor-- ;break;}}
                        if (i==95) {str[cur+a]=0 ; a++ ; elxor--;}
                f++;ch=clipbo[f];
                  }
        }
         if (!ins) {ar+=a;} else {
             if (cur+a > ar) ar=(cur+a); }
         if((orio>ar) && (!ins) ) {for (f=cur+a; diaf1<=orio ; f++,diaf1++) str[f] = str[diaf1];}
         SDL_free(clipbo);
        goto esot_anadiat;}                        
                 
                   }
        break;
                  
                        case SDL_SCANCODE_C :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME C (* Copy) //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                                if (!vam[0]) continue;
                                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                                size=0;
                                for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) size++;
                                    else if ( (what>94) && (what<164) ) size+=2;
                                    else size++; }
                                    size++;
                                    clipbo=malloc(size);
                                    if (clipbo==NULL) {printf ("Out of Memory \n"); break ; }
                                    a=0;
                                    for (f=vam[1] ; f<=vam[2] ; f++) {
                                    what=str[f];
                                    if (what<95) {
                                        clipbo[a]=gouv[what].who; a++;}
                                    else if ( (what>94) && (what<164) ) {
                                        cha=((unico[what-95][0]/256)-255);
                                        chb = (unico[what-95][0] % 256);
                                        clipbo[a]=cha; clipbo[a+1]=chb; a+=2;}
                                    else if (what==200) {clipbo[a]='\n' ; a++;}}
                                    clipbo[a]='\0';
                                    size=SDL_SetClipboardText(clipbo);
                                    if (!size) {
                                       
                                        setcolor (COLOR (epr1,epg1,epb1));  
                                        for (a=vam[1]; a<=vam[2]; a++) {
                                        y1=pos[a][1] ;
                                        if (y1<yt || y1>=ektos) continue;
                                        what=str[a];
                                        x1=pos[a][0] ; 
                                        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); }refresh(); continue ;}
                                        mem_int=gouv[what].where ;
                                        for(f=0; f<gouv[what].hei ; f++) {
                                        for(i=0;i<gouv[what].wid;i++) {
                                        co.lor = *mem_int++;
                                        if (!co.lor)  _putpixel(x1+i , y1+f); }}     
                                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}}
                                        refresh();
                                    } 
                                    free(clipbo);
                                    continue;  }
                    break ;
                    
                    case SDL_SCANCODE_RCTRL :
                    case SDL_SCANCODE_LCTRL :
                        continue;
                    
                    case SDL_SCANCODE_RETURN :
                    case 88 :
                    switch (ch_mod) { // ELEGXOS GIA CTRL PATHMENO MAZI ME ENTER //
                    case 64 :
                    case 128 :
                    case 4160 :
                    case 4224 :
                    case 8256 :
                    case 8320 :
                    case 12352 :
                    case 12416 : 
                    {
                        if (mem_small) hide_help_inp(hlpxt , hlpyt);
                    f=cur;
                    if (f) {while (pos[f][1]>yt) f--;
                        while (pos[f][0]!=xl) f--;
                        diaf1 = f;} else diaf1 = 0;
                    fidicls (xl,yt,xr,yb,0,0,0);
                    putimage(xl-1,yt-21,mem1,0); putimage(xep,yep,mem_undscr,0);free(mem_undscr);free(mem1) ; free(mem_cu); free(mem_flusa); free(mem_enter);free(mem_tent);  free(mem_under); 
                    if (bar) { putimage (xr+3,yt-1,mem_bar,0); refresh(); }
                    if (mem_bar) free(mem_bar); 
                    if (keyb_gr) free(mem_flgr); 
                    free(mem_rmenu); free(mem_arrs); free(mem_info);free(mem_find); free(mem_fonter);  free(mem_link);
                    str[ar]=255;
                    if (inp_mem_ghost) { free(inp_mem_ghost); inp_mem_ghost=0; }
                    langex = (us_flag) ? 1 : 2 ;
                    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);    SDL_SetCursor(cursor);refresh();  ar=0; undo=0; undo_firfile=1; undo_lasfile=0 ; cur=0;vam[0]=0;vam[1]=0;vam[2]=0;wherp=0;pre_cur=0;ins=0; return diaf1;
                    }
                    default :
                    {

                        if (keyb_gr) {ton=0 ; dial=0 ;}
                        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                        if (vam[0]) {                              // ξεβάφω
                        setcolor (COLOR (bkr,bkg,bkb));  
                        for (a=vam[1]; a<=vam[2]; a++) {
                         y1= pos[a][1] ;
                        if (y1>=ektos || y1<yt) continue ;
                        what=str[a];
                        x1= pos[a][0] ;
                        if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) { _putpixel (i,f); }continue ;}
                        mem_int=gouv[what].where ;
                        for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                        co.lor = *mem_int++;
                        if (!co.lor) _putpixel(x1+i , y1+f);}}
                        while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
                        }
                        refresh();
                        vam[0]=0; pre_cur=0;
                        }
                        if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                        if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                            f=cur;
                        if (f) {
                            while (pos[f][1]!=yt) f--;
                            while (pos[f][0]!=xl) f--;
                            ano_ar=f; } else ano_ar=cur;
                            
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0; 
                        }
                        
                        if (cur==ar) {
                            if (orio==ar) continue ;
                            pos[cur][0]=x; pos[cur][1]=y;
                            str[cur]=200;
                            ar++ ; cur ++;
                            str[ar]=255;
                            x=xl; y+=bh ;
                            pos[ar][0]=x ; pos[ar][1]=y;
                             if (y == ektos) {
                                size=imagesize(xl,yt+bh,xr-1,yb);
                                mem_power=malloc(size);
                                if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                                getimage(xl,yt+bh,xr-1,yb,mem_power);
                                putimage (xl,yt,mem_power,0); free (mem_power);
                                setcolor (COLOR(bkr,bkg,bkb));  
                                for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                                for(i=ar;i>=0;i--) pos[i][1]-=bh;
                                refresh();
                                y-=bh;  }
                            
                            goto barovios;
                        }
                        
                        if(!ins) {
                            if (orio==ar) continue ;
                            ar++; for(f=ar;f>cur;f--) str[f]=str[f-1];}
                        str[cur]=200;
                        x1=x ; y1=y;
                
                 anadiat :
                          // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if((y1>=yt) && (y1<ektos)) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos) {for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur; a<ar; a++) {
                    what=str[a];
                    
                if (what==200) {pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh; continue ;}
                wrap=0;
                if ((x1+gouv[what].wid) > xr-2) { 
                        if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}refresh();}
                                            }
                                        }  
                x1=xl ; y1+=bh; }
                
                do{
                pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ; 
                what=str[a-wrap];
                if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                mem_int=gouv[what].where ;
                for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x1+i , y1+f);}}
                 x1+=gouv[what].wid;
                wrap--;    
                    } while (wrap>=0);
                }
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) { cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else { x=x1 ; y=y1;}
                 if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     a=cur; y-=bh;
                     x1=xl ; y1=y;
                     while (pos[a][1]==y) {
                     what=str[a];
                     if (what>=200) break ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}refresh();}
                        
                 } goto barovios; }
                                 
                }
                        
                
            //ΕΛΕΓΧΟΣ ΠΡΙΝ ΤΗΝ ΕΚΤΥΠΩΣΗ ΕΝΟΣ ΧΑΡΑΚΤΗΡΑ //
            if (vam[0]) {                              // ξεβάφω
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            setcolor (COLOR (bkr,bkg,bkb));   
            for (a=vam[1]; a<=vam[2]; a++) {
             y1= pos[a][1] ;
            if (y1>=ektos || y1<yt) continue ;
            what=str[a];
            x1= pos[a][0] ;
            if (what==200) {for (f=y1;f<y1+bh;f++) for(i=x1;i<xr-1;i++) {_putpixel (i,f); } continue ;}
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
            for(i=0;i<gouv[what].wid;i++) {
            co.lor = *mem_int++;
            if (!co.lor) _putpixel(x1+i , y1+f);}}
            while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}            
            }
            refresh();
            vam[0]=0;pre_cur=0;
            }
            
            if (ghost) { // Ξεβάφω ότι έχει βρεθεί με την εύρεση
                    
                if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
                    f=cur;
                if (f) {
                    while (pos[f][1]!=yt) f--;
                    while (pos[f][0]!=xl) f--;
                    ano_ar=f; } else ano_ar=cur;
                    
                setcolor (COLOR (bkr,bkg,bkb)) ;
                for (a=ano_ar; a<ar; a++) {
                    if (!ghost[a]) continue ;
                    what=str[a];
                    if (what==200) continue ;
                    y1=pos[a][1];
                    if (y1>=ektos) break ; 
                    x1=pos[a][0];
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                        for(i=0;i<gouv[what].wid;i++) {
                            co.lor = *mem_int++;
                            if (!co.lor) _putpixel(x1+i , y1+f);}}
                    while (f<bh) {for(i=0;i<gouv[what].wid;i++) { _putpixel(x1+i , y1+f);} f++ ;}} 
                 refresh();
                 free(inp_mem_ghost) ; ghost=inp_mem_ghost=0;
            }
                
                
            if (ch_scan<57) {
                switch (ch_mod) { // ELEGXOS GIA SHIFT PATHMENO MAZI ME CHAR
                    case 1 :
                    case 2 :
                    case 4097 :
                    case 4098 :
                    case 8193 :
                    case 8194 :
                    case 12289 :
                    case 12290 : 
                        shift=1 ; break ;
                    default : shift = 0; }
                  
                  // To caps_lock αντιστρέφει το shift για τα Α έως Ζ //
                    if (ch_scan>3 && ch_scan<30) {
                        if (caps_lock) shift = abs (shift-1) ;}
            what = (gr_flag) ? grek.sort[ch_scan][shift] : engl.sort[ch_scan][shift] ;
            if (!gr_flag) goto typechar ;
            if (dial) {
                switch (gouv[what].who) {
                    case 'i' :
                    case 'y' :
                    case 'I' :
                    case 'Y' :
                        met+=2 ; dial=0 ; break ;
                    default : dial=0 ; met=0 ;}}
                    
            if (ton) {
                switch (gouv[what].who) { 
                    case 'I' :
                    case 'Y' :    
                    met=1 ; ton=0 ; break ;
                case 'a' :
                case 'e' :               
                case 'h' :                  
                case 'i' :                    
                case 'o' :                    
                case 'y' :                   
                case 'v' :                   
                case 'A' :
                case 'E' :
                case 'H' :
               case 'O':
               case 'V' :
                   met+=1 ; ton =0 ; break ;
                default : met=0 ; ton=0;}}
                
            what += met ; met=0 ;
            
            typechar:
            if(diak) {putimage(x,y,mem_cu,0); refresh() ; diak=0;}
            
            if (cur==ar) {
            if ( orio==ar ) continue ;
            str[ar]=what ; ar++; cur++; str[ar]=255 ;
            wrap=0;
            if ( (x+gouv[what].wid) > xr-2) {  
               if ( (what) ) {  
               i=cur-1;
               while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
               i++;wrap--;
               if (elax<wrap+1) wrap=0;
               if ( (wrap) ) {
               x1=pos[i][0];y1=pos[i][1];
               if ((y1>=yt) && (y1<ektos)) {
               setcolor (COLOR(bkr,bkg,bkb));  
               for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                    }
                }
            x = xl ; y+=bh ;
            }
            if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     y-=bh;
                     refresh();
                }
                 
            
            do {
            pos[(cur-1-wrap)][0]=x ; pos[(cur-1-wrap)][1]=y ;
            what=str[cur-1-wrap];
            mem_int=gouv[what].where ;
            for(f=0; f<gouv[what].hei ; f++) {
                for(i=0;i<gouv[what].wid;i++) {
                co.lor = *mem_int++;
                if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );
                setcolor(COLOR (red,green,blue));
                 
                _putpixel(x+i , y+f);}}
            refresh();
            x=x+gouv[what].wid;
            wrap--;
            }while (wrap>=0);
            pos[cur][0]=x; pos[cur][1]=y;
            refresh();
                     }
            
            else {                               // cur != ar
             
               if (!ins) {
                    if ( orio==ar ) continue ;
                    ar++;
                    for(f=ar; f>cur; f--) str[f]=str[f-1];
                   str[cur]=what ;
                   if ( (what) && (ar<orio) && (cur) ) {
                           if (str[cur+1] && (!str[cur-1])) {
                               ar++;
                               for(f=ar; f>cur+1; f--) str[f]=str[f-1];
                               str[cur+1]=0;
                           }
                       }
            }
                    
                str[cur]=what;
                f=0;i=0;
                while (pos[cur-f][0]!=xl) f++;
                if ((cur-f)) {
                i = f+1;
                while ( pos[cur-i][0] !=xl ) {
                    if (str[cur-i]!=200) i++;
                    else {i=0;break;} }}
                secr = (i) ? i : f ;
                x1=pos[cur-secr][0] ; y1=pos[cur-secr][1];
                
                // DIAGRAFH PALIVN XARAKTHRVN //
                setcolor (COLOR(bkr,bkg,bkb));  
                if ((y1>=yt) && (y1<ektos) ) {for (i=x1;i<=xr;i++) {for (f=y1 ; f<y1+bh; f++) _putpixel (i,f);}}
                if(y1+bh!=ektos){for (i=xl;i<=xr;i++) {for (f=y1+bh ; f<=yb; f++) _putpixel (i,f);}}
                 
                for (a=cur-secr; a<ar; a++) {
                    what=str[a];
                        
                    if (what==200) {pos[a][0]=x1 ; pos[a][1]=y1 ;x1=xl ; y1+=bh;  continue ;}
                    wrap=0;            
                    if ((x1+gouv[what].wid) > xr-2) { 
                        if ( (what) ) {  
                        i=a;
                        while ( (str[i]) && (str[i]!=200) ) {if (!i) {wrap=1; break;} else wrap++; i--;}
                        i++;wrap--;
                        if (elax<wrap+1) wrap=0;
                        if ( (wrap) ) {
                        x2=pos[i][0];y2=pos[i][1];
                        if (y2<ektos && y2>=yt) {
                        setcolor (COLOR(bkr,bkg,bkb));  
                        for (i=x2;i<=xr;i++) {for (f=y2 ; f<y2+bh; f++) _putpixel (i,f);}}
                                            }
                                        }  
                    x1=xl ; y1+=bh; }
                        
                    do { 
                    pos[a-wrap][0]=x1 ; pos[a-wrap][1]=y1 ;     
                    what=str[a-wrap];
                    if (y1>=ektos || y1<yt) {x1+=gouv[what].wid; wrap--; continue ;}
                    
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;
                    wrap--;
                    }while (wrap>=0);
                }
                
                 refresh();
                 str[a]=255 ;
                 pos[a][0]=x1 ; pos[a][1]=y1;
                 if (cur<ar) {cur++; x=pos[cur][0] ; y=pos[cur][1];}
                 else {x=x1; y=y1;}
                 
                 if ( y == ektos ) {
                     size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt+bh,xr-1,yb,mem_power);
                     putimage (xl,yt,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=y-bh ; f<=yb; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]-=bh;
                     a=cur; y-=bh;
                     x1=x ; y1=y;
                     while (pos[a][1]==y) {
                     what=str[a];
                     if (what>=200) break ;
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    x1+=gouv[what].wid;a++;}
                    refresh();
                }
                
                if (y<yt)   {
                    size=imagesize(xl,yt+bh,xr-1,yb);
                     mem_power=malloc(size);
                     if (mem_power==NULL) {printf ("Memory not Enough \n") ; ar-- ; cur-- ; str[ar]=255 ; continue ;}
                     getimage(xl,yt,xr-1,ektos-bh,mem_power);
                     putimage (xl,yt+bh,mem_power,0); free (mem_power);
                     setcolor (COLOR(bkr,bkg,bkb));  
                     for (i=xl;i<xr;i++) {for (f=yt ; f<yt+bh; f++) _putpixel (i,f);}
                     for(i=ar;i>=0;i--) pos[i][1]+=bh;
                     a=cur; y1=yt;
                     while (pos[a][0]!=xl) a--;
                     while (pos[a][1]==y1) {
                     what=str[a];
                     if (what==200) break ;
                    x1=pos[a][0] ; 
                    mem_int=gouv[what].where ;
                    for(f=0; f<gouv[what].hei ; f++) {
                    for(i=0;i<gouv[what].wid;i++) {
                    co.lor = *mem_int++;
                    if (!co.lor) continue;

                // Gia MENA 
alfa =  ((float)co.rgb[0] / 255) ;
neg = ((float)1 - alfa);
red = (int) ( (alfa * (float)chxr[0]) + (neg * (float) bkxr[0]) );
green = (int) ( (alfa * (float)chxr[1]) + (neg * (float) bkxr[1]) );
blue = (int) ( (alfa * (float)chxr[2]) + (neg * (float) bkxr[2]) );    
                setcolor(COLOR (red,green,blue));
                     
                    _putpixel(x1+i , y1+f);}}
                    a++;
                    }
                    refresh();
                    y=yt;
                                }
                    
                }
  if ( (!bar) ) {
                    proyt=abs(pos[0][1]-yt) ;
                    metektos = pos[ar][1]- yt - ( (maxline-1)*bh );
                    
                    if ( (!proyt) && (metektos<=0) ) continue ;
                    bar=1;
                    setcolor (COLOR (0,255,0) );  
                    rectangle (xr+3,yt-1,xr+13,yb);
                    setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
                    olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
                    y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
                    y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;
                     if (y1==y2) y2++;
                    setcolor (COLOR (255,165,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                    refresh();
                    continue ;
                            }
        else
                            {
               proyt1=abs(pos[0][1]-yt) ;
               metektos1 = pos[ar][1]- yt - ( (maxline-1)*bh );
               if ( (!proyt1) && (metektos1<=0) ) {
               putimage (xr+3,yt-1,mem_bar,0);
               bar=0;
                refresh();
               continue ;}
               if (proyt1==proyt && metektos1==metektos) continue;
               proyt=proyt1 ; metektos=metektos1;
               olohei = (metektos<=0) ? proyt+maxline*bh : proyt+maxline*bh+metektos ;
               setcolor (COLOR (0,0,0) );  
                    for (f=xr+4 ; f<xr+13 ; f++) {
                        for (i=yt ; i < yb; i++) _putpixel (f,i); }
               y1 = ( ( (yb-yt-1)*proyt) / olohei ); y1+= yt;
               y2=( ( (yb-yt-1)*maxline*bh) / olohei ); y2+=y1;     
                if (y1==y2) y2++;
               setcolor (COLOR (255,165,0) );  
               for (f=xr+4 ; f<xr+13 ; f++) {
                    for (i=y1 ; i < y2; i++) _putpixel (f,i); }
                refresh();
                            }
                continue ;
              }
              continue;
       
    case SDL_QUIT:
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
        goto DROMO;
    continue ;

    case SDL_WINDOWEVENT :
        if (mem_small) hide_help_inp(hlpxt , hlpyt);
    refresh(); continue;

    default:
    continue;
    
        }
    } 
}

// END DIARY INPUT



