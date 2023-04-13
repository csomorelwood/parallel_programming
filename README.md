# ZH Felkészülés PP

## 1. Írj C programot, amely Linux IPC-t használ.
Hozz létre egy közös memóriaszegmenst egész érték tárolására és inicializáld egy tetszőleges pozitív
számmal. A szülő processz hozzon létre 3 db gyerek processzt:
(a) ha a gyerekprocessz azonosítója páros: altassuk a processzt 3 másodpercig, majd ezt követően
szorozza be a közös szegmensen található értéket 3-mal
(b) ha a gyerekprocessz azonosítója páratlan: altassuk a processzt 1 másodpercig, majd szorozza
be a közös szegmensen található értéket 7-tel
A szülő processz várja meg a gyerek processzeket és írja ki a szegmens aktuális értékét. Kölcsönös
kizárással biztosítsd, hogy a gyerekprocesszek ne írják felül egymás számításait. Csak és kizárólag
a szükséges kódrészlet legyen része a kritikus szakasznak.
*25 pont*

## 2. Írj egy párhuzamosan futó Java programot.
Legyen legalább 2 db Consumer és pontosan 1 db Producer szálad. A Producer töltsön fel egy
kollekciót random számokkal úgy, hogy a Consumer-ek egyenlően fel tudják osztani azt maguk
között. A Consumer-ek várják meg a feltöltést. Ezt követően minden Consumer számolja ki a
részkollekcióban lévő számok összegét. A számítások után a Producer írja ki a teljes kollekcióban
lévő számok számtani közepét felhasználva a Consumer-ek által elvégzett összegzéseket.
Figyelj a kölcsönös kizárásra és a párhuzamosan futtatható részekre az erőforrást reprezentáló Buffer
osztály megfelelő metódusainál, csak és kizárólag a szükséges kódrészlet legyen része a kritikus
*25 pont*

## 3. Írj párhuzamos processzekből álló Occam programot, amely egy olyan automatát valósít meg, amely
felismeri azt, hogy a szóban előforduló ’o’ - ’c’ - ’a’ - ’m’ karakterek számának összege osztható-e
hárommal. A bejövő karaktereket a standard input-ról olvassa, az eredményt a standard output-ra
írja.
A program az ENTER billentyű leütésére jelenítse meg az eredményt ("Osztható"/"Nem osztható"),
majd szabályosan lépjen ki. A csővezeték lépései:
(a) folyamat: csak az ’o’ - ’c’ - ’a’ - ’m’ karaktereket engedi át
(b) folyamat: eldönti, hogy osztható-e 3-mal a beérkezett karakterek száma
*25 pont*

## 4. Írj párhuzamosan futó taszkokból álló PVM programot.
A master hozzon létre 3 új processzt, amelyek a worker kódot futtatják. A master mindhárom
worker-nek elküld egy egymástól különböző prímszámot. A worker-ek fogadják ezt a számot, majd
kiszámolják a kapott szám faktoriálisát és visszaküldik a master-nek, amely kiírja a kapott számok
összegét. A számokat double-ként kezeld.
Figyelj a túlcsordulásra, ilyen esetben írja ki a program, hogy túlcsordulás történt.
*25 pont*
