// A Bison parser, made by GNU Bison 3.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file ftcexpr_yacc_defines.gen.hxx
 ** Define the ftcexpr::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_FTCEXPR_FTCEXPR_YACC_DEFINES_GEN_HXX_INCLUDED
# define YY_FTCEXPR_FTCEXPR_YACC_DEFINES_GEN_HXX_INCLUDED
// //                    "%code requires" blocks.
#line 17 "ftcexpr.gen.yacc"

#include "ftcexpr_demo_driver_fwd.hxx"

#line 52 "ftcexpr_yacc_defines.gen.hxx"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef FTCEXPR_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define FTCEXPR_DEBUG 1
#  else
#   define FTCEXPR_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define FTCEXPR_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined FTCEXPR_DEBUG */

#line 9 "ftcexpr.gen.yacc"
namespace ftcexpr {
#line 176 "ftcexpr_yacc_defines.gen.hxx"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef FTCEXPR_STYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YYASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // ftcexpr_primary_expression
      // ftcexpr_postfix_expression
      // ftcexpr_unary_expression
      // ftcexpr_multiplicative_expression
      // ftcexpr_additive_expression
      // ftcexpr_shift_expression
      // ftcexpr_relational_expression
      // ftcexpr_equality_expression
      // ftcexpr_and_expression
      // ftcexpr_exclusive_or_expression
      // ftcexpr_inclusive_or_expression
      // ftcexpr_logical_and_expression
      // ftcexpr_logical_or_expression
      // ftcexpr_conditional_expression
      // ftcexpr_expression
      char dummy1[sizeof (ftcexpr_rule_type)];

      // INTLITERAL
      // IDENTIFIER
      char dummy2[sizeof (std::string)];

      // ftcexpr_primary_leaf_expression
      // ftcexpr_LEFT_OP
      // ftcexpr_RIGHT_OP
      // ftcexpr_LE_OP
      // ftcexpr_GE_OP
      // ftcexpr_EQ_OP
      // ftcexpr_NE_OP
      // ftcexpr_AND_OP
      // ftcexpr_OR_OP
      // ftcexpr_argument_expression_list
      // ftcexpr_member_access
      // ftcexpr_INC_OP
      // ftcexpr_DEC_OP
      // ftcexpr_cast_expression
      // ftcexpr_ADDRESSOF
      // ftcexpr_DEREFER
      // ftcexpr_type
      // ftcexpr_SIZEOF
      char dummy3[sizeof (uint64_t)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef FTCEXPR_STYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_END = 0,
        TOK_INTLITERAL = 258,
        TOK_IDENTIFIER = 259,
        TOK_NEVER_TOKEN_MACC = 260,
        TOK_NEVER_TOKEN_INC_OP = 261,
        TOK_NEVER_TOKEN_DEC_OP = 262,
        TOK_NEVER_TOKEN_ADDRESSOF = 263,
        TOK_NEVER_TOKEN_DEREFER = 264,
        TOK_NEVER_TOKEN_TYPE = 265,
        TOK_LEFT_OP = 266,
        TOK_RIGHT_OP = 267,
        TOK_LE_OP = 268,
        TOK_GE_OP = 269,
        TOK_EQ_OP = 270,
        TOK_NE_OP = 271,
        TOK_AND_OP = 272,
        TOK_OR_OP = 273,
        TOK_NEVER_TOKEN_SIZEOF = 274
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ftcexpr_rule_type&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ftcexpr_rule_type& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, uint64_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const uint64_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
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
        value.template destroy< ftcexpr_rule_type > ();
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        value.template destroy< std::string > ();
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
        value.template destroy< uint64_t > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YYASSERT (tok == token::TOK_END || tok == token::TOK_NEVER_TOKEN_MACC || tok == token::TOK_NEVER_TOKEN_INC_OP || tok == token::TOK_NEVER_TOKEN_DEC_OP || tok == token::TOK_NEVER_TOKEN_ADDRESSOF || tok == token::TOK_NEVER_TOKEN_DEREFER || tok == token::TOK_NEVER_TOKEN_TYPE || tok == token::TOK_LEFT_OP || tok == token::TOK_RIGHT_OP || tok == token::TOK_LE_OP || tok == token::TOK_GE_OP || tok == token::TOK_EQ_OP || tok == token::TOK_NE_OP || tok == token::TOK_AND_OP || tok == token::TOK_OR_OP || tok == token::TOK_NEVER_TOKEN_SIZEOF || tok == 40 || tok == 41 || tok == 91 || tok == 93 || tok == 43 || tok == 45 || tok == 126 || tok == 33 || tok == 42 || tok == 47 || tok == 37 || tok == 60 || tok == 62 || tok == 38 || tok == 94 || tok == 124 || tok == 63 || tok == 58);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YYASSERT (tok == token::TOK_END || tok == token::TOK_NEVER_TOKEN_MACC || tok == token::TOK_NEVER_TOKEN_INC_OP || tok == token::TOK_NEVER_TOKEN_DEC_OP || tok == token::TOK_NEVER_TOKEN_ADDRESSOF || tok == token::TOK_NEVER_TOKEN_DEREFER || tok == token::TOK_NEVER_TOKEN_TYPE || tok == token::TOK_LEFT_OP || tok == token::TOK_RIGHT_OP || tok == token::TOK_LE_OP || tok == token::TOK_GE_OP || tok == token::TOK_EQ_OP || tok == token::TOK_NE_OP || tok == token::TOK_AND_OP || tok == token::TOK_OR_OP || tok == token::TOK_NEVER_TOKEN_SIZEOF || tok == 40 || tok == 41 || tok == 91 || tok == 93 || tok == 43 || tok == 45 || tok == 126 || tok == 33 || tok == 42 || tok == 47 || tok == 37 || tok == 60 || tok == 62 || tok == 38 || tok == 94 || tok == 124 || tok == 63 || tok == 58);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::TOK_INTLITERAL || tok == token::TOK_IDENTIFIER);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::TOK_INTLITERAL || tok == token::TOK_IDENTIFIER);
      }
