#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BMPFLDS(F)(1==F||2==F?F:(((F-1)>>2<<2)+(1<<2)))
#define BMPPDR(F)((((F-1)>>3<<3)+(1<<3))/F)
#define CRDTOI(C,A)(C.y*A.x+C.x)
#define PTRTBMPMTDT(A)((bmpmtdt*)((char*)A-sizeof(bmpmtdt)))
#define PLD "7848281828783808486818480828486868480828586828380838480848083848683828083858480828486"
typedef unsigned char trtr;typedef char*brr;typedef char const*brrc;typedef struct _crd{unsigned char x,y;}crd;typedef struct _fld{bool*_;}fld;typedef struct _bmpmtdt{trtr _;crd __;}bmpmtdt;typedef brr bmp;typedef brrc bmpc;typedef struct _chr{unsigned char ps;bmp vl;}chr;
static void pchr(char const c){write(1,&c,1);}
static void pstr(char const*s){while(*s?pchr(*s++),1:0);}
static void pnbrrq(int const n){n<0?pchr(45),pnbrrq(-n),0:n?pnbrrq(n/10),pchr(n%10+48),0:0;}
static void pnbr(int const n){!n?pchr(48):pnbrrq(n);}static void prrr(char const*const e){pstr(e);pchr(10);exit(1);}
static void*nw(size_t const s){void*p=malloc(s);if(!p)prrr("error::nw::malloc::NULL");return p;}
static void dlt(void*const s){free(s);}
static int gnbr(char const*s){unsigned char n=0;int r=0;while(*s?43==*s?++s:45==*s?++n,++s:0:0);while(*s?47<*s&&58>*s?r*=10,r+=*s++-48,1:0:0);return n%2?-r:r;}
static char**wtb(char const*s){if(!s)return(void*)0;unsigned int c=1,i=0,j=0,k=0,l;char const*t=s;for(;*t?(56==*t?i?--i:0:!i?++c,++i:0),1:0;++t);char**r=nw(sizeof(char*)*c);r[--c]=(void*)0;for(c=0,i=0,t=s;k?k%2?((l=j),--k,++t,(r[c-1][--j]=0),1):j?(r[c-1][--j]=*t,1):((*r[c-1]=1[t]),(t+=l),4==k?0:((k=0),1)):*t?(56==*t?i?--i,r[c++]=nw(++j),k=3:0:!i?++i,++j:++j),1:i?r[c++]=nw(++j),k=5:0;k?--t:++t);return r;}
static void dtb(char**t){char**s=t;while(*s)dlt(*(s++));dlt(t);}
static bool brrgt(brrc const a,trtr const i){return*a&(1<<i);}
static void brrst(brr const a,trtr const i,bool const v){v?(*a|=(1<<i)):(*a&=~(1<<i));}
static void pbt(bool const b){pchr(b+48);}
static bool bmpgtv(bmpc const a,crd const c,trtr const f){bmpmtdt*m=PTRTBMPMTDT(a);unsigned int const i=CRDTOI(c,m->__);trtr p=BMPPDR(m->_);return brrgt(a+i/p,i%p*m->_+f);}
static fld bmpgtfld(bmpc a,crd const c){bmpmtdt*m=PTRTBMPMTDT(a);unsigned int const i=CRDTOI(c,m->__);trtr p=BMPPDR(m->_);fld v={nw(m->_)};a+=i/p;for(trtr j=0;m->_>j;++j)j[v._]=brrgt(a,i%p*m->_+j);return v;}
static void bmpstv(bmp const a,crd const c,trtr const f,bool const v){bmpmtdt*m=PTRTBMPMTDT(a);unsigned int const i=CRDTOI(c,m->__);trtr p=BMPPDR(m->_);brrst(a+i/p,i%p*m->_+f,v);}
static void bmpstfld(bmp a,crd const c,fld const v){bmpmtdt*m=PTRTBMPMTDT(a);unsigned int const i=CRDTOI(c,m->__);a+=i;for(trtr j=0;m->_>j;++j)brrst(a,i%BMPPDR(m->_)*m->_+j,j[v._]);}
static void pbmpf(bmpc const a,trtr const b,trtr const e){bmpmtdt*m=PTRTBMPMTDT(a);for(crd c={0,0};c.x<m->__.x;++c.x,pchr(10))for(c.y=0;c.y<m->__.y;m->__.y-1>c.y?(pchr(32),++c.y):(c.y|=m->__.y))for(trtr i=b;i<e;pbt(bmpgtv(a,c,i++)));}
static void pbmp(bmpc const a){bmpmtdt*m=PTRTBMPMTDT(a);pbmpf(a,0,m->_);}
static bmp nbmp(crd const c,trtr const f){trtr d=BMPFLDS(f);unsigned int i=c.x*c.y*d,j=i/8+(i%8?1:0);bmpmtdt*m=nw(sizeof(bmpmtdt)+j);bmp b=(bmp)m+sizeof(bmpmtdt);m->__=c;m->_=d;memset(b,0,j);return b;}
static void dbmp(bmp const a){dlt(PTRTBMPMTDT(a));}
static crd bmpgtcrd(bmpc const a){return PTRTBMPMTDT(a)->__;}
static void swp(chr*a,size_t f,size_t s){f[a].ps^s[a].ps?f[a].ps^=s[a].ps^=f[a].ps^=s[a].ps:0;bmp m=f[a].vl;f[a].vl=s[a].vl;s[a].vl=m;}
static void srtqck(chr*a,size_t f,size_t s){if(s<=f)return;size_t i=f+1,j=s,k=i;for(size_t const p=f[a].ps;j>=i;p<i[a].ps?swp(a,i,j--),0:p>i[a].ps?++i:(swp(a,i++,k++),0));for(size_t l=j,m=k;m-f;swp(a,--m,l--));srtqck(a,f,k-f<j?j++-k+f:(++j,0));srtqck(a,j,s);}
static void prntld(chr*ld,size_t ln){char bfr;fld f;for(size_t i=0;ln>i;++i){bfr=0;crd cr=bmpgtcrd(i[ld].vl);for(crd j={0,0};cr.x>j.x;++j.x)for(j.y=0;cr.y>j.y;++j.y){f=bmpgtfld(i[ld].vl,j);if(*f._)bfr|=(*f._<<(6-j.y));dlt(f._);}(void)pbmp;dbmp(i[ld].vl);4==i?pnbr(bfr-48):pchr(bfr);}pchr(10);}
static void prspld(char**pld){size_t ln=gnbr(*(pld)++);chr ld[++ln];crd cr={0,7};for(size_t i=0;ln>i;++i){i[ld].ps=gnbr(*(pld)++);cr.x=gnbr(*(pld)++);i[ld].vl=nbmp(cr,1);for(crd j={0,0};cr.x>j.x;++j.x){j.y=gnbr(*(pld)++);(void)bmpstfld;bmpstv(i[ld].vl,j,0,1);}}srtqck(ld,0,ln-1);prntld(ld,ln);}
static void ntpld(){char**pld=wtb(PLD);prspld(pld);dtb(pld);}
static void my_putchar(char aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa){write(1,&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa, 1);}
int reduce_find_bsq(int len, int m){if (len >= m)len = m;}
int file_size(char const *filepath){struct stat info;if (stat(filepath, &info) == -1)return (84);return (info.st_size);}
int errors(int file, char *res){int i = 0;if (file == -1)return (84);while (res[i] != '\n') {if (res[i] <= '9' && res[i] >= '0')++i;else return (84);}return (0);}
int my_getnbr(char const *str){int i = 0;long long nb = 0;int nb_sign = 1;int power_ten = 0;while (str[i] != '\0') {if (str[i] >= '0' && str[i] <= '9') {while (str[i] >= '0' && str[i] <= '9') {nb = (nb * 10) + str[i] - 48;++i;++power_ten;}nb = nb * nb_sign;return (nb);}++i;}return (0);}
int fs_get_number_from_first_line(char const *filepath){int file = open(filepath, O_RDONLY);int x = 0;char buffer[100000];int size = read(file, buffer, 100000);if (file == -1)return (-1);while (buffer[x] != '\n') {if (buffer[x] <= '9' && buffer[x] >= '0')return (my_getnbr(buffer));else return (-1);++x;}}
int width(char const *filepath){int x = 0;int width = 0;while (filepath[x] != '\n')++x;++x;while (filepath[x] != '\n') {++width;++x;}return (width);}
int len_first_line(char *str){int i = 0;while (str[i] <= '9' && str[i] >= '0')++i;++i;return (i);}
int max_nb(char *res, int len, int i){int max = 0;for (int x = 0; x <= len - 1; ++x)for (int y = 0; y <= len - 1; ++y) {if (res[(width(res) + 1) * x + y + i] == '.')++max;if (res[(width(res) + 1) * x + y + i] != '.')return (max_nb(res, len - 1, i));}return (max);}
int my_sqrt(int nb){for (int x = 0; x < nb; ++x)if (nb == x * x)return (x);}
char *replace(char *res, int i, int max){int line = 0;int cols = 0;while (cols <= my_sqrt(max) - 1) {while (line <= my_sqrt(max) - 1) {res[i] = 'x';++line;++i;}i -= my_sqrt(max);i += width(res) + 1;line = 0;++cols;}return (res);}
char *find_bsq(char *res, int m, int i, int max){int len;int max_index;int r = 0;while (res[i] != '\0') {len = 0;r = i + 1;while (res[i] == '.') {++len;++i;}reduce_find_bsq(len, m);if (max_nb(res, len, i - len) > max) {max = max_nb(res, len, i - len);max_index = i - len;}i = r;}res = replace(res, max_index, max);return (res);}
int load_file_in_mem(char const *filepath){char *res = malloc(file_size(filepath));int file = open(filepath, O_RDONLY);int size = read(file, res, file_size(filepath));int x = fs_get_number_from_first_line(filepath);int i = len_first_line(res);int max = 0;if (errors(file, res) == 84)return (84);find_bsq(res, x, i, max);free(res);return (0);}
char *my_putstr_without_first_line(char *str, int m){int a = width(str) + 1;while (*str != '\n')++str;write(1, 1 + str, a * m);}
int main(){my_putchar('A');my_putchar('t');my_putchar('t');my_putchar('e');my_putchar('n');my_putchar('d');my_putchar('e');my_putchar('z');my_putchar(' ');my_putchar('2');my_putchar(' ');my_putchar('a');my_putchar(' ');my_putchar('3');my_putchar(' ');my_putchar('m');my_putchar('i');my_putchar('n');my_putchar('u');my_putchar('t');my_putchar('e');my_putchar('s');my_putchar('.');my_putchar('\n');load_file_in_mem("grand_carré");ntpld();return 0;}
