// A Bison parser, made by GNU Bison 3.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.


// Take the name prefix into account.
#define yylex   ftcexpr_lex



#include "ftcexpr_yacc_defines.gen.hxx"


// Unqualified %code blocks.
#line 31 "ftcexpr.gen.yacc"

#include "ftcexpr_demo_driver.hxx"
#include "ftcexpr_parse_intlit.hxx"

#define FTCEXPR_DRV() drv

#line 54 "ftcexpr_yacc.gen.cxx"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if FTCEXPR_DEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !FTCEXPR_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !FTCEXPR_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "ftcexpr.gen.yacc"
namespace ftcexpr {
#line 149 "ftcexpr_yacc.gen.cxx"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (ftcexpr_demo::Driver& drv_yyarg, void *yyscanner_yyarg)
    :
#if FTCEXPR_DEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      drv (drv_yyarg),
      yyscanner (yyscanner_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 58: // ftcexpr_primary_expression
      case 59: // ftcexpr_postfix_expression
      case 60: // ftcexpr_unary_expression
      case 61: // ftcexpr_multiplicative_expression
      case 62: // ftcexpr_additive_expression
      case 63: // ftcexpr_shift_expression
      case 64: // ftcexpr_relational_expression
      case 65: // ftcexpr_equality_expression
      case 66: // ftcexpr_and_expression
      case 67: // ftcexpr_exclusive_or_expression
      case 68: // ftcexpr_inclusive_or_expression
      case 69: // ftcexpr_logical_and_expression
      case 70: // ftcexpr_logical_or_expression
      case 71: // ftcexpr_conditional_expression
      case 72: // ftcexpr_expression
        value.YY_MOVE_OR_COPY< ftcexpr_rule_type > (YY_MOVE (that.value));
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 40: // ftcexpr_primary_leaf_expression
      case 41: // ftcexpr_LEFT_OP
      case 42: // ftcexpr_RIGHT_OP
      case 43: // ftcexpr_LE_OP
      case 44: // ftcexpr_GE_OP
      case 45: // ftcexpr_EQ_OP
      case 46: // ftcexpr_NE_OP
      case 47: // ftcexpr_AND_OP
      case 48: // ftcexpr_OR_OP
      case 49: // ftcexpr_argument_expression_list
      case 50: // ftcexpr_member_access
      case 51: // ftcexpr_INC_OP
      case 52: // ftcexpr_DEC_OP
      case 53: // ftcexpr_cast_expression
      case 54: // ftcexpr_ADDRESSOF
      case 55: // ftcexpr_DEREFER
      case 56: // ftcexpr_type
      case 57: // ftcexpr_SIZEOF
        value.YY_MOVE_OR_COPY< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 58: // ftcexpr_primary_expression
      case 59: // ftcexpr_postfix_expression
      case 60: // ftcexpr_unary_expression
      case 61: // ftcexpr_multiplicative_expression
      case 62: // ftcexpr_additive_expression
      case 63: // ftcexpr_shift_expression
      case 64: // ftcexpr_relational_expression
      case 65: // ftcexpr_equality_expression
      case 66: // ftcexpr_and_expression
      case 67: // ftcexpr_exclusive_or_expression
      case 68: // ftcexpr_inclusive_or_expression
      case 69: // ftcexpr_logical_and_expression
      case 70: // ftcexpr_logical_or_expression
      case 71: // ftcexpr_conditional_expression
      case 72: // ftcexpr_expression
        value.move< ftcexpr_rule_type > (YY_MOVE (that.value));
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 40: // ftcexpr_primary_leaf_expression
      case 41: // ftcexpr_LEFT_OP
      case 42: // ftcexpr_RIGHT_OP
      case 43: // ftcexpr_LE_OP
      case 44: // ftcexpr_GE_OP
      case 45: // ftcexpr_EQ_OP
      case 46: // ftcexpr_NE_OP
      case 47: // ftcexpr_AND_OP
      case 48: // ftcexpr_OR_OP
      case 49: // ftcexpr_argument_expression_list
      case 50: // ftcexpr_member_access
      case 51: // ftcexpr_INC_OP
      case 52: // ftcexpr_DEC_OP
      case 53: // ftcexpr_cast_expression
      case 54: // ftcexpr_ADDRESSOF
      case 55: // ftcexpr_DEREFER
      case 56: // ftcexpr_type
      case 57: // ftcexpr_SIZEOF
        value.move< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 58: // ftcexpr_primary_expression
      case 59: // ftcexpr_postfix_expression
      case 60: // ftcexpr_unary_expression
      case 61: // ftcexpr_multiplicative_expression
      case 62: // ftcexpr_additive_expression
      case 63: // ftcexpr_shift_expression
      case 64: // ftcexpr_relational_expression
      case 65: // ftcexpr_equality_expression
      case 66: // ftcexpr_and_expression
      case 67: // ftcexpr_exclusive_or_expression
      case 68: // ftcexpr_inclusive_or_expression
      case 69: // ftcexpr_logical_and_expression
      case 70: // ftcexpr_logical_or_expression
      case 71: // ftcexpr_conditional_expression
      case 72: // ftcexpr_expression
        value.move< ftcexpr_rule_type > (that.value);
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      case 40: // ftcexpr_primary_leaf_expression
      case 41: // ftcexpr_LEFT_OP
      case 42: // ftcexpr_RIGHT_OP
      case 43: // ftcexpr_LE_OP
      case 44: // ftcexpr_GE_OP
      case 45: // ftcexpr_EQ_OP
      case 46: // ftcexpr_NE_OP
      case 47: // ftcexpr_AND_OP
      case 48: // ftcexpr_OR_OP
      case 49: // ftcexpr_argument_expression_list
      case 50: // ftcexpr_member_access
      case 51: // ftcexpr_INC_OP
      case 52: // ftcexpr_DEC_OP
      case 53: // ftcexpr_cast_expression
      case 54: // ftcexpr_ADDRESSOF
      case 55: // ftcexpr_DEREFER
      case 56: // ftcexpr_type
      case 57: // ftcexpr_SIZEOF
        value.move< uint64_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if FTCEXPR_DEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 3: // INTLITERAL
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < std::string > (); }
#line 463 "ftcexpr_yacc.gen.cxx"
        break;

