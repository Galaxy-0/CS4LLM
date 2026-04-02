#ifndef NANOC_PARSER_H
#define NANOC_PARSER_H

#include "ast.h"

// Returns a ND_PROGRAM node, or NULL on failure.
Node* parse(const char* source);

#endif
