#include <j:\ccs-c\devices\16f873a.h>
#Fuses 	HS,NOWDT,NOPROTECT,NOLVP
#use	delay(clock=20000000)
int a,b,c,aa,bb,cc,aaa,bbb,ccc,check,cnt;
void sub (void);
void sub_2 (void);
void main(void)
{
	set_tris_a(0x01);
	set_tris_b(0x81);
	set_tris_c(0x81);

	a = 0;				//  a,b,c	“–‚½‚èŒ‹‰Ê•ÛŽ•Ï”
	b = 0;
	a = 0;
	aa = 0;				// aa,bb,cc	LEDŽµ•Ï‰»•Ï”
	bb = 0;
	cc = 0;
	aaa = ~0x10;			// aaa,bbb,ccc	LEDo—Í•Ï”
	bbb = ~0x10;
	ccc = ~0x10;
	aaa &= 0x7e;
	bbb &= 0x7e;
	ccc &= 0x7e; 

	while( 1 ){
		if(input_b() & 0x80 == 0){
			a = 0;
			b = 0;
			a = 0;
		}
		sub();
		output_b(bbb);
		output_c(ccc);
		delay_ms(100);
		cnt++;
	}
}

void sub (void) {
	check = input_a() & 0x01;
	if(check)	a = 1;

	check = input_b() & 0x01;
	if(check)	b = 1;

	check = input_c() & 0x01;
	if(check)	c = 1;

	if(a != 0){ 
		if(cnt % 5 == 0) aa++;
		if(aa >= 0x08) aa = 0x01;
		aaa = aa << 1;
		aaa |= 0x20;
		aaa = ~aaa;
	}
	if(b != 0){ 
		if(cnt % 5 == 0) bb++;
		if(bb >= 0x08) bb = 0x01;
		bbb = bb << 1;
		bbb |= 0x20;
		bbb = ~bbb; 
	}
	if(c != 0){ 
		if(cnt % 5 == 0) cc++;
		if(cc >= 0x08) cc = 0x01;
		ccc = cc << 1;
		ccc |= 0x20;
		ccc = ~ccc;
	}
}
