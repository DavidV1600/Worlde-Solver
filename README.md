# Echipa
Voinescu David-Ioan,
Milosi Elias,
Huminic Angel


# Descriere Proiect
Algoritmul de gasire a cuvantului potrivit se bazeaza pe teoria informatiei, folosind Entropia lui Shannon. Acesta calculeaza pentru fiecare litera din alfabet probabilitatea ei de a aparea pe orice pozitie (1,2,3,4,5) in cuvintele ramase posibile, iar analizand toate cuvintele, il alege pe cel care ofera cea mai multa informatie. Algoritmul foloseste varianta (easy mode), in care el poate folosi cuvinte chiar daca acestea nu mai au posibilitatea de a fi raspunsul corect, aceasta varianta fiind mai buna deoarece exista situatii in care un cuvant care nu poate fi solutia ofera mai multa informatie, decat oricare din cele ramase ca posibilitati de a fi solutia.

# Media de rezolvare
Algoritmul are o medie de 4.35 (4.34922) incercari pana a gasi raspunsul corect si incepe sa ghiceasca cu cuvantul LUTRE.

# Pornire proiect
Pentru a rula modul in care jocul se rezolva singur trebuie deschise 2 console/terminale simultan, in primul vom rula comanda "./AI", iar apoi in celalalt vom rula "./JOC".
Pentru a rula doar jocul, unde utilizatorul introduce cuvinte trebuie rulata doar comanda "./JOC".
Daca nu functioneaza trebuie rulate "g++ main.cpp -o AI" si "g++ main2.cpp -o JOC", iar apoi cele doi comenzi.

# Referinte
https://youtu.be/v68zYyaEmEA,  
https://youtu.be/fRed0Xmc2Wg
