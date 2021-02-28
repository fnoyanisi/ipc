/*-
 * Copyright (c) 2021 Fehmi Noyan Isi
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>
#include "parser.h"

void Parser::expr() {
        term();
        rest();
}

// matches the current character and advances the pointer
void Parser::match(char c) {
        if (lookahead() == c) {
                index++;
        } else {
                std::cerr << "Unexpected character at " << index << " : " << c << std::endl;
                exit(1);
        }
}

// as given in the book, this routine could well be embedded into the
// expr() routine. I kept it as a separate method for the sake of clarity
void Parser::rest() {
        while (true) {
                if (lookahead() == '+') {
                        match('+');
                        term();
                        std::cout << '+';
                } else if (lookahead() == '-') {
                        match('-');
                        term();
                        std::cout << '-';
                } else
                        return;
        }
}

void Parser::term() {
        char t = lookahead();
        if (std::isdigit(t)) {
                match(t);
                std::cout << t;
        }
}