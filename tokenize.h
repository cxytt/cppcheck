//---------------------------------------------------------------------------
#ifndef tokenizeH
#define tokenizeH
//---------------------------------------------------------------------------

#include <string>
#include <vector>

extern std::vector<std::string> Files;

struct TOKEN
{
    unsigned int FileIndex;
    char *str;
    unsigned int linenr;
    struct TOKEN *next;
};
extern struct TOKEN *tokens, *tokens_back;


void Tokenize(const char FileName[]);

void TokenizeCode(std::istream &code, const unsigned int FileIndex=0);

// Return size.
int SizeOfType(const char type[]);

// Simplify tokenlist
// -----------------------------
void SimplifyTokenList();


// Deallocate lists..
void DeallocateTokens();


// Helper functions for handling the tokens list..
TOKEN *findtoken(TOKEN *tok1, const char *tokenstr[]);
bool match(const TOKEN *tok, const char pattern[]);
TOKEN *gettok(TOKEN *tok, int index);
const char *getstr(TOKEN *tok, int index);

//---------------------------------------------------------------------------
#endif