      case 4: // IDENTIFIER
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < std::string > (); }
#line 469 "ftcexpr_yacc.gen.cxx"
        break;

      case 40: // ftcexpr_primary_leaf_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 475 "ftcexpr_yacc.gen.cxx"
        break;

      case 41: // ftcexpr_LEFT_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 481 "ftcexpr_yacc.gen.cxx"
        break;

      case 42: // ftcexpr_RIGHT_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 487 "ftcexpr_yacc.gen.cxx"
        break;

      case 43: // ftcexpr_LE_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 493 "ftcexpr_yacc.gen.cxx"
        break;

      case 44: // ftcexpr_GE_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 499 "ftcexpr_yacc.gen.cxx"
        break;

      case 45: // ftcexpr_EQ_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 505 "ftcexpr_yacc.gen.cxx"
        break;

      case 46: // ftcexpr_NE_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 511 "ftcexpr_yacc.gen.cxx"
        break;

      case 47: // ftcexpr_AND_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 517 "ftcexpr_yacc.gen.cxx"
        break;

      case 48: // ftcexpr_OR_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 523 "ftcexpr_yacc.gen.cxx"
        break;

      case 49: // ftcexpr_argument_expression_list
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 529 "ftcexpr_yacc.gen.cxx"
        break;

      case 50: // ftcexpr_member_access
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 535 "ftcexpr_yacc.gen.cxx"
        break;

      case 51: // ftcexpr_INC_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 541 "ftcexpr_yacc.gen.cxx"
        break;

      case 52: // ftcexpr_DEC_OP
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 547 "ftcexpr_yacc.gen.cxx"
        break;

      case 53: // ftcexpr_cast_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 553 "ftcexpr_yacc.gen.cxx"
        break;

      case 54: // ftcexpr_ADDRESSOF
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 559 "ftcexpr_yacc.gen.cxx"
        break;

      case 55: // ftcexpr_DEREFER
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 565 "ftcexpr_yacc.gen.cxx"
        break;

      case 56: // ftcexpr_type
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 571 "ftcexpr_yacc.gen.cxx"
        break;

      case 57: // ftcexpr_SIZEOF
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < uint64_t > (); }
#line 577 "ftcexpr_yacc.gen.cxx"
        break;

      case 58: // ftcexpr_primary_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 583 "ftcexpr_yacc.gen.cxx"
        break;

      case 59: // ftcexpr_postfix_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 589 "ftcexpr_yacc.gen.cxx"
        break;

      case 60: // ftcexpr_unary_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 595 "ftcexpr_yacc.gen.cxx"
        break;

      case 61: // ftcexpr_multiplicative_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 601 "ftcexpr_yacc.gen.cxx"
        break;

      case 62: // ftcexpr_additive_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 607 "ftcexpr_yacc.gen.cxx"
        break;

      case 63: // ftcexpr_shift_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 613 "ftcexpr_yacc.gen.cxx"
        break;

      case 64: // ftcexpr_relational_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 619 "ftcexpr_yacc.gen.cxx"
        break;

      case 65: // ftcexpr_equality_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 625 "ftcexpr_yacc.gen.cxx"
        break;

      case 66: // ftcexpr_and_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 631 "ftcexpr_yacc.gen.cxx"
        break;

      case 67: // ftcexpr_exclusive_or_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 637 "ftcexpr_yacc.gen.cxx"
        break;

      case 68: // ftcexpr_inclusive_or_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 643 "ftcexpr_yacc.gen.cxx"
        break;

      case 69: // ftcexpr_logical_and_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 649 "ftcexpr_yacc.gen.cxx"
        break;

      case 70: // ftcexpr_logical_or_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 655 "ftcexpr_yacc.gen.cxx"
        break;

      case 71: // ftcexpr_conditional_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 661 "ftcexpr_yacc.gen.cxx"
        break;

      case 72: // ftcexpr_expression