#endif
    };

    /// Build a parser object.
    parser (ftcexpr_demo::Driver& drv_yyarg, void *yyscanner_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if FTCEXPR_DEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOK_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOK_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTLITERAL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_INTLITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTLITERAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_INTLITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER_TOKEN_MACC (location_type l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_MACC, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER_TOKEN_MACC (const location_type& l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_MACC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER_TOKEN_INC_OP (location_type l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_INC_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER_TOKEN_INC_OP (const location_type& l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_INC_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER_TOKEN_DEC_OP (location_type l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_DEC_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER_TOKEN_DEC_OP (const location_type& l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_DEC_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER_TOKEN_ADDRESSOF (location_type l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_ADDRESSOF, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER_TOKEN_ADDRESSOF (const location_type& l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_ADDRESSOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER_TOKEN_DEREFER (location_type l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_DEREFER, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER_TOKEN_DEREFER (const location_type& l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_DEREFER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER_TOKEN_TYPE (location_type l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER_TOKEN_TYPE (const location_type& l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_OP (location_type l)
      {
        return symbol_type (token::TOK_LEFT_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_OP (const location_type& l)
      {
        return symbol_type (token::TOK_LEFT_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_OP (location_type l)
      {
        return symbol_type (token::TOK_RIGHT_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_OP (const location_type& l)
      {
        return symbol_type (token::TOK_RIGHT_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE_OP (location_type l)
      {
        return symbol_type (token::TOK_LE_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_LE_OP (const location_type& l)
      {
        return symbol_type (token::TOK_LE_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE_OP (location_type l)
      {
        return symbol_type (token::TOK_GE_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_GE_OP (const location_type& l)
      {
        return symbol_type (token::TOK_GE_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_OP (location_type l)
      {
        return symbol_type (token::TOK_EQ_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ_OP (const location_type& l)
      {
        return symbol_type (token::TOK_EQ_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE_OP (location_type l)
      {
        return symbol_type (token::TOK_NE_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_NE_OP (const location_type& l)
      {
        return symbol_type (token::TOK_NE_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_OP (location_type l)
      {
        return symbol_type (token::TOK_AND_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_AND_OP (const location_type& l)
      {
        return symbol_type (token::TOK_AND_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_OP (location_type l)
      {
        return symbol_type (token::TOK_OR_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_OR_OP (const location_type& l)
      {
        return symbol_type (token::TOK_OR_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER_TOKEN_SIZEOF (location_type l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_SIZEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER_TOKEN_SIZEOF (const location_type& l)
      {
        return symbol_type (token::TOK_NEVER_TOKEN_SIZEOF, l);
      }
#endif


  private:
    /// This class is not copiable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const signed char yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const signed char yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if FTCEXPR_DEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 103,     ///< Last index in yytable_.
      yynnts_ = 35,  ///< Number of nonterminal symbols.
      yyfinal_ = 41, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 38  ///< Number of tokens.
    };


    // User arguments.
    ftcexpr_demo::Driver& drv;
    void *yyscanner;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,     2,     2,    30,    33,     2,
      20,    21,    28,    24,     2,    25,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,     2,
      31,     2,    32,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,    26,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19
    };
    const unsigned user_token_number_max_ = 274;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
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
        value.move< ftcexpr_rule_type > (std::move (that.value));
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        value.move< std::string > (std::move (that.value));
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
        value.move< uint64_t > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
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
        value.copy< ftcexpr_rule_type > (YY_MOVE (that.value));
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
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
        value.copy< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
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
        value.move< ftcexpr_rule_type > (YY_MOVE (s.value));
        break;

      case 3: // INTLITERAL
      case 4: // IDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
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
        value.move< uint64_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const YY_NOEXCEPT
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,    91,    93,    43,    45,   126,    33,    42,    47,
      37,    60,    62,    38,    94,   124,    63,    58
    };
    return token_type (yytoken_number_[type]);
  }

#line 9 "ftcexpr.gen.yacc"
} // ftcexpr
#line 1675 "ftcexpr_yacc_defines.gen.hxx"





#endif // !YY_FTCEXPR_FTCEXPR_YACC_DEFINES_GEN_HXX_INCLUDED
