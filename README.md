# Junior-Stair-Light-Project

This is a stair light project, based on arduino. Low cost, low effort, still some fun walking up or down the stairs.

I created this for a friend. For several reasons, we connected ground of all LED strips together and led all the positive leads to the circuit for switching/PWM. Because of that, we had to use that dual-transistor circuit, which I found on the internet, to be able to switch the positive lines.
It is actually easier to switch the negative lines, that just requires one transistor/MOSFET, so if you do this you should probably go with that approach.

Nothing more to add really, just read the circuit under schematics/kicad (there is a PDF) and you should be good.

# BOM (for 13 steps):

Power supply, 12V DC, 2A should be enough (I found a 3A in my mess)
1 x Arduino Nano
2 x 10k resistors
1 x 5V regulator (L4940V5)
2 x 100uF electrolytic capacitor
1 x 100nF ceramic capacitor
Per step:
1 x LED stripe (12V, for cars)
2 x 1kOhm resistor
1 x 10kOhm resistor
1 x BC337 (or similar) NPN Transistor
1 x BC327 (or similar) PNP Transistor
A prototype board for soldering components
Some wires for connecting the components
Tools (soldering iron, solder, cutter, clippers, a Dremel helps to cut the copper on the board)

Some time and patience

# Steps:
1. buy all the material
2. create the board (see pictures), start with one channel first
3. test that first channel
4. create all the channels
5. stick it to your stairs

I'll create a PCB, so if you want you can order it from your favourite PCB shop, should be cheap as well and save a lot of time. It is not easy to prototype this stuff, depends on you.



Can probably be done on one weekend.
