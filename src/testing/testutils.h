/**
 * "debug" namespace header file
**/

#ifndef TESTUTILS_H
#define TESTUTILS_H

#include <string>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <streambuf>

#include "../skipsearch/skipsearch.h"
#include "../kmp_skipsearch/kmp_skipsearch.h"
#include "../alpha_skipsearch/alpha_skipsearch.h"
#include "../beta_skipsearch/beta_skipsearch.h"
#include "../gamma_skipsearch/gamma_skipsearch.h"
#include "../mp/mp.h"
#include "../escape_sequences.h"
#include "../helpers.h"
#include "stringset.h"

using namespace std;

namespace debug {
    void testSSOnMP(StringSet&);
    void testKMPSSOnMP(StringSet&);
    void testAlphaSSOnMP(StringSet&);
    void testBetaSSOnMP(StringSet&);
    void testGammaSSOnMP(StringSet&);


    void fileSearchCompare(string, string, char, char);
    void fullCompare(StringSet&);
    void separatedFullCompare(StringSet&);
}

#endif