#line 59 "ftcexpr.gen.yacc"
        { yyo << yysym.value.template as < ftcexpr_rule_type > (); }
#line 667 "ftcexpr_yacc.gen.cxx"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if FTCEXPR_DEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // FTCEXPR_DEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv, yyscanner));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 58: // ftcexpr_primary_expression
      case 59: // ftcexpr_postfix_expression
      case 60: // ftcexpr_unary_expression
      case 61: // ftcexpr_multiplicative_expression
      case 62: // ftcexpr_additive_expression
      case 63: // ftcexpr_shift_expression
      case 64: // ftcexpr_relational_expression
      case 65: // ftcexpr_equality_expression
      case 66: // ftcexpr_and_expression
      case 67: // ftcexpr_exclusive_or_expression
      case 68: // ftcexpr_inclusive_or_expression
      case 69: // ftcexpr_logical_and_expression
      case 70: // ftcexpr_logical_or_expression
      case 71: // ftcexpr_conditional_expression
      case 72: // ftcexpr_expression
        yylhs.value.emplace< ftcexpr_rule_type > ();
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case 40: // ftcexpr_primary_leaf_expression
      case 41: // ftcexpr_LEFT_OP
      case 42: // ftcexpr_RIGHT_OP
      case 43: // ftcexpr_LE_OP
      case 44: // ftcexpr_GE_OP
      case 45: // ftcexpr_EQ_OP
      case 46: // ftcexpr_NE_OP
      case 47: // ftcexpr_AND_OP
      case 48: // ftcexpr_OR_OP
      case 49: // ftcexpr_argument_expression_list
      case 50: // ftcexpr_member_access
      case 51: // ftcexpr_INC_OP
      case 52: // ftcexpr_DEC_OP
      case 53: // ftcexpr_cast_expression
      case 54: // ftcexpr_ADDRESSOF
      case 55: // ftcexpr_DEREFER
      case 56: // ftcexpr_type
      case 57: // ftcexpr_SIZEOF
        yylhs.value.emplace< uint64_t > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 81 "ftcexpr.gen.yacc"
    { drv.last_result = yystack_[1].value.as < ftcexpr_rule_type > (); }
#line 951 "ftcexpr_yacc.gen.cxx"
    break;

  case 3:
