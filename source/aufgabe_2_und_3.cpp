//sequentielle Container:
/* vector:
Ähnelt einem Array
bietet wahlfreien Zugriff auf alle Elemente.
Einfügen und Löschen benötigt etwas mehr Zeit, da große Teile des Vectors in den Speicher verschoben werden müssen

deque:
double-ended-queue
Ähnlich wie vector, aber optimiertes einfuegen und loeschen.
gut fuer FIFO/LIFO Implementierungen

list:
doppelt verkettete Liste
optimiertes Sortieren der Elemente im Gegensatz zu vector oder deque

assoziative Container:
set/mutliset:
sortierter assoziativer Container. Sortierung wird immer Aufrecht erhalten.
eignet sich gut fuer Mengenoperationen.
multiset kann ein Element mehrfach enthalten set nicht.

map/multimap:
ähnlich wie set, aber Elemente sind Wertepaare.

Beispiele:
Speichern der Punkte eines Polygons:
vector: feste Anzahl an Punkten -> keine Probleme mit einfuegen und loeschen + freier Zugriff

Zuordnung von Farbnamen und entsprechenden RGB-Werten:
map: sortiertes Speichern von Name(String) und RGB Werten (map, da jeder Wert nur einmal benötigt wird)

FIFO-Warteschlange von Druckaufträgen:
deque: optimiertes einfuegen am Anfang und loeschen am Ende perfekt fuer FIFO
*/
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <time.h>



int main(){

    //init pseudo-random numbers
    srand(time(nullptr));

    std::list<unsigned int> liste;
    std::set<unsigned int> set;
    std::set<unsigned int> out;
    std::map<int, int> amount;

    int counter = 0;
    int counter2 = 0;
    int counter3 = 1;

    for(int i = 1; i <= 100; i++){
        liste.push_front(std::rand() % 100 + 1);
    }

    for(int index: liste){
        set.insert(index);
    }

    //count how many different numbers are in the set
    for(int index: set){
        counter2++;
    }

    //numbers that dont occur are inserted in a new set out
    for(int i = 1; i <= 100; i++){
        if(set.count(i) == 0){
            out.insert(i);
        }
    }

    std::cout << "These numbers are not included in the list: " << std::endl;
    //output:
    for(int index: out){
        std::cout << index << std::endl;
    }
    
    return 0;
}