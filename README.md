# Helloworldmatritsia

An Arduino project that displays the letters of **HELLO WORLD** one by one on an 8x8 LED matrix (MAX7219 driver).

## Required Parts

- Arduino UNO / Nano (or compatible board)
- 8x8 LED matrix module with MAX7219 driver
- Jumper wires

## Wiring

| MAX7219 | Arduino |
|---------|---------|
| VCC     | 5V      |
| GND     | GND     |
| DIN     | D11     |
| CS      | D10     |
| CLK     | D13     |

## Usage

1. Open `HelloWorldMatrix/HelloWorldMatrix.ino` in the Arduino IDE.
2. Select your board (Tools → Board) and port (Tools → Port).
3. Click **Upload**.

No extra libraries are required — the code talks to the MAX7219 directly.

## How It Works

The letters appear one by one: **H → E → L → L → O → W → O → R → L → D → ♥**, and the sequence repeats.

Settings in the code:

- `HARF_VAQTI` — how long each letter stays on screen (default: 800 ms)
- `PAUZA` — dark pause between letters (default: 200 ms)
- `REG_INTENSITY` value — brightness (0x00 to 0x0F)
