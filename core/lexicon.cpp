#include "lexicon.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
Lexicon::Lexicon() {
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
  std::srand(std::time({}));
}

/*!
 * @todo    Generate A random Name based on Syllable count
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
 * @todo    Returns the current size of the Lexigraph
*/
int Lexicon::getLexigraphSize() {
  return lexigraph.size();
}

/*!
 * @todo    Returns the current size of the Lexigraph
*/
void Lexicon::setLexigraph(std::string lexigraph) { this->lexigraph = lexigraph; }

void Lexicon::_help() {
  std::string helpline = "\nLexicon Help File"
  "\n";
  this->log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Lexicon::~Lexicon() { }
