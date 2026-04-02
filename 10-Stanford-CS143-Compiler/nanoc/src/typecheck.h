#ifndef NANOC_TYPECHECK_H
#define NANOC_TYPECHECK_H

#include "ast.h"

// Returns true if program is type-correct.
bool typecheck(Node* program);

#endif
