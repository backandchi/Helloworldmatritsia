/*
 * HELLO WORLD - 8x8 LED Matritsa (MAX7219)
 * ----------------------------------------
 * Harflar birin-ketin (H, E, L, L, O, keyin W, O, R, L, D)
 * 8x8 matritsada chiqadi.
 *
 * Ulanish (Arduino UNO / Nano):
 *   MAX7219 VCC  -> 5V
 *   MAX7219 GND  -> GND
 *   MAX7219 DIN  -> D11
 *   MAX7219 CS   -> D10
 *   MAX7219 CLK  -> D13
 *
 * Hech qanday qo'shimcha kutubxona kerak emas!
 */

// Pinlar
const int DIN_PIN = 11;
const int CS_PIN  = 10;
const int CLK_PIN = 13;

// MAX7219 registrlari
const byte REG_NOOP        = 0x00;
const byte REG_DECODEMODE  = 0x09;
const byte REG_INTENSITY   = 0x0A;
const byte REG_SCANLIMIT   = 0x0B;
const byte REG_SHUTDOWN    = 0x0C;
const byte REG_DISPLAYTEST = 0x0F;

// Har bir harf ko'rinish vaqti (millisekund)
const unsigned int HARF_VAQTI = 800;
const unsigned int PAUZA      = 200;   // harflar orasidagi qorong'i pauza

// 8x8 harf shakllari (har bir byte - bitta qator)
const byte HARF_H[8] = {
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};

const byte HARF_E[8] = {
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01111100,
  B01100000,
  B01100000,
  B01111110
};

const byte HARF_L[8] = {
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110,
  B01111110
};

const byte HARF_O[8] = {
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100
};

const byte HARF_W[8] = {
  B01100011,
  B01100011,
  B01100011,
  B01101011,
  B01101011,
  B01111111,
  B01110111,
  B01100011
};

const byte HARF_R[8] = {
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01111000,
  B01101100,
  B01100110,
  B01100011
};

const byte HARF_D[8] = {
  B01111100,
  B01100110,
  B01100011,
  B01100011,
  B01100011,
  B01100011,
  B01100110,
  B01111100
};

const byte HARF_YURAK[8] = {   // oxirida bonus :)
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000
};

// "HELLO WORLD" ketma-ketligi
const byte* SOZ[] = {
  HARF_H, HARF_E, HARF_L, HARF_L, HARF_O,   // HELLO
  HARF_W, HARF_O, HARF_R, HARF_L, HARF_D,   // WORLD
  HARF_YURAK
};
const int HARFLAR_SONI = sizeof(SOZ) / sizeof(SOZ[0]);

// MAX7219 ga bitta buyruq yuborish
void max7219Yoz(byte registr, byte qiymat) {
  digitalWrite(CS_PIN, LOW);
  shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, registr);
  shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, qiymat);
  digitalWrite(CS_PIN, HIGH);
}

// Ekranni tozalash
void ekranTozala() {
  for (byte qator = 1; qator <= 8; qator++) {
    max7219Yoz(qator, B00000000);
  }
}

// Bitta harfni matritsaga chiqarish
void harfChiqar(const byte harf[8]) {
  for (byte qator = 0; qator < 8; qator++) {
    max7219Yoz(qator + 1, harf[qator]);
  }
}

void setup() {
  pinMode(DIN_PIN, OUTPUT);
  pinMode(CS_PIN,  OUTPUT);
  pinMode(CLK_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  // MAX7219 ni sozlash
  max7219Yoz(REG_DISPLAYTEST, 0x00);  // test rejimini o'chirish
  max7219Yoz(REG_DECODEMODE,  0x00);  // dekodlashsiz (matritsa rejimi)
  max7219Yoz(REG_SCANLIMIT,   0x07);  // barcha 8 qator
  max7219Yoz(REG_INTENSITY,   0x08);  // yorqinlik (0x00 - 0x0F)
  max7219Yoz(REG_SHUTDOWN,    0x01);  // ekranni yoqish

  ekranTozala();
}

void loop() {
  // Harflarni birin-ketin chiqarish
  for (int i = 0; i < HARFLAR_SONI; i++) {
    harfChiqar(SOZ[i]);
    delay(HARF_VAQTI);

    ekranTozala();
    delay(PAUZA);
  }

  // So'z tugagach biroz kutib, qaytadan boshlash
  delay(1000);
}
