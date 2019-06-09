/* ftcexpt_rule_types.yacc
 * LICENSE: GPL version 3, see LICENSE
 *
 * This file provides typing for integer expression rules.
*/

%type <ftcexpr_rule_type> ftcexpr_primary_expression  ftcexpr_postfix_expression ftcexpr_unary_expression
%type <ftcexpr_rule_type> ftcexpr_multiplicative_expression ftcexpr_additive_expression ftcexpr_shift_expression
%type <ftcexpr_rule_type> ftcexpr_relational_expression ftcexpr_equality_expression ftcexpr_and_expression
%type <ftcexpr_rule_type> ftcexpr_exclusive_or_expression ftcexpr_inclusive_or_expression
%type <ftcexpr_rule_type> ftcexpr_logical_and_expression ftcexpr_logical_or_expression ftcexpr_conditional_expression

%type <ftcexpr_rule_type> ftcexpr_expression

