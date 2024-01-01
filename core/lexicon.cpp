/*!
 * @class   Lexicon lexicon.cpp lexicon.h
 * @brief   The Lexicon will handle ciphers, names, word generations and hold
 *          the names generated for lookup
*/
#include "lexicon.h"

/*!
 * @brief   Default Constructor
*/
Lexicon::Lexicon() {
  std::srand(std::time(NULL));
  lexigraph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  syllables = {
    "th", "el", "ar", "en", "ka", 
    "lor", "mi", "us", "dra", "gon", 
    "fir", "il", "or", "in", "ter", 
    "sh", "al", "er", "ri", "ma", 
    "on", "re", "is", "ael", "eth", 
    "cia", "an", "tal", "li", "ond", 
    "fel", "ul", "mir", "sa", "vel", 
    "ra", "ith", "ran", "oth", "tor", 
    "zi", "gen", "dru", "gal", "ren", 
    "tal", "nai", "syth", "ke", "zen"
  };
  // Initialize random number generator
}

/*!
 * @brief   Generate A random Name based on Syllable count
 * @param[in] count - Number of Syllables in desired name
*/
std::string Lexicon::generateName(int count) { 
  std::string name;
  for (int i = 0; i < count; ++i) {
    int randomIndex = rand() % syllables.size();
    name += syllables[randomIndex];
  }
  return name;
}

/*!
 * @brief   Returns the current size of the Lexigraph
 * @return  Size of Current Lexigraph
*/
int Lexicon::getLexigraphSize() { return lexigraph.size(); }

/*!
 * @brief   Returns the current size of the Lexigraph
 * @return  Size of Current Lexigraph
*/
void Lexicon::setLexigraph(std::string lexigraph) { this->lexigraph = lexigraph; }

/*!
 * @brief   Default Deconstructor
*/
Lexicon::~Lexicon() { }
