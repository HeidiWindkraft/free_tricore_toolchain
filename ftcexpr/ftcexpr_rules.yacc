
%%

/* [DRIVER] FTCEXPR_DRV() is meant to retrieve the driver interface and shall work in several languages.
 *          C: Could be a define to a global variable containing function pointers.
 *             Could be `*drv` where `drv` is an additional pointer argument to the parse function
 *               which points to a struct containing function pointers.
 *          C++: Could be `drv` where `drv` is an additional reference argument to the parse function
 *                 which points to an object having methods.
 *          Java: Could be a method returning an object which has methods.
*/
/* [RULE_CALLOUT]
 *   ftcexpr_primary_leaf_expression: INTEGER_LITERAL | IDENTIFIER | ...;
 *   ftcexpr_LEFT_OP : "<<"
 *   ftcexpr_RIGHT_OP: ">>"
 *   ftcexpr_LE_OP   : "<="
 *   ftcexpr_GE_OP   : ">="
 *   ftcexpr_EQ_OP   : "=="
 *   ftcexpr_NE_OP   : "!="
 *   ftcexpr_AND_OP  : "&&"
 *   ftcexpr_OR_OP   : "||"
 *   ftcexpr_argument_expression_list: ...
 *   ftcexpr_member_access: '.' IDENTIFIER | PTR_OP IDENTIFIER; ftcexpr_member_access: NEVER_TOKEN;
 *   ftcexpr_INC_OP  : "++"  : NEVER_TOKEN;
 *   ftcexpr_DEC_OP  : "--"  : NEVER_TOKEN;
 *   ftcexpr_cast_expression: ftcexpr_unary_expression
 *   ftcexpr_ADDRESSOF: "&" : NEVER_TOKEN;
 *   ftcexpr_DEREFER: "*" : NEVER_TOKEN;
 *   ftcexpr_type: ... : NEVER_TOKEN;
*/

ftcexpr_primary_expression
	: ftcexpr_primary_leaf_expression { $$ = $1; }
	| '(' ftcexpr_expression ')' { $$ = $2; }
	;

ftcexpr_postfix_expression
	: ftcexpr_primary_expression { $$ = $1; }
	| ftcexpr_postfix_expression '[' ftcexpr_expression ']' { $$ = FTCEXPR_DRV().subscript($1,$3); }
	| ftcexpr_postfix_expression '(' ftcexpr_argument_expression_list ')' { $$ = FTCEXPR_DRV().call($1,$3); }
	| ftcexpr_postfix_expression ftcexpr_member_access { $$ = FTCEXPR_DRV().member_access($1, $2); }
	| ftcexpr_postfix_expression ftcexpr_INC_OP { $$ = FTCEXPR_DRV().post_inc($1); }
	| ftcexpr_postfix_expression ftcexpr_DEC_OP { $$ = FTCEXPR_DRV().post_dec($1); }
	;

ftcexpr_unary_expression
	: ftcexpr_postfix_expression { $$ = $1; }
	| '+' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().unary_plus($2); }
	| '-' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().neg($2); }
	| '~' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().bitnot($2); }
	| '!' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().lognot($2); }
	| ftcexpr_ADDRESSOF ftcexpr_cast_expression { $$ = FTCEXPR_DRV().addressof($2); }
	| ftcexpr_DEREFER ftcexpr_cast_expression { $$ = FTCEXPR_DRV().derefer($2); }
	| ftcexpr_INC_OP ftcexpr_unary_expression { $$ = FTCEXPR_DRV().pre_inc($2); }
	| ftcexpr_DEC_OP ftcexpr_unary_expression { $$ = FTCEXPR_DRV().pre_dec($2); }
	| ftcexpr_SIZEOF ftcexpr_unary_expression { $$ = FTCEXPR_DRV().sizeof_expr($2); }
	| ftcexpr_SIZEOF '(' ftcexpr_type ')' { $$ = FTCEXPR_DRV().sizeof_type($3); }
	;