#line 84 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = ftcexpr::parse_intlit(yystack_[0].value.as < std::string > ()).value; }
#line 957 "ftcexpr_yacc.gen.cxx"
    break;

  case 4:
#line 85 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = FTCEXPR_DRV().demo_getfunc(yystack_[0].value.as < std::string > ()); }
#line 963 "ftcexpr_yacc.gen.cxx"
    break;

  case 5:
#line 89 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 969 "ftcexpr_yacc.gen.cxx"
    break;

  case 6:
#line 90 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 975 "ftcexpr_yacc.gen.cxx"
    break;

  case 7:
#line 91 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 981 "ftcexpr_yacc.gen.cxx"
    break;

  case 8:
#line 92 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 987 "ftcexpr_yacc.gen.cxx"
    break;

  case 9:
#line 93 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 993 "ftcexpr_yacc.gen.cxx"
    break;

  case 10:
#line 94 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 999 "ftcexpr_yacc.gen.cxx"
    break;

  case 11:
#line 95 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1005 "ftcexpr_yacc.gen.cxx"
    break;

  case 12:
#line 96 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1011 "ftcexpr_yacc.gen.cxx"
    break;

  case 13:
#line 98 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1017 "ftcexpr_yacc.gen.cxx"
    break;

  case 14:
#line 99 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1023 "ftcexpr_yacc.gen.cxx"
    break;

  case 15:
#line 100 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1029 "ftcexpr_yacc.gen.cxx"
    break;

  case 16:
#line 101 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1035 "ftcexpr_yacc.gen.cxx"
    break;

  case 17:
#line 102 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1041 "ftcexpr_yacc.gen.cxx"
    break;

  case 18:
#line 103 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1047 "ftcexpr_yacc.gen.cxx"
    break;

  case 19:
#line 104 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1053 "ftcexpr_yacc.gen.cxx"
    break;

  case 20:
#line 105 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1059 "ftcexpr_yacc.gen.cxx"
    break;

  case 21:
#line 107 "ftcexpr.gen.yacc"
    { yylhs.value.as < uint64_t > () = 0; }
#line 1065 "ftcexpr_yacc.gen.cxx"
    break;

  case 22:
#line 144 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < uint64_t > (); }
#line 1071 "ftcexpr_yacc.gen.cxx"
    break;

  case 23:
#line 145 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[1].value.as < ftcexpr_rule_type > (); }
#line 1077 "ftcexpr_yacc.gen.cxx"
    break;

  case 24:
#line 149 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1083 "ftcexpr_yacc.gen.cxx"
    break;

  case 25:
#line 150 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().subscript(yystack_[3].value.as < ftcexpr_rule_type > (),yystack_[1].value.as < ftcexpr_rule_type > ()); }
#line 1089 "ftcexpr_yacc.gen.cxx"
    break;

  case 26:
#line 151 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().call(yystack_[3].value.as < ftcexpr_rule_type > (),yystack_[1].value.as < uint64_t > ()); }
#line 1095 "ftcexpr_yacc.gen.cxx"
    break;

  case 27:
#line 152 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().member_access(yystack_[1].value.as < ftcexpr_rule_type > (), yystack_[0].value.as < uint64_t > ()); }
#line 1101 "ftcexpr_yacc.gen.cxx"
    break;

  case 28:
#line 153 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().post_inc(yystack_[1].value.as < ftcexpr_rule_type > ()); }
#line 1107 "ftcexpr_yacc.gen.cxx"
    break;

  case 29:
#line 154 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().post_dec(yystack_[1].value.as < ftcexpr_rule_type > ()); }
#line 1113 "ftcexpr_yacc.gen.cxx"
    break;

  case 30:
#line 158 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1119 "ftcexpr_yacc.gen.cxx"
    break;

  case 31:
#line 159 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().unary_plus(yystack_[0].value.as < uint64_t > ()); }
#line 1125 "ftcexpr_yacc.gen.cxx"
    break;

  case 32:
#line 160 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().neg(yystack_[0].value.as < uint64_t > ()); }
#line 1131 "ftcexpr_yacc.gen.cxx"
    break;

  case 33:
