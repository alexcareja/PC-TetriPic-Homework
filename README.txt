**************************README**************************
=========================TetriPic=========================

Student: Careja Alexandru-Cristian
Grupa: 314CD

Codul este impartit in mai multe fisiere sursa pentru o
modularizare mai buna;


Task 1 - Pentru realizarea taskului 1 si 2 am descoperit
	ca fiecare piesa poate fi construita din cate 2
	dreptunghiuri (sau doar unul in cazurile O si I).
	Functia piesa(...) primeste ca argumente inaltimea
	si latimea piesei, apoi cate 4 coordonate pentru 
	fiecare dreptunghi(pozitia coltului din stanga sus
	si pozitia coltului din dreapta jos), iar in final
	primeste tot ca argumente valorile Red Green Blue
	pentru colorarea piesei, si numele fisierului de
	output. In functia piesa(...) sunt completate
	campurile fileheader si infoheader al fiecarei 
	piese, pe de o parte cu valorile default date in
	cerinta temei (functia basic_data se ocupa de 
	aceasta), iar pe de alta parte cu valorile 
	caracteristice fiecarei piese, anume height, width
	numarul de biti, etc. Piesa este mai intai creata
	si completata cu toate campurile albe. Apoi sunt
	scrise si bucatile din piesa prin metoda celor 2 
	dreptunghiuri. Piesa este gata sa fie scrisa, dar
	trebuie verificat daca aceasta are nevoie de un 
	padding la finalul fiecarui rand de biti. Verific
	daca latimea piesei (in biti) este multiplu de 4.
	Daca este multiplu de 4, atunci nu are nevoie de
	padding, dar daca piesa are o latime de exemplu
	de 310 pixeli, ea are nevoie de 2 bytes de padding
	la finalul fiecarei linii de pixeli. Acest lucru
	l-am implementat printr-o variabila short careia 
	i-am dat valoarea 0 (pentru ca toti cei 16 biti sa
	fie 0) si am scris-o la finalul fiecarui rand de 
	biti (acolo unde a fost nevoie de padding).
	

Task 2 - Am folosit aceeasi functie ca la taskul 1

Task 3 - Citirea datelor din fisierul ".in". Pentru o 
	rezolvare mai usoara am folosit o harta minimizata
	in care un element reprezinta un patrat de 10x10
	pixeli din matricea finala. In harta minimizata
	0 reprezinta negru, 1 alb, iar I, O, S, Z, L, J, T
	reprezinta un patrat din piesa corespunzatoare.
	Harta minimizata e initializata neagra, si cu 4
	linii albe deasupra. Este apelata functia 
	drop_pieces(...) unde fiecare piesa este creata
	intr-o matrice de aceleasi dimensiuni ca harta
	si in care am facut piesa sa cada cu cate un rand,
	pana cand ar avea o coliziune in harta. In momentul
	in care este detectata o coliziune, piesa este 
	copiata in harta, se verifica daca s-a completat 
	vreo linie (in scopul de a o elimina) si se trece
	la urmatoarea piesa. Daca o piesa incalca spatiul
	alb de deasupra hartii in momentul in care este 
	pusa in harta, atunci jocul ia sfarsit. Dupa ce
	au cazut toate piesele, sau jocul a luat sfarsit
	harta minimizata este convertita la o harta de 
	pixeli RGB si fiecare litera (I, o, S, etc.) si 1
	si 0 sunt inlocuiti cu valorile Red Green Blue
	pentru colorarea hartii si a pieselor din ea.

Task 4 - Aici am citit datele din cerinta4.bmp si mi-am
	initializat o harta (de 10 x 10 ori mai mica) in
	care am memorat culorile (0, 1, I, O , S, etc.)
	pentru fiecare patrat de 10x10 pixeli, si am aplicat
	algoritmul de la taskul 3 de cadere al pieselor.
