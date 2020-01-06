// ConsoleApplicationW.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <functional>

void affiche()
{
    std::cout << " pointer function" << std::endl;
}
void takefct(int i, std::function<void()> i_f)
{
    std::cout << i;
    i_f();
}
struct Foo
{
    Foo(int i) :m_int(i) {};
    void print_add(int i) { std::cout << i + m_int; }
    int m_int;
};
int main()
{
    auto f = &affiche;
    void (*f1)() = f;
    //void(*affiche)() g = affiche;
    takefct(5, f1);
    takefct(6, []() {std::cout << "i'm a lambda expression";});
    auto binded = std::bind(takefct, 7, f1);
    binded();
    Foo foo(10);
    std::function<void(const Foo, int)> method = &Foo::print_add;
    method(foo, 8);

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