ftcexpr_multiplicative_expression
	: ftcexpr_cast_expression { $$ = $1; }
	| ftcexpr_multiplicative_expression '*' ftcexpr_unary_expression { $$ = FTCEXPR_DRV().mul($1,$3); }
	| ftcexpr_multiplicative_expression '/' ftcexpr_unary_expression { $$ = FTCEXPR_DRV().div($1,$3); }
	| ftcexpr_multiplicative_expression '%' ftcexpr_unary_expression { $$ = FTCEXPR_DRV().mod($1,$3); }
	;

ftcexpr_additive_expression
	: ftcexpr_multiplicative_expression { $$ = $1; }
	| ftcexpr_additive_expression '+' ftcexpr_multiplicative_expression { $$ = FTCEXPR_DRV().add($1,$3); }
	| ftcexpr_additive_expression '-' ftcexpr_multiplicative_expression { $$ = FTCEXPR_DRV().sub($1,$3); }
	;

ftcexpr_shift_expression
	: ftcexpr_additive_expression { $$ = $1; }
	| ftcexpr_shift_expression ftcexpr_LEFT_OP ftcexpr_additive_expression { $$ = FTCEXPR_DRV().shl($1,$3); }
	| ftcexpr_shift_expression ftcexpr_RIGHT_OP ftcexpr_additive_expression { $$ = FTCEXPR_DRV().shr($1,$3); }
	;

ftcexpr_relational_expression
	: ftcexpr_shift_expression { $$ = $1; }
	| ftcexpr_relational_expression '<' ftcexpr_shift_expression { $$ = FTCEXPR_DRV().less($1,$3); }
	| ftcexpr_relational_expression '>' ftcexpr_shift_expression { $$ = FTCEXPR_DRV().greater($1,$3); }
	| ftcexpr_relational_expression ftcexpr_LE_OP ftcexpr_shift_expression { $$ = FTCEXPR_DRV().less_eq($1,$3); }
	| ftcexpr_relational_expression ftcexpr_GE_OP ftcexpr_shift_expression { $$ = FTCEXPR_DRV().greater_eq($1,$3); }
	;

ftcexpr_equality_expression
	: ftcexpr_relational_expression { $$ = $1; }
	| ftcexpr_equality_expression ftcexpr_EQ_OP ftcexpr_relational_expression { $$ = FTCEXPR_DRV().eq($1,$3); }
	| ftcexpr_equality_expression ftcexpr_NE_OP ftcexpr_relational_expression { $$ = FTCEXPR_DRV().neq($1,$3); }
	;

ftcexpr_and_expression
	: ftcexpr_equality_expression { $$ = $1; }
	| ftcexpr_and_expression '&' ftcexpr_equality_expression { $$ = FTCEXPR_DRV().bitand($1,$3); }
	;

ftcexpr_exclusive_or_expression
	: ftcexpr_and_expression { $$ = $1; }
	| ftcexpr_exclusive_or_expression '^' ftcexpr_and_expression { $$ = FTCEXPR_DRV().exor($1,$3); }
	;

ftcexpr_inclusive_or_expression
	: ftcexpr_exclusive_or_expression { $$ = $1; }
	| ftcexpr_inclusive_or_expression '|' ftcexpr_exclusive_or_expression { $$ = FTCEXPR_DRV().bitor($1,$3); }
	;

ftcexpr_logical_and_expression
	: ftcexpr_inclusive_or_expression { $$ = $1; }
	| ftcexpr_logical_and_expression ftcexpr_AND_OP ftcexpr_inclusive_or_expression {
		$$ = FTCEXPR_DRV().logand($1,$3);
	};

ftcexpr_logical_or_expression
	: ftcexpr_logical_and_expression { $$ = $1; }
	| ftcexpr_logical_or_expression ftcexpr_OR_OP ftcexpr_logical_and_expression { $$ = FTCEXPR_DRV().logor($1,$3); }
	;

ftcexpr_conditional_expression
	: ftcexpr_logical_or_expression { $$ = $1; }
	| ftcexpr_logical_or_expression '?' ftcexpr_expression ':' ftcexpr_conditional_expression {
		$$ = FTCEXPR_DRV().if_then_else($1,$3,$5);
	};

ftcexpr_expression: ftcexpr_conditional_expression { $$ = $1; }