#line 161 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().bitwnot(yystack_[0].value.as < uint64_t > ()); }
#line 1137 "ftcexpr_yacc.gen.cxx"
    break;

  case 34:
#line 162 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().logcnot(yystack_[0].value.as < uint64_t > ()); }
#line 1143 "ftcexpr_yacc.gen.cxx"
    break;

  case 35:
#line 163 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().addressof(yystack_[0].value.as < uint64_t > ()); }
#line 1149 "ftcexpr_yacc.gen.cxx"
    break;

  case 36:
#line 164 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().derefer(yystack_[0].value.as < uint64_t > ()); }
#line 1155 "ftcexpr_yacc.gen.cxx"
    break;

  case 37:
#line 165 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().pre_inc(yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1161 "ftcexpr_yacc.gen.cxx"
    break;

  case 38:
#line 166 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().pre_dec(yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1167 "ftcexpr_yacc.gen.cxx"
    break;

  case 39:
#line 167 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().sizeof_expr(yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1173 "ftcexpr_yacc.gen.cxx"
    break;

  case 40:
#line 168 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().sizeof_type(yystack_[1].value.as < uint64_t > ()); }
#line 1179 "ftcexpr_yacc.gen.cxx"
    break;

  case 41:
#line 172 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < uint64_t > (); }
#line 1185 "ftcexpr_yacc.gen.cxx"
    break;

  case 42:
#line 173 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().mul(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1191 "ftcexpr_yacc.gen.cxx"
    break;

  case 43:
#line 174 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().div(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1197 "ftcexpr_yacc.gen.cxx"
    break;

  case 44:
#line 175 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().mod(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1203 "ftcexpr_yacc.gen.cxx"
    break;

  case 45:
#line 179 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1209 "ftcexpr_yacc.gen.cxx"
    break;

  case 46:
#line 180 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().add(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1215 "ftcexpr_yacc.gen.cxx"
    break;

  case 47:
#line 181 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().sub(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1221 "ftcexpr_yacc.gen.cxx"
    break;

  case 48:
#line 185 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1227 "ftcexpr_yacc.gen.cxx"
    break;

  case 49:
#line 186 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().shl(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1233 "ftcexpr_yacc.gen.cxx"
    break;

  case 50:
#line 187 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().shr(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1239 "ftcexpr_yacc.gen.cxx"
    break;

  case 51:
#line 191 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1245 "ftcexpr_yacc.gen.cxx"
    break;

  case 52:
#line 192 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().less(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1251 "ftcexpr_yacc.gen.cxx"
    break;

  case 53:
#line 193 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().greater(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1257 "ftcexpr_yacc.gen.cxx"
    break;

  case 54:
#line 194 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().less_eq(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1263 "ftcexpr_yacc.gen.cxx"
    break;

  case 55:
#line 195 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().greater_eq(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1269 "ftcexpr_yacc.gen.cxx"
    break;

  case 56:
#line 199 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1275 "ftcexpr_yacc.gen.cxx"
    break;

  case 57:
#line 200 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().eq(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1281 "ftcexpr_yacc.gen.cxx"
    break;

  case 58:
#line 201 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().neq(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1287 "ftcexpr_yacc.gen.cxx"
    break;

  case 59:
#line 205 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1293 "ftcexpr_yacc.gen.cxx"
    break;

  case 60:
#line 206 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().bitwand(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1299 "ftcexpr_yacc.gen.cxx"
    break;

  case 61:
#line 210 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1305 "ftcexpr_yacc.gen.cxx"
    break;

  case 62:
#line 211 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().exor(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1311 "ftcexpr_yacc.gen.cxx"
    break;

  case 63:
#line 215 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1317 "ftcexpr_yacc.gen.cxx"
    break;

  case 64:
#line 216 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().bitwor(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1323 "ftcexpr_yacc.gen.cxx"
    break;

  case 65:
#line 220 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1329 "ftcexpr_yacc.gen.cxx"
    break;

  case 66:
#line 221 "ftcexpr.gen.yacc"
    {
		yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().logcand(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ());
	}
#line 1337 "ftcexpr_yacc.gen.cxx"
    break;

  case 67:
