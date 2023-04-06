#include <NokiaLCD.h>
#include <TimeLib.h>
#define besar 2
#define hitam		0x000
#define NAVY 		0x008
#define BLUE		0x00F
#define TEAL 		0x088
#define EMERALD		0x0C5
#define GREEN		0x0F0
#define CYAN		0x0FF
#define SLATE 		0x244
#define INDIGO  	0x408
#define TURQUOISE	0x4ED
#define olive		0x682
#define maroon 		0x800
#define ungu 		0x808
#define abuAbu 		0x888
#define biruLangit		0x8CE
#define coklat		0xB22
#define crimson 	0xD13
#define orchid 		0xD7D
#define merah		0xF00
#define magenta		0xF0F
#define orange 		0xF40
#define pink		0xF6A
#define koral		0xF75
#define salmon 		0xF87
#define emas		0xFD0
#define kuning		0xFF0
#define putih		0xFFF

NokiaLCD lcd;

const char like[] = {
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x7f,0xf8,
0x00,0xff,0xf8,
0x00,0xff,0xf8,
0x00,0x7f,0xf8,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x01,0xff,0xf8,
0x07,0xff,0xf8,
0x07,0xff,0xf8,
0x0f,0xff,0xf8,
0x1f,0xff,0xf8,
0x3f,0xff,0xf8,
0x7f,0xff,0xf8,
0x7e,0xff,0xf8,
0x10,0xff,0xf8,
0x00,0xff,0xf8,
0x00,0xff,0xf8,
0x00,0xff,0xf8,
0x00,0xff,0xf0,
0x00,0xff,0x80,
0x00,0x7e,0x00,
0x00,0x38,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
};

const char youtube[] = {
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x07,0xff,0xc0,
0x03,0xff,0x80,
0x03,0xff,0x80,
0x01,0xff,0x00,
0x01,0xff,0x00,
0x00,0xfe,0x00,
0x00,0x7e,0x00,
0x00,0x7c,0x00,
0x00,0x38,0x00,
0x00,0x38,0x00,
0x00,0x10,0x00,
0x00,0x10,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
0x00,0x00,0x00,
};

const char WidthPages = 3;
const char HeightPixels = 32;

void setup()
{
  DDRD |= B01111100;
  PORTD |= B01111100;
  lcd.lcd_init();
  lcd.lcd_clear(putih,0,0,131,131);
  setTime(23,59,50,31,12,2023);
//  printHari();
//  printDate();
//  printTime(hour(),minute(),second());
}

void printHari()
{
  char hari[10];
  sprintf(hari,"%9s",dayStr(weekday()));
  lcd.LCDPutStr(hari,30,2,besar,biruLangit,putih);
}

void printTime(int h,int m,int s)
{
 char detik[4];
 if (second() < 10)
  {
    sprintf(detik,"0%1d",second());
  }
  else
  {
    sprintf(detik, "%2d",second());
  }
  lcd.LCDPutStr(detik,10,50,besar,orange,putih);
  char menit[4];
  if (minute() < 10)
  {
    sprintf(menit, "0%1d:", minute());
  }
  else
  {
    sprintf(menit, "%2d:", minute());
  }
  lcd.LCDPutStr(menit,10,26,besar,maroon,putih);
  char jam[4];
  if (hour() < 10)
  {
    sprintf(jam, "0%1d:", hour());
  }
  else
  {
    sprintf(jam, "%2d:", hour());
  }
 lcd.LCDPutStr(jam,10,2,besar,orange,putih);
}

void printDate()
{
 char tanggal[4];
 sprintf(tanggal,"%2d",day());
 lcd.LCDPutStr(tanggal,50,2,besar,coklat,putih);
 char bulan[12];
 sprintf(bulan,"%9s",monthStr(month()));
 lcd.LCDPutStr(bulan,50,16,besar,orchid,putih);
 char tahun[6];
 sprintf(tahun,"%4d",year());
 lcd.LCDPutStr(tahun,50,98,besar,ungu,putih);
}

void logo(int x0, int y0) {
  for (int row = 0; row < HeightPixels; row++) {
    for (int col = 0; col < WidthPages; col++) {
      unsigned char logo = youtube[row * WidthPages + col];
      for (int x = 0; x < 8; x++) {
        if ((logo >> (7 - x) & 0x01) != 1) {
          lcd.LCDSetPixel(x0 + col * 8 + x, row + y0, merah);
        }
      }
    }
  }
}

void suka(int x0, int y0) {
  for (int row = 0; row < HeightPixels; row++) {
    for (int col = 0; col < WidthPages; col++) {
      unsigned char suka = like[row * WidthPages + col];
      for (int x = 0; x < 8; x++) {
        if ((suka >> (7 - x) & 0x01) != 1) {
          lcd.LCDSetPixel(x0 + col * 8 + x, row + y0, merah);
        }
      }
    }
  }
}

void loop()
{
 printTime(hour(),minute(),second());
 printDate();
 printHari();
 suka(74,4);
 lcd.LCDSetRect(74,4,98,128,0,merah);
 lcd.LCDSetRect(73,5,97,127,0,merah);
 lcd.LCDPutStr("LIKE",81,38,besar,merah,putih);
 logo(104,4);
 lcd.LCDSetRect(104,4,128,128,0,merah);
 lcd.LCDSetRect(105,5,127,127,0,merah);
 lcd.LCDPutStr("SUBSCRIBE",110,38,besar,merah,putih);
}
