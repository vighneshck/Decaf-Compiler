%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
%}

%%
"class" { return CLASS; }
"int" { return DTYPE; }
"boolean" { return DTYPE; }
[a-zA-Z] { return ALPHA; }
[0-9a-zA-Z] { return ALPHA_NUM; }
