Magicni generator
===================


C program za generiranje svih vrsta magicnih kvadrata
-------------------

Fleksibilan program napisan u c-u gdje korisnik zadaje velicinu stranice, a program generira magicni kvadrat.  
Ukoliko korisnik nema pojma koliki bi kvadrat htio generirati, program mu nudi opciju nasumicno izabranog broja. 
Nakon izvrsenja korisniku je dana opcija da se nastavi igrati dalje ako to zeli. 
Nacin rjesavanja magicnih kvadrata ovisi o njegovim dimenzijama:

 1. slucaj - stranice su neparne (3x3, 5x5, 17x17..) (**odd order**)
 2. slucaj - stranice su parne, ali **nisu** djeljive s 4 (6x6, 10x10, 14x14..) (**even order**)
 3. slucaj - stranice su parne i djeljive su s 4 (4x4, 8x8, 12x12..) (**doubly even order**)

Algoritmi koristeni za rjesavanje sva tri slucaja mogu se pronaci na: http://mathworld.wolfram.com/MagicSquare.html 

![term](term.PNG)

___


