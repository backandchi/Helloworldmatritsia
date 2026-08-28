# Helloworldmatritsia

8x8 LED matritsada (MAX7219 drayverli) **HELLO WORLD** harflarini birin-ketin ko'rsatadigan Arduino loyihasi.

## Kerakli qismlar

- Arduino UNO / Nano (yoki mos plata)
- MAX7219 drayverli 8x8 LED matritsa moduli
- Ulash simlari

## Ulanish sxemasi

| MAX7219 | Arduino |
|---------|---------|
| VCC     | 5V      |
| GND     | GND     |
| DIN     | D11     |
| CS      | D10     |
| CLK     | D13     |

## Ishlatish

1. `HelloWorldMatrix/HelloWorldMatrix.ino` faylini Arduino IDE da oching.
2. Platani tanlang (Tools → Board) va portni tanlang (Tools → Port).
3. **Upload** tugmasini bosing.

Hech qanday qo'shimcha kutubxona kerak emas — kod MAX7219 bilan to'g'ridan-to'g'ri ishlaydi.

## Qanday ishlaydi

Harflar birin-ketin chiqadi: **H → E → L → L → O → W → O → R → L → D → ♥** va shu ketma-ketlik qaytadan takrorlanadi.

Kod ichidagi sozlamalar:

- `HARF_VAQTI` — har bir harf qancha vaqt ko'rinishi (standart: 800 ms)
- `PAUZA` — harflar orasidagi qorong'i pauza (standart: 200 ms)
- `REG_INTENSITY` qiymati — yorqinlik (0x00 dan 0x0F gacha)
