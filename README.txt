Tema 2: eStore Platform  - Matusa Sebastian-Nicolae 322AA

	Intrega tema este implementata.
	Consider ca aceasta tema m-a ajutat in intelegea mai buna a diferitelor structuri STL, aflarea 
de noi concepte (dynamic cast  si ce inseamna sa lucrezi pe un proiect cu o parte deja implementata.

	La prima cerinta am avut de implementat metode in ierarhiile Product, User si ShoppingCart.
Metodele au constat intr-o serie de constructori (simpli, cu parametrii, de copiere), seteri si
geteri, in unele locuri diversi operatori precum „==” sau „!=”, plus alte metode auxiliare. In unele
cazuri unele metode au necesitat putina mai multa atentie, deoarece trebuia sa am in vedere niste
exceptii. Spre exemplu metoda int getQuantity(int); , unde a trebuit sa verific daca produsul cerut
se afla pe stoc sau nu, in caz contrat fiind necesar sa returnez -1. Produsele din cos le-am sters cu
functia „erase” a map-ului, iar de adaugat, am facut-o cu operator[].
	La cerinta doi, destinata clasei Server partea mai complicata a constat in crearea legaturii
dintre utilizator si cosul sau de cumparaturi. Mi-am luat un iterator cu care am parcurs lista de Users
iar pentru fiecare dintre ei aveam comenzile 
tp = (*p)->getUserID();     
__UserID__ProductsCart__[tp] = new ShoppingCart();  
cu care cream legatura. __UserID__ProductsCart__ este un map cu key-ul de tip int (id-ul utilizatorului),
iar valoarea chiar cosul sau de cumparaturi(obiect de tip ShoppingCart*).
	
	La cerinta trei am avut de implementat diverse interogari.
3a
	Parcurg lista de produse de pe server, extrag id-ul fiecarui produs in parte si verific daca este espressor 
si redus, in acelasi timp (prin formula id-ul: a=3->produs redus, b=9->espressor). Daca sunt indeplinite ambele
conditii adaug produsul respectiv in lista.
3b
	Parcurg lista de useri de pe server si verific daca acesta este nonpremium ( cu ajutorul metodei
getUserType() ) si daca are pretul pe transport sub 11.5lei ( cu ajutorul metodei getTransportCost() ).
Daca sunt intedepline conditiile, adaug user-ul intr-o lista auxiliara si dupa ce am parcurs toata lista de 
useri de pe server o returnez.
3c
	Parcurg lista de produse de pe server. Fac dynamic cast la produs (Product -> ResealedProduct) si
verific daca a avut succes. Fac aceasta conversie pentru a putea avea acces la metoda getReason() pentru
a verifica conditia ceruta de cerinta. Dupa ce am parcurs toata lista de produse si mi-am creat noua lista,
o ordonez dupa pret folosindu-ma de functia sort a std::list. Imi creez in clasa Utility o functie de tip bool care
imi va compara 2 produse (fac de asemenea dynamic cast din Product in NonFoodProduct pentru a avea acces la pret) astfel 
incat sort sa o primeasca ca parametru.
3d
	La aceasta interogare am mers pe acelasi rationament ca si la celelalte. Un lucru mai interesant
ar fi functia de comparare, unde am facut conversie din Product in FoodProduct pentru a avea acces
la campurile dupa care trebuie sa fac compararea. Am comparat dupa nume, tara de origine si apoi dupa pret.
3e
	Mi-am creat o lista care contine utilizatori care au acelasi judet in ambele adrese.
	Am compat-o dupa numele judetului, astfel incat sa pot afla judetul cu cei mai multi locuitori.
	Dupa ce am aflat judetul respectiv, am parcurs iar lista creata anterior si am extras din aceasta 
utilizatorii care stateau la casa intr-o noua lista.
	Am sortat lista dupa id-ul de utilizator si am returnat-o.
3f
	Mi-am creat o lista care contine doar produse de tip telefon sau imprimanta din lista de produse
de pe server.
	Am creat alta lista de utilizatori Premium.
	Parcurg lista de utilizatori Premium si verific in map-ul de discount-uri al fiecaruia daca detine
vreo reducere la vreun telefon sau la vreo imprimanta. Daca da, verific daca aceasta exista in stocul magazinul si in
caz afirmativ adaug utilizatorul respectiv in lista finala.
	Un lucru interesant de care a trebui sa tin cont a fost acela ca a trebuit sa fiu atent nu doar la
a doua cifra din id-ul produsului, ci si la prima, astfel incat sa verific daca produsul nu este alimentar.
	
	La cerinta 4 pentru implementarea metodei processRequests a trebuit sa tin cont de mai multe lucruri:
	Daca size<capacity
		Daca numarul nu se afla in vec_lru, il adaug la inceput, deplasez restul elementelor si maresc size-ul cu 1.
		Daca se afla deja in vec_lru, il adaug la inceput,deplasez restul elementelor si sterg celalalt element identic.
 Size-ul nu se modifica.
		
	Daca size==capacity
		Daca nu se afla in vec_lru, il adaug la inceput si sterg ultimul element.
		Daca se afla deja in vec_lru, il adaug la inceput,deplasez restul elementelor si sterg celalalt element identic
	
	Cerinta Bonus a necesitat cea mai multa atentia si cel mai mult debugging, deoarece au fost foarte multe
detalii tehnice de care a trebui sa se tina cont. In rezolvare m-am folosit de mai toate metode deja implementate care
ma puteau ajuta. Mai multe detalii in comentariile facute in cod.
		


	