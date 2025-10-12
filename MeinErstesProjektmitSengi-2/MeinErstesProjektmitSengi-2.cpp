// Kommentare mit double slash 
//Geschichte: C++ ist die Erweiterung von C, C kann bspw. keine Klassen erstellen

//header dateien: .h gekennzeichnet, zB iostream, werden über #include <namederheaderfile> eingebunden
//header files, die bereits existieren werden über die <> aufgerufen, eigene über ""

#include <iostream>
#include <string> //"visual studios" header file
#include "test.h" //eigene header file

typedef unsigned char byte; //ich kann mir auch eigene "Datentypen" erstellen

//weil unsere construction function nicht funktioniert (wegen der int pointer geschichte in Zeile 21) machen wir noch
//einen wrapper zB Kool Savas
void* address(int* pointer, int offset) //void* ist der DATENTYP für Pointer
{
    return (void*)((long long)pointer + (long long)offset);
}


//in construction legen wir 4 bytes in einen integer ab
void construction(int* dst, byte*b1, byte* b2, byte* b3, byte* b4)
{
    //kopiere b1 in dst
    std::memcpy(address(dst, 0), b1, 1); //wir nehmen dst und schreiben d1 in das erste BYTE
    std::memcpy(address(dst, 1), b2, 1); //same nur diesmal ins 2. BYTE ( realisiert durch dst + 1) -- FALSCH : wir gehen einen ganzen INT weiter! also simmer drüber höhö
    std::memcpy(address(dst, 2), b3, 1); //usw...
    std::memcpy(address(dst, 3), b4, 1);
    return; //optional (aber natürlich OHNE rückgabeparameter weil void
}

int main() //void: meine applikation gibt immer 0 zurück, int: meine applikation kann einen rückgabewert liefern - führt nur irgendwas aus
{
    int speicher = 5; //int: 4byte
    unsigned int int2; //der unsigned int haben keine negativwerte, somit können mehr positive werte genutzt werden - geht mit jedem 
    //zahlenbasierten zahlentypen

    long long schlong1 = 540; //nur "long" kann auch int sein, "long long" ist immer 64bit also 8 byte
        short short1; //2byte
    char char1 = 90; //1 byte, man kann nur zahlen zuweisen und ist genau 1 byte groß 

    byte b1 = 1;
    byte b2 = 1;
    byte b3 = 1;
    byte b4 = 1;
 
    construction(&speicher, &b1, &b2, &b3, &b4);


    // Orte von Variablen (wo sie im speicher zu finden sind) werden mit "&" aufgerufen
    std::cout << "Hello Dirq!\n";
    std::cout << char1 << std::endl;
    std::cout << speicher << std::endl;
}