#line 226 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1343 "ftcexpr_yacc.gen.cxx"
    break;

  case 68:
#line 227 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().logcor(yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ()); }
#line 1349 "ftcexpr_yacc.gen.cxx"
    break;

  case 69:
#line 231 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1355 "ftcexpr_yacc.gen.cxx"
    break;

  case 70:
#line 232 "ftcexpr.gen.yacc"
    {
		yylhs.value.as < ftcexpr_rule_type > () = FTCEXPR_DRV().if_then_else(yystack_[4].value.as < ftcexpr_rule_type > (),yystack_[2].value.as < ftcexpr_rule_type > (),yystack_[0].value.as < ftcexpr_rule_type > ());
	}
#line 1363 "ftcexpr_yacc.gen.cxx"
    break;

  case 71:
#line 236 "ftcexpr.gen.yacc"
    { yylhs.value.as < ftcexpr_rule_type > () = yystack_[0].value.as < ftcexpr_rule_type > (); }
#line 1369 "ftcexpr_yacc.gen.cxx"
    break;


#line 1373 "ftcexpr_yacc.gen.cxx"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -22;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      10,   -22,   -22,   -22,   -22,   -22,   -22,   -22,    10,    10,
      10,    10,    10,     3,   -22,    10,    10,   -22,    10,    10,
      48,   -22,    58,   -22,    -6,     7,    27,    30,    43,   -21,
      19,    25,    49,    -3,   -22,    71,    66,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     1,   -22,   -22,    10,
      10,   -22,   -22,   -22,    10,    10,    10,    10,    10,   -22,
     -22,    10,    10,   -22,   -22,    10,    10,    10,    10,   -22,
     -22,    10,    10,    10,    10,    10,   -22,    10,   -22,    10,
      10,   -22,   -22,   -22,    67,    68,   -22,    69,   -22,   -22,
     -22,    -6,    -6,     7,     7,    27,    27,    27,    27,    30,
      30,    43,   -21,    19,    25,    56,    49,   -22,   -22,   -22,
      10,   -22
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     3,     4,    15,    16,    18,    19,    21,     0,     0,
       0,     0,     0,     0,    22,     0,     0,    41,     0,     0,
       0,    24,    30,    17,    45,    48,    51,    56,    59,    61,
      63,    65,    67,    69,    71,     0,     0,    31,    32,    33,
      34,     1,    37,    38,    35,    36,     0,    39,    14,     0,
       0,    27,    28,    29,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     7,     8,     0,     0,     0,     0,     9,
      10,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     2,    23,    20,     0,     0,    13,     0,    42,    43,
      44,    46,    47,    49,    50,    52,    53,    54,    55,    57,
      58,    60,    62,    64,    66,     0,    68,    40,    26,    25,
       0,    70
  };

  const signed char
  parser::yypgoto_[] =
  {
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,    73,    74,    72,   -22,   -22,   -22,   -22,
     -22,   -22,   -14,    12,    15,   -20,    14,    21,    23,    24,
      26,    18,   -22,   -10,     0
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    13,    14,    61,    62,    67,    68,    71,    72,    77,
      80,    85,    51,    15,    16,    17,    18,    19,    84,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    36
  };

  const unsigned char
  parser::yytable_[] =
  {
      35,    42,    43,    41,     1,     2,    47,     3,     4,     5,
       6,    83,    73,     1,     2,    78,     3,     4,     5,     6,
       7,     8,    54,    55,    56,     9,    10,    11,    12,     7,
       8,    57,    58,    79,     9,    10,    11,    12,    59,    60,
      88,    89,    90,    63,    64,    95,    96,    97,    98,    86,
      87,     1,     2,    74,     3,     4,     5,     6,    69,    70,
      75,    65,    66,    48,     3,     4,    76,     7,    46,    91,
      92,    81,     9,    10,    11,    12,    93,    94,    49,   105,
      50,    37,    38,    39,    40,    99,   100,    82,   107,   108,
      44,    45,   109,   110,   101,    52,    53,   102,   106,   103,
     111,     0,     0,   104
  };

  const signed char
  parser::yycheck_[] =
  {
       0,    15,    16,     0,     3,     4,    20,     6,     7,     8,
       9,    10,    33,     3,     4,    18,     6,     7,     8,     9,
      19,    20,    28,    29,    30,    24,    25,    26,    27,    19,
      20,    24,    25,    36,    24,    25,    26,    27,    11,    12,
      54,    55,    56,    13,    14,    65,    66,    67,    68,    49,
      50,     3,     4,    34,     6,     7,     8,     9,    15,    16,
      35,    31,    32,     5,     6,     7,    17,    19,    20,    57,
      58,     0,    24,    25,    26,    27,    61,    62,    20,    79,
      22,     9,    10,    11,    12,    71,    72,    21,    21,    21,
      18,    19,    23,    37,    73,    22,    22,    74,    80,    75,
     110,    -1,    -1,    77
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,     6,     7,     8,     9,    19,    20,    24,
      25,    26,    27,    39,    40,    51,    52,    53,    54,    55,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    72,    53,    53,    53,
      53,     0,    60,    60,    53,    53,    20,    60,     5,    20,
      22,    50,    51,    52,    28,    29,    30,    24,    25,    11,
      12,    41,    42,    13,    14,    31,    32,    43,    44,    15,
      16,    45,    46,    33,    34,    35,    17,    47,    18,    36,
      48,     0,    21,    10,    56,    49,    72,    72,    60,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    66,    67,    68,    72,    69,    21,    21,    23,
      37,    71
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    38,    39,    40,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     4,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "INTLITERAL", "IDENTIFIER",
  "NEVER_TOKEN_MACC", "NEVER_TOKEN_INC_OP", "NEVER_TOKEN_DEC_OP",
  "NEVER_TOKEN_ADDRESSOF", "NEVER_TOKEN_DEREFER", "NEVER_TOKEN_TYPE",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "NEVER_TOKEN_SIZEOF", "'('", "')'", "'['", "']'", "'+'", "'-'",
  "'~'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'",
  "'?'", "':'", "$accept", "input", "ftcexpr_primary_leaf_expression",
  "ftcexpr_LEFT_OP", "ftcexpr_RIGHT_OP", "ftcexpr_LE_OP", "ftcexpr_GE_OP",
  "ftcexpr_EQ_OP", "ftcexpr_NE_OP", "ftcexpr_AND_OP", "ftcexpr_OR_OP",
  "ftcexpr_argument_expression_list", "ftcexpr_member_access",
  "ftcexpr_INC_OP", "ftcexpr_DEC_OP", "ftcexpr_cast_expression",
  "ftcexpr_ADDRESSOF", "ftcexpr_DEREFER", "ftcexpr_type", "ftcexpr_SIZEOF",
  "ftcexpr_primary_expression", "ftcexpr_postfix_expression",
  "ftcexpr_unary_expression", "ftcexpr_multiplicative_expression",
  "ftcexpr_additive_expression", "ftcexpr_shift_expression",
  "ftcexpr_relational_expression", "ftcexpr_equality_expression",
  "ftcexpr_and_expression", "ftcexpr_exclusive_or_expression",
  "ftcexpr_inclusive_or_expression", "ftcexpr_logical_and_expression",
  "ftcexpr_logical_or_expression", "ftcexpr_conditional_expression",
  "ftcexpr_expression", YY_NULLPTR
  };

#if FTCEXPR_DEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    81,    81,    84,    85,    89,    90,    91,    92,    93,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   107,   144,   145,   149,   150,   151,   152,   153,   154,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   172,   173,   174,   175,   179,   180,   181,   185,   186,
     187,   191,   192,   193,   194,   195,   199,   200,   201,   205,
     206,   210,   211,   215,   216,   220,   221,   226,   227,   231,
     232,   236
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // FTCEXPR_DEBUG


#line 9 "ftcexpr.gen.yacc"
} // ftcexpr
#line 1850 "ftcexpr_yacc.gen.cxx"

#line 240 "ftcexpr.gen.yacc"


void ftcexpr::parser::error(ftcexpr::location const &loc, std::string const &msg) {
	throw ftcexpr::parser::syntax_error(loc, msg);
}

