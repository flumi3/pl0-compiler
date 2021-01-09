/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    t_const = 258,
    t_var = 259,
    t_procedure = 260,
    t_call = 261,
    t_begin = 262,
    t_end = 263,
    t_if = 264,
    t_then = 265,
    t_while = 266,
    t_do = 267,
    t_odd = 268,
    t_equals = 269,
    t_hashtag = 270,
    t_lt = 271,
    t_lteq = 272,
    t_gt = 273,
    t_gteq = 274,
    t_plus = 275,
    t_minus = 276,
    t_mult = 277,
    t_div = 278,
    t_assign = 279,
    t_qMark = 280,
    t_eMark = 281,
    t_dot = 282,
    t_comma = 283,
    t_semicolon = 284,
    t_br_open = 285,
    t_br_close = 286,
    t_number = 287,
    t_ident = 288
  };
#endif
/* Tokens.  */
#define t_const 258
#define t_var 259
#define t_procedure 260
#define t_call 261
#define t_begin 262
#define t_end 263
#define t_if 264
#define t_then 265
#define t_while 266
#define t_do 267
#define t_odd 268
#define t_equals 269
#define t_hashtag 270
#define t_lt 271
#define t_lteq 272
#define t_gt 273
#define t_gteq 274
#define t_plus 275
#define t_minus 276
#define t_mult 277
#define t_div 278
#define t_assign 279
#define t_qMark 280
#define t_eMark 281
#define t_dot 282
#define t_comma 283
#define t_semicolon 284
#define t_br_open 285
#define t_br_close 286
#define t_number 287
#define t_ident 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "pl0-y-parser.y"

    int num;
    opTree* tree;
    opTreeEntry entry;
    char* id;

#line 130 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